begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  This file contains the flask_op hypercall commands and definitions.  *  *  Author:  George Coker,<gscoker@alpha.ncsc.mil>  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FLASK_OP_H__
end_ifndef

begin_define
define|#
directive|define
name|__FLASK_OP_H__
end_define

begin_define
define|#
directive|define
name|XEN_FLASK_INTERFACE_VERSION
value|1
end_define

begin_struct
struct|struct
name|xen_flask_load
block|{
name|XEN_GUEST_HANDLE
argument_list|(
argument|char
argument_list|)
name|buffer
expr_stmt|;
name|uint32_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_setenforce
block|{
name|uint32_t
name|enforcing
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_sid_context
block|{
comment|/* IN/OUT: sid to convert to/from string */
name|uint32_t
name|sid
decl_stmt|;
comment|/* IN: size of the context buffer      * OUT: actual size of the output context string      */
name|uint32_t
name|size
decl_stmt|;
name|XEN_GUEST_HANDLE
argument_list|(
argument|char
argument_list|)
name|context
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_access
block|{
comment|/* IN: access request */
name|uint32_t
name|ssid
decl_stmt|;
name|uint32_t
name|tsid
decl_stmt|;
name|uint32_t
name|tclass
decl_stmt|;
name|uint32_t
name|req
decl_stmt|;
comment|/* OUT: AVC data */
name|uint32_t
name|allowed
decl_stmt|;
name|uint32_t
name|audit_allow
decl_stmt|;
name|uint32_t
name|audit_deny
decl_stmt|;
name|uint32_t
name|seqno
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_transition
block|{
comment|/* IN: transition SIDs and class */
name|uint32_t
name|ssid
decl_stmt|;
name|uint32_t
name|tsid
decl_stmt|;
name|uint32_t
name|tclass
decl_stmt|;
comment|/* OUT: new SID */
name|uint32_t
name|newsid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_userlist
block|{
comment|/* IN: starting SID for list */
name|uint32_t
name|start_sid
decl_stmt|;
comment|/* IN: size of user string and output buffer      * OUT: number of SIDs returned */
name|uint32_t
name|size
decl_stmt|;
union|union
block|{
comment|/* IN: user to enumerate SIDs */
name|XEN_GUEST_HANDLE
argument_list|(
argument|char
argument_list|)
name|user
expr_stmt|;
comment|/* OUT: SID list */
name|XEN_GUEST_HANDLE
argument_list|(
argument|uint32
argument_list|)
name|sids
expr_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_boolean
block|{
comment|/* IN/OUT: numeric identifier for boolean [GET/SET]      * If -1, name will be used and bool_id will be filled in. */
name|uint32_t
name|bool_id
decl_stmt|;
comment|/* OUT: current enforcing value of boolean [GET/SET] */
name|uint8_t
name|enforcing
decl_stmt|;
comment|/* OUT: pending value of boolean [GET/SET] */
name|uint8_t
name|pending
decl_stmt|;
comment|/* IN: new value of boolean [SET] */
name|uint8_t
name|new_value
decl_stmt|;
comment|/* IN: commit new value instead of only setting pending [SET] */
name|uint8_t
name|commit
decl_stmt|;
comment|/* IN: size of boolean name buffer [GET/SET]      * OUT: actual size of name [GET only] */
name|uint32_t
name|size
decl_stmt|;
comment|/* IN: if bool_id is -1, used to find boolean [GET/SET]      * OUT: textual name of boolean [GET only]      */
name|XEN_GUEST_HANDLE
argument_list|(
argument|char
argument_list|)
name|name
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_setavc_threshold
block|{
comment|/* IN */
name|uint32_t
name|threshold
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_hash_stats
block|{
comment|/* OUT */
name|uint32_t
name|entries
decl_stmt|;
name|uint32_t
name|buckets_used
decl_stmt|;
name|uint32_t
name|buckets_total
decl_stmt|;
name|uint32_t
name|max_chain_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_cache_stats
block|{
comment|/* IN */
name|uint32_t
name|cpu
decl_stmt|;
comment|/* OUT */
name|uint32_t
name|lookups
decl_stmt|;
name|uint32_t
name|hits
decl_stmt|;
name|uint32_t
name|misses
decl_stmt|;
name|uint32_t
name|allocations
decl_stmt|;
name|uint32_t
name|reclaims
decl_stmt|;
name|uint32_t
name|frees
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_ocontext
block|{
comment|/* IN */
name|uint32_t
name|ocon
decl_stmt|;
name|uint32_t
name|sid
decl_stmt|;
name|uint64_t
name|low
decl_stmt|,
name|high
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_peersid
block|{
comment|/* IN */
name|evtchn_port_t
name|evtchn
decl_stmt|;
comment|/* OUT */
name|uint32_t
name|sid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_flask_op
block|{
name|uint32_t
name|cmd
decl_stmt|;
define|#
directive|define
name|FLASK_LOAD
value|1
define|#
directive|define
name|FLASK_GETENFORCE
value|2
define|#
directive|define
name|FLASK_SETENFORCE
value|3
define|#
directive|define
name|FLASK_CONTEXT_TO_SID
value|4
define|#
directive|define
name|FLASK_SID_TO_CONTEXT
value|5
define|#
directive|define
name|FLASK_ACCESS
value|6
define|#
directive|define
name|FLASK_CREATE
value|7
define|#
directive|define
name|FLASK_RELABEL
value|8
define|#
directive|define
name|FLASK_USER
value|9
define|#
directive|define
name|FLASK_POLICYVERS
value|10
define|#
directive|define
name|FLASK_GETBOOL
value|11
define|#
directive|define
name|FLASK_SETBOOL
value|12
define|#
directive|define
name|FLASK_COMMITBOOLS
value|13
define|#
directive|define
name|FLASK_MLS
value|14
define|#
directive|define
name|FLASK_DISABLE
value|15
define|#
directive|define
name|FLASK_GETAVC_THRESHOLD
value|16
define|#
directive|define
name|FLASK_SETAVC_THRESHOLD
value|17
define|#
directive|define
name|FLASK_AVC_HASHSTATS
value|18
define|#
directive|define
name|FLASK_AVC_CACHESTATS
value|19
define|#
directive|define
name|FLASK_MEMBER
value|20
define|#
directive|define
name|FLASK_ADD_OCONTEXT
value|21
define|#
directive|define
name|FLASK_DEL_OCONTEXT
value|22
define|#
directive|define
name|FLASK_GET_PEER_SID
value|23
name|uint32_t
name|interface_version
decl_stmt|;
comment|/* XEN_FLASK_INTERFACE_VERSION */
union|union
block|{
name|struct
name|xen_flask_load
name|load
decl_stmt|;
name|struct
name|xen_flask_setenforce
name|enforce
decl_stmt|;
comment|/* FLASK_CONTEXT_TO_SID and FLASK_SID_TO_CONTEXT */
name|struct
name|xen_flask_sid_context
name|sid_context
decl_stmt|;
name|struct
name|xen_flask_access
name|access
decl_stmt|;
comment|/* FLASK_CREATE, FLASK_RELABEL, FLASK_MEMBER */
name|struct
name|xen_flask_transition
name|transition
decl_stmt|;
name|struct
name|xen_flask_userlist
name|userlist
decl_stmt|;
comment|/* FLASK_GETBOOL, FLASK_SETBOOL */
name|struct
name|xen_flask_boolean
name|boolean
decl_stmt|;
name|struct
name|xen_flask_setavc_threshold
name|setavc_threshold
decl_stmt|;
name|struct
name|xen_flask_hash_stats
name|hash_stats
decl_stmt|;
name|struct
name|xen_flask_cache_stats
name|cache_stats
decl_stmt|;
comment|/* FLASK_ADD_OCONTEXT, FLASK_DEL_OCONTEXT */
name|struct
name|xen_flask_ocontext
name|ocontext
decl_stmt|;
name|struct
name|xen_flask_peersid
name|peersid
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_flask_op
name|xen_flask_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_flask_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

