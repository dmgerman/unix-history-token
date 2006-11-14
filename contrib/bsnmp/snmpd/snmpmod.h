begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: bsnmp/snmpd/snmpmod.h,v 1.32 2006/02/14 09:04:20 brandt_h Exp $  *  * SNMP daemon data and functions exported to modules.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|snmpmod_h_
end_ifndef

begin_define
define|#
directive|define
name|snmpmod_h_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|"asn1.h"
end_include

begin_include
include|#
directive|include
file|"snmp.h"
end_include

begin_include
include|#
directive|include
file|"snmpagent.h"
end_include

begin_define
define|#
directive|define
name|MAX_MOD_ARGS
value|16
end_define

begin_comment
comment|/*  * These macros help to handle object lists for SNMP tables. They use  * tail queues to hold the objects in ascending order in the list.  * ordering can be done either on an integer/unsigned field, an asn_oid  * or an ordering function.  */
end_comment

begin_define
define|#
directive|define
name|INSERT_OBJECT_OID_LINK_INDEX
parameter_list|(
name|PTR
parameter_list|,
name|LIST
parameter_list|,
name|LINK
parameter_list|,
name|INDEX
parameter_list|)
value|do {	\ 	__typeof (PTR) _lelem;						\ 									\ 	TAILQ_FOREACH(_lelem, (LIST), LINK)				\ 		if (asn_compare_oid(&_lelem->INDEX,&(PTR)->INDEX)> 0)	\ 			break;						\ 	if (_lelem == NULL)						\ 		TAILQ_INSERT_TAIL((LIST), (PTR), LINK);			\ 	else								\ 		TAILQ_INSERT_BEFORE(_lelem, (PTR), LINK);		\     } while (0)
end_define

begin_define
define|#
directive|define
name|INSERT_OBJECT_INT_LINK_INDEX
parameter_list|(
name|PTR
parameter_list|,
name|LIST
parameter_list|,
name|LINK
parameter_list|,
name|INDEX
parameter_list|)
value|do {	\ 	__typeof (PTR) _lelem;						\ 									\ 	TAILQ_FOREACH(_lelem, (LIST), LINK)				\ 		if ((asn_subid_t)_lelem->INDEX> (asn_subid_t)(PTR)->INDEX)\ 			break;						\ 	if (_lelem == NULL)						\ 		TAILQ_INSERT_TAIL((LIST), (PTR), LINK);			\ 	else								\ 		TAILQ_INSERT_BEFORE(_lelem, (PTR), LINK);		\     } while (0)
end_define

begin_define
define|#
directive|define
name|INSERT_OBJECT_FUNC_LINK
parameter_list|(
name|PTR
parameter_list|,
name|LIST
parameter_list|,
name|LINK
parameter_list|,
name|FUNC
parameter_list|)
value|do {		\ 	__typeof (PTR) _lelem;						\ 									\ 	TAILQ_FOREACH(_lelem, (LIST), LINK)				\ 		if ((FUNC)(_lelem, (PTR))> 0)				\ 			break;						\ 	if (_lelem == NULL)						\ 		TAILQ_INSERT_TAIL((LIST), (PTR), LINK);			\ 	else								\ 		TAILQ_INSERT_BEFORE(_lelem, (PTR), LINK);		\     } while (0)
end_define

begin_define
define|#
directive|define
name|INSERT_OBJECT_FUNC_LINK_REV
parameter_list|(
name|PTR
parameter_list|,
name|LIST
parameter_list|,
name|HEAD
parameter_list|,
name|LINK
parameter_list|,
name|FUNC
parameter_list|)
value|do {	\ 	__typeof (PTR) _lelem;						\ 									\ 	TAILQ_FOREACH_REVERSE(_lelem, (LIST), HEAD, LINK)		\ 		if ((FUNC)(_lelem, (PTR))< 0)				\ 			break;						\ 	if (_lelem == NULL)						\ 		TAILQ_INSERT_HEAD((LIST), (PTR), LINK);			\ 	else								\ 		TAILQ_INSERT_AFTER((LIST), _lelem, (PTR), LINK);	\     } while (0)
end_define

begin_define
define|#
directive|define
name|FIND_OBJECT_OID_LINK_INDEX
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|LINK
parameter_list|,
name|INDEX
parameter_list|)
value|({	\ 	__typeof (TAILQ_FIRST(LIST)) _lelem;				\ 									\ 	TAILQ_FOREACH(_lelem, (LIST), LINK)				\ 		if (index_compare(OID, SUB,&_lelem->INDEX) == 0)	\ 			break;						\ 	(_lelem);							\     })
end_define

