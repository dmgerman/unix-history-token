begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ====================================================================  * Copyright (c) 1999 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_SYMHACKS_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_SYMHACKS_H
end_define

begin_include
include|#
directive|include
file|<openssl/e_os2.h>
end_include

begin_comment
comment|/* Hacks to solve the problem with linkers incapable of handling very long    symbol names.  In the case of VMS, the limit is 31 characters on VMS for    VAX. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_SYS_VMS
end_ifdef

begin_comment
comment|/* Hack a long name in crypto/ex_data.c */
end_comment

begin_undef
undef|#
directive|undef
name|CRYPTO_get_ex_data_implementation
end_undef

begin_define
define|#
directive|define
name|CRYPTO_get_ex_data_implementation
value|CRYPTO_get_ex_data_impl
end_define

begin_undef
undef|#
directive|undef
name|CRYPTO_set_ex_data_implementation
end_undef

begin_define
define|#
directive|define
name|CRYPTO_set_ex_data_implementation
value|CRYPTO_set_ex_data_impl
end_define

begin_comment
comment|/* Hack a long name in crypto/asn1/a_mbstr.c */
end_comment

begin_undef
undef|#
directive|undef
name|ASN1_STRING_set_default_mask_asc
end_undef

begin_define
define|#
directive|define
name|ASN1_STRING_set_default_mask_asc
value|ASN1_STRING_set_def_mask_asc
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* No longer needed, since safestack macro magic does the job */
end_comment

begin_comment
comment|/* Hack the names created with DECLARE_ASN1_SET_OF(PKCS7_SIGNER_INFO) */
end_comment

begin_undef
undef|#
directive|undef
name|i2d_ASN1_SET_OF_PKCS7_SIGNER_INFO
end_undef

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_PKCS7_SIGNER_INFO
value|i2d_ASN1_SET_OF_PKCS7_SIGINF
end_define

begin_undef
undef|#
directive|undef
name|d2i_ASN1_SET_OF_PKCS7_SIGNER_INFO
end_undef

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_PKCS7_SIGNER_INFO
value|d2i_ASN1_SET_OF_PKCS7_SIGINF
end_define

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
comment|/* No longer needed, since safestack macro magic does the job */
end_comment

begin_comment
comment|/* Hack the names created with DECLARE_ASN1_SET_OF(PKCS7_RECIP_INFO) */
end_comment

begin_undef
undef|#
directive|undef
name|i2d_ASN1_SET_OF_PKCS7_RECIP_INFO
end_undef

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_PKCS7_RECIP_INFO
value|i2d_ASN1_SET_OF_PKCS7_RECINF
end_define

begin_undef
undef|#
directive|undef
name|d2i_ASN1_SET_OF_PKCS7_RECIP_INFO
end_undef

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_PKCS7_RECIP_INFO
value|d2i_ASN1_SET_OF_PKCS7_RECINF
end_define

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
comment|/* No longer needed, since safestack macro magic does the job */
end_comment

begin_comment
comment|/* Hack the names created with DECLARE_ASN1_SET_OF(ACCESS_DESCRIPTION) */
end_comment

begin_undef
undef|#
directive|undef
name|i2d_ASN1_SET_OF_ACCESS_DESCRIPTION
end_undef

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_ACCESS_DESCRIPTION
value|i2d_ASN1_SET_OF_ACC_DESC
end_define

begin_undef
undef|#
directive|undef
name|d2i_ASN1_SET_OF_ACCESS_DESCRIPTION
end_undef

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_ACCESS_DESCRIPTION
value|d2i_ASN1_SET_OF_ACC_DESC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Hack the names created with DECLARE_PEM_rw(NETSCAPE_CERT_SEQUENCE) */
end_comment

begin_undef
undef|#
directive|undef
name|PEM_read_NETSCAPE_CERT_SEQUENCE
end_undef

begin_define
define|#
directive|define
name|PEM_read_NETSCAPE_CERT_SEQUENCE
value|PEM_read_NS_CERT_SEQ
end_define

begin_undef
undef|#
directive|undef
name|PEM_write_NETSCAPE_CERT_SEQUENCE
end_undef

