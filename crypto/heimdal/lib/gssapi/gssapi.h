begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: gssapi.h,v 1.20 2001/01/30 00:35:48 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GSSAPI_H_
end_ifndef

begin_define
define|#
directive|define
name|GSSAPI_H_
end_define

begin_comment
comment|/*  * First, include stddef.h to get size_t defined.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_comment
comment|/*  * Now define the three implementation-dependent types.  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|OM_uint32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|gss_uint32
typedef|;
end_typedef

begin_comment
comment|/*  * This is to avoid having to include<krb5.h>  */
end_comment

begin_struct_decl
struct_decl|struct
name|krb5_auth_context_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|Principal
struct_decl|;
end_struct_decl

begin_comment
comment|/* typedef void *gss_name_t; */
end_comment

begin_typedef
typedef|typedef
name|struct
name|Principal
modifier|*
name|gss_name_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gss_ctx_id_t_desc_struct
block|{
name|struct
name|krb5_auth_context_data
modifier|*
name|auth_context
decl_stmt|;
name|gss_name_t
name|source
decl_stmt|,
name|target
decl_stmt|;
name|OM_uint32
name|flags
decl_stmt|;
enum|enum
block|{
name|LOCAL
init|=
literal|1
block|,
name|OPEN
init|=
literal|2
block|}
name|more_flags
enum|;
name|struct
name|krb5_ticket
modifier|*
name|ticket
decl_stmt|;
block|}
name|gss_ctx_id_t_desc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|gss_ctx_id_t_desc
modifier|*
name|gss_ctx_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gss_OID_desc_struct
block|{
name|OM_uint32
name|length
decl_stmt|;
name|void
modifier|*
name|elements
decl_stmt|;
block|}
name|gss_OID_desc
operator|,
typedef|*
name|gss_OID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gss_OID_set_desc_struct
block|{
name|size_t
name|count
decl_stmt|;
name|gss_OID
name|elements
decl_stmt|;
block|}
name|gss_OID_set_desc
operator|,
typedef|*
name|gss_OID_set
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_keytab_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|krb5_ccache_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|gss_cred_usage_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gss_cred_id_t_desc_struct
block|{
name|gss_name_t
name|principal
decl_stmt|;
name|struct
name|krb5_keytab_data
modifier|*
name|keytab
decl_stmt|;
name|OM_uint32
name|lifetime
decl_stmt|;
name|gss_cred_usage_t
name|usage
decl_stmt|;
name|gss_OID_set
name|mechanisms
decl_stmt|;
name|struct
name|krb5_ccache_data
modifier|*
name|ccache
decl_stmt|;
block|}
name|gss_cred_id_t_desc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|gss_cred_id_t_desc
modifier|*
name|gss_cred_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gss_buffer_desc_struct
block|{
name|size_t
name|length
decl_stmt|;
name|void
modifier|*
name|value
decl_stmt|;
block|}
name|gss_buffer_desc
operator|,
typedef|*
name|gss_buffer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gss_channel_bindings_struct
block|{
name|OM_uint32
name|initiator_addrtype
decl_stmt|;
name|gss_buffer_desc
name|initiator_address
decl_stmt|;
name|OM_uint32
name|acceptor_addrtype
decl_stmt|;
name|gss_buffer_desc
name|acceptor_address
decl_stmt|;
name|gss_buffer_desc
name|application_data
decl_stmt|;
block|}
typedef|*
name|gss_channel_bindings_t
typedef|;
end_typedef

begin_comment
comment|/*  * For now, define a QOP-type as an OM_uint32  */
end_comment

begin_typedef
typedef|typedef
name|OM_uint32
name|gss_qop_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flag bits for context-level services.  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_DELEG_FLAG
value|1
end_define

begin_define
define|#
directive|define
name|GSS_C_MUTUAL_FLAG
value|2
end_define

begin_define
define|#
directive|define
name|GSS_C_REPLAY_FLAG
value|4
end_define

begin_define
define|#
directive|define
name|GSS_C_SEQUENCE_FLAG
value|8
end_define

