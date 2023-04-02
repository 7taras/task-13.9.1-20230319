#include "SocialNetwork.h"

SocialNetwork::SocialNetwork() {
    for (int i = 0; i < USERCOUNT; i++)
        for (int j = 0; j < USERCOUNT; j++)
            matrix[i][j] = false;
    usersCount = 0;
}

void SocialNetwork::addUser(int id, std::string& name)
{
    User* newUser = new User(id, name);
    users[usersCount] = newUser;
    usersCount++;
}

void SocialNetwork::addLink(int id1, int id2)
{
    matrix[id1][id2] = true;
    matrix[id2][id1] = true;
}

void SocialNetwork::deleteLink(int id1, int id2)
{
    matrix[id1][id2] = false;
    matrix[id2][id1] = false;
}

bool SocialNetwork::userExists(int id)
{
    for (int i = 0; i < usersCount; ++i)
    {
        if (users[i]->id == id) return true;
    }
    return false;
}


bool SocialNetwork::linkExists(int id1, int id2)
{
    return matrix[id1][id2];
}

void SocialNetwork::deleteUser(int id)
{
    User* current = 0;
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i]->id == id) current = users[i];
    }
    
    for (int i = 0; i < USERCOUNT; i++)
    {
        matrix[i][id] = 0;
        matrix[id][i] = 0;
    }

    int foundIndex = -1;
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i] == current)
            foundIndex = i;
    }
    usersCount--;
    for (int i = foundIndex; i < usersCount; i++)
    {
        users[i] = users[i + 1];
    }
    delete current;
}

