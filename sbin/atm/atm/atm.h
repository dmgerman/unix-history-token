begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * User configuration and display program  * --------------------------------------  *  * Control blocks  *  */
end_comment

begin_define
define|#
directive|define
name|MAX_NIFS
value|256
end_define

begin_comment
comment|/* Max network interfaces */
end_comment

begin_define
define|#
directive|define
name|MIN_VCI
value|32
end_define

begin_comment
comment|/* Smallest non-reserved VCI */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * User commands  */
end_comment

begin_struct
struct|struct
name|cmd
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Command name */
name|int
name|minp
decl_stmt|;
comment|/* Minimum number of parameters */
name|int
name|maxp
decl_stmt|;
comment|/* Maximum number of parameters */
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
comment|/* Processing function */
specifier|const
name|char
modifier|*
name|help
decl_stmt|;
comment|/* User help string */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Supported signalling protocols  */
end_comment

begin_struct
struct|struct
name|proto
block|{
specifier|const
name|char
modifier|*
name|p_name
decl_stmt|;
comment|/* Protocol name */
name|u_char
name|p_id
decl_stmt|;
comment|/* Protocol id */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Table of state names  */
end_comment

begin_struct
struct|struct
name|state
block|{
specifier|const
name|char
modifier|*
name|s_name
decl_stmt|;
comment|/* State name */
name|u_char
name|s_id
decl_stmt|;
comment|/* State id */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Supported signalling protocol states  */
end_comment

begin_struct
struct|struct
name|proto_state
block|{
specifier|const
name|char
modifier|*
name|p_name
decl_stmt|;
comment|/* Signalling manager name */
specifier|const
name|struct
name|state
modifier|*
name|p_state
decl_stmt|;
comment|/* Protocol state table */
specifier|const
name|struct
name|state
modifier|*
name|v_state
decl_stmt|;
comment|/* Protocol VCC state table */
name|u_char
name|p_id
decl_stmt|;
comment|/* Protocol ID */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Supported VCC owners  */
end_comment

begin_struct
struct|struct
name|owner
block|{
specifier|const
name|char
modifier|*
name|o_name
decl_stmt|;
comment|/* Owner name */
name|u_int
name|o_sap
decl_stmt|;
comment|/* Owner's SAP */
name|void
function_decl|(
modifier|*
name|o_pvcadd
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|,
name|struct
name|atmaddreq
modifier|*
parameter_list|,
name|struct
name|air_int_rsp
modifier|*
parameter_list|)
function_decl|;
comment|/* PVC ADD processing function */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Supported AALs  */
end_comment

begin_struct
struct|struct
name|aal
block|{
specifier|const
name|char
modifier|*
name|a_name
decl_stmt|;
comment|/* AAL name */
name|u_char
name|a_id
decl_stmt|;
comment|/* AAL code */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Supported encapsulations  */
end_comment

begin_struct
struct|struct
name|encaps
block|{
specifier|const
name|char
modifier|*
name|e_name
decl_stmt|;
comment|/* Encapsulation name */
name|u_char
name|e_id
decl_stmt|;
comment|/* Encapsulation code */
block|}
struct|;
end_struct

begin_comment
comment|/*  * External variables  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|prog
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Program invocation */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|prefix
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current command prefix */
end_comment

begin_comment
comment|/*  * Global function declarations  */
end_comment

begin_comment
comment|/* atm_eni.c */
end_comment

begin_function_decl
name|void
name|show_eni_stats
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_fore200.c */
end_comment

begin_function_decl
name|void
name|show_fore200_stats
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_inet.c */
end_comment

begin_function_decl
name|void
name|ip_pvcadd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|,
name|struct
name|atmaddreq
modifier|*
parameter_list|,
name|struct
name|air_int_rsp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_print.c */
end_comment

begin_function_decl
name|void
name|print_arp_info
parameter_list|(
name|struct
name|air_arp_rsp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_asrv_info
parameter_list|(
name|struct
name|air_asrv_rsp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_cfg_info
parameter_list|(
name|struct
name|air_cfg_rsp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_intf_info
parameter_list|(
name|struct
name|air_int_rsp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_ip_vcc_info
parameter_list|(
name|struct
name|air_ip_vcc_rsp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_netif_info
parameter_list|(
name|struct
name|air_netif_rsp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_intf_stats
parameter_list|(
name|struct
name|air_phy_stat_rsp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_vcc_stats
parameter_list|(
name|struct
name|air_vcc_rsp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_vcc_info
parameter_list|(
name|struct
name|air_vcc_rsp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_version_info
parameter_list|(
name|struct
name|air_version_rsp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_set.c */
end_comment

begin_function_decl
name|void
name|set_arpserver
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_macaddr
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_netif
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_prefix
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_show.c */
end_comment

begin_function_decl
name|void
name|show_arp
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_arpserv
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_config
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_intf
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_ip_vcc
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_netif
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_vcc
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_version
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_intf_stats
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_vcc_stats
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_subr.c */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|get_vendor
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_adapter
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_media_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_bus_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_bus_slot_info
parameter_list|(
name|int
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_adapter_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_hex_addr
parameter_list|(
name|char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|format_mac_addr
parameter_list|(
specifier|const
name|Mac_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_ip_prefix
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|compress_prefix_list
parameter_list|(
name|struct
name|in_addr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|check_netif_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sock_error
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|proto
name|protos
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|aal
name|aals
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|encaps
name|encaps
index|[]
decl_stmt|;
end_decl_stmt

end_unit

