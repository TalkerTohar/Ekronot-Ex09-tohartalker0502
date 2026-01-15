#pragma once
#include "DeviceList.h"

class User
{
public:
	// initializes a new user with id, username and age
	void init(const unsigned int id, const std::string username, const unsigned int age);

	// releases momory allocated and clears object
	void clear();

	// getters
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices();

	// adds a Device object to the user's devices list
	void addDevice(const Device newDevice);

	// return false if there is a device which is NOT active
	bool checkIfDevicesAreOn() const;

private:

	// fields
	unsigned int _id;
	std::string _username;
	unsigned int age;
	DevicesList _devices;
};

