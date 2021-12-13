#include <pcap.h>
#include <iostream>
#include <stdint.h>

using namespace std;

struct Param{
    const char* interface = nullptr;
    const char* ap = nullptr;
    const char* station = "NULL";

    bool parse(int argc, char const *argv[]){
        if (argc < 3){
            usage();
            return false;
        }
        
        interface = argv[1];
        ap = argv[2];
        if (3 < argc)
            station = argv[3];
        
        return true;        
    }

    void usage(void){
        printf("syntax : deauth-attack <interface> <ap mac> [<station mac>]\n");
        printf("sample : deauth-attack mon0 00:11:22:33:44:55 66:77:88:99:AA:BB\n");
    }

    void info(void){
        printf("[!] argv info\n");
        printf("    interface   : %s\n", interface);
        printf("    ap mac      : %s\n", ap);
        printf("    station mac : %s\n", station);
    }
} ;
