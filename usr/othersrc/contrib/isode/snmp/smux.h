begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* smux.h - SMUX include file */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/snmp/RCS/smux.h,v 1.4 91/02/22 09:44:01 mrose Interim $  *  * Contributed by NYSERNet Inc.  This work was partially supported by the  * U.S. Defense Advanced Research Projects Agency and the Rome Air Development  * Center of the U.S. Air Force Systems Command under contract number  * F30602-88-C-0016.  *  *  * $Log:	smux.h,v $  * Revision 1.4  91/02/22  09:44:01  mrose  * Interim 6.8  *   * Revision 1.3  90/10/29  18:38:49  mrose  * updates  *   * Revision 1.2  90/02/19  15:38:48  mrose  * one more time  *   * Revision 1.1  90/02/17  10:38:29  mrose  * smux  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEPYPATH
end_ifndef

begin_include
include|#
directive|include
file|<isode/pepy/SNMP-types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"SNMP-types.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|readOnly
value|int_SNMP_operation_readOnly
end_define

begin_define
define|#
directive|define
name|readWrite
value|int_SNMP_operation_readWrite
end_define

begin_define
define|#
directive|define
name|delete
value|int_SNMP_operation_delete
end_define

begin_define
define|#
directive|define
name|goingDown
value|int_SNMP_ClosePDU_goingDown
end_define

begin_define
define|#
directive|define
name|unsupportedVersion
value|int_SNMP_ClosePDU_unsupportedVersion
end_define

begin_define
define|#
directive|define
name|packetFormat
value|int_SNMP_ClosePDU_packetFormat
end_define

begin_define
define|#
directive|define
name|protocolError
value|int_SNMP_ClosePDU_protocolError
end_define

begin_define
define|#
directive|define
name|internalError
value|int_SNMP_ClosePDU_internalError
end_define

begin_define
define|#
directive|define
name|authenticationFailure
value|int_SNMP_ClosePDU_authenticationFailure
end_define

begin_define
define|#
directive|define
name|invalidOperation
value|(-1)
end_define

begin_define
define|#
directive|define
name|parameterMissing
value|(-2)
end_define

begin_define
define|#
directive|define
name|systemError
value|(-3)
end_define

begin_define
define|#
directive|define
name|youLoseBig
value|(-4)
end_define

begin_define
define|#
directive|define
name|congestion
value|(-5)
end_define

begin_define
define|#
directive|define
name|inProgress
value|(-6)
end_define

begin_decl_stmt
specifier|extern
name|integer
name|smux_errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|smux_info
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_function_decl
name|int
name|smux_init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* INIT */
end_comment

begin_function_decl
name|int
name|smux_simple_open
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* (simple) OPEN */
end_comment

begin_function_decl
name|int
name|smux_close
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* CLOSE */
end_comment

begin_function_decl
name|int
name|smux_register
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* REGISTER */
end_comment

begin_function_decl
name|int
name|smux_response
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RESPONSE */
end_comment

begin_function_decl
name|int
name|smux_wait
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* WAIT */
end_comment

begin_function_decl
name|int
name|smux_trap
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* TRAP */
end_comment

begin_function_decl
name|char
modifier|*
name|smux_error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* TEXTUAL ERROR */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|smuxEntry
block|{
name|char
modifier|*
name|se_name
decl_stmt|;
name|OIDentifier
name|se_identity
decl_stmt|;
name|char
modifier|*
name|se_password
decl_stmt|;
name|int
name|se_priority
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|setsmuxEntry
argument_list|()
decl_stmt|,
name|endsmuxEntry
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|smuxEntry
modifier|*
name|getsmuxEntry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|smuxEntry
modifier|*
name|getsmuxEntrybyname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|smuxEntry
modifier|*
name|getsmuxEntrybyidentity
parameter_list|()
function_decl|;
end_function_decl

end_unit

