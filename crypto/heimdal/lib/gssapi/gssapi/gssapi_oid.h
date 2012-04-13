begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generated file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GSSAPI_GSSAPI_OID
end_ifndef

begin_define
define|#
directive|define
name|GSSAPI_GSSAPI_OID
value|1
end_define

begin_comment
comment|/* contact Love HÃ¶rnquist Ãstrand<lha@h5l.org> for new oid arcs */
end_comment

begin_comment
comment|/*   * 1.2.752.43.13 Heimdal GSS-API Extentions   */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_copy_ccache_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_COPY_CCACHE_X
value|(&__gss_krb5_copy_ccache_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_get_tkt_flags_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_GET_TKT_FLAGS_X
value|(&__gss_krb5_get_tkt_flags_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_extract_authz_data_from_sec_context_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_EXTRACT_AUTHZ_DATA_FROM_SEC_CONTEXT_X
value|(&__gss_krb5_extract_authz_data_from_sec_context_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_compat_des3_mic_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_COMPAT_DES3_MIC_X
value|(&__gss_krb5_compat_des3_mic_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_register_acceptor_identity_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_REGISTER_ACCEPTOR_IDENTITY_X
value|(&__gss_krb5_register_acceptor_identity_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_export_lucid_context_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_EXPORT_LUCID_CONTEXT_X
value|(&__gss_krb5_export_lucid_context_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_export_lucid_context_v1_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_EXPORT_LUCID_CONTEXT_V1_X
value|(&__gss_krb5_export_lucid_context_v1_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_set_dns_canonicalize_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_SET_DNS_CANONICALIZE_X
value|(&__gss_krb5_set_dns_canonicalize_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_get_subkey_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_GET_SUBKEY_X
value|(&__gss_krb5_get_subkey_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_get_initiator_subkey_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_GET_INITIATOR_SUBKEY_X
value|(&__gss_krb5_get_initiator_subkey_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_get_acceptor_subkey_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_GET_ACCEPTOR_SUBKEY_X
value|(&__gss_krb5_get_acceptor_subkey_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_send_to_kdc_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_SEND_TO_KDC_X
value|(&__gss_krb5_send_to_kdc_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_get_authtime_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_GET_AUTHTIME_X
value|(&__gss_krb5_get_authtime_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_get_service_keyblock_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_GET_SERVICE_KEYBLOCK_X
value|(&__gss_krb5_get_service_keyblock_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_set_allowable_enctypes_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_SET_ALLOWABLE_ENCTYPES_X
value|(&__gss_krb5_set_allowable_enctypes_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_set_default_realm_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_SET_DEFAULT_REALM_X
value|(&__gss_krb5_set_default_realm_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_ccache_name_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_CCACHE_NAME_X
value|(&__gss_krb5_ccache_name_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_set_time_offset_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_SET_TIME_OFFSET_X
value|(&__gss_krb5_set_time_offset_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_get_time_offset_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_GET_TIME_OFFSET_X
value|(&__gss_krb5_get_time_offset_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_plugin_register_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_PLUGIN_REGISTER_X
value|(&__gss_krb5_plugin_register_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_ntlm_get_session_key_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_NTLM_GET_SESSION_KEY_X
value|(&__gss_ntlm_get_session_key_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_nt_ntlm_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NT_NTLM
value|(&__gss_c_nt_ntlm_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_nt_dn_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NT_DN
value|(&__gss_c_nt_dn_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_nt_principal_name_referral_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_NT_PRINCIPAL_NAME_REFERRAL
value|(&__gss_krb5_nt_principal_name_referral_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ntlm_avguest_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NTLM_AVGUEST
value|(&__gss_c_ntlm_avguest_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ntlm_v1_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NTLM_V1
value|(&__gss_c_ntlm_v1_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ntlm_v2_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NTLM_V2
value|(&__gss_c_ntlm_v2_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ntlm_session_key_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NTLM_SESSION_KEY
value|(&__gss_c_ntlm_session_key_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ntlm_force_v1_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_NTLM_FORCE_V1
value|(&__gss_c_ntlm_force_v1_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_cred_no_ci_flags_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_CRED_NO_CI_FLAGS_X
value|(&__gss_krb5_cred_no_ci_flags_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_import_cred_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_IMPORT_CRED_X
value|(&__gss_krb5_import_cred_x_oid_desc)
end_define

begin_comment
comment|/* glue for gss_inquire_saslname_for_mech */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_sasl_mech_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_SASL_MECH_NAME
value|(&__gss_c_ma_sasl_mech_name_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_mech_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_MECH_NAME
value|(&__gss_c_ma_mech_name_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_mech_description_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_MECH_DESCRIPTION
value|(&__gss_c_ma_mech_description_oid_desc)
end_define

begin_comment
comment|/* credential types */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_cred_password_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_CRED_PASSWORD
value|(&__gss_c_cred_password_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_cred_certificate_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_CRED_CERTIFICATE
value|(&__gss_c_cred_certificate_oid_desc)
end_define

begin_comment
comment|/* Heimdal mechanisms - 1.2.752.43.14 */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_sasl_digest_md5_mechanism_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_SASL_DIGEST_MD5_MECHANISM
value|(&__gss_sasl_digest_md5_mechanism_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_netlogon_mechanism_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_NETLOGON_MECHANISM
value|(&__gss_netlogon_mechanism_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_netlogon_set_session_key_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_NETLOGON_SET_SESSION_KEY_X
value|(&__gss_netlogon_set_session_key_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_netlogon_set_sign_algorithm_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_NETLOGON_SET_SIGN_ALGORITHM_X
value|(&__gss_netlogon_set_sign_algorithm_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_netlogon_nt_netbios_dns_name_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_NETLOGON_NT_NETBIOS_DNS_NAME
value|(&__gss_netlogon_nt_netbios_dns_name_oid_desc)
end_define

begin_comment
comment|/* GSS_KRB5_EXTRACT_AUTHZ_DATA_FROM_SEC_CONTEXT_X.128 */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_inq_win2k_pac_x_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_INQ_WIN2K_PAC_X
value|(&__gss_c_inq_win2k_pac_x_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_inq_sspi_session_key_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_INQ_SSPI_SESSION_KEY
value|(&__gss_c_inq_sspi_session_key_oid_desc)
end_define

begin_comment
comment|/*  * "Standard" mechs  */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_krb5_mechanism_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_KRB5_MECHANISM
value|(&__gss_krb5_mechanism_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_ntlm_mechanism_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_NTLM_MECHANISM
value|(&__gss_ntlm_mechanism_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_spnego_mechanism_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_SPNEGO_MECHANISM
value|(&__gss_spnego_mechanism_oid_desc)
end_define

begin_comment
comment|/* From Luke Howard */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_peer_has_updated_spnego_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_PEER_HAS_UPDATED_SPNEGO
value|(&__gss_c_peer_has_updated_spnego_oid_desc)
end_define

begin_comment
comment|/*  * OID mappings with name and short description and and slightly longer description  */
end_comment

begin_comment
comment|/*  * RFC5587  */
end_comment

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_mech_concrete_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_MECH_CONCRETE
value|(&__gss_c_ma_mech_concrete_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_mech_pseudo_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_MECH_PSEUDO
value|(&__gss_c_ma_mech_pseudo_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_mech_composite_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_MECH_COMPOSITE
value|(&__gss_c_ma_mech_composite_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_mech_nego_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_MECH_NEGO
value|(&__gss_c_ma_mech_nego_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_mech_glue_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_MECH_GLUE
value|(&__gss_c_ma_mech_glue_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_not_mech_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_NOT_MECH
value|(&__gss_c_ma_not_mech_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_deprecated_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_DEPRECATED
value|(&__gss_c_ma_deprecated_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_not_dflt_mech_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_NOT_DFLT_MECH
value|(&__gss_c_ma_not_dflt_mech_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_itok_framed_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_ITOK_FRAMED
value|(&__gss_c_ma_itok_framed_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_auth_init_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_AUTH_INIT
value|(&__gss_c_ma_auth_init_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_auth_targ_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_AUTH_TARG
value|(&__gss_c_ma_auth_targ_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_auth_init_init_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_AUTH_INIT_INIT
value|(&__gss_c_ma_auth_init_init_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_auth_targ_init_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_AUTH_TARG_INIT
value|(&__gss_c_ma_auth_targ_init_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_auth_init_anon_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_AUTH_INIT_ANON
value|(&__gss_c_ma_auth_init_anon_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_auth_targ_anon_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_AUTH_TARG_ANON
value|(&__gss_c_ma_auth_targ_anon_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_deleg_cred_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_DELEG_CRED
value|(&__gss_c_ma_deleg_cred_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_integ_prot_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_INTEG_PROT
value|(&__gss_c_ma_integ_prot_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_conf_prot_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_CONF_PROT
value|(&__gss_c_ma_conf_prot_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_mic_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_MIC
value|(&__gss_c_ma_mic_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_wrap_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_WRAP
value|(&__gss_c_ma_wrap_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_prot_ready_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_PROT_READY
value|(&__gss_c_ma_prot_ready_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_replay_det_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_REPLAY_DET
value|(&__gss_c_ma_replay_det_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_oos_det_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_OOS_DET
value|(&__gss_c_ma_oos_det_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_cbindings_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_CBINDINGS
value|(&__gss_c_ma_cbindings_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_pfs_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_PFS
value|(&__gss_c_ma_pfs_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_compress_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_COMPRESS
value|(&__gss_c_ma_compress_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_c_ma_ctx_trans_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_MA_CTX_TRANS
value|(&__gss_c_ma_ctx_trans_oid_desc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GSSAPI_GSSAPI_OID */
end_comment

end_unit