begin_define
define|#
directive|define
name|NEXT_OBJECT_OID_LINK_INDEX
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|LINK
parameter_list|,
name|INDEX
parameter_list|)
value|({	\ 	__typeof (TAILQ_FIRST(LIST)) _lelem;				\ 									\ 	TAILQ_FOREACH(_lelem, (LIST), LINK)				\ 		if (index_compare(OID, SUB,&_lelem->INDEX)< 0)	\ 			break;						\ 	(_lelem);							\     })
end_define

begin_define
define|#
directive|define
name|FIND_OBJECT_INT_LINK_INDEX
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|LINK
parameter_list|,
name|INDEX
parameter_list|)
value|({	\ 	__typeof (TAILQ_FIRST(LIST)) _lelem;				\ 									\ 	if ((OID)->len - SUB != 1)					\ 		_lelem = NULL;						\ 	else								\ 		TAILQ_FOREACH(_lelem, (LIST), LINK)			\ 			if ((OID)->subs[SUB] == (asn_subid_t)_lelem->INDEX)\ 				break;					\ 	(_lelem);							\     })
end_define

begin_define
define|#
directive|define
name|NEXT_OBJECT_INT_LINK_INDEX
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|LINK
parameter_list|,
name|INDEX
parameter_list|)
value|({	\ 	__typeof (TAILQ_FIRST(LIST)) _lelem;				\ 									\ 	if ((OID)->len - SUB == 0)					\ 		_lelem = TAILQ_FIRST(LIST);				\ 	else								\ 		TAILQ_FOREACH(_lelem, (LIST), LINK)			\ 			if ((OID)->subs[SUB]< (asn_subid_t)_lelem->INDEX)\ 				break;					\ 	(_lelem);							\     })
end_define

begin_define
define|#
directive|define
name|FIND_OBJECT_FUNC_LINK
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|LINK
parameter_list|,
name|FUNC
parameter_list|)
value|({		\ 	__typeof (TAILQ_FIRST(LIST)) _lelem;				\ 									\ 	TAILQ_FOREACH(_lelem, (LIST), LINK)				\ 		if ((FUNC)(OID, SUB, _lelem) == 0)			\ 			break;						\ 	(_lelem);							\     })
end_define

begin_define
define|#
directive|define
name|NEXT_OBJECT_FUNC_LINK
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|LINK
parameter_list|,
name|FUNC
parameter_list|)
value|({		\ 	__typeof (TAILQ_FIRST(LIST)) _lelem;				\ 									\ 	TAILQ_FOREACH(_lelem, (LIST), LINK)				\ 		if ((FUNC)(OID, SUB, _lelem)< 0)			\ 			break;						\ 	(_lelem);							\     })
end_define

begin_comment
comment|/*  * Macros for the case where the index field is called 'index'  */
end_comment

begin_define
define|#
directive|define
name|INSERT_OBJECT_OID_LINK
parameter_list|(
name|PTR
parameter_list|,
name|LIST
parameter_list|,
name|LINK
parameter_list|)
define|\
value|INSERT_OBJECT_OID_LINK_INDEX(PTR, LIST, LINK, index)
end_define

begin_define
define|#
directive|define
name|INSERT_OBJECT_INT_LINK
parameter_list|(
name|PTR
parameter_list|,
name|LIST
parameter_list|,
name|LINK
parameter_list|)
value|do {			\     INSERT_OBJECT_INT_LINK_INDEX(PTR, LIST, LINK, index)
end_define

begin_define
define|#
directive|define
name|FIND_OBJECT_OID_LINK
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|LINK
parameter_list|)
define|\
value|FIND_OBJECT_OID_LINK_INDEX(LIST, OID, SUB, LINK, index)
end_define

begin_define
define|#
directive|define
name|NEXT_OBJECT_OID_LINK
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|LINK
parameter_list|)
define|\
value|NEXT_OBJECT_OID_LINK_INDEX(LIST, OID, SUB, LINK, index)
end_define

begin_define
define|#
directive|define
name|FIND_OBJECT_INT_LINK
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|LINK
parameter_list|)
define|\
value|FIND_OBJECT_INT_LINK_INDEX(LIST, OID, SUB, LINK, index)
end_define

begin_define
define|#
directive|define
name|NEXT_OBJECT_INT_LINK
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|LINK
parameter_list|)
define|\
value|NEXT_OBJECT_INT_LINK_INDEX(LIST, OID, SUB, LINK, index)
end_define

begin_comment
comment|/*  * Macros for the case where the index field is called 'index' and the  * link field 'link'.  */
end_comment

begin_define
define|#
directive|define
name|INSERT_OBJECT_OID
parameter_list|(
name|PTR
parameter_list|,
name|LIST
parameter_list|)
define|\
value|INSERT_OBJECT_OID_LINK_INDEX(PTR, LIST, link, index)
end_define

