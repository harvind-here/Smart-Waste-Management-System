import gradio as gr
import numpy as np
from datetime import datetime, timedelta

# Define the UI components
bin_status = gr.Blocks()
with bin_status:
    gr.Markdown("# Bin Status")
    bin_level = gr.Plot(
        value=None,
        label="Bin Level"
    )
    bin_image = gr.Image(label="Bin Image")
    bin_location = gr.Textbox(label="Location")
    bin_alerts = gr.Textbox(label="Alerts")

# Define the function to update the UI
def update_bin_status(bin_data):
    bin_level.plot(bin_data["levels"], Label='Time', ylabel='Level (%)')
    bin_image.value = bin_data["image"]
    bin_location.value = bin_data["location"]
    bin_alerts.value = bin_data["alerts"]

# Create a mock data generator for demonstration
def mock_data_generator():
    while True:
        levels = np.random.rand(10) * 100
        times = [datetime.now() + timedelta(minutes=i) for i in range(10)]
        bin_data = {
            "levels": list(zip(times, levels)),
            "image": "Downloads\\img1.jpeg",
            "location": "123 Main St, India",
            "alerts": "Bin level reached 80%",
        }
        yield bin_data

import time
from threading import Thread

# ... (rest of the code remains the same) ...

# Define a function to continuously update the UI with mock data
def update_ui_with_mock_data():
    data_generator = mock_data_generator()
    while True:
        bin_data = next(data_generator)
        update_bin_status(bin_data)
        time.sleep(5)  # Wait for 5 seconds before generating the next data point

# Start a separate thread to update the UI with mock data
ui_thread = Thread(target=update_ui_with_mock_data)
ui_thread.start()

# Start the Gradio app
data_generator = mock_data_generator()
bin_status.launch(share=True, server_port=#****)
