begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"krb5/gsskrb5_locl.h"
end_include

begin_include
include|#
directive|include
file|<gssapi_mech.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: external.c 22128 2007-12-04 00:56:55Z lha $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x01"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) user_name(1)}.  The constant  * GSS_C_NT_USER_NAME should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_c_nt_user_name_oid_desc
init|=
block|{
literal|10
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x86\x48\x86\xf7\x12"
literal|"\x01\x02\x01\x01"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_USER_NAME
init|=
operator|&
name|gss_c_nt_user_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x02"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) machine_uid_name(2)}.  * The constant GSS_C_NT_MACHINE_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_c_nt_machine_uid_name_oid_desc
init|=
block|{
literal|10
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x86\x48\x86\xf7\x12"
literal|"\x01\x02\x01\x02"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_MACHINE_UID_NAME
init|=
operator|&
name|gss_c_nt_machine_uid_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x03"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) string_uid_name(3)}.  * The constant GSS_C_NT_STRING_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_c_nt_string_uid_name_oid_desc
init|=
block|{
literal|10
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x86\x48\x86\xf7\x12"
literal|"\x01\x02\x01\x03"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_STRING_UID_NAME
init|=
operator|&
name|gss_c_nt_string_uid_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\x01\x05\x06\x02"},  * corresponding to an object-identifier value of  * {iso(1) org(3) dod(6) internet(1) security(5)  * nametypes(6) gss-host-based-services(2)).  The constant  * GSS_C_NT_HOSTBASED_SERVICE_X should be initialized to point  * to that gss_OID_desc.  This is a deprecated OID value, and  * implementations wishing to support hostbased-service names  * should instead use the GSS_C_NT_HOSTBASED_SERVICE OID,  * defined below, to identify such names;  * GSS_C_NT_HOSTBASED_SERVICE_X should be accepted a synonym  * for GSS_C_NT_HOSTBASED_SERVICE when presented as an input  * parameter, but should not be emitted by GSS-API  * implementations  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_c_nt_hostbased_service_x_oid_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2b\x06\x01\x05\x06\x02"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_HOSTBASED_SERVICE_X
init|=
operator|&
name|gss_c_nt_hostbased_service_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x04"}, corresponding to an  * object-identifier value of {iso(1) member-body(2)  * Unites States(840) mit(113554) infosys(1) gssapi(2)  * generic(1) service_name(4)}.  The constant  * GSS_C_NT_HOSTBASED_SERVICE should be initialized  * to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_c_nt_hostbased_service_oid_desc
init|=
block|{
literal|10
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x86\x48\x86\xf7\x12"
literal|"\x01\x02\x01\x04"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_HOSTBASED_SERVICE
init|=
operator|&
name|gss_c_nt_hostbased_service_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\01\x05\x06\x03"},  * corresponding to an object identifier value of  * {1(iso), 3(org), 6(dod), 1(internet), 5(security),  * 6(nametypes), 3(gss-anonymous-name)}.  The constant  * and GSS_C_NT_ANONYMOUS should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_c_nt_anonymous_oid_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2b\x06\01\x05\x06\x03"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_ANONYMOUS
init|=
operator|&
name|gss_c_nt_anonymous_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\x01\x05\x06\x04"},  * corresponding to an object-identifier value of  * {1(iso), 3(org), 6(dod), 1(internet), 5(security),  * 6(nametypes), 4(gss-api-exported-name)}.  The constant  * GSS_C_NT_EXPORT_NAME should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_c_nt_export_name_oid_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2b\x06\x01\x05\x06\x04"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_NT_EXPORT_NAME
init|=
operator|&
name|gss_c_nt_export_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *   This name form shall be represented by the Object Identifier {iso(1)  *   member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  *   krb5(2) krb5_name(1)}.  The recommended symbolic name for this type  *   is "GSS_KRB5_NT_PRINCIPAL_NAME".  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_nt_principal_name_oid_desc
init|=
block|{
literal|10
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x86\x48\x86\xf7\x12\x01\x02\x02\x01"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_NT_PRINCIPAL_NAME
init|=
operator|&
name|gss_krb5_nt_principal_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *   This name form shall be represented by the Object Identifier {iso(1)  *   member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  *   generic(1) user_name(1)}.  The recommended symbolic name for this  *   type is "GSS_KRB5_NT_USER_NAME".  */
end_comment

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_NT_USER_NAME
init|=
operator|&
name|gss_c_nt_user_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *   This name form shall be represented by the Object Identifier {iso(1)  *   member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  *   generic(1) machine_uid_name(2)}.  The recommended symbolic name for  *   this type is "GSS_KRB5_NT_MACHINE_UID_NAME".  */
end_comment

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_NT_MACHINE_UID_NAME
init|=
operator|&
name|gss_c_nt_machine_uid_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *   This name form shall be represented by the Object Identifier {iso(1)  *   member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  *   generic(1) string_uid_name(3)}.  The recommended symbolic name for  *   this type is "GSS_KRB5_NT_STRING_UID_NAME".  */
end_comment

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_NT_STRING_UID_NAME
init|=
operator|&
name|gss_c_nt_string_uid_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *   To support ongoing experimentation, testing, and evolution of the  *   specification, the Kerberos V5 GSS-API mechanism as defined in this  *   and any successor memos will be identified with the following Object  *   Identifier, as defined in RFC-1510, until the specification is  *   advanced to the level of Proposed Standard RFC:  *  *   {iso(1), org(3), dod(5), internet(1), security(5), kerberosv5(2)}  *  *   Upon advancement to the level of Proposed Standard RFC, the Kerberos  *   V5 GSS-API mechanism will be identified by an Object Identifier  *   having the value:  *  *   {iso(1) member-body(2) United States(840) mit(113554) infosys(1)  *   gssapi(2) krb5(2)}  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* This is the old OID */
end_comment

begin_endif
unit|static gss_OID_desc gss_krb5_mechanism_oid_desc = {5, rk_UNCONST("\x2b\x05\x01\x05\x02")};
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_mechanism_oid_desc
init|=
block|{
literal|9
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x86\x48\x86\xf7\x12\x01\x02\x02"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_MECHANISM
init|=
operator|&
name|gss_krb5_mechanism_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * draft-ietf-cat-iakerb-09, IAKERB:  *   The mechanism ID for IAKERB proxy GSS-API Kerberos, in accordance  *   with the mechanism proposed by SPNEGO [7] for negotiating protocol  *   variations, is:  {iso(1) org(3) dod(6) internet(1) security(5)  *   mechanisms(5) iakerb(10) iakerbProxyProtocol(1)}.  The proposed  *   mechanism ID for IAKERB minimum messages GSS-API Kerberos, in  *   accordance with the mechanism proposed by SPNEGO for negotiating  *   protocol variations, is: {iso(1) org(3) dod(6) internet(1)  *   security(5) mechanisms(5) iakerb(10)  *   iakerbMinimumMessagesProtocol(2)}.  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_iakerb_proxy_mechanism_oid_desc
init|=
block|{
literal|7
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2b\x06\x01\x05\x05\x0a\x01"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_IAKERB_PROXY_MECHANISM
init|=
operator|&
name|gss_iakerb_proxy_mechanism_oid_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_iakerb_min_msg_mechanism_oid_desc
init|=
block|{
literal|7
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2b\x06\x01\x05\x05\x0a\x02"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_IAKERB_MIN_MSG_MECHANISM
init|=
operator|&
name|gss_iakerb_min_msg_mechanism_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_c_peer_has_updated_spnego_oid_desc
init|=
block|{
literal|9
block|,
operator|(
name|void
operator|*
operator|)
literal|"\x2b\x06\x01\x04\x01\xa9\x4a\x13\x05"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_C_PEER_HAS_UPDATED_SPNEGO
init|=
operator|&
name|gss_c_peer_has_updated_spnego_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * 1.2.752.43.13 Heimdal GSS-API Extentions  */
end_comment

begin_comment
comment|/* 1.2.752.43.13.1 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_copy_ccache_x_oid_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x01"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_COPY_CCACHE_X
init|=
operator|&
name|gss_krb5_copy_ccache_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.2 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_get_tkt_flags_x_oid_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x02"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_GET_TKT_FLAGS_X
init|=
operator|&
name|gss_krb5_get_tkt_flags_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.3 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_extract_authz_data_from_sec_context_x_oid_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x03"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_EXTRACT_AUTHZ_DATA_FROM_SEC_CONTEXT_X
init|=
operator|&
name|gss_krb5_extract_authz_data_from_sec_context_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.4 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_compat_des3_mic_x_oid_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x04"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_COMPAT_DES3_MIC_X
init|=
operator|&
name|gss_krb5_compat_des3_mic_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.5 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_register_acceptor_identity_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x05"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_REGISTER_ACCEPTOR_IDENTITY_X
init|=
operator|&
name|gss_krb5_register_acceptor_identity_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.6 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_export_lucid_context_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x06"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_EXPORT_LUCID_CONTEXT_X
init|=
operator|&
name|gss_krb5_export_lucid_context_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.6.1 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_export_lucid_context_v1_x_desc
init|=
block|{
literal|7
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x06\x01"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_EXPORT_LUCID_CONTEXT_V1_X
init|=
operator|&
name|gss_krb5_export_lucid_context_v1_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.7 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_set_dns_canonicalize_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x07"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_SET_DNS_CANONICALIZE_X
init|=
operator|&
name|gss_krb5_set_dns_canonicalize_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.8 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_get_subkey_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x08"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_GET_SUBKEY_X
init|=
operator|&
name|gss_krb5_get_subkey_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.9 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_get_initiator_subkey_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x09"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_GET_INITIATOR_SUBKEY_X
init|=
operator|&
name|gss_krb5_get_initiator_subkey_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.10 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_get_acceptor_subkey_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x0a"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_GET_ACCEPTOR_SUBKEY_X
init|=
operator|&
name|gss_krb5_get_acceptor_subkey_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.11 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_send_to_kdc_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x0b"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_SEND_TO_KDC_X
init|=
operator|&
name|gss_krb5_send_to_kdc_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.12 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_get_authtime_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x0c"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_GET_AUTHTIME_X
init|=
operator|&
name|gss_krb5_get_authtime_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.13 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_get_service_keyblock_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x0d"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_GET_SERVICE_KEYBLOCK_X
init|=
operator|&
name|gss_krb5_get_service_keyblock_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.14 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_set_allowable_enctypes_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x0e"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_SET_ALLOWABLE_ENCTYPES_X
init|=
operator|&
name|gss_krb5_set_allowable_enctypes_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.15 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_set_default_realm_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x0f"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_SET_DEFAULT_REALM_X
init|=
operator|&
name|gss_krb5_set_default_realm_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.13.16 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_krb5_ccache_name_x_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0d\x10"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_KRB5_CCACHE_NAME_X
init|=
operator|&
name|gss_krb5_ccache_name_x_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2.752.43.14.1 */
end_comment

begin_decl_stmt
specifier|static
name|gss_OID_desc
name|gss_sasl_digest_md5_mechanism_desc
init|=
block|{
literal|6
block|,
name|rk_UNCONST
argument_list|(
literal|"\x2a\x85\x70\x2b\x0e\x01"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gss_OID
name|GSS_SASL_DIGEST_MD5_MECHANISM
init|=
operator|&
name|gss_sasl_digest_md5_mechanism_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Context for krb5 calls.  */
end_comment

begin_comment
comment|/*  *  */
end_comment

begin_decl_stmt
specifier|static
name|gssapi_mech_interface_desc
name|krb5_mech
init|=
block|{
name|GMI_VERSION
block|,
literal|"kerberos 5"
block|,
block|{
literal|9
block|,
literal|"\x2a\x86\x48\x86\xf7\x12\x01\x02\x02"
block|}
block|,
name|_gsskrb5_acquire_cred
block|,
name|_gsskrb5_release_cred
block|,
name|_gsskrb5_init_sec_context
block|,
name|_gsskrb5_accept_sec_context
block|,
name|_gsskrb5_process_context_token
block|,
name|_gsskrb5_delete_sec_context
block|,
name|_gsskrb5_context_time
block|,
name|_gsskrb5_get_mic
block|,
name|_gsskrb5_verify_mic
block|,
name|_gsskrb5_wrap
block|,
name|_gsskrb5_unwrap
block|,
name|_gsskrb5_display_status
block|,
name|_gsskrb5_indicate_mechs
block|,
name|_gsskrb5_compare_name
block|,
name|_gsskrb5_display_name
block|,
name|_gsskrb5_import_name
block|,
name|_gsskrb5_export_name
block|,
name|_gsskrb5_release_name
block|,
name|_gsskrb5_inquire_cred
block|,
name|_gsskrb5_inquire_context
block|,
name|_gsskrb5_wrap_size_limit
block|,
name|_gsskrb5_add_cred
block|,
name|_gsskrb5_inquire_cred_by_mech
block|,
name|_gsskrb5_export_sec_context
block|,
name|_gsskrb5_import_sec_context
block|,
name|_gsskrb5_inquire_names_for_mech
block|,
name|_gsskrb5_inquire_mechs_for_name
block|,
name|_gsskrb5_canonicalize_name
block|,
name|_gsskrb5_duplicate_name
block|,
name|_gsskrb5_inquire_sec_context_by_oid
block|,
name|_gsskrb5_inquire_cred_by_oid
block|,
name|_gsskrb5_set_sec_context_option
block|,
name|_gsskrb5_set_cred_option
block|,
name|_gsskrb5_pseudo_random
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|gssapi_mech_interface
name|__gss_krb5_initialize
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|krb5_mech
return|;
block|}
end_function

end_unit

