#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    // Categories and products
    string categories[5] = { "Household", "Industrial", "Personal", "Gaming", "Entertainment" };
    string products[5][10] = {
        {"Refrigerator", "Washing Machine", "Microwave", "Vacuum Cleaner", "Toaster", "Blender", "Iron", "Fan", "Air Conditioner", "Dishwasher"},
        {"Drill Machine", "Grinder", "Welding Machine", "Compressor", "Generator", "Lathe Machine", "Cutter", "Sander", "Press", "Pump"},
        {"Smartphone", "Laptop", "Tablet", "Smartwatch", "Headphones", "Camera", "Printer", "Speaker", "Projector", "E-reader"},
        {"Gaming Console", "Gaming PC", "Gaming Chair", "Gaming Mouse", "Gaming Keyboard", "Gaming Headset", "Gaming Monitor", "VR Headset", "Joystick", "Gaming Glasses"},
        {"TV", "Home Theater", "Soundbar", "Streaming Device", "Blu-ray Player", "Karaoke Machine", "Radio", "MP3 Player", "CD Player", "Record Player"}
    };

    // Realistic brands for each product category
    string brands[5][10][3] = {
        { // Household
            {"Samsung", "LG", "Whirlpool"}, {"Samsung", "LG", "Bosch"}, {"Panasonic", "Samsung", "LG"},
            {"Dyson", "Shark", "Hoover"}, {"Philips", "Black+Decker", "Cuisinart"}, {"Ninja", "Vitamix", "Oster"},
            {"Philips", "Tefal", "Rowenta"}, {"Honeywell", "Dyson", "Lask"}, {"Daikin", "Carrier", "LG"},
            {"Bosch", "Whirlpool", "Samsung"}
        },
        { // Industrial
            {"Bosch", "DeWalt", "Makita"}, {"Bosch", "Metabo", "Hitachi"}, {"Lincoln Electric", "Miller", "ESAB"},
            {"Ingersoll Rand", "Atlas Copco", "Sullair"}, {"Honda", "Generac", "Cummins"}, {"Jet", "Grizzly", "Shop Fox"},
            {"Bosch", "Makita", "DeWalt"}, {"Bosch", "Makita", "Dewalt"}, {"Dake", "Baileigh", "Shop Fox"},
            {"Grundfos", "Wilo", "Pentair"}
        },
        { // Personal
            {"Apple", "Samsung", "Google"}, {"Apple", "Dell", "HP"}, {"Apple", "Samsung", "Microsoft"},
            {"Apple", "Samsung", "Fitbit"}, {"Sony", "Bose", "Sennheiser"}, {"Canon", "Nikon", "Sony"},
            {"HP", "Canon", "Epson"}, {"JBL", "Sony", "Bose"}, {"Epson", "BenQ", "Optoma"},
            {"Amazon", "Kobo", "Barnes & Noble"}
        },
        { // Gaming
            {"Sony", "Microsoft", "Nintendo"}, {"Alienware", "ASUS ROG", "MSI"}, {"Secretlab", "DXRacer", "Herman Miller"},
            {"Logitech", "Razer", "SteelSeries"}, {"Corsair", "Razer", "Logitech"}, {"SteelSeries", "HyperX", "Razer"},
            {"ASUS", "Acer", "LG"}, {"Oculus", "HTC", "Sony"}, {"Logitech", "Thrustmaster", "Microsoft"},
            {"Gunnar", "HyperX", "Razer"}
        },
        { // Entertainment
            {"Samsung", "LG", "Sony"}, {"Sony", "Samsung", "LG"}, {"Sonos", "Bose", "Samsung"},
            {"Roku", "Apple TV", "Amazon Fire TV"}, {"Sony", "LG", "Panasonic"}, {"Singing Machine", "Karaoke USA", "Ion Audio"},
            {"Sony", "Panasonic", "Sangean"}, {"Apple", "Sony", "SanDisk"}, {"Sony", "Panasonic", "Philips"},
            {"Audio-Technica", "Pro-Ject", "Sony"}
        }
    };

    // Stock and prices
    int stock[5][10] = {
        {10, 15, 20, 25, 30, 35, 40, 45, 50, 55}, {5, 10, 15, 20, 25, 30, 35, 40, 45, 50},
        {100, 150, 200, 250, 300, 350, 400, 450, 500, 550}, {20, 25, 30, 35, 40, 45, 50, 55, 60, 65},
        {50, 55, 60, 65, 70, 75, 80, 85, 90, 95}
    };
    float cost[5][10] = {
        {50000, 40000, 30000, 20000, 10000, 8000, 5000, 7000, 80000, 60000}, {20000, 15000, 30000, 40000, 50000, 60000, 10000, 12000, 25000, 30000},
        {80000, 100000, 50000, 30000, 20000, 70000, 15000, 12000, 40000, 10000}, {40000, 120000, 30000, 5000, 10000, 15000, 20000, 25000, 8000, 6000},
        {60000, 50000, 30000, 10000, 20000, 15000, 5000, 3000, 4000, 7000}
    };
    float sellingPrice[5][10] = {
        {60000, 50000, 40000, 30000, 15000, 10000, 8000, 10000, 100000, 80000}, {30000, 25000, 40000, 50000, 70000, 80000, 15000, 18000, 35000, 40000},
        {100000, 120000, 70000, 50000, 30000, 90000, 20000, 15000, 50000, 15000}, {50000, 150000, 40000, 10000, 15000, 20000, 30000, 35000, 10000, 8000},
        {80000, 70000, 40000, 15000, 30000, 20000, 8000, 5000, 6000, 10000}
    };

    // Sales and cart
    const int MAX_SALES = 1000;
    string soldProducts[MAX_SALES], soldBrands[MAX_SALES], soldColors[MAX_SALES];
    float soldPrices[MAX_SALES]; // Includes tax
    int soldQuantities[MAX_SALES], salesCount = 0;

    const int MAX_PRODUCTS = 100;
    string selectedProducts[MAX_PRODUCTS], selectedBrands[MAX_PRODUCTS], selectedColors[MAX_PRODUCTS];
    float selectedPrices[MAX_PRODUCTS], selectedTaxes[MAX_PRODUCTS], selectedTotalPrices[MAX_PRODUCTS];
    int productCount = 0;

    bool programRunning = true;
    while (programRunning) {
        // Main menu
        cout << "\n_________________________________________________\n";
        cout << "       WELCOME TO THE ELECTRONICS STORE       \n";
        cout << "\n______________________________________________\n";
        cout << "1. User Processing\n";
        cout << "2. Admin Processing\n";
        cout << "3. Exit Program\n";
        cout << "\n";

        int mainChoice;
        while (true) {
            cout << "\n______________________________________________\n";
            cout << "Select an option (1-3): ";
            cin >> mainChoice;
            cout << "\n______________________________________________\n";
            if (cin.fail() || mainChoice < 1 || mainChoice > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1 and 3.\n";
            }
            else break;
        }

        if (mainChoice == 1) {
            // User Processing
            string name, contact, address;
            int age;

            // Get user details
            cout << "\n______________________________________________\n";
            cout << "\n************  ENTER YOUR DETAILS  ************";
            cout << "\n______________________________________________\n";

            while (true) {
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                bool valid = true;
                for (char c : name) {
                    if (!isalpha(c) && c != ' ') {
                        valid = false;
                        break;
                    }
                }
                if (valid) break;
                cout << "Invalid name! Name should contain only alphabets and spaces.\n";
            }

            while (true) {
                cout << "Age: ";
                cin >> age;
                if (cin.fail() || age < 15 || age > 100) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid age! Age must be between 15 and 100.\n";
                }
                else break;
            }

            while (true) {
                cout << "Contact (11 digits): ";
                cin >> contact;
                if (contact.length() == 11) {
                    bool valid = true;
                    for (char c : contact) {
                        if (!isdigit(c)) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) break;
                }
                cout << "Invalid contact! Must be 11 digits.\n";
            }

            cin.ignore();
            while (true) {
                cout << "Address: ";
                getline(cin, address);
                if (address.length() >= 10) break;
                cout << "Invalid address! Address must be at least 10 characters.\n";
            }

            bool continueShopping = true;
            while (continueShopping) {
                // Display categories
                cout << "\n______________________________________________\n";
                cout << "\n************   SELECT A CATEGORY  ************";
                cout << "\n______________________________________________\n";

                if (age < 18) {
                    cout << "You are under 18. You can only purchase Personal, Gaming, or Entertainment products.\n";
                    cout << "1. Personal\n";
                    cout << "2. Gaming\n";
                    cout << "3. Entertainment\n";
                }
                else {
                    for (int i = 0; i < 5; i++) {
                        cout << i + 1 << ". " << categories[i] << "\n";
                    }
                }

                // Select category
                int categoryChoice;
                while (true) {
                    cout << "\n______________________________________________\n";
                    cout << "\nSelect a category (1-" << (age < 18 ? 3 : 5) << "): ";
                    cin >> categoryChoice;
                    cout << "\n______________________________________________\n";
                    if (cin.fail() || categoryChoice < 1 || categoryChoice >(age < 18 ? 3 : 5)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a number between 1 and " << (age < 18 ? 3 : 5) << ".\n";
                    }
                    else {
                        if (age < 18) {
                            if (categoryChoice == 1) categoryChoice = 2; // Personal
                            else if (categoryChoice == 2) categoryChoice = 3; // Gaming
                            else if (categoryChoice == 3) categoryChoice = 4; // Entertainment
                        }
                        else {
                            categoryChoice--;
                        }
                        break;
                    }
                }

                // Display products
                cout << "\n______________________________________________\n";
                cout << "         PRODUCTS IN "  << "\n______________________________________________\n" << categories[categoryChoice] << "          ";

                cout << "\n______________________________________________\n";
                int productNumber = 1;
                for (int i = 0; i < 10; i++) {
                    if (stock[categoryChoice][i] > 0) {
                        cout << productNumber << ". " << products[categoryChoice][i] << "\n";
                        productNumber++;
                    }
                }

                // Select product
                int productChoice;
                while (true) {
                    cout << "\n______________________________________________\n";
                    cout << "\nSelect a product (1-" << productNumber - 1 << "): ";
                    cin >> productChoice;
                    cout << "\n______________________________________________\n";
                    if (cin.fail() || productChoice < 1 || productChoice > productNumber - 1) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a number between 1 and " << productNumber - 1 << ".\n";
                    }
                    else break;
                }

                // Map product choice to actual index
                int actualIndex = -1, count = 0;
                for (int i = 0; i < 10; i++) {
                    if (stock[categoryChoice][i] > 0) {
                        count++;
                        if (count == productChoice) {
                            actualIndex = i;
                            break;
                        }
                    }
                }

                if (actualIndex == -1) {
                    cout << "\nInvalid product selection.\n";
                    continue;
                }

                // Display brands
                cout << "\n______________________________________________\n";
                cout << "*******         AVAILABLE BRANDS         *******\n";
                cout << "\n______________________________________________\n";
                for (int i = 0; i < 3; i++) {
                    cout << i + 1 << ". " << brands[categoryChoice][actualIndex][i] << "\n";
                }

                // Select brand
                int brandChoice;
                while (true) {
                    cout << "\n______________________________________________\n";
                    cout << "\nSelect a brand (1-3): ";
                    cin >> brandChoice;
                    cout << "\n______________________________________________\n";
                    if (cin.fail() || brandChoice < 1 || brandChoice > 3) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a number between 1 and 3.\n";
                    }
                    else {
                        brandChoice--;
                        break;
                    }
                }

                // Select color
                string color;
                cout << "\nEnter the color name of the product: \nRed\nBlack\nWhite \n";
                cin >> color;

                // Display specifications
                cout << "\n______________________________________________\n";
                cout << "*****        PRODUCT SPECIFICATIONS        *****\n";
                cout << "\n______________________________________________\n";
                cout << "Product: " << brands[categoryChoice][actualIndex][brandChoice] << " " << products[categoryChoice][actualIndex] << "\n";
                cout << "Color: " << color << "\n";
                cout << "Warranty: 1 year\n";

                // Calculate price with tax
                float price = sellingPrice[categoryChoice][actualIndex]; // Already in rupees
                float tax = price * 0.05;
                float totalPrice = price + tax;

                // Save selected product details
                selectedProducts[productCount] = products[categoryChoice][actualIndex];
                selectedBrands[productCount] = brands[categoryChoice][actualIndex][brandChoice];
                selectedColors[productCount] = color;
                selectedPrices[productCount] = price;
                selectedTaxes[productCount] = tax;
                selectedTotalPrices[productCount] = totalPrice;
                productCount++;

                // Update stock
                stock[categoryChoice][actualIndex]--;

                // Save sales information (including tax)
                soldProducts[salesCount] = products[categoryChoice][actualIndex];
                soldBrands[salesCount] = brands[categoryChoice][actualIndex][brandChoice];
                soldColors[salesCount] = color;
                soldPrices[salesCount] = totalPrice; // Store total price (including tax)
                soldQuantities[salesCount] = 1;
                salesCount++;

                // Display cart
                cout << "\n______________________________________________\n";
                cout << "                YOUR CART                       \n";
                cout << "\n______________________________________________\n";
                float total = 0.0;
                for (int i = 0; i < productCount; i++) {
                    cout << i + 1 << ". " << selectedBrands[i] << " " << selectedProducts[i] << " (" << selectedColors[i] << ") - Rs." << selectedTotalPrices[i] << "\n";
                    total += selectedTotalPrices[i];
                }
                cout << "\n______________________________________________\n";
                cout << "Total: Rs." << total << "\n";
                cout << "\n";

                // Purchase options
                int purchaseOption;
                while (true) {
                    cout << "\n______________________________________________\n";
                    cout << "*              PURCHASE OPTIONS                *\n";
                    cout << "\n______________________________________________\n";
                    cout << "1. Continue Shopping\n";
                    cout << "2. Proceed to Payment\n";
                    cout << "3. Cancel Purchase\n";
                    cout << "Select an option (1-3): ";
                    cin >> purchaseOption;
                    if (cin.fail() || purchaseOption < 1 || purchaseOption > 3) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a number between 1 and 3.\n";
                    }
                    else break;
                }

                if (purchaseOption == 2) {
                    // Calculate total bill
                    float totalBill = 0.0;
                    for (int i = 0; i < productCount; i++) {
                        totalBill += selectedTotalPrices[i];
                    }

                    // Apply discounts
                    float discount = 0.0;
                    if (totalBill > 500000) discount = 0.10;
                    else if (totalBill > 300000) discount = 0.08;
                    else if (totalBill > 100000) discount = 0.05;

                    float discountedTotal = totalBill * (1 - discount);

                    // Delivery options
                    int deliveryOption;
                    while (true) {
                        cout << "\n______________________________________________\n";
                        cout << "1. Pick Up\n";
                        cout << "2. Home Delivery (Rs. 2000 delivery charges)\n";
                        cout << "Select an option (1-2): ";
                        cin >> deliveryOption;
                        if (cin.fail() || deliveryOption < 1 || deliveryOption > 2) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter 1 or 2.\n";
                        }
                        else break;
                    }

                    // Add delivery charges if home delivery is selected
                    if (deliveryOption == 2) {
                        discountedTotal += 2000;
                    }

                    int paymentOption = 0;
                    if (deliveryOption == 1) {
                        // Pickup options
                        while (true) {
                            cout << "\n______________________________________________\n";
                            cout << "*               PAYMENT OPTIONS                *\n";
                            cout << "\n______________________________________________\n";
                            cout << "1. Digital Payment\n";
                            cout << "2. Cash Payment\n";
                            cout << "Select an option (1-2): ";
                            cin >> paymentOption;
                            if (cin.fail() || paymentOption < 1 || paymentOption > 2) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input. Please enter 1 or 2.\n";
                            }
                            else break;
                        }
                    }
                    else {
                        // Home delivery options
                        while (true) {
                            cout << "\n______________________________________________\n";
                            cout << "          PAYMENT OPTIONS            \n";
                            cout << "\n______________________________________________\n";
                            cout << "1. Payment on Delivery\n";
                            cout << "2. Payment Now\n";
                            cout << "Select an option (1-2): ";
                            cin >> paymentOption;
                            if (cin.fail() || paymentOption < 1 || paymentOption > 2) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input. Please enter 1 or 2.\n";
                            }
                            else break;
                        }

                        if (paymentOption == 1) {
                            cout << "\nYou can take the products now and pay on delivery.\n";
                        }
                        else {
                            // Payment Now options
                            while (true) {
                                cout << "\n______________________________________________\n";
                                cout << "*                PAYMENT METHOD             *\n";
                                cout << "\n______________________________________________\n";
                                cout << "1. Digital Payment\n";
                                cout << "2. Cash Payment\n";
                                cout << "Select an option (1-2): ";
                                cin >> paymentOption;
                                if (cin.fail() || paymentOption < 1 || paymentOption > 2) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Invalid input. Please enter 1 or 2.\n";
                                }
                                else break;
                            }
                        }
                    }

                    // Generate bill slip
                    cout << "\n______________________________________________\n";
                    cout << "              BILL SLIP              \n";
                    cout << "\n______________________________________________\n";
                    cout << "Name: " << name << "\n";
                    cout << "Contact: " << contact << "\n";
                    cout << "Address: " << address << "\n";
                    cout << "Payment Method: " << (paymentOption == 1 ? "Digital" : "Cash") << "\n";
                    cout << "Delivery Option: " << (deliveryOption == 1 ? "Pick Up" : "Home Delivery") << "\n";
                    cout << "\nITEMS:\n";
                    for (int i = 0; i < productCount; i++) {
                        cout << i + 1 << ". " << selectedBrands[i] << " " << selectedProducts[i] << " (" << selectedColors[i] << ") - Rs." << selectedTotalPrices[i] << "\n";
                    }
                    cout << "\nSubtotal: Rs." << totalBill << "\n";
                    if (discount > 0) {
                        cout << "Discount (" << discount * 100 << "%): Rs." << totalBill * discount << "\n";
                    }
                    if (deliveryOption == 2) {
                        cout << "Delivery Charges: Rs. 2000\n";
                    }
                    cout << "\n______________________________________________\n";
                    cout << "Total: Rs." << discountedTotal << "\n";
                    cout << "\n______________________________________________\n";

                    continueShopping = false;
                    productCount = 0;
                }
                else if (purchaseOption == 3) {
                    cout << "\nPurchase canceled. Returning to main menu.\n";
                    continueShopping = false;
                    productCount = 0;
                }
            }
        }
        else if (mainChoice == 2) {
            // Admin Processing
            int adminCode;
            cout << "\n______________________________________________\n";
            cout << "*            ADMIN PROCESSING                 *\n";
            cout << "\n______________________________________________\n";
            while (true) {
                cout << "Enter admin code: ";
                cin >> adminCode;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid number.\n";
                }
                else break;
            }

            if (adminCode == 4321) {
                bool adminMenu = true;
                while (adminMenu) {
                    cout << "\n______________________________________________\n";
                    cout << "                   ADMIN MENU                  \n";
                    cout << "\n______________________________________________\n";
                    cout << "1. View Sales Report\n";
                    cout << "2. View Stock\n";
                    cout << "3. Restock Products\n";
                    cout << "4. Exit Admin Menu\n";
                    cout << "Select an option (1-4): ";

                    int adminChoice;
                    cin >> adminChoice;

                    if (adminChoice == 1) {
                        // Sales Report
                        cout << "\n______________________________________________\n";
                        cout << "                  SALES REPORT               \n";
                        cout << "\n______________________________________________\n";
                        float totalSales = 0.0;
                        float totalCost = 0.0;
                        for (int i = 0; i < salesCount; i++) {
                            totalSales += soldPrices[i] * soldQuantities[i]; // soldPrices includes tax
                            for (int j = 0; j < 5; j++) {
                                for (int k = 0; k < 10; k++) {
                                    if (products[j][k] == soldProducts[i]) {
                                        totalCost += cost[j][k] * soldQuantities[i];
                                        break;
                                    }
                                }
                            }
                        }
                        float totalProfit = totalSales - totalCost;
                        cout << "Total Sales (including tax): Rs." << totalSales << "\n";
                        cout << "Total Cost: Rs." << totalCost << "\n";
                        cout << "Total Profit: Rs." << totalProfit << "\n";
                    }
                    else if (adminChoice == 2) {
                        // View Stock
                        cout << "\n______________________________________________\n";
                        cout << "*              CURRENT STOCK              *\n";
                        cout << "\n______________________________________________\n";
                        for (int i = 0; i < 5; i++) {
                            cout << "\nCategory: " << categories[i] << "\n";
                            for (int j = 0; j < 10; j++) {
                                cout << j + 1 << ". " << products[i][j] << " (Stock: " << stock[i][j] << ")\n";
                            }
                        }
                    }
                    else if (adminChoice == 3) {
                        // Restock Products
                        cout << "\n______________________________________________\n";
                        cout << "                RESTOCK PRODUCTS           \n";
                        cout << "\n______________________________________________\n";

                        // Display available categories
                        cout << "Available Categories:\n";
                        for (int i = 0; i < 5; i++) {
                            cout << i + 1 << ". " << categories[i] << "\n";
                        }

                        // Ask for category choice
                        int categoryChoice;
                        cout << "Enter the number of the category you want to restock: ";
                        cin >> categoryChoice;

                        // Validate category choice
                        if (categoryChoice < 1 || categoryChoice > 5) {
                            cout << "Invalid category choice!\n";
                            return 0;
                        }

                        // Display products in the selected category
                        cout << "\n______________________________________________\n";
                        cout << "\nProducts in " << categories[categoryChoice - 1] << ":\n";
                        for (int j = 0; j < 10; j++) {
                            cout << j + 1 << ". " << products[categoryChoice - 1][j] << " (Current Stock: " << stock[categoryChoice - 1][j] << ")\n";
                        }

                        // Ask for product choice
                        int productChoice;
                        cout << "Enter the number of the product you want to restock: ";
                        cin >> productChoice;

                        // Validate product choice
                        if (productChoice < 1 || productChoice > 10) {
                            cout << "Invalid product choice!\n";
                            return 0;
                        }

                        // Ask for new stock quantity
                        int newStock;
                        cout << "Enter new stock quantity for " << products[categoryChoice - 1][productChoice - 1] << ": ";
                        cin >> newStock;

                        // Validate and update stock
                        if (newStock >= 0) {
                            stock[categoryChoice - 1][productChoice - 1] = newStock;
                            cout << "Stock updated successfully!\n";
                        }
                        else {
                            cout << "Invalid quantity! Stock not changed.\n";
                        }
                    }
                    else if (adminChoice == 4) {
                        adminMenu = false;
                        cout << "\nExiting admin menu...\n";
                    }
                    else {
                        cout << "Invalid choice! Please try again.\n";
                    }
                }
            }
            else {
                cout << "\nIncorrect code. Access denied.\n";
            }
        }
        else if (mainChoice == 3) {
            cout << "\nExiting program. Goodbye!\n";
            programRunning = false;
        }
    }

    return 0;
}