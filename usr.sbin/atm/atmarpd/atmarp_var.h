begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Server Cache Synchronization Protocol (SCSP) Support  * ----------------------------------------------------  *  * SCSP-ATMARP server interface: control blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATMARP_ATMARP_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_ATMARP_ATMARP_VAR_H
end_define

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
comment|/*  * Operational constants  */
end_comment

begin_define
define|#
directive|define
name|ATMARP_DIR
value|"/tmp"
end_define

begin_define
define|#
directive|define
name|ATMARP_SOCK_PREFIX
value|"AA_"
end_define

begin_define
define|#
directive|define
name|ATMARP_CACHE_INTERVAL
value|50
end_define

begin_define
define|#
directive|define
name|ATMARP_PERM_INTERVAL
value|600
end_define

begin_define
define|#
directive|define
name|ATMARP_KEEPALIVE_INTERVAL
value|5
end_define

begin_comment
comment|/*  * Macros for manipulating ATMARP tables and entries  */
end_comment

begin_define
define|#
directive|define
name|ATMARP_HASHSIZ
value|19
end_define

begin_comment
comment|/* Hash table size */
end_comment

begin_define
define|#
directive|define
name|ATMARP_HASH
parameter_list|(
name|ip
parameter_list|)
value|((u_long)(ip) % ATMARP_HASHSIZ)
end_define

begin_define
define|#
directive|define
name|ATMARP_ADD
parameter_list|(
name|ai
parameter_list|,
name|aa
parameter_list|)
define|\
value|{								\ 	Atmarp	**h;						\ 	h =&ai->ai_arptbl[ATMARP_HASH((aa)->aa_dstip.s_addr)];	\ 	LINK2TAIL((aa), Atmarp, *h, aa_next);			\ }
end_define

begin_define
define|#
directive|define
name|ATMARP_DELETE
parameter_list|(
name|ai
parameter_list|,
name|aa
parameter_list|)
define|\
value|{								\ 	Atmarp	**h;						\ 	h =&ai->ai_arptbl[ATMARP_HASH((aa)->aa_dstip.s_addr)];	\ 	UNLINK((aa), Atmarp, *h, aa_next);			\ }
end_define

begin_define
define|#
directive|define
name|ATMARP_LOOKUP
parameter_list|(
name|ai
parameter_list|,
name|ip
parameter_list|,
name|aa
parameter_list|)
define|\
value|{								\ 	for ((aa) = (ai)->ai_arptbl[ATMARP_HASH(ip)];		\ 				(aa); (aa) = (aa)->aa_next) {	\ 		if ((aa)->aa_dstip.s_addr == (ip))		\ 			break;					\ 	}							\ }
end_define

begin_comment
comment|/*  * Macro to compare originator ID structures  */
end_comment

begin_define
define|#
directive|define
name|OID_EQUAL
parameter_list|(
name|id1
parameter_list|,
name|id2
parameter_list|)
define|\
value|(((id1)->id_len == (id2)->id_len)&&			\ 	(bcmp((caddr_t)(id1)->id,				\ 	 	(caddr_t)(id2)->id,				\ 		(id1)->id_len) == 0))
end_define

begin_define
define|#
directive|define
name|KEY_EQUAL
parameter_list|(
name|key1
parameter_list|,
name|key2
parameter_list|)
define|\
value|(((key1)->key_len == (key2)->key_len)&&		\ 	(bcmp((caddr_t)(key1)->key,				\ 	 	(caddr_t)(key2)->key,				\ 		(key1)->key_len) == 0))
end_define

begin_comment
comment|/*  * Interface entry for ATMARP SCSP interface daemon  */
end_comment

