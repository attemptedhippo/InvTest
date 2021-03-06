#pragma once
#include <list>
#include <utility>
#include <memory>
#include "item.h"

class bag {
private:
	std::list<std::unique_ptr<item>> inventory;

public:
	const unsigned int maxItem;

	bag() : maxItem(10) { }
	bag(int _maxItem) : maxItem(_maxItem) { }

	bool add(std::unique_ptr<item> item) {
		if (maxItem > 0 && inventory.size() >= maxItem) {
			//Inventory full
			std::cout << "couldnt add item\n";
			return false;
		}else {
			inventory.push_back(move(item));
			return true;
		}
	}

	item* get(int _itemID) {
		for (std::list<std::unique_ptr<item>>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
			if (it->get()->getNum() == _itemID) {
				return it->get();
			}
		}
		return nullptr;
	}

	std::list<std::unique_ptr<item>>::iterator begin() {
		return inventory.begin();
	}

	unsigned int size() {
		return inventory.size();
	}
};
