import matplotlib.pyplot as plt
import numpy as np
from matplotlib.widgets import Slider, TextBox, Button
import json

shoulder_length = 135
elbow_length = 106
elbow_value_write = 0
shoulder_value_write = 0
shoulder_offset = 0
elbow_offset = 0
json_file_path = '../config/slider_values.json'
point_file = '../data/gait_sequence.txt'

try:
    with open(json_file_path, 'r') as file:
        saved_values = json.load(file)
        shoulder_offset = saved_values.get('shoulder_offset', 0)
        elbow_offset = saved_values.get('elbow_offset', 0)
except FileNotFoundError:
    print("El archivo no se encuentra.")
except Exception as e:
    print("Error al cargar el archivo:", e)


def on_button_click(text):
    try:
        with open(point_file, 'r') as file:
            # Lee las líneas del archivo
            lines = file.readlines()
            repetitions = int(text)
            for i in range(repetitions):
                for line in lines:

                    # Obtiene las coordenadas de cada línea
                    coords = line.strip().split()
                    elbow_slider.set_val(float(coords[0]))
                    shoulder_slider.set_val(float(coords[1]))
                    plt.pause(1 / speed_slider.val)  # Pausa de 1 segundo para hacerlo visible

    except FileNotFoundError:
        print("El archivo no se encuentra.")
    except Exception as e:
        print("Error al leer el archivo:", e)


def on_point_button_click(event):
    with open(point_file, 'a') as file:
        file.write(f"{elbow_value_write}        {shoulder_value_write}\n")
    file.close
    print("Punto añadido")

fig, ax = plt.subplots()
plt.subplots_adjust(bottom=0.5)
ax.set_xlim((-shoulder_length - elbow_length) * 1.25, (shoulder_length + elbow_length) * 1.25)
ax.set_ylim((-shoulder_length - elbow_length) * 1.25, shoulder_length * 1.25)
ax.set_aspect('equal', adjustable='box')
ax.set_xlabel('X (mm)')
ax.set_ylabel('Y (mm)')
ax.set_title('Representación visual del brazo robot')
ax.grid()

line_shoulder, = ax.plot([], [], 'bo-')
line_elbow, = ax.plot([], [], 'go-')
line_arm, = ax.plot([], [], 'go-')
point_end, = ax.plot([], [], 'ro')

elbow_slider_ax = plt.axes([0.2, 0.3, 0.65, 0.03], facecolor='lightgoldenrodyellow')
shoulder_slider_ax = plt.axes([0.2, 0.25, 0.65, 0.03], facecolor='lightgoldenrodyellow')
elbow_offset_slider_ax = plt.axes([0.2, 0.15, 0.65, 0.03], facecolor='lightgoldenrodyellow')
shoulder_offset_slider_ax = plt.axes([0.2, 0.1, 0.65, 0.03], facecolor='lightgoldenrodyellow')
speed_slider_ax = plt.axes([0.55, 0.01, 0.1, 0.03], facecolor='lightgoldenrodyellow')
point_button_ax = plt.axes([0.3, 0.01, 0.1, 0.05])
coord_x_textbox_ax = plt.axes([0.2, 0.35, 0.05, 0.02], facecolor='lightgoldenrodyellow')
coord_y_textbox_ax = plt.axes([0.35, 0.35, 0.05, 0.02], facecolor='lightgoldenrodyellow')
play_ax = plt.axes([0.4, 0.01, 0.1, 0.05])
repeat_ax = plt.axes([0.55, 0.04, 0.02, 0.02])


elbow_slider = Slider(elbow_slider_ax, 'Arm', 0, 180, valinit=0)
shoulder_slider = Slider(shoulder_slider_ax, 'Wrist', 0, 180, valinit=0)
elbow_offset_slider = Slider(elbow_offset_slider_ax, 'Offset Arm', -180, 180, valinit=elbow_offset)
shoulder_offset_slider = Slider(shoulder_offset_slider_ax, 'Offset Wrist', -180, 180, valinit=shoulder_offset)
speed_slider = Slider(speed_slider_ax, 'speed', 1, 10, valinit=1)
coord_x_textbox = TextBox(coord_x_textbox_ax, 'X (mm): ', initial='X=0', color='white')
coord_y_textbox = TextBox(coord_y_textbox_ax, 'Y (mm): ', initial='Y=0', color='white')
point_button = Button(point_button_ax, 'Añadir punto')
play_button = Button(play_ax, 'Play')
repeat_text = TextBox(repeat_ax, 'Replay', initial=1, color='white')



def init():
    line_shoulder.set_data([], [])
    line_elbow.set_data([], [])
    line_arm.set_data([], [])
    point_end.set_data([], [])
    return line_shoulder, line_elbow, line_arm, point_end

def update(val):
    global elbow_value_write, shoulder_value_write
    elbow_angle = elbow_slider.val + elbow_offset_slider.val
    shoulder_angle = shoulder_slider.val + shoulder_offset_slider.val

    shoulder_x = 0
    shoulder_y = 0
    elbow_x = shoulder_length * np.cos(np.radians(shoulder_angle))
    elbow_y = shoulder_length * np.sin(np.radians(shoulder_angle))
    end_x = elbow_x + elbow_length * np.cos(np.radians(shoulder_angle + elbow_angle))
    end_y = elbow_y + elbow_length * np.sin(np.radians(shoulder_angle + elbow_angle))

    line_shoulder.set_data([0, shoulder_x], [0, shoulder_y])
    line_elbow.set_data([shoulder_x, elbow_x], [shoulder_y, elbow_y])
    line_arm.set_data([elbow_x, end_x], [elbow_y, end_y])
    point_end.set_data(end_x, end_y)

    coord_x_textbox.set_val('{:.2f}'.format(end_x))
    coord_y_textbox.set_val('{:.2f}'.format(end_y))
    
    elbow_value_write = elbow_slider.val
    shoulder_value_write = shoulder_slider.val
    fig.canvas.draw_idle()

    
elbow_slider.on_changed(update)
shoulder_slider.on_changed(update)
elbow_offset_slider.on_changed(update)
shoulder_offset_slider.on_changed(update)
point_button.on_clicked(on_point_button_click)
play_button.on_clicked(lambda event: on_button_click(repeat_text.text))

update(None)

plt.show()

slider_values = {
    'shoulder_offset': shoulder_offset_slider.val,
    'elbow_offset': elbow_offset_slider.val
}

with open(json_file_path, 'w') as file:
    json.dump(slider_values, file)