begin_define
define|#
directive|define
name|GSS_C_CONF_FLAG
value|16
end_define

begin_define
define|#
directive|define
name|GSS_C_INTEG_FLAG
value|32
end_define

begin_define
define|#
directive|define
name|GSS_C_ANON_FLAG
value|64
end_define

begin_define
define|#
directive|define
name|GSS_C_PROT_READY_FLAG
value|128
end_define

begin_define
define|#
directive|define
name|GSS_C_TRANS_FLAG
value|256
end_define

begin_comment
comment|/*  * Credential usage options  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_BOTH
value|0
end_define

begin_define
define|#
directive|define
name|GSS_C_INITIATE
value|1
end_define

begin_define
define|#
directive|define
name|GSS_C_ACCEPT
value|2
end_define

begin_comment
comment|/*  * Status code types for gss_display_status  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_GSS_CODE
value|1
end_define

begin_define
define|#
directive|define
name|GSS_C_MECH_CODE
value|2
end_define

begin_comment
comment|/*  * The constant definitions for channel-bindings address families  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_AF_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_LOCAL
value|1
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_INET
value|2
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_IMPLINK
value|3
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_PUP
value|4
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_CHAOS
value|5
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_NS
value|6
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_NBS
value|7
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_ECMA
value|8
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_DATAKIT
value|9
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_CCITT
value|10
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_SNA
value|11
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_DECnet
value|12
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_DLI
value|13
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_LAT
value|14
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_HYLINK
value|15
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_APPLETALK
value|16
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_BSC
value|17
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_DSS
value|18
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_OSI
value|19
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_X25
value|21
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_INET6
value|24
end_define

begin_define
define|#
directive|define
name|GSS_C_AF_NULLADDR
value|255
end_define

begin_comment
comment|/*  * Various Null values  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_NO_NAME
value|((gss_name_t) 0)
end_define

begin_define
define|#
directive|define
name|GSS_C_NO_BUFFER
value|((gss_buffer_t) 0)
end_define

begin_define
define|#
directive|define
name|GSS_C_NO_OID
value|((gss_OID) 0)
end_define

begin_define
define|#
directive|define
name|GSS_C_NO_OID_SET
value|((gss_OID_set) 0)
end_define

begin_define
define|#
directive|define
name|GSS_C_NO_CONTEXT
value|((gss_ctx_id_t) 0)
end_define

begin_define
define|#
directive|define
name|GSS_C_NO_CREDENTIAL
value|((gss_cred_id_t) 0)
end_define

begin_define
define|#
directive|define
name|GSS_C_NO_CHANNEL_BINDINGS
value|((gss_channel_bindings_t) 0)
end_define

begin_define
define|#
directive|define
name|GSS_C_EMPTY_BUFFER
value|{0, NULL}
end_define

begin_comment
comment|/*  * Some alternate names for a couple of the above  * values.  These are defined for V1 compatibility.  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_NULL_OID
value|GSS_C_NO_OID
end_define

begin_define
define|#
directive|define
name|GSS_C_NULL_OID_SET
value|GSS_C_NO_OID_SET
end_define

begin_comment
comment|/*  * Define the default Quality of Protection for per-message  * services.  Note that an implementation that offers multiple  * levels of QOP may define GSS_C_QOP_DEFAULT to be either zero  * (as done here) to mean "default protection", or to a specific  * explicit QOP value.  However, a value of 0 should always be  * interpreted by a GSSAPI implementation as a request for the  * default protection level.  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_QOP_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|GSS_KRB5_CONF_C_QOP_DES
value|0x0100
end_define

begin_define
define|#
directive|define
name|GSS_KRB5_CONF_C_QOP_DES3_KD
value|0x0200
end_define

begin_comment
comment|/*  * Expiration time of 2^32-1 seconds means infinite lifetime for a  * credential or security context  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_INDEFINITE
value|0xfffffffful
end_define

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x01"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) user_name(1)}.  The constant  * GSS_C_NT_USER_NAME should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_C_NT_USER_NAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x02"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) machine_uid_name(2)}.  * The constant GSS_C_NT_MACHINE_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_C_NT_MACHINE_UID_NAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x03"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) string_uid_name(3)}.  * The constant GSS_C_NT_STRING_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_C_NT_STRING_UID_NAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\x01\x05\x06\x02"},  * corresponding to an object-identifier value of  * {iso(1) org(3) dod(6) internet(1) security(5)  * nametypes(6) gss-host-based-services(2)).  The constant  * GSS_C_NT_HOSTBASED_SERVICE_X should be initialized to point  * to that gss_OID_desc.  This is a deprecated OID value, and  * implementations wishing to support hostbased-service names  * should instead use the GSS_C_NT_HOSTBASED_SERVICE OID,  * defined below, to identify such names;  * GSS_C_NT_HOSTBASED_SERVICE_X should be accepted a synonym  * for GSS_C_NT_HOSTBASED_SERVICE when presented as an input  * parameter, but should not be emitted by GSS-API  * implementations  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_C_NT_HOSTBASED_SERVICE_X
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x04"}, corresponding to an  * object-identifier value of {iso(1) member-body(2)  * Unites States(840) mit(113554) infosys(1) gssapi(2)  * generic(1) service_name(4)}.  The constant  * GSS_C_NT_HOSTBASED_SERVICE should be initialized  * to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_C_NT_HOSTBASED_SERVICE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\01\x05\x06\x03"},  * corresponding to an object identifier value of  * {1(iso), 3(org), 6(dod), 1(internet), 5(security),  * 6(nametypes), 3(gss-anonymous-name)}.  The constant  * and GSS_C_NT_ANONYMOUS should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_C_NT_ANONYMOUS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\x01\x05\x06\x04"},  * corresponding to an object-identifier value of  * {1(iso), 3(org), 6(dod), 1(internet), 5(security),  * 6(nametypes), 4(gss-api-exported-name)}.  The constant  * GSS_C_NT_EXPORT_NAME should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_C_NT_EXPORT_NAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This if for kerberos5 names.  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_KRB5_NT_PRINCIPAL_NAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_KRB5_NT_USER_NAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_KRB5_NT_MACHINE_UID_NAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_KRB5_NT_STRING_UID_NAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_KRB5_MECHANISM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for compatibility with MIT api */
end_comment

