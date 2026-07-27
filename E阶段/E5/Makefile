.DEFAULT_GOAL := all

KNOWN_GOALS := all sim wave lint clean
DESIGN_GOALS := $(filter-out $(KNOWN_GOALS),$(MAKECMDGOALS))

ifneq ($(strip $(DESIGN_GOALS)),)
DESIGN ?= $(firstword $(DESIGN_GOALS))
.PHONY: $(DESIGN_GOALS)
$(DESIGN_GOALS): ;
endif

TOPNAME ?= top
DESIGN  ?= DoubleSwitchNVBoard
PYTHON  ?= python3.11

WORK_DIR := $(abspath $(DESIGN))

NXDC_FILES = $(WORK_DIR)/constr/top.nxdc
BUILD_DIR = $(WORK_DIR)/build
OBJ_DIR  := $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)
VSRCS := $(WORK_DIR)/vsrc/top.v
CSRCS := $(WORK_DIR)/csrc/sim_main.cpp
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
CSRCS += $(SRC_AUTO_BIND)
VERILATOR := verilator			
VERILATOR_FLAGS := -MMD --cc --exe --build --trace-fst \
                   -Wall -O3 --x-assign fast --x-initial fast --noassert
                   
$(shell mkdir -p $(BUILD_DIR))           
$(SRC_AUTO_BIND): $(NXDC_FILES)
	$(PYTHON) $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@


# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@test -d "$(WORK_DIR)" || (echo "Cannot find $(WORK_DIR)"; exit 1)
	@mkdir -p $(BUILD_DIR)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module $(TOPNAME) \
		$^ \
		$(addprefix -CFLAGS ,$(CXXFLAGS)) \
		$(addprefix -LDFLAGS ,$(LDFLAGS)) \
		--Mdir $(OBJ_DIR) \
		-o $(abspath $(BIN))
		
all: sim


sim:$(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	cd $(WORK_DIR) && ./build/$(TOPNAME)

	
wave:
	@test -f "$(WORK_DIR)/wave.fst" || (echo "Cannot find $(WORK_DIR)/wave.fst"; exit 1)
	cd $(WORK_DIR) && gtkwave wave.fst
	
lint:
	$(VERILATOR) --lint-only -Wall \
		--top-module $(TOPNAME) \
		$(VSRCS)	

clean:
	rm -rf $(BUILD_DIR)


include ../Makefile
.PHONY: all sim wave lint clean