begin_struct
struct|struct
name|atmarp_intf
block|{
name|struct
name|atmarp_intf
modifier|*
name|ai_next
decl_stmt|;
comment|/* Next chained I/F */
name|char
name|ai_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Network I/F name */
name|struct
name|in_addr
name|ai_ip_addr
decl_stmt|;
comment|/* IP address */
name|struct
name|in_addr
name|ai_subnet_mask
decl_stmt|;
comment|/* Subnet mask */
name|int
name|ai_mtu
decl_stmt|;
comment|/* IP MTU */
name|Atm_addr
name|ai_atm_addr
decl_stmt|;
comment|/* ATM address */
name|Atm_addr
name|ai_atm_subaddr
decl_stmt|;
comment|/* ATM subaddress */
name|int
name|ai_scsp_sock
decl_stmt|;
comment|/* Socket to SCSP */
name|Harp_timer
name|ai_keepalive_t
decl_stmt|;
comment|/* Keepalive timer */
name|char
modifier|*
name|ai_scsp_sockname
decl_stmt|;
comment|/* Socket name */
name|u_char
name|ai_state
decl_stmt|;
comment|/* Interface state */
name|u_char
name|ai_mark
decl_stmt|;
name|struct
name|atmarp
modifier|*
name|ai_arptbl
index|[
name|ATMARP_HASHSIZ
index|]
decl_stmt|;
comment|/* ARP cache */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atmarp_intf
name|Atmarp_intf
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AI_STATE_NULL
value|0
end_define

begin_define
define|#
directive|define
name|AI_STATE_UP
value|1
end_define

begin_comment
comment|/*  * Super-LIS control block for ATMARP server daemon  */
end_comment

begin_struct
struct|struct
name|atmarp_slis
block|{
name|struct
name|atmarp_slis
modifier|*
name|as_next
decl_stmt|;
comment|/* Next super-LIS */
name|char
modifier|*
name|as_name
decl_stmt|;
comment|/* Name of super-LIS */
name|int
name|as_cnt
decl_stmt|;
comment|/* LIS count */
name|Atmarp_intf
modifier|*
name|as_intfs
decl_stmt|;
comment|/* List of intfs */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atmarp_slis
name|Atmarp_slis
typedef|;
end_typedef

begin_comment
comment|/*  * ATMARP cache entry format  */
end_comment

begin_struct
struct|struct
name|atmarp
block|{
name|struct
name|atmarp
modifier|*
name|aa_next
decl_stmt|;
comment|/* Hash chain link */
name|struct
name|in_addr
name|aa_dstip
decl_stmt|;
comment|/* Destination IP addr */
name|Atm_addr
name|aa_dstatm
decl_stmt|;
comment|/* Destination ATM addr */
name|Atm_addr
name|aa_dstatmsub
decl_stmt|;
comment|/* Destination ATM subaddr */
name|struct
name|scsp_ckey
name|aa_key
decl_stmt|;
comment|/* SCSP cache key */
name|struct
name|scsp_id
name|aa_oid
decl_stmt|;
comment|/* SCSP originator ID */
name|long
name|aa_seq
decl_stmt|;
comment|/* SCSP sequence no. */
name|Atmarp_intf
modifier|*
name|aa_intf
decl_stmt|;
comment|/* Interface for entry */
name|u_char
name|aa_flags
decl_stmt|;
comment|/* Flags (see below) */
name|u_char
name|aa_origin
decl_stmt|;
comment|/* Entry origin */
name|char
name|aa_mark
decl_stmt|;
comment|/* Mark */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atmarp
name|Atmarp
typedef|;
end_typedef

begin_comment
comment|/*  * ATMARP Entry Flags  */
end_comment

begin_define
define|#
directive|define
name|AAF_PERM
value|0x01
end_define

begin_comment
comment|/* Entry is permanent */
end_comment

begin_define
define|#
directive|define
name|AAF_SERVER
value|0x02
end_define

begin_comment
comment|/* Entry is for the server */
end_comment

begin_comment
comment|/*  * Global variables  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|prog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atmarp_debug_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atmarp_max_socket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Atmarp_intf
modifier|*
name|atmarp_intf_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Atmarp_slis
modifier|*
name|atmarp_slis_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|atmarp_log_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Function definitions  */
end_comment

begin_comment
comment|/* atmarp_config.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|atmarp_cfg_netif
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atmarp_log.c */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
specifier|extern
name|void
name|atmarp_log
name|__P
argument_list|(
operator|(
specifier|const
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|void
name|atmarp_log
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|va_alist
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|atmarp_mem_err
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atmarp_scsp.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|atmarp_scsp_cache
name|__P
argument_list|(
operator|(
name|Atmarp_intf
operator|*
operator|,
name|Scsp_if_msg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atmarp_scsp_update
name|__P
argument_list|(
operator|(
name|Atmarp
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atmarp_scsp_update_in
name|__P
argument_list|(
operator|(
name|Atmarp_intf
operator|*
operator|,
name|Scsp_if_msg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atmarp_scsp_read
name|__P
argument_list|(
operator|(
name|Atmarp_intf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atmarp_scsp_out
name|__P
argument_list|(
operator|(
name|Atmarp_intf
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atmarp_scsp_connect
name|__P
argument_list|(
operator|(
name|Atmarp_intf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|atmarp_scsp_close
name|__P
argument_list|(
operator|(
name|Atmarp_intf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atmarp_scsp_disconnect
name|__P
argument_list|(
operator|(
name|Atmarp_intf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atmarp_subr.c */
end_comment

begin_decl_stmt
specifier|extern
name|Atmarp_intf
modifier|*
name|atmarp_find_intf_sock
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Atmarp_intf
modifier|*
name|atmarp_find_intf_name
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
specifier|extern
name|void
name|atmarp_clear_marks
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atmarp_is_server
name|__P
argument_list|(
operator|(
name|Atmarp_intf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atmarp_if_ready
name|__P
argument_list|(
operator|(
name|Atmarp_intf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Atmarp
modifier|*
name|atmarp_copy_cache_entry
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
specifier|extern
name|int
name|atmarp_update_kernel
name|__P
argument_list|(
operator|(
name|Atmarp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|atmarp_get_updated_cache
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|atmarp_process_cache_entry
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
specifier|extern
name|void
name|print_atmarp_intf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|Atmarp_intf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_atmarp_cache
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|Atmarp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_atmarp_cache
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|Atmarp_intf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|atmarp_sigint
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atmarp_timer.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|atmarp_cache_timeout
name|__P
argument_list|(
operator|(
name|Harp_timer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|atmarp_perm_timeout
name|__P
argument_list|(
operator|(
name|Harp_timer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|atmarp_keepalive_timeout
name|__P
argument_list|(
operator|(
name|Harp_timer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATMARP_ATMARP_VAR_H */
end_comment

end_unit