begin_define
define|#
directive|define
name|INSERT_OBJECT_INT
parameter_list|(
name|PTR
parameter_list|,
name|LIST
parameter_list|)
define|\
value|INSERT_OBJECT_INT_LINK_INDEX(PTR, LIST, link, index)
end_define

begin_define
define|#
directive|define
name|INSERT_OBJECT_FUNC_REV
parameter_list|(
name|PTR
parameter_list|,
name|LIST
parameter_list|,
name|HEAD
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|INSERT_OBJECT_FUNC_LINK_REV(PTR, LIST, HEAD, link, FUNC)
end_define

begin_define
define|#
directive|define
name|FIND_OBJECT_OID
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|)
define|\
value|FIND_OBJECT_OID_LINK_INDEX(LIST, OID, SUB, link, index)
end_define

begin_define
define|#
directive|define
name|FIND_OBJECT_INT
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|)
define|\
value|FIND_OBJECT_INT_LINK_INDEX(LIST, OID, SUB, link, index)
end_define

begin_define
define|#
directive|define
name|FIND_OBJECT_FUNC
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|FIND_OBJECT_FUNC_LINK(LIST, OID, SUB, link, FUNC)
end_define

begin_define
define|#
directive|define
name|NEXT_OBJECT_OID
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|)
define|\
value|NEXT_OBJECT_OID_LINK_INDEX(LIST, OID, SUB, link, index)
end_define

begin_define
define|#
directive|define
name|NEXT_OBJECT_INT
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|)
define|\
value|NEXT_OBJECT_INT_LINK_INDEX(LIST, OID, SUB, link, index)
end_define

