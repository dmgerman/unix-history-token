begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003-2004  *	Hartmut Brandt  *	All rights reserved.  *  * Copyright (c) 2001-2002  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Redistribution of this software and documentation and use in source and  * binary forms, with or without modification, are permitted provided that  * the following conditions are met:  *  * 1. Redistributions of source code or documentation must retain the above  *    copyright notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE AND DOCUMENTATION IS PROVIDED BY THE AUTHORS  * AND ITS CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * THE AUTHORS OR ITS CONTRIBUTORS  BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $Begemot: libunimsg/netnatm/api/atmapi.h,v 1.1 2004/07/08 08:21:48 brandt Exp $  *  * ATM API as defined per af-saa-0108  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_API_ATMAPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_API_ATMAPI_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* size of an endpointlen including trailing \0 */
end_comment

begin_define
define|#
directive|define
name|ATM_EPNAMSIZ
value|65
end_define

begin_enum
enum|enum
name|atmstate
block|{
name|ATM_A0
block|,
comment|/* non existent */
name|ATM_A1
block|,
comment|/* initial */
name|ATM_A2
block|,
comment|/* outgoing call preparation */
name|ATM_A3
block|,
comment|/* outgoing call requested */
name|ATM_A4
block|,
comment|/* incoming call preparation */
name|ATM_A5
block|,
comment|/* wait incoming call */
name|ATM_A6
block|,
comment|/* incoming call present */
name|ATM_A7
block|,
comment|/* incoming call requested */
name|ATM_A8
block|,
comment|/* p2p data transfer */
name|ATM_A9
block|,
comment|/* p2mp root data transfer */
name|ATM_A10
block|,
comment|/* p2mp leaf data transfer */
name|ATM_A11
block|,
comment|/* terminated */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|atmop
block|{
name|ATMOP_RESP
block|,
comment|/* 0 */
name|ATMOP_ABORT_CONNECTION
block|,
name|ATMOP_ACCEPT_INCOMING_CALL
block|,
name|ATMOP_ADD_PARTY
block|,
name|ATMOP_ADD_PARTY_REJECT
block|,
name|ATMOP_ADD_PARTY_SUCCESS
block|,
comment|/* 5 */
name|ATMOP_ARRIVAL_OF_INCOMING_CALL
block|,
name|ATMOP_CALL_RELEASE
block|,
name|ATMOP_CONNECT_OUTGOING_CALL
block|,
name|ATMOP_DROP_PARTY
block|,
name|ATMOP_GET_LOCAL_PORT_INFO
block|,
comment|/* 10 */
name|ATMOP_P2MP_CALL_ACTIVE
block|,
name|ATMOP_P2P_CALL_ACTIVE
block|,
name|ATMOP_PREPARE_INCOMING_CALL
block|,
name|ATMOP_PREPARE_OUTGOING_CALL
block|,
name|ATMOP_QUERY_CONNECTION_ATTRIBUTES
block|,
comment|/* 15 */
name|ATMOP_REJECT_INCOMING_CALL
block|,
name|ATMOP_SET_CONNECTION_ATTRIBUTES
block|,
name|ATMOP_WAIT_ON_INCOMING_CALL
block|,
name|ATMOP_SET_CONNECTION_ATTRIBUTES_X
block|,
name|ATMOP_QUERY_CONNECTION_ATTRIBUTES_X
block|,
comment|/* 20 */
name|ATMOP_QUERY_STATE
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|ATM_DEFINE_ERRORS
define|\
value|DEF(ATMERR_OK,		 0, "OK")				\    DEF(ATMERR_SYS,		-1, "syscall error")			\    DEF(ATMERR_BAD_OP,		-2, "bad operation")			\    DEF(ATMERR_BAD_ARGS,		-3, "bad arguments for operation")	\    DEF(ATMERR_BAD_STATE,	-4, "operation in bad state")		\    DEF(ATMERR_BAD_ATTR,		-5, "unknown attribute")		\    DEF(ATMERR_BAD_VALUE,	-6, "bad attribute value")		\    DEF(ATMERR_BUSY,		-7, "busy")				\    DEF(ATMERR_RDONLY,		-8, "read-only attribute")		\    DEF(ATMERR_BAD_SAP,		-9, "bad SAP")				\    DEF(ATMERR_OVERLAP,		-10,"overlaping SAP")			\    DEF(ATMERR_BAD_ENDPOINT,	-11,"bad ATM endpoint")			\    DEF(ATMERR_PREVIOUSLY_ABORTED,-12,"previously aborted")		\    DEF(ATMERR_NO_CALL,		-13,"no incoming call")			\    DEF(ATMERR_BAD_LEAF_IDENT,	-14,"bad leaf identifier")		\    DEF(ATMERR_BAD_PORT,		-15,"unknown port")			\    DEF(ATMERR_BAD_SIGNAL,	-29-UNIAPI_ERROR_BAD_SIGNAL, "bad signal")\    DEF(ATMERR_BADCU,		-29-UNIAPI_ERROR_BADCU, "bad coordinator state")\    DEF(ATMERR_BAD_CALLSTATE,	-29-UNIAPI_ERROR_BAD_CALLSTATE, "bad call state")\    DEF(ATMERR_BAD_EPSTATE,	-29-UNIAPI_ERROR_BAD_EPSTATE, "bad party state")\    DEF(ATMERR_BAD_UNIARG,	-29-UNIAPI_ERROR_BAD_ARG, "bad uni argument")\    DEF(ATMERR_BAD_CALL,		-29-UNIAPI_ERROR_BAD_CALL, "unknown call")\    DEF(ATMERR_BAD_PARTY,	-29-UNIAPI_ERROR_BAD_PARTY, "unknown party")\    DEF(ATMERR_BAD_CTYPE,	-29-UNIAPI_ERROR_BAD_CTYPE, "wrong call type")\    DEF(ATMERR_BAD_IE,		-29-UNIAPI_ERROR_BAD_IE, "bad information element")\    DEF(ATMERR_EPREF_INUSE,	-29-UNIAPI_ERROR_EPREF_INUSE, "endpoint reference in use")\    DEF(ATMERR_MISSING_IE,	-29-UNIAPI_ERROR_MISSING_IE, "missing information element")\    DEF(ATMERR_ENCODING,		-29-UNIAPI_ERROR_ENCODING, "encoding error")\    DEF(ATMERR_NOMEM,		-29-UNIAPI_ERROR_NOMEM, "no memory")\    DEF(ATMERR_UNIBUSY,		-29-UNIAPI_ERROR_BUSY, "uni process busy")
end_define

begin_define
define|#
directive|define
name|ATM_MKUNIERR
parameter_list|(
name|E
parameter_list|)
value|(-29 - (E))
end_define

begin_enum
enum|enum
name|atm_error
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
value|NAME = (VAL),
name|ATM_DEFINE_ERRORS
undef|#
directive|undef
name|DEF
block|}
enum|;
end_enum

begin_enum
enum|enum
name|atm_attribute
block|{
name|ATM_ATTR_NONE
init|=
literal|0
block|,
name|ATM_ATTR_BLLI_SELECTOR
block|,
name|ATM_ATTR_BLLI
block|,
name|ATM_ATTR_BEARER
block|,
name|ATM_ATTR_TRAFFIC
block|,
name|ATM_ATTR_QOS
block|,
name|ATM_ATTR_EXQOS
block|,
name|ATM_ATTR_CALLED
block|,
name|ATM_ATTR_CALLEDSUB
block|,
name|ATM_ATTR_CALLING
block|,
name|ATM_ATTR_CALLINGSUB
block|,
name|ATM_ATTR_AAL
block|,
name|ATM_ATTR_EPREF
block|,
name|ATM_ATTR_CONNED
block|,
name|ATM_ATTR_CONNEDSUB
block|,
name|ATM_ATTR_EETD
block|,
name|ATM_ATTR_ABRSETUP
block|,
name|ATM_ATTR_ABRADD
block|,
name|ATM_ATTR_CONNID
block|,
name|ATM_ATTR_MDCR
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|atm_resp
block|{
name|int32_t
name|resp
decl_stmt|;
name|uint32_t
name|data
decl_stmt|;
comment|/* type of attached data */
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|ATMRESP_NONE
block|,
comment|/* no data */
name|ATMRESP_ATTRS
block|,
comment|/* attribute(s) */
name|ATMRESP_PORTS
block|,
comment|/* port info */
name|ATMRESP_STATE
block|,
comment|/* endpoint state */
name|ATMRESP_EXSTAT
block|,
comment|/* extended status */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|atm_abort_connection
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
name|atm_query_connection_attributes
block|{
name|uint32_t
name|attr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_set_connection_attributes
block|{
name|uint32_t
name|attr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_query_connection_attributes_x
block|{
name|uint32_t
name|count
decl_stmt|;
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
name|uint32_t
name|attr
index|[
literal|0
index|]
decl_stmt|;
else|#
directive|else
name|uint32_t
name|attr
index|[]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_set_connection_attributes_x
block|{
name|uint32_t
name|count
decl_stmt|;
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
name|uint32_t
name|attr
index|[
literal|0
index|]
decl_stmt|;
else|#
directive|else
name|uint32_t
name|attr
index|[]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_prepare_incoming_call
block|{
name|struct
name|uni_sap
name|sap
decl_stmt|;
name|uint32_t
name|queue_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_connect_outgoing_call
block|{
name|struct
name|uni_ie_called
name|called
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_call_release
block|{
name|struct
name|uni_ie_cause
name|cause
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_p2p_call_active
block|{
name|struct
name|uni_ie_connid
name|connid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_p2mp_call_active
block|{
name|struct
name|uni_ie_connid
name|connid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_accept_incoming_call
block|{
name|char
name|newep
index|[
name|ATM_EPNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_reject_incoming_call
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
name|atm_add_party
block|{
name|uint16_t
name|leaf_ident
decl_stmt|;
name|struct
name|uni_ie_called
name|called
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_add_party_success
block|{
name|uint16_t
name|leaf_ident
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_add_party_reject
block|{
name|uint16_t
name|leaf_ident
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
name|atm_drop_party
block|{
name|uint16_t
name|leaf_ident
decl_stmt|;
name|struct
name|uni_ie_cause
name|cause
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Get local port info. If port is 0, information on all ports is returned,  * otherwise only on the named port.  * The response consists of a header with two counters, a list of ports  * (struct atm_port_info) and a list of addresses (struct uni_addr).  * The port to which an address belongs is implicit in the num_addrs field  * of the port.  */
end_comment

begin_struct
struct|struct
name|atm_get_local_port_info
block|{
name|uint32_t
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_port_list
block|{
name|uint32_t
name|num_ports
decl_stmt|;
comment|/* number of ports */
name|uint32_t
name|num_addrs
decl_stmt|;
comment|/* total number of addresses */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_port_info
block|{
name|uint32_t
name|port
decl_stmt|;
name|uint32_t
name|pcr
decl_stmt|;
name|uint32_t
name|max_vpi_bits
decl_stmt|;
name|uint32_t
name|max_vci_bits
decl_stmt|;
name|uint32_t
name|max_svpc_vpi
decl_stmt|;
name|uint32_t
name|max_svcc_vpi
decl_stmt|;
name|uint32_t
name|min_svcc_vci
decl_stmt|;
name|u_char
name|esi
index|[
literal|6
index|]
decl_stmt|;
name|uint32_t
name|num_addrs
decl_stmt|;
comment|/* number of addresses on this port */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Endpoint state info  */
end_comment

begin_struct
struct|struct
name|atm_epstate
block|{
name|char
name|name
index|[
name|ATM_EPNAMSIZ
index|]
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Extended status information.  */
end_comment

begin_struct
struct|struct
name|atm_exstatus
block|{
name|uint32_t
name|neps
decl_stmt|;
comment|/* endpoints */
name|uint32_t
name|nports
decl_stmt|;
comment|/* ports */
name|uint32_t
name|nconns
decl_stmt|;
comment|/* connections */
name|uint32_t
name|nparties
decl_stmt|;
comment|/* number of parties */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_exstatus_ep
block|{
name|char
name|name
index|[
name|ATM_EPNAMSIZ
index|]
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
comment|/* Ux */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_exstatus_port
block|{
name|uint32_t
name|portno
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_exstatus_conn
block|{
name|uint32_t
name|id
decl_stmt|;
name|uint32_t
name|cref
decl_stmt|;
comment|/* (flag<< 23) | cref */
name|uint32_t
name|port
decl_stmt|;
name|char
name|ep
index|[
name|ATM_EPNAMSIZ
index|]
decl_stmt|;
comment|/* \0 - none */
name|uint8_t
name|state
decl_stmt|;
comment|/* Cx */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_exstatus_party
block|{
name|uint32_t
name|connid
decl_stmt|;
name|uint16_t
name|epref
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
comment|/* Px */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

