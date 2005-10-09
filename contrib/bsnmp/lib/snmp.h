begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: bsnmp/lib/snmp.h,v 1.30 2004/08/06 08:46:54 brandt Exp $  *  * Header file for SNMP functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|snmp_h_
end_ifndef

begin_define
define|#
directive|define
name|snmp_h_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|SNMP_COMMUNITY_MAXLEN
value|128
end_define

begin_define
define|#
directive|define
name|SNMP_MAX_BINDINGS
value|100
end_define

begin_enum
enum|enum
name|snmp_syntax
block|{
name|SNMP_SYNTAX_NULL
init|=
literal|0
block|,
name|SNMP_SYNTAX_INTEGER
block|,
comment|/* == INTEGER32 */
name|SNMP_SYNTAX_OCTETSTRING
block|,
name|SNMP_SYNTAX_OID
block|,
name|SNMP_SYNTAX_IPADDRESS
block|,
name|SNMP_SYNTAX_COUNTER
block|,
name|SNMP_SYNTAX_GAUGE
block|,
comment|/* == UNSIGNED32 */
name|SNMP_SYNTAX_TIMETICKS
block|,
comment|/* v2 additions */
name|SNMP_SYNTAX_COUNTER64
block|,
name|SNMP_SYNTAX_NOSUCHOBJECT
block|,
comment|/* exception */
name|SNMP_SYNTAX_NOSUCHINSTANCE
block|,
comment|/* exception */
name|SNMP_SYNTAX_ENDOFMIBVIEW
block|,
comment|/* exception */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|snmp_value
block|{
name|struct
name|asn_oid
name|var
decl_stmt|;
name|enum
name|snmp_syntax
name|syntax
decl_stmt|;
union|union
name|snmp_values
block|{
name|int32_t
name|integer
decl_stmt|;
comment|/* also integer32 */
struct|struct
block|{
name|u_int
name|len
decl_stmt|;
name|u_char
modifier|*
name|octets
decl_stmt|;
block|}
name|octetstring
struct|;
name|struct
name|asn_oid
name|oid
decl_stmt|;
name|u_char
name|ipaddress
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|uint32
decl_stmt|;
comment|/* also gauge32, counter32, 						   unsigned32, timeticks */
name|uint64_t
name|counter64
decl_stmt|;
block|}
name|v
union|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|snmp_version
block|{
name|SNMP_Verr
init|=
literal|0
block|,
name|SNMP_V1
init|=
literal|1
block|,
name|SNMP_V2c
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|snmp_pdu
block|{
name|char
name|community
index|[
name|SNMP_COMMUNITY_MAXLEN
operator|+
literal|1
index|]
decl_stmt|;
name|enum
name|snmp_version
name|version
decl_stmt|;
name|u_int
name|type
decl_stmt|;
comment|/* trap only */
name|struct
name|asn_oid
name|enterprise
decl_stmt|;
name|u_char
name|agent_addr
index|[
literal|4
index|]
decl_stmt|;
name|int32_t
name|generic_trap
decl_stmt|;
name|int32_t
name|specific_trap
decl_stmt|;
name|uint32_t
name|time_stamp
decl_stmt|;
comment|/* others */
name|int32_t
name|request_id
decl_stmt|;
name|int32_t
name|error_status
decl_stmt|;
name|int32_t
name|error_index
decl_stmt|;
comment|/* fixes for encoding */
name|u_char
modifier|*
name|outer_ptr
decl_stmt|;
name|u_char
modifier|*
name|pdu_ptr
decl_stmt|;
name|u_char
modifier|*
name|vars_ptr
decl_stmt|;
name|struct
name|snmp_value
name|bindings
index|[
name|SNMP_MAX_BINDINGS
index|]
decl_stmt|;
name|u_int
name|nbindings
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|snmp_v1_pdu
value|snmp_pdu
end_define

begin_define
define|#
directive|define
name|SNMP_PDU_GET
value|0
end_define

begin_define
define|#
directive|define
name|SNMP_PDU_GETNEXT
value|1
end_define

begin_define
define|#
directive|define
name|SNMP_PDU_RESPONSE
value|2
end_define

begin_define
define|#
directive|define
name|SNMP_PDU_SET
value|3
end_define

begin_define
define|#
directive|define
name|SNMP_PDU_TRAP
value|4
end_define

begin_comment
comment|/* v1 */
end_comment

begin_define
define|#
directive|define
name|SNMP_PDU_GETBULK
value|5
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_PDU_INFORM
value|6
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_PDU_TRAP2
value|7
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_PDU_REPORT
value|8
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_NOERROR
value|0
end_define

begin_define
define|#
directive|define
name|SNMP_ERR_TOOBIG
value|1
end_define

begin_define
define|#
directive|define
name|SNMP_ERR_NOSUCHNAME
value|2
end_define

begin_comment
comment|/* v1 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_BADVALUE
value|3
end_define

begin_comment
comment|/* v1 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_READONLY
value|4
end_define

begin_comment
comment|/* v1 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_GENERR
value|5
end_define

begin_define
define|#
directive|define
name|SNMP_ERR_NO_ACCESS
value|6
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_WRONG_TYPE
value|7
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_WRONG_LENGTH
value|8
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_WRONG_ENCODING
value|9
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_WRONG_VALUE
value|10
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_NO_CREATION
value|11
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_INCONS_VALUE
value|12
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_RES_UNAVAIL
value|13
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_COMMIT_FAILED
value|14
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_UNDO_FAILED
value|15
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_AUTH_ERR
value|16
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_NOT_WRITEABLE
value|17
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_ERR_INCONS_NAME
value|18
end_define

begin_comment
comment|/* v2 */
end_comment

begin_define
define|#
directive|define
name|SNMP_TRAP_COLDSTART
value|0
end_define

begin_define
define|#
directive|define
name|SNMP_TRAP_WARMSTART
value|1
end_define

begin_define
define|#
directive|define
name|SNMP_TRAP_LINKDOWN
value|2
end_define

begin_define
define|#
directive|define
name|SNMP_TRAP_LINKUP
value|3
end_define

begin_define
define|#
directive|define
name|SNMP_TRAP_AUTHENTICATION_FAILURE
value|4
end_define

begin_define
define|#
directive|define
name|SNMP_TRAP_EGP_NEIGHBOR_LOSS
value|5
end_define

begin_define
define|#
directive|define
name|SNMP_TRAP_ENTERPRISE
value|6
end_define

begin_enum
enum|enum
name|snmp_code
block|{
name|SNMP_CODE_OK
init|=
literal|0
block|,
name|SNMP_CODE_FAILED
block|,
name|SNMP_CODE_BADVERS
block|,
name|SNMP_CODE_BADLEN
block|,
name|SNMP_CODE_BADENC
block|,
name|SNMP_CODE_OORANGE
block|, }
enum|;
end_enum

begin_function_decl
name|void
name|snmp_value_free
parameter_list|(
name|struct
name|snmp_value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snmp_value_parse
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|snmp_syntax
parameter_list|,
name|union
name|snmp_values
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snmp_value_copy
parameter_list|(
name|struct
name|snmp_value
modifier|*
parameter_list|,
specifier|const
name|struct
name|snmp_value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_pdu_free
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|snmp_code
name|snmp_pdu_decode
parameter_list|(
name|struct
name|asn_buf
modifier|*
name|b
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
name|pdu
parameter_list|,
name|int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|snmp_code
name|snmp_pdu_encode
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snmp_pdu_snoop
parameter_list|(
specifier|const
name|struct
name|asn_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_pdu_dump
parameter_list|(
specifier|const
name|struct
name|snmp_pdu
modifier|*
name|pdu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|snmp_error
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|snmp_printf
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRUTH_MK
parameter_list|(
name|F
parameter_list|)
value|((F) ? 1 : 2)
end_define

begin_define
define|#
directive|define
name|TRUTH_GET
parameter_list|(
name|T
parameter_list|)
value|(((T) == 1) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|TRUTH_OK
parameter_list|(
name|T
parameter_list|)
value|((T) == 1 || (T) == 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

