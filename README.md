# Inventory Management System in C++

This C++ program simulates inventory management for a warehouse. It reads inventory data and operations from two external files: `inventory.dat` and `operations.dat`. The program then updates the inventory bins based on the operations (adding or removing parts) and displays the inventory before and after the operations are executed. The program uses functions to handle adding and removing parts, as well as displaying the updated inventory in a neat table format.

## Key Features:

- Reads inventory data from a file and stores it in an array of structs.
- Performs add/remove operations based on the data from the operations file.
- Displays inventory before and after performing the operations.

## Sample Files

**inventory.dat** (plaintext):
Valve 10 Bearing 5 Bushing 15 Coupling 21 Flange 7 Gear 5 Gear Housing 5 Vacuum Gripper 25 Cable 18 Rod 12

markdown
Copy
Edit

**operations.dat** (plaintext):
Add Flange 3 Remove Rod 2 Remove Gear Housing 1 Add Valve 5 Add Vacuum Gripper 10 Remove Bushing 5 Add Coupling 4 Remove Vacuum Gripper 5

shell
Copy
Edit

## Sample Bash Commands

### Before Operations:

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
bash
Copy
Edit
$ ./inventory
Warehouse inventory after the operations

Part               Quantity
Valve              15
Bearing            5
Bushing            10
Coupling           25
Flange             10
Gear               5
Gear Housing       4
Vacuum Gripper     30
Cable              18
Rod                10
How to Run:
Compile the program using g++:

bash
Copy
Edit
g++ inventory.cpp -o inventory
