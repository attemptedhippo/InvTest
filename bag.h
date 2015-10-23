#pragma once
#include <list>
#include <utility>
#include <memory>
#include "item.h"

using namespace std;

class bag {
private:
	list<unique_ptr<item>> inventory;

public:
	const unsigned int maxItem;
	
	bag() : maxItem(10) { }
	bag(int _maxItem) : maxItem(_maxItem) { }

	bool add(std::unique_ptr<item> item) {
		if (maxItem > 0 && inventory.size() >= maxItem) {
			//Inventory full
			cout << "couldnt add item\n";
			return false;
		}else {
			inventory.push_back(move(item));
			return true;
		}
	}

	item* get(int _itemID) {

		for (list<unique_ptr<item>>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			if (it->get()->getNum() == _itemID) {
				return it->get();
			}
		}
		return nullptr;
	}

	unsigned int size() {
		return inventory.size();
	}
};