begin_define
define|#
directive|define
name|NEXT_OBJECT_FUNC
parameter_list|(
name|LIST
parameter_list|,
name|OID
parameter_list|,
name|SUB
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|NEXT_OBJECT_FUNC_LINK(LIST, OID, SUB, link, FUNC)
end_define

begin_struct_decl
struct_decl|struct
name|lmodule
struct_decl|;
end_struct_decl

begin_comment
comment|/* The tick when the program was started. This is the absolute time of  * the start in 100th of a second. */
end_comment

begin_decl_stmt
specifier|extern
name|uint64_t
name|start_tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The tick when the current packet was received. This is the absolute  * time in 100th of second. */
end_comment

begin_decl_stmt
specifier|extern
name|uint64_t
name|this_tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the current absolute time in 100th of a second. */
end_comment

begin_function_decl
name|uint64_t
name|get_ticks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return code for proxy function  */
end_comment

begin_enum
enum|enum
name|snmpd_proxy_err
block|{
comment|/* proxy code will process the PDU */
name|SNMPD_PROXY_OK
block|,
comment|/* proxy code does not process PDU */
name|SNMPD_PROXY_REJ
block|,
comment|/* drop this PDU */
name|SNMPD_PROXY_DROP
block|,
comment|/* drop because of bad community */
name|SNMPD_PROXY_BADCOMM
block|,
comment|/* drop because of bad community use */
name|SNMPD_PROXY_BADCOMMUSE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Input handling  */
end_comment

begin_enum
enum|enum
name|snmpd_input_err
block|{
comment|/* proceed with packet */
name|SNMPD_INPUT_OK
block|,
comment|/* fatal error in packet, ignore it */
name|SNMPD_INPUT_FAILED
block|,
comment|/* value encoding has wrong length in a SET operation */
name|SNMPD_INPUT_VALBADLEN
block|,
comment|/* value encoding is out of range */
name|SNMPD_INPUT_VALRANGE
block|,
comment|/* value has bad encoding */
name|SNMPD_INPUT_VALBADENC
block|,
comment|/* need more data (truncated packet) */
name|SNMPD_INPUT_TRUNC
block|,
comment|/* unknown community */
name|SNMPD_INPUT_BAD_COMM
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Every loadable module must have one of this structures with  * the external name 'config'.  */
end_comment

begin_struct
struct|struct
name|snmp_module
block|{
comment|/* a comment describing what this module implements */
specifier|const
name|char
modifier|*
name|comment
decl_stmt|;
comment|/* the initialization function */
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|lmodule
modifier|*
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
comment|/* the finalisation function */
name|int
function_decl|(
modifier|*
name|fini
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* the idle function */
name|void
function_decl|(
modifier|*
name|idle
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* the dump function */
name|void
function_decl|(
modifier|*
name|dump
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* re-configuration function */
name|void
function_decl|(
modifier|*
name|config
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* start operation */
name|void
function_decl|(
modifier|*
name|start
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* proxy a PDU */
name|enum
name|snmpd_proxy_err
function_decl|(
modifier|*
name|proxy
function_decl|)
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
parameter_list|,
name|enum
name|snmpd_input_err
parameter_list|,
name|int32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* the tree this module is going to server */
specifier|const
name|struct
name|snmp_node
modifier|*
name|tree
decl_stmt|;
name|u_int
name|tree_size
decl_stmt|;
comment|/* function called, when another module was unloaded/loaded */
name|void
function_decl|(
modifier|*
name|loading
function_decl|)
parameter_list|(
specifier|const
name|struct
name|lmodule
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Stuff exported to modules  */
end_comment

begin_comment
comment|/*  * The system group.  */
end_comment

begin_struct
struct|struct
name|systemg
block|{
name|u_char
modifier|*
name|descr
decl_stmt|;
name|struct
name|asn_oid
name|object_id
decl_stmt|;
name|u_char
modifier|*
name|contact
decl_stmt|;
name|u_char
modifier|*
name|name
decl_stmt|;
name|u_char
modifier|*
name|location
decl_stmt|;
name|u_int32_t
name|services
decl_stmt|;
name|u_int32_t
name|or_last_change
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|systemg
name|systemg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Community support.  *  * We have 2 fixed communities for SNMP read and write access. Modules  * can create their communities dynamically. They are deleted automatically  * if the module is unloaded.  */
end_comment

begin_define
define|#
directive|define
name|COMM_INITIALIZE
value|0
end_define

begin_define
define|#
directive|define
name|COMM_READ
value|1
end_define

begin_define
define|#
directive|define
name|COMM_WRITE
value|2
end_define

begin_function_decl
name|u_int
name|comm_define
parameter_list|(
name|u_int
parameter_list|,
specifier|const
name|char
modifier|*
name|descr
parameter_list|,
name|struct
name|lmodule
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|comm_string
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* community for current packet */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|community
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Well known OIDs  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|asn_oid
name|oid_zeroDotZero
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Request ID ranges.  *  * A module can request a range of request ids and associate them with a  * type field. All ranges are deleted if a module is unloaded.  */
end_comment

begin_function_decl
name|u_int
name|reqid_allocate
parameter_list|(
name|int
name|size
parameter_list|,
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|reqid_next
parameter_list|(
name|u_int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|reqid_base
parameter_list|(
name|u_int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reqid_istype
parameter_list|(
name|int32_t
name|reqid
parameter_list|,
name|u_int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|reqid_type
parameter_list|(
name|int32_t
name|reqid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Timers.  */
end_comment

begin_function_decl
name|void
modifier|*
name|timer_start
parameter_list|(
name|u_int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|timer_start_repeat
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|timer_stop
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * File descriptors  */
end_comment

begin_function_decl
name|void
modifier|*
name|fd_select
parameter_list|(
name|int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fd_deselect
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fd_suspend
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fd_resume
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Object resources  */
end_comment

begin_function_decl
name|u_int
name|or_register
parameter_list|(
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|or_unregister
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Buffers  */
end_comment

begin_function_decl
name|void
modifier|*
name|buf_alloc
parameter_list|(
name|int
name|tx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|buf_size
parameter_list|(
name|int
name|tx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* decode PDU and find community */
end_comment

begin_function_decl
name|enum
name|snmpd_input_err
name|snmp_input_start
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|int32_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* process the pdu. returns either _OK or _FAILED */
end_comment

begin_function_decl
name|enum
name|snmpd_input_err
name|snmp_input_finish
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|snmpd_input_err
parameter_list|,
name|int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_output
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_send_port
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sending traps */
end_comment

begin_function_decl
name|void
name|snmp_send_trap
parameter_list|(
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Action support  */
end_comment

begin_function_decl
name|int
name|string_save
parameter_list|(
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|ssize_t
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|string_commit
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|string_rollback
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|string_get
parameter_list|(
name|struct
name|snmp_value
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|ssize_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|string_get_max
parameter_list|(
name|struct
name|snmp_value
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|ssize_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|string_free
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ip_save
parameter_list|(
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_rollback
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_commit
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ip_get
parameter_list|(
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oid_save
parameter_list|(
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oid_rollback
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oid_commit
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oid_get
parameter_list|(
name|struct
name|snmp_value
modifier|*
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|index_decode
parameter_list|(
specifier|const
name|struct
name|asn_oid
modifier|*
name|oid
parameter_list|,
name|u_int
name|sub
parameter_list|,
name|u_int
name|code
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|index_compare
parameter_list|(
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|index_compare_off
parameter_list|(
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|index_append
parameter_list|(
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|index_append_off
parameter_list|(
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

