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
argument_list|(
argument|*func
argument_list|)
comment|/* Processing function */
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
expr_stmt|;
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
name|char
modifier|*
name|p_name
decl_stmt|;
comment|/* Signalling manager name */
name|struct
name|state
modifier|*
name|p_state
decl_stmt|;
comment|/* Protocol state table */
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
argument_list|(
argument|*o_pvcadd
argument_list|)
comment|/* PVC ADD processing function */
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|,
expr|struct
name|atmaddreq
operator|*
operator|,
expr|struct
name|air_int_rsp
operator|*
operator|)
argument_list|)
expr_stmt|;
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
comment|/* atm.c */
end_comment

begin_decl_stmt
name|int
name|do_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|cmd
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usage
name|__P
argument_list|(
operator|(
expr|struct
name|cmd
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|attach
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|detach
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pvc_add
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|arp_add
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pvc_dlt
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|svc_dlt
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vcc_dlt
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|,
expr|struct
name|atmdelreq
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|arp_dlt
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|help
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atm_eni.c */
end_comment

begin_decl_stmt
name|void
name|show_eni_stats
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_eni_oc3
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_eni_atm
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_eni_aal0
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_eni_aal5
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_eni_driver
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atm_fore200.c */
end_comment

begin_decl_stmt
name|void
name|show_fore200_stats
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_fore200_taxi
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_fore200_oc3
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_fore200_dev
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_fore200_atm
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_fore200_aal0
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_fore200_aal4
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_fore200_aal5
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_fore200_driver
name|__P
argument_list|(
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atm_inet.c */
end_comment

begin_decl_stmt
name|void
name|ip_pvcadd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|,
expr|struct
name|atmaddreq
operator|*
operator|,
expr|struct
name|air_int_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atm_print.c */
end_comment

begin_decl_stmt
name|void
name|print_arp_info
name|__P
argument_list|(
operator|(
expr|struct
name|air_arp_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_asrv_info
name|__P
argument_list|(
operator|(
expr|struct
name|air_asrv_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_cfg_info
name|__P
argument_list|(
operator|(
expr|struct
name|air_cfg_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_intf_info
name|__P
argument_list|(
operator|(
expr|struct
name|air_int_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_ip_vcc_info
name|__P
argument_list|(
operator|(
expr|struct
name|air_ip_vcc_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_netif_info
name|__P
argument_list|(
operator|(
expr|struct
name|air_netif_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_intf_stats
name|__P
argument_list|(
operator|(
expr|struct
name|air_phy_stat_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_vcc_stats
name|__P
argument_list|(
operator|(
expr|struct
name|air_vcc_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_vcc_info
name|__P
argument_list|(
operator|(
expr|struct
name|air_vcc_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_version_info
name|__P
argument_list|(
operator|(
expr|struct
name|air_version_rsp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atm_set.c */
end_comment

begin_decl_stmt
name|void
name|set_arpserver
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_macaddr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_netif
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_prefix
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atm_show.c */
end_comment

begin_decl_stmt
name|void
name|show_arp
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show_arpserv
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show_config
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show_intf
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show_ip_vcc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show_netif
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show_intf_stats
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show_vcc_stats
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show_vcc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show_version
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|cmd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atm_subr.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|get_vendor
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|get_adapter
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|get_media_type
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|get_bus_type
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|get_bus_slot_info
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|get_adapter_name
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_info_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|atminfreq
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|get_vcc_info
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|air_vcc_rsp
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|verify_nif_name
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr_in
modifier|*
name|get_ip_addr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|get_hex_addr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|format_mac_addr
name|__P
argument_list|(
operator|(
name|Mac_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|parse_ip_prefix
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|compress_prefix_list
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|check_netif_name
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sock_error
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

