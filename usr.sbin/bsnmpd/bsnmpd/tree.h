begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* generated file, don't edit - use ./genfiles */
end_comment

begin_function_decl
name|int
name|op_system_group
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
name|LEAF_sysDescr
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_sysObjectId
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_sysUpTime
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_sysContact
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_sysName
value|5
end_define

begin_define
define|#
directive|define
name|LEAF_sysLocation
value|6
end_define

begin_define
define|#
directive|define
name|LEAF_sysServices
value|7
end_define

begin_define
define|#
directive|define
name|LEAF_sysORLastChange
value|8
end_define

begin_function_decl
name|int
name|op_or_table
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
name|LEAF_sysORID
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_sysORDescr
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_sysORUpTime
value|4
end_define

begin_function_decl
name|int
name|op_snmp
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
name|LEAF_snmpInPkts
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_snmpInBadVersions
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_snmpInBadCommunityNames
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_snmpInBadCommunityUses
value|5
end_define

begin_define
define|#
directive|define
name|LEAF_snmpInASNParseErrs
value|6
end_define

begin_define
define|#
directive|define
name|LEAF_snmpEnableAuthenTraps
value|30
end_define

begin_define
define|#
directive|define
name|LEAF_snmpSilentDrops
value|31
end_define

begin_define
define|#
directive|define
name|LEAF_snmpProxyDrops
value|32
end_define

begin_function_decl
name|int
name|op_snmpd_config
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
name|LEAF_begemotSnmpdTransmitBuffer
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_begemotSnmpdReceiveBuffer
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_begemotSnmpdCommunityDisable
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_begemotSnmpdTrap1Addr
value|4
end_define

begin_function_decl
name|int
name|op_trapsink
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
name|LEAF_begemotTrapSinkStatus
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_begemotTrapSinkComm
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_begemotTrapSinkVersion
value|5
end_define

begin_function_decl
name|int
name|op_snmp_port
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
name|LEAF_begemotSnmpdPortStatus
value|3
end_define

begin_function_decl
name|int
name|op_community
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
name|LEAF_begemotSnmpdCommunityString
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_begemotSnmpdCommunityDescr
value|4
end_define

begin_function_decl
name|int
name|op_modules
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
name|LEAF_begemotSnmpdModulePath
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_begemotSnmpdModuleComment
value|3
end_define

begin_function_decl
name|int
name|op_snmpd_stats
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
name|LEAF_begemotSnmpdStatsNoRxBufs
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_begemotSnmpdStatsNoTxBufs
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_begemotSnmpdStatsInTooLongPkts
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_begemotSnmpdStatsInBadPduTypes
value|4
end_define

begin_function_decl
name|int
name|op_debug
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
name|LEAF_begemotSnmpdDebugDumpPdus
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_begemotSnmpdDebugSnmpTrace
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_begemotSnmpdDebugSyslogPri
value|3
end_define

begin_function_decl
name|int
name|op_local_port
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
name|LEAF_begemotSnmpdLocalPortStatus
value|2
end_define

begin_function_decl
name|int
name|op_snmp_set
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
name|LEAF_snmpSetSerialNo
value|1
end_define

begin_define
define|#
directive|define
name|CTREE_SIZE
value|40
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|snmp_node
name|ctree
index|[]
decl_stmt|;
end_decl_stmt

end_unit

