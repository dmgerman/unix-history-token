begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * ATM Stack definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_ATM_STACK_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_ATM_STACK_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure used to define a kernel-provided ATM stack service and its  * associated entry points.  Each stack service provider must register  * themselves before they will be used.  ATM stack service providers include   * kernel modules (both linked and loaded) and device drivers, which must list  * (via its atm_pif) any of its available hardware-supplied stack services   * (such as on-card AAL processing).  */
end_comment

begin_struct
struct|struct
name|stack_defn
block|{
name|struct
name|stack_defn
modifier|*
name|sd_next
decl_stmt|;
comment|/* Next in registry list */
name|Sap_t
name|sd_sap
decl_stmt|;
comment|/* Stack instance SAP */
name|u_char
name|sd_flag
decl_stmt|;
comment|/* Flags (see below) */
comment|/* Exported functions */
name|int
argument_list|(
argument|*sd_inst
argument_list|)
comment|/* Stack instantiation */
name|__P
argument_list|(
operator|(
expr|struct
name|stack_defn
operator|*
operator|*
operator|,
name|Atm_connvc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*sd_lower
argument_list|)
comment|/* Lower (from above) command handler */
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
name|void
argument_list|(
argument|*sd_upper
argument_list|)
comment|/* Upper (from below) command handler */
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
comment|/* Variables used during stack instantiation */
name|void
modifier|*
name|sd_toku
decl_stmt|;
comment|/* Stack service instance token */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Stack Service Flags  */
end_comment

begin_define
define|#
directive|define
name|SDF_TERM
value|0x01
end_define

begin_comment
comment|/* Terminal (to lowest layer) service */
end_comment

begin_comment
comment|/*  * Stack Specification List    *  * The list names the stack services and their layering relationships in  * order to construct a stack to provide the protocol services defined  * by the list.  The list is ordered starting from the stack service   * interfacing with the user "down" to the ATM cell service.  */
end_comment

begin_define
define|#
directive|define
name|STACK_CNT
value|8
end_define

begin_comment
comment|/* Max services in a stack list */
end_comment

begin_struct
struct|struct
name|stack_list
block|{
name|Sap_t
name|sl_sap
index|[
name|STACK_CNT
index|]
decl_stmt|;
comment|/* Stack service SAP list */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used during the construction and instantiation of a stack   * instance from a supplied stack list.  It contains pointers to the stack   * service definitions which will be used to implement the stack.  The first   * element in the array is reserved for the user's "stack service".  */
end_comment

begin_struct
struct|struct
name|stack_inst
block|{
name|struct
name|stack_defn
modifier|*
name|si_srvc
index|[
name|STACK_CNT
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Assigned services */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macros to update buffer headroom values during stack instantiation.  *  * These values are advisory, i.e. every service must verify the amount  * of available space in input/output messages and allocate new buffers  * if needed.  *  * The 'maximum' and 'minimum' values used below may be chosen by a   * service to reflect the typical, expected message traffic pattern   * for a specific connection.  *   * The macro arguments are:  *	cvp = pointer to connection vcc;  *	hi = maximum amount of buffer headroom required by the current  *	     service during input message processing;  *	si = minimum amount of buffer data stripped off the front   *	     of an input message by the current service;  *	ho = maximum amount of buffer headroom required by the current  *	     service during output message processing;  *	ao = maximum amount of buffer data added to the front   *	     of an output message by the current service;  */
end_comment

begin_define
define|#
directive|define
name|HEADIN
parameter_list|(
name|cvp
parameter_list|,
name|hi
parameter_list|,
name|si
parameter_list|)
define|\
value|{								\ 	short	t = (cvp)->cvc_attr.headin - (si);		\ 	t = (t>= (hi)) ? t : (hi);				\ 	(cvp)->cvc_attr.headin = roundup(t, sizeof(long));	\ }
end_define

begin_define
define|#
directive|define
name|HEADOUT
parameter_list|(
name|cvp
parameter_list|,
name|ho
parameter_list|,
name|ao
parameter_list|)
define|\
value|{								\ 	short	t = (cvp)->cvc_attr.headout + (ao);		\ 	t = (t>= (ho)) ? t : (ho);				\ 	(cvp)->cvc_attr.headout = roundup(t, sizeof(long));	\ }
end_define

begin_comment
comment|/*  * Stack command codes - All stack command codes are specific to the   * defined stack SAP across which the command is used.  Command values 0-15   * are reserved for any common codes, which all stack SAPs must support.  */
end_comment

begin_define
define|#
directive|define
name|STKCMD
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|v
parameter_list|)
value|(((s)<< 16) | (d) | (v))
end_define

begin_define
define|#
directive|define
name|STKCMD_DOWN
value|0
end_define

begin_define
define|#
directive|define
name|STKCMD_UP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|STKCMD_SAP_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|STKCMD_VAL_MASK
value|0x00007fff
end_define

begin_comment
comment|/* Common command values (0-15) */
end_comment

begin_define
define|#
directive|define
name|CCV_INIT
value|1
end_define

begin_comment
comment|/* DOWN */
end_comment

begin_define
define|#
directive|define
name|CCV_TERM
value|2
end_define

begin_comment
comment|/* DOWN */
end_comment

begin_comment
comment|/* SAP_ATM */
end_comment

begin_define
define|#
directive|define
name|ATM_INIT
value|STKCMD(SAP_ATM, STKCMD_DOWN, CCV_INIT)
end_define

begin_define
define|#
directive|define
name|ATM_TERM
value|STKCMD(SAP_ATM, STKCMD_DOWN, CCV_TERM)
end_define

begin_define
define|#
directive|define
name|ATM_DATA_REQ
value|STKCMD(SAP_ATM, STKCMD_DOWN, 16)
end_define

begin_define
define|#
directive|define
name|ATM_DATA_IND
value|STKCMD(SAP_ATM, STKCMD_UP, 17)
end_define

begin_comment
comment|/* SAP_SAR */
end_comment

begin_define
define|#
directive|define
name|SAR_INIT
value|STKCMD(SAP_SAR, STKCMD_DOWN, CCV_INIT)
end_define

begin_define
define|#
directive|define
name|SAR_TERM
value|STKCMD(SAP_SAR, STKCMD_DOWN, CCV_TERM)
end_define

begin_define
define|#
directive|define
name|SAR_UNITDATA_INV
value|STKCMD(SAP_SAR, STKCMD_DOWN, 16)
end_define

begin_define
define|#
directive|define
name|SAR_UNITDATA_SIG
value|STKCMD(SAP_SAR, STKCMD_UP, 17)
end_define

begin_define
define|#
directive|define
name|SAR_UABORT_INV
value|STKCMD(SAP_SAR, STKCMD_DOWN, 18)
end_define

begin_define
define|#
directive|define
name|SAR_UABORT_SIG
value|STKCMD(SAP_SAR, STKCMD_UP, 19)
end_define

begin_define
define|#
directive|define
name|SAR_PABORT_SIG
value|STKCMD(SAP_SAR, STKCMD_UP, 20)
end_define

begin_comment
comment|/* SAP_CPCS */
end_comment

begin_define
define|#
directive|define
name|CPCS_INIT
value|STKCMD(SAP_CPCS, STKCMD_DOWN, CCV_INIT)
end_define

begin_define
define|#
directive|define
name|CPCS_TERM
value|STKCMD(SAP_CPCS, STKCMD_DOWN, CCV_TERM)
end_define

begin_define
define|#
directive|define
name|CPCS_UNITDATA_INV
value|STKCMD(SAP_CPCS, STKCMD_DOWN, 16)
end_define

begin_define
define|#
directive|define
name|CPCS_UNITDATA_SIG
value|STKCMD(SAP_CPCS, STKCMD_UP, 17)
end_define

begin_define
define|#
directive|define
name|CPCS_UABORT_INV
value|STKCMD(SAP_CPCS, STKCMD_DOWN, 18)
end_define

begin_define
define|#
directive|define
name|CPCS_UABORT_SIG
value|STKCMD(SAP_CPCS, STKCMD_UP, 19)
end_define

begin_define
define|#
directive|define
name|CPCS_PABORT_SIG
value|STKCMD(SAP_CPCS, STKCMD_UP, 20)
end_define

begin_comment
comment|/* SAP_SSCOP */
end_comment

begin_define
define|#
directive|define
name|SSCOP_INIT
value|STKCMD(SAP_SSCOP, STKCMD_DOWN, CCV_INIT)
end_define

begin_define
define|#
directive|define
name|SSCOP_TERM
value|STKCMD(SAP_SSCOP, STKCMD_DOWN, CCV_TERM)
end_define

begin_define
define|#
directive|define
name|SSCOP_ESTABLISH_REQ
value|STKCMD(SAP_SSCOP, STKCMD_DOWN, 16)
end_define

begin_define
define|#
directive|define
name|SSCOP_ESTABLISH_IND
value|STKCMD(SAP_SSCOP, STKCMD_UP, 17)
end_define

begin_define
define|#
directive|define
name|SSCOP_ESTABLISH_RSP
value|STKCMD(SAP_SSCOP, STKCMD_DOWN, 18)
end_define

begin_define
define|#
directive|define
name|SSCOP_ESTABLISH_CNF
value|STKCMD(SAP_SSCOP, STKCMD_UP, 19)
end_define

begin_define
define|#
directive|define
name|SSCOP_RELEASE_REQ
value|STKCMD(SAP_SSCOP, STKCMD_DOWN, 20)
end_define

begin_define
define|#
directive|define
name|SSCOP_RELEASE_IND
value|STKCMD(SAP_SSCOP, STKCMD_UP, 21)
end_define

begin_define
define|#
directive|define
name|SSCOP_RELEASE_CNF
value|STKCMD(SAP_SSCOP, STKCMD_UP, 22)
end_define

begin_define
define|#
directive|define
name|SSCOP_DATA_REQ
value|STKCMD(SAP_SSCOP, STKCMD_DOWN, 23)
end_define

begin_define
define|#
directive|define
name|SSCOP_DATA_IND
value|STKCMD(SAP_SSCOP, STKCMD_UP, 24)
end_define

begin_define
define|#
directive|define
name|SSCOP_RESYNC_REQ
value|STKCMD(SAP_SSCOP, STKCMD_DOWN, 25)
end_define

begin_define
define|#
directive|define
name|SSCOP_RESYNC_IND
value|STKCMD(SAP_SSCOP, STKCMD_UP, 26)
end_define

begin_define
define|#
directive|define
name|SSCOP_RESYNC_RSP
value|STKCMD(SAP_SSCOP, STKCMD_DOWN, 27)
end_define

begin_define
define|#
directive|define
name|SSCOP_RESYNC_CNF
value|STKCMD(SAP_SSCOP, STKCMD_UP, 28)
end_define

begin_define
define|#
directive|define
name|SSCOP_RECOVER_IND
value|STKCMD(SAP_SSCOP, STKCMD_UP, 29)
end_define

begin_define
define|#
directive|define
name|SSCOP_RECOVER_RSP
value|STKCMD(SAP_SSCOP, STKCMD_DOWN, 30)
end_define

begin_define
define|#
directive|define
name|SSCOP_UNITDATA_REQ
value|STKCMD(SAP_SSCOP, STKCMD_DOWN, 31)
end_define

begin_define
define|#
directive|define
name|SSCOP_UNITDATA_IND
value|STKCMD(SAP_SSCOP, STKCMD_UP, 32)
end_define

begin_define
define|#
directive|define
name|SSCOP_RETRIEVE_REQ
value|STKCMD(SAP_SSCOP, STKCMD_DOWN, 33)
end_define

begin_define
define|#
directive|define
name|SSCOP_RETRIEVE_IND
value|STKCMD(SAP_SSCOP, STKCMD_UP, 34)
end_define

begin_define
define|#
directive|define
name|SSCOP_RETRIEVECMP_IND
value|STKCMD(SAP_SSCOP, STKCMD_UP, 35)
end_define

begin_comment
comment|/* SAP_SSCF_UNI */
end_comment

begin_define
define|#
directive|define
name|SSCF_UNI_INIT
value|STKCMD(SAP_SSCF_UNI, STKCMD_DOWN, CCV_INIT)
end_define

begin_define
define|#
directive|define
name|SSCF_UNI_TERM
value|STKCMD(SAP_SSCF_UNI, STKCMD_DOWN, CCV_TERM)
end_define

begin_define
define|#
directive|define
name|SSCF_UNI_ESTABLISH_REQ
value|STKCMD(SAP_SSCF_UNI, STKCMD_DOWN, 16)
end_define

begin_define
define|#
directive|define
name|SSCF_UNI_ESTABLISH_IND
value|STKCMD(SAP_SSCF_UNI, STKCMD_UP, 17)
end_define

begin_define
define|#
directive|define
name|SSCF_UNI_ESTABLISH_CNF
value|STKCMD(SAP_SSCF_UNI, STKCMD_UP, 18)
end_define

begin_define
define|#
directive|define
name|SSCF_UNI_RELEASE_REQ
value|STKCMD(SAP_SSCF_UNI, STKCMD_DOWN, 19)
end_define

begin_define
define|#
directive|define
name|SSCF_UNI_RELEASE_IND
value|STKCMD(SAP_SSCF_UNI, STKCMD_UP, 20)
end_define

begin_define
define|#
directive|define
name|SSCF_UNI_RELEASE_CNF
value|STKCMD(SAP_SSCF_UNI, STKCMD_UP, 21)
end_define

begin_define
define|#
directive|define
name|SSCF_UNI_DATA_REQ
value|STKCMD(SAP_SSCF_UNI, STKCMD_DOWN, 22)
end_define

begin_define
define|#
directive|define
name|SSCF_UNI_DATA_IND
value|STKCMD(SAP_SSCF_UNI, STKCMD_UP, 23)
end_define

begin_define
define|#
directive|define
name|SSCF_UNI_UNITDATA_REQ
value|STKCMD(SAP_SSCF_UNI, STKCMD_DOWN, 24)
end_define

begin_define
define|#
directive|define
name|SSCF_UNI_UNITDATA_IND
value|STKCMD(SAP_SSCF_UNI, STKCMD_UP, 25)
end_define

begin_comment
comment|/*  * The STACK_CALL macro must be used for all stack calls between adjacent  * entities.  In order to avoid the problem with recursive stack calls   * modifying protocol state, this macro will only allow calls to proceed if   * they are not "against the flow" of any currently pending calls for a  * stack instance.  If the requested call can't be processed now, it will   * be deferred and queued until a later, safe time (but before control is   * returned back to the kernel scheduler) when it will be dispatched.  *  * The STACK_CALL macro arguments are:  *	cmd = command code;  *	fn  = Destination entity processing function  * 	tok = Destination layer's session token;  *	cvp = Connection VCC address;  *	a1  = command specific argument;  *	a2  = command specific argument;  *	ret = call result value (0 => success)  *  * The receiving entity command processing function prototype is:  *  * 	void (fn)(int cmd, int tok, int arg1, int arg2)  *  */
end_comment

begin_define
define|#
directive|define
name|STACK_CALL
parameter_list|(
name|cmd
parameter_list|,
name|fn
parameter_list|,
name|tok
parameter_list|,
name|cvp
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|ret
parameter_list|)
define|\
value|{									\ 	if ((cmd)& STKCMD_UP) {					\ 		if ((cvp)->cvc_downcnt) {				\ 			(ret) = atm_stack_enq((cmd), (fn), (tok), 	\ 						(cvp), (a1), (a2));	\ 		} else {						\ 			(cvp)->cvc_upcnt++;				\ 			(*fn)(cmd, tok, a1, a2);			\ 			(cvp)->cvc_upcnt--;				\ 			(ret) = 0;					\ 		}							\ 	} else {							\ 		if ((cvp)->cvc_upcnt) {					\ 			(ret) = atm_stack_enq((cmd), (fn), (tok), 	\ 						(cvp), (a1), (a2));	\ 		} else {						\ 			(cvp)->cvc_downcnt++;				\ 			(*fn)(cmd, tok, a1, a2);			\ 			(cvp)->cvc_downcnt--;				\ 			(ret) = 0;					\ 		}							\ 	}								\ }
end_define

begin_comment
comment|/*  * Stack queue entry - The stack queue will contain stack calls which have   * been deferred in order to avoid recursive calls to a single protocol   * control block.  The queue entries are allocated from its own storage pool.  */
end_comment

begin_struct
struct|struct
name|stackq_entry
block|{
name|struct
name|stackq_entry
modifier|*
name|sq_next
decl_stmt|;
comment|/* Next entry in queue */
name|int
name|sq_cmd
decl_stmt|;
comment|/* Stack command */
name|void
argument_list|(
argument|*sq_func
argument_list|)
comment|/* Destination function */
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
name|void
modifier|*
name|sq_token
decl_stmt|;
comment|/* Destination token */
name|int
name|sq_arg1
decl_stmt|;
comment|/* Command-specific argument */
name|int
name|sq_arg2
decl_stmt|;
comment|/* Command-specific argument */
name|Atm_connvc
modifier|*
name|sq_connvc
decl_stmt|;
comment|/* Connection VCC */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macro to avoid unnecessary function call when draining the stack queue.  */
end_comment

begin_define
define|#
directive|define
name|STACK_DRAIN
parameter_list|()
define|\
value|{									\ 	if (atm_stackq_head)						\ 		atm_stack_drain();					\ }
end_define

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
comment|/* _NETATM_ATM_STACK_H */
end_comment

end_unit

