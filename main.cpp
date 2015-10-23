#include <iostream>
#include "item.h"
#include "bag.h"
#include "itemDefines.h"

using namespace std;

int main() {

	bag storeInv;
	bag inventory;
	storeInv.add(unique_ptr<item>(ITEM_RPOTION(5)));
	storeInv.add(unique_ptr<item>(ITEM_ISWORD(5)));
	storeInv.add(unique_ptr<item>(ITEM_ICHEST(5)));
	storeInv.add(unique_ptr<item>(ITEM_ILEGS(5)));

	inventory.add(unique_ptr<item>(ITEM_RPOTION(1)));
	inventory.add(unique_ptr<item>(ITEM_ISWORD(1)));
	inventory.add(unique_ptr<item>(ITEM_ILEGS(1)));

	cout << "In store:\n";
	for (auto &i : (storeInv.begin())) { // wat do?
		if (storeInv.get(i) != nullptr) {//I know the code in the loop is wrong
			cout << storeInv.get(i)->getQuant() << "x " << storeInv.get(i)->getName() << " : $" << storeInv.get(i)->getPrice() << endl;
		}
	}
	
	cout << "\nIn inventory:\n";
	for (int i = 0; i < inventory.maxItem; i++) {
		if (inventory.get(i) != nullptr) {
			cout << inventory.get(i)->getQuant() << "x " << inventory.get(i)->getName() << " : $" << inventory.get(i)->getPrice() << endl;
		}
	}
	cin.get();

	return 0;
}