begin_define
define|#
directive|define
name|PEM_write_NETSCAPE_CERT_SEQUENCE
value|PEM_write_NS_CERT_SEQ
end_define

begin_undef
undef|#
directive|undef
name|PEM_read_bio_NETSCAPE_CERT_SEQUENCE
end_undef

begin_define
define|#
directive|define
name|PEM_read_bio_NETSCAPE_CERT_SEQUENCE
value|PEM_read_bio_NS_CERT_SEQ
end_define

begin_undef
undef|#
directive|undef
name|PEM_write_bio_NETSCAPE_CERT_SEQUENCE
end_undef

begin_define
define|#
directive|define
name|PEM_write_bio_NETSCAPE_CERT_SEQUENCE
value|PEM_write_bio_NS_CERT_SEQ
end_define

begin_undef
undef|#
directive|undef
name|PEM_write_cb_bio_NETSCAPE_CERT_SEQUENCE
end_undef

begin_define
define|#
directive|define
name|PEM_write_cb_bio_NETSCAPE_CERT_SEQUENCE
value|PEM_write_cb_bio_NS_CERT_SEQ
end_define

begin_comment
comment|/* Hack the names created with DECLARE_PEM_rw(PKCS8_PRIV_KEY_INFO) */
end_comment

begin_undef
undef|#
directive|undef
name|PEM_read_PKCS8_PRIV_KEY_INFO
end_undef

begin_define
define|#
directive|define
name|PEM_read_PKCS8_PRIV_KEY_INFO
value|PEM_read_P8_PRIV_KEY_INFO
end_define

begin_undef
undef|#
directive|undef
name|PEM_write_PKCS8_PRIV_KEY_INFO
end_undef

begin_define
define|#
directive|define
name|PEM_write_PKCS8_PRIV_KEY_INFO
value|PEM_write_P8_PRIV_KEY_INFO
end_define

begin_undef
undef|#
directive|undef
name|PEM_read_bio_PKCS8_PRIV_KEY_INFO
end_undef

begin_define
define|#
directive|define
name|PEM_read_bio_PKCS8_PRIV_KEY_INFO
value|PEM_read_bio_P8_PRIV_KEY_INFO
end_define

begin_undef
undef|#
directive|undef
name|PEM_write_bio_PKCS8_PRIV_KEY_INFO
end_undef

begin_define
define|#
directive|define
name|PEM_write_bio_PKCS8_PRIV_KEY_INFO
value|PEM_write_bio_P8_PRIV_KEY_INFO
end_define

begin_undef
undef|#
directive|undef
name|PEM_write_cb_bio_PKCS8_PRIV_KEY_INFO
end_undef

begin_define
define|#
directive|define
name|PEM_write_cb_bio_PKCS8_PRIV_KEY_INFO
value|PEM_wrt_cb_bio_P8_PRIV_KEY_INFO
end_define

begin_comment
comment|/* Hack other PEM names */
end_comment

begin_undef
undef|#
directive|undef
name|PEM_write_bio_PKCS8PrivateKey_nid
end_undef

begin_define
define|#
directive|define
name|PEM_write_bio_PKCS8PrivateKey_nid
value|PEM_write_bio_PKCS8PrivKey_nid
end_define

begin_comment
comment|/* Hack some long X509 names */
end_comment

begin_undef
undef|#
directive|undef
name|X509_REVOKED_get_ext_by_critical
end_undef

begin_define
define|#
directive|define
name|X509_REVOKED_get_ext_by_critical
value|X509_REVOKED_get_ext_by_critic
end_define

begin_comment
comment|/* Hack some long CRYPTO names */
end_comment

begin_undef
undef|#
directive|undef
name|CRYPTO_set_dynlock_destroy_callback
end_undef

begin_define
define|#
directive|define
name|CRYPTO_set_dynlock_destroy_callback
value|CRYPTO_set_dynlock_destroy_cb
end_define

begin_undef
undef|#
directive|undef
name|CRYPTO_set_dynlock_create_callback
end_undef

begin_define
define|#
directive|define
name|CRYPTO_set_dynlock_create_callback
value|CRYPTO_set_dynlock_create_cb
end_define

