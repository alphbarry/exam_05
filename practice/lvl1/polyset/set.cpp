#include "set.hpp"

set::set() : bag_ref() {}

set::set(searchable_bag &b) : bag_ref(&b) {}

set::set(const set &other) : bag_ref(other.bag_ref) {}

set &set::operator=(const set &other) {
	if (this != &other)
		bag_ref = other.bag_ref;
	return *this;
}

set::~set() {}

void set::insert(int value){
	if (bag_ref != 0 && !bag_ref->has(value))
		bag_ref->insert(value);
}

void set::insert(int *values, int count){
	if (bag_ref == 0)
		return;
	for (int i = 0; i < count; ++i){
		if (!bag_ref->has(values[i]))
			insert(values[i]);
	}
}

bool set::has(int value) const{
	return bag_ref->has(value);
}

void set::print() const{
	bag_ref->print();
}

void set::clear() {
	bag_ref->clear();
}

const searchable_bag &set::get_bag() const{
	return *bag_ref;
}
