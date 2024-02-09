import matplotlib.pyplot as plt

# Coordinates for Recursive Merge Sort
x_recursive = [200, 700, 1500, 2000, 3000]
y_recursive = [6.1e-05, 0.000252, 0.000503, 0.000708, 0.001125]

# Coordinates for Non-Recursive Merge Sort
x_non_recursive = [200, 700, 1500, 2000, 3000]
y_non_recursive = [6.9e-05, 0.00023, 0.000537, 0.000729, 0.00113]

plt.plot(x_recursive, y_recursive, marker='o', linestyle='-', color='orange', label='Recursive Merge Sort')
plt.plot(x_non_recursive, y_non_recursive, marker='o', linestyle='-', color='blue', label='Non-Recursive Merge Sort')

plt.title('Merge Sort Performance')
plt.xlabel('Number of Elements in Array')
plt.ylabel('Time (seconds)')
plt.legend()
plt.grid(True)
plt.show()
