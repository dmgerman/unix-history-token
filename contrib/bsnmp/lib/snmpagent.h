begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: bsnmp/lib/snmpagent.h,v 1.13 2004/08/06 08:46:56 brandt Exp $  *  * Header file for SNMP functions. This requires snmp.h to be included.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|snmp_agent_h_
end_ifndef

begin_define
define|#
directive|define
name|snmp_agent_h_
end_define

begin_struct_decl
struct_decl|struct
name|snmp_dependency
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|snmp_ret
block|{
comment|/* OK, generate a response */
name|SNMP_RET_OK
init|=
literal|0
block|,
comment|/* Error, ignore packet (no response) */
name|SNMP_RET_IGN
init|=
literal|1
block|,
comment|/* Error, generate response from original packet */
name|SNMP_RET_ERR
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/* Semi-Opaque object for SET operations */
end_comment

begin_struct
struct|struct
name|snmp_context
block|{
name|u_int
name|var_index
decl_stmt|;
name|struct
name|snmp_scratch
modifier|*
name|scratch
decl_stmt|;
name|struct
name|snmp_dependency
modifier|*
name|dep
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
comment|/* user data */
name|enum
name|snmp_ret
name|code
decl_stmt|;
comment|/* return code */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|snmp_scratch
block|{
name|void
modifier|*
name|ptr1
decl_stmt|;
name|void
modifier|*
name|ptr2
decl_stmt|;
name|uint32_t
name|int1
decl_stmt|;
name|uint32_t
name|int2
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|snmp_depop
block|{
name|SNMP_DEPOP_COMMIT
block|,
name|SNMP_DEPOP_ROLLBACK
block|,
name|SNMP_DEPOP_FINISH
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|snmp_depop_t
function_decl|)
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_dependency
modifier|*
parameter_list|,
name|enum
name|snmp_depop
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|snmp_dependency
block|{
name|struct
name|asn_oid
name|obj
decl_stmt|;
name|struct
name|asn_oid
name|idx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The TREE  */
end_comment

begin_enum
enum|enum
name|snmp_node_type
block|{
name|SNMP_NODE_LEAF
init|=
literal|1
block|,
name|SNMP_NODE_COLUMN
block|}
enum|;
end_enum

begin_enum
enum|enum
name|snmp_op
block|{
name|SNMP_OP_GET
init|=
literal|1
block|,
name|SNMP_OP_GETNEXT
block|,
name|SNMP_OP_SET
block|,
name|SNMP_OP_COMMIT
block|,
name|SNMP_OP_ROLLBACK
block|, }
enum|;
end_enum

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|snmp_op_t
function_decl|)
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|snmp_node
block|{
name|struct
name|asn_oid
name|oid
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of the leaf */
name|enum
name|snmp_node_type
name|type
decl_stmt|;
comment|/* type of this node */
name|enum
name|snmp_syntax
name|syntax
decl_stmt|;
name|snmp_op_t
name|op
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
name|uint32_t
name|index
decl_stmt|;
comment|/* index data */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* application data */
name|void
modifier|*
name|tree_data
decl_stmt|;
comment|/* application data */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|snmp_node
modifier|*
name|tree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|tree_size
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SNMP_NODE_CANSET
value|0x0001
end_define

begin_comment
comment|/* SET allowed */
end_comment

begin_define
define|#
directive|define
name|SNMP_INDEXES_MAX
value|7
end_define

begin_define
define|#
directive|define
name|SNMP_INDEX_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SNMP_INDEX_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|SNMP_INDEX_COUNT
parameter_list|(
name|V
parameter_list|)
value|((V)& SNMP_INDEX_MASK)
end_define

begin_define
define|#
directive|define
name|SNMP_INDEX
parameter_list|(
name|V
parameter_list|,
name|I
parameter_list|)
define|\
value|(((V)>> (((I) + 1) * SNMP_INDEX_SHIFT))& SNMP_INDEX_MASK)
end_define

begin_enum
enum|enum
block|{
name|SNMP_TRACE_GET
init|=
literal|0x00000001
block|,
name|SNMP_TRACE_GETNEXT
init|=
literal|0x00000002
block|,
name|SNMP_TRACE_SET
init|=
literal|0x00000004
block|,
name|SNMP_TRACE_DEPEND
init|=
literal|0x00000008
block|,
name|SNMP_TRACE_FIND
init|=
literal|0x00000010
block|, }
enum|;
end_enum

begin_comment
comment|/* trace flag for the following functions */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|snmp_trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* called to write the trace */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|snmp_debug
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|snmp_ret
name|snmp_get
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
name|pdu
parameter_list|,
name|struct
name|asn_buf
modifier|*
name|resp_b
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
name|resp
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|snmp_ret
name|snmp_getnext
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
name|pdu
parameter_list|,
name|struct
name|asn_buf
modifier|*
name|resp_b
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
name|resp
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|snmp_ret
name|snmp_getbulk
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
name|pdu
parameter_list|,
name|struct
name|asn_buf
modifier|*
name|resp_b
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
name|resp
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|snmp_ret
name|snmp_set
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
name|pdu
parameter_list|,
name|struct
name|asn_buf
modifier|*
name|resp_b
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
name|resp
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|snmp_ret
name|snmp_make_errresp
parameter_list|(
specifier|const
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|struct
name|asn_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|snmp_dependency
modifier|*
name|snmp_dep_lookup
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|snmp_depop_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|snmp_context
modifier|*
name|snmp_init_context
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snmp_dep_commit
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snmp_dep_rollback
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_dep_finish
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