begin_undef
undef|#
directive|undef
name|CRYPTO_set_dynlock_lock_callback
end_undef

begin_define
define|#
directive|define
name|CRYPTO_set_dynlock_lock_callback
value|CRYPTO_set_dynlock_lock_cb
end_define

begin_undef
undef|#
directive|undef
name|CRYPTO_get_dynlock_lock_callback
end_undef

begin_define
define|#
directive|define
name|CRYPTO_get_dynlock_lock_callback
value|CRYPTO_get_dynlock_lock_cb
end_define

begin_undef
undef|#
directive|undef
name|CRYPTO_get_dynlock_destroy_callback
end_undef

begin_define
define|#
directive|define
name|CRYPTO_get_dynlock_destroy_callback
value|CRYPTO_get_dynlock_destroy_cb
end_define

begin_undef
undef|#
directive|undef
name|CRYPTO_get_dynlock_create_callback
end_undef

begin_define
define|#
directive|define
name|CRYPTO_get_dynlock_create_callback
value|CRYPTO_get_dynlock_create_cb
end_define

begin_undef
undef|#
directive|undef
name|CRYPTO_set_locked_mem_ex_functions
end_undef

begin_define
define|#
directive|define
name|CRYPTO_set_locked_mem_ex_functions
value|CRYPTO_set_locked_mem_ex_funcs
end_define

begin_undef
undef|#
directive|undef
name|CRYPTO_get_locked_mem_ex_functions
end_undef

begin_define
define|#
directive|define
name|CRYPTO_get_locked_mem_ex_functions
value|CRYPTO_get_locked_mem_ex_funcs
end_define

begin_comment
comment|/* Hack some long SSL names */
end_comment

begin_undef
undef|#
directive|undef
name|SSL_CTX_set_default_verify_paths
end_undef

begin_define
define|#
directive|define
name|SSL_CTX_set_default_verify_paths
value|SSL_CTX_set_def_verify_paths
end_define

begin_undef
undef|#
directive|undef
name|SSL_get_ex_data_X509_STORE_CTX_idx
end_undef

begin_define
define|#
directive|define
name|SSL_get_ex_data_X509_STORE_CTX_idx
value|SSL_get_ex_d_X509_STORE_CTX_idx
end_define

begin_undef
undef|#
directive|undef
name|SSL_add_file_cert_subjects_to_stack
end_undef

begin_define
define|#
directive|define
name|SSL_add_file_cert_subjects_to_stack
value|SSL_add_file_cert_subjs_to_stk
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* This function is not defined i VMS. */
end_comment

begin_undef
undef|#
directive|undef
name|SSL_add_dir_cert_subjects_to_stack
end_undef

begin_define
define|#
directive|define
name|SSL_add_dir_cert_subjects_to_stack
value|SSL_add_dir_cert_subjs_to_stk
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|SSL_CTX_use_certificate_chain_file
end_undef

begin_define
define|#
directive|define
name|SSL_CTX_use_certificate_chain_file
value|SSL_CTX_use_cert_chain_file
end_define

begin_undef
undef|#
directive|undef
name|SSL_CTX_set_cert_verify_callback
end_undef

begin_define
define|#
directive|define
name|SSL_CTX_set_cert_verify_callback
value|SSL_CTX_set_cert_verify_cb
end_define

begin_undef
undef|#
directive|undef
name|SSL_CTX_set_default_passwd_cb_userdata
end_undef

begin_define
define|#
directive|define
name|SSL_CTX_set_default_passwd_cb_userdata
value|SSL_CTX_set_def_passwd_cb_ud
end_define

begin_comment
comment|/* Hack some long ENGINE names */
end_comment

begin_undef
undef|#
directive|undef
name|ENGINE_get_default_BN_mod_exp_crt
end_undef

begin_define
define|#
directive|define
name|ENGINE_get_default_BN_mod_exp_crt
value|ENGINE_get_def_BN_mod_exp_crt
end_define

begin_undef
undef|#
directive|undef
name|ENGINE_set_default_BN_mod_exp_crt
end_undef

