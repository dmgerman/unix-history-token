begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/sig/unidef.h,v 1.9 2004/07/08 08:22:24 brandt Exp $  *  * UNI public definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATM_SIG_UNIDEF_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATM_SIG_UNIDEF_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Debug facilities  */
end_comment

begin_define
define|#
directive|define
name|UNI_DEBUG_FACILITIES
define|\
value|UNI_DEBUG_DEFINE(TIMEOUT)	\ 	UNI_DEBUG_DEFINE(RESTART)	\ 	UNI_DEBUG_DEFINE(SAAL)		\ 	UNI_DEBUG_DEFINE(PARSE)		\ 	UNI_DEBUG_DEFINE(CALL)		\ 	UNI_DEBUG_DEFINE(WARN)		\ 	UNI_DEBUG_DEFINE(COORD)		\ 	UNI_DEBUG_DEFINE(API)		\ 	UNI_DEBUG_DEFINE(MSG)		\ 	UNI_DEBUG_DEFINE(ERR)		\ 	UNI_DEBUG_DEFINE(VERIFY)	\  enum uni_verb {
end_define

begin_define
define|#
directive|define
name|UNI_DEBUG_DEFINE
parameter_list|(
name|D
parameter_list|)
value|UNI_FAC_##D,
end_define

begin_decl_stmt
name|UNI_DEBUG_FACILITIES
undef|#
directive|undef
name|UNI_DEBUG_DEFINE
name|UNI_MAXFACILITY
decl_stmt|,
end_decl_stmt

begin_comment
unit|};
comment|/*  * Default timer values and repeat counts  */
end_comment

begin_define
define|#
directive|define
name|UNI_T301_DEFAULT
value|180000
end_define

begin_define
define|#
directive|define
name|UNI_T303_DEFAULT
value|4000
end_define

begin_define
define|#
directive|define
name|UNI_T303_CNT_DEFAULT
value|2
end_define

begin_define
define|#
directive|define
name|UNI_T308_DEFAULT
value|30000
end_define

begin_define
define|#
directive|define
name|UNI_T308_CNT_DEFAULT
value|2
end_define

begin_define
define|#
directive|define
name|UNI_T309_DEFAULT
value|10000
end_define

begin_define
define|#
directive|define
name|UNI_T310U_DEFAULT
value|30000
end_define

begin_define
define|#
directive|define
name|UNI_T310N_DEFAULT
value|10000
end_define

begin_define
define|#
directive|define
name|UNI_T313_DEFAULT
value|4000
end_define

begin_define
define|#
directive|define
name|UNI_T316_DEFAULT
value|120000
end_define

begin_define
define|#
directive|define
name|UNI_T316_CNT_DEFAULT
value|2
end_define

begin_define
define|#
directive|define
name|UNI_T317_DEFAULT
value|90000
end_define

begin_define
define|#
directive|define
name|UNI_T322_DEFAULT
value|4000
end_define

begin_define
define|#
directive|define
name|UNI_T322_CNT_DEFAULT
value|2
end_define

begin_define
define|#
directive|define
name|UNI_T397_DEFAULT
value|UNI_T301_DEFAULT
end_define

begin_define
define|#
directive|define
name|UNI_T398_DEFAULT
value|4000
end_define

begin_define
define|#
directive|define
name|UNI_T399U_DEFAULT
value|(UNI_T303_DEFAULT + UNI_T310U_DEFAULT)
end_define

begin_define
define|#
directive|define
name|UNI_T399N_DEFAULT
value|(UNI_T303_DEFAULT + UNI_T310N_DEFAULT)
end_define

begin_comment
comment|/*  * Protocol support  */
end_comment

