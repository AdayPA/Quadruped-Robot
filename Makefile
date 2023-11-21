# Directorios
SKETCH_DIR = /home/adaypa/Programming/RobotDog/sketches
SKETCH_NAME = RobotDog.ino

# Configuración de la placa (ajusta según tu configuración)
BOARD = arduino:avr:nano

# Detectar automáticamente el puerto
PORT := $(shell ls /dev/ttyUSB* 2>/dev/null)

# Comandos
COMPILE_CMD = arduino-cli compile --fqbn $(BOARD) $(SKETCH_DIR)/$(SKETCH_NAME)
UPLOAD_CMD = arduino-cli upload -p $(PORT) --fqbn $(BOARD) $(SKETCH_DIR)/$(SKETCH_NAME)

# Objetivos predeterminados
.PHONY: all compile upload

all: compile upload

compile:
	$(COMPILE_CMD)

upload:
	$(UPLOAD_CMD)