begin_define
define|#
directive|define
name|ENGINE_set_default_BN_mod_exp_crt
value|ENGINE_set_def_BN_mod_exp_crt
end_define

begin_undef
undef|#
directive|undef
name|ENGINE_set_load_privkey_function
end_undef

begin_define
define|#
directive|define
name|ENGINE_set_load_privkey_function
value|ENGINE_set_load_privkey_fn
end_define

begin_undef
undef|#
directive|undef
name|ENGINE_get_load_privkey_function
end_undef

begin_define
define|#
directive|define
name|ENGINE_get_load_privkey_function
value|ENGINE_get_load_privkey_fn
end_define

begin_comment
comment|/* Hack some long OCSP names */
end_comment

begin_undef
undef|#
directive|undef
name|OCSP_REQUEST_get_ext_by_critical
end_undef

begin_define
define|#
directive|define
name|OCSP_REQUEST_get_ext_by_critical
value|OCSP_REQUEST_get_ext_by_crit
end_define

begin_undef
undef|#
directive|undef
name|OCSP_BASICRESP_get_ext_by_critical
end_undef

begin_define
define|#
directive|define
name|OCSP_BASICRESP_get_ext_by_critical
value|OCSP_BASICRESP_get_ext_by_crit
end_define

begin_undef
undef|#
directive|undef
name|OCSP_SINGLERESP_get_ext_by_critical
end_undef

begin_define
define|#
directive|define
name|OCSP_SINGLERESP_get_ext_by_critical
value|OCSP_SINGLERESP_get_ext_by_crit
end_define

begin_comment
comment|/* Hack some long DES names */
end_comment

begin_undef
undef|#
directive|undef
name|_ossl_old_des_ede3_cfb64_encrypt
end_undef

begin_define
define|#
directive|define
name|_ossl_old_des_ede3_cfb64_encrypt
value|_ossl_odes_ede3_cfb64_encrypt
end_define

begin_undef
undef|#
directive|undef
name|_ossl_old_des_ede3_ofb64_encrypt
end_undef

begin_define
define|#
directive|define
name|_ossl_old_des_ede3_ofb64_encrypt
value|_ossl_odes_ede3_ofb64_encrypt
end_define

begin_comment
comment|/* Hack some long EVP names */
end_comment

begin_undef
undef|#
directive|undef
name|OPENSSL_add_all_algorithms_noconf
end_undef

begin_define
define|#
directive|define
name|OPENSSL_add_all_algorithms_noconf
value|OPENSSL_add_all_algo_noconf
end_define

begin_undef
undef|#
directive|undef
name|OPENSSL_add_all_algorithms_conf
end_undef

begin_define
define|#
directive|define
name|OPENSSL_add_all_algorithms_conf
value|OPENSSL_add_all_algo_conf
end_define

begin_comment
comment|/* Hack some long EC names */
end_comment

begin_undef
undef|#
directive|undef
name|EC_POINT_set_Jprojective_coordinates_GFp
end_undef

begin_define
define|#
directive|define
name|EC_POINT_set_Jprojective_coordinates_GFp
define|\
value|EC_POINT_set_Jproj_coords_GFp
end_define

begin_undef
undef|#
directive|undef
name|EC_POINT_get_Jprojective_coordinates_GFp
end_undef

begin_define
define|#
directive|define
name|EC_POINT_get_Jprojective_coordinates_GFp
define|\
value|EC_POINT_get_Jproj_coords_GFp
end_define

begin_undef
undef|#
directive|undef
name|EC_POINT_set_affine_coordinates_GFp
end_undef

begin_define
define|#
directive|define
name|EC_POINT_set_affine_coordinates_GFp
value|EC_POINT_set_affine_coords_GFp
end_define

begin_undef
undef|#
directive|undef
name|EC_POINT_get_affine_coordinates_GFp
end_undef

begin_define
define|#
directive|define
name|EC_POINT_get_affine_coordinates_GFp
value|EC_POINT_get_affine_coords_GFp
end_define

begin_undef
undef|#
directive|undef
name|EC_POINT_set_compressed_coordinates_GFp
end_undef

