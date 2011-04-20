#ifndef __AMPE_H
#define __AMPE_H

enum plink_state {
    PLINK_LISTEN,
    PLINK_OPN_SNT,
    PLINK_OPN_RCVD,
    PLINK_CNF_RCVD,
    PLINK_ESTAB,
    PLINK_HOLDING,
    PLINK_BLOCKED
};

/*  meshd calls these:  */
int ampe_initialize(unsigned char *meshid, unsigned char meshid_len);
int process_ampe_frame(struct ieee80211_mgmt_frame *frame, int len, unsigned char *me, void *cookie);
int start_peer_link(unsigned char *peer_mac, unsigned char *me, void *cookie);

/*  and implements these:  */
void estab_peer_link(unsigned char *peer);
#endif