begin_enum
enum|enum
name|uni_proto
block|{
name|UNIPROTO_UNI40U
block|,
comment|/* UNI4.0 user side */
name|UNIPROTO_UNI40N
block|,
comment|/* UNI4.0 network side */
name|UNIPROTO_PNNI10
block|,
comment|/* PNNI1.0 */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_popt
block|{
name|UNIPROTO_GFP
init|=
literal|0x0001
block|,
comment|/* enable GFP */
name|UNIPROTO_SB_TB
init|=
literal|0x0002
block|,
comment|/* Coincident Sb-Tb/Tb */
name|UNIPROTO_ALLMASK
init|=
literal|0x0003
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Other options  */
end_comment

begin_enum
enum|enum
name|uni_option
block|{
name|UNIOPT_GIT_HARD
init|=
literal|0x0001
block|,
comment|/* harder check of GIT IE */
name|UNIOPT_BEARER_HARD
init|=
literal|0x0002
block|,
comment|/* harder check of BEARER IE */
name|UNIOPT_CAUSE_HARD
init|=
literal|0x0004
block|,
comment|/* harder check of CAUSE IE */
name|UNIOPT_ALLMASK
init|=
literal|0x0007
block|, }
enum|;
end_enum

begin_comment
comment|/*  * UNI configuration  */
end_comment

begin_struct
struct|struct
name|uni_config
block|{
name|uint32_t
name|proto
decl_stmt|;
comment|/* which protocol */
name|uint32_t
name|popt
decl_stmt|;
comment|/* protocol option */
name|uint32_t
name|option
decl_stmt|;
comment|/* other options */
name|uint32_t
name|timer301
decl_stmt|;
comment|/* T301 */
name|uint32_t
name|timer303
decl_stmt|;
comment|/* T303 */
name|uint32_t
name|init303
decl_stmt|;
comment|/* T303 retransmission count */
name|uint32_t
name|timer308
decl_stmt|;
comment|/* T308 */
name|uint32_t
name|init308
decl_stmt|;
comment|/* T308 retransmission count */
name|uint32_t
name|timer309
decl_stmt|;
comment|/* T309 */
name|uint32_t
name|timer310
decl_stmt|;
comment|/* T310 */
name|uint32_t
name|timer313
decl_stmt|;
comment|/* T313 */
name|uint32_t
name|timer316
decl_stmt|;
comment|/* T316 */
name|uint32_t
name|init316
decl_stmt|;
comment|/* T316 retransmission count */
name|uint32_t
name|timer317
decl_stmt|;
comment|/* T317 */
name|uint32_t
name|timer322
decl_stmt|;
comment|/* T322 */
name|uint32_t
name|init322
decl_stmt|;
comment|/* T322 retransmission count */
name|uint32_t
name|timer397
decl_stmt|;
comment|/* T397 */
name|uint32_t
name|timer398
decl_stmt|;
comment|/* T398 */
name|uint32_t
name|timer399
decl_stmt|;
comment|/* T399 */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|uni_config_mask
block|{
name|UNICFG_PROTO
init|=
literal|0x00000001
block|,
name|UNICFG_TIMER301
init|=
literal|0x00000002
block|,
name|UNICFG_TIMER303
init|=
literal|0x00000004
block|,
name|UNICFG_INIT303
init|=
literal|0x00000008
block|,
name|UNICFG_TIMER308
init|=
literal|0x00000010
block|,
name|UNICFG_INIT308
init|=
literal|0x00000020
block|,
name|UNICFG_TIMER309
init|=
literal|0x00000040
block|,
name|UNICFG_TIMER310
init|=
literal|0x00000080
block|,
name|UNICFG_TIMER313
init|=
literal|0x00000100
block|,
name|UNICFG_TIMER316
init|=
literal|0x00000200
block|,
name|UNICFG_INIT316
init|=
literal|0x00000400
block|,
name|UNICFG_TIMER317
init|=
literal|0x00000800
block|,
name|UNICFG_TIMER322
init|=
literal|0x00001000
block|,
name|UNICFG_INIT322
init|=
literal|0x00002000
block|,
name|UNICFG_TIMER397
init|=
literal|0x00004000
block|,
name|UNICFG_TIMER398
init|=
literal|0x00008000
block|,
name|UNICFG_TIMER399
init|=
literal|0x00010000
block|,
name|UNICFG_ALLMASK
init|=
literal|0x0001ffff
block|, }
enum|;
end_enum

begin_comment
comment|/*  * API signals  */
end_comment

begin_enum
enum|enum
name|uni_sig
block|{
name|UNIAPI_ERROR
init|=
literal|0
block|,
comment|/* UNI -> API */
name|UNIAPI_CALL_CREATED
init|=
literal|1
block|,
comment|/* UNI -> API */
name|UNIAPI_CALL_DESTROYED
init|=
literal|2
block|,
comment|/* UNI -> API */
name|UNIAPI_PARTY_CREATED
init|=
literal|3
block|,
comment|/* UNI -> API */
name|UNIAPI_PARTY_DESTROYED
init|=
literal|4
block|,
comment|/* UNI -> API */
name|UNIAPI_LINK_ESTABLISH_request
init|=
literal|5
block|,
comment|/* API -> UNI */
name|UNIAPI_LINK_ESTABLISH_confirm
init|=
literal|6
block|,
comment|/* UNI -> API */
name|UNIAPI_LINK_RELEASE_request
init|=
literal|7
block|,
comment|/* API -> UNI */
name|UNIAPI_LINK_RELEASE_confirm
init|=
literal|8
block|,
comment|/* UNI -> API */
name|UNIAPI_RESET_request
init|=
literal|9
block|,
comment|/* API -> UNI */
name|UNIAPI_RESET_confirm
init|=
literal|10
block|,
comment|/* UNI -> API */
name|UNIAPI_RESET_indication
init|=
literal|11
block|,
comment|/* UNI -> API */
name|UNIAPI_RESET_ERROR_indication
init|=
literal|12
block|,
comment|/* UNI -> API */
name|UNIAPI_RESET_response
init|=
literal|13
block|,
comment|/* API -> UNI */
name|UNIAPI_RESET_ERROR_response
init|=
literal|14
block|,
comment|/* API -> UNI */
name|UNIAPI_RESET_STATUS_indication
init|=
literal|15
block|,
comment|/* UNI -> API */
name|UNIAPI_SETUP_request
init|=
literal|16
block|,
comment|/* API -> UNI */
name|UNIAPI_SETUP_indication
init|=
literal|17
block|,
comment|/* UNI -> API */
name|UNIAPI_SETUP_response
init|=
literal|18
block|,
comment|/* API -> UNI */
name|UNIAPI_SETUP_confirm
init|=
literal|19
block|,
comment|/* UNI -> API */
name|UNIAPI_SETUP_COMPLETE_indication
init|=
literal|20
block|,
comment|/* U-UNI -> API */
name|UNIAPI_SETUP_COMPLETE_request
init|=
literal|46
block|,
comment|/* API -> N-UNI */
name|UNIAPI_ALERTING_request
init|=
literal|21
block|,
comment|/* API -> UNI */
name|UNIAPI_ALERTING_indication
init|=
literal|22
block|,
comment|/* UNI -> API */
name|UNIAPI_PROCEEDING_request
init|=
literal|23
block|,
comment|/* API -> UNI */
name|UNIAPI_PROCEEDING_indication
init|=
literal|24
block|,
comment|/* UNI -> API */
name|UNIAPI_RELEASE_request
init|=
literal|25
block|,
comment|/* API -> UNI */
name|UNIAPI_RELEASE_indication
init|=
literal|26
block|,
comment|/* UNI -> API */
name|UNIAPI_RELEASE_response
init|=
literal|27
block|,
comment|/* API -> UNI */
name|UNIAPI_RELEASE_confirm
init|=
literal|28
block|,
comment|/* UNI -> API */
name|UNIAPI_NOTIFY_request
init|=
literal|29
block|,
comment|/* API -> UNI */
name|UNIAPI_NOTIFY_indication
init|=
literal|30
block|,
comment|/* UNI -> API */
name|UNIAPI_STATUS_indication
init|=
literal|31
block|,
comment|/* UNI -> API */
name|UNIAPI_STATUS_ENQUIRY_request
init|=
literal|32
block|,
comment|/* API -> UNI */
name|UNIAPI_ADD_PARTY_request
init|=
literal|33
block|,
comment|/* API -> UNI */
name|UNIAPI_ADD_PARTY_indication
init|=
literal|34
block|,
comment|/* UNI -> API */
name|UNIAPI_PARTY_ALERTING_request
init|=
literal|35
block|,
comment|/* API -> UNI */
name|UNIAPI_PARTY_ALERTING_indication
init|=
literal|36
block|,
comment|/* UNI -> API */
name|UNIAPI_ADD_PARTY_ACK_request
init|=
literal|37
block|,
comment|/* API -> UNI */
name|UNIAPI_ADD_PARTY_ACK_indication
init|=
literal|38
block|,
comment|/* UNI -> API */
name|UNIAPI_ADD_PARTY_REJ_request
init|=
literal|39
block|,
comment|/* API -> UNI */
name|UNIAPI_ADD_PARTY_REJ_indication
init|=
literal|40
block|,
comment|/* UNI -> API */
name|UNIAPI_DROP_PARTY_request
init|=
literal|41
block|,
comment|/* API -> UNI */
name|UNIAPI_DROP_PARTY_indication
init|=
literal|42
block|,
comment|/* UNI -> API */
name|UNIAPI_DROP_PARTY_ACK_request
init|=
literal|43
block|,
comment|/* API -> UNI */
name|UNIAPI_DROP_PARTY_ACK_indication
init|=
literal|44
block|,
comment|/* UNI -> API */
name|UNIAPI_ABORT_CALL_request
init|=
literal|45
block|,
comment|/* API -> UNI */
name|UNIAPI_MAXSIG
init|=
literal|47
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uniapi_error
block|{
name|uint32_t
name|reason
decl_stmt|;
name|uint32_t
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* keep this in sync with atmapi.h:enum atmerr */
end_comment

begin_define
define|#
directive|define
name|UNIAPI_DEF_ERRORS
parameter_list|(
name|MACRO
parameter_list|)
define|\
value|MACRO(OK, 0, "no error")					\ 	MACRO(ERROR_BAD_SIGNAL,	1, "unknown signal")			\ 	MACRO(ERROR_BADCU,	2, "signal in bad co-ordinator state")	\ 	MACRO(ERROR_BAD_CALLSTATE, 3, "signal in bad call state")	\ 	MACRO(ERROR_BAD_EPSTATE, 4, "signal in bad endpoint state")	\ 	MACRO(ERROR_BAD_ARG,	5, "bad argument")			\ 	MACRO(ERROR_BAD_CALL,	6, "unknown call reference")		\ 	MACRO(ERROR_BAD_PARTY,	7, "unknown party")			\ 	MACRO(ERROR_BAD_CTYPE,	8, "bad type of call for signal")	\ 	MACRO(ERROR_BAD_IE,	9, "bad information element")		\ 	MACRO(ERROR_EPREF_INUSE, 10, "endpoint reference already in use") \ 	MACRO(ERROR_MISSING_IE,	11, "missing information element")	\ 	MACRO(ERROR_ENCODING,	12, "error during message encoding")	\ 	MACRO(ERROR_NOMEM,	13, "out of memory")			\ 	MACRO(ERROR_BUSY,	14, "status enquiry busy")
end_define

begin_enum
enum|enum
block|{
define|#
directive|define
name|DEF
parameter_list|(
name|NAME
parameter_list|,
name|VAL
parameter_list|,
name|STR
parameter_list|)
value|UNIAPI_##NAME = VAL,
name|UNIAPI_DEF_ERRORS
argument_list|(
argument|DEF
argument_list|)
undef|#
directive|undef
name|DEF
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uniapi_call_created
block|{
name|struct
name|uni_cref
name|cref
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_call_destroyed
block|{
name|struct
name|uni_cref
name|cref
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_party_created
block|{
name|struct
name|uni_cref
name|cref
decl_stmt|;
name|struct
name|uni_ie_epref
name|epref
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_party_destroyed
block|{
name|struct
name|uni_cref
name|cref
decl_stmt|;
name|struct
name|uni_ie_epref
name|epref
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_abort_call_request
block|{
name|struct
name|uni_cref
name|cref
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_reset_request
block|{
name|struct
name|uni_ie_restart
name|restart
decl_stmt|;
name|struct
name|uni_ie_connid
name|connid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_reset_confirm
block|{
name|struct
name|uni_ie_restart
name|restart
decl_stmt|;
name|struct
name|uni_ie_connid
name|connid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_reset_indication
block|{
name|struct
name|uni_ie_restart
name|restart
decl_stmt|;
name|struct
name|uni_ie_connid
name|connid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_reset_error_indication
block|{
name|uint32_t
name|source
decl_stmt|;
comment|/* 0 - start, 1 - response */
name|uint32_t
name|reason
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNIAPI_DEF_RESET_ERRORS
parameter_list|(
name|MACRO
parameter_list|)
define|\
value|MACRO(UNIAPI_RESET_ERROR_NO_CONFIRM,		0,	\ 	    "no confirmation")					\ 	MACRO(UNIAPI_RESET_ERROR_NO_RESPONSE,		1,	\ 	    "no response")					\ 	MACRO(UNIAPI_RESET_ERROR_PEER_INCOMP_STATE,	2,	\ 	    "incompatible state")
end_define

begin_enum
enum|enum
block|{
define|#
directive|define
name|DEF
parameter_list|(
name|NAME
parameter_list|,
name|VALUE
parameter_list|,
name|STR
parameter_list|)
value|NAME = VALUE,
name|UNIAPI_DEF_RESET_ERRORS
argument_list|(
argument|DEF
argument_list|)
undef|#
directive|undef
name|DEF
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uniapi_reset_response
block|{
name|struct
name|uni_ie_restart
name|restart
decl_stmt|;
name|struct
name|uni_ie_connid
name|connid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_reset_error_response
block|{
name|struct
name|uni_ie_cause
name|cause
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_reset_status_indication
block|{
name|struct
name|uni_cref
name|cref
decl_stmt|;
comment|/* STATUS message CREF */
name|struct
name|uni_ie_callstate
name|callstate
decl_stmt|;
name|struct
name|uni_ie_cause
name|cause
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_setup_request
block|{
name|struct
name|uni_setup
name|setup
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_setup_indication
block|{
name|struct
name|uni_setup
name|setup
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_setup_response
block|{
name|struct
name|uni_connect
name|connect
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_setup_confirm
block|{
name|struct
name|uni_connect
name|connect
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_setup_complete_indication
block|{
name|struct
name|uni_connect_ack
name|connect_ack
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_setup_complete_request
block|{
name|struct
name|uni_connect_ack
name|connect_ack
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_alerting_request
block|{
name|struct
name|uni_alerting
name|alerting
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_alerting_indication
block|{
name|struct
name|uni_alerting
name|alerting
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_proceeding_request
block|{
name|struct
name|uni_call_proc
name|call_proc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_proceeding_indication
block|{
name|struct
name|uni_call_proc
name|call_proc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_release_request
block|{
name|struct
name|uni_release
name|release
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_release_indication
block|{
name|struct
name|uni_release
name|release
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_release_response
block|{
name|struct
name|uni_release_compl
name|release_compl
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A release confirm can come from a RELEASE COMPLETE or a RELEASE.  * Because the IEs in a RELEASE COMPLETE are a subset of a RELEASE,  * use the RELEASE here.  */
end_comment

begin_struct
struct|struct
name|uniapi_release_confirm
block|{
name|struct
name|uni_release
name|release
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_notify_request
block|{
name|struct
name|uni_notify
name|notify
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_notify_indication
block|{
name|struct
name|uni_notify
name|notify
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_status_indication
block|{
name|struct
name|uni_cref
name|cref
decl_stmt|;
name|enum
name|uni_callstate
name|my_state
decl_stmt|;
name|enum
name|uni_cause
name|my_cause
decl_stmt|;
name|struct
name|uni_ie_callstate
name|his_state
decl_stmt|;
name|struct
name|uni_ie_cause
name|his_cause
decl_stmt|;
name|struct
name|uni_ie_epref
name|epref
decl_stmt|;
name|struct
name|uni_ie_epstate
name|epstate
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_status_enquiry_request
block|{
name|struct
name|uni_cref
name|cref
decl_stmt|;
name|struct
name|uni_ie_epref
name|epref
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_add_party_request
block|{
name|struct
name|uni_add_party
name|add
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_add_party_indication
block|{
name|struct
name|uni_add_party
name|add
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_party_alerting_request
block|{
name|struct
name|uni_party_alerting
name|alert
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_party_alerting_indication
block|{
name|struct
name|uni_party_alerting
name|alert
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_add_party_ack_request
block|{
name|struct
name|uni_add_party_ack
name|ack
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_add_party_ack_indication
block|{
name|struct
name|uni_add_party_ack
name|ack
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_add_party_rej_request
block|{
name|struct
name|uni_add_party_rej
name|rej
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_add_party_rej_indication
block|{
name|struct
name|uni_add_party_rej
name|rej
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_drop_party_request
block|{
name|struct
name|uni_drop_party
name|drop
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_drop_party_indication
block|{
name|struct
name|uni_drop_party
name|drop
decl_stmt|;
name|struct
name|uni_ie_cause
name|my_cause
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_drop_party_ack_request
block|{
name|struct
name|uni_drop_party_ack
name|ack
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uniapi_drop_party_ack_indication
block|{
name|struct
name|uni_drop_party
name|drop
decl_stmt|;
name|struct
name|uni_ie_crankback
name|crankback
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|uniapi_all
block|{
name|struct
name|uniapi_error
name|error
decl_stmt|;
name|struct
name|uniapi_call_created
name|call_created
decl_stmt|;
name|struct
name|uniapi_call_destroyed
name|call_destroyed
decl_stmt|;
name|struct
name|uniapi_party_created
name|party_created
decl_stmt|;
name|struct
name|uniapi_party_destroyed
name|party_destroyed
decl_stmt|;
name|struct
name|uniapi_abort_call_request
name|abort_call_request
decl_stmt|;
name|struct
name|uniapi_reset_request
name|reset_request
decl_stmt|;
name|struct
name|uniapi_reset_confirm
name|reset_confirm
decl_stmt|;
name|struct
name|uniapi_reset_indication
name|reset_indication
decl_stmt|;
name|struct
name|uniapi_reset_error_indication
name|reset_error_indication
decl_stmt|;
name|struct
name|uniapi_reset_response
name|reset_response
decl_stmt|;
name|struct
name|uniapi_reset_error_response
name|reset_error_response
decl_stmt|;
name|struct
name|uniapi_reset_status_indication
name|reset_status_indication
decl_stmt|;
name|struct
name|uniapi_setup_request
name|setup_request
decl_stmt|;
name|struct
name|uniapi_setup_indication
name|setup_indication
decl_stmt|;
name|struct
name|uniapi_setup_response
name|setup_response
decl_stmt|;
name|struct
name|uniapi_setup_confirm
name|setup_confirm
decl_stmt|;
name|struct
name|uniapi_setup_complete_indication
name|setup_complete_indication
decl_stmt|;
name|struct
name|uniapi_setup_complete_request
name|setup_complete_request
decl_stmt|;
name|struct
name|uniapi_alerting_request
name|alerting_request
decl_stmt|;
name|struct
name|uniapi_alerting_indication
name|alerting_indication
decl_stmt|;
name|struct
name|uniapi_proceeding_request
name|proceeding_request
decl_stmt|;
name|struct
name|uniapi_proceeding_indication
name|proceeding_indication
decl_stmt|;
name|struct
name|uniapi_release_request
name|release_request
decl_stmt|;
name|struct
name|uniapi_release_indication
name|release_indication
decl_stmt|;
name|struct
name|uniapi_release_response
name|release_response
decl_stmt|;
name|struct
name|uniapi_release_confirm
name|release_confirm
decl_stmt|;
name|struct
name|uniapi_notify_request
name|notify_request
decl_stmt|;
name|struct
name|uniapi_notify_indication
name|notify_indication
decl_stmt|;
name|struct
name|uniapi_status_indication
name|status_indication
decl_stmt|;
name|struct
name|uniapi_status_enquiry_request
name|status_enquiry_request
decl_stmt|;
name|struct
name|uniapi_add_party_request
name|add_party_request
decl_stmt|;
name|struct
name|uniapi_add_party_indication
name|add_party_indication
decl_stmt|;
name|struct
name|uniapi_party_alerting_request
name|party_alerting_request
decl_stmt|;
name|struct
name|uniapi_party_alerting_indication
name|party_alerting_indication
decl_stmt|;
name|struct
name|uniapi_add_party_ack_request
name|add_party_ack_request
decl_stmt|;
name|struct
name|uniapi_add_party_ack_indication
name|add_party_ack_indication
decl_stmt|;
name|struct
name|uniapi_add_party_rej_request
name|add_party_rej_request
decl_stmt|;
name|struct
name|uniapi_add_party_rej_indication
name|add_party_rej_indication
decl_stmt|;
name|struct
name|uniapi_drop_party_request
name|drop_party_request
decl_stmt|;
name|struct
name|uniapi_drop_party_indication
name|drop_party_indication
decl_stmt|;
name|struct
name|uniapi_drop_party_ack_request
name|drop_party_ack_request
decl_stmt|;
name|struct
name|uniapi_drop_party_ack_indication
name|drop_party_ack_indication
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

end_unit

