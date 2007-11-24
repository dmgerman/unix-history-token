begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Server Cache Synchronization Protocol (SCSP) Support  * ----------------------------------------------------  *  * SCSP message formats  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSP_SCSP_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSP_SCSP_VAR_H
end_define

begin_comment
comment|/*  * Protocol constants  */
end_comment

begin_define
define|#
directive|define
name|SCSP_Open_Interval
value|30
end_define

begin_define
define|#
directive|define
name|SCSP_HELLO_Interval
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_HELLO_DF
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_CAReXmitInterval
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_CSUSReXmitInterval
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_CSA_HOP_CNT
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_CSUReXmitInterval
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_CSUReXmitMax
value|5
end_define

begin_comment
comment|/*  * Operational constants  */
end_comment

begin_define
define|#
directive|define
name|SCSPD_CONFIG
value|"/etc/scspd.conf"
end_define

begin_define
define|#
directive|define
name|SCSPD_DIR
value|"/tmp"
end_define

begin_define
define|#
directive|define
name|SCSPD_DUMP
value|"/tmp/scspd.dump"
end_define

begin_define
define|#
directive|define
name|SCSP_HASHSZ
value|19
end_define

begin_define
define|#
directive|define
name|SCSPD_SOCK_NAME
value|"SCSPD"
end_define

begin_comment
comment|/*  * HELLO finite state machine states  */
end_comment

begin_define
define|#
directive|define
name|SCSP_HFSM_DOWN
value|0
end_define

begin_define
define|#
directive|define
name|SCSP_HFSM_WAITING
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_HFSM_UNI_DIR
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_HFSM_BI_DIR
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_HFSM_STATE_CNT
value|SCSP_HFSM_BI_DIR + 1
end_define

begin_comment
comment|/*  * HELLO finite state machine events  */
end_comment

begin_define
define|#
directive|define
name|SCSP_HFSM_VC_ESTAB
value|0
end_define

begin_define
define|#
directive|define
name|SCSP_HFSM_VC_CLOSED
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_HFSM_HELLO_T
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_HFSM_RCV_T
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_HFSM_RCVD
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_HFSM_EVENT_CNT
value|SCSP_HFSM_RCVD + 1
end_define

begin_comment
comment|/*  * Cache Alignment finite state machine states  */
end_comment

begin_define
define|#
directive|define
name|SCSP_CAFSM_DOWN
value|0
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_NEG
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_MASTER
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_SLAVE
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_UPDATE
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_ALIGNED
value|5
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_STATE_CNT
value|SCSP_CAFSM_ALIGNED + 1
end_define

begin_comment
comment|/*  * Cache Alignment finite state machine events  */
end_comment

begin_define
define|#
directive|define
name|SCSP_CAFSM_HELLO_UP
value|0
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_HELLO_DOWN
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_CA_MSG
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_CSUS_MSG
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_CSU_REQ
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_CSU_REPLY
value|5
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_CA_T
value|6
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_CSUS_T
value|7
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_CSU_T
value|8
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_CACHE_UPD
value|9
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_CACHE_RSP
value|10
end_define

begin_define
define|#
directive|define
name|SCSP_CAFSM_EVENT_CNT
value|SCSP_CAFSM_CACHE_RSP + 1
end_define

begin_comment
comment|/*  * Client Interface finite state machine states  */
end_comment

begin_define
define|#
directive|define
name|SCSP_CIFSM_NULL
value|0
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_SUM
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_UPD
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_ALIGN
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_STATE_CNT
value|SCSP_CIFSM_ALIGN + 1
end_define

begin_comment
comment|/*  * Client Interface finite state machine events  */
end_comment

begin_define
define|#
directive|define
name|SCSP_CIFSM_CA_DOWN
value|0
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_CA_SUMM
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_CA_UPD
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_CA_ALIGN
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_SOL_RSP
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_UPD_REQ
value|5
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_UPD_RSP
value|6
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_CSU_REQ
value|7
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_CSU_REPLY
value|8
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_CSU_SOL
value|9
end_define

