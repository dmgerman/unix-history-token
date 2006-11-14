begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|AP_H
end_ifndef

begin_define
define|#
directive|define
name|AP_H
end_define

begin_comment
comment|/* STA flags */
end_comment

begin_define
define|#
directive|define
name|WLAN_STA_AUTH
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_ASSOC
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PS
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_TIM
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PERM
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_AUTHORIZED
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PENDING_POLL
value|BIT(6)
end_define

begin_comment
comment|/* pending activity poll not ACKed */
end_comment

begin_define
define|#
directive|define
name|WLAN_STA_PREAUTH
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|WLAN_RATE_1M
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WLAN_RATE_2M
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WLAN_RATE_5M5
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WLAN_RATE_11M
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WLAN_RATE_COUNT
value|4
end_define

begin_comment
comment|/* Maximum size of Supported Rates info element. IEEE 802.11 has a limit of 8,  * but some pre-standard IEEE 802.11g products use longer elements. */
end_comment

begin_define
define|#
directive|define
name|WLAN_SUPP_RATES_MAX
value|32
end_define

begin_struct
struct|struct
name|sta_info
block|{
name|struct
name|sta_info
modifier|*
name|next
decl_stmt|;
comment|/* next entry in sta list */
name|struct
name|sta_info
modifier|*
name|hnext
decl_stmt|;
comment|/* next entry in hash table list */
name|u8
name|addr
index|[
literal|6
index|]
decl_stmt|;
name|u16
name|aid
decl_stmt|;
comment|/* STA's unique AID (1 .. 2007) or 0 if not yet assigned */
name|u32
name|flags
decl_stmt|;
name|u16
name|capability
decl_stmt|;
name|u16
name|listen_interval
decl_stmt|;
comment|/* or beacon_int for APs */
name|u8
name|supported_rates
index|[
name|WLAN_SUPP_RATES_MAX
index|]
decl_stmt|;
name|u8
name|tx_supp_rates
decl_stmt|;
enum|enum
block|{
name|STA_NULLFUNC
init|=
literal|0
block|,
name|STA_DISASSOC
block|,
name|STA_DEAUTH
block|,
name|STA_REMOVE
block|}
name|timeout_next
enum|;
comment|/* IEEE 802.1X related data */
name|struct
name|eapol_state_machine
modifier|*
name|eapol_sm
decl_stmt|;
comment|/* IEEE 802.11f (IAPP) related data */
name|struct
name|ieee80211_mgmt
modifier|*
name|last_assoc_req
decl_stmt|;
name|u32
name|acct_session_id_hi
decl_stmt|;
name|u32
name|acct_session_id_lo
decl_stmt|;
name|time_t
name|acct_session_start
decl_stmt|;
name|int
name|acct_session_started
decl_stmt|;
name|int
name|acct_terminate_cause
decl_stmt|;
comment|/* Acct-Terminate-Cause */
name|int
name|acct_interim_interval
decl_stmt|;
comment|/* Acct-Interim-Interval */
name|unsigned
name|long
name|last_rx_bytes
decl_stmt|;
name|unsigned
name|long
name|last_tx_bytes
decl_stmt|;
name|u32
name|acct_input_gigawords
decl_stmt|;
comment|/* Acct-Input-Gigawords */
name|u32
name|acct_output_gigawords
decl_stmt|;
comment|/* Acct-Output-Gigawords */
name|u8
modifier|*
name|challenge
decl_stmt|;
comment|/* IEEE 802.11 Shared Key Authentication Challenge */
name|int
name|pairwise
decl_stmt|;
comment|/* Pairwise cipher suite, WPA_CIPHER_* */
name|u8
modifier|*
name|wpa_ie
decl_stmt|;
name|size_t
name|wpa_ie_len
decl_stmt|;
name|struct
name|wpa_state_machine
modifier|*
name|wpa_sm
decl_stmt|;
enum|enum
block|{
name|WPA_VERSION_NO_WPA
init|=
literal|0
comment|/* WPA not used */
block|,
name|WPA_VERSION_WPA
init|=
literal|1
comment|/* WPA / IEEE 802.11i/D3.0 */
block|,
name|WPA_VERSION_WPA2
init|=
literal|2
comment|/* WPA2 / IEEE 802.11i */
block|}
name|wpa
enum|;
name|int
name|wpa_key_mgmt
decl_stmt|;
comment|/* the selected WPA_KEY_MGMT_* */
name|struct
name|rsn_pmksa_cache
modifier|*
name|pmksa
decl_stmt|;
name|struct
name|rsn_preauth_interface
modifier|*
name|preauth_iface
decl_stmt|;
name|u8
name|req_replay_counter
index|[
literal|8
comment|/* WPA_REPLAY_COUNTER_LEN */
index|]
decl_stmt|;
name|int
name|req_replay_counter_used
decl_stmt|;
name|u32
name|dot11RSNAStatsTKIPLocalMICFailures
decl_stmt|;
name|u32
name|dot11RSNAStatsTKIPRemoteMICFailures
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_STA_COUNT
value|1024
end_define

begin_comment
comment|/* Maximum number of AIDs to use for STAs; must be 2007 or lower  * (8802.11 limitation) */
end_comment

begin_define
define|#
directive|define
name|MAX_AID_TABLE_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|STA_HASH_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|STA_HASH
parameter_list|(
name|sta
parameter_list|)
value|(sta[5])
end_define

begin_comment
comment|/* Default value for maximum station inactivity. After AP_MAX_INACTIVITY has  * passed since last received frame from the station, a nullfunc data frame is  * sent to the station. If this frame is not acknowledged and no other frames  * have been received, the station will be disassociated after  * AP_DISASSOC_DELAY seconds. Similarily, the station will be deauthenticated  * after AP_DEAUTH_DELAY seconds has passed after disassociation. */
end_comment

begin_define
define|#
directive|define
name|AP_MAX_INACTIVITY
value|(5 * 60)
end_define

begin_define
define|#
directive|define
name|AP_DISASSOC_DELAY
value|(1)
end_define

begin_define
define|#
directive|define
name|AP_DEAUTH_DELAY
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AP_H */
end_comment

end_unit

