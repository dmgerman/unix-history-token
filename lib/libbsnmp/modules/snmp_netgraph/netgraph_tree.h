begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* generated file, don't edit - use ./genfiles */
end_comment

begin_function_decl
name|int
name|op_ng_config
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
end_function_decl

begin_define
define|#
directive|define
name|LEAF_begemotNgControlNodeName
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgResBufSiz
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgTimeout
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgDebugLevel
value|4
end_define

begin_function_decl
name|int
name|op_ng_stats
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
end_function_decl

begin_define
define|#
directive|define
name|LEAF_begemotNgNoMems
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgMsgReadErrs
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgTooLargeMsgs
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgDataReadErrs
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgTooLargeDatas
value|5
end_define

begin_function_decl
name|int
name|op_ng_type
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
end_function_decl

begin_define
define|#
directive|define
name|LEAF_begemotNgTypeStatus
value|2
end_define

begin_function_decl
name|int
name|op_ng_node
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
end_function_decl

begin_define
define|#
directive|define
name|LEAF_begemotNgNodeStatus
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgNodeName
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgNodeType
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgNodeHooks
value|5
end_define

begin_function_decl
name|int
name|op_ng_hook
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
end_function_decl

begin_define
define|#
directive|define
name|LEAF_begemotNgHookStatus
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgHookPeerNodeId
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgHookPeerHook
value|5
end_define

begin_define
define|#
directive|define
name|LEAF_begemotNgHookPeerType
value|6
end_define

begin_define
define|#
directive|define
name|netgraph_CTREE_SIZE
value|18
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|snmp_node
name|netgraph_ctree
index|[]
decl_stmt|;
end_decl_stmt

end_unit

