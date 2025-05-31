import matplotlib.pyplot as plt  # Import the plotting library to visualize the servo motion

# Initialize lists to keep track of time and servo angles for plotting later
time_points = []
myservo_angles = []
myservo2_angles = []

# Starting state before anything begins
current_time = 0.0  # We start counting time from 0 seconds
myservo_current_angle = 0  # Servo 1 starts at 0 degrees
myservo2_current_angle = 0 # Servo 2 also starts at 0 degrees

# Save this initial state so the plot includes the starting point
time_points.append(current_time)
myservo_angles.append(myservo_current_angle)
myservo2_angles.append(myservo2_current_angle)

# --- Simulating what would happen inside loop() in an Arduino sketch ---

# Step 1: Move Servo 1 from 0 to 90 degrees, increasing 1 degree at a time
# Each movement takes 0.1 seconds
for pos in range(0, 91):  # This loop runs from 0 up to and including 90
    myservo_current_angle = pos  # Update Servo 1's angle
    current_time += 100 / 1000.0  # Add 100 milliseconds to the simulated time
    
    # Log the current state
    time_points.append(current_time)
    myservo_angles.append(myservo_current_angle)
    myservo2_angles.append(myservo2_current_angle)  # Servo 2 stays still during this phase

# Step 2: Wait for 1 second before moving Servo 2
current_time += 1000 / 1000.0  # Simulate the 1-second pause

# Log the current state after the delay — no angles change here
time_points.append(current_time)
myservo_angles.append(myservo_current_angle)
myservo2_angles.append(myservo2_current_angle)

# Step 3: Now move Servo 2 from 0 to 90 degrees (1 degree at a time)
# Again, each step takes 0.1 seconds
for pos in range(0, 91):  # Same as before, but now for Servo 2
    myservo2_current_angle = pos  # Update Servo 2's angle
    current_time += 100 / 1000.0  # Simulate 100ms delay
    
    # Log this state
    time_points.append(current_time)
    myservo_angles.append(myservo_current_angle)  # Servo 1 stays constant now
    myservo2_angles.append(myservo2_current_angle)

# Step 4: Add a short 0.5 second pause before the next movement
current_time += 500 / 1000.0  # Simulate 0.5 seconds passing

# Record the state after the delay
time_points.append(current_time)
myservo_angles.append(myservo_current_angle)
myservo2_angles.append(myservo2_current_angle)

# Step 5: Both servos move back from 90 to 0 degrees
# This time, the change is in steps of 10 degrees, and both move together
for pos in range(90, -1, -10):  
    myservo_current_angle = pos
    myservo2_current_angle = pos
    current_time += 100 / 1000.0  # Each step still takes 0.1 seconds
    
    # Record this synchronized movement
    time_points.append(current_time)
    myservo_angles.append(myservo_current_angle)
    myservo2_angles.append(myservo2_current_angle)


# --- Time to visualize the simulation! ---
plt.figure(figsize=(12, 6))  # Make the plot a decent size so everything is readable

# Plot both servos’ angles over time
plt.plot(time_points, myservo_angles, label='Servo 1 (Link 1)')
plt.plot(time_points, myservo2_angles, label='Servo 2 (Link 2)', linestyle='--')  # Dashed line for differentiation

# Add labels and a title to make the plot clear
plt.title('Simulated Angle Rotations of Robotic Arm Links Over Time')
plt.xlabel('Time (seconds)')
plt.ylabel('Angle (degrees)')
plt.grid(True)  # Add grid lines to improve readability
plt.legend()  # Show which line is which
plt.tight_layout()
plt.show()