REPOS_ROOT = ${REPOS}
BUILD_DIR = ${shell pwd}/build
BUILD_OBJ_DIR = ${shell pwd}/build/obj
BUILD_BIN_DIR = ${shell pwd}/build/bin
BIN = koshlect

LVGL_DIR_NAME ?= lvgl
LVGL_DIR ?= ${REPOS_ROOT}

CFLAGS+=-DLV_CONF_INCLUDE_SIMPLE -I./inc/lvgl -I./inc -I$(LVGL_DIR)/lvgl -g

include $(LVGL_DIR)/$(LVGL_DIR_NAME)/lvgl.mk
include $(LVGL_DIR)/lv_drivers/lv_drivers.mk

LDFLAGS := -lSDL2

OBJEXT 			?= .o

MAINSRC += main.c 
CSRCS += src/*.c


AOBJS 			= $(ASRCS:.S=$(OBJEXT))
COBJS 			= $(CSRCS:.c=$(OBJEXT))

MAINOBJ 		= $(MAINSRC:.c=$(OBJEXT))

SRCS 			= $(ASRCS) $(CSRCS) $(MAINSRC)
OBJS 			= $(AOBJS) $(COBJS) $(MAINOBJ)
TARGET 			= $(addprefix $(BUILD_OBJ_DIR)/, $(patsubst ./%, %, $(OBJS)))

## MAINOBJ -> OBJFILES

all:
	make -j16 default

$(BUILD_OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC $<"

default: $(TARGET)
	@mkdir -p $(dir $(BUILD_BIN_DIR)/)
	$(CC) -o $(BUILD_BIN_DIR)/$(BIN) $(TARGET) $(LDFLAGS)

clean: 
	rm -rf $(BUILD_DIR)

install:
	install -d $(DESTDIR)$(bindir)
	install $(BUILD_BIN_DIR)/$(BIN) $(DESTDIR)$(bindir)

uninstall:
	$(RM) -r $(addprefix $(DESTDIR)$(bindir)/,$(BIN))
