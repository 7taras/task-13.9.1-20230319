#pragma once
#include <string>

#define USERCOUNT 20

class SocialNetwork
{
public:
	SocialNetwork();

	class User
	{
	public:
		User(int _id, std::string _name) : id(_id), name(_name){}
		int id;
		std::string name;
	};

	void addUser(int id, std::string& name);
	void addLink(int id1, int id2);
	void deleteUser(int id);
	void deleteLink(int id1, int id2);

private:
	bool userExists(int id);
	bool linkExists(int id1, int id2);
	bool matrix[USERCOUNT][USERCOUNT]{ false };
	int usersCount{ 0 };
	User* users[USERCOUNT]{ nullptr };
};

