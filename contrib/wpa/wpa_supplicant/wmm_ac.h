begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Wi-Fi Multimedia Admission Control (WMM-AC)  * Copyright(c) 2014, Intel Mobile Communication GmbH.  * Copyright(c) 2014, Intel Corporation. All rights reserved.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WMM_AC_H
end_ifndef

begin_define
define|#
directive|define
name|WMM_AC_H
end_define

begin_include
include|#
directive|include
file|"common/ieee802_11_defs.h"
end_include

begin_include
include|#
directive|include
file|"drivers/driver.h"
end_include

begin_struct_decl
struct_decl|struct
name|wpa_supplicant
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|WMM_AC_ACCESS_POLICY_EDCA
value|1
end_define

begin_define
define|#
directive|define
name|WMM_AC_FIXED_MSDU_SIZE
value|BIT(15)
end_define

begin_define
define|#
directive|define
name|WMM_AC_MAX_TID
value|7
end_define

begin_define
define|#
directive|define
name|WMM_AC_MAX_USER_PRIORITY
value|7
end_define

begin_define
define|#
directive|define
name|WMM_AC_MIN_SBA_UNITY
value|0x2000
end_define

begin_define
define|#
directive|define
name|WMM_AC_MAX_NOMINAL_MSDU
value|32767
end_define

begin_comment
comment|/**  * struct wmm_ac_assoc_data - WMM Admission Control Association Data  *  * This struct will store any relevant WMM association data needed by WMM AC.  * In case there is a valid WMM association, an instance of this struct will be  * created. In case there is no instance of this struct, the station is not  * associated to a valid WMM BSS and hence, WMM AC will not be used.  */
end_comment

begin_struct
struct|struct
name|wmm_ac_assoc_data
block|{
struct|struct
block|{
comment|/* 		 * acm - Admission Control Mandatory 		 * In case an access category is ACM, the traffic will have 		 * to be admitted by WMM-AC's admission mechanism before use. 		 */
name|unsigned
name|int
name|acm
range|:
literal|1
decl_stmt|;
comment|/* 		 * uapsd_queues - Unscheduled Automatic Power Save Delivery 		 *		  queues. 		 * Indicates whether ACs are configured for U-APSD (or legacy 		 * PS). Storing this value is necessary in order to set the 		 * Power Save Bit (PSB) in ADDTS request Action frames (if not 		 * given). 		 */
name|unsigned
name|int
name|uapsd
range|:
literal|1
decl_stmt|;
block|}
name|ac_params
index|[
name|WMM_AC_NUM
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * wmm_ac_dir - WMM Admission Control Direction  */
end_comment

begin_enum
enum|enum
name|wmm_ac_dir
block|{
name|WMM_AC_DIR_UPLINK
init|=
literal|0
block|,
name|WMM_AC_DIR_DOWNLINK
init|=
literal|1
block|,
name|WMM_AC_DIR_BIDIRECTIONAL
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/**  * ts_dir_idx - indices of internally saved tspecs  *  * we can have multiple tspecs (downlink + uplink) per ac.  * save them in array, and use the enum to directly access  * the respective tspec slot (according to the direction).  */
end_comment

begin_enum
enum|enum
name|ts_dir_idx
block|{
name|TS_DIR_IDX_UPLINK
block|,
name|TS_DIR_IDX_DOWNLINK
block|,
name|TS_DIR_IDX_BIDI
block|,
name|TS_DIR_IDX_COUNT
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|TS_DIR_IDX_ALL
value|(BIT(TS_DIR_IDX_COUNT) - 1)
end_define

begin_comment
comment|/**  * struct wmm_ac_addts_request - ADDTS Request Information  *  * The last sent ADDTS request(s) will be saved as element(s) of this struct in  * order to be compared with the received ADDTS response in ADDTS response  * action frame handling and should be stored until that point.  * In case a new traffic stream will be created/replaced/updated, only its  * relevant traffic stream information will be stored as a wmm_ac_ts struct.  */
end_comment

begin_struct
struct|struct
name|wmm_ac_addts_request
block|{
comment|/* 	 * dialog token - Used to link the recived ADDTS response with this 	 * saved ADDTS request when ADDTS response is being handled 	 */
name|u8
name|dialog_token
decl_stmt|;
comment|/* 	 * address - The alleged traffic stream's receiver/transmitter address 	 * Address and TID are used to identify the TS (TID is contained in 	 * TSPEC) 	 */
name|u8
name|address
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/* 	 * tspec - Traffic Stream Specification, will be used to compare the 	 * sent TSPEC in ADDTS request to the received TSPEC in ADDTS response 	 * and act accordingly in ADDTS response handling 	 */
name|struct
name|wmm_tspec_element
name|tspec
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wmm_ac_ts_setup_params - TS setup parameters  *  * This struct holds parameters which should be provided  * to wmm_ac_ts_setup in order to setup a traffic stream  */
end_comment

begin_struct
struct|struct
name|wmm_ac_ts_setup_params
block|{
comment|/* 	 * tsid - Traffic ID 	 * TID and address are used to identify the TS 	 */
name|int
name|tsid
decl_stmt|;
comment|/* 	 * direction - Traffic Stream's direction 	 */
name|enum
name|wmm_ac_dir
name|direction
decl_stmt|;
comment|/* 	 * user_priority - Traffic Stream's user priority 	 */
name|int
name|user_priority
decl_stmt|;
comment|/* 	 * nominal_msdu_size - Nominal MAC service data unit size 	 */
name|int
name|nominal_msdu_size
decl_stmt|;
comment|/* 	 * fixed_nominal_msdu - Whether the size is fixed 	 * 0 = Nominal MSDU size is not fixed 	 * 1 = Nominal MSDU size is fixed 	 */
name|int
name|fixed_nominal_msdu
decl_stmt|;
comment|/* 	 * surplus_bandwidth_allowance - Specifies excess time allocation 	 */
name|int
name|mean_data_rate
decl_stmt|;
comment|/* 	 * minimum_phy_rate - Specifies the minimum supported PHY rate in bps 	 */
name|int
name|minimum_phy_rate
decl_stmt|;
comment|/* 	 * surplus_bandwidth_allowance - Specifies excess time allocation 	 */
name|int
name|surplus_bandwidth_allowance
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|wmm_ac_notify_assoc
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ies_len
parameter_list|,
specifier|const
name|struct
name|wmm_params
modifier|*
name|wmm_params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wmm_ac_notify_disassoc
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpas_wmm_ac_addts
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wmm_ac_ts_setup_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpas_wmm_ac_delts
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|u8
name|tsid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wmm_ac_rx_action
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|da
parameter_list|,
specifier|const
name|u8
modifier|*
name|sa
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpas_wmm_ac_status
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wmm_ac_save_tspecs
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wmm_ac_clear_saved_tspecs
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wmm_ac_restore_tspecs
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WMM_AC_H */
end_comment

end_unit