begin_define
define|#
directive|define
name|EC_POINT_set_compressed_coordinates_GFp
value|EC_POINT_set_compr_coords_GFp
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_group_set_curve_GFp
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_group_set_curve_GFp
value|ec_GFp_simple_grp_set_curve_GFp
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_group_get_curve_GFp
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_group_get_curve_GFp
value|ec_GFp_simple_grp_get_curve_GFp
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_group_clear_finish
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_group_clear_finish
value|ec_GFp_simple_grp_clear_finish
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_group_set_generator
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_group_set_generator
value|ec_GFp_simple_grp_set_generator
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_group_get0_generator
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_group_get0_generator
value|ec_GFp_simple_grp_gt0_generator
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_group_get_cofactor
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_group_get_cofactor
value|ec_GFp_simple_grp_get_cofactor
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_point_clear_finish
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_point_clear_finish
value|ec_GFp_simple_pt_clear_finish
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_point_set_to_infinity
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_point_set_to_infinity
value|ec_GFp_simple_pt_set_to_inf
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_points_make_affine
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_points_make_affine
value|ec_GFp_simple_pts_make_affine
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_group_get_curve_GFp
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_group_get_curve_GFp
value|ec_GFp_simple_grp_get_curve_GFp
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_set_Jprojective_coordinates_GFp
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_set_Jprojective_coordinates_GFp
define|\
value|ec_GFp_smp_set_Jproj_coords_GFp
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_get_Jprojective_coordinates_GFp
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_get_Jprojective_coordinates_GFp
define|\
value|ec_GFp_smp_get_Jproj_coords_GFp
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_point_set_affine_coordinates_GFp
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_point_set_affine_coordinates_GFp
define|\
value|ec_GFp_smp_pt_set_af_coords_GFp
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_point_get_affine_coordinates_GFp
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_point_get_affine_coordinates_GFp
define|\
value|ec_GFp_smp_pt_get_af_coords_GFp
end_define

begin_undef
undef|#
directive|undef
name|ec_GFp_simple_set_compressed_coordinates_GFp
end_undef

begin_define
define|#
directive|define
name|ec_GFp_simple_set_compressed_coordinates_GFp
define|\
value|ec_GFp_smp_set_compr_coords_GFp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined OPENSSL_SYS_VMS */
end_comment

begin_comment
comment|/* Case insensiteve linking causes problems.... */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL_SYS_WIN16
argument_list|)
operator|||
name|defined
argument_list|(
name|OPENSSL_SYS_VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|OPENSSL_SYS_OS2
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|ERR_load_CRYPTO_strings
end_undef

begin_define
define|#
directive|define
name|ERR_load_CRYPTO_strings
value|ERR_load_CRYPTOlib_strings
end_define

begin_undef
undef|#
directive|undef
name|OCSP_crlID_new
end_undef

begin_define
define|#
directive|define
name|OCSP_crlID_new
value|OCSP_crlID2_new
end_define

begin_comment
comment|/* These functions do not seem to exist!  However, I'm paranoid...    Original command in x509v3.h:    These functions are being redefined in another directory,    and clash when the linker is case-insensitive, so let's    hide them a little, by giving them an extra 'o' at the    beginning of the name... */
end_comment

begin_undef
undef|#
directive|undef
name|X509v3_cleanup_extensions
end_undef

begin_define
define|#
directive|define
name|X509v3_cleanup_extensions
value|oX509v3_cleanup_extensions
end_define

begin_undef
undef|#
directive|undef
name|X509v3_add_extension
end_undef

begin_define
define|#
directive|define
name|X509v3_add_extension
value|oX509v3_add_extension
end_define

begin_undef
undef|#
directive|undef
name|X509v3_add_netscape_extensions
end_undef

begin_define
define|#
directive|define
name|X509v3_add_netscape_extensions
value|oX509v3_add_netscape_extensions
end_define

begin_undef
undef|#
directive|undef
name|X509v3_add_standard_extensions
end_undef

begin_define
define|#
directive|define
name|X509v3_add_standard_extensions
value|oX509v3_add_standard_extensions
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
comment|/* ! defined HEADER_VMS_IDHACKS_H */
end_comment

end_unit

