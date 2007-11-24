begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant - Exported functions for wpa_supplicant modules  * Copyright (c) 2003-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPA_SUPPLICANT_H
end_ifndef

begin_define
define|#
directive|define
name|WPA_SUPPLICANT_H
end_define

begin_comment
comment|/* Driver wrappers are not supposed to directly touch the internal data  * structure used in wpa_supplicant, so that definition is not provided here.  */
end_comment

begin_struct_decl
struct_decl|struct
name|wpa_supplicant
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * enum wpa_event_type - Event type for wpa_supplicant_event() calls  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|wpa_event_type
block|{
comment|/** 	 * EVENT_ASSOC - Association completed 	 * 	 * This event needs to be delivered when the driver completes IEEE 	 * 802.11 association or reassociation successfully. 	 * wpa_driver_ops::get_bssid() is expected to provide the current BSSID 	 * after this even has been generated. In addition, optional 	 * EVENT_ASSOCINFO may be generated just before EVENT_ASSOC to provide 	 * more information about the association. If the driver interface gets 	 * both of these events at the same time, it can also include the 	 * assoc_info data in EVENT_ASSOC call. 	 */
name|EVENT_ASSOC
block|,
comment|/** 	 * EVENT_DISASSOC - Association lost 	 * 	 * This event should be called when association is lost either due to 	 * receiving deauthenticate or disassociate frame from the AP or when 	 * sending either of these frames to the current AP. 	 */
name|EVENT_DISASSOC
block|,
comment|/** 	 * EVENT_MICHAEL_MIC_FAILURE - Michael MIC (TKIP) detected 	 * 	 * This event must be delivered when a Michael MIC error is detected by 	 * the local driver. Additional data is for event processing is 	 * provided with union wpa_event_data::michael_mic_failure. This 	 * information is used to request new encyption key and to initiate 	 * TKIP countermeasures if needed. 	 */
name|EVENT_MICHAEL_MIC_FAILURE
block|,
comment|/** 	 * EVENT_SCAN_RESULTS - Scan results available 	 * 	 * This event must be called whenever scan results are available to be 	 * fetched with struct wpa_driver_ops::get_scan_results(). This event 	 * is expected to be used some time after struct wpa_driver_ops::scan() 	 * is called. If the driver provides an unsolicited event when the scan 	 * has been completed, this event can be used to trigger 	 * EVENT_SCAN_RESULTS call. If such event is not available from the 	 * driver, the driver wrapper code is expected to use a registered 	 * timeout to generate EVENT_SCAN_RESULTS call after the time that the 	 * scan is expected to be completed. 	 */
name|EVENT_SCAN_RESULTS
block|,
comment|/** 	 * EVENT_ASSOCINFO - Report optional extra information for association 	 * 	 * This event can be used to report extra association information for 	 * EVENT_ASSOC processing. This extra information includes IEs from 	 * association frames and Beacon/Probe Response frames in union 	 * wpa_event_data::assoc_info. EVENT_ASSOCINFO must be send just before 	 * EVENT_ASSOC. Alternatively, the driver interface can include 	 * assoc_info data in the EVENT_ASSOC call if it has all the 	 * information available at the same point. 	 */
name|EVENT_ASSOCINFO
block|,
comment|/** 	 * EVENT_INTERFACE_STATUS - Report interface status changes 	 * 	 * This optional event can be used to report changes in interface 	 * status (interface added/removed) using union 	 * wpa_event_data::interface_status. This can be used to trigger 	 * wpa_supplicant to stop and re-start processing for the interface, 	 * e.g., when a cardbus card is ejected/inserted. 	 */
name|EVENT_INTERFACE_STATUS
block|,
comment|/** 	 * EVENT_PMKID_CANDIDATE - Report a candidate AP for pre-authentication 	 * 	 * This event can be used to inform wpa_supplicant about candidates for 	 * RSN (WPA2) pre-authentication. If wpa_supplicant is not responsible 	 * for scan request (ap_scan=2 mode), this event is required for 	 * pre-authentication. If wpa_supplicant is performing scan request 	 * (ap_scan=1), this event is optional since scan results can be used 	 * to add pre-authentication candidates. union 	 * wpa_event_data::pmkid_candidate is used to report the BSSID of the 	 * candidate and priority of the candidate, e.g., based on the signal 	 * strength, in order to try to pre-authenticate first with candidates 	 * that are most likely targets for re-association. 	 * 	 * EVENT_PMKID_CANDIDATE can be called whenever the driver has updates 	 * on the candidate list. In addition, it can be called for the current 	 * AP and APs that have existing PMKSA cache entries. wpa_supplicant 	 * will automatically skip pre-authentication in cases where a valid 	 * PMKSA exists. When more than one candidate exists, this event should 	 * be generated once for each candidate. 	 * 	 * Driver will be notified about successful pre-authentication with 	 * struct wpa_driver_ops::add_pmkid() calls. 	 */
name|EVENT_PMKID_CANDIDATE
block|}
name|wpa_event_type
typedef|;
end_typedef

begin_comment
comment|/**  * union wpa_event_data - Additional data for wpa_supplicant_event() calls  */
end_comment

