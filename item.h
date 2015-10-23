#pragma once
#include <string>

using namespace std;

class item {
private:
	string name;
	int num;
	int qty;
	int price;
public:
	item() : name("default"), num(0), qty(0), price(0) {
	}

	item(item &_item) :
		name(_item.getName()),
		num(_item.getNum()),
		qty(_item.getQuant()),
		price(_item.getPrice()) {
	}

	item(string _name, int _num, int _qty, int _price) :
		name(_name), num(_num), qty(_qty), price(_price) {
	}

	string getName() {
		return name;
	}

	int getNum() {
		return num;
	}

	int getQuant() {
		return qty;
	}

	int getPrice() {
		return price;
	}

	bool addToStack(int amount) {
		qty += amount;
		return true;
	}
};