begin_define
define|#
directive|define
name|SCSP_CIFSM_EVENT_CNT
value|SCSP_CIFSM_CSU_SOL + 1
end_define

begin_comment
comment|/*  * Server connection states (not part of any FSM)  */
end_comment

begin_define
define|#
directive|define
name|SCSP_SS_NULL
value|0
end_define

begin_define
define|#
directive|define
name|SCSP_SS_CFG
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_SS_ACTIVE
value|2
end_define

begin_comment
comment|/*  * Hash a cache key  *  *	key	pointer to an Scsp_ckey structure  */
end_comment

begin_define
define|#
directive|define
name|SCSP_HASH
parameter_list|(
name|key
parameter_list|)
value|scsp_hash((key))
end_define

begin_comment
comment|/*  * Add a cache summary entry to a client's cache summary  *  *	cpp	pointer to a server control block  *	key	pointer to an Scsp_cse structure  */
end_comment

begin_define
define|#
directive|define
name|SCSP_ADD
parameter_list|(
name|cpp
parameter_list|,
name|key
parameter_list|)
define|\
value|{								\ 	Scsp_cse	**c;					\ 	c =&(cpp)->ss_cache[SCSP_HASH(&(key)->sc_key)];	\ 	LINK2TAIL((key), Scsp_cse, *c, sc_next);		\ }
end_define

begin_comment
comment|/*  * Delete a cache summary entry from a client's cache summary  *  *	cpp	pointer to a server control block  *	s	pointer to an Scsp_cse structure  */
end_comment

begin_define
define|#
directive|define
name|SCSP_DELETE
parameter_list|(
name|cpp
parameter_list|,
name|s
parameter_list|)
define|\
value|{							\ 	Scsp_cse	**c;				\ 	c =&(cpp)->ss_cache[SCSP_HASH(&(s)->sc_key)];	\ 	UNLINK((s), Scsp_cse, *c, sc_next);		\ }
end_define

begin_comment
comment|/*  * Search a client's cache summary for a given key  *  *	cpp	pointer to a server control block  *	key	pointer to an Scsp_ckey structure to find  *	s	Scsp_cse structure pointer to be set  */
end_comment

begin_define
define|#
directive|define
name|SCSP_LOOKUP
parameter_list|(
name|cpp
parameter_list|,
name|key
parameter_list|,
name|s
parameter_list|)
define|\
value|{								\ 	for ((s) = (cpp)->ss_cache[SCSP_HASH(key)];		\ 			(s);					\ 			(s) = (s)->sc_next) {			\ 		if (scsp_cmp_key((key),&(s)->sc_key) == 0)	\ 			break;					\ 	}							\ }
end_define

begin_comment
comment|/*  * SCSP pending connection control block  *  * The pending connection block is used to keep track of server  * connections which are open but haven't been identified yet.  */
end_comment

