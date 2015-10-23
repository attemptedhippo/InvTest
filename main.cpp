#include <iostream>
#include <list>
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

	cout << "In store:\nThe shop has " << storeInv.size() << " items.\n";
	for (int i = 0; i < inventory.maxItem; i++) {
		if (inventory.get(i) != nullptr) {
			cout << storeInv.get(i)->getQuant() << "x " << storeInv.get(i)->getName() << " : $" << storeInv.get(i)->getPrice() << endl;
		}
		else {
			//cout << "Item number " << i << " cannot be found!\n";
		}
	}

	cout << "\nIn inventory:\nYou have " << inventory.size() << " items.\n";
	for (int i = 0; i < inventory.maxItem; i++) {
		if (inventory.get(i) != nullptr) {
			cout << inventory.get(i)->getQuant() << "x " << inventory.get(i)->getName() << " : $" << inventory.get(i)->getPrice() << endl;
		}
		else {
			//cout << "Item number " << i << " cannot be found!\n";
		}
	}
	cin.get();

	return 0;
}