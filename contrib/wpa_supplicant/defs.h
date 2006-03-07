begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant - Common definitions  * Copyright (c) 2004-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|DEFS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FALSE
end_ifdef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TRUE
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
enum|enum
block|{
name|FALSE
init|=
literal|0
block|,
name|TRUE
init|=
literal|1
block|}
name|Boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|WPA_ALG_NONE
block|,
name|WPA_ALG_WEP
block|,
name|WPA_ALG_TKIP
block|,
name|WPA_ALG_CCMP
block|}
name|wpa_alg
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CIPHER_NONE
block|,
name|CIPHER_WEP40
block|,
name|CIPHER_TKIP
block|,
name|CIPHER_CCMP
block|,
name|CIPHER_WEP104
block|}
name|wpa_cipher
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|KEY_MGMT_802_1X
block|,
name|KEY_MGMT_PSK
block|,
name|KEY_MGMT_NONE
block|,
name|KEY_MGMT_802_1X_NO_WPA
block|,
name|KEY_MGMT_WPA_NONE
block|}
name|wpa_key_mgmt
typedef|;
end_typedef

begin_comment
comment|/**  * enum wpa_states - wpa_supplicant state  *  * These enumeration values are used to indicate the current wpa_supplicant  * state (wpa_s->wpa_state). The current state can be retrieved with  * wpa_supplicant_get_state() function and the state can be changed by calling  * wpa_supplicant_set_state(). In WPA state machine (wpa.c and preauth.c), the  * wrapper functions wpa_sm_get_state() and wpa_sm_set_state() should be used  * to access the state variable.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/** 	 * WPA_DISCONNECTED - Disconnected state 	 * 	 * This state indicates that client is not associated, but is likely to 	 * start looking for an access point. This state is entered when a 	 * connection is lost. 	 */
name|WPA_DISCONNECTED
block|,
comment|/** 	 * WPA_INACTIVE - Inactive state (wpa_supplicant disabled) 	 * 	 * This state is entered if there are no enabled networks in the 	 * configuration. wpa_supplicant is not trying to associate with a new 	 * network and external interaction (e.g., ctrl_iface call to add or 	 * enable a network) is needed to start association. 	 */
name|WPA_INACTIVE
block|,
comment|/** 	 * WPA_SCANNING - Scanning for a network 	 * 	 * This state is entered when wpa_supplicant starts scanning for a 	 * network. 	 */
name|WPA_SCANNING
block|,
comment|/** 	 * WPA_ASSOCIATING - Trying to associate with a BSS/SSID 	 * 	 * This state is entered when wpa_supplicant has found a suitable BSS 	 * to associate with and the driver is configured to try to associate 	 * with this BSS in ap_scan=1 mode. When using ap_scan=2 mode, this 	 * state is entered when the driver is configured to try to associate 	 * with a network using the configured SSID and security policy. 	 */
name|WPA_ASSOCIATING
block|,
comment|/** 	 * WPA_ASSOCIATED - Association completed 	 * 	 * This state is entered when the driver reports that association has 	 * been successfully completed with an AP. If IEEE 802.1X is used 	 * (with or without WPA/WPA2), wpa_supplicant remains in this state 	 * until the IEEE 802.1X/EAPOL authentication has been completed. 	 */
name|WPA_ASSOCIATED
block|,
comment|/** 	 * WPA_4WAY_HANDSHAKE - WPA 4-Way Key Handshake in progress 	 * 	 * This state is entered when WPA/WPA2 4-Way Handshake is started. In 	 * case of WPA-PSK, this happens when receiving the first EAPOL-Key 	 * frame after association. In case of WPA-EAP, this state is entered 	 * when the IEEE 802.1X/EAPOL authentication has been completed. 	 */
name|WPA_4WAY_HANDSHAKE
block|,
comment|/** 	 * WPA_GROUP_HANDSHAKE - WPA Group Key Handshake in progress 	 * 	 * This state is entered when 4-Way Key Handshake has been completed 	 * (i.e., when the supplicant sends out message 4/4) and when Group 	 * Key rekeying is started by the AP (i.e., when supplicant receives 	 * message 1/2). 	 */
name|WPA_GROUP_HANDSHAKE
block|,
comment|/** 	 * WPA_COMPLETED - All authentication completed 	 * 	 * This state is entered when the full authentication process is 	 * completed. In case of WPA2, this happens when the 4-Way Handshake is 	 * successfully completed. With WPA, this state is entered after the 	 * Group Key Handshake; with IEEE 802.1X (non-WPA) connection is 	 * completed after dynamic keys are received (or if not used, after 	 * the EAP authentication has been completed). With static WEP keys and 	 * plaintext connections, this state is entered when an association 	 * has been completed. 	 * 	 * This state indicates that the supplicant has completed its 	 * processing for the association phase and that data connection is 	 * fully configured. 	 */
name|WPA_COMPLETED
block|}
name|wpa_states
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEFS_H */
end_comment

end_unit

