begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_typedef
typedef|typedef
enum|enum
block|{
name|EVENT_ASSOC
block|,
name|EVENT_DISASSOC
block|,
name|EVENT_MICHAEL_MIC_FAILURE
block|,
name|EVENT_SCAN_RESULTS
block|,
name|EVENT_ASSOCINFO
block|,
name|EVENT_INTERFACE_STATUS
block|,
name|EVENT_PMKID_CANDIDATE
block|}
name|wpa_event_type
typedef|;
end_typedef

begin_union
union|union
name|wpa_event_data
block|{
struct|struct
block|{
comment|/* Optional request information data: IEs included in AssocReq 		 * and AssocResp. If these are not returned by the driver, 		 * WPA Supplicant will generate the WPA/RSN IE. */
name|u8
modifier|*
name|req_ies
decl_stmt|,
modifier|*
name|resp_ies
decl_stmt|;
name|size_t
name|req_ies_len
decl_stmt|,
name|resp_ies_len
decl_stmt|;
comment|/* Optional Beacon/ProbeResp data: IEs included in Beacon or 		 * Probe Response frames from the current AP (i.e., the one 		 * that the client just associated with). This information is 		 * used to update WPA/RSN IE for the AP. If this field is not 		 * set, the results from previous scan will be used. If no 		 * data for the new AP is found, scan results will be requested 		 * again (without scan request). At this point, the driver is 		 * expected to provide WPA/RSN IE for the AP (if WPA/WPA2 is 		 * used). */
name|u8
modifier|*
name|beacon_ies
decl_stmt|;
comment|/* beacon or probe resp IEs */
name|size_t
name|beacon_ies_len
decl_stmt|;
block|}
name|assoc_info
struct|;
struct|struct
block|{
name|int
name|unicast
decl_stmt|;
block|}
name|michael_mic_failure
struct|;
struct|struct
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
struct|struct
block|{
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|int
name|index
decl_stmt|;
comment|/* smaller the index, higher the priority */
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
comment|/**  * wpa_supplicant_event - report a driver event for wpa_supplicant  * @wpa_s: pointer to wpa_supplicant data; this is the @ctx variable registered  *	with wpa_driver_events_init()  * @event: event type (defined above)  * @data: possible extra data for the event  *  * Driver wrapper code should call this function whenever an event is received  * from the driver.  */
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
comment|/**  * wpa_msg - conditional printf for default target and ctrl_iface monitors  * @level: priority level (MSG_*) of the message  * @fmt: printf format string, followed by optional arguments  *  * This function is used to print conditional debugging and error messages. The  * output may be directed to stdout, stderr, and/or syslog based on  * configuration. This function is like wpa_printf(), but it also sends the  * same message to all attached ctrl_iface monitors.  *  * Note: New line '\n' is added to the end of the text when printing to stdout.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPA_SUPPLICANT_H */
end_comment

end_unit

