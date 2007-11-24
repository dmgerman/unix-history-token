begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003-2004  *	Hartmut Brandt  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Redistribution of this software and documentation and use in source and  * binary forms, with or without modification, are permitted provided that  * the following conditions are met:  *  * 1. Redistributions of source code or documentation must retain the above  *    copyright notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE AND DOCUMENTATION IS PROVIDED BY THE AUTHOR  * AND ITS CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * THE AUTHOR OR ITS CONTRIBUTORS  BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $Begemot: libunimsg/netnatm/api/ccpriv.h,v 1.2 2005/05/23 11:49:17 brandt_h Exp $  *  * ATM API as defined per af-saa-0108  *  * Private declarations.  */
end_comment

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
file|<netgraph/atm/ccatm/ng_ccatm_cust.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|"cccust.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|ccuser
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ccconn
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ccaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ccport
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ccdata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ccsig
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ccparty
struct_decl|;
end_struct_decl

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|ccuser_list
argument_list|,
name|ccuser
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|ccconn_list
argument_list|,
name|ccconn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ccaddr_list
argument_list|,
name|ccaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ccport_list
argument_list|,
name|ccport
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ccsig_list
argument_list|,
name|ccsig
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|ccparty_list
argument_list|,
name|ccparty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Private node data.  */
end_comment

begin_struct
struct|struct
name|ccdata
block|{
name|struct
name|ccuser_list
name|user_list
decl_stmt|;
comment|/* instance list */
name|struct
name|ccport_list
name|port_list
decl_stmt|;
comment|/* list of ports */
name|struct
name|ccconn_list
name|orphaned_conns
decl_stmt|;
comment|/* list of connections */
name|struct
name|ccsig_list
name|sigs
decl_stmt|;
comment|/* current signals */
name|struct
name|ccsig_list
name|def_sigs
decl_stmt|;
comment|/* deferred signals */
name|struct
name|ccsig_list
name|free_sigs
decl_stmt|;
comment|/* free signals */
specifier|const
name|struct
name|cc_funcs
modifier|*
name|funcs
decl_stmt|;
name|uint32_t
name|cookie
decl_stmt|;
comment|/* cookie generator */
name|u_int
name|log
decl_stmt|;
comment|/* logging flags */
block|}
struct|;
end_struct

begin_comment
comment|/* retrieve info on local ports */
end_comment

