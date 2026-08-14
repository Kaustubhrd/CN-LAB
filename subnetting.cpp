#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {

    string ip;

    cout << "Enter an IP address: ";
    cin >> ip;

    // Get the first octet
    stringstream ss(ip);
    string firstPart;

    getline(ss, firstPart, '.');

    int first_octet = stoi(firstPart);

    if (first_octet >= 1 && first_octet <= 126) {

        cout << "\nClass A" << endl;
        cout << "Range: 1.0.0.0 - 126.255.255.255" << endl;

        cout << "Binary Reason:" << endl;
        cout << "  First bit is fixed as 0" << endl;
        cout << "  Pattern: 0xxxxxxx" << endl;

        cout << "Default Subnet Mask: 255.0.0.0 (/8)" << endl;

        cout << "No of Networks: 2^7 - 2 = 126" << endl;

        cout << "Reason:" << endl;
        cout << "  - First bit is fixed as 0, leaving 7 bits for network IDs."
             << endl;
        cout << "  - Therefore, Number of Networks = 2^7." << endl;
        cout << "  - Subtract 2 because Network 0 is reserved and Network 127 "
             << "is reserved for Loopback." << endl;

        cout << "No of Hosts: 2^24 - 2 = 16,777,214" << endl;

        cout << "Reason:" << endl;
        cout << "  - 24 bits are available for host IDs." << endl;
        cout << "  - Subtract 2 because one address is the Network Address "
             << "and one is the Broadcast Address." << endl;
    }

    else if (first_octet == 127) {

        cout << "\nLoopback Address" << endl;
        cout << "Range: 127.0.0.0 - 127.255.255.255" << endl;
        cout << "Binary: 01111111" << endl;

        cout << "Reason:" << endl;
        cout << "  - Reserved by the IPv4 standard for loopback testing."
             << endl;
        cout << "  - Used to test the local machine." << endl;
        cout << "  - Any packet sent to a 127.x.x.x address is returned to "
             << "the same computer instead of being sent over the network."
             << endl;
    }

    else if (first_octet >= 128 && first_octet <= 191) {

        cout << "\nClass B" << endl;
        cout << "Range: 128.0.0.0 - 191.255.255.255" << endl;

        cout << "Binary Reason:" << endl;
        cout << "  First two bits are fixed as 10" << endl;
        cout << "  Pattern: 10xxxxxx" << endl;

        cout << "Default Subnet Mask: 255.255.0.0 (/16)" << endl;

        cout << "No of Networks: 2^14 = 16,384" << endl;

        cout << "Reason:" << endl;
        cout << "  - First 2 bits are fixed as 10." << endl;
        cout << "  - Remaining 6 bits in the first octet + 8 bits in the "
             << "second octet = 14 network bits." << endl;
        cout << "  - Therefore, Number of Networks = 2^14." << endl;

        cout << "No of Hosts: 2^16 - 2 = 65,534" << endl;

        cout << "Reason:" << endl;
        cout << "  - 16 bits are available for host IDs." << endl;
        cout << "  - Subtract 2 because one address is the Network Address "
             << "and one is the Broadcast Address." << endl;
    }

    else if (first_octet >= 192 && first_octet <= 223) {

        cout << "\nClass C" << endl;
        cout << "Range: 192.0.0.0 - 223.255.255.255" << endl;

        cout << "Binary Reason:" << endl;
        cout << "  First three bits are fixed as 110" << endl;
        cout << "  Pattern: 110xxxxx" << endl;

        cout << "Default Subnet Mask: 255.255.255.0 (/24)" << endl;

        cout << "No of Networks: 2^21 = 2,097,152" << endl;

        cout << "Reason:" << endl;
        cout << "  - First 3 bits are fixed as 110." << endl;
        cout << "  - Remaining 5 bits in the first octet + 8 bits in the "
             << "second octet + 8 bits in the third octet = 21 network bits."
             << endl;
        cout << "  - Therefore, Number of Networks = 2^21." << endl;

        cout << "No of Hosts: 2^8 - 2 = 254" << endl;

        cout << "Reason:" << endl;
        cout << "  - 8 bits are available for host IDs." << endl;
        cout << "  - Subtract 2 because one address is the Network Address "
             << "and one is the Broadcast Address." << endl;
    }

    else if (first_octet >= 224 && first_octet <= 239) {

        cout << "\nClass D (Multicast)" << endl;
        cout << "Range: 224.0.0.0 - 239.255.255.255" << endl;

        cout << "Binary Reason:" << endl;
        cout << "  First four bits are fixed as 1110" << endl;
        cout << "  Pattern: 1110xxxx" << endl;

        cout << "Default Subnet Mask: Not Applicable" << endl;
        cout << "No of Networks: Not Applicable" << endl;
        cout << "No of Hosts: Not Applicable" << endl;

        cout << "Reason:" << endl;
        cout << "  - Class D addresses are reserved for multicast communication."
             << endl;
        cout << "  - They are not assigned to individual hosts." << endl;
    }

    else if (first_octet >= 240 && first_octet <= 255) {

        cout << "\nClass E (Experimental)" << endl;
        cout << "Range: 240.0.0.0 - 255.255.255.255" << endl;

        cout << "Binary Reason:" << endl;
        cout << "  First four bits are fixed as 1111" << endl;
        cout << "  Pattern: 1111xxxx" << endl;

        cout << "Default Subnet Mask: Not Applicable" << endl;
        cout << "No of Networks: Not Applicable" << endl;
        cout << "No of Hosts: Not Applicable" << endl;

        cout << "Reason:" << endl;
        cout << "  - Class E addresses are reserved for experimental and "
             << "research purposes." << endl;
        cout << "  - They are not used for general host addressing." << endl;
    }

    else {

        cout << "Invalid IP Address" << endl;
    }

    return 0;
}
