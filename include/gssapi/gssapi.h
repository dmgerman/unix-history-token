begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) The Internet Society (2000).  All Rights Reserved.  *  * This document and translations of it may be copied and furnished to  * others, and derivative works that comment on or otherwise explain it  * or assist in its implementation may be prepared, copied, published  * and distributed, in whole or in part, without restriction of any  * kind, provided that the above copyright notice and this paragraph are  * included on all such copies and derivative works.  However, this  * document itself may not be modified in any way, such as by removing  * the copyright notice or references to the Internet Society or other  * Internet organizations, except as needed for the purpose of  * developing Internet standards in which case the procedures for  * copyrights defined in the Internet Standards process must be  * followed, or as required to translate it into languages other than  * English.  *  * The limited permissions granted above are perpetual and will not be  * revoked by the Internet Society or its successors or assigns.  *  * This document and the information contained herein is provided on an  * "AS IS" basis and THE INTERNET SOCIETY AND THE INTERNET ENGINEERING  * TASK FORCE DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING  * BUT NOT LIMITED TO ANY WARRANTY THAT THE USE OF THE INFORMATION  * HEREIN WILL NOT INFRINGE ANY RIGHTS OR ANY IMPLIED WARRANTIES OF  * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GSSAPI_GSSAPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_GSSAPI_GSSAPI_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SSIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__ssize_t
name|ssize_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SSIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compatibility with Heimdal 1.5.1 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GSSAPI_CPP_START
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compatibility with Heimdal 1.5.1 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUILD_GSSAPI_LIB
end_ifndef

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

begin_comment
comment|/* Compatibility with Heimdal 1.5.1 */
end_comment

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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * If the platform supports the xom.h header file, it should be  * included here.  */
end_comment

begin_include
include|#
directive|include
file|<xom.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Now define the three implementation-dependent types.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_gss_ctx_id_t
modifier|*
name|gss_ctx_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_gss_cred_id_t
modifier|*
name|gss_cred_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_gss_name_t
modifier|*
name|gss_name_t
typedef|;
end_typedef

begin_comment
comment|/*  * The following type must be defined as the smallest natural  * unsigned integer supported by the platform that has at least  * 32 bits of precision.  */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|gss_uint32
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|OM_STRING
end_ifdef

begin_comment
comment|/*  * We have included the xom.h header file.  Verify that OM_uint32  * is defined correctly.  */
end_comment

begin_if
if|#
directive|if
sizeof|sizeof
argument_list|(
name|gss_uint32
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|OM_uint32
argument_list|)
end_if

begin_error
error|#
directive|error
error|Incompatible definition of OM_uint32 from xom.h
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|OM_object_identifier
name|gss_OID_desc
typedef|,
modifier|*
name|gss_OID
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * We can't use X/Open definitions, so roll our own.  */
end_comment

begin_typedef
typedef|typedef
name|gss_uint32
name|OM_uint32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|OM_uint64
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

begin_endif
endif|#
directive|endif
end_endif

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

begin_typedef
typedef|typedef
name|int
name|gss_cred_usage_t
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
comment|/*  * Define the default Quality of Protection for per-message  * services.  Note that an implementation that offers multiple  * levels of QOP may define GSS_C_QOP_DEFAULT to be either zero  * (as done here) to mean "default protection", or to a specific  * explicit QOP value.  However, a value of 0 should always be  * interpreted by a GSS-API implementation as a request for the  * default protection level.  */
end_comment

begin_define
define|#
directive|define
name|GSS_C_QOP_DEFAULT
value|0
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
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  * "\x01\x02\x01\x01"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  * infosys(1) gssapi(2) generic(1) user_name(1)}.  The constant  * GSS_C_NT_USER_NAME should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_C_NT_USER_NAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x02"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  * infosys(1) gssapi(2) generic(1) machine_uid_name(2)}.  * The constant GSS_C_NT_MACHINE_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_C_NT_MACHINE_UID_NAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x03"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  * infosys(1) gssapi(2) generic(1) string_uid_name(3)}.  * The constant GSS_C_NT_STRING_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
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
comment|/*  *   This name form shall be represented by the Object Identifier {iso(1)  *   member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  *   krb5(2) krb5_name(1)}.  The recommended symbolic name for this type  *   is "GSS_KRB5_NT_PRINCIPAL_NAME".  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_KRB5_NT_PRINCIPAL_NAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This name form shall be represented by the Object Identifier {iso(1)  * member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  * generic(1) user_name(1)}.  The recommended symbolic name for this  * type is "GSS_KRB5_NT_USER_NAME".  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_KRB5_NT_USER_NAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This name form shall be represented by the Object Identifier {iso(1)  * member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  * generic(1) machine_uid_name(2)}.  The recommended symbolic name for  * this type is "GSS_KRB5_NT_MACHINE_UID_NAME".  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_KRB5_NT_MACHINE_UID_NAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This name form shall be represented by the Object Identifier {iso(1)  * member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  * generic(1) string_uid_name(3)}.  The recommended symbolic name for  * this type is "GSS_KRB5_NT_STRING_UID_NAME".  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID
name|GSS_KRB5_NT_STRING_UID_NAME
decl_stmt|;
end_decl_stmt

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
comment|/*  * The macros that test status codes for error conditions.  * Note that the GSS_ERROR() macro has changed slightly from  * the V1 GSS-API so that it now evaluates its argument  * only once.  */
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
value|(x& ((GSS_C_CALLING_ERROR_MASK<< GSS_C_CALLING_ERROR_OFFSET) | \        (GSS_C_ROUTINE_ERROR_MASK<< GSS_C_ROUTINE_ERROR_OFFSET)))
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
define|\
value|(1ul<< (GSS_C_SUPPLEMENTARY_OFFSET + 0))
end_define

begin_define
define|#
directive|define
name|GSS_S_DUPLICATE_TOKEN
define|\
value|(1ul<< (GSS_C_SUPPLEMENTARY_OFFSET + 1))
end_define

begin_define
define|#
directive|define
name|GSS_S_OLD_TOKEN
define|\
value|(1ul<< (GSS_C_SUPPLEMENTARY_OFFSET + 2))
end_define

begin_define
define|#
directive|define
name|GSS_S_UNSEQ_TOKEN
define|\
value|(1ul<< (GSS_C_SUPPLEMENTARY_OFFSET + 3))
end_define

begin_define
define|#
directive|define
name|GSS_S_GAP_TOKEN
define|\
value|(1ul<< (GSS_C_SUPPLEMENTARY_OFFSET + 4))
end_define

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * Finally, function prototypes for the GSS-API routines.  */
name|OM_uint32
name|gss_acquire_cred
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* desired_name */
name|OM_uint32
parameter_list|,
comment|/* time_req */
specifier|const
name|gss_OID_set
parameter_list|,
comment|/* desired_mechs */
name|gss_cred_usage_t
parameter_list|,
comment|/* cred_usage */
name|gss_cred_id_t
modifier|*
parameter_list|,
comment|/* output_cred_handle */
name|gss_OID_set
modifier|*
parameter_list|,
comment|/* actual_mechs */
name|OM_uint32
modifier|*
comment|/* time_rec */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_release_cred
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_cred_id_t
modifier|*
comment|/* cred_handle */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_init_sec_context
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_cred_id_t
parameter_list|,
comment|/* initiator_cred_handle */
name|gss_ctx_id_t
modifier|*
parameter_list|,
comment|/* context_handle */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* target_name */
specifier|const
name|gss_OID
parameter_list|,
comment|/* mech_type */
name|OM_uint32
parameter_list|,
comment|/* req_flags */
name|OM_uint32
parameter_list|,
comment|/* time_req */
specifier|const
name|gss_channel_bindings_t
parameter_list|,
comment|/* input_chan_bindings */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* input_token */
name|gss_OID
modifier|*
parameter_list|,
comment|/* actual_mech_type */
name|gss_buffer_t
parameter_list|,
comment|/* output_token */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* ret_flags */
name|OM_uint32
modifier|*
comment|/* time_rec */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_accept_sec_context
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_ctx_id_t
modifier|*
parameter_list|,
comment|/* context_handle */
specifier|const
name|gss_cred_id_t
parameter_list|,
comment|/* acceptor_cred_handle */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* input_token_buffer */
specifier|const
name|gss_channel_bindings_t
parameter_list|,
comment|/* input_chan_bindings */
name|gss_name_t
modifier|*
parameter_list|,
comment|/* src_name */
name|gss_OID
modifier|*
parameter_list|,
comment|/* mech_type */
name|gss_buffer_t
parameter_list|,
comment|/* output_token */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* ret_flags */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* time_rec */
name|gss_cred_id_t
modifier|*
comment|/* delegated_cred_handle */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_process_context_token
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
specifier|const
name|gss_buffer_t
comment|/* token_buffer */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_delete_sec_context
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_ctx_id_t
modifier|*
parameter_list|,
comment|/* context_handle */
name|gss_buffer_t
comment|/* output_token */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_context_time
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|OM_uint32
modifier|*
comment|/* time_rec */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_get_mic
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|gss_qop_t
parameter_list|,
comment|/* qop_req */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* message_buffer */
name|gss_buffer_t
comment|/* message_token */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_verify_mic
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* message_buffer */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* token_buffer */
name|gss_qop_t
modifier|*
comment|/* qop_state */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_wrap
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|int
parameter_list|,
comment|/* conf_req_flag */
name|gss_qop_t
parameter_list|,
comment|/* qop_req */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* input_message_buffer */
name|int
modifier|*
parameter_list|,
comment|/* conf_state */
name|gss_buffer_t
comment|/* output_message_buffer */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_unwrap
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* input_message_buffer */
name|gss_buffer_t
parameter_list|,
comment|/* output_message_buffer */
name|int
modifier|*
parameter_list|,
comment|/* conf_state */
name|gss_qop_t
modifier|*
comment|/* qop_state */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_display_status
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|OM_uint32
parameter_list|,
comment|/* status_value */
name|int
parameter_list|,
comment|/* status_type */
specifier|const
name|gss_OID
parameter_list|,
comment|/* mech_type */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* message_context */
name|gss_buffer_t
comment|/* status_string */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_indicate_mechs
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_OID_set
modifier|*
comment|/* mech_set */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_compare_name
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* name1 */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* name2 */
name|int
modifier|*
comment|/* name_equal */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_display_name
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* input_name */
name|gss_buffer_t
parameter_list|,
comment|/* output_name_buffer */
name|gss_OID
modifier|*
comment|/* output_name_type */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_import_name
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* input_name_buffer */
specifier|const
name|gss_OID
parameter_list|,
comment|/* input_name_type */
name|gss_name_t
modifier|*
comment|/* output_name */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_export_name
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* input_name */
name|gss_buffer_t
comment|/* exported_name */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_release_name
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
modifier|*
comment|/* input_name */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_release_buffer
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_buffer_t
comment|/* buffer */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_release_oid_set
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_OID_set
modifier|*
comment|/* set */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_cred
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_cred_id_t
parameter_list|,
comment|/* cred_handle */
name|gss_name_t
modifier|*
parameter_list|,
comment|/* name */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* lifetime */
name|gss_cred_usage_t
modifier|*
parameter_list|,
comment|/* cred_usage */
name|gss_OID_set
modifier|*
comment|/* mechanisms */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_context
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|gss_name_t
modifier|*
parameter_list|,
comment|/* src_name */
name|gss_name_t
modifier|*
parameter_list|,
comment|/* targ_name */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* lifetime_rec */
name|gss_OID
modifier|*
parameter_list|,
comment|/* mech_type */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* ctx_flags */
name|int
modifier|*
parameter_list|,
comment|/* locally_initiated */
name|int
modifier|*
comment|/* open */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_wrap_size_limit
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|int
parameter_list|,
comment|/* conf_req_flag */
name|gss_qop_t
parameter_list|,
comment|/* qop_req */
name|OM_uint32
parameter_list|,
comment|/* req_output_size */
name|OM_uint32
modifier|*
comment|/* max_input_size */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_add_cred
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_cred_id_t
parameter_list|,
comment|/* input_cred_handle */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* desired_name */
specifier|const
name|gss_OID
parameter_list|,
comment|/* desired_mech */
name|gss_cred_usage_t
parameter_list|,
comment|/* cred_usage */
name|OM_uint32
parameter_list|,
comment|/* initiator_time_req */
name|OM_uint32
parameter_list|,
comment|/* acceptor_time_req */
name|gss_cred_id_t
modifier|*
parameter_list|,
comment|/* output_cred_handle */
name|gss_OID_set
modifier|*
parameter_list|,
comment|/* actual_mechs */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* initiator_time_rec */
name|OM_uint32
modifier|*
comment|/* acceptor_time_rec */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_cred_by_mech
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_cred_id_t
parameter_list|,
comment|/* cred_handle */
specifier|const
name|gss_OID
parameter_list|,
comment|/* mech_type */
name|gss_name_t
modifier|*
parameter_list|,
comment|/* name */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* initiator_lifetime */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* acceptor_lifetime */
name|gss_cred_usage_t
modifier|*
comment|/* cred_usage */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_export_sec_context
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_ctx_id_t
modifier|*
parameter_list|,
comment|/* context_handle */
name|gss_buffer_t
comment|/* interprocess_token */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_import_sec_context
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* interprocess_token */
name|gss_ctx_id_t
modifier|*
comment|/* context_handle */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_create_empty_oid_set
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_OID_set
modifier|*
comment|/* oid_set */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_add_oid_set_member
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_OID
parameter_list|,
comment|/* member_oid */
name|gss_OID_set
modifier|*
comment|/* oid_set */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_test_oid_set_member
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_OID
parameter_list|,
comment|/* member */
specifier|const
name|gss_OID_set
parameter_list|,
comment|/* set */
name|int
modifier|*
comment|/* present */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_names_for_mech
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_OID
parameter_list|,
comment|/* mechanism */
name|gss_OID_set
modifier|*
comment|/* name_types */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_mechs_for_name
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* input_name */
name|gss_OID_set
modifier|*
comment|/* mech_types */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_canonicalize_name
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* input_name */
specifier|const
name|gss_OID
parameter_list|,
comment|/* mech_type */
name|gss_name_t
modifier|*
comment|/* output_name */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_duplicate_name
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* src_name */
name|gss_name_t
modifier|*
comment|/* dest_name */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The following routines are obsolete variants of gss_get_mic,  * gss_verify_mic, gss_wrap and gss_unwrap.  They should be  * provided by GSS-API V2 implementations for backwards  * compatibility with V1 applications.  Distinct entrypoints  * (as opposed to #defines) should be provided, both to allow  * GSS-API V1 applications to link against GSS-API V2 implementations,  * and to retain the slight parameter type differences between the  * obsolete versions of these routines and their current forms.  */
end_comment

begin_function_decl
name|OM_uint32
name|gss_sign
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|int
parameter_list|,
comment|/* qop_req */
name|gss_buffer_t
parameter_list|,
comment|/* message_buffer */
name|gss_buffer_t
comment|/* message_token */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_verify
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|gss_buffer_t
parameter_list|,
comment|/* message_buffer */
name|gss_buffer_t
parameter_list|,
comment|/* token_buffer */
name|int
modifier|*
comment|/* qop_state */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_seal
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|int
parameter_list|,
comment|/* conf_req_flag */
name|int
parameter_list|,
comment|/* qop_req */
name|gss_buffer_t
parameter_list|,
comment|/* input_message_buffer */
name|int
modifier|*
parameter_list|,
comment|/* conf_state */
name|gss_buffer_t
comment|/* output_message_buffer */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_unseal
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|gss_buffer_t
parameter_list|,
comment|/* input_message_buffer */
name|gss_buffer_t
parameter_list|,
comment|/* output_message_buffer */
name|int
modifier|*
parameter_list|,
comment|/* conf_state */
name|int
modifier|*
comment|/* qop_state */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Other extensions and helper functions.  */
end_comment

begin_function_decl
name|int
name|gss_oid_equal
parameter_list|(
specifier|const
name|gss_OID
parameter_list|,
comment|/* first OID to compare */
specifier|const
name|gss_OID
comment|/* second OID to compare */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_release_oid
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor status */
name|gss_OID
modifier|*
comment|/* oid to free */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_decapsulate_token
parameter_list|(
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* mechanism independent token */
name|gss_OID
parameter_list|,
comment|/* desired mechanism */
name|gss_buffer_t
comment|/* decapsulated mechanism dependent token */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_encapsulate_token
parameter_list|(
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* mechanism dependent token */
name|gss_OID
parameter_list|,
comment|/* desired mechanism */
name|gss_buffer_t
comment|/* encapsulated mechanism independent token */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_duplicate_oid
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor status */
specifier|const
name|gss_OID
parameter_list|,
comment|/* oid to copy */
name|gss_OID
modifier|*
comment|/* result */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_oid_to_str
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor status */
name|gss_OID
parameter_list|,
comment|/* oid to convert */
name|gss_buffer_t
comment|/* buffer to contain string */
parameter_list|)
function_decl|;
end_function_decl

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

begin_define
define|#
directive|define
name|GSS_C_NO_BUFFER_SET
value|((gss_buffer_set_t) 0)
end_define

begin_function_decl
name|OM_uint32
name|gss_create_empty_buffer_set
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor status */
name|gss_buffer_set_t
modifier|*
comment|/* location for new buffer set */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_add_buffer_set_member
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor status */
name|gss_buffer_t
parameter_list|,
comment|/* buffer to add */
name|gss_buffer_set_t
modifier|*
comment|/* set to add to */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_release_buffer_set
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor status */
name|gss_buffer_set_t
modifier|*
comment|/* set to release */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_sec_context_by_oid
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
specifier|const
name|gss_OID
parameter_list|,
comment|/* desired_object */
name|gss_buffer_set_t
modifier|*
comment|/* result */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_inquire_cred_by_oid
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_cred_id_t
parameter_list|,
comment|/* cred_handle */
specifier|const
name|gss_OID
parameter_list|,
comment|/* desired_object */
name|gss_buffer_set_t
modifier|*
comment|/* result */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_set_sec_context_option
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor status */
name|gss_ctx_id_t
modifier|*
parameter_list|,
comment|/* context */
specifier|const
name|gss_OID
parameter_list|,
comment|/* option to set */
specifier|const
name|gss_buffer_t
comment|/* option value */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_set_cred_option
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor status */
name|gss_cred_id_t
modifier|*
parameter_list|,
comment|/* cred */
specifier|const
name|gss_OID
parameter_list|,
comment|/* option to set */
specifier|const
name|gss_buffer_t
comment|/* option value */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_pseudo_random
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor status */
name|gss_ctx_id_t
parameter_list|,
comment|/* context handle */
name|int
name|prf_key
parameter_list|,
comment|/* XXX */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* data to seed generator */
name|ssize_t
parameter_list|,
comment|/* amount of data required */
name|gss_buffer_t
comment|/* buffer for result */
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_UID_T_DECLARED
end_ifdef

begin_function_decl
name|OM_uint32
name|gss_pname_to_uid
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor status */
specifier|const
name|gss_name_t
name|pname
parameter_list|,
comment|/* principal name */
specifier|const
name|gss_OID
name|mech
parameter_list|,
comment|/* mechanism to query */
name|uid_t
modifier|*
name|uidp
comment|/* pointer to UID for result */
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GSSAPI_GSSAPI_H_ */
end_comment

end_unit

