# Configuración para la conexión SSH
RPI_USER = ubuntu
RPI_IP = 192.168.1.46# Reemplaza con la IP de tu Raspberry Pi
RPI_DIR = /home/$(RPI_USER)/RobotDog
RPI_INO_DIR = RobotDog
SKETCH_NAME = sketches/RobotDog.ino
PRIVATE_KEY = /home/adaypa/.ssh/id_rsa  # Reemplaza con tu ruta real

# Comandos
COPY_CMD = scp -i $(PRIVATE_KEY) $(SKETCH_NAME) $(RPI_USER)@$(RPI_IP):$(RPI_DIR)/
UPLOAD_CMD = ssh -i $(PRIVATE_KEY) $(RPI_USER)@$(RPI_IP) "/home/ubuntu/arduino_upload.sh $(RPI_INO_DIR)"

# Objetivos predeterminados
.PHONY: all upload

all: upload

upload: $(SKETCH_NAME)
	$(COPY_CMD)
	$(UPLOAD_CMD)