begin_struct
struct|struct
name|scsp_pending
block|{
name|struct
name|scsp_pending
modifier|*
name|sp_next
decl_stmt|;
name|int
name|sp_sock
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_pending
name|Scsp_pending
typedef|;
end_typedef

begin_comment
comment|/*  * SCSP Server instance control block  */
end_comment

begin_struct
struct|struct
name|scsp_server
block|{
name|struct
name|scsp_server
modifier|*
name|ss_next
decl_stmt|;
comment|/* Server chain */
name|char
modifier|*
name|ss_name
decl_stmt|;
comment|/* Server name */
name|char
name|ss_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface */
name|Atm_media
name|ss_media
decl_stmt|;
comment|/* Physical comm medium */
name|char
name|ss_state
decl_stmt|;
comment|/* Server connection state */
name|u_long
name|ss_pid
decl_stmt|;
comment|/* Protocol ID */
name|int
name|ss_id_len
decl_stmt|;
comment|/* ID length */
name|int
name|ss_ckey_len
decl_stmt|;
comment|/* Cache key length */
name|u_long
name|ss_sgid
decl_stmt|;
comment|/* Server group ID */
name|u_long
name|ss_fid
decl_stmt|;
comment|/* Family ID */
name|int
name|ss_sock
decl_stmt|;
comment|/* Socket to client */
name|int
name|ss_dcs_lsock
decl_stmt|;
comment|/* DCS listen socket */
name|Scsp_id
name|ss_lsid
decl_stmt|;
comment|/* Local Server ID */
name|Atm_addr
name|ss_addr
decl_stmt|;
comment|/* Local ATM addr */
name|Atm_addr
name|ss_subaddr
decl_stmt|;
comment|/* Local ATM subaddr */
name|int
name|ss_mtu
decl_stmt|;
comment|/* Interface MTU */
name|int
name|ss_mark
decl_stmt|;
name|struct
name|scsp_dcs
modifier|*
name|ss_dcs
decl_stmt|;
comment|/* Ptr to list of DCSs */
name|struct
name|scsp_cse
modifier|*
name|ss_cache
index|[
name|SCSP_HASHSZ
index|]
decl_stmt|;
comment|/* Client's cache */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_server
name|Scsp_server
typedef|;
end_typedef

begin_comment
comment|/*  * SCSP client cache summary entry control block  */
end_comment

begin_struct
struct|struct
name|scsp_cse
block|{
name|struct
name|scsp_cse
modifier|*
name|sc_next
decl_stmt|;
comment|/* Next on chain */
name|long
name|sc_seq
decl_stmt|;
comment|/* CSA sequence no */
name|Scsp_ckey
name|sc_key
decl_stmt|;
comment|/* Cache key */
name|Scsp_id
name|sc_oid
decl_stmt|;
comment|/* Origin ID */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_cse
name|Scsp_cse
typedef|;
end_typedef

begin_comment
comment|/*  * CSU Request retransmission control block  */
end_comment

begin_struct
struct|struct
name|scsp_csu_rexmt
block|{
name|struct
name|scsp_csu_rexmt
modifier|*
name|sr_next
decl_stmt|;
comment|/* Next rexmit block */
name|struct
name|scsp_dcs
modifier|*
name|sr_dcs
decl_stmt|;
comment|/* DCS block */
name|Scsp_csa
modifier|*
name|sr_csa
decl_stmt|;
comment|/* CSAs for rexmit */
name|Harp_timer
name|sr_t
decl_stmt|;
comment|/* Rexmit timer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_csu_rexmt
name|Scsp_csu_rexmt
typedef|;
end_typedef

begin_comment
comment|/*  * SCSP DCS control block  */
end_comment

begin_struct
struct|struct
name|scsp_dcs
block|{
name|struct
name|scsp_dcs
modifier|*
name|sd_next
decl_stmt|;
comment|/* DCS chain */
name|Scsp_server
modifier|*
name|sd_server
decl_stmt|;
comment|/* Local server */
name|Scsp_id
name|sd_dcsid
decl_stmt|;
comment|/* DCS ID */
name|Atm_addr
name|sd_addr
decl_stmt|;
comment|/* DCS ATM address */
name|Atm_addr
name|sd_subaddr
decl_stmt|;
comment|/* DCS ATM subaddress */
name|int
name|sd_sock
decl_stmt|;
comment|/* Socket to DCS */
name|Harp_timer
name|sd_open_t
decl_stmt|;
comment|/* Open VCC retry timer */
name|int
name|sd_hello_state
decl_stmt|;
comment|/* Hello FSM state */
name|int
name|sd_hello_int
decl_stmt|;
comment|/* Hello interval */
name|int
name|sd_hello_df
decl_stmt|;
comment|/* Hello dead factor */
name|int
name|sd_hello_rcvd
decl_stmt|;
comment|/* Hello msg received */
name|Harp_timer
name|sd_hello_h_t
decl_stmt|;
comment|/* Hello timer */
name|Harp_timer
name|sd_hello_rcv_t
decl_stmt|;
comment|/* Hello receive timer */
name|int
name|sd_ca_state
decl_stmt|;
comment|/* CA FSM state */
name|long
name|sd_ca_seq
decl_stmt|;
comment|/* CA sequence number */
name|int
name|sd_ca_rexmt_int
decl_stmt|;
comment|/* CA rexmit interval */
name|Scsp_msg
modifier|*
name|sd_ca_rexmt_msg
decl_stmt|;
comment|/* Saved CA msg */
name|Scsp_cse
modifier|*
name|sd_ca_csas
decl_stmt|;
comment|/* CSAS still to send */
name|Harp_timer
name|sd_ca_rexmt_t
decl_stmt|;
comment|/* CA rexmit timer */
name|int
name|sd_csus_rexmt_int
decl_stmt|;
comment|/* CSUS rexmit int */
name|Scsp_csa
modifier|*
name|sd_crl
decl_stmt|;
comment|/* Cache req list */
name|Scsp_msg
modifier|*
name|sd_csus_rexmt_msg
decl_stmt|;
comment|/* Saved CSUS msg */
name|Harp_timer
name|sd_csus_rexmt_t
decl_stmt|;
comment|/* CSUS rexmit timer */
name|int
name|sd_hops
decl_stmt|;
comment|/* CSA hop count */
name|Scsp_csa
modifier|*
name|sd_csu_ack_pend
decl_stmt|;
comment|/* CSUs to be ACKed */
name|Scsp_csa
modifier|*
name|sd_csu_ack
decl_stmt|;
comment|/* CSUs ACKed */
name|int
name|sd_csu_rexmt_int
decl_stmt|;
comment|/* CSU Req rxmt time */
name|int
name|sd_csu_rexmt_max
decl_stmt|;
comment|/* CSU Req rxmt limit */
name|Scsp_csu_rexmt
modifier|*
name|sd_csu_rexmt
decl_stmt|;
comment|/* CSU Req rxmt queue */
name|int
name|sd_client_state
decl_stmt|;
comment|/* Client I/F state */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_dcs
name|Scsp_dcs
typedef|;
end_typedef

begin_comment
comment|/*  * Trace options  */
end_comment

begin_define
define|#
directive|define
name|SCSP_TRACE_HFSM
value|1
end_define

begin_comment
comment|/* Trace the Hello FSM */
end_comment

begin_define
define|#
directive|define
name|SCSP_TRACE_CAFSM
value|2
end_define

begin_comment
comment|/* Trace the CA FSM */
end_comment

begin_define
define|#
directive|define
name|SCSP_TRACE_CFSM
value|4
end_define

begin_comment
comment|/* Trace the server I/F FSM */
end_comment

begin_define
define|#
directive|define
name|SCSP_TRACE_HELLO_MSG
value|8
end_define

begin_comment
comment|/* Trace Hello protocol msgs */
end_comment

begin_define
define|#
directive|define
name|SCSP_TRACE_CA_MSG
value|16
end_define

begin_comment
comment|/* Trace CA protocol msgs */
end_comment

begin_define
define|#
directive|define
name|SCSP_TRACE_IF_MSG
value|32
end_define

begin_comment
comment|/* Trace server I/F msgs */
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
name|FILE
modifier|*
name|cfg_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|scsp_config_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|scsp_log_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scsp_log_syslog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Scsp_server
modifier|*
name|scsp_server_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Scsp_pending
modifier|*
name|scsp_pending_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scsp_max_socket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scsp_debug_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scsp_trace_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|scsp_trace_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Executable functions  */
end_comment

begin_comment
comment|/* scsp_cafsm.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|scsp_cafsm
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_config.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|scsp_config
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|start_dcs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|finish_dcs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_dcs_addr
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_dcs_ca_rexmit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_dcs_csus_rexmit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_dcs_csu_rexmit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_dcs_csu_rexmit_max
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_dcs_hello_df
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_dcs_hello_int
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_dcs_hops
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_dcs_id
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_intf
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_protocol
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_server_group
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|start_server
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|finish_server
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_log_file
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_config_lex.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_config_parse.y */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
specifier|extern
name|void
name|parse_error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|parse_error
parameter_list|(
name|char
modifier|*
parameter_list|,
name|va_alist
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* scsp_hfsm.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|scsp_hfsm
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Scsp_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_if.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|scsp_cfsm
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Scsp_msg
modifier|*
parameter_list|,
name|Scsp_if_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_input.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|scsp_free_msg
parameter_list|(
name|Scsp_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Scsp_msg
modifier|*
name|scsp_parse_msg
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_log.c */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
specifier|extern
name|void
name|scsp_log
parameter_list|(
specifier|const
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_trace
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|scsp_log
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|va_alist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_trace
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|va_alist
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|scsp_open_trace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_trace_msg
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|Scsp_msg
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_mem_err
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_msg.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|scsp_csus_ack
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|Scsp_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_send_ca
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_send_csus
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_send_csu_req
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|Scsp_csa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_send_csu_reply
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|Scsp_csa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_send_hello
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_output.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|scsp_format_msg
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|Scsp_msg
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_send_msg
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|Scsp_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_print.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|format_hfsm_state
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|format_hfsm_event
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|format_cafsm_state
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|format_cafsm_event
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|format_cifsm_state
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|format_cifsm_event
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_scsp_cse
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|Scsp_cse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_scsp_msg
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|Scsp_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_scsp_if_msg
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|Scsp_if_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_scsp_pending
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|Scsp_pending
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_scsp_server
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|Scsp_server
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_scsp_dcs
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|Scsp_dcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_scsp_dump
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_socket.c */
end_comment

begin_function_decl
specifier|extern
name|Scsp_dcs
modifier|*
name|scsp_find_dcs
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Scsp_server
modifier|*
name|scsp_find_server
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_dcs_connect
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_dcs_listen
parameter_list|(
name|Scsp_server
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Scsp_dcs
modifier|*
name|scsp_dcs_accept
parameter_list|(
name|Scsp_server
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_dcs_read
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_server_listen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_server_accept
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Scsp_if_msg
modifier|*
name|scsp_if_sock_read
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_if_sock_write
parameter_list|(
name|int
parameter_list|,
name|Scsp_if_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_server_read
parameter_list|(
name|Scsp_server
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_send_cache_ind
parameter_list|(
name|Scsp_server
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_pending_read
parameter_list|(
name|Scsp_pending
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_subr.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|scsp_hash
parameter_list|(
name|Scsp_ckey
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_cmp_id
parameter_list|(
name|Scsp_id
modifier|*
parameter_list|,
name|Scsp_id
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_cmp_key
parameter_list|(
name|Scsp_ckey
modifier|*
parameter_list|,
name|Scsp_ckey
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_is_atmarp_server
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Scsp_cse
modifier|*
name|scsp_dup_cse
parameter_list|(
name|Scsp_cse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Scsp_csa
modifier|*
name|scsp_dup_csa
parameter_list|(
name|Scsp_csa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Scsp_csa
modifier|*
name|scsp_cse2csas
parameter_list|(
name|Scsp_cse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_dcs_cleanup
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_dcs_delete
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_server_shutdown
parameter_list|(
name|Scsp_server
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_server_delete
parameter_list|(
name|Scsp_server
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_get_server_info
parameter_list|(
name|Scsp_server
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_process_ca
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|Scsp_ca
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_process_cache_rsp
parameter_list|(
name|Scsp_server
modifier|*
parameter_list|,
name|Scsp_if_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsp_propagate_csa
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|Scsp_csa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_update_cache
parameter_list|(
name|Scsp_dcs
modifier|*
parameter_list|,
name|Scsp_csa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_reconfigure
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* scsp_timer.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|scsp_open_timeout
parameter_list|(
name|Harp_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_hello_timeout
parameter_list|(
name|Harp_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_hello_rcv_timeout
parameter_list|(
name|Harp_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_ca_retran_timeout
parameter_list|(
name|Harp_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_csus_retran_timeout
parameter_list|(
name|Harp_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsp_csu_req_retran_timeout
parameter_list|(
name|Harp_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSP_SCSP_VAR_H */
end_comment

end_unit