begin_function_decl
name|struct
name|atm_port_list
modifier|*
name|cc_get_local_port_info
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* log */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CCATM_DEBUG
end_ifdef

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
name|cc_log
parameter_list|(
name|CC
parameter_list|,
name|FMT
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do {					\ 	(CC)->funcs->log("%s (data=%p): " FMT, __FUNCTION__,		\ 	    (CC) , ## ARGS);						\     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cc_log
parameter_list|(
name|CC
parameter_list|,
name|FMT
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	(CC)->funcs->log("%s (data=%p): " FMT, __func__,		\ 	    (CC), __VA_ARGS__);						\     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

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
name|cc_log
parameter_list|(
name|CC
parameter_list|,
name|FMT
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cc_log
parameter_list|(
name|CC
parameter_list|,
name|FMT
parameter_list|,
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * structure to remember cookies for outstanding requests  * we also remember the request itself but don't use it.  */
end_comment

begin_struct
struct|struct
name|ccreq
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ccreq
argument_list|)
name|link
expr_stmt|;
name|uint32_t
name|cookie
decl_stmt|;
name|uint32_t
name|req
decl_stmt|;
name|struct
name|ccconn
modifier|*
name|conn
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ccreq_list
argument_list|,
name|ccreq
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Port data. Each port has one UNI stack below.  * The port number is in param.port. The number is assigned when the  * hook to the uni is connected. This hook has the name 'uni<port>'.  */
end_comment

begin_struct
struct|struct
name|ccport
block|{
name|void
modifier|*
name|uarg
decl_stmt|;
comment|/* hook to UNI protocol */
name|struct
name|ccdata
modifier|*
name|cc
decl_stmt|;
comment|/* back pointer to node */
enum|enum
block|{
name|CCPORT_STOPPED
block|,
comment|/* halted */
name|CCPORT_RUNNING
block|,
comment|/* ok */
block|}
name|admin
enum|;
comment|/* admin status */
name|struct
name|ccconn_list
name|conn_list
decl_stmt|;
comment|/* list of connections */
name|struct
name|ccaddr_list
name|addr_list
decl_stmt|;
comment|/* list of network addresses */
name|struct
name|atm_port_info
name|param
decl_stmt|;
comment|/* parameters */
comment|/* list of outstanding requests */
name|struct
name|ccreq_list
name|cookies
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|ccport
argument_list|)
name|node_link
expr_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CCATM_DEBUG
end_ifdef

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
name|cc_port_log
parameter_list|(
name|P
parameter_list|,
name|FMT
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do {				\ 	(P)->cc->funcs->log("%s (port=%p/%u): " FMT, __FUNCTION__,	\ 	    (P), (P)->param.port , ## ARGS);				\     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cc_port_log
parameter_list|(
name|P
parameter_list|,
name|FMT
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	(P)->cc->funcs->log("%s (port=%p/%u): " FMT, __func__,		\ 	    (P), (P)->param.port, __VA_ARGS__);				\     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

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
name|cc_port_log
parameter_list|(
name|P
parameter_list|,
name|FMT
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cc_port_log
parameter_list|(
name|P
parameter_list|,
name|FMT
parameter_list|,
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CONN_STATES
define|\
value|DEF(CONN_NULL)
comment|/*  C0 */
value|\ 	DEF(CONN_OUT_PREPARING)
comment|/*  C1 */
value|\ 	DEF(CONN_OUT_WAIT_CREATE)
comment|/*  C2 */
value|\ 	DEF(CONN_OUT_WAIT_OK)
comment|/*  C3 */
value|\ 	DEF(CONN_OUT_WAIT_CONF)
comment|/*  C4 */
value|\ 							\ 	DEF(CONN_ACTIVE)
comment|/*  C5 */
value|\ 							\ 	DEF(CONN_IN_PREPARING)
comment|/* C10 */
value|\ 	DEF(CONN_IN_WAITING)
comment|/* C21 */
value|\ 	DEF(CONN_IN_ARRIVED)
comment|/* C11 */
value|\ 	DEF(CONN_IN_WAIT_ACCEPT_OK)
comment|/* C12 */
value|\ 	DEF(CONN_IN_WAIT_COMPL)
comment|/* C13 */
value|\ 							\ 	DEF(CONN_REJ_WAIT_OK)
comment|/* C14 */
value|\ 	DEF(CONN_REL_IN_WAIT_OK)
comment|/* C15 */
value|\ 	DEF(CONN_REL_WAIT_OK)
comment|/* C20 */
value|\ 							\ 	DEF(CONN_AB_WAIT_REQ_OK)
comment|/* C33 */
value|\ 	DEF(CONN_AB_WAIT_RESP_OK)
comment|/* C34 */
value|\ 	DEF(CONN_AB_FLUSH_IND)
comment|/* C35 */
value|\ 	DEF(CONN_OUT_WAIT_DESTROY)
end_define

begin_comment
comment|/* C37 */
end_comment

begin_enum
enum|enum
name|conn_state
block|{
define|#
directive|define
name|DEF
parameter_list|(
name|N
parameter_list|)
value|N,
name|CONN_STATES
undef|#
directive|undef
name|DEF
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|CONN_SIGS
define|\
value|DEF(CONNECT_OUTGOING)
comment|/* U */
value|\ 	DEF(ARRIVAL)
comment|/* U */
value|\ 	DEF(RELEASE)
comment|/* U */
value|\ 	DEF(REJECT)
comment|/* U */
value|\ 	DEF(ACCEPT)
comment|/* U newuser */
value|\ 	DEF(ADD_PARTY)
comment|/* U ident */
value|\ 	DEF(DROP_PARTY)
comment|/* U ident */
value|\ 	DEF(USER_ABORT)
comment|/* U */
value|\ 									\ 	DEF(CREATED)
comment|/* P msg */
value|\ 	DEF(DESTROYED)
comment|/* P */
value|\ 	DEF(SETUP_CONFIRM)
comment|/* P msg */
value|\ 	DEF(SETUP_IND)
comment|/* P msg */
value|\ 	DEF(SETUP_COMPL)
comment|/* P msg */
value|\ 	DEF(PROC_IND)
comment|/* P msg */
value|\ 	DEF(ALERTING_IND)
comment|/* P msg */
value|\ 	DEF(REL_CONF)
comment|/* P msg */
value|\ 	DEF(REL_IND)
comment|/* P msg */
value|\ 	DEF(PARTY_CREATED)
comment|/* P msg */
value|\ 	DEF(PARTY_DESTROYED)
comment|/* P msg */
value|\ 	DEF(PARTY_ALERTING_IND)
comment|/* P msg */
value|\ 	DEF(PARTY_ADD_ACK_IND)
comment|/* P msg */
value|\ 	DEF(PARTY_ADD_REJ_IND)
comment|/* P msg */
value|\ 	DEF(DROP_PARTY_IND)
comment|/* P msg */
value|\ 	DEF(DROP_PARTY_ACK_IND)
comment|/* P msg */
value|\ 									\ 	DEF(OK)
comment|/* P msg */
value|\ 	DEF(ERROR)
end_define

begin_comment
comment|/* P msg */
end_comment

begin_enum
enum|enum
name|conn_sig
block|{
define|#
directive|define
name|DEF
parameter_list|(
name|NAME
parameter_list|)
value|CONN_SIG_##NAME,
name|CONN_SIGS
undef|#
directive|undef
name|DEF
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|cc_conn_sigtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This describes a connection and must be in sync with the UNI  * stack.  */
end_comment

begin_struct
struct|struct
name|ccconn
block|{
name|enum
name|conn_state
name|state
decl_stmt|;
comment|/* API state of the connection */
name|struct
name|ccdata
modifier|*
name|cc
decl_stmt|;
comment|/* owner node */
name|struct
name|ccport
modifier|*
name|port
decl_stmt|;
comment|/* the port we belong to */
name|struct
name|ccuser
modifier|*
name|user
decl_stmt|;
comment|/* user instance we belong to */
name|TAILQ_ENTRY
argument_list|(
argument|ccconn
argument_list|)
name|connq_link
expr_stmt|;
comment|/* queue of the owner */
name|LIST_ENTRY
argument_list|(
argument|ccconn
argument_list|)
name|port_link
expr_stmt|;
comment|/* link in list of port */
name|struct
name|uni_cref
name|cref
decl_stmt|;
name|uint8_t
name|reason
decl_stmt|;
name|struct
name|ccuser
modifier|*
name|acceptor
decl_stmt|;
comment|/* attributes */
name|uint32_t
name|blli_selector
decl_stmt|;
name|struct
name|uni_ie_blli
name|blli
index|[
name|UNI_NUM_IE_BLLI
index|]
decl_stmt|;
name|struct
name|uni_ie_bearer
name|bearer
decl_stmt|;
name|struct
name|uni_ie_traffic
name|traffic
decl_stmt|;
name|struct
name|uni_ie_qos
name|qos
decl_stmt|;
name|struct
name|uni_ie_exqos
name|exqos
decl_stmt|;
name|struct
name|uni_ie_called
name|called
decl_stmt|;
name|struct
name|uni_ie_calledsub
name|calledsub
decl_stmt|;
name|struct
name|uni_ie_aal
name|aal
decl_stmt|;
name|struct
name|uni_ie_epref
name|epref
decl_stmt|;
name|struct
name|uni_ie_conned
name|conned
decl_stmt|;
name|struct
name|uni_ie_connedsub
name|connedsub
decl_stmt|;
name|struct
name|uni_ie_eetd
name|eetd
decl_stmt|;
name|struct
name|uni_ie_abrsetup
name|abrsetup
decl_stmt|;
name|struct
name|uni_ie_abradd
name|abradd
decl_stmt|;
name|struct
name|uni_ie_mdcr
name|mdcr
decl_stmt|;
name|struct
name|uni_ie_calling
name|calling
decl_stmt|;
name|struct
name|uni_ie_callingsub
name|callingsub
decl_stmt|;
name|struct
name|uni_ie_connid
name|connid
decl_stmt|;
name|struct
name|uni_ie_tns
name|tns
index|[
name|UNI_NUM_IE_TNS
index|]
decl_stmt|;
name|struct
name|uni_ie_atraffic
name|atraffic
decl_stmt|;
name|struct
name|uni_ie_mintraffic
name|mintraffic
decl_stmt|;
name|struct
name|uni_ie_cscope
name|cscope
decl_stmt|;
name|struct
name|uni_ie_bhli
name|bhli
decl_stmt|;
comment|/* bit mask of written attributes in A6 */
name|u_int
name|dirty_attr
decl_stmt|;
name|struct
name|uni_ie_cause
name|cause
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|ccparty_list
name|parties
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* dirty attribute mask values */
end_comment

begin_enum
enum|enum
block|{
name|CCDIRTY_AAL
init|=
literal|0x0001
block|,
name|CCDIRTY_BLLI
init|=
literal|0x0002
block|,
name|CCDIRTY_CONNID
init|=
literal|0x0004
block|,
name|CCDIRTY_NOTIFY
init|=
literal|0x0008
block|,
comment|/* XXX */
name|CCDIRTY_EETD
init|=
literal|0x0010
block|,
name|CCDIRTY_GIT
init|=
literal|0x0020
block|,
comment|/* XXX */
name|CCDIRTY_UU
init|=
literal|0x0040
block|,
comment|/* XXX */
name|CCDIRTY_TRAFFIC
init|=
literal|0x0080
block|,
name|CCDIRTY_EXQOS
init|=
literal|0x0100
block|,
name|CCDIRTY_ABRSETUP
init|=
literal|0x0200
block|,
name|CCDIRTY_ABRADD
init|=
literal|0x0400
block|, }
enum|;
end_enum

begin_comment
comment|/* set conn to new state */
end_comment

begin_function_decl
name|void
name|cc_conn_set_state
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|,
name|enum
name|conn_state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return string for state */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|cc_conn_state2str
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* connect connection to user */
end_comment

begin_function_decl
name|void
name|cc_connect_to_user
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|,
name|struct
name|ccuser
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* disconnect from the user */
end_comment

begin_function_decl
name|void
name|cc_disconnect_from_user
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* abort the connection */
end_comment

begin_function_decl
name|void
name|cc_conn_abort
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* destroy a connection */
end_comment

begin_function_decl
name|void
name|cc_conn_destroy
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* create a connection */
end_comment

begin_function_decl
name|struct
name|ccconn
modifier|*
name|cc_conn_create
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* assign to port */
end_comment

begin_function_decl
name|void
name|cc_conn_ins_port
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|,
name|struct
name|ccport
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* remove from port */
end_comment

begin_function_decl
name|void
name|cc_conn_rem_port
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dispatch a connection to a user or reject it */
end_comment

begin_function_decl
name|void
name|cc_conn_dispatch
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* disconnect from acceptor */
end_comment

begin_function_decl
name|void
name|cc_conn_reset_acceptor
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* log on a connection */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CCATM_DEBUG
end_ifdef

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
name|cc_conn_log
parameter_list|(
name|C
parameter_list|,
name|FMT
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do {				\ 	(C)->cc->funcs->log("%s (conn=%p): " FMT, __FUNCTION__,		\ 	    (C) , ## ARGS);						\     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cc_conn_log
parameter_list|(
name|C
parameter_list|,
name|FMT
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	(C)->cc->funcs->log("%s (conn=%p): " FMT, __func__,		\ 	    (C), __VA_ARGS__);						\     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

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
name|cc_conn_log
parameter_list|(
name|C
parameter_list|,
name|FMT
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cc_conn_log
parameter_list|(
name|C
parameter_list|,
name|FMT
parameter_list|,
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* handle signal to connection */
end_comment

begin_function_decl
name|void
name|cc_conn_sig_handle
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|,
name|enum
name|conn_sig
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|u_int
name|iarg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Mp connection parties  */
end_comment

begin_define
define|#
directive|define
name|PARTY_STATES
define|\
value|DEF(NULL)
comment|/* 0 created */
value|\ 	DEF(ACTIVE)
comment|/* 1 active */
value|\ 	DEF(ADD_WAIT_CREATE)
comment|/* 2 wait for PARTY_CREATE */
value|\ 	DEF(ADD_WAIT_OK)
comment|/* 3 wait for OK for ADD.request */
value|\ 	DEF(ADD_WAIT_ACK)
comment|/* 4 wait for ADD.ack/rej */
value|\ 	DEF(DROP_WAIT_OK)
comment|/* 5 wait for OK for DROP.request */
value|\ 	DEF(DROP_WAIT_ACK)
comment|/* 6 wait for DROP.ack */
value|\ 	DEF(WAIT_DESTROY)
comment|/* 7 wait for destroy */
value|\ 	DEF(WAIT_SETUP_COMPL)
comment|/* 8 wait for setup.complete */
value|\ 	DEF(WAIT_DROP_ACK_OK)
comment|/* 9 wait for OK for DROP_ACK.request */
value|\ 	DEF(WAIT_SETUP_CONF)
comment|/* 10 wait for setup.confirm */
value|\ 	DEF(ADD_DROP_WAIT_OK)
comment|/* 11 wait for ok to DROP.request */
value|\ 	DEF(ADD_DROPACK_WAIT_OK)
end_define

begin_comment
comment|/* 12 wait for ok to DROP_ACK.req */
end_comment

begin_enum
enum|enum
name|party_state
block|{
define|#
directive|define
name|DEF
parameter_list|(
name|N
parameter_list|)
value|PARTY_##N,
name|PARTY_STATES
undef|#
directive|undef
name|DEF
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ccparty
block|{
name|struct
name|ccconn
modifier|*
name|conn
decl_stmt|;
comment|/* owner */
name|LIST_ENTRY
argument_list|(
argument|ccparty
argument_list|)
name|link
expr_stmt|;
name|enum
name|party_state
name|state
decl_stmt|;
name|struct
name|uni_ie_called
name|called
decl_stmt|;
name|struct
name|uni_ie_epref
name|epref
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* set party to new state */
end_comment

begin_function_decl
name|void
name|cc_party_set_state
parameter_list|(
name|struct
name|ccparty
modifier|*
parameter_list|,
name|enum
name|party_state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return string for state */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|cc_party_state2str
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* create new party */
end_comment

begin_function_decl
name|struct
name|ccparty
modifier|*
name|cc_party_create
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|,
name|u_int
name|ident
parameter_list|,
name|u_int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* log on a party */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CCATM_DEBUG
end_ifdef

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
name|cc_party_log
parameter_list|(
name|P
parameter_list|,
name|FMT
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do {				\ 	(P)->conn->cc->funcs->log("%s (conn=%p, party=%p): " FMT,	\ 	    __FUNCTION__, (P)->conn, (P) , ## ARGS);			\     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cc_party_log
parameter_list|(
name|P
parameter_list|,
name|FMT
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	(P)->conn->cc->funcs->log("%s (conn=%p, party=%p): " FMT,	\ 	__func__, (P)->conn, (P), __VA_ARGS__);				\     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

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
name|cc_party_log
parameter_list|(
name|P
parameter_list|,
name|FMT
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cc_party_log
parameter_list|(
name|P
parameter_list|,
name|FMT
parameter_list|,
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is kind of a user socket, i.e. the entity managed towards the  * upper layer.  */
end_comment

begin_define
define|#
directive|define
name|USER_STATES
define|\
value|DEF(USER_NULL)
comment|/* U0 none */
value|\ 	DEF(USER_OUT_PREPARING)
comment|/* U1 process set/query requests */
value|\ 	DEF(USER_OUT_WAIT_OK)
comment|/* U2 wait for OK to setup */
value|\ 	DEF(USER_OUT_WAIT_CONF)
comment|/* U3 wait for SETUP.confirm */
value|\ 	DEF(USER_ACTIVE)
comment|/* U4 A8-9-10/U10 */
value|\ 	DEF(USER_REL_WAIT)
comment|/* U5 wait for release to compl */
value|\ 	DEF(USER_IN_PREPARING)
comment|/* U6 set SAP */
value|\ 	DEF(USER_IN_WAITING)
comment|/* U7 wait and dispatch */
value|\ 	DEF(USER_IN_ARRIVED)
comment|/* U8 waiting for rej/acc */
value|\ 	DEF(USER_IN_WAIT_REJ)
comment|/* U9 wait for rejecting */
value|\ 	DEF(USER_IN_WAIT_ACC)
comment|/* U10 wait for accepting */
value|\ 	DEF(USER_IN_ACCEPTING)
comment|/* U11 wait for SETUP_complete */
value|\ 	DEF(USER_REL_WAIT_SCOMP)
comment|/* U12 wait for SETUP_complete */
value|\ 	DEF(USER_REL_WAIT_SCONF)
comment|/* U13 wait for SETUP.confirm */
value|\ 	DEF(USER_REL_WAIT_CONF)
comment|/* U14 wait for confirm */
value|\ 	DEF(USER_REL_WAIT_CONN)
end_define

begin_comment
comment|/* U15 wait for CONN_OK */
end_comment

begin_enum
enum|enum
name|user_state
block|{
define|#
directive|define
name|DEF
parameter_list|(
name|N
parameter_list|)
value|N,
name|USER_STATES
undef|#
directive|undef
name|DEF
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|USER_SIGS
define|\
value|DEF(PREPARE_OUTGOING)
comment|/* U */
value|\ 	DEF(CONNECT_OUTGOING)
comment|/* U msg */
value|\ 	DEF(PREPARE_INCOMING)
comment|/* U msg */
value|\ 	DEF(WAIT_ON_INCOMING)
comment|/* U msg */
value|\ 	DEF(REJECT_INCOMING)
comment|/* U msg */
value|\ 	DEF(ACCEPT_INCOMING)
comment|/* U msg */
value|\ 	DEF(CALL_RELEASE)
comment|/* U msg */
value|\ 	DEF(ADD_PARTY)
comment|/* U msg */
value|\ 	DEF(DROP_PARTY)
comment|/* U msg */
value|\ 	DEF(QUERY_ATTR)
comment|/* U msg */
value|\ 	DEF(QUERY_ATTR_X)
comment|/* U msg */
value|\ 	DEF(SET_ATTR)
comment|/* U msg */
value|\ 	DEF(SET_ATTR_X)
comment|/* U msg */
value|\ 	DEF(QUERY_STATE)
comment|/* U */
value|\ 	DEF(GET_LOCAL_PORT_INFO)
comment|/* U msg */
value|\ 	DEF(ABORT_CONNECTION)
comment|/* U msg */
value|\ 								\ 	DEF(CONNECT_OUTGOING_OK)
comment|/* */
value|\ 	DEF(CONNECT_OUTGOING_ERR)
comment|/* reason */
value|\ 	DEF(SETUP_CONFIRM)
comment|/* */
value|\ 	DEF(SETUP_IND)
comment|/* */
value|\ 	DEF(REJECT_OK)
comment|/* */
value|\ 	DEF(REJECT_ERR)
comment|/* reason */
value|\ 	DEF(ACCEPT_OK)
comment|/* */
value|\ 	DEF(ACCEPT_ERR)
comment|/* reason */
value|\ 	DEF(ACCEPTING)
comment|/* */
value|\ 	DEF(SETUP_COMPL)
comment|/* */
value|\ 	DEF(RELEASE_CONFIRM)
comment|/* */
value|\ 	DEF(RELEASE_ERR)
comment|/* reason */
value|\ 	DEF(ADD_PARTY_ERR)
comment|/* reason */
value|\ 	DEF(ADD_PARTY_OK)
comment|/* */
value|\ 	DEF(ADD_PARTY_ACK)
comment|/* leaf-ident */
value|\ 	DEF(ADD_PARTY_REJ)
comment|/* leaf-ident */
value|\ 	DEF(DROP_PARTY_ERR)
comment|/* reason */
value|\ 	DEF(DROP_PARTY_OK)
comment|/* */
value|\ 	DEF(DROP_PARTY_IND)
comment|/* leaf-ident */
value|\   enum user_sig {
end_define

begin_define
define|#
directive|define
name|DEF
parameter_list|(
name|NAME
parameter_list|)
value|USER_SIG_##NAME,
end_define

begin_expr_stmt
name|USER_SIGS
end_expr_stmt

begin_undef
undef|#
directive|undef
name|DEF
end_undef

begin_decl_stmt
unit|};
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|cc_user_sigtab
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|ccuser
block|{
name|LIST_ENTRY
argument_list|(
argument|ccuser
argument_list|)
name|node_link
expr_stmt|;
comment|/* link in list of node */
name|enum
name|user_state
name|state
decl_stmt|;
comment|/* type of this instance */
name|struct
name|ccdata
modifier|*
name|cc
decl_stmt|;
comment|/* the node */
name|void
modifier|*
name|uarg
decl_stmt|;
comment|/* the hook (if any) */
name|char
name|name
index|[
name|ATM_EPNAMSIZ
index|]
decl_stmt|;
enum|enum
block|{
name|USER_P2P
block|,
name|USER_ROOT
block|,
name|USER_LEAF
block|}
name|config
enum|;
comment|/* configuration */
name|struct
name|uni_sap
modifier|*
name|sap
decl_stmt|;
comment|/* listening SAP */
name|u_int
name|queue_max
decl_stmt|;
comment|/* maximum queue size */
name|u_int
name|queue_act
decl_stmt|;
comment|/* actual queue size */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ccconn
argument_list|)
name|connq
expr_stmt|;
comment|/* pending connections */
name|struct
name|ccconn
modifier|*
name|accepted
decl_stmt|;
name|struct
name|uni_ie_cause
name|cause
index|[
literal|2
index|]
decl_stmt|;
comment|/* cause from connection */
name|u_int
name|aborted
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* set user to new state */
end_comment

begin_function_decl
name|void
name|cc_user_set_state
parameter_list|(
name|struct
name|ccuser
modifier|*
parameter_list|,
name|enum
name|user_state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return string for state */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|cc_user_state2str
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* log on a user */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CCATM_DEBUG
end_ifdef

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
name|cc_user_log
parameter_list|(
name|U
parameter_list|,
name|FMT
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do {				\ 	(U)->cc->funcs->log("%s (user=%p): " FMT, __FUNCTION__,		\ 	    (U) , ## ARGS);						\     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cc_user_log
parameter_list|(
name|U
parameter_list|,
name|FMT
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	(U)->cc->funcs->log("%s (user=%p): " FMT, __func__,		\ 	    (U), __VA_ARGS__);						\     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

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
name|cc_user_log
parameter_list|(
name|U
parameter_list|,
name|FMT
parameter_list|,
name|ARGS
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cc_user_log
parameter_list|(
name|U
parameter_list|,
name|FMT
parameter_list|,
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Handle a signal to this user */
end_comment

begin_function_decl
name|void
name|cc_user_sig_handle
parameter_list|(
name|struct
name|ccuser
modifier|*
parameter_list|,
name|enum
name|user_sig
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Addresses  */
end_comment

begin_struct
struct|struct
name|ccaddr
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ccaddr
argument_list|)
name|port_link
expr_stmt|;
name|struct
name|uni_addr
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* signal to connection */
end_comment

begin_function_decl
name|int
name|cc_conn_sig
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|,
name|enum
name|conn_sig
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* signal with message to connection */
end_comment

begin_function_decl
name|int
name|cc_conn_sig_msg
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|,
name|enum
name|conn_sig
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cc_conn_sig_msg_nodef
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|,
name|enum
name|conn_sig
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* response signal to connection */
end_comment

begin_function_decl
name|int
name|cc_conn_resp
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|,
name|enum
name|conn_sig
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* flush all signals to a given connection */
end_comment

begin_function_decl
name|void
name|cc_conn_sig_flush
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Queue a signal to this user */
end_comment

begin_function_decl
name|int
name|cc_user_sig
parameter_list|(
name|struct
name|ccuser
modifier|*
parameter_list|,
name|enum
name|user_sig
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Queue a signal with message to this user */
end_comment

begin_function_decl
name|int
name|cc_user_sig_msg
parameter_list|(
name|struct
name|ccuser
modifier|*
parameter_list|,
name|enum
name|user_sig
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flush all signals to a given user */
end_comment

begin_function_decl
name|void
name|cc_user_sig_flush
parameter_list|(
name|struct
name|ccuser
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* flush all signals */
end_comment

begin_function_decl
name|void
name|cc_sig_flush_all
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

