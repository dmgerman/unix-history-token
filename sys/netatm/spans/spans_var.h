begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * SPANS Signalling Manager  * ---------------------------  *  * Protocol control blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPANS_SPANS_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_SPANS_SPANS_VAR_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * Constants to indicate the state of the signalling interface  */
end_comment

begin_define
define|#
directive|define
name|SPANS_UNI_UP
value|1
end_define

begin_define
define|#
directive|define
name|SPANS_UNI_DOWN
value|-1
end_define

begin_comment
comment|/*  * Structure containing state information for each SPANS protocol  * instance.  There will be one instance for each ATM device interface  * using the SPANS signalling manager.  */
end_comment

begin_struct
struct|struct
name|spans
block|{
name|struct
name|siginst
name|sp_inst
decl_stmt|;
comment|/* Header */
name|struct
name|atm_time
name|sp_time
decl_stmt|;
comment|/* Timer controls */
name|void
argument_list|(
argument|*sp_lower
argument_list|)
comment|/* Lower command handler */
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|Atm_connection
modifier|*
name|sp_conn
decl_stmt|;
comment|/* Signalling connection */
name|long
name|sp_s_epoch
decl_stmt|;
comment|/* Switch epoch */
name|long
name|sp_h_epoch
decl_stmt|;
comment|/* Host epoch */
name|u_int
name|sp_probe_ct
decl_stmt|;
comment|/* Status_req msgs unanswered */
name|u_int
name|sp_alloc_vci
decl_stmt|;
comment|/* Next VCI to allocate */
name|u_int
name|sp_alloc_vpi
decl_stmt|;
comment|/* Next VPI to allocate */
name|u_int
name|sp_min_vci
decl_stmt|;
comment|/* Lowest VCI to allocate */
name|u_int
name|sp_max_vci
decl_stmt|;
comment|/* Highest VCI to allocate */
name|struct
name|spanscls
modifier|*
name|sp_cls
decl_stmt|;
comment|/* CLS instance */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sp_next
value|sp_inst.si_next
end_define

begin_define
define|#
directive|define
name|sp_pif
value|sp_inst.si_pif
end_define

begin_define
define|#
directive|define
name|sp_addr
value|sp_inst.si_addr
end_define

begin_define
define|#
directive|define
name|sp_subaddr
value|sp_inst.si_subaddr
end_define

begin_define
define|#
directive|define
name|sp_vccq
value|sp_inst.si_vccq
end_define

begin_define
define|#
directive|define
name|sp_state
value|sp_inst.si_state
end_define

begin_define
define|#
directive|define
name|sp_ipserv
value|sp_inst.si_ipserv
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_KERNEL */
end_comment

begin_comment
comment|/*  * SPANS Protocol States  */
end_comment

begin_define
define|#
directive|define
name|SPANS_ACTIVE
value|1
end_define

begin_comment
comment|/* Active */
end_comment

begin_define
define|#
directive|define
name|SPANS_DETACH
value|2
end_define

begin_comment
comment|/* Detach in progress */
end_comment

begin_define
define|#
directive|define
name|SPANS_INIT
value|3
end_define

begin_comment
comment|/* Initializing */
end_comment

begin_define
define|#
directive|define
name|SPANS_PROBE
value|4
end_define

begin_comment
comment|/* Exchanging status info */
end_comment

begin_define
define|#
directive|define
name|SPANS_PROBE_INTERVAL
value|(ATM_HZ)
end_define

begin_comment
comment|/* Interval between SPANS_STAT_REQs */
end_comment

begin_define
define|#
directive|define
name|SPANS_PROBE_THRESH
value|10
end_define

begin_comment
comment|/* Probe time-out threshold */
end_comment

begin_define
define|#
directive|define
name|SPANS_PROBE_ERR_WAIT
value|(3 * ATM_HZ)
end_define

begin_comment
comment|/* Time to wait if send probe fails */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * SPANS Virtual Channel Connection control block.  All information  * regarding the state of a SPANS-controlled VCC will be recorded here.  * There will be one SPANS VCC control block for each SPANS-controlled  * VCC.  */
end_comment

begin_struct
struct|struct
name|spans_vccb
block|{
name|struct
name|vccb
name|vcp_hdr
decl_stmt|;
comment|/* Generic VCCB */
name|u_short
name|sv_retry
decl_stmt|;
comment|/* Xmit retry count */
name|spans_atm_conn
name|sv_conn
decl_stmt|;
comment|/* SPANS connection info */
name|spans_resrc
name|sv_spans_qos
decl_stmt|;
comment|/* QoS for VCC */
name|spans_aal
name|sv_spans_aal
decl_stmt|;
comment|/* AAL for VCC */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sv_type
value|vcp_hdr.vc_type
end_define

begin_define
define|#
directive|define
name|sv_proto
value|vcp_hdr.vc_proto
end_define

begin_define
define|#
directive|define
name|sv_sstate
value|vcp_hdr.vc_sstate
end_define

begin_define
define|#
directive|define
name|sv_ustate
value|vcp_hdr.vc_ustate
end_define

begin_define
define|#
directive|define
name|sv_pif
value|vcp_hdr.vc_pif
end_define

begin_define
define|#
directive|define
name|sv_nif
value|vcp_hdr.vc_nif
end_define

begin_define
define|#
directive|define
name|sv_sigelem
value|vcp_hdr.vc_sigelem
end_define

begin_define
define|#
directive|define
name|sv_time
value|vcp_hdr.vc_time
end_define

begin_define
define|#
directive|define
name|sv_vpi
value|vcp_hdr.vc_vpi
end_define

begin_define
define|#
directive|define
name|sv_vci
value|vcp_hdr.vc_vci
end_define

begin_define
define|#
directive|define
name|sv_connvc
value|vcp_hdr.vc_connvc
end_define

begin_define
define|#
directive|define
name|sv_ipdus
value|vcp_hdr.vc_ipdus
end_define

begin_define
define|#
directive|define
name|sv_opdus
value|vcp_hdr.vc_opdus
end_define

begin_define
define|#
directive|define
name|sv_ibytes
value|vcp_hdr.vc_ibytes
end_define

begin_define
define|#
directive|define
name|sv_obytes
value|vcp_hdr.vc_obytes
end_define

begin_define
define|#
directive|define
name|sv_ierrors
value|vcp_hdr.vc_ierrors
end_define

begin_define
define|#
directive|define
name|sv_oerrors
value|vcp_hdr.vc_oerrors
end_define

begin_define
define|#
directive|define
name|sv_tstamp
value|vcp_hdr.vc_tstamp
end_define

begin_define
define|#
directive|define
name|sv_daddr
value|sv_conn.daddr
end_define

begin_define
define|#
directive|define
name|sv_saddr
value|sv_conn.saddr
end_define

begin_define
define|#
directive|define
name|sv_dsap
value|sv_conn.dsap
end_define

begin_define
define|#
directive|define
name|sv_ssap
value|sv_conn.ssap
end_define

begin_define
define|#
directive|define
name|SV_MAX_RETRY
value|3
end_define

begin_define
define|#
directive|define
name|SV_TIMEOUT
value|(ATM_HZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_KERNEL */
end_comment

begin_comment
comment|/*  * SPANS VCC Signalling Protocol States  */
end_comment

begin_define
define|#
directive|define
name|SPANS_VC_NULL
value|0
end_define

begin_comment
comment|/* No state */
end_comment

begin_define
define|#
directive|define
name|SPANS_VC_ACTIVE
value|1
end_define

begin_comment
comment|/* Active */
end_comment

begin_define
define|#
directive|define
name|SPANS_VC_ACT_DOWN
value|2
end_define

begin_comment
comment|/* Active - Interface down */
end_comment

begin_define
define|#
directive|define
name|SPANS_VC_POPEN
value|3
end_define

begin_comment
comment|/* VCC open in progress */
end_comment

begin_define
define|#
directive|define
name|SPANS_VC_R_POPEN
value|4
end_define

begin_comment
comment|/* VCC rmt open in progress */
end_comment

begin_define
define|#
directive|define
name|SPANS_VC_OPEN
value|5
end_define

begin_comment
comment|/* VCC open */
end_comment

begin_define
define|#
directive|define
name|SPANS_VC_CLOSE
value|6
end_define

begin_comment
comment|/* VCC close in progress */
end_comment

begin_define
define|#
directive|define
name|SPANS_VC_ABORT
value|7
end_define

begin_comment
comment|/* VCC abort in progress */
end_comment

begin_define
define|#
directive|define
name|SPANS_VC_FREE
value|8
end_define

begin_comment
comment|/* Waiting for user to free resources */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * Macro to compare two SPANS addresses.    *  * Returns 0 if the addresses are equal.  */
end_comment

begin_define
define|#
directive|define
name|spans_addr_cmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(bcmp((caddr_t)a, (caddr_t)b, sizeof(struct spans_addr)))
end_define

begin_comment
comment|/*  * Macro to copy a SPANS address from a to b.    */
end_comment

begin_define
define|#
directive|define
name|spans_addr_copy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(KM_COPY((caddr_t)a, (caddr_t)b, sizeof(struct spans_addr)))
end_define

begin_comment
comment|/*  * Timer macros  */
end_comment

begin_define
define|#
directive|define
name|SPANS_TIMER
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|atm_timeout(&(s)->sp_time, (t), spans_timer)
end_define

begin_define
define|#
directive|define
name|SPANS_CANCEL
parameter_list|(
name|s
parameter_list|)
value|atm_untimeout(&(s)->sp_time)
end_define

begin_define
define|#
directive|define
name|SPANS_VC_TIMER
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|atm_timeout(&(v)->vc_time, (t), spans_vctimer)
end_define

begin_define
define|#
directive|define
name|SPANS_VC_CANCEL
parameter_list|(
name|v
parameter_list|)
value|atm_untimeout(&(v)->vc_time)
end_define

begin_comment
comment|/*  * Global function declarations  */
end_comment

begin_struct_decl
struct_decl|struct
name|ipvcc
struct_decl|;
end_struct_decl

begin_comment
comment|/* spans_arp.c */
end_comment

begin_decl_stmt
name|int
name|spansarp_svcout
name|__P
argument_list|(
operator|(
expr|struct
name|ipvcc
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
name|spansarp_svcin
name|__P
argument_list|(
operator|(
expr|struct
name|ipvcc
operator|*
operator|,
name|Atm_addr
operator|*
operator|,
name|Atm_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spansarp_svcactive
name|__P
argument_list|(
operator|(
expr|struct
name|ipvcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spansarp_vcclose
name|__P
argument_list|(
operator|(
expr|struct
name|ipvcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spansarp_ipact
name|__P
argument_list|(
operator|(
expr|struct
name|spanscls
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spansarp_ipdact
name|__P
argument_list|(
operator|(
expr|struct
name|spanscls
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spansarp_stop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spansarp_input
name|__P
argument_list|(
operator|(
expr|struct
name|spanscls
operator|*
operator|,
name|KBuffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spansarp_ioctl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|caddr_t
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spans_cls.c */
end_comment

begin_decl_stmt
name|int
name|spanscls_start
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spanscls_stop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spanscls_attach
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spanscls_detach
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spanscls_closevc
name|__P
argument_list|(
operator|(
expr|struct
name|spanscls
operator|*
operator|,
expr|struct
name|t_atm_cause
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spans_if.c */
end_comment

begin_decl_stmt
name|int
name|spans_abort
name|__P
argument_list|(
operator|(
expr|struct
name|vccb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spans_free
name|__P
argument_list|(
operator|(
expr|struct
name|vccb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spans_msg.c */
end_comment

begin_decl_stmt
name|int
name|spans_send_msg
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
name|spans_msg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spans_send_open_req
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
expr|struct
name|spans_vccb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spans_send_open_rsp
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
expr|struct
name|spans_vccb
operator|*
operator|,
name|spans_result
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spans_send_close_req
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
expr|struct
name|spans_vccb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spans_rcv_msg
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
name|KBuffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spans_print.c */
end_comment

begin_decl_stmt
name|void
name|spans_print_msg
name|__P
argument_list|(
operator|(
name|spans_msg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spans_proto.c */
end_comment

begin_decl_stmt
name|void
name|spans_timer
name|__P
argument_list|(
operator|(
expr|struct
name|atm_time
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spans_vctimer
name|__P
argument_list|(
operator|(
expr|struct
name|atm_time
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spans_upper
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spans_notify
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spans_subr.c */
end_comment

begin_decl_stmt
name|int
name|spans_open_vcc
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
name|Atm_connvc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spans_close_vcc
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
expr|struct
name|spans_vccb
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spans_clear_vcc
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
expr|struct
name|spans_vccb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spans_switch_reset
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spans_util.c */
end_comment

begin_decl_stmt
name|int
name|spans_get_spans_sap
name|__P
argument_list|(
operator|(
name|Sap_t
operator|,
name|spans_sap
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spans_get_local_sap
name|__P
argument_list|(
operator|(
name|spans_sap
operator|,
name|Sap_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spans_ephemeral_sap
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spans_get_spans_aal
name|__P
argument_list|(
operator|(
name|Aal_t
operator|,
name|spans_aal
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spans_get_local_aal
name|__P
argument_list|(
operator|(
name|spans_aal
operator|,
name|Aal_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spans_verify_vccb
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
expr|struct
name|spans_vccb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|spans_vccb
modifier|*
name|spans_find_vpvc
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|u_char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|spans_vccb
modifier|*
name|spans_find_conn
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|,
expr|struct
name|spans_atm_conn
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|spans_vpvc
name|spans_alloc_vpvc
name|__P
argument_list|(
operator|(
expr|struct
name|spans
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|spans_addr_print
name|__P
argument_list|(
operator|(
expr|struct
name|spans_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spans_dump_buffer
name|__P
argument_list|(
operator|(
name|KBuffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * External variables  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|spans_addr
name|spans_bcastaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|spans_vcpool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|spans_msgpool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|t_atm_cause
name|spans_cause
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPANS_SPANS_VAR_H */
end_comment

end_unit

