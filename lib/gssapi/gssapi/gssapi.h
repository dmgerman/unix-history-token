begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2007 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GSSAPI_GSSAPI_H_
end_ifndef

begin_define
define|#
directive|define
name|GSSAPI_GSSAPI_H_
end_define

begin_comment
comment|/*  * First, include stddef.h to get size_t defined.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BUILD_GSSAPI_LIB
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|GSSAPI_LIB_FUNCTION
value|__declspec(dllimport)
end_define

begin_define
define|#
directive|define
name|GSSAPI_LIB_CALL
value|__stdcall
end_define

begin_define
define|#
directive|define
name|GSSAPI_LIB_VARIABLE
value|__declspec(dllimport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GSSAPI_LIB_FUNCTION
end_define

begin_define
define|#
directive|define
name|GSSAPI_LIB_CALL
end_define

begin_define
define|#
directive|define
name|GSSAPI_LIB_VARIABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GSSAPI_DEPRECATED_FUNCTION
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
operator|(
name|__GNUC__
operator|>
literal|3
operator|)
operator|||
operator|(
operator|(
name|__GNUC__
operator|==
literal|3
operator|)
operator|&&
operator|(
name|__GNUC_MINOR__
operator|>=
literal|1
operator|)
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|GSSAPI_DEPRECATED_FUNCTION
parameter_list|(
name|X
parameter_list|)
value|__attribute__((deprecated))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GSSAPI_DEPRECATED_FUNCTION
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compatiblity with MIT Kerberos on the Mac */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__ppc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|2
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|GSSAPI_CPP_START
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|GSSAPI_CPP_END
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GSSAPI_CPP_START
end_define

begin_define
define|#
directive|define
name|GSSAPI_CPP_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|GSSAPI_CALLCONV
value|__stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GSSAPI_CALLCONV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Now define the three implementation-dependent types.  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|OM_uint32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|OM_uint64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|gss_uint32
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|gss_name_t_desc_struct
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|gss_name_t_desc_struct
modifier|*
name|gss_name_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|gss_name_t_desc_struct
modifier|*
name|gss_const_name_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|gss_ctx_id_t_desc_struct
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|gss_ctx_id_t_desc_struct
modifier|*
name|gss_ctx_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|gss_ctx_id_t_desc_struct
name|gss_const_ctx_id_t
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
specifier|const
name|gss_OID_desc
modifier|*
name|gss_const_OID
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

begin_typedef
typedef|typedef
specifier|const
name|gss_OID_set_desc
modifier|*
name|gss_const_OID_set
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gss_cred_usage_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|gss_cred_id_t_desc_struct
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|gss_cred_id_t_desc_struct
modifier|*
name|gss_cred_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|gss_cred_id_t_desc_struct
modifier|*
name|gss_const_cred_id_t
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
specifier|const
name|gss_buffer_desc
modifier|*
name|gss_const_buffer_t
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

begin_typedef
typedef|typedef
specifier|const
name|struct
name|gss_channel_bindings_struct
modifier|*
name|gss_const_channel_bindings_t
typedef|;
end_typedef

begin_comment
comment|/* GGF extension data types */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gss_buffer_set_desc_struct
block|{
name|size_t
name|count
decl_stmt|;
name|gss_buffer_desc
modifier|*
name|elements
decl_stmt|;
block|}
name|gss_buffer_set_desc
operator|,
typedef|*
name|gss_buffer_set_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gss_iov_buffer_desc_struct
block|{
name|OM_uint32
name|type
decl_stmt|;
name|gss_buffer_desc
name|buffer
decl_stmt|;
block|}
name|gss_iov_buffer_desc
operator|,
typedef|*
name|gss_iov_buffer_t
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

begin_define
define|#
directive|define
name|GSS_C_DCE_STYLE
value|4096
end_define

begin_define
define|#
directive|define
name|GSS_C_IDENTIFY_FLAG
value|8192
end_define

