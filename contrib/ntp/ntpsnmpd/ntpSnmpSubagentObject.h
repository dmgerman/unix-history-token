begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*****************************************************************************  *  *  ntpSnmpSubAgentObject.h  *  *	Definitions and macros for ntpSnmpSubAgentObject.c  *  ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTPSNMPSUBAGENTOBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|NTPSNMPSUBAGENTOBJECT_H
end_define

begin_comment
comment|/* Function Prototypes */
end_comment

begin_function_decl
name|size_t
name|ntpsnmpd_parse_string
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|char
modifier|*
name|field
parameter_list|,
name|size_t
name|fieldsize
parameter_list|,
name|char
modifier|*
name|value
parameter_list|,
name|size_t
name|valuesize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|ntpsnmpd_cut_string
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|char
modifier|*
name|dest
parameter_list|,
name|char
name|delim
parameter_list|,
name|int
name|fieldnumber
parameter_list|,
name|size_t
name|maxsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|read_ntp_value
parameter_list|(
specifier|const
name|char
modifier|*
name|variable
parameter_list|,
name|char
modifier|*
name|value
parameter_list|,
name|size_t
name|valuesize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialization */
end_comment

begin_function_decl
name|void
name|init_ntpSnmpSubagentObject
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MIB Section 1 Callback Functions*/
end_comment

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntSoftwareName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntSoftwareVersion
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntSoftwareVendor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntSystemType
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntTimeResolution
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntTimePrecision
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntTimeDistance
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIB Section 2 Callback Functions (TODO) */
end_comment

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntStatusCurrentMode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntStatusCurrentModeVal
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntStatusStratum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntStatusActiveRefSourceId
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntStatusActiveRefSourceName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Netsnmp_Node_Handler
name|get_ntpEntStatusActiveOffset
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NTPV4_OID
value|1,3,6,1,2,1,197
end_define

begin_comment
comment|/* mib-2 197 */
end_comment

begin_comment
comment|/*  * The following macros simplify the registration of the callback  * functions and register the name and OID of either read-only (RO) or  * read-write (RW) functions.  */
end_comment

begin_define
define|#
directive|define
name|SETUP_OID_RO
parameter_list|(
name|oidname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|static oid oidname##_oid [] = { __VA_ARGS__ };			\ {								\ 	netsnmp_register_read_only_instance(			\ 		netsnmp_create_handler_registration(		\ 			"#oidname",				\ 			get_##oidname,				\ 			oidname##_oid,				\ 			OID_LENGTH				\ 			( oidname##_oid ),			\ 			HANDLER_CAN_RONLY));			\ }
end_define

begin_define
define|#
directive|define
name|SETUP_OID_RW
parameter_list|(
name|oidname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|static oid oidname##_oid [] = { __VA_ARGS__ };			\ {								\ 	netsnmp_register_instance(				\ 		netsnmp_create_handler_registration(		\ 			"#oidname",				\ 			do_##oidname,				\ 			oidname##_oid,				\ 			OID_LENGTH				\ 			( oidname##_oid ),			\ 			HANDLER_CAN_RWRITE));			\ }
end_define

begin_define
define|#
directive|define
name|NTP_OID_RO
parameter_list|(
name|oidname
parameter_list|,
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|SETUP_OID_RO(oidname, NTPV4_OID, w, x, y, z)
end_define

begin_define
define|#
directive|define
name|NTP_OID_RW
parameter_list|(
name|oidname
parameter_list|,
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|SETUP_OID_RW(oidname, NTPV4_OID, w, x, y, z)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

