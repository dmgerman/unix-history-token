begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2000 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"gsskrb5_locl.h"
end_include

begin_include
include|#
directive|include
file|<gssapi_mech.h>
end_include

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x01"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) user_name(1)}.  The constant  * GSS_C_NT_USER_NAME should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_c_nt_user_name_oid_desc
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

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x02"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) machine_uid_name(2)}.  * The constant GSS_C_NT_MACHINE_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_c_nt_machine_uid_name_oid_desc
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

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x03"},  * corresponding to an object-identifier value of  * {iso(1) member-body(2) United States(840) mit(113554)  *  infosys(1) gssapi(2) generic(1) string_uid_name(3)}.  * The constant GSS_C_NT_STRING_UID_NAME should be  * initialized to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_c_nt_string_uid_name_oid_desc
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

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\x01\x05\x06\x02"},  * corresponding to an object-identifier value of  * {iso(1) org(3) dod(6) internet(1) security(5)  * nametypes(6) gss-host-based-services(2)).  The constant  * GSS_C_NT_HOSTBASED_SERVICE_X should be initialized to point  * to that gss_OID_desc.  This is a deprecated OID value, and  * implementations wishing to support hostbased-service names  * should instead use the GSS_C_NT_HOSTBASED_SERVICE OID,  * defined below, to identify such names;  * GSS_C_NT_HOSTBASED_SERVICE_X should be accepted a synonym  * for GSS_C_NT_HOSTBASED_SERVICE when presented as an input  * parameter, but should not be emitted by GSS-API  * implementations  */
end_comment

begin_decl_stmt
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_c_nt_hostbased_service_x_oid_desc
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

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {10, (void *)"\x2a\x86\x48\x86\xf7\x12"  *              "\x01\x02\x01\x04"}, corresponding to an  * object-identifier value of {iso(1) member-body(2)  * Unites States(840) mit(113554) infosys(1) gssapi(2)  * generic(1) service_name(4)}.  The constant  * GSS_C_NT_HOSTBASED_SERVICE should be initialized  * to point to that gss_OID_desc.  */
end_comment

begin_decl_stmt
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_c_nt_hostbased_service_oid_desc
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

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\01\x05\x06\x03"},  * corresponding to an object identifier value of  * {1(iso), 3(org), 6(dod), 1(internet), 5(security),  * 6(nametypes), 3(gss-anonymous-name)}.  The constant  * and GSS_C_NT_ANONYMOUS should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_c_nt_anonymous_oid_desc
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

begin_comment
comment|/*  * The implementation must reserve static storage for a  * gss_OID_desc object containing the value  * {6, (void *)"\x2b\x06\x01\x05\x06\x04"},  * corresponding to an object-identifier value of  * {1(iso), 3(org), 6(dod), 1(internet), 5(security),  * 6(nametypes), 4(gss-api-exported-name)}.  The constant  * GSS_C_NT_EXPORT_NAME should be initialized to point  * to that gss_OID_desc.  */
end_comment

begin_decl_stmt
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_c_nt_export_name_oid_desc
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

begin_comment
comment|/*  *   This name form shall be represented by the Object Identifier {iso(1)  *   member-body(2) United States(840) mit(113554) infosys(1) gssapi(2)  *   krb5(2) krb5_name(1)}.  The recommended symbolic name for this type  *   is "GSS_KRB5_NT_PRINCIPAL_NAME".  */
end_comment

begin_decl_stmt
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_krb5_nt_principal_name_oid_desc
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

begin_comment
comment|/*  * draft-ietf-cat-iakerb-09, IAKERB:  *   The mechanism ID for IAKERB proxy GSS-API Kerberos, in accordance  *   with the mechanism proposed by SPNEGO [7] for negotiating protocol  *   variations, is:  {iso(1) org(3) dod(6) internet(1) security(5)  *   mechanisms(5) iakerb(10) iakerbProxyProtocol(1)}.  The proposed  *   mechanism ID for IAKERB minimum messages GSS-API Kerberos, in  *   accordance with the mechanism proposed by SPNEGO for negotiating  *   protocol variations, is: {iso(1) org(3) dod(6) internet(1)  *   security(5) mechanisms(5) iakerb(10)  *   iakerbMinimumMessagesProtocol(2)}.  */
end_comment

begin_decl_stmt
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_iakerb_proxy_mechanism_oid_desc
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
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_iakerb_min_msg_mechanism_oid_desc
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

begin_comment
comment|/*  * Context for krb5 calls.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static gss_mo_desc krb5_mo[] = {     { 	GSS_C_MA_SASL_MECH_NAME, 	GSS_MO_MA, 	"SASL mech name", 	rk_UNCONST("GS2-KRB5"), 	_gss_mo_get_ctx_as_string, 	NULL     },     { 	GSS_C_MA_MECH_NAME, 	GSS_MO_MA, 	"Mechanism name", 	rk_UNCONST("KRB5"), 	_gss_mo_get_ctx_as_string, 	NULL     },     { 	GSS_C_MA_MECH_DESCRIPTION, 	GSS_MO_MA, 	"Mechanism description", 	rk_UNCONST("Heimdal Kerberos 5 mech"), 	_gss_mo_get_ctx_as_string, 	NULL     },     { 	GSS_C_MA_MECH_CONCRETE, 	GSS_MO_MA     },     { 	GSS_C_MA_ITOK_FRAMED, 	GSS_MO_MA     },     { 	GSS_C_MA_AUTH_INIT, 	GSS_MO_MA     },     { 	GSS_C_MA_AUTH_TARG, 	GSS_MO_MA     },     { 	GSS_C_MA_AUTH_INIT_ANON, 	GSS_MO_MA     },     { 	GSS_C_MA_DELEG_CRED, 	GSS_MO_MA     },     { 	GSS_C_MA_INTEG_PROT, 	GSS_MO_MA     },     { 	GSS_C_MA_CONF_PROT, 	GSS_MO_MA     },     { 	GSS_C_MA_MIC, 	GSS_MO_MA     },     { 	GSS_C_MA_WRAP, 	GSS_MO_MA     },     { 	GSS_C_MA_PROT_READY, 	GSS_MO_MA     },     { 	GSS_C_MA_REPLAY_DET, 	GSS_MO_MA     },     { 	GSS_C_MA_OOS_DET, 	GSS_MO_MA     },     { 	GSS_C_MA_CBINDINGS, 	GSS_MO_MA     },     { 	GSS_C_MA_PFS, 	GSS_MO_MA     },     { 	GSS_C_MA_CTX_TRANS, 	GSS_MO_MA     } };
endif|#
directive|endif
end_endif

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
name|rk_UNCONST
argument_list|(
literal|"\x2a\x86\x48\x86\xf7\x12\x01\x02\x02"
argument_list|)
block|}
block|,
literal|0
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
block|,
if|#
directive|if
literal|0
block|_gk_wrap_iov,     _gk_unwrap_iov,     _gk_wrap_iov_length,
else|#
directive|else
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
endif|#
directive|endif
name|_gsskrb5_store_cred
block|,
name|_gsskrb5_export_cred
block|,
name|_gsskrb5_import_cred
block|,
name|_gsskrb5_acquire_cred_ext
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
if|#
directive|if
literal|0
block|krb5_mo,     sizeof(krb5_mo) / sizeof(krb5_mo[0]),
else|#
directive|else
name|NULL
block|,
literal|0
block|,
endif|#
directive|endif
name|_gsskrb5_pname_to_uid
block|,
name|_gsskrb5_authorize_localname
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
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

