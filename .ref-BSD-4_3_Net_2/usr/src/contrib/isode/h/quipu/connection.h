begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* connection.h - directory internal structures */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/connection.h,v 7.3 91/02/22 09:25:34 mrose Interim $  *  *  * $Log:	connection.h,v $  * Revision 7.3  91/02/22  09:25:34  mrose  * Interim 6.8  *   * Revision 7.2  90/10/17  11:46:19  mrose  * sync  *   * Revision 7.1  90/07/09  14:38:23  mrose  * sync  *   * Revision 7.0  89/11/23  21:56:28  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUCON
end_ifndef

begin_define
define|#
directive|define
name|QUIPUCON
end_define

begin_include
include|#
directive|include
file|"quipu/common.h"
end_include

begin_include
include|#
directive|include
file|"quipu/dsargument.h"
end_include

begin_include
include|#
directive|include
file|"quipu/dsap.h"
end_include

begin_define
define|#
directive|define
name|DSA_PRIO_LOW
value|1
end_define

begin_define
define|#
directive|define
name|DSA_PRIO_MED
value|2
end_define

begin_define
define|#
directive|define
name|DSA_PRIO_HIGH
value|3
end_define

begin_define
define|#
directive|define
name|DSA_MAX_PRIO
value|3
end_define

begin_decl_stmt
specifier|extern
name|int
name|max_conns
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_CONNS
value|max_conns
end_define

begin_comment
comment|/* Maximum concurrent connections */
end_comment

begin_define
define|#
directive|define
name|CONNS_RESERVED_DI
value|2
end_define

begin_comment
comment|/* Reserved for Get DSA Info ops */
end_comment

begin_define
define|#
directive|define
name|CONNS_RESERVED_X500
value|10
end_define

begin_comment
comment|/* Reserved for normal operations */
end_comment

begin_comment
comment|/* *  If the connection definitions are altered bear in mind that  *  MAX_CONNS - CONNS_RESERVED_FOR_DI - CONNS_RESERVED_FOR_X500 *  must be at least 1 to allow get edb ops to happen, and should *  probably be at least 2 to allow one get edb operation to block. */
end_comment

begin_comment
comment|/* *  The following structures form the basis of the connection mesh *  which is central to the scheduling of the DSA. */
end_comment

begin_comment
comment|/* *  The di_block structure is used to generate lists of dsa information *  blocks even when the information is not yet available. *  There are 3 states which a di_block can be in: *	DI_ACCESSPOINT:	di_block contains access point only. *	DI_COMPLETE:	di_block contains entry for dsa. *	DI_DEFERRED:	di_block is waiting for a dsa entry. * *  The links in this structure need to be handled with care!! *  di_next is used to link the "di_block"s on *	1) the global list if that is where this block is kept *	2) the requesting operation if that is where this block is kept *	3) the requesting task if that is where this block is kept * *  di_wake_next is used to link the "di_block"s for the performing *  operation, so that it is obvious what needs to be alerted. * *  di_task points to the task to be alerted from type DI_TASK *  di_oper points to the operation to be alerted from type DI_OPERATION *  di_perform points to the operation performing the get dsa info operation */
end_comment

