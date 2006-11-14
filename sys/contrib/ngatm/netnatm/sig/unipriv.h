begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/sig/unipriv.h,v 1.17 2004/07/08 08:22:25 brandt Exp $  *  * Private UNI stuff.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|unipriv_h
end_ifndef

begin_define
define|#
directive|define
name|unipriv_h
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<netgraph/atm/uni/ng_uni_cust.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"unicust.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|call
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|party
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|cu_stat
block|{
name|CU_STAT0
block|,
comment|/* AAL connection released */
name|CU_STAT1
block|,
comment|/* awaiting establish */
name|CU_STAT2
block|,
comment|/* awaiting release */
name|CU_STAT3
block|,
comment|/* AAL connection established */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Internal Signals  */
end_comment

begin_define
define|#
directive|define
name|DEF_COORD_SIGS
define|\
value|DEF_PRIV_SIG(O_SAAL_ESTABLISH_indication,	SAAL)		\   DEF_PRIV_SIG(O_SAAL_ESTABLISH_confirm,	SAAL)		\   DEF_PRIV_SIG(O_SAAL_RELEASE_indication,	SAAL)		\   DEF_PRIV_SIG(O_SAAL_RELEASE_confirm,		SAAL)		\   DEF_PRIV_SIG(O_SAAL_DATA_indication,		SAAL)		\   DEF_PRIV_SIG(O_SAAL_UDATA_indication,		SAAL)		\   DEF_PRIV_SIG(O_T309,				Coord)		\   DEF_PRIV_SIG(O_DATA,				Coord)		\   DEF_PRIV_SIG(O_LINK_ESTABLISH_request,	API)		\   DEF_PRIV_SIG(O_LINK_RELEASE_request,		API)		\   DEF_PRIV_SIG(O_RESET_request,			API)		\   DEF_PRIV_SIG(O_RESET_response,		API)		\   DEF_PRIV_SIG(O_RESET_ERROR_response,		API)		\   DEF_PRIV_SIG(O_SETUP_request,			API)		\   DEF_PRIV_SIG(O_SETUP_response,		API)		\   DEF_PRIV_SIG(O_SETUP_COMPLETE_request,	API)		\   DEF_PRIV_SIG(O_PROCEEDING_request,		API)		\   DEF_PRIV_SIG(O_ALERTING_request,		API)		\   DEF_PRIV_SIG(O_RELEASE_request,		API)		\   DEF_PRIV_SIG(O_RELEASE_response,		API)		\   DEF_PRIV_SIG(O_NOTIFY_request,		API)		\   DEF_PRIV_SIG(O_STATUS_ENQUIRY_request,	API)		\   DEF_PRIV_SIG(O_ADD_PARTY_request,		API)		\   DEF_PRIV_SIG(O_PARTY_ALERTING_request,	API)		\   DEF_PRIV_SIG(O_ADD_PARTY_ACK_request,		API)		\   DEF_PRIV_SIG(O_ADD_PARTY_REJ_request,		API)		\   DEF_PRIV_SIG(O_DROP_PARTY_request,		API)		\   DEF_PRIV_SIG(O_DROP_PARTY_ACK_request,	API)		\   DEF_PRIV_SIG(O_ABORT_CALL_request,		API)		\   DEF_PRIV_SIG(O_CALL_DESTROYED,		CallControl)	\   DEF_PRIV_SIG(O_RESET_indication,		ResetRespond)	\   DEF_PRIV_SIG(O_END,				Coord)
end_define

begin_define
define|#
directive|define
name|DEF_RESPOND_SIGS
define|\
value|DEF_PRIV_SIG(R_RESTART,			Coord)		\   DEF_PRIV_SIG(R_STATUS,			Coord)		\   DEF_PRIV_SIG(R_RESET_response,		Coord)		\   DEF_PRIV_SIG(R_RESET_ERROR_response,		Coord)		\   DEF_PRIV_SIG(R_T317,				ResetRespond)	\   DEF_PRIV_SIG(R_END,				ResetRespond)
end_define

begin_define
define|#
directive|define
name|DEF_START_SIGS
define|\
value|DEF_PRIV_SIG(S_RESTART_ACK,			Coord)		\   DEF_PRIV_SIG(S_STATUS,			Coord)		\   DEF_PRIV_SIG(S_RESET_request,			Coord)		\   DEF_PRIV_SIG(S_T316,				ResetStart)	\   DEF_PRIV_SIG(S_END,				ResetStart)
end_define

begin_define
define|#
directive|define
name|DEF_CALL_SIGS
define|\
value|DEF_PRIV_SIG(C_LINK_ESTABLISH_confirm,	Coord)		\   DEF_PRIV_SIG(C_LINK_ESTABLISH_indication,	Coord)		\   DEF_PRIV_SIG(C_LINK_ESTABLISH_ERROR_indication,Coord)		\   DEF_PRIV_SIG(C_LINK_RELEASE_indication,	Coord)		\   DEF_PRIV_SIG(C_SETUP_request,			Coord)		\   DEF_PRIV_SIG(C_SETUP_response,		Coord)		\   DEF_PRIV_SIG(C_SETUP_COMPLETE_request,	Coord)		\   DEF_PRIV_SIG(C_PROCEEDING_request,		Coord)		\   DEF_PRIV_SIG(C_ALERTING_request,		Coord)		\   DEF_PRIV_SIG(C_RELEASE_request,		Coord)		\   DEF_PRIV_SIG(C_RELEASE_response,		Coord)		\   DEF_PRIV_SIG(C_NOTIFY_request,		Coord)		\   DEF_PRIV_SIG(C_STATUS_ENQUIRY_request,	Coord)		\   DEF_PRIV_SIG(C_ADD_PARTY_request,		Coord)		\   DEF_PRIV_SIG(C_PARTY_ALERTING_request,	Coord)		\   DEF_PRIV_SIG(C_ADD_PARTY_ACK_request,		Coord)		\   DEF_PRIV_SIG(C_ADD_PARTY_REJ_request,		Coord)		\   DEF_PRIV_SIG(C_DROP_PARTY_request,		Coord)		\   DEF_PRIV_SIG(C_DROP_PARTY_ACK_request,	Coord)		\   DEF_PRIV_SIG(C_ABORT_CALL_request,		Coord)		\   DEF_PRIV_SIG(C_UNKNOWN,			Coord)		\   DEF_PRIV_SIG(C_SETUP,				Coord)		\   DEF_PRIV_SIG(C_CALL_PROC,			Coord)		\   DEF_PRIV_SIG(C_ALERTING,			Coord)		\   DEF_PRIV_SIG(C_CONNECT,			Coord)		\   DEF_PRIV_SIG(C_CONNECT_ACK,			Coord)		\   DEF_PRIV_SIG(C_RELEASE,			Coord)		\   DEF_PRIV_SIG(C_RELEASE_COMPL,			Coord)		\   DEF_PRIV_SIG(C_COBISETUP,			Coord)		\   DEF_PRIV_SIG(C_NOTIFY,			Coord)		\   DEF_PRIV_SIG(C_STATUS,			Coord)		\   DEF_PRIV_SIG(C_STATUS_ENQ,			Coord)		\   DEF_PRIV_SIG(C_ADD_PARTY,			Coord)		\   DEF_PRIV_SIG(C_PARTY_ALERTING,		Coord)		\   DEF_PRIV_SIG(C_ADD_PARTY_ACK,			Coord)		\   DEF_PRIV_SIG(C_ADD_PARTY_REJ,			Coord)		\   DEF_PRIV_SIG(C_DROP_PARTY,			Coord)		\   DEF_PRIV_SIG(C_DROP_PARTY_ACK,		Coord)		\   DEF_PRIV_SIG(C_CALL_DELETE,			CallControl)	\   DEF_PRIV_SIG(C_T301,				CallControl)	\   DEF_PRIV_SIG(C_T303,				CallControl)	\   DEF_PRIV_SIG(C_T308,				CallControl)	\   DEF_PRIV_SIG(C_T310,				CallControl)	\   DEF_PRIV_SIG(C_T313,				CallControl)	\   DEF_PRIV_SIG(C_T322,				CallControl)	\   DEF_PRIV_SIG(C_DROP_PARTY_indication,		PartyControl)	\   DEF_PRIV_SIG(C_SEND_DROP_PARTY,		PartyControl)	\   DEF_PRIV_SIG(C_DROP_PARTY_ACK_indication,	PartyControl)	\   DEF_PRIV_SIG(C_SEND_DROP_PARTY_ACK,		PartyControl)	\   DEF_PRIV_SIG(C_ADD_PARTY_REJ_indication,	PartyControl)	\   DEF_PRIV_SIG(C_SEND_ADD_PARTY_REJ,		PartyControl)	\   DEF_PRIV_SIG(C_SEND_STATUS_ENQ,		PartyControl)	\   DEF_PRIV_SIG(C_PARTY_DESTROYED,		PartyControl)	\   DEF_PRIV_SIG(C_END,				CallControl)
end_define

begin_define
define|#
directive|define
name|DEF_PARTY_SIGS
define|\
value|DEF_PRIV_SIG(P_SETUP,				CallControl)		\   DEF_PRIV_SIG(P_ALERTING,			CallControl)		\   DEF_PRIV_SIG(P_CONNECT,			CallControl)		\   DEF_PRIV_SIG(P_CONNECT_ACK,			CallControl)		\   DEF_PRIV_SIG(P_RELEASE,			CallControl)		\   DEF_PRIV_SIG(P_RELEASE_COMPL,			CallControl)		\   DEF_PRIV_SIG(P_STATUS,			CallControl)		\   DEF_PRIV_SIG(P_ADD_PARTY,			CallControl)		\   DEF_PRIV_SIG(P_PARTY_ALERTING,		CallControl)		\   DEF_PRIV_SIG(P_ADD_PARTY_ACK,			CallControl)		\   DEF_PRIV_SIG(P_ADD_PARTY_REJ,			CallControl)		\   DEF_PRIV_SIG(P_DROP_PARTY,			CallControl)		\   DEF_PRIV_SIG(P_DROP_PARTY_ACK,		CallControl)		\   DEF_PRIV_SIG(P_SETUP_request,			CallControl)		\   DEF_PRIV_SIG(P_SETUP_response,		CallControl)		\   DEF_PRIV_SIG(P_SETUP_COMPL_request,		CallControl)		\   DEF_PRIV_SIG(P_ALERTING_request,		CallControl)		\   DEF_PRIV_SIG(P_RELEASE_request,		CallControl)		\   DEF_PRIV_SIG(P_RELEASE_response,		CallControl)		\   DEF_PRIV_SIG(P_RELEASE_confirm,		CallControl)		\   DEF_PRIV_SIG(P_STATUS_ENQUIRY_request,	CallControl)		\   DEF_PRIV_SIG(P_ADD_PARTY_request,		CallControl)		\   DEF_PRIV_SIG(P_PARTY_ALERTING_request,	CallControl)		\   DEF_PRIV_SIG(P_ADD_PARTY_ACK_request,		CallControl)		\   DEF_PRIV_SIG(P_ADD_PARTY_REJ_request,		CallControl)		\   DEF_PRIV_SIG(P_DROP_PARTY_request,		CallControl)		\   DEF_PRIV_SIG(P_DROP_PARTY_ACK_request,	CallControl)		\   DEF_PRIV_SIG(P_PARTY_DELETE,			PartyControl)		\   DEF_PRIV_SIG(P_T397,				PartyControl)		\   DEF_PRIV_SIG(P_T398,				PartyControl)		\   DEF_PRIV_SIG(P_T399,				PartyControl)		\   DEF_PRIV_SIG(P_END,				PartyControl)
end_define

begin_define
define|#
directive|define
name|DEF_PRIV_SIG
parameter_list|(
name|NAME
parameter_list|,
name|FROM
parameter_list|)
value|SIG##NAME,
end_define

begin_enum
enum|enum
name|coord_sig
block|{
name|DEF_COORD_SIGS
block|}
enum|;
end_enum

begin_enum
enum|enum
name|respond_sig
block|{
name|DEF_RESPOND_SIGS
block|}
enum|;
end_enum

begin_enum
enum|enum
name|start_sig
block|{
name|DEF_START_SIGS
block|}
enum|;
end_enum

begin_enum
enum|enum
name|call_sig
block|{
name|DEF_CALL_SIGS
block|}
enum|;
end_enum

begin_enum
enum|enum
name|party_sig
block|{
name|DEF_PARTY_SIGS
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEF_PRIV_SIG
end_undef

begin_comment
comment|/*************************************************************  *  * SIGNALS and SIGNAL QUEUES  */
end_comment

begin_enum
enum|enum
block|{
name|SIG_COORD
block|,
name|SIG_RESET_START
block|,
name|SIG_RESET_RESP
block|,
name|SIG_CALL
block|,
name|SIG_PARTY
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|sig
block|{
name|TAILQ_ENTRY
argument_list|(
argument|sig
argument_list|)
name|link
expr_stmt|;
name|u_int
name|type
decl_stmt|;
comment|/* one of the above */
name|struct
name|call
modifier|*
name|call
decl_stmt|;
comment|/* call to send to */
name|struct
name|party
modifier|*
name|party
decl_stmt|;
comment|/* party to send to */
name|uint32_t
name|sig
decl_stmt|;
comment|/* the signal */
name|uint32_t
name|cookie
decl_stmt|;
comment|/* user cookie */
name|struct
name|uni_msg
modifier|*
name|msg
decl_stmt|;
comment|/* attached message */
name|struct
name|uni_all
modifier|*
name|u
decl_stmt|;
comment|/* dito */
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sigqueue
argument_list|,
name|sig
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|SIGQ_CLEAR
parameter_list|(
name|Q
parameter_list|)
define|\
value|do {								\ 	struct sig *s;							\ 	while(!TAILQ_EMPTY(Q)) {					\ 		s = TAILQ_FIRST(Q);					\ 		TAILQ_REMOVE(Q, s, link);				\ 		if(s->msg) uni_msg_destroy(s->msg);			\ 		if(s->u) UNI_FREE(s->u);				\ 		SIG_FREE(s);						\ 	}								\     } while(0)
end_define

begin_function_decl
name|void
name|uni_sig_party
parameter_list|(
name|struct
name|party
modifier|*
parameter_list|,
name|enum
name|party_sig
parameter_list|,
name|uint32_t
name|cookie
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_sig_call
parameter_list|(
name|struct
name|call
modifier|*
parameter_list|,
name|enum
name|call_sig
parameter_list|,
name|uint32_t
name|cookie
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_sig_coord
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|enum
name|coord_sig
parameter_list|,
name|uint32_t
name|cookie
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_sig_start
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|enum
name|start_sig
parameter_list|,
name|uint32_t
name|cookie
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_sig_respond
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|enum
name|respond_sig
parameter_list|,
name|uint32_t
name|cookie
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************************************************  *  * CALL INSTANCES  */
end_comment

begin_struct
struct|struct
name|party
block|{
name|struct
name|call
modifier|*
name|call
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|party
argument_list|)
name|link
expr_stmt|;
name|u_int
name|epref
decl_stmt|;
comment|/* endpoint reference */
name|u_int
name|flags
decl_stmt|;
comment|/* flags */
name|enum
name|uni_epstate
name|state
decl_stmt|;
comment|/* party state */
name|struct
name|uni_timer
name|t397
decl_stmt|;
comment|/* T397 */
name|struct
name|uni_timer
name|t398
decl_stmt|;
comment|/* T398 */
name|struct
name|uni_timer
name|t399
decl_stmt|;
comment|/* T399 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PARTY_MINE
value|0x0001
end_define

begin_comment
comment|/* must be 1 */
end_comment

begin_define
define|#
directive|define
name|PARTY_CONNECT
value|0x0002
end_define

begin_comment
comment|/* connect request from this party */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|partyqueue
argument_list|,
name|party
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|uni_destroy_party
parameter_list|(
name|struct
name|party
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|party
modifier|*
name|uni_find_party
parameter_list|(
name|struct
name|call
modifier|*
parameter_list|,
name|struct
name|uni_ie_epref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|party
modifier|*
name|uni_find_partyx
parameter_list|(
name|struct
name|call
modifier|*
parameter_list|,
name|u_int
name|epref
parameter_list|,
name|u_int
name|mine
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|party
modifier|*
name|uni_create_party
parameter_list|(
name|struct
name|call
modifier|*
parameter_list|,
name|struct
name|uni_ie_epref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|party
modifier|*
name|uni_create_partyx
parameter_list|(
name|struct
name|call
modifier|*
parameter_list|,
name|u_int
name|epref
parameter_list|,
name|u_int
name|mine
parameter_list|,
name|uint32_t
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|uni_party_act_count
parameter_list|(
name|struct
name|call
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|call_type
block|{
name|CALL_NULL
block|,
comment|/* not known yet */
name|CALL_P2P
block|,
comment|/* normal point-to-point call */
name|CALL_COBI
block|,
comment|/* Q.2932.1 COBI call */
name|CALL_ROOT
block|,
comment|/* point-to-multipoint root */
name|CALL_LEAF
block|,
comment|/* point-to-multipoint leaf */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|call_state
block|{
name|CALLST_NULL
block|,
name|CALLST_U1
block|,
name|CALLST_U3
block|,
name|CALLST_U4
block|,
name|CALLST_U6
block|,
name|CALLST_U7
block|,
name|CALLST_U8
block|,
name|CALLST_U9
block|,
name|CALLST_U10
block|,
name|CALLST_U11
block|,
name|CALLST_U12
block|,
name|CALLST_N1
block|,
name|CALLST_N3
block|,
name|CALLST_N4
block|,
name|CALLST_N6
block|,
name|CALLST_N7
block|,
name|CALLST_N8
block|,
name|CALLST_N9
block|,
name|CALLST_N10
block|,
name|CALLST_N11
block|,
name|CALLST_N12
block|}
enum|;
end_enum

begin_struct
struct|struct
name|call
block|{
name|TAILQ_ENTRY
argument_list|(
argument|call
argument_list|)
name|link
expr_stmt|;
comment|/* link between calls */
name|struct
name|uni
modifier|*
name|uni
decl_stmt|;
comment|/* backpointer to owning UNI */
name|u_int
name|cref
decl_stmt|;
comment|/* call reference value or lij seqno */
name|u_int
name|mine
decl_stmt|;
comment|/* if TRUE this is my call */
name|enum
name|call_type
name|type
decl_stmt|;
comment|/* what call is it */
name|enum
name|call_state
name|cstate
decl_stmt|;
comment|/* the state of the call */
name|struct
name|uni_ie_connid
name|connid
decl_stmt|;
comment|/* the connection ID */
name|struct
name|uni_setup
name|msg_setup
decl_stmt|;
comment|/* retransmission */
name|struct
name|uni_release
name|msg_release
decl_stmt|;
comment|/* retransmission */
name|struct
name|uni_ie_epref
name|stat_epref
decl_stmt|;
comment|/* retransmission */
name|struct
name|partyqueue
name|parties
decl_stmt|;
name|u_int
name|se_active
decl_stmt|;
comment|/* status enquiry active */
name|u_int
name|epref_alloc
decl_stmt|;
name|struct
name|uni_timer
name|t308
decl_stmt|;
comment|/* T303 */
name|u_int
name|cnt308
decl_stmt|;
name|struct
name|uni_timer
name|t303
decl_stmt|;
comment|/* T303 */
name|u_int
name|cnt303
decl_stmt|;
name|struct
name|uni_timer
name|t301
decl_stmt|;
comment|/* T301 */
name|struct
name|uni_timer
name|t310
decl_stmt|;
comment|/* T310 */
name|struct
name|uni_timer
name|t313
decl_stmt|;
comment|/* T313 */
name|struct
name|uni_timer
name|t322
decl_stmt|;
comment|/* T322 */
name|u_int
name|cnt322
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|callqueue
argument_list|,
name|call
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|struct
name|call
modifier|*
name|uni_find_call
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|struct
name|uni_cref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|call
modifier|*
name|uni_find_callx
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|u_int
name|cref
parameter_list|,
name|u_int
name|mine
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|call
modifier|*
name|uni_create_call
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|u_int
name|cref
parameter_list|,
name|u_int
name|mine
parameter_list|,
name|uint32_t
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|call
modifier|*
name|uni_create_new_call
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|uint32_t
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_destroy_call
parameter_list|(
name|struct
name|call
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_bad_message
parameter_list|(
name|struct
name|call
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|uni_ie_epref
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct
specifier|extern
specifier|const
struct|struct
name|callstates
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|enum
name|uni_callstate
name|ext
decl_stmt|;
block|}
name|callstates
index|[]
struct|;
end_struct

begin_comment
comment|/*************************************************************  *  * UNI INSTANCE  */
end_comment

begin_struct
struct|struct
name|uni
block|{
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* user arg */
specifier|const
name|struct
name|uni_funcs
modifier|*
name|funcs
decl_stmt|;
name|enum
name|uni_proto
name|proto
decl_stmt|;
comment|/* protocol */
name|struct
name|unicx
name|cx
decl_stmt|;
comment|/* decoding/coding context */
name|int
name|sb_tb
range|:
literal|1
decl_stmt|;
comment|/* Sb-Tb/Tb point */
name|struct
name|sigqueue
name|workq
decl_stmt|;
comment|/* work queue */
name|struct
name|sigqueue
name|delq
decl_stmt|;
comment|/* delayed signal queue */
name|int
name|working
decl_stmt|;
name|uint32_t
name|cref_alloc
decl_stmt|;
name|enum
name|cu_stat
name|custat
decl_stmt|;
comment|/* coordinator state */
name|struct
name|uni_timer
name|t309
decl_stmt|;
name|u_int
name|timer309
decl_stmt|;
name|enum
name|uni_callstate
name|glob_start
decl_stmt|;
name|enum
name|uni_callstate
name|glob_respond
decl_stmt|;
name|struct
name|uni_timer
name|t316
decl_stmt|;
name|struct
name|uni_timer
name|t317
decl_stmt|;
name|struct
name|uni_ie_connid
name|connid_start
decl_stmt|;
name|struct
name|uni_ie_connid
name|connid_respond
decl_stmt|;
name|u_int
name|cnt316
decl_stmt|;
name|struct
name|uni_ie_restart
name|restart_start
decl_stmt|;
name|struct
name|callqueue
name|calls
decl_stmt|;
name|struct
name|uni_ie_cause
name|cause
decl_stmt|;
comment|/* working area for verify */
comment|/* tuneable parameters */
name|u_int
name|timer301
decl_stmt|;
name|u_int
name|init303
decl_stmt|;
name|u_int
name|timer303
decl_stmt|;
name|u_int
name|init308
decl_stmt|;
name|u_int
name|timer308
decl_stmt|;
name|u_int
name|timer310
decl_stmt|;
name|u_int
name|timer313
decl_stmt|;
name|u_int
name|init316
decl_stmt|;
name|u_int
name|timer316
decl_stmt|;
name|u_int
name|timer317
decl_stmt|;
name|u_int
name|timer322
decl_stmt|;
name|u_int
name|init322
decl_stmt|;
name|u_int
name|timer397
decl_stmt|;
name|u_int
name|timer398
decl_stmt|;
name|u_int
name|timer399
decl_stmt|;
name|u_int
name|debug
index|[
name|UNI_MAXFACILITY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|uniapi_uni_error
parameter_list|(
name|struct
name|uni
modifier|*
name|uni
parameter_list|,
name|uint32_t
name|reason
parameter_list|,
name|uint32_t
name|cookie
parameter_list|,
name|uint32_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uniapi_call_error
parameter_list|(
name|struct
name|call
modifier|*
name|c
parameter_list|,
name|uint32_t
name|reason
parameter_list|,
name|uint32_t
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uniapi_party_error
parameter_list|(
name|struct
name|party
modifier|*
name|p
parameter_list|,
name|uint32_t
name|reason
parameter_list|,
name|uint32_t
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************************************************  *  * INLINE FUNCTIONS  */
end_comment

begin_comment
comment|/* Enqueue a signal in the working queue */
end_comment

begin_function_decl
name|void
name|uni_enq_sig
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|call
modifier|*
parameter_list|,
name|struct
name|party
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Enqueue a signal in the delayed queue */
end_comment

begin_function_decl
name|void
name|uni_delenq_sig
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|call
modifier|*
parameter_list|,
name|struct
name|party
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Enqueue a signal to the coordinator */
end_comment

begin_define
define|#
directive|define
name|uni_enq_coord
parameter_list|(
name|UNI
parameter_list|,
name|SIG
parameter_list|,
name|COOKIE
parameter_list|,
name|MSG
parameter_list|)
value|do {			\ 	uni_enq_sig((UNI), SIG_COORD, NULL, NULL,			\ 	    (SIG), (COOKIE), (MSG), NULL);				\     } while (0)
end_define

begin_comment
comment|/* Enqueue a delayed signal to the coordinator */
end_comment

begin_define
define|#
directive|define
name|uni_delenq_coord
parameter_list|(
name|UNI
parameter_list|,
name|SIG
parameter_list|,
name|COOKIE
parameter_list|,
name|MSG
parameter_list|)
value|do {			\ 	uni_delenq_sig((UNI), SIG_COORD, NULL, NULL,			\ 	    (SIG), (COOKIE), (MSG), NULL);				\     } while (0)
end_define

begin_comment
comment|/* Enqueue a signal to a call */
end_comment

begin_define
define|#
directive|define
name|uni_enq_call
parameter_list|(
name|CALL
parameter_list|,
name|SIG
parameter_list|,
name|COOKIE
parameter_list|,
name|MSG
parameter_list|,
name|U
parameter_list|)
value|do {			\ 	uni_enq_sig((CALL)->uni, SIG_CALL, (CALL), NULL,		\ 	    (SIG), (COOKIE), (MSG), (U));				\     } while (0)
end_define

begin_comment
comment|/* Enqueue a signal to a party */
end_comment

begin_define
define|#
directive|define
name|uni_enq_party
parameter_list|(
name|PARTY
parameter_list|,
name|SIG
parameter_list|,
name|COOKIE
parameter_list|,
name|MSG
parameter_list|,
name|U
parameter_list|)
value|do {			\ 	uni_enq_sig((PARTY)->call->uni, SIG_PARTY, (PARTY)->call,	\ 	    (PARTY), (SIG), (COOKIE), (MSG), (U));			\     } while (0)
end_define

begin_comment
comment|/* Enqueue a signal to RESET-START */
end_comment

begin_define
define|#
directive|define
name|uni_enq_start
parameter_list|(
name|UNI
parameter_list|,
name|SIG
parameter_list|,
name|COOKIE
parameter_list|,
name|MSG
parameter_list|,
name|U
parameter_list|)
value|do {			\ 	uni_enq_sig((UNI), SIG_RESET_START, NULL, NULL,			\ 	    (SIG), (COOKIE), (MSG), (U));				\     } while (0)
end_define

begin_comment
comment|/* Enqueue a signal to RESET-RESPOND */
end_comment

begin_define
define|#
directive|define
name|uni_enq_resp
parameter_list|(
name|UNI
parameter_list|,
name|SIG
parameter_list|,
name|COOKIE
parameter_list|,
name|MSG
parameter_list|,
name|U
parameter_list|)
value|do {			\ 	uni_enq_sig((UNI), SIG_RESET_RESP, NULL, NULL,			\ 	    (SIG), (COOKIE), (MSG), (U));				\     } while (0)
end_define

begin_function_decl
name|int
name|uni_send_output
parameter_list|(
name|struct
name|uni_all
modifier|*
name|u
parameter_list|,
name|struct
name|uni
modifier|*
name|uni
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_undel
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|sig
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_delsig
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|call
modifier|*
parameter_list|,
name|struct
name|party
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_release_compl
parameter_list|(
name|struct
name|call
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************************************************/
end_comment

begin_comment
comment|/*  * Message verification.  */
end_comment

begin_define
define|#
directive|define
name|MANDATE_IE
parameter_list|(
name|UNI
parameter_list|,
name|MSG
parameter_list|,
name|IE
parameter_list|)
define|\
value|do {								\ 	if (!IE_ISGOOD(MSG))						\ 		uni_mandate_ie(UNI, IE);				\     } while(0)
end_define

begin_enum
enum|enum
name|verify
block|{
name|VFY_OK
block|,
comment|/* ok */
name|VFY_RAP
block|,
comment|/* report and proceed */
name|VFY_RAPU
block|,
comment|/* report and proceed becuase of unknown IEs */
name|VFY_I
block|,
comment|/* ignore */
name|VFY_CLR
block|,
comment|/* clear call */
name|VFY_RAI
block|,
comment|/* report and ignore */
name|VFY_RAIM
block|,
comment|/* report and ignore because if mandat. IE miss */
block|}
enum|;
end_enum

begin_function_decl
name|void
name|uni_mandate_ie
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|enum
name|uni_ietype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_mandate_epref
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|struct
name|uni_ie_epref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|verify
name|uni_verify
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|enum
name|uni_msgact
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_respond_status_verify
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|struct
name|uni_cref
modifier|*
parameter_list|,
name|enum
name|uni_callstate
parameter_list|,
name|struct
name|uni_ie_epref
modifier|*
parameter_list|,
name|enum
name|uni_epstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_vfy_remove_unknown
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_vfy_remove_cause
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_vfy_collect_ies
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_respond_status
parameter_list|(
name|struct
name|uni
modifier|*
name|uni
parameter_list|,
name|struct
name|uni_cref
modifier|*
name|cref
parameter_list|,
name|enum
name|uni_callstate
name|cs
parameter_list|,
name|enum
name|uni_cause
name|c1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_respond_status_mtype
parameter_list|(
name|struct
name|uni
modifier|*
name|uni
parameter_list|,
name|struct
name|uni_cref
modifier|*
name|cref
parameter_list|,
name|enum
name|uni_callstate
name|cs
parameter_list|,
name|enum
name|uni_cause
name|c1
parameter_list|,
name|u_int
name|mtype
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FOREACH_ERR
parameter_list|(
name|E
parameter_list|,
name|UNI
parameter_list|)
define|\
value|for ((E) = (UNI)->cx.err; (E)< (UNI)->cx.err + (UNI)->cx.errcnt; (E)++)
end_define

begin_define
define|#
directive|define
name|ALLOC_API
parameter_list|(
name|TYPE
parameter_list|,
name|API
parameter_list|)
define|\
value|({								\ 	TYPE *_tmp = NULL;					\ 								\ 	if(((API) = uni_msg_alloc(sizeof(TYPE))) != NULL) {	\ 		_tmp = uni_msg_wptr((API), TYPE *);		\ 		(API)->b_wptr += sizeof(TYPE);			\ 		memset(_tmp, 0, sizeof(TYPE));			\ 	}							\ 	_tmp;							\     })
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__GNUC__
operator|<
literal|3
end_if

begin_define
define|#
directive|define
name|VERBOSE
parameter_list|(
name|UNI
parameter_list|,
name|FAC
parameter_list|,
name|LEVEL
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do {			\ 	if ((UNI)->debug[(FAC)]>= (LEVEL)) {			\ 		(UNI)->funcs->verbose((UNI), (UNI)->arg, (FAC) ,\ 		   ## ARGS);					\ 	}							\     } while(0)
end_define

begin_define
define|#
directive|define
name|VERBOSE0
parameter_list|(
name|UNI
parameter_list|,
name|FAC
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do {			\ 	(UNI)->funcs->verbose((UNI), (UNI)->arg, (FAC) ,	\ 	    ## ARGS);						\     } while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VERBOSE
parameter_list|(
name|UNI
parameter_list|,
name|FAC
parameter_list|,
name|LEVEL
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if ((UNI)->debug[(FAC)]>= (LEVEL)) {			\ 		(UNI)->funcs->verbose((UNI), (UNI)->arg, (FAC),	\ 		    __VA_ARGS__);				\ 	}							\     } while(0)
end_define

begin_define
define|#
directive|define
name|VERBOSE0
parameter_list|(
name|UNI
parameter_list|,
name|FAC
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	(UNI)->funcs->verbose((UNI), (UNI)->arg, (FAC),		\ 	    __VA_ARGS__);					\     } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TIMER_INIT_UNI
parameter_list|(
name|U
parameter_list|,
name|T
parameter_list|)
value|_TIMER_INIT(U,T)
end_define

begin_define
define|#
directive|define
name|TIMER_INIT_CALL
parameter_list|(
name|C
parameter_list|,
name|T
parameter_list|)
value|_TIMER_INIT(C,T)
end_define

begin_define
define|#
directive|define
name|TIMER_INIT_PARTY
parameter_list|(
name|P
parameter_list|,
name|T
parameter_list|)
value|_TIMER_INIT(P,T)
end_define

begin_define
define|#
directive|define
name|TIMER_DESTROY_UNI
parameter_list|(
name|U
parameter_list|,
name|T
parameter_list|)
value|_TIMER_DESTROY(U, (U)->T)
end_define

begin_define
define|#
directive|define
name|TIMER_DESTROY_CALL
parameter_list|(
name|C
parameter_list|,
name|T
parameter_list|)
value|_TIMER_DESTROY((C)->uni, (C)->T)
end_define

begin_define
define|#
directive|define
name|TIMER_DESTROY_PARTY
parameter_list|(
name|P
parameter_list|,
name|T
parameter_list|)
value|_TIMER_DESTROY((P)->call->uni, (P)->T)
end_define

begin_define
define|#
directive|define
name|TIMER_STOP_UNI
parameter_list|(
name|U
parameter_list|,
name|T
parameter_list|)
value|_TIMER_STOP(U, (U)->T)
end_define

begin_define
define|#
directive|define
name|TIMER_STOP_CALL
parameter_list|(
name|C
parameter_list|,
name|T
parameter_list|)
value|_TIMER_STOP((C)->uni, (C)->T)
end_define

begin_define
define|#
directive|define
name|TIMER_STOP_PARTY
parameter_list|(
name|P
parameter_list|,
name|T
parameter_list|)
value|_TIMER_STOP((P)->call->uni, (P)->T)
end_define

begin_define
define|#
directive|define
name|TIMER_START_UNI
parameter_list|(
name|U
parameter_list|,
name|T
parameter_list|,
name|N
parameter_list|)
value|_TIMER_START(U, U, (U)->T, N, _##T##_func)
end_define

begin_define
define|#
directive|define
name|TIMER_START_CALL
parameter_list|(
name|C
parameter_list|,
name|T
parameter_list|,
name|N
parameter_list|)
value|_TIMER_START(C->uni, C, (C)->T, N, _##T##_func)
end_define

begin_define
define|#
directive|define
name|TIMER_START_PARTY
parameter_list|(
name|P
parameter_list|,
name|T
parameter_list|,
name|N
parameter_list|)
value|_TIMER_START(P->call->uni, P, (P)->T, N, _##T##_func)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