begin_define
define|#
directive|define
name|gss_mech_krb5
value|GSS_KRB5_MECHANISM
end_define

begin_comment
comment|/* Major status codes */
end_comment

begin_define
define|#
directive|define
name|GSS_S_COMPLETE
value|0
end_define

begin_comment
comment|/*  * Some "helper" definitions to make the status code macros obvious.  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_CALLING_ERROR_OFFSET
value|24
end_define

begin_define
define|#
directive|define
name|GSS_C_ROUTINE_ERROR_OFFSET
value|16
end_define

begin_define
define|#
directive|define
name|GSS_C_SUPPLEMENTARY_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|GSS_C_CALLING_ERROR_MASK
value|0377ul
end_define

begin_define
define|#
directive|define
name|GSS_C_ROUTINE_ERROR_MASK
value|0377ul
end_define

begin_define
define|#
directive|define
name|GSS_C_SUPPLEMENTARY_MASK
value|0177777ul
end_define

begin_comment
comment|/*  * The macros that test status codes for error conditions.  * Note that the GSS_ERROR() macro has changed slightly from  * the V1 GSSAPI so that it now evaluates its argument  * only once.  */
end_comment

begin_define
define|#
directive|define
name|GSS_CALLING_ERROR
parameter_list|(
name|x
parameter_list|)
define|\
value|(x& (GSS_C_CALLING_ERROR_MASK<< GSS_C_CALLING_ERROR_OFFSET))
end_define

begin_define
define|#
directive|define
name|GSS_ROUTINE_ERROR
parameter_list|(
name|x
parameter_list|)
define|\
value|(x& (GSS_C_ROUTINE_ERROR_MASK<< GSS_C_ROUTINE_ERROR_OFFSET))
end_define

