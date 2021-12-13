#pragma once
#include <stdint.h>
#include <iostream>

using namespace std;

struct radiotap_header {
        u_int8_t        it_version;     /* set to 0 */
        u_int8_t        it_pad;
        u_int16_t       it_len;         /* entire length */
        u_int32_t       it_present;     /* fields present */
} __attribute__((__packed__));

struct IEEE80211{
    uint16_t type; // Beacon frame : (0x0008) / Deauthentication (0x000c)
    uint16_t duration;
    uint8_t dmac[6];
    uint8_t smac[6];
    uint8_t BSSID[6];
    uint16_t frag_seqnum; // 12bit : sequence number , 4 bit : fragment number

} __attribute__((__packed__));


struct tagged_parameter{
    uint8_t tag_num;
    uint8_t tag_len;
    u_char data[1];
} __attribute__((__packed__));

struct wireless_management{
    // wireless management

    //fixed parameter
    uint64_t timestamp;
    uint16_t beacon_interval;
    uint16_t capabilities_information;

    //tag : not fixed
    tagged_parameter tag_data;
} __attribute__ ((__packed__));
    