begin_union
union|union
name|wpa_event_data
block|{
comment|/** 	 * struct assoc_info - Data for EVENT_ASSOC and EVENT_ASSOCINFO events 	 * 	 * This structure is optional for EVENT_ASSOC calls and required for 	 * EVENT_ASSOCINFO calls. By using EVENT_ASSOC with this data, the 	 * driver interface does not need to generate separate EVENT_ASSOCINFO 	 * calls. 	 */
struct|struct
name|assoc_info
block|{
comment|/** 		 * req_ies - (Re)Association Request IEs 		 * 		 * If the driver generates WPA/RSN IE, this event data must be 		 * returned for WPA handshake to have needed information. If 		 * wpa_supplicant-generated WPA/RSN IE is used, this 		 * information event is optional. 		 * 		 * This should start with the first IE (fixed fields before IEs 		 * are not included). 		 */
name|u8
modifier|*
name|req_ies
decl_stmt|;
comment|/** 		 * req_ies_len - Length of req_ies in bytes 		 */
name|size_t
name|req_ies_len
decl_stmt|;
comment|/** 		 * resp_ies - (Re)Association Response IEs 		 * 		 * Optional association data from the driver. This data is not 		 * required WPA, but may be useful for some protocols and as 		 * such, should be reported if this is available to the driver 		 * interface. 		 * 		 * This should start with the first IE (fixed fields before IEs 		 * are not included). 		 */
name|u8
modifier|*
name|resp_ies
decl_stmt|;
comment|/** 		 * resp_ies_len - Length of resp_ies in bytes 		 */
name|size_t
name|resp_ies_len
decl_stmt|;
comment|/** 		 * beacon_ies - Beacon or Probe Response IEs 		 * 		 * Optional Beacon/ProbeResp data: IEs included in Beacon or 		 * Probe Response frames from the current AP (i.e., the one 		 * that the client just associated with). This information is 		 * used to update WPA/RSN IE for the AP. If this field is not 		 * set, the results from previous scan will be used. If no 		 * data for the new AP is found, scan results will be requested 		 * again (without scan request). At this point, the driver is 		 * expected to provide WPA/RSN IE for the AP (if WPA/WPA2 is 		 * used). 		 * 		 * This should start with the first IE (fixed fields before IEs 		 * are not included). 		 */
name|u8
modifier|*
name|beacon_ies
decl_stmt|;
comment|/** 		 * beacon_ies_len - Length of beacon_ies */
name|size_t
name|beacon_ies_len
decl_stmt|;
block|}
name|assoc_info
struct|;
comment|/** 	 * struct michael_mic_failure - Data for EVENT_MICHAEL_MIC_FAILURE 	 */
struct|struct
name|michael_mic_failure
block|{
name|int
name|unicast
decl_stmt|;
block|}
name|michael_mic_failure
struct|;
comment|/** 	 * struct interface_status - Data for EVENT_INTERFACE_STATUS 	 */
struct|struct
name|interface_status
block|{
name|char
name|ifname
index|[
literal|20
index|]
decl_stmt|;
enum|enum
block|{
name|EVENT_INTERFACE_ADDED
block|,
name|EVENT_INTERFACE_REMOVED
block|}
name|ievent
enum|;
block|}
name|interface_status
struct|;
comment|/** 	 * struct pmkid_candidate - Data for EVENT_PMKID_CANDIDATE 	 */
struct|struct
name|pmkid_candidate
block|{
comment|/** BSSID of the PMKID candidate */
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** Smaller the index, higher the priority */
name|int
name|index
decl_stmt|;
comment|/** Whether RSN IE includes pre-authenticate flag */
name|int
name|preauth
decl_stmt|;
block|}
name|pmkid_candidate
struct|;
block|}
union|;
end_union

begin_comment
comment|/**  * wpa_supplicant_event - Report a driver event for wpa_supplicant  * @wpa_s: pointer to wpa_supplicant data; this is the ctx variable registered  *	with struct wpa_driver_ops::init()  * @event: event type (defined above)  * @data: possible extra data for the event  *  * Driver wrapper code should call this function whenever an event is received  * from the driver.  */
end_comment

begin_function_decl
name|void
name|wpa_supplicant_event
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|wpa_event_type
name|event
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_msg - Conditional printf for default target and ctrl_iface monitors  * @wpa_s: pointer to wpa_supplicant data; this is the ctx variable registered  *	with struct wpa_driver_ops::init()  * @level: priority level (MSG_*) of the message  * @fmt: printf format string, followed by optional arguments  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. This function is like wpa_printf(), but it also sends the  * same message to all attached ctrl_iface monitors.  *  * Note: New line '\n' is added to the end of the text when printing to stdout.  */
end_comment

begin_function_decl
name|void
name|wpa_msg
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|wpa_ssid_txt
parameter_list|(
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_supplicant_rx_eapol - Deliver a received EAPOL frame to wpa_supplicant  * @ctx: Context pointer (wpa_s)  * @src_addr: Source address of the EAPOL frame  * @buf: EAPOL data starting from the EAPOL header (i.e., no Ethernet header)  * @len: Length of the EAPOL data  *  * This function is called for each received EAPOL frame.  */
end_comment

begin_function_decl
name|void
name|wpa_supplicant_rx_eapol
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|src_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPA_SUPPLICANT_H */
end_comment

end_unit