begin_define
define|#
directive|define
name|GSS_SUPPLEMENTARY_INFO
parameter_list|(
name|x
parameter_list|)
define|\
value|(x& (GSS_C_SUPPLEMENTARY_MASK<< GSS_C_SUPPLEMENTARY_OFFSET))
end_define

begin_define
define|#
directive|define
name|GSS_ERROR
parameter_list|(
name|x
parameter_list|)
define|\
value|(x& ((GSS_C_CALLING_ERROR_MASK<< GSS_C_CALLING_ERROR_OFFSET) | \         (GSS_C_ROUTINE_ERROR_MASK<< GSS_C_ROUTINE_ERROR_OFFSET)))
end_define

begin_comment
comment|/*  * Now the actual status code definitions  */
end_comment

begin_comment
comment|/*  * Calling errors:  */
end_comment

begin_define
define|#
directive|define
name|GSS_S_CALL_INACCESSIBLE_READ
define|\
value|(1ul<< GSS_C_CALLING_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_CALL_INACCESSIBLE_WRITE
define|\
value|(2ul<< GSS_C_CALLING_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_CALL_BAD_STRUCTURE
define|\
value|(3ul<< GSS_C_CALLING_ERROR_OFFSET)
end_define

begin_comment
comment|/*  * Routine errors:  */
end_comment

begin_define
define|#
directive|define
name|GSS_S_BAD_MECH
value|(1ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_NAME
value|(2ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_NAMETYPE
value|(3ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_BINDINGS
value|(4ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_STATUS
value|(5ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_SIG
value|(6ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_MIC
value|GSS_S_BAD_SIG
end_define

begin_define
define|#
directive|define
name|GSS_S_NO_CRED
value|(7ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_NO_CONTEXT
value|(8ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_DEFECTIVE_TOKEN
value|(9ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_DEFECTIVE_CREDENTIAL
value|(10ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_CREDENTIALS_EXPIRED
value|(11ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_CONTEXT_EXPIRED
value|(12ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_FAILURE
value|(13ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_QOP
value|(14ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_UNAUTHORIZED
value|(15ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_UNAVAILABLE
value|(16ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_DUPLICATE_ELEMENT
value|(17ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_define
define|#
directive|define
name|GSS_S_NAME_NOT_MN
value|(18ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_comment
comment|/*  * Supplementary info bits:  */
end_comment

begin_define
define|#
directive|define
name|GSS_S_CONTINUE_NEEDED
value|(1ul<< (GSS_C_SUPPLEMENTARY_OFFSET + 0))
end_define

begin_define
define|#
directive|define
name|GSS_S_DUPLICATE_TOKEN
value|(1ul<< (GSS_C_SUPPLEMENTARY_OFFSET + 1))
end_define

begin_define
define|#
directive|define
name|GSS_S_OLD_TOKEN
value|(1ul<< (GSS_C_SUPPLEMENTARY_OFFSET + 2))
end_define

begin_define
define|#
directive|define
name|GSS_S_UNSEQ_TOKEN
value|(1ul<< (GSS_C_SUPPLEMENTARY_OFFSET + 3))
end_define

begin_define
define|#
directive|define
name|GSS_S_GAP_TOKEN
value|(1ul<< (GSS_C_SUPPLEMENTARY_OFFSET + 4))
end_define

begin_comment
comment|/*  * From RFC1964:  *  * 4.1.1. Non-Kerberos-specific codes  */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_G_BAD_SERVICE_NAME
value|1
end_define

begin_comment
comment|/* "No @ in SERVICE-NAME name string" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_G_BAD_STRING_UID
value|2
end_define

begin_comment
comment|/* "STRING-UID-NAME contains nondigits" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_G_NOUSER
value|3
end_define

begin_comment
comment|/* "UID does not resolve to username" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_G_VALIDATE_FAILED
value|4
end_define

begin_comment
comment|/* "Validation error" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_G_BUFFER_ALLOC
value|5
end_define

begin_comment
comment|/* "Couldn't allocate gss_buffer_t data" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_G_BAD_MSG_CTX
value|6
end_define

begin_comment
comment|/* "Message context invalid" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_G_WRONG_SIZE
value|7
end_define

begin_comment
comment|/* "Buffer is the wrong size" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_G_BAD_USAGE
value|8
end_define

begin_comment
comment|/* "Credential usage type is unknown" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_G_UNKNOWN_QOP
value|9
end_define

begin_comment
comment|/* "Unknown quality of protection specified" */
end_comment

begin_comment
comment|/*    * 4.1.2. Kerberos-specific-codes    */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_KG_CCACHE_NOMATCH
value|10
end_define

begin_comment
comment|/* "Principal in credential cache does not match desired name" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_KG_KEYTAB_NOMATCH
value|11
end_define

begin_comment
comment|/* "No principal in keytab matches desired name" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_KG_TGT_MISSING
value|12
end_define

begin_comment
comment|/* "Credential cache has no TGT" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_KG_NO_SUBKEY
value|13
end_define

begin_comment
comment|/* "Authenticator has no subkey" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_KG_CONTEXT_ESTABLISHED
value|14
end_define

begin_comment
comment|/* "Context is already fully established" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_KG_BAD_SIGN_TYPE
value|15
end_define

begin_comment
comment|/* "Unknown signature type in token" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_KG_BAD_LENGTH
value|16
end_define

begin_comment
comment|/* "Invalid field length in token" */
end_comment

begin_define
define|#
directive|define
name|GSS_KRB5_S_KG_CTX_INCOMPLETE
value|17
end_define

begin_comment
comment|/* "Attempt to use incomplete security context" */
end_comment

begin_comment
comment|/*  * Finally, function prototypes for the GSS-API routines.  */
end_comment

begin_function_decl
name|OM_uint32
name|gss_acquire_cred
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_name_t
name|desired_name
parameter_list|,
name|OM_uint32
name|time_req
parameter_list|,
specifier|const
name|gss_OID_set
name|desired_mechs
parameter_list|,
name|gss_cred_usage_t
name|cred_usage
parameter_list|,
name|gss_cred_id_t
modifier|*
name|output_cred_handle
parameter_list|,
name|gss_OID_set
modifier|*
name|actual_mechs
parameter_list|,
name|OM_uint32
modifier|*
name|time_rec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_release_cred
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_cred_id_t
modifier|*
name|cred_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_init_sec_context
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_cred_id_t
name|initiator_cred_handle
parameter_list|,
name|gss_ctx_id_t
modifier|*
name|context_handle
parameter_list|,
specifier|const
name|gss_name_t
name|target_name
parameter_list|,
specifier|const
name|gss_OID
name|mech_type
parameter_list|,
name|OM_uint32
name|req_flags
parameter_list|,
name|OM_uint32
name|time_req
parameter_list|,
specifier|const
name|gss_channel_bindings_t
name|input_chan_bindings
parameter_list|,
specifier|const
name|gss_buffer_t
name|input_token
parameter_list|,
name|gss_OID
modifier|*
name|actual_mech_type
parameter_list|,
name|gss_buffer_t
name|output_token
parameter_list|,
name|OM_uint32
modifier|*
name|ret_flags
parameter_list|,
name|OM_uint32
modifier|*
name|time_rec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_accept_sec_context
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
modifier|*
name|context_handle
parameter_list|,
specifier|const
name|gss_cred_id_t
name|acceptor_cred_handle
parameter_list|,
specifier|const
name|gss_buffer_t
name|input_token_buffer
parameter_list|,
specifier|const
name|gss_channel_bindings_t
name|input_chan_bindings
parameter_list|,
name|gss_name_t
modifier|*
name|src_name
parameter_list|,
name|gss_OID
modifier|*
name|mech_type
parameter_list|,
name|gss_buffer_t
name|output_token
parameter_list|,
name|OM_uint32
modifier|*
name|ret_flags
parameter_list|,
name|OM_uint32
modifier|*
name|time_rec
parameter_list|,
name|gss_cred_id_t
modifier|*
name|delegated_cred_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_process_context_token
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
specifier|const
name|gss_buffer_t
name|token_buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_delete_sec_context
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
modifier|*
name|context_handle
parameter_list|,
name|gss_buffer_t
name|output_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_context_time
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|OM_uint32
modifier|*
name|time_rec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_get_mic
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|gss_qop_t
name|qop_req
parameter_list|,
specifier|const
name|gss_buffer_t
name|message_buffer
parameter_list|,
name|gss_buffer_t
name|message_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_verify_mic
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
specifier|const
name|gss_buffer_t
name|message_buffer
parameter_list|,
specifier|const
name|gss_buffer_t
name|token_buffer
parameter_list|,
name|gss_qop_t
modifier|*
name|qop_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_wrap
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|int
name|conf_req_flag
parameter_list|,
name|gss_qop_t
name|qop_req
parameter_list|,
specifier|const
name|gss_buffer_t
name|input_message_buffer
parameter_list|,
name|int
modifier|*
name|conf_state
parameter_list|,
name|gss_buffer_t
name|output_message_buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_unwrap
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
specifier|const
name|gss_buffer_t
name|input_message_buffer
parameter_list|,
name|gss_buffer_t
name|output_message_buffer
parameter_list|,
name|int
modifier|*
name|conf_state
parameter_list|,
name|gss_qop_t
modifier|*
name|qop_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_display_status
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|OM_uint32
name|status_value
parameter_list|,
name|int
name|status_type
parameter_list|,
specifier|const
name|gss_OID
name|mech_type
parameter_list|,
name|OM_uint32
modifier|*
name|message_context
parameter_list|,
name|gss_buffer_t
name|status_string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_indicate_mechs
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_OID_set
modifier|*
name|mech_set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_compare_name
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_name_t
name|name1
parameter_list|,
specifier|const
name|gss_name_t
name|name2
parameter_list|,
name|int
modifier|*
name|name_equal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_display_name
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_name_t
name|input_name
parameter_list|,
name|gss_buffer_t
name|output_name_buffer
parameter_list|,
name|gss_OID
modifier|*
name|output_name_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_import_name
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_buffer_t
name|input_name_buffer
parameter_list|,
specifier|const
name|gss_OID
name|input_name_type
parameter_list|,
name|gss_name_t
modifier|*
name|output_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_export_name
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_name_t
name|input_name
parameter_list|,
name|gss_buffer_t
name|exported_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_release_name
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_name_t
modifier|*
name|input_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_release_buffer
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_buffer_t
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_release_oid_set
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_OID_set
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_cred
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_cred_id_t
name|cred_handle
parameter_list|,
name|gss_name_t
modifier|*
name|name
parameter_list|,
name|OM_uint32
modifier|*
name|lifetime
parameter_list|,
name|gss_cred_usage_t
modifier|*
name|cred_usage
parameter_list|,
name|gss_OID_set
modifier|*
name|mechanisms
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_context
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|gss_name_t
modifier|*
name|src_name
parameter_list|,
name|gss_name_t
modifier|*
name|targ_name
parameter_list|,
name|OM_uint32
modifier|*
name|lifetime_rec
parameter_list|,
name|gss_OID
modifier|*
name|mech_type
parameter_list|,
name|OM_uint32
modifier|*
name|ctx_flags
parameter_list|,
name|int
modifier|*
name|locally_initiated
parameter_list|,
name|int
modifier|*
name|open
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_wrap_size_limit
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|int
name|conf_req_flag
parameter_list|,
name|gss_qop_t
name|qop_req
parameter_list|,
name|OM_uint32
name|req_output_size
parameter_list|,
name|OM_uint32
modifier|*
name|max_input_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_add_cred
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_cred_id_t
name|input_cred_handle
parameter_list|,
specifier|const
name|gss_name_t
name|desired_name
parameter_list|,
specifier|const
name|gss_OID
name|desired_mech
parameter_list|,
name|gss_cred_usage_t
name|cred_usage
parameter_list|,
name|OM_uint32
name|initiator_time_req
parameter_list|,
name|OM_uint32
name|acceptor_time_req
parameter_list|,
name|gss_cred_id_t
modifier|*
name|output_cred_handle
parameter_list|,
name|gss_OID_set
modifier|*
name|actual_mechs
parameter_list|,
name|OM_uint32
modifier|*
name|initiator_time_rec
parameter_list|,
name|OM_uint32
modifier|*
name|acceptor_time_rec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_cred_by_mech
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_cred_id_t
name|cred_handle
parameter_list|,
specifier|const
name|gss_OID
name|mech_type
parameter_list|,
name|gss_name_t
modifier|*
name|name
parameter_list|,
name|OM_uint32
modifier|*
name|initiator_lifetime
parameter_list|,
name|OM_uint32
modifier|*
name|acceptor_lifetime
parameter_list|,
name|gss_cred_usage_t
modifier|*
name|cred_usage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_export_sec_context
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
modifier|*
name|context_handle
parameter_list|,
name|gss_buffer_t
name|interprocess_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_import_sec_context
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_buffer_t
name|interprocess_token
parameter_list|,
name|gss_ctx_id_t
modifier|*
name|context_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_create_empty_oid_set
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_OID_set
modifier|*
name|oid_set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_add_oid_set_member
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_OID
name|member_oid
parameter_list|,
name|gss_OID_set
modifier|*
name|oid_set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_test_oid_set_member
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_OID
name|member
parameter_list|,
specifier|const
name|gss_OID_set
name|set
parameter_list|,
name|int
modifier|*
name|present
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_names_for_mech
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_OID
name|mechanism
parameter_list|,
name|gss_OID_set
modifier|*
name|name_types
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_mechs_for_name
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_name_t
name|input_name
parameter_list|,
name|gss_OID_set
modifier|*
name|mech_types
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_canonicalize_name
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_name_t
name|input_name
parameter_list|,
specifier|const
name|gss_OID
name|mech_type
parameter_list|,
name|gss_name_t
modifier|*
name|output_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_duplicate_name
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_name_t
name|src_name
parameter_list|,
name|gss_name_t
modifier|*
name|dest_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The following routines are obsolete variants of gss_get_mic,  * gss_verify_mic, gss_wrap and gss_unwrap.  They should be  * provided by GSSAPI V2 implementations for backwards  * compatibility with V1 applications.  Distinct entrypoints  * (as opposed to #defines) should be provided, both to allow  * GSSAPI V1 applications to link against GSSAPI V2 implementations,  * and to retain the slight parameter type differences between the  * obsolete versions of these routines and their current forms.  */
end_comment

begin_function_decl
name|OM_uint32
name|gss_sign
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|int
name|qop_req
parameter_list|,
name|gss_buffer_t
name|message_buffer
parameter_list|,
name|gss_buffer_t
name|message_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_verify
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|gss_buffer_t
name|message_buffer
parameter_list|,
name|gss_buffer_t
name|token_buffer
parameter_list|,
name|int
modifier|*
name|qop_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_seal
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|int
name|conf_req_flag
parameter_list|,
name|int
name|qop_req
parameter_list|,
name|gss_buffer_t
name|input_message_buffer
parameter_list|,
name|int
modifier|*
name|conf_state
parameter_list|,
name|gss_buffer_t
name|output_message_buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_unseal
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|gss_buffer_t
name|input_message_buffer
parameter_list|,
name|gss_buffer_t
name|output_message_buffer
parameter_list|,
name|int
modifier|*
name|conf_state
parameter_list|,
name|int
modifier|*
name|qop_state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * kerberos mechanism specific functions  */
end_comment

begin_function_decl
name|OM_uint32
name|gsskrb5_register_acceptor_identity
parameter_list|(
name|char
modifier|*
name|identity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_krb5_copy_ccache
parameter_list|(
name|OM_uint32
modifier|*
name|minor
parameter_list|,
name|gss_cred_id_t
name|cred
parameter_list|,
name|struct
name|krb5_ccache_data
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GSSAPI_H_ */
end_comment

end_unit

