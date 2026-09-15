#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    char ch;

    cout << "SUBNET\n";
    cout << "A subnet is a smaller division of a network used to organize devices and improve communication.\n\n";

    cout << "Enter IP Address : ";
    cin >> a >> ch >> b >> ch >> c >> ch >> d ;

    cout << "\nIP Address : " << a << "." << b << "." << c << "." << d;

    cout << "\n\nOctets";
    cout << "\n1st Octet : " << a;
    cout << "\n2nd Octet : " << b;
    cout << "\n3rd Octet : " << c;
    cout << "\n4th Octet : " << d;

    if(a>=1 && a<=126)
    {
        cout << "\n\nClass : A";
        cout << "\nStarting Bit : 0";
        cout << "\nDefault Subnet Mask : 255.0.0.0 (/8)";
        cout << "\nNetwork Bits : 8";
        cout << "\nHost Bits : 24";

        cout << "\n\nNumber of Networks : 126";
        cout << "\nReason : First bit is fixed as 0, leaving 7 bits for the Network ID.";
        cout << "\n         2^7 = 128 networks.";
        cout << "\n         Network 0 and 127 are reserved.";
        cout << "\n         Therefore usable networks = 126.";

        cout << "\n\nHosts per Network : 16,777,214";
        cout << "\nReason : 24 bits are used for Host ID.";
        cout << "\n         2^24 = 16,777,216 addresses.";
        cout << "\n         1 address is reserved as the Network Address.";
        cout << "\n         1 address is reserved as the Broadcast Address.";
        cout << "\n         Therefore usable hosts = 2^24 - 2.";

        cout << "\n\nPurpose : Used for very large networks.";
    }

    else if(a==127)
    {
        cout << "\n\nReserved Address";
        cout << "\n127.x.x.x is reserved for Loopback.";
        cout << "\nExample : 127.0.0.1";
        cout << "\nPurpose : Used by a computer to communicate with itself.";
        cout << "\nIt is mainly used for testing the TCP/IP protocol.";
    }

    else if(a>=128 && a<=191)
    {
        cout << "\n\nClass : B";
        cout << "\nStarting Bits : 10";
        cout << "\nDefault Subnet Mask : 255.255.0.0 (/16)";
        cout << "\nNetwork Bits : 16";
        cout << "\nHost Bits : 16";

        cout << "\n\nNumber of Networks : 16,384";
        cout << "\nReason : First 2 bits are fixed as 10, leaving 14 bits.";
        cout << "\n         2^14 = 16,384 networks.";

        cout << "\n\nHosts per Network : 65,534";
        cout << "\nReason : 16 bits are used for Host ID.";
        cout << "\n         2^16 = 65,536 addresses.";
        cout << "\n         1 address is reserved as the Network Address.";
        cout << "\n         1 address is reserved as the Broadcast Address.";
        cout << "\n         Therefore usable hosts = 2^16 - 2.";

        cout << "\n\nPurpose : Used for medium-sized networks.";
    }

    else if(a>=192 && a<=223)
    {
        cout << "\n\nClass : C";
        cout << "\nStarting Bits : 110";
        cout << "\nDefault Subnet Mask : 255.255.255.0 (/24)";
        cout << "\nNetwork Bits : 24";
        cout << "\nHost Bits : 8";

        cout << "\n\nNumber of Networks : 2,097,152";
        cout << "\nReason : First 3 bits are fixed as 110, leaving 21 bits.";
        cout << "\n         2^21 = 2,097,152 networks.";

        cout << "\n\nHosts per Network : 254";
        cout << "\nReason : 8 bits are used for Host ID.";
        cout << "\n         2^8 = 256 addresses.";
        cout << "\n         1 address is reserved as the Network Address.";
        cout << "\n         1 address is reserved as the Broadcast Address.";
        cout << "\n         Therefore usable hosts = 2^8 - 2 = 254.";

        cout << "\n\nPurpose : Used for small networks.";
    }

    else if(a>=224 && a<=239)
    {
        cout << "\n\nClass : D";
        cout << "\nStarting Bits : 1110";
        cout << "\nPurpose : Multicast.";
        cout << "\nThese addresses are not assigned to individual hosts.";
        cout << "\nThey are used for one-to-many communication.";
    }

    else if(a>=240 && a<=255)
    {
        cout << "\n\nClass : E";
        cout << "\nStarting Bits : 1111";
        cout << "\nPurpose : Experimental and Research.";
        cout << "\nThese addresses are reserved and are not assigned to normal hosts.";
    }

    else
    {
        cout << "\nInvalid IP Address.";
    }

    return 0;
} 