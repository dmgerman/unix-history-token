begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<kgssapi/gssapi.h>
end_include

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  * "\x01\x02\x01\x01"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  * infosys(1) gssapi(2) generic(1) user_name(1)}.  The constant  * GSS_C_NT_USER_NAME should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|GSS_C_NT_USER_NAME_storage
init|=
block|{
literal|10
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
literal|"\x2a\x86\x48\x86\xf7\x12\x01\x02\x01\x01"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_USER_NAME
init|=
operator|&
name|GSS_C_NT_USER_NAME_storage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x02"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  * infosys(1) gssapi(2) generic(1) machine_uid_name(2)}.  * The constant GSS_C_NT_MACHINE_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|GSS_C_NT_MACHINE_UID_NAME_storage
init|=
block|{
literal|10
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
literal|"\x2a\x86\x48\x86\xf7\x12\x01\x02\x01\x02"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_MACHINE_UID_NAME
init|=
operator|&
name|GSS_C_NT_MACHINE_UID_NAME_storage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x03"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  * infosys(1) gssapi(2) generic(1) string_uid_name(3)}.  * The constant GSS_C_NT_STRING_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|GSS_C_NT_STRING_UID_NAME_storage
init|=
block|{
literal|10
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
literal|"\x2a\x86\x48\x86\xf7\x12\x01\x02\x01\x03"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_STRING_UID_NAME
init|=
operator|&
name|GSS_C_NT_STRING_UID_NAME_storage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\x01\x05\x06\x02"},  * corresponding to an object-identifier value of  * {iso(1) org(3) dod(6) internet(1) security(5)  * nametypes(6) gss-host-based-services(2)).  The constant  * GSS_C_NT_HOSTBASED_SERVICE_X should be initialized to point  * to that gss_OID_desc.  This is a deprecated OID value, and  * implementations wishing to support hostbased-service names  * should instead use the GSS_C_NT_HOSTBASED_SERVICE OID,  * defined below, to identify such names;  * GSS_C_NT_HOSTBASED_SERVICE_X should be accepted a synonym  * for GSS_C_NT_HOSTBASED_SERVICE when presented as an input  * parameter, but should not be emitted by GSS-API  * implementations  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|GSS_C_NT_HOSTBASED_SERVICE_X_storage
init|=
block|{
literal|6
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
literal|"\x2b\x06\x01\x05\x06\x02"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_HOSTBASED_SERVICE_X
init|=
operator|&
name|GSS_C_NT_HOSTBASED_SERVICE_X_storage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x04"}, corresponding to an  * object-identifier value of {iso(1) member-body(2)  * Unites States(840) mit(113554) infosys(1) gssapi(2)  * generic(1) service_name(4)}.  The constant  * GSS_C_NT_HOSTBASED_SERVICE should be initialized  * to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|GSS_C_NT_HOSTBASED_SERVICE_storage
init|=
block|{
literal|10
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
literal|"\x2a\x86\x48\x86\xf7\x12\x01\x02\x01\x04"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_HOSTBASED_SERVICE
init|=
operator|&
name|GSS_C_NT_HOSTBASED_SERVICE_storage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\01\x05\x06\x03"},  * corresponding to an object identifier value of  * {1(iso), 3(org), 6(dod), 1(internet), 5(security),  * 6(nametypes), 3(gss-anonymous-name)}.  The constant  * and GSS_C_NT_ANONYMOUS should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|GSS_C_NT_ANONYMOUS_storage
init|=
block|{
literal|6
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
literal|"\x2b\x06\01\x05\x06\x03"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_ANONYMOUS
init|=
operator|&
name|GSS_C_NT_ANONYMOUS_storage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\x01\x05\x06\x04"},  * corresponding to an object-identifier value of  * {1(iso), 3(org), 6(dod), 1(internet), 5(security),  * 6(nametypes), 4(gss-api-exported-name)}.  The constant  * GSS_C_NT_EXPORT_NAME should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|GSS_C_NT_EXPORT_NAME_storage
init|=
block|{
literal|6
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
literal|"\x2b\x06\x01\x05\x06\x04"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_EXPORT_NAME
init|=
operator|&
name|GSS_C_NT_EXPORT_NAME_storage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *   This name form shall be represented by the Object Identifier {iso(1)  *   member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  *   krb5(2) krb5_name(1)}.  The recommended symbolic name for this type  *   is "GSS_KRB5_NT_PRINCIPAL_NAME".  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|GSS_KRB5_NT_PRINCIPAL_NAME_storage
init|=
block|{
literal|10
block|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
literal|"\x2a\x86\x48\x86\xf7\x12\x01\x02\x02\x01"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_NT_PRINCIPAL_NAME
init|=
operator|&
name|GSS_KRB5_NT_PRINCIPAL_NAME_storage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This name form shall be represented by the Object Identifier {iso(1)  * member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  * generic(1) user_name(1)}.  The recommended symbolic name for this  * type is "GSS_KRB5_NT_USER_NAME".  */
end_comment

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_NT_USER_NAME
init|=
operator|&
name|GSS_C_NT_USER_NAME_storage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This name form shall be represented by the Object Identifier {iso(1)  * member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  * generic(1) machine_uid_name(2)}.  The recommended symbolic name for  * this type is "GSS_KRB5_NT_MACHINE_UID_NAME".  */
end_comment

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_NT_MACHINE_UID_NAME
init|=
operator|&
name|GSS_C_NT_MACHINE_UID_NAME_storage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This name form shall be represented by the Object Identifier {iso(1)  * member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  * generic(1) string_uid_name(3)}.  The recommended symbolic name for  * this type is "GSS_KRB5_NT_STRING_UID_NAME".  */
end_comment

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_NT_STRING_UID_NAME
init|=
operator|&
name|GSS_C_NT_STRING_UID_NAME_storage
decl_stmt|;
end_decl_stmt

end_unit

