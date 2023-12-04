#include <iostream>
#include <fstream>
#include "Parser.h"
#include "ActorDB.h"

using namespace std;

ActorDB actordb;

void do_register_actor(unsigned int actor_id, string actor_last, string actor_first) {
    Actor a(actor_id, actor_last, actor_first);
    if (actordb.addActor(a)) 
        cout << "register_actor: Registered actor " << a.getName() << endl;
    else
        cout << "register_actor: Error actor id " << actor_id << " already in use" << endl;
    return;
}

bool expected(Parser &p, unsigned int howmany) {
    if (p.numArgs() < howmany) { 
        cout << endl << "Can't operate with " << MISSING_ARGS << endl;
        return false;
    }
    if (p.numArgs() > howmany) {
        cout << endl << "Ignoring " << UNEXPECTED_ARGS << endl; 
        return true;
    }
    return true;
}

bool assertInt(Parser &p, unsigned int argnum) {
    if (!Parser::isInteger(p.getArg(argnum))) {
        cout << "Error: field " << p.getArg(argnum) << " is not an integer" << endl;
        return false;
    }
    return true;
}

bool accept_commands(istream &is, bool silent = false, bool echo = false) {
    string line;

    while (1) {
        if (!silent) {
            cout << endl << "Enter a command: " << endl;
            cout << "Choose from " << endl <<
                "   register_actor <actorid> <last> <first>" << endl <<
                "   quit" << endl; 
            cout << ": ";
        }

        getline(is, line);
        if (echo) {
            cout << endl;
            cout << "======================================================" << endl;
            cout << line << endl;
            cout << "======================================================" << endl;
        }

        Parser p(line);
        if (p.getOperation().empty()) {
            if (is.fail())
                return false;
            continue;
        }

        if (p.getOperation() == "quit") {
            expected(p, 0);
            return true;
        } else if (p.getOperation() == "register_actor") {
            if (!expected(p, 3))  
                continue;
            if (!assertInt(p, 1))
                continue;
            int actor_id = stoi(p.getArg(1));
            do_register_actor(actor_id, p.getArg(2), p.getArg(3));
        } else {
            cout << std::endl << "Command not recognized. Please try again." << endl; 
        }
    }
    return true;
}

int main() {
    accept_commands(cin, false, false);
    return 0;
}
