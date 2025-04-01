# Inventory Management System in C++

This C++ program simulates inventory management for a warehouse. It reads inventory data and operations from two external files: `inventory.dat` and `operations.dat`. The program then updates the inventory bins based on the operations (adding or removing parts) and displays the inventory before and after the operations are executed. The program uses functions to handle adding and removing parts, as well as displaying the updated inventory in a neat table format.

## Key Features:

- Reads inventory data from a file and stores it in an array of structs.
- Performs add/remove operations based on the data from the operations file.
- Displays inventory before and after performing the operations.


```bash
$ ./inventory
Warehouse inventory before the operations

Part               Quantity
Valve              10
Bearing            5
Bushing            15
Coupling           21
Flange             7
Gear               5
Gear Housing       5
Vacuum Gripper     25
Cable              18
Rod                12

After Operations:
$ ./inventory
Warehouse inventory after the operations

Part               Quantity
Valve              25
Bearing            5
Bushing            10
Coupling           25
Flange             10
Gear               19
Gear Housing       4
Vacuum Gripper     30
Cable              18
Rod                10
