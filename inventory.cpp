
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>  
#include <iomanip>

using namespace std;

// Structure to represent an inventory bin
struct Bin {
    string description;
    int quantity;
};

// Function prototypes
void AddParts(Bin bins[], int index, int quantity);
void RemoveParts(Bin bins[], int index, int quantity);
void Display(const Bin bins[]);

int main() {
    
    // Array to store the 10 bins
    Bin bins[10];

    // Open the inventory file
    ifstream myIn;
    myIn.open("inventory.dat");
    assert(myIn);  // Make sure the file is open correctly

    // Populate the bins with inventory data
    for (int i = 0; i < 10; ++i) {
        getline(myIn, bins[i].description); // Read part description
        myIn >> bins[i].quantity; // Read part quantity
        myIn.ignore(); // ignores  newline characterss
    }

    myIn.close();  // Close file

    // Display warehouse inventory 
    cout << "Warehouse inventory before the operations\n"; 
    cout << endl; 
    cout << "Part               Quantity\n"; 
    cout << endl;
    Display(bins);

    // Open the operations file
    ifstream myOp;
    myOp.open("operations.dat");
    assert(myOp);  // Make sure the file is open correctly

    string operation, partName;
    int quantity;

    // Loop through each operation in the file and perform the necessary action
    while (myOp >> operation) {
        myOp.ignore(); // To ignore the newline after operation
        getline(myOp, partName); // Read part name
        myOp >> quantity;        
        myOp.ignore();          

        // Find the index of the part in the bins array
        int index = -1;
        for (int i = 0; i < 10; ++i) {
            if (bins[i].description == partName) {
                index = i;
                break;
            }
        }

        // Check if the operation is "Add" or "Remove" and perform the action
        if (index != -1) {
            if (operation == "Add") { 
                AddParts(bins, index, quantity);
            } else if (operation == "Remove") {
                RemoveParts(bins, index, quantity);
            }
        }
    }

    myOp.close();  //close file

    // Display warehouse inventory after operations
    cout << "\nWarehouse inventory after the operations\n"; 
    cout << endl; 
    cout << "Part               Quantity\n"; 
    cout << endl; 
    Display(bins);

    return 0;
}

// Function to add parts to a bin
void AddParts(Bin bins[], int index, int quantity) {
    bins[index].quantity += quantity;
}

// Function to remove parts from a bin
void RemoveParts(Bin bins[], int index, int quantity) {
    if (bins[index].quantity >= quantity) {
        bins[index].quantity -= quantity;
    } else {
        cout << "Error! Not enough parts to remove from bin " << bins[index].description << endl;
    }
}

// Function to display the inventory
void Display(const Bin bins[]) {
    for (int i = 0; i < 10; ++i) {
        cout << left << setw(17) << bins[i].description << "  " << bins[i].quantity << endl;
    }
}