begin_define
define|#
directive|define
name|GSS_C_EXTENDED_ERROR_FLAG
value|16384
end_define

begin_define
define|#
directive|define
name|GSS_C_DELEG_POLICY_FLAG
value|32768
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
name|GSS_C_NO_BUFFER_SET
value|((gss_buffer_set_t) 0)
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

begin_define
define|#
directive|define
name|GSS_C_NO_IOV_BUFFER
value|((gss_iov_buffer_t)0)
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
comment|/*  * Type of gss_wrap_iov()/gss_unwrap_iov().  */
end_comment

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE_EMPTY
value|0
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE_DATA
value|1
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE_HEADER
value|2
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE_MECH_PARAMS
value|3
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE_TRAILER
value|7
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE_PADDING
value|9
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE_STREAM
value|10
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE_SIGN_ONLY
value|11
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE_FLAG_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_FLAG_ALLOCATE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_FLAG_ALLOCATED
value|0x00020000
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE_FLAG_ALLOCATE
value|0x00010000
end_define

begin_comment
comment|/* old name */
end_comment

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE_FLAG_ALLOCATED
value|0x00020000
end_define

begin_comment
comment|/* old name */
end_comment

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_TYPE
parameter_list|(
name|_t
parameter_list|)
value|((_t)& ~GSS_IOV_BUFFER_TYPE_FLAG_MASK)
end_define

begin_define
define|#
directive|define
name|GSS_IOV_BUFFER_FLAGS
parameter_list|(
name|_t
parameter_list|)
value|((_t)& GSS_IOV_BUFFER_TYPE_FLAG_MASK)
end_define

begin_decl_stmt
name|GSSAPI_CPP_START
include|#
directive|include
file|<gssapi/gssapi_oid.h>
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x01"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) user_name(1)}.  The constant  * GSS_C_NT_USER_NAME should be initialized to point  * to that gss_OID_desc.  */
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_nt_user_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NT_USER_NAME
value|(&__gss_c_nt_user_name_oid_desc)
end_define

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x02"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) machine_uid_name(2)}.  * The constant GSS_C_NT_MACHINE_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_nt_machine_uid_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NT_MACHINE_UID_NAME
value|(&__gss_c_nt_machine_uid_name_oid_desc)
end_define

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x03"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) string_uid_name(3)}.  * The constant GSS_C_NT_STRING_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_nt_string_uid_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NT_STRING_UID_NAME
value|(&__gss_c_nt_string_uid_name_oid_desc)
end_define

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\x01\x05\x06\x02"},  * corresponding to an object-identifier value of  * {iso(1) org(3) dod(6) internet(1) security(5)  * nametypes(6) gss-host-based-services(2)).  The constant  * GSS_C_NT_HOSTBASED_SERVICE_X should be initialized to point  * to that gss_OID_desc.  This is a deprecated OID value, and  * implementations wishing to support hostbased-service names  * should instead use the GSS_C_NT_HOSTBASED_SERVICE OID,  * defined below, to identify such names;  * GSS_C_NT_HOSTBASED_SERVICE_X should be accepted a synonym  * for GSS_C_NT_HOSTBASED_SERVICE when presented as an input  * parameter, but should not be emitted by GSS-API  * implementations  */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_nt_hostbased_service_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NT_HOSTBASED_SERVICE_X
value|(&__gss_c_nt_hostbased_service_x_oid_desc)
end_define

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x04"}, corresponding to an  * object-identifier value of {iso(1) member-body(2)  * Unites States(840) mit(113554) infosys(1) gssapi(2)  * generic(1) service_name(4)}.  The constant  * GSS_C_NT_HOSTBASED_SERVICE should be initialized  * to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_nt_hostbased_service_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NT_HOSTBASED_SERVICE
value|(&__gss_c_nt_hostbased_service_oid_desc)
end_define

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\01\x05\x06\x03"},  * corresponding to an object identifier value of  * {1(iso), 3(org), 6(dod), 1(internet), 5(security),  * 6(nametypes), 3(gss-anonymous-name)}.  The constant  * and GSS_C_NT_ANONYMOUS should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_nt_anonymous_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NT_ANONYMOUS
value|(&__gss_c_nt_anonymous_oid_desc)
end_define

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\x01\x05\x06\x04"},  * corresponding to an object-identifier value of  * {1(iso), 3(org), 6(dod), 1(internet), 5(security),  * 6(nametypes), 4(gss-api-exported-name)}.  The constant  * GSS_C_NT_EXPORT_NAME should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_nt_export_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NT_EXPORT_NAME
value|(&__gss_c_nt_export_name_oid_desc)
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

