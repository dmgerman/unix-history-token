begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI 3.0/3.1 Signalling Manager  * ----------------------------------------  *  * Protocol control blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNISIG_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_UNISIG_VAR_H
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure containing state information for each UNI protocol  * instance.  There will be one instance for each ATM device interface  * using the UNI signalling manager.  */
end_comment

begin_struct
struct|struct
name|unisig
block|{
name|struct
name|siginst
name|us_inst
decl_stmt|;
comment|/* Header */
name|struct
name|atm_time
name|us_time
decl_stmt|;
comment|/* Timer controls */
name|void
function_decl|(
modifier|*
name|us_lower
function_decl|)
comment|/* Lower command handler */
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|Atm_connection
modifier|*
name|us_conn
decl_stmt|;
comment|/* Signalling connection */
name|int
name|us_cref
decl_stmt|;
comment|/* Call reference allocation */
name|u_int
name|us_retry
decl_stmt|;
comment|/* Protocol retry count */
name|u_short
name|us_headout
decl_stmt|;
comment|/* Headroom on sig ch output */
name|u_char
name|us_proto
decl_stmt|;
comment|/* Signalling version */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|us_next
value|us_inst.si_next
end_define

begin_define
define|#
directive|define
name|us_pif
value|us_inst.si_pif
end_define

begin_define
define|#
directive|define
name|us_addr
value|us_inst.si_addr
end_define

begin_define
define|#
directive|define
name|us_subaddr
value|us_inst.si_subaddr
end_define

begin_define
define|#
directive|define
name|us_vccq
value|us_inst.si_vccq
end_define

begin_define
define|#
directive|define
name|us_state
value|us_inst.si_state
end_define

begin_define
define|#
directive|define
name|us_ipserv
value|us_inst.si_ipserv
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Signalling manager states  */
end_comment

begin_define
define|#
directive|define
name|UNISIG_NULL
value|0
end_define

begin_define
define|#
directive|define
name|UNISIG_ADDR_WAIT
value|1
end_define

begin_define
define|#
directive|define
name|UNISIG_INIT
value|2
end_define

begin_define
define|#
directive|define
name|UNISIG_ACTIVE
value|3
end_define

begin_define
define|#
directive|define
name|UNISIG_DETACH
value|4
end_define

begin_comment
comment|/*  * Signalling manager events  */
end_comment

begin_define
define|#
directive|define
name|UNISIG_SIGMGR_TIMEOUT
value|0
end_define

begin_define
define|#
directive|define
name|UNISIG_SIGMGR_SSCF_EST_IND
value|1
end_define

begin_define
define|#
directive|define
name|UNISIG_SIGMGR_SSCF_EST_CNF
value|2
end_define

begin_define
define|#
directive|define
name|UNISIG_SIGMGR_SSCF_RLS_IND
value|3
end_define

begin_define
define|#
directive|define
name|UNISIG_SIGMGR_SSCF_RLS_CNF
value|4
end_define

begin_define
define|#
directive|define
name|UNISIG_SIGMGR_SSCF_DATA_IND
value|5
end_define

begin_define
define|#
directive|define
name|UNISIG_SIGMGR_SSCF_UDATA_IND
value|6
end_define

begin_define
define|#
directive|define
name|UNISIG_SIGMGR_CALL_CLEARED
value|7
end_define

begin_define
define|#
directive|define
name|UNISIG_SIGMGR_DETACH
value|8
end_define

begin_define
define|#
directive|define
name|UNISIG_SIGMGR_ADDR_SET
value|9
end_define

begin_comment
comment|/*  * Signalling manager timer values  */
end_comment

begin_define
define|#
directive|define
name|UNISIG_SSCF_TIMEOUT
value|(3 * ATM_HZ)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * UNI Virtual Channel Connection control block.  All information  * regarding the state of a UNI-controlled VCC will be recorded here.  * There will be one UNI VCC control block for each UNI-controlled  * VCC.  */
end_comment

begin_struct
struct|struct
name|unisig_vccb
block|{
name|struct
name|vccb
name|vcp_hdr
decl_stmt|;
comment|/* Generic VCCB */
name|u_short
name|uv_retry
decl_stmt|;
comment|/* Xmit retry count */
name|u_int
name|uv_call_ref
decl_stmt|;
comment|/* Q.2931 call reference */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|uv_type
value|vcp_hdr.vc_type
end_define

begin_define
define|#
directive|define
name|uv_proto
value|vcp_hdr.vc_proto
end_define

begin_define
define|#
directive|define
name|uv_sstate
value|vcp_hdr.vc_sstate
end_define

begin_define
define|#
directive|define
name|uv_ustate
value|vcp_hdr.vc_ustate
end_define

begin_define
define|#
directive|define
name|uv_pif
value|vcp_hdr.vc_pif
end_define

begin_define
define|#
directive|define
name|uv_nif
value|vcp_hdr.vc_nif
end_define

begin_define
define|#
directive|define
name|uv_sigelem
value|vcp_hdr.vc_sigelem
end_define

begin_define
define|#
directive|define
name|uv_time
value|vcp_hdr.vc_time
end_define

begin_define
define|#
directive|define
name|uv_vpi
value|vcp_hdr.vc_vpi
end_define

begin_define
define|#
directive|define
name|uv_vci
value|vcp_hdr.vc_vci
end_define

begin_define
define|#
directive|define
name|uv_connvc
value|vcp_hdr.vc_connvc
end_define

begin_define
define|#
directive|define
name|uv_ipdus
value|vcp_hdr.vc_ipdus
end_define

begin_define
define|#
directive|define
name|uv_opdus
value|vcp_hdr.vc_opdus
end_define

begin_define
define|#
directive|define
name|uv_ibytes
value|vcp_hdr.vc_ibytes
end_define

begin_define
define|#
directive|define
name|uv_obytes
value|vcp_hdr.vc_obytes
end_define

begin_define
define|#
directive|define
name|uv_ierrors
value|vcp_hdr.vc_ierrors
end_define

begin_define
define|#
directive|define
name|uv_oerrors
value|vcp_hdr.vc_oerrors
end_define

begin_define
define|#
directive|define
name|uv_tstamp
value|vcp_hdr.vc_tstamp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * UNI VCC protocol states.  Taken from The ATM Forum UNI 3.0 (section  * 5.2.1.1)  */
end_comment

begin_define
define|#
directive|define
name|UNI_NULL
value|0
end_define

begin_comment
comment|/* No call exists */
end_comment

begin_define
define|#
directive|define
name|UNI_CALL_INITIATED
value|1
end_define

begin_comment
comment|/* Initiating call */
end_comment

begin_define
define|#
directive|define
name|UNI_CALL_OUT_PROC
value|3
end_define

begin_comment
comment|/* Outgoing call proceeding */
end_comment

begin_define
define|#
directive|define
name|UNI_CALL_DELIVERED
value|4
end_define

begin_comment
comment|/* Not supported */
end_comment

begin_define
define|#
directive|define
name|UNI_CALL_PRESENT
value|6
end_define

begin_comment
comment|/* Call coming in */
end_comment

begin_define
define|#
directive|define
name|UNI_CALL_RECEIVED
value|7
end_define

begin_comment
comment|/* Not supported */
end_comment

begin_define
define|#
directive|define
name|UNI_CONNECT_REQUEST
value|8
end_define

begin_comment
comment|/* Call coming in */
end_comment

begin_define
define|#
directive|define
name|UNI_CALL_IN_PROC
value|9
end_define

begin_comment
comment|/* Incoming call proceeding */
end_comment

begin_define
define|#
directive|define
name|UNI_ACTIVE
value|10
end_define

begin_comment
comment|/* Call is established */
end_comment

begin_define
define|#
directive|define
name|UNI_RELEASE_REQUEST
value|11
end_define

begin_comment
comment|/* Clearing call */
end_comment

begin_define
define|#
directive|define
name|UNI_RELEASE_IND
value|12
end_define

begin_comment
comment|/* Network disconnecting */
end_comment

begin_comment
comment|/*  * Additional states required for internal management of VCCs  */
end_comment

begin_define
define|#
directive|define
name|UNI_SSCF_RECOV
value|13
end_define

begin_comment
comment|/* Signalling chan recovery */
end_comment

begin_define
define|#
directive|define
name|UNI_FREE
value|14
end_define

begin_comment
comment|/* Waiting for user to free */
end_comment

begin_define
define|#
directive|define
name|UNI_PVC_ACTIVE
value|15
end_define

begin_comment
comment|/* PVC Active */
end_comment

begin_define
define|#
directive|define
name|UNI_PVC_ACT_DOWN
value|16
end_define

begin_comment
comment|/* PVC Active - i/f down */
end_comment

begin_comment
comment|/*  * UNI VCC events  */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_TIMEOUT
value|0
end_define

begin_comment
comment|/* Timer expired */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_CALLP_MSG
value|1
end_define

begin_comment
comment|/* CALL PROCEEDING message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_CONNECT_MSG
value|2
end_define

begin_comment
comment|/* CONNECT message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_CNCTACK_MSG
value|3
end_define

begin_comment
comment|/* CONNECT ACK message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_SETUP_MSG
value|4
end_define

begin_comment
comment|/* SETUP message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_RELEASE_MSG
value|5
end_define

begin_comment
comment|/* RELEASE message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_RLSCMP_MSG
value|6
end_define

begin_comment
comment|/* RELEASE COMPLETE message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_STATUS_MSG
value|7
end_define

begin_comment
comment|/* STATUS message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_STATUSENQ_MSG
value|8
end_define

begin_comment
comment|/* STATUS ENQ message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_ADDP_MSG
value|9
end_define

begin_comment
comment|/* ADD PARTY message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_ADDPACK_MSG
value|10
end_define

begin_comment
comment|/* ADD PARTY ACK message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_ADDPREJ_MSG
value|11
end_define

begin_comment
comment|/* ADD PARTY REJ message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_DROP_MSG
value|12
end_define

begin_comment
comment|/* DROP PARTY message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_DROPACK_MSG
value|13
end_define

begin_comment
comment|/* DROP PARTY ACK message */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_SETUP_CALL
value|14
end_define

begin_comment
comment|/* Setup routine called */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_ACCEPT_CALL
value|15
end_define

begin_comment
comment|/* Accept call routine called */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_REJECT_CALL
value|16
end_define

begin_comment
comment|/* Reject call routine called */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_RELEASE_CALL
value|17
end_define

begin_comment
comment|/* Release routine called */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_ABORT_CALL
value|18
end_define

begin_comment
comment|/* Abort routine called */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_SAAL_FAIL
value|19
end_define

begin_comment
comment|/* Signalling AAL failed */
end_comment

begin_define
define|#
directive|define
name|UNI_VC_SAAL_ESTAB
value|20
end_define

begin_comment
comment|/* Signalling AAL back up */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * UNI Timer Values.  These values (except for T317) are taken from  * The ATM Forum UNI 3.0 (section 5.7.2).  */
end_comment

begin_define
define|#
directive|define
name|UNI_T303
value|(4 * ATM_HZ)
end_define

begin_define
define|#
directive|define
name|UNI_T308
value|(30 * ATM_HZ)
end_define

begin_define
define|#
directive|define
name|UNI_T309
value|(10 * ATM_HZ)
end_define

begin_define
define|#
directive|define
name|UNI_T310
value|(10 * ATM_HZ)
end_define

begin_define
define|#
directive|define
name|UNI_T313
value|(4 * ATM_HZ)
end_define

begin_define
define|#
directive|define
name|UNI_T316
value|(120 * ATM_HZ)
end_define

begin_define
define|#
directive|define
name|UNI_T317
value|(60 * ATM_HZ)
end_define

begin_define
define|#
directive|define
name|UNI_T322
value|(4 * ATM_HZ)
end_define

begin_define
define|#
directive|define
name|UNI_T398
value|(4 * ATM_HZ)
end_define

begin_define
define|#
directive|define
name|UNI_T399
value|(14 * ATM_HZ)
end_define

begin_comment
comment|/*  * Timer macros  */
end_comment

begin_define
define|#
directive|define
name|UNISIG_TIMER
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|atm_timeout(&(s)->us_time, (t), unisig_timer)
end_define

begin_define
define|#
directive|define
name|UNISIG_CANCEL
parameter_list|(
name|s
parameter_list|)
value|atm_untimeout(&(s)->us_time)
end_define

begin_define
define|#
directive|define
name|UNISIG_VC_TIMER
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|atm_timeout(&(v)->vc_time, (t), unisig_vctimer)
end_define

begin_define
define|#
directive|define
name|UNISIG_VC_CANCEL
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
name|usfmt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|unisig_msg
struct_decl|;
end_struct_decl

begin_comment
comment|/* unisig_decode.c */
end_comment

begin_function_decl
name|int
name|usf_dec_msg
parameter_list|(
name|struct
name|usfmt
modifier|*
parameter_list|,
name|struct
name|unisig_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unisig_encode.c */
end_comment

begin_function_decl
name|int
name|usf_enc_msg
parameter_list|(
name|struct
name|usfmt
modifier|*
parameter_list|,
name|struct
name|unisig_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unisig_if.c */
end_comment

begin_function_decl
name|int
name|unisig_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_free
parameter_list|(
name|struct
name|vccb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unisig_mbuf.c */
end_comment

begin_function_decl
name|int
name|usf_init
parameter_list|(
name|struct
name|usfmt
modifier|*
parameter_list|,
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usf_byte
parameter_list|(
name|struct
name|usfmt
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usf_short
parameter_list|(
name|struct
name|usfmt
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usf_int3
parameter_list|(
name|struct
name|usfmt
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usf_int
parameter_list|(
name|struct
name|usfmt
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usf_ext
parameter_list|(
name|struct
name|usfmt
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usf_count
parameter_list|(
name|struct
name|usfmt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usf_byte_mark
parameter_list|(
name|struct
name|usfmt
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unisig_msg.c */
end_comment

begin_struct_decl
struct_decl|struct
name|ie_generic
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|unisig_cause_from_attr
parameter_list|(
name|struct
name|ie_generic
modifier|*
parameter_list|,
name|Atm_attributes
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unisig_cause_from_msg
parameter_list|(
name|struct
name|ie_generic
modifier|*
parameter_list|,
name|struct
name|unisig_msg
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_send_msg
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|struct
name|unisig_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_send_setup
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|struct
name|unisig_vccb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_send_release
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|struct
name|unisig_vccb
modifier|*
parameter_list|,
name|struct
name|unisig_msg
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_send_release_complete
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|struct
name|unisig_vccb
modifier|*
parameter_list|,
name|struct
name|unisig_msg
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_send_status
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|struct
name|unisig_vccb
modifier|*
parameter_list|,
name|struct
name|unisig_msg
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_rcv_msg
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unisig_print.c */
end_comment

begin_function_decl
name|void
name|usp_print_msg
parameter_list|(
name|struct
name|unisig_msg
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unisig_proto.c */
end_comment

begin_function_decl
name|void
name|unisig_timer
parameter_list|(
name|struct
name|atm_time
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unisig_vctimer
parameter_list|(
name|struct
name|atm_time
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unisig_saal_ctl
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unisig_saal_data
parameter_list|(
name|void
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|unisig_getname
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unisig_connected
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unisig_cleared
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|t_atm_cause
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unisig_sigmgr_state.c */
end_comment

begin_function_decl
name|int
name|unisig_sigmgr_state
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|int
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unisig_subr.c */
end_comment

begin_function_decl
name|void
name|unisig_cause_attr_from_user
parameter_list|(
name|Atm_attributes
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unisig_cause_attr_from_ie
parameter_list|(
name|Atm_attributes
modifier|*
parameter_list|,
name|struct
name|ie_generic
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_open_vcc
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|Atm_connvc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_close_vcc
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|struct
name|unisig_vccb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_clear_vcc
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|struct
name|unisig_vccb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unisig_switch_reset
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unisig_save_attrs
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|struct
name|unisig_msg
modifier|*
parameter_list|,
name|Atm_attributes
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_set_attrs
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|struct
name|unisig_msg
modifier|*
parameter_list|,
name|Atm_attributes
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unisig_util.c */
end_comment

begin_function_decl
name|void
name|unisig_free_msg
parameter_list|(
name|struct
name|unisig_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_verify_vccb
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|struct
name|unisig_vccb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|unisig_vccb
modifier|*
name|unisig_find_conn
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|unisig_vccb
modifier|*
name|unisig_find_vpvc
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_alloc_call_ref
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|unisig_addr_print
parameter_list|(
name|Atm_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unisig_print_mbuf
parameter_list|(
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unisig_print_buffer
parameter_list|(
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unisig_vc_state.c */
end_comment

begin_function_decl
name|int
name|unisig_vc_state
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|struct
name|unisig_vccb
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|unisig_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * External variables  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|unisig_vcpool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|unisig_msgpool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|unisig_iepool
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNISIG_VAR_H */
end_comment

end_unit