begin_struct
struct|struct
name|di_block
block|{
name|DN
name|di_dn
decl_stmt|;
comment|/* Name of dsa this block refers to */
name|char
name|di_type
decl_stmt|;
comment|/* Global list, operation list or task list */
define|#
directive|define
name|DI_GLOBAL
value|1
comment|/* deferred_dis lists this block */
define|#
directive|define
name|DI_OPERATION
value|2
comment|/* di_oper lists this block */
define|#
directive|define
name|DI_TASK
value|3
comment|/* di_task lists this block */
name|struct
name|task_act
modifier|*
name|di_task
decl_stmt|;
name|struct
name|oper_act
modifier|*
name|di_oper
decl_stmt|;
comment|/* *  The following are needed to generate chaining arguments from DSAInformation *  in the case of chaining (DI_OPERATION); and to generate continuation *  references in the case of referring (DI_TASK). Not present for DI_GLOBAL */
name|DN
name|di_target
decl_stmt|;
name|int
name|di_reftype
decl_stmt|;
name|int
name|di_rdn_resolved
decl_stmt|;
name|int
name|di_aliasedRDNs
decl_stmt|;
name|char
name|di_state
decl_stmt|;
comment|/* How the dsa information is formed */
define|#
directive|define
name|DI_COMPLETE
value|1
comment|/* di_entry filled out */
define|#
directive|define
name|DI_ACCESSPOINT
value|2
comment|/* di_accesspoints filled out */
define|#
directive|define
name|DI_DEFERRED
value|3
comment|/* di_perform still generating di_entry */
name|struct
name|access_point
modifier|*
name|di_accesspoints
decl_stmt|;
name|Entry
name|di_entry
decl_stmt|;
name|struct
name|oper_act
modifier|*
name|di_perform
decl_stmt|;
name|struct
name|di_block
modifier|*
name|di_wake_next
decl_stmt|;
comment|/* List of blocks to wake */
name|struct
name|di_block
modifier|*
name|di_next
decl_stmt|;
comment|/* List of blocks */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULL_DI_BLOCK
value|((struct di_block *) NULL)
end_define

begin_comment
comment|/* * Operations received over a bound association are represented as a * linked list of task blocks. The following task block structure  * contains the invocation (including decoded argument) received, * representations of the progress of the task and fields to be * used for generating the response. */
end_comment

begin_struct
struct|struct
name|task_act
block|{
name|int
name|tk_prio
decl_stmt|;
name|char
name|tk_state
decl_stmt|;
define|#
directive|define
name|TK_ACTIVE
value|1
comment|/* Task ready to have work done */
define|#
directive|define
name|TK_PASSIVE
value|2
comment|/* Task waiting for operation */
define|#
directive|define
name|TK_SUSPEND
value|3
comment|/* Giving the network a chance */
name|struct
name|DSAPinvoke
name|tk_dx
decl_stmt|;
name|struct
name|di_block
modifier|*
name|tk_dsas
decl_stmt|;
comment|/* di_blocks for referral */
name|struct
name|DSAPindication
name|tk_resp
decl_stmt|;
name|struct
name|ds_op_res
modifier|*
name|tk_result
decl_stmt|;
name|struct
name|DSError
modifier|*
name|tk_error
decl_stmt|;
comment|/* Specific additions to provide multi-subtask search implementation */
name|struct
name|ds_search_task
modifier|*
name|local_st
decl_stmt|;
name|struct
name|ds_search_task
modifier|*
name|refer_st
decl_stmt|;
name|struct
name|ds_search_task
modifier|*
name|referred_st
decl_stmt|;
name|char
name|tk_timed
decl_stmt|;
name|time_t
name|tk_timeout
decl_stmt|;
name|struct
name|oper_act
modifier|*
name|tk_operlist
decl_stmt|;
name|struct
name|task_act
modifier|*
name|tk_next
decl_stmt|;
name|struct
name|connection
modifier|*
name|tk_conn
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLTASK
value|((struct task_act *) NULL)
end_define

begin_struct
struct|struct
name|oper_act
block|{
name|int
name|on_id
decl_stmt|;
name|char
name|on_state
decl_stmt|;
define|#
directive|define
name|ON_DEFERRED
value|1
comment|/* Waiting for DSA INFO */
define|#
directive|define
name|ON_CHAINED
value|2
comment|/* Waiting for a response */
define|#
directive|define
name|ON_COMPLETE
value|3
comment|/* Waiting to be used by task */
define|#
directive|define
name|ON_ABANDONED
value|4
comment|/* Waiting for response - no task */
name|char
name|on_type
decl_stmt|;
define|#
directive|define
name|ON_TYPE_X500
value|1
define|#
directive|define
name|ON_TYPE_BIND_COMPARE
value|2
define|#
directive|define
name|ON_TYPE_GET_DSA_INFO
value|3
define|#
directive|define
name|ON_TYPE_GET_EDB
value|4
define|#
directive|define
name|ON_TYPE_SUBTASK
value|5
define|#
directive|define
name|ON_TYPE_SHADOW
value|6
comment|/* Specific to ON_TYPE_X500 */
name|struct
name|task_act
modifier|*
name|on_task
decl_stmt|;
comment|/* Task to wake */
comment|/* Specific to ON_TYPE_BIND_COMPARE */
name|struct
name|connection
modifier|*
name|on_bind_compare
decl_stmt|;
comment|/* Bind to wake */
comment|/* Specific to ON_TYPE_GET_DSA_INFO */
name|struct
name|di_block
modifier|*
name|on_wake_list
decl_stmt|;
comment|/* di_blocks to wake */
comment|/* Specific to ON_TYPE_GET_EDB */
name|Entry
name|on_getedb_eptr
decl_stmt|;
comment|/* previous entry */
name|char
modifier|*
name|on_getedb_ver
decl_stmt|;
comment|/* previous version */
comment|/* Specific to ON_TYPE_SUBTASK */
name|struct
name|ds_search_task
modifier|*
name|on_subtask
decl_stmt|;
name|struct
name|di_block
modifier|*
name|on_dsas
decl_stmt|;
comment|/* DSAInfos for chaining */
name|struct
name|ds_op_arg
name|on_req
decl_stmt|;
comment|/* Argument stuff */
name|struct
name|ds_op_arg
modifier|*
name|on_arg
decl_stmt|;
name|struct
name|DSAPindication
name|on_resp
decl_stmt|;
comment|/* Response stuff */
name|char
name|on_relay
decl_stmt|;
comment|/* if TRUE try Relay DSA */
name|struct
name|oper_act
modifier|*
name|on_next_conn
decl_stmt|;
name|struct
name|oper_act
modifier|*
name|on_next_task
decl_stmt|;
name|struct
name|connection
modifier|*
name|on_conn
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLOPER
value|((struct oper_act *) NULL)
end_define

begin_struct
struct|struct
name|conn_start
block|{
comment|/* Values stored after call to TNetAccept */
name|int
name|cs_vecp
decl_stmt|;
name|char
modifier|*
name|cs_vec
index|[
literal|4
index|]
decl_stmt|;
name|char
modifier|*
name|cs_svec
index|[
literal|4
index|]
decl_stmt|;
comment|/* Value extracted from above by conn_init() */
name|struct
name|DSAPstart
name|cs_ds
decl_stmt|;
comment|/* Operation carrying out compare for binding */
name|struct
name|oper_act
modifier|*
name|cs_bind_compare
decl_stmt|;
comment|/* Result or error generated for response */
name|struct
name|ds_bind_arg
name|cs_res
decl_stmt|;
name|struct
name|ds_bind_error
name|cs_err
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|conn_connect
block|{
comment|/* Bind argument used in conn_request() */
name|struct
name|ds_bind_arg
name|cc_req
decl_stmt|;
name|struct
name|DSAPconnect
name|cc_dc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* * Conn is the structure used to represent external connections */
end_comment

begin_struct
struct|struct
name|connection
block|{
name|char
name|cn_state
decl_stmt|;
comment|/* State of the connection */
define|#
directive|define
name|CN_INDICATED
value|1
define|#
directive|define
name|CN_WAITING
value|2
define|#
directive|define
name|CN_CONNECTING1
value|3
define|#
directive|define
name|CN_CONNECTING2
value|4
define|#
directive|define
name|CN_OPEN
value|5
define|#
directive|define
name|CN_FAILED
value|6
define|#
directive|define
name|CN_CLOSING
value|7
define|#
directive|define
name|CN_OPENING
value|8
name|char
name|cn_ctx
decl_stmt|;
comment|/* DS_CTX_* values defined in dsap.h for use by decoders */
name|char
name|cn_initiator
decl_stmt|;
comment|/* TRUE: this DSA is initiator, FALSE: this DSA is responder */
comment|/* Information used during initialisation of the connection */
union|union
block|{
name|struct
name|conn_start
name|cn_start_un_start
decl_stmt|;
comment|/* responder */
name|struct
name|conn_connect
name|cn_start_un_connect
decl_stmt|;
comment|/* initiator */
block|}
name|cn_start_un
union|;
define|#
directive|define
name|cn_start
value|cn_start_un.cn_start_un_start
define|#
directive|define
name|cn_connect
value|cn_start_un.cn_start_un_connect
comment|/* 	struct ds_bind_arg	* cn_res; 	struct ds_bind_error		* cn_err;  	struct init_activity	  cn_init_act; 	struct oper_act 	* cn_bind_compare; */
name|time_t
name|cn_last_used
decl_stmt|;
comment|/* Time at which this connection was last used */
name|time_t
name|cn_last_release
decl_stmt|;
comment|/* Time at which this connection release was last attempted */
name|DN
name|cn_dn
decl_stmt|;
comment|/* Name of the entity at the far end of the connection */
name|struct
name|PSAPaddr
name|cn_addr
decl_stmt|;
comment|/* Address of the entity at the far end of the connection */
name|int
name|cn_ad
decl_stmt|;
comment|/* Descriptor identifying the association on which the connection is based */
comment|/* 	int			  cn_context_id; */
comment|/* Context identifier of context to be used for user-data. */
name|int
name|cn_op_id
decl_stmt|;
comment|/* Used to ensure unique invoke id's are used when invoking operations. */
name|struct
name|task_act
modifier|*
name|cn_tasklist
decl_stmt|;
comment|/* List of tasks received over this connection. */
name|struct
name|oper_act
modifier|*
name|cn_operlist
decl_stmt|;
comment|/* List of operations sent over this connection. */
name|struct
name|connection
modifier|*
name|cn_next
decl_stmt|;
comment|/* Rest of list of connections. */
name|int
name|cn_authen
decl_stmt|;
comment|/* Takes a value from bind.h -> level to which the association is authenticated */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLCONN
value|((struct connection *) NULL)
end_define

begin_comment
comment|/* *  Global variables are nasty but useful. Here the external definitions *  for the most crucial are given: *	a handle on the connections being processed *	info describing how this DSA wants the lower layers parameterised *	a handle on current deferred get dsa info operations *	a handle on current get_edb operations */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|connection
modifier|*
name|connlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Connection blocks */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|conns_used
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* No. conns in connlist */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|connection
modifier|*
name|connwaitlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Connection blocks to be */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|di_block
modifier|*
name|deferred_dis
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* deferred di_blocks */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|oper_act
modifier|*
name|get_edb_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GET_EDB operations */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|PSAPaddr
modifier|*
name|mydsaaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PSAP of this DSA */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