begin_define
define|#
directive|define
name|GSS_S_BAD_MECH_ATTR
value|(19ul<< GSS_C_ROUTINE_ERROR_OFFSET)
end_define

begin_comment
comment|/*  * Apparently awating spec fix.  */
end_comment

begin_define
define|#
directive|define
name|GSS_S_CRED_UNAVAIL
value|GSS_S_FAILURE
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
comment|/*  * Finally, function prototypes for the GSS-API routines.  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_OPTION_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|GSS_C_CRED_NO_UI
value|0x10000
end_define

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_acquire_cred
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*desired_name*/
parameter_list|,
name|OM_uint32
comment|/*time_req*/
parameter_list|,
specifier|const
name|gss_OID_set
comment|/*desired_mechs*/
parameter_list|,
name|gss_cred_usage_t
comment|/*cred_usage*/
parameter_list|,
name|gss_cred_id_t
modifier|*
comment|/*output_cred_handle*/
parameter_list|,
name|gss_OID_set
modifier|*
comment|/*actual_mechs*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*time_rec*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_release_cred
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_cred_id_t
modifier|*
comment|/*cred_handle*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_init_sec_context
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_cred_id_t
comment|/*initiator_cred_handle*/
parameter_list|,
name|gss_ctx_id_t
modifier|*
comment|/*context_handle*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*target_name*/
parameter_list|,
specifier|const
name|gss_OID
comment|/*mech_type*/
parameter_list|,
name|OM_uint32
comment|/*req_flags*/
parameter_list|,
name|OM_uint32
comment|/*time_req*/
parameter_list|,
specifier|const
name|gss_channel_bindings_t
comment|/*input_chan_bindings*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*input_token*/
parameter_list|,
name|gss_OID
modifier|*
comment|/*actual_mech_type*/
parameter_list|,
name|gss_buffer_t
comment|/*output_token*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*ret_flags*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*time_rec*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_accept_sec_context
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_ctx_id_t
modifier|*
comment|/*context_handle*/
parameter_list|,
specifier|const
name|gss_cred_id_t
comment|/*acceptor_cred_handle*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*input_token_buffer*/
parameter_list|,
specifier|const
name|gss_channel_bindings_t
comment|/*input_chan_bindings*/
parameter_list|,
name|gss_name_t
modifier|*
comment|/*src_name*/
parameter_list|,
name|gss_OID
modifier|*
comment|/*mech_type*/
parameter_list|,
name|gss_buffer_t
comment|/*output_token*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*ret_flags*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*time_rec*/
parameter_list|,
name|gss_cred_id_t
modifier|*
comment|/*delegated_cred_handle*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_process_context_token
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*token_buffer*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_delete_sec_context
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_ctx_id_t
modifier|*
comment|/*context_handle*/
parameter_list|,
name|gss_buffer_t
comment|/*output_token*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_context_time
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*time_rec*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_get_mic
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
name|gss_qop_t
comment|/*qop_req*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*message_buffer*/
parameter_list|,
name|gss_buffer_t
comment|/*message_token*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_verify_mic
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*message_buffer*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*token_buffer*/
parameter_list|,
name|gss_qop_t
modifier|*
comment|/*qop_state*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_wrap
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
name|int
comment|/*conf_req_flag*/
parameter_list|,
name|gss_qop_t
comment|/*qop_req*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*input_message_buffer*/
parameter_list|,
name|int
modifier|*
comment|/*conf_state*/
parameter_list|,
name|gss_buffer_t
comment|/*output_message_buffer*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_unwrap
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*input_message_buffer*/
parameter_list|,
name|gss_buffer_t
comment|/*output_message_buffer*/
parameter_list|,
name|int
modifier|*
comment|/*conf_state*/
parameter_list|,
name|gss_qop_t
modifier|*
comment|/*qop_state*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_display_status
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|OM_uint32
comment|/*status_value*/
parameter_list|,
name|int
comment|/*status_type*/
parameter_list|,
specifier|const
name|gss_OID
comment|/*mech_type*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*message_context*/
parameter_list|,
name|gss_buffer_t
comment|/*status_string*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_indicate_mechs
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_OID_set
modifier|*
comment|/*mech_set*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_compare_name
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*name1*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*name2*/
parameter_list|,
name|int
modifier|*
comment|/*name_equal*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_display_name
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*input_name*/
parameter_list|,
name|gss_buffer_t
comment|/*output_name_buffer*/
parameter_list|,
name|gss_OID
modifier|*
comment|/*output_name_type*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_import_name
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*input_name_buffer*/
parameter_list|,
specifier|const
name|gss_OID
comment|/*input_name_type*/
parameter_list|,
name|gss_name_t
modifier|*
comment|/*output_name*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_export_name
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*input_name*/
parameter_list|,
name|gss_buffer_t
comment|/*exported_name*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_release_name
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_name_t
modifier|*
comment|/*input_name*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_release_buffer
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_buffer_t
comment|/*buffer*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_release_oid_set
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_OID_set
modifier|*
comment|/*set*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_inquire_cred
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_cred_id_t
comment|/*cred_handle*/
parameter_list|,
name|gss_name_t
modifier|*
comment|/*name*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*lifetime*/
parameter_list|,
name|gss_cred_usage_t
modifier|*
comment|/*cred_usage*/
parameter_list|,
name|gss_OID_set
modifier|*
comment|/*mechanisms*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_inquire_context
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
name|gss_name_t
modifier|*
comment|/*src_name*/
parameter_list|,
name|gss_name_t
modifier|*
comment|/*targ_name*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*lifetime_rec*/
parameter_list|,
name|gss_OID
modifier|*
comment|/*mech_type*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*ctx_flags*/
parameter_list|,
name|int
modifier|*
comment|/*locally_initiated*/
parameter_list|,
name|int
modifier|*
comment|/*open_context*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_wrap_size_limit
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
name|int
comment|/*conf_req_flag*/
parameter_list|,
name|gss_qop_t
comment|/*qop_req*/
parameter_list|,
name|OM_uint32
comment|/*req_output_size*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*max_input_size*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_add_cred
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_cred_id_t
comment|/*input_cred_handle*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*desired_name*/
parameter_list|,
specifier|const
name|gss_OID
comment|/*desired_mech*/
parameter_list|,
name|gss_cred_usage_t
comment|/*cred_usage*/
parameter_list|,
name|OM_uint32
comment|/*initiator_time_req*/
parameter_list|,
name|OM_uint32
comment|/*acceptor_time_req*/
parameter_list|,
name|gss_cred_id_t
modifier|*
comment|/*output_cred_handle*/
parameter_list|,
name|gss_OID_set
modifier|*
comment|/*actual_mechs*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*initiator_time_rec*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*acceptor_time_rec*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_inquire_cred_by_mech
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_cred_id_t
comment|/*cred_handle*/
parameter_list|,
specifier|const
name|gss_OID
comment|/*mech_type*/
parameter_list|,
name|gss_name_t
modifier|*
comment|/*name*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*initiator_lifetime*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*acceptor_lifetime*/
parameter_list|,
name|gss_cred_usage_t
modifier|*
comment|/*cred_usage*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_export_sec_context
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_ctx_id_t
modifier|*
comment|/*context_handle*/
parameter_list|,
name|gss_buffer_t
comment|/*interprocess_token*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_import_sec_context
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*interprocess_token*/
parameter_list|,
name|gss_ctx_id_t
modifier|*
comment|/*context_handle*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_create_empty_oid_set
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_OID_set
modifier|*
comment|/*oid_set*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_add_oid_set_member
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_OID
comment|/*member_oid*/
parameter_list|,
name|gss_OID_set
modifier|*
comment|/*oid_set*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_test_oid_set_member
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_OID
comment|/*member*/
parameter_list|,
specifier|const
name|gss_OID_set
comment|/*set*/
parameter_list|,
name|int
modifier|*
comment|/*present*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_inquire_names_for_mech
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_OID
comment|/*mechanism*/
parameter_list|,
name|gss_OID_set
modifier|*
comment|/*name_types*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_inquire_mechs_for_name
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*input_name*/
parameter_list|,
name|gss_OID_set
modifier|*
comment|/*mech_types*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_canonicalize_name
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*input_name*/
parameter_list|,
specifier|const
name|gss_OID
comment|/*mech_type*/
parameter_list|,
name|gss_name_t
modifier|*
comment|/*output_name*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_duplicate_name
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*src_name*/
parameter_list|,
name|gss_name_t
modifier|*
comment|/*dest_name*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_duplicate_oid
parameter_list|(
name|OM_uint32
modifier|*
comment|/* minor_status */
parameter_list|,
name|gss_OID
comment|/* src_oid */
parameter_list|,
name|gss_OID
modifier|*
comment|/* dest_oid */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_release_oid
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_OID
modifier|*
comment|/* oid */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_oid_to_str
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_OID
comment|/* oid */
parameter_list|,
name|gss_buffer_t
comment|/* str */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_inquire_sec_context_by_oid
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
name|gss_OID
name|desired_object
parameter_list|,
name|gss_buffer_set_t
modifier|*
name|data_set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_set_sec_context_option
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
name|gss_OID
name|desired_object
parameter_list|,
specifier|const
name|gss_buffer_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_set_cred_option
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_cred_id_t
modifier|*
name|cred_handle
parameter_list|,
specifier|const
name|gss_OID
name|object
parameter_list|,
specifier|const
name|gss_buffer_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|int
name|GSSAPI_LIB_CALL
name|gss_oid_equal
parameter_list|(
name|gss_const_OID
name|a
parameter_list|,
name|gss_const_OID
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_create_empty_buffer_set
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_buffer_set_t
modifier|*
name|buffer_set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_add_buffer_set_member
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_buffer_t
name|member_buffer
parameter_list|,
name|gss_buffer_set_t
modifier|*
name|buffer_set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_release_buffer_set
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_buffer_set_t
modifier|*
name|buffer_set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_inquire_cred_by_oid
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
name|desired_object
parameter_list|,
name|gss_buffer_set_t
modifier|*
name|data_set
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * RFC 4401  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_PRF_KEY_FULL
value|0
end_define

begin_define
define|#
directive|define
name|GSS_C_PRF_KEY_PARTIAL
value|1
end_define

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_pseudo_random
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
name|context
parameter_list|,
name|int
name|prf_key
parameter_list|,
specifier|const
name|gss_buffer_t
name|prf_in
parameter_list|,
name|ssize_t
name|desired_output_len
parameter_list|,
name|gss_buffer_t
name|prf_out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_store_cred
parameter_list|(
name|OM_uint32
modifier|*
comment|/* minor_status */
parameter_list|,
name|gss_cred_id_t
comment|/* input_cred_handle */
parameter_list|,
name|gss_cred_usage_t
comment|/* cred_usage */
parameter_list|,
specifier|const
name|gss_OID
comment|/* desired_mech */
parameter_list|,
name|OM_uint32
comment|/* overwrite_cred */
parameter_list|,
name|OM_uint32
comment|/* default_cred */
parameter_list|,
name|gss_OID_set
modifier|*
comment|/* elements_stored */
parameter_list|,
name|gss_cred_usage_t
modifier|*
comment|/* cred_usage_stored */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Query functions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|size_t
name|header
decl_stmt|;
comment|/**< size of header */
name|size_t
name|trailer
decl_stmt|;
comment|/**< size of trailer */
name|size_t
name|max_msg_size
decl_stmt|;
comment|/**< maximum message size */
name|size_t
name|buffers
decl_stmt|;
comment|/**< extra GSS_IOV_BUFFER_TYPE_EMPTY buffer to pass */
name|size_t
name|blocksize
decl_stmt|;
comment|/**< Specificed optimal size of messages, also 			 is the maximum padding size 			 (GSS_IOV_BUFFER_TYPE_PADDING) */
block|}
name|gss_context_stream_sizes
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_c_attr_stream_sizes_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_ATTR_STREAM_SIZES
value|(&__gss_c_attr_stream_sizes_oid_desc)
end_define

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_context_query_attributes
parameter_list|(
name|OM_uint32
modifier|*
comment|/* minor_status */
parameter_list|,
specifier|const
name|gss_ctx_id_t
comment|/* context_handle */
parameter_list|,
specifier|const
name|gss_OID
comment|/* attribute */
parameter_list|,
name|void
modifier|*
comment|/*data*/
parameter_list|,
name|size_t
comment|/* len */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The following routines are obsolete variants of gss_get_mic,  * gss_verify_mic, gss_wrap and gss_unwrap.  They should be  * provided by GSSAPI V2 implementations for backwards  * compatibility with V1 applications.  Distinct entrypoints  * (as opposed to #defines) should be provided, both to allow  * GSSAPI V1 applications to link against GSSAPI V2 implementations,  * and to retain the slight parameter type differences between the  * obsolete versions of these routines and their current forms.  */
end_comment

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_sign
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
name|int
comment|/*qop_req*/
parameter_list|,
name|gss_buffer_t
comment|/*message_buffer*/
parameter_list|,
name|gss_buffer_t
comment|/*message_token*/
parameter_list|)
function_decl|GSSAPI_DEPRECATED_FUNCTION
parameter_list|(
function_decl|"Use gss_get_mic"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_verify
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
name|gss_buffer_t
comment|/*message_buffer*/
parameter_list|,
name|gss_buffer_t
comment|/*token_buffer*/
parameter_list|,
name|int
modifier|*
comment|/*qop_state*/
parameter_list|)
function_decl|GSSAPI_DEPRECATED_FUNCTION
parameter_list|(
function_decl|"Use gss_verify_mic"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_seal
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
name|int
comment|/*conf_req_flag*/
parameter_list|,
name|int
comment|/*qop_req*/
parameter_list|,
name|gss_buffer_t
comment|/*input_message_buffer*/
parameter_list|,
name|int
modifier|*
comment|/*conf_state*/
parameter_list|,
name|gss_buffer_t
comment|/*output_message_buffer*/
parameter_list|)
function_decl|GSSAPI_DEPRECATED_FUNCTION
parameter_list|(
function_decl|"Use gss_wrap"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_unseal
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
name|gss_ctx_id_t
comment|/*context_handle*/
parameter_list|,
name|gss_buffer_t
comment|/*input_message_buffer*/
parameter_list|,
name|gss_buffer_t
comment|/*output_message_buffer*/
parameter_list|,
name|int
modifier|*
comment|/*conf_state*/
parameter_list|,
name|int
modifier|*
comment|/*qop_state*/
parameter_list|)
function_decl|GSSAPI_DEPRECATED_FUNCTION
parameter_list|(
function_decl|"Use gss_unwrap"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  *  */
end_comment

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_encapsulate_token
parameter_list|(
name|gss_const_buffer_t
comment|/* input_token */
parameter_list|,
name|gss_const_OID
comment|/* oid */
parameter_list|,
name|gss_buffer_t
comment|/* output_token */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_decapsulate_token
parameter_list|(
name|gss_const_buffer_t
comment|/* input_token */
parameter_list|,
name|gss_const_OID
comment|/* oid */
parameter_list|,
name|gss_buffer_t
comment|/* output_token */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * AEAD support  */
end_comment

begin_comment
comment|/*  * GSS_IOV  */
end_comment

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_wrap_iov
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
name|gss_ctx_id_t
parameter_list|,
name|int
parameter_list|,
name|gss_qop_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|gss_iov_buffer_desc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_unwrap_iov
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
name|gss_ctx_id_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|gss_qop_t
modifier|*
parameter_list|,
name|gss_iov_buffer_desc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_wrap_iov_length
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
name|gss_ctx_id_t
parameter_list|,
name|int
parameter_list|,
name|gss_qop_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|gss_iov_buffer_desc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_release_iov_buffer
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
name|gss_iov_buffer_desc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_export_cred
parameter_list|(
name|OM_uint32
modifier|*
comment|/* minor_status */
parameter_list|,
name|gss_cred_id_t
comment|/* cred_handle */
parameter_list|,
name|gss_buffer_t
comment|/* cred_token */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_import_cred
parameter_list|(
name|OM_uint32
modifier|*
comment|/* minor_status */
parameter_list|,
name|gss_buffer_t
comment|/* cred_token */
parameter_list|,
name|gss_cred_id_t
modifier|*
comment|/* cred_handle */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * mech option  */
end_comment

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|int
name|GSSAPI_LIB_CALL
name|gss_mo_set
parameter_list|(
name|gss_const_OID
name|mech
parameter_list|,
name|gss_const_OID
name|option
parameter_list|,
name|int
name|enable
parameter_list|,
name|gss_buffer_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|int
name|GSSAPI_LIB_CALL
name|gss_mo_get
parameter_list|(
name|gss_const_OID
name|mech
parameter_list|,
name|gss_const_OID
name|option
parameter_list|,
name|gss_buffer_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|void
name|GSSAPI_LIB_CALL
name|gss_mo_list
parameter_list|(
name|gss_const_OID
name|mech
parameter_list|,
name|gss_OID_set
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_mo_name
parameter_list|(
name|gss_const_OID
name|mech
parameter_list|,
name|gss_const_OID
name|options
parameter_list|,
name|gss_buffer_t
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * SASL glue functions and mech inquire  */
end_comment

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_inquire_saslname_for_mech
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_OID
name|desired_mech
parameter_list|,
name|gss_buffer_t
name|sasl_mech_name
parameter_list|,
name|gss_buffer_t
name|mech_name
parameter_list|,
name|gss_buffer_t
name|mech_description
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_inquire_mech_for_saslname
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_buffer_t
name|sasl_mech_name
parameter_list|,
name|gss_OID
modifier|*
name|mech_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_indicate_mechs_by_attrs
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_const_OID_set
name|desired_mech_attrs
parameter_list|,
name|gss_const_OID_set
name|except_mech_attrs
parameter_list|,
name|gss_const_OID_set
name|critical_mech_attrs
parameter_list|,
name|gss_OID_set
modifier|*
name|mechs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_inquire_attrs_for_mech
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_const_OID
name|mech
parameter_list|,
name|gss_OID_set
modifier|*
name|mech_attr
parameter_list|,
name|gss_OID_set
modifier|*
name|known_mech_attrs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_display_mech_attr
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_const_OID
name|mech_attr
parameter_list|,
name|gss_buffer_t
name|name
parameter_list|,
name|gss_buffer_t
name|short_desc
parameter_list|,
name|gss_buffer_t
name|long_desc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Solaris compat  */
end_comment

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_acquire_cred_with_password
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*desired_name*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*password*/
parameter_list|,
name|OM_uint32
comment|/*time_req*/
parameter_list|,
specifier|const
name|gss_OID_set
comment|/*desired_mechs*/
parameter_list|,
name|gss_cred_usage_t
comment|/*cred_usage*/
parameter_list|,
name|gss_cred_id_t
modifier|*
comment|/*output_cred_handle*/
parameter_list|,
name|gss_OID_set
modifier|*
comment|/*actual_mechs*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*time_rec*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_add_cred_with_password
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_cred_id_t
comment|/*input_cred_handle*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*desired_name*/
parameter_list|,
specifier|const
name|gss_OID
comment|/*desired_mech*/
parameter_list|,
specifier|const
name|gss_buffer_t
comment|/*password*/
parameter_list|,
name|gss_cred_usage_t
comment|/*cred_usage*/
parameter_list|,
name|OM_uint32
comment|/*initiator_time_req*/
parameter_list|,
name|OM_uint32
comment|/*acceptor_time_req*/
parameter_list|,
name|gss_cred_id_t
modifier|*
comment|/*output_cred_handle*/
parameter_list|,
name|gss_OID_set
modifier|*
comment|/*actual_mechs*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*initiator_time_rec*/
parameter_list|,
name|OM_uint32
modifier|*
comment|/*acceptor_time_rec*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_pname_to_uid
parameter_list|(
name|OM_uint32
modifier|*
name|minor
parameter_list|,
specifier|const
name|gss_name_t
name|name
parameter_list|,
specifier|const
name|gss_OID
name|mech_type
parameter_list|,
name|uid_t
modifier|*
name|uidOut
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_authorize_localname
parameter_list|(
name|OM_uint32
modifier|*
name|minor
parameter_list|,
specifier|const
name|gss_name_t
name|name
parameter_list|,
specifier|const
name|gss_name_t
name|user
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|int
name|GSSAPI_LIB_CALL
name|gss_userok
parameter_list|(
specifier|const
name|gss_name_t
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_buffer_desc
name|__gss_c_attr_local_login_user
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_ATTR_LOCAL_LOGIN_USER
value|(&__gss_c_attr_local_login_user)
end_define

begin_comment
comment|/*  * Naming extensions  */
end_comment

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_display_name_ext
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|gss_OID
parameter_list|,
comment|/* display_as_name_type */
name|gss_buffer_t
comment|/* display_name */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_inquire_name
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|int
modifier|*
parameter_list|,
comment|/* name_is_MN */
name|gss_OID
modifier|*
parameter_list|,
comment|/* MN_mech */
name|gss_buffer_set_t
modifier|*
comment|/* attrs */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_get_name_attribute
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|gss_buffer_t
parameter_list|,
comment|/* attr */
name|int
modifier|*
parameter_list|,
comment|/* authenticated */
name|int
modifier|*
parameter_list|,
comment|/* complete */
name|gss_buffer_t
parameter_list|,
comment|/* value */
name|gss_buffer_t
parameter_list|,
comment|/* display_value */
name|int
modifier|*
comment|/* more */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_set_name_attribute
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|int
parameter_list|,
comment|/* complete */
name|gss_buffer_t
parameter_list|,
comment|/* attr */
name|gss_buffer_t
comment|/* value */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_delete_name_attribute
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|gss_buffer_t
comment|/* attr */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|OM_uint32
name|GSSAPI_LIB_CALL
name|gss_export_name_composite
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|gss_buffer_t
comment|/* exp_composite_name */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  */
end_comment

begin_function_decl
name|GSSAPI_LIB_FUNCTION
specifier|const
name|char
modifier|*
name|GSSAPI_LIB_CALL
name|gss_oid_to_name
parameter_list|(
name|gss_const_OID
name|oid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GSSAPI_LIB_FUNCTION
name|gss_OID
name|GSSAPI_LIB_CALL
name|gss_name_to_oid
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|GSSAPI_CPP_END
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__ppc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|GSSAPI_DEPRECATED_FUNCTION
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GSSAPI_GSSAPI_H_ */
end_comment

end_unit

