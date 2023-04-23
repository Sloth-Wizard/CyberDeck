DIR_Config = /home/pnots/EPaper/e-Paper/RaspberryPi_JetsonNano/c/lib/Config
DIR_Examples = /home/pnots/EPaper/e-Paper/RaspberryPi_JetsonNano/c/examples
DIR_EDP = /home/pnots/EPaper/e-Paper/RaspberryPi_JetsonNano/c/lib/e-Paper
DIR_FONTS = /home/pnots/EPaper/e-Paper/RaspberryPi_JetsonNano/c/lib/Fonts
DIR_GUI = /home/pnots/EPaper/e-Paper/RaspberryPi_JetsonNano/c/lib/GUI
DIR_BIN = /home/pnots/EPaper/e-Paper/RaspberryPi_JetsonNano/c/bin

EPD = NULL

OBJ_C_EPD = ${DIR_EPD}/EPD_2in13b_V3.c
OBJ_C_EX = ./image.c
OBJ_C = $(wildcard ${OBJ_C_EPD} ${DIR_GUI}/*.c ${OBJ_C_EX} ImageData.c ${DIR_FONTS}/*.c )
OBJ_O = $(patsubst %.c,${DIR_BIN}/%.o,$(notdir ${OBJ_V}))
RPI_DEV_C = $(wildcard ${DIR_BIN}/dev_hardware_SPI.o ${DIR_BIN}/RPI_sysfs_gpio.o ${DIR_BIN}/DEV_Config.o )
JETSON_DEV_C = $(wildcard ${DIR_BIN}/sysfs_software_spi.o ${DIR_BIN}/sysfs_gpio.o ${DIR_BIN}/DEV_Config.o )
DEBUG = -D DEBUG
USELIB_RPI = USE_BCM2835_LIB
LIB_RPI=-Wl,--gc-sections -lbcm2835 -lm
DEBUG_RPI = -D ${USELIB_RPI} -D RPI
USELIB_JETSONI = USE_DEV_LIB
LIB_JETSONI = -lm
DEBUG_JETSONI = -D ${USELIB_JETSONI} -D JETSON

.PHONY : RPI JETSON clean

RPI:RPI_DEV RPI_epd
JETSON:JETSON_DEV JETSON_epd

TARGET = epd
CC = gcc
MSG = -g -O -ffunction-sections -fdata-sections -Wall
CFLAGS += ${MSG} -D ${EPD}

RPI_epd:${OBJ_O}
	echo $(@)
	${CC} ${CFLAGS} -D RPI ${OBJ_O} ${RPI_DEV_C} -o ${TARGET} ${LIB_RPI} ${DEBUG}

JETSON_epd:${OBJ_O}
	echo $(@)
	${CC} ${CFLAGS} ${OBJ_O} ${JETSON_DEV_C} -o ${TARGET} ${LIB_JETSONI} ${DEBUG}
$(shell mkdir -p ./bin)

${DIR_BIN}/%.o:${DIR_Examples}/%.c
	${CC} ${CFLAGS} -c	$< -o $@ -I ${DIR_Config} -I ${DIR_GUI} -I ${DIR_EPD} ${DEBUG}

${DIR_BIN}/%.o:${DIR_EPD}/%.c
	${CC} ${CFLAGS} -c	$< -o $@ ${DIF_Config} ${DEBUG}

${DIR_BIN}/%.o:${DIR_FONTS}/%.c
	${CC} ${CFLAGS} -c	$< -o $@ ${DEBUG}

${DIR_BIN}/%.o:${DIR_GUI}/%.c
	${CC} ${CFLAGS} -c	$< -o $@ -I ${DIR_Config} ${DEBUG}

RPI_DEV:
	${CC} ${CFLAGS} ${DEBUG_RPI} -v ${DIR_Config}/dev_hardware_SPI.c -o ${DIR_BIN}/dev_hardware_SPI.o ${LIB_RPI} ${DEBUG}
	${CC} ${CFLAGS} ${DEBUG_RPI} -v ${DIR_Config}/RPI_sysfs_gpio.c -o ${DIR_BIN}/RPI_sysfs_gpio.o ${LIB_RPI} ${DEBUG}
	${CC} ${CFLAGS} ${DEBUG_RPI} -v ${DIR_Config}/DEV_Config.c -o ${DIR_BIN}/DEV_Config.o ${LIB_RPI} ${DEBUG}

JETSON_DEV:
	${CC} ${CFLAGS} ${DEBUG_JETSONI} -c	${DIR_Config}/sysfs_software_spi.c -o ${DIR_BIN}/sysfs_software_spi.o ${LIB_JETSONI} ${DEBUG}
	${CC} ${CFLAGS} ${DEBUG_JETSONI} -c	${DIR_Config}/sysfs_gpio.c -o ${DIR_BIN}/sysfs_gpio.o ${LIB_JETSONI} ${DEBUG}
	${CC} ${CFLAGS} ${DEBUG_JETSONI} -c	${DIR_Config}/DEV_Config.c -o ${DIR_BIN}/DEV_Config.o ${LIB_JETSONI} ${DEBUG}

clean :
	rm ${DIR_BIN}/*.* 
	rm ${TARGET} 
