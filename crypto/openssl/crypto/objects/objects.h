begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/objects/objects.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_OBJECTS_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_OBJECTS_H
end_define

begin_define
define|#
directive|define
name|USE_OBJ_MAC
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OBJ_MAC
end_ifdef

begin_include
include|#
directive|include
file|<openssl/obj_mac.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SN_undef
value|"UNDEF"
end_define

begin_define
define|#
directive|define
name|LN_undef
value|"undefined"
end_define

begin_define
define|#
directive|define
name|NID_undef
value|0
end_define

begin_define
define|#
directive|define
name|OBJ_undef
value|0L
end_define

begin_define
define|#
directive|define
name|SN_Algorithm
value|"Algorithm"
end_define

begin_define
define|#
directive|define
name|LN_algorithm
value|"algorithm"
end_define

begin_define
define|#
directive|define
name|NID_algorithm
value|38
end_define

begin_define
define|#
directive|define
name|OBJ_algorithm
value|1L,3L,14L,3L,2L
end_define

begin_define
define|#
directive|define
name|LN_rsadsi
value|"rsadsi"
end_define

begin_define
define|#
directive|define
name|NID_rsadsi
value|1
end_define

begin_define
define|#
directive|define
name|OBJ_rsadsi
value|1L,2L,840L,113549L
end_define

begin_define
define|#
directive|define
name|LN_pkcs
value|"pkcs"
end_define

begin_define
define|#
directive|define
name|NID_pkcs
value|2
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs
value|OBJ_rsadsi,1L
end_define

begin_define
define|#
directive|define
name|SN_md2
value|"MD2"
end_define

begin_define
define|#
directive|define
name|LN_md2
value|"md2"
end_define

begin_define
define|#
directive|define
name|NID_md2
value|3
end_define

begin_define
define|#
directive|define
name|OBJ_md2
value|OBJ_rsadsi,2L,2L
end_define

begin_define
define|#
directive|define
name|SN_md5
value|"MD5"
end_define

begin_define
define|#
directive|define
name|LN_md5
value|"md5"
end_define

begin_define
define|#
directive|define
name|NID_md5
value|4
end_define

begin_define
define|#
directive|define
name|OBJ_md5
value|OBJ_rsadsi,2L,5L
end_define

begin_define
define|#
directive|define
name|SN_rc4
value|"RC4"
end_define

begin_define
define|#
directive|define
name|LN_rc4
value|"rc4"
end_define

begin_define
define|#
directive|define
name|NID_rc4
value|5
end_define

begin_define
define|#
directive|define
name|OBJ_rc4
value|OBJ_rsadsi,3L,4L
end_define

begin_define
define|#
directive|define
name|LN_rsaEncryption
value|"rsaEncryption"
end_define

begin_define
define|#
directive|define
name|NID_rsaEncryption
value|6
end_define

begin_define
define|#
directive|define
name|OBJ_rsaEncryption
value|OBJ_pkcs,1L,1L
end_define

begin_define
define|#
directive|define
name|SN_md2WithRSAEncryption
value|"RSA-MD2"
end_define

begin_define
define|#
directive|define
name|LN_md2WithRSAEncryption
value|"md2WithRSAEncryption"
end_define

begin_define
define|#
directive|define
name|NID_md2WithRSAEncryption
value|7
end_define

begin_define
define|#
directive|define
name|OBJ_md2WithRSAEncryption
value|OBJ_pkcs,1L,2L
end_define

begin_define
define|#
directive|define
name|SN_md5WithRSAEncryption
value|"RSA-MD5"
end_define

begin_define
define|#
directive|define
name|LN_md5WithRSAEncryption
value|"md5WithRSAEncryption"
end_define

begin_define
define|#
directive|define
name|NID_md5WithRSAEncryption
value|8
end_define

begin_define
define|#
directive|define
name|OBJ_md5WithRSAEncryption
value|OBJ_pkcs,1L,4L
end_define

begin_define
define|#
directive|define
name|SN_pbeWithMD2AndDES_CBC
value|"PBE-MD2-DES"
end_define

begin_define
define|#
directive|define
name|LN_pbeWithMD2AndDES_CBC
value|"pbeWithMD2AndDES-CBC"
end_define

begin_define
define|#
directive|define
name|NID_pbeWithMD2AndDES_CBC
value|9
end_define

begin_define
define|#
directive|define
name|OBJ_pbeWithMD2AndDES_CBC
value|OBJ_pkcs,5L,1L
end_define

begin_define
define|#
directive|define
name|SN_pbeWithMD5AndDES_CBC
value|"PBE-MD5-DES"
end_define

begin_define
define|#
directive|define
name|LN_pbeWithMD5AndDES_CBC
value|"pbeWithMD5AndDES-CBC"
end_define

begin_define
define|#
directive|define
name|NID_pbeWithMD5AndDES_CBC
value|10
end_define

begin_define
define|#
directive|define
name|OBJ_pbeWithMD5AndDES_CBC
value|OBJ_pkcs,5L,3L
end_define

begin_define
define|#
directive|define
name|LN_X500
value|"X500"
end_define

begin_define
define|#
directive|define
name|NID_X500
value|11
end_define

begin_define
define|#
directive|define
name|OBJ_X500
value|2L,5L
end_define

begin_define
define|#
directive|define
name|LN_X509
value|"X509"
end_define

begin_define
define|#
directive|define
name|NID_X509
value|12
end_define

begin_define
define|#
directive|define
name|OBJ_X509
value|OBJ_X500,4L
end_define

begin_define
define|#
directive|define
name|SN_commonName
value|"CN"
end_define

begin_define
define|#
directive|define
name|LN_commonName
value|"commonName"
end_define

begin_define
define|#
directive|define
name|NID_commonName
value|13
end_define

begin_define
define|#
directive|define
name|OBJ_commonName
value|OBJ_X509,3L
end_define

begin_define
define|#
directive|define
name|SN_countryName
value|"C"
end_define

begin_define
define|#
directive|define
name|LN_countryName
value|"countryName"
end_define

begin_define
define|#
directive|define
name|NID_countryName
value|14
end_define

begin_define
define|#
directive|define
name|OBJ_countryName
value|OBJ_X509,6L
end_define

begin_define
define|#
directive|define
name|SN_localityName
value|"L"
end_define

begin_define
define|#
directive|define
name|LN_localityName
value|"localityName"
end_define

begin_define
define|#
directive|define
name|NID_localityName
value|15
end_define

begin_define
define|#
directive|define
name|OBJ_localityName
value|OBJ_X509,7L
end_define

begin_comment
comment|/* Postal Address? PA */
end_comment

begin_comment
comment|/* should be "ST" (rfc1327) but MS uses 'S' */
end_comment

begin_define
define|#
directive|define
name|SN_stateOrProvinceName
value|"ST"
end_define

begin_define
define|#
directive|define
name|LN_stateOrProvinceName
value|"stateOrProvinceName"
end_define

begin_define
define|#
directive|define
name|NID_stateOrProvinceName
value|16
end_define

begin_define
define|#
directive|define
name|OBJ_stateOrProvinceName
value|OBJ_X509,8L
end_define

begin_define
define|#
directive|define
name|SN_organizationName
value|"O"
end_define

begin_define
define|#
directive|define
name|LN_organizationName
value|"organizationName"
end_define

begin_define
define|#
directive|define
name|NID_organizationName
value|17
end_define

begin_define
define|#
directive|define
name|OBJ_organizationName
value|OBJ_X509,10L
end_define

begin_define
define|#
directive|define
name|SN_organizationalUnitName
value|"OU"
end_define

begin_define
define|#
directive|define
name|LN_organizationalUnitName
value|"organizationalUnitName"
end_define

begin_define
define|#
directive|define
name|NID_organizationalUnitName
value|18
end_define

begin_define
define|#
directive|define
name|OBJ_organizationalUnitName
value|OBJ_X509,11L
end_define

begin_define
define|#
directive|define
name|SN_rsa
value|"RSA"
end_define

begin_define
define|#
directive|define
name|LN_rsa
value|"rsa"
end_define

begin_define
define|#
directive|define
name|NID_rsa
value|19
end_define

begin_define
define|#
directive|define
name|OBJ_rsa
value|OBJ_X500,8L,1L,1L
end_define

begin_define
define|#
directive|define
name|LN_pkcs7
value|"pkcs7"
end_define

begin_define
define|#
directive|define
name|NID_pkcs7
value|20
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs7
value|OBJ_pkcs,7L
end_define

begin_define
define|#
directive|define
name|LN_pkcs7_data
value|"pkcs7-data"
end_define

begin_define
define|#
directive|define
name|NID_pkcs7_data
value|21
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs7_data
value|OBJ_pkcs7,1L
end_define

begin_define
define|#
directive|define
name|LN_pkcs7_signed
value|"pkcs7-signedData"
end_define

begin_define
define|#
directive|define
name|NID_pkcs7_signed
value|22
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs7_signed
value|OBJ_pkcs7,2L
end_define

begin_define
define|#
directive|define
name|LN_pkcs7_enveloped
value|"pkcs7-envelopedData"
end_define

begin_define
define|#
directive|define
name|NID_pkcs7_enveloped
value|23
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs7_enveloped
value|OBJ_pkcs7,3L
end_define

begin_define
define|#
directive|define
name|LN_pkcs7_signedAndEnveloped
value|"pkcs7-signedAndEnvelopedData"
end_define

begin_define
define|#
directive|define
name|NID_pkcs7_signedAndEnveloped
value|24
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs7_signedAndEnveloped
value|OBJ_pkcs7,4L
end_define

begin_define
define|#
directive|define
name|LN_pkcs7_digest
value|"pkcs7-digestData"
end_define

begin_define
define|#
directive|define
name|NID_pkcs7_digest
value|25
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs7_digest
value|OBJ_pkcs7,5L
end_define

begin_define
define|#
directive|define
name|LN_pkcs7_encrypted
value|"pkcs7-encryptedData"
end_define

begin_define
define|#
directive|define
name|NID_pkcs7_encrypted
value|26
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs7_encrypted
value|OBJ_pkcs7,6L
end_define

begin_define
define|#
directive|define
name|LN_pkcs3
value|"pkcs3"
end_define

begin_define
define|#
directive|define
name|NID_pkcs3
value|27
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs3
value|OBJ_pkcs,3L
end_define

begin_define
define|#
directive|define
name|LN_dhKeyAgreement
value|"dhKeyAgreement"
end_define

begin_define
define|#
directive|define
name|NID_dhKeyAgreement
value|28
end_define

begin_define
define|#
directive|define
name|OBJ_dhKeyAgreement
value|OBJ_pkcs3,1L
end_define

begin_define
define|#
directive|define
name|SN_des_ecb
value|"DES-ECB"
end_define

begin_define
define|#
directive|define
name|LN_des_ecb
value|"des-ecb"
end_define

begin_define
define|#
directive|define
name|NID_des_ecb
value|29
end_define

begin_define
define|#
directive|define
name|OBJ_des_ecb
value|OBJ_algorithm,6L
end_define

begin_define
define|#
directive|define
name|SN_des_cfb64
value|"DES-CFB"
end_define

begin_define
define|#
directive|define
name|LN_des_cfb64
value|"des-cfb"
end_define

begin_define
define|#
directive|define
name|NID_des_cfb64
value|30
end_define

begin_comment
comment|/* IV + num */
end_comment

begin_define
define|#
directive|define
name|OBJ_des_cfb64
value|OBJ_algorithm,9L
end_define

begin_define
define|#
directive|define
name|SN_des_cbc
value|"DES-CBC"
end_define

begin_define
define|#
directive|define
name|LN_des_cbc
value|"des-cbc"
end_define

begin_define
define|#
directive|define
name|NID_des_cbc
value|31
end_define

begin_comment
comment|/* IV */
end_comment

begin_define
define|#
directive|define
name|OBJ_des_cbc
value|OBJ_algorithm,7L
end_define

begin_define
define|#
directive|define
name|SN_des_ede
value|"DES-EDE"
end_define

begin_define
define|#
directive|define
name|LN_des_ede
value|"des-ede"
end_define

begin_define
define|#
directive|define
name|NID_des_ede
value|32
end_define

begin_comment
comment|/* ?? */
end_comment

begin_define
define|#
directive|define
name|OBJ_des_ede
value|OBJ_algorithm,17L
end_define

begin_define
define|#
directive|define
name|SN_des_ede3
value|"DES-EDE3"
end_define

begin_define
define|#
directive|define
name|LN_des_ede3
value|"des-ede3"
end_define

begin_define
define|#
directive|define
name|NID_des_ede3
value|33
end_define

begin_define
define|#
directive|define
name|SN_idea_cbc
value|"IDEA-CBC"
end_define

begin_define
define|#
directive|define
name|LN_idea_cbc
value|"idea-cbc"
end_define

begin_define
define|#
directive|define
name|NID_idea_cbc
value|34
end_define

begin_define
define|#
directive|define
name|OBJ_idea_cbc
value|1L,3L,6L,1L,4L,1L,188L,7L,1L,1L,2L
end_define

begin_define
define|#
directive|define
name|SN_idea_cfb64
value|"IDEA-CFB"
end_define

begin_define
define|#
directive|define
name|LN_idea_cfb64
value|"idea-cfb"
end_define

begin_define
define|#
directive|define
name|NID_idea_cfb64
value|35
end_define

begin_define
define|#
directive|define
name|SN_idea_ecb
value|"IDEA-ECB"
end_define

begin_define
define|#
directive|define
name|LN_idea_ecb
value|"idea-ecb"
end_define

begin_define
define|#
directive|define
name|NID_idea_ecb
value|36
end_define

begin_define
define|#
directive|define
name|SN_rc2_cbc
value|"RC2-CBC"
end_define

begin_define
define|#
directive|define
name|LN_rc2_cbc
value|"rc2-cbc"
end_define

begin_define
define|#
directive|define
name|NID_rc2_cbc
value|37
end_define

begin_define
define|#
directive|define
name|OBJ_rc2_cbc
value|OBJ_rsadsi,3L,2L
end_define

begin_define
define|#
directive|define
name|SN_rc2_ecb
value|"RC2-ECB"
end_define

begin_define
define|#
directive|define
name|LN_rc2_ecb
value|"rc2-ecb"
end_define

begin_define
define|#
directive|define
name|NID_rc2_ecb
value|38
end_define

begin_define
define|#
directive|define
name|SN_rc2_cfb64
value|"RC2-CFB"
end_define

begin_define
define|#
directive|define
name|LN_rc2_cfb64
value|"rc2-cfb"
end_define

begin_define
define|#
directive|define
name|NID_rc2_cfb64
value|39
end_define

begin_define
define|#
directive|define
name|SN_rc2_ofb64
value|"RC2-OFB"
end_define

begin_define
define|#
directive|define
name|LN_rc2_ofb64
value|"rc2-ofb"
end_define

begin_define
define|#
directive|define
name|NID_rc2_ofb64
value|40
end_define

begin_define
define|#
directive|define
name|SN_sha
value|"SHA"
end_define

begin_define
define|#
directive|define
name|LN_sha
value|"sha"
end_define

begin_define
define|#
directive|define
name|NID_sha
value|41
end_define

begin_define
define|#
directive|define
name|OBJ_sha
value|OBJ_algorithm,18L
end_define

begin_define
define|#
directive|define
name|SN_shaWithRSAEncryption
value|"RSA-SHA"
end_define

begin_define
define|#
directive|define
name|LN_shaWithRSAEncryption
value|"shaWithRSAEncryption"
end_define

begin_define
define|#
directive|define
name|NID_shaWithRSAEncryption
value|42
end_define

begin_define
define|#
directive|define
name|OBJ_shaWithRSAEncryption
value|OBJ_algorithm,15L
end_define

begin_define
define|#
directive|define
name|SN_des_ede_cbc
value|"DES-EDE-CBC"
end_define

begin_define
define|#
directive|define
name|LN_des_ede_cbc
value|"des-ede-cbc"
end_define

begin_define
define|#
directive|define
name|NID_des_ede_cbc
value|43
end_define

begin_define
define|#
directive|define
name|SN_des_ede3_cbc
value|"DES-EDE3-CBC"
end_define

begin_define
define|#
directive|define
name|LN_des_ede3_cbc
value|"des-ede3-cbc"
end_define

begin_define
define|#
directive|define
name|NID_des_ede3_cbc
value|44
end_define

begin_define
define|#
directive|define
name|OBJ_des_ede3_cbc
value|OBJ_rsadsi,3L,7L
end_define

begin_define
define|#
directive|define
name|SN_des_ofb64
value|"DES-OFB"
end_define

begin_define
define|#
directive|define
name|LN_des_ofb64
value|"des-ofb"
end_define

begin_define
define|#
directive|define
name|NID_des_ofb64
value|45
end_define

begin_define
define|#
directive|define
name|OBJ_des_ofb64
value|OBJ_algorithm,8L
end_define

begin_define
define|#
directive|define
name|SN_idea_ofb64
value|"IDEA-OFB"
end_define

begin_define
define|#
directive|define
name|LN_idea_ofb64
value|"idea-ofb"
end_define

begin_define
define|#
directive|define
name|NID_idea_ofb64
value|46
end_define

begin_define
define|#
directive|define
name|LN_pkcs9
value|"pkcs9"
end_define

begin_define
define|#
directive|define
name|NID_pkcs9
value|47
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs9
value|OBJ_pkcs,9L
end_define

begin_define
define|#
directive|define
name|SN_pkcs9_emailAddress
value|"Email"
end_define

begin_define
define|#
directive|define
name|LN_pkcs9_emailAddress
value|"emailAddress"
end_define

begin_define
define|#
directive|define
name|NID_pkcs9_emailAddress
value|48
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs9_emailAddress
value|OBJ_pkcs9,1L
end_define

begin_define
define|#
directive|define
name|LN_pkcs9_unstructuredName
value|"unstructuredName"
end_define

begin_define
define|#
directive|define
name|NID_pkcs9_unstructuredName
value|49
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs9_unstructuredName
value|OBJ_pkcs9,2L
end_define

begin_define
define|#
directive|define
name|LN_pkcs9_contentType
value|"contentType"
end_define

begin_define
define|#
directive|define
name|NID_pkcs9_contentType
value|50
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs9_contentType
value|OBJ_pkcs9,3L
end_define

begin_define
define|#
directive|define
name|LN_pkcs9_messageDigest
value|"messageDigest"
end_define

begin_define
define|#
directive|define
name|NID_pkcs9_messageDigest
value|51
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs9_messageDigest
value|OBJ_pkcs9,4L
end_define

begin_define
define|#
directive|define
name|LN_pkcs9_signingTime
value|"signingTime"
end_define

begin_define
define|#
directive|define
name|NID_pkcs9_signingTime
value|52
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs9_signingTime
value|OBJ_pkcs9,5L
end_define

begin_define
define|#
directive|define
name|LN_pkcs9_countersignature
value|"countersignature"
end_define

begin_define
define|#
directive|define
name|NID_pkcs9_countersignature
value|53
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs9_countersignature
value|OBJ_pkcs9,6L
end_define

begin_define
define|#
directive|define
name|LN_pkcs9_challengePassword
value|"challengePassword"
end_define

begin_define
define|#
directive|define
name|NID_pkcs9_challengePassword
value|54
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs9_challengePassword
value|OBJ_pkcs9,7L
end_define

begin_define
define|#
directive|define
name|LN_pkcs9_unstructuredAddress
value|"unstructuredAddress"
end_define

begin_define
define|#
directive|define
name|NID_pkcs9_unstructuredAddress
value|55
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs9_unstructuredAddress
value|OBJ_pkcs9,8L
end_define

begin_define
define|#
directive|define
name|LN_pkcs9_extCertAttributes
value|"extendedCertificateAttributes"
end_define

begin_define
define|#
directive|define
name|NID_pkcs9_extCertAttributes
value|56
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs9_extCertAttributes
value|OBJ_pkcs9,9L
end_define

begin_define
define|#
directive|define
name|SN_netscape
value|"Netscape"
end_define

begin_define
define|#
directive|define
name|LN_netscape
value|"Netscape Communications Corp."
end_define

begin_define
define|#
directive|define
name|NID_netscape
value|57
end_define

begin_define
define|#
directive|define
name|OBJ_netscape
value|2L,16L,840L,1L,113730L
end_define

begin_define
define|#
directive|define
name|SN_netscape_cert_extension
value|"nsCertExt"
end_define

begin_define
define|#
directive|define
name|LN_netscape_cert_extension
value|"Netscape Certificate Extension"
end_define

begin_define
define|#
directive|define
name|NID_netscape_cert_extension
value|58
end_define

begin_define
define|#
directive|define
name|OBJ_netscape_cert_extension
value|OBJ_netscape,1L
end_define

begin_define
define|#
directive|define
name|SN_netscape_data_type
value|"nsDataType"
end_define

begin_define
define|#
directive|define
name|LN_netscape_data_type
value|"Netscape Data Type"
end_define

begin_define
define|#
directive|define
name|NID_netscape_data_type
value|59
end_define

begin_define
define|#
directive|define
name|OBJ_netscape_data_type
value|OBJ_netscape,2L
end_define

begin_define
define|#
directive|define
name|SN_des_ede_cfb64
value|"DES-EDE-CFB"
end_define

begin_define
define|#
directive|define
name|LN_des_ede_cfb64
value|"des-ede-cfb"
end_define

begin_define
define|#
directive|define
name|NID_des_ede_cfb64
value|60
end_define

begin_define
define|#
directive|define
name|SN_des_ede3_cfb64
value|"DES-EDE3-CFB"
end_define

begin_define
define|#
directive|define
name|LN_des_ede3_cfb64
value|"des-ede3-cfb"
end_define

begin_define
define|#
directive|define
name|NID_des_ede3_cfb64
value|61
end_define

begin_define
define|#
directive|define
name|SN_des_ede_ofb64
value|"DES-EDE-OFB"
end_define

begin_define
define|#
directive|define
name|LN_des_ede_ofb64
value|"des-ede-ofb"
end_define

begin_define
define|#
directive|define
name|NID_des_ede_ofb64
value|62
end_define

begin_define
define|#
directive|define
name|SN_des_ede3_ofb64
value|"DES-EDE3-OFB"
end_define

begin_define
define|#
directive|define
name|LN_des_ede3_ofb64
value|"des-ede3-ofb"
end_define

begin_define
define|#
directive|define
name|NID_des_ede3_ofb64
value|63
end_define

begin_comment
comment|/* I'm not sure about the object ID */
end_comment

begin_define
define|#
directive|define
name|SN_sha1
value|"SHA1"
end_define

begin_define
define|#
directive|define
name|LN_sha1
value|"sha1"
end_define

begin_define
define|#
directive|define
name|NID_sha1
value|64
end_define

begin_define
define|#
directive|define
name|OBJ_sha1
value|OBJ_algorithm,26L
end_define

begin_comment
comment|/* 28 Jun 1996 - eay */
end_comment

begin_comment
comment|/* #define OBJ_sha1			1L,3L,14L,2L,26L,05L<- wrong */
end_comment

begin_define
define|#
directive|define
name|SN_sha1WithRSAEncryption
value|"RSA-SHA1"
end_define

begin_define
define|#
directive|define
name|LN_sha1WithRSAEncryption
value|"sha1WithRSAEncryption"
end_define

begin_define
define|#
directive|define
name|NID_sha1WithRSAEncryption
value|65
end_define

begin_define
define|#
directive|define
name|OBJ_sha1WithRSAEncryption
value|OBJ_pkcs,1L,5L
end_define

begin_define
define|#
directive|define
name|SN_dsaWithSHA
value|"DSA-SHA"
end_define

begin_define
define|#
directive|define
name|LN_dsaWithSHA
value|"dsaWithSHA"
end_define

begin_define
define|#
directive|define
name|NID_dsaWithSHA
value|66
end_define

begin_define
define|#
directive|define
name|OBJ_dsaWithSHA
value|OBJ_algorithm,13L
end_define

begin_define
define|#
directive|define
name|SN_dsa_2
value|"DSA-old"
end_define

begin_define
define|#
directive|define
name|LN_dsa_2
value|"dsaEncryption-old"
end_define

begin_define
define|#
directive|define
name|NID_dsa_2
value|67
end_define

begin_define
define|#
directive|define
name|OBJ_dsa_2
value|OBJ_algorithm,12L
end_define

begin_comment
comment|/* proposed by microsoft to RSA */
end_comment

begin_define
define|#
directive|define
name|SN_pbeWithSHA1AndRC2_CBC
value|"PBE-SHA1-RC2-64"
end_define

begin_define
define|#
directive|define
name|LN_pbeWithSHA1AndRC2_CBC
value|"pbeWithSHA1AndRC2-CBC"
end_define

begin_define
define|#
directive|define
name|NID_pbeWithSHA1AndRC2_CBC
value|68
end_define

begin_define
define|#
directive|define
name|OBJ_pbeWithSHA1AndRC2_CBC
value|OBJ_pkcs,5L,11L
end_define

begin_comment
comment|/* proposed by microsoft to RSA as pbeWithSHA1AndRC4: it is now  * defined explicitly in PKCS#5 v2.0 as id-PBKDF2 which is something  * completely different.  */
end_comment

begin_define
define|#
directive|define
name|LN_id_pbkdf2
value|"PBKDF2"
end_define

begin_define
define|#
directive|define
name|NID_id_pbkdf2
value|69
end_define

begin_define
define|#
directive|define
name|OBJ_id_pbkdf2
value|OBJ_pkcs,5L,12L
end_define

begin_define
define|#
directive|define
name|SN_dsaWithSHA1_2
value|"DSA-SHA1-old"
end_define

begin_define
define|#
directive|define
name|LN_dsaWithSHA1_2
value|"dsaWithSHA1-old"
end_define

begin_define
define|#
directive|define
name|NID_dsaWithSHA1_2
value|70
end_define

begin_comment
comment|/* Got this one from 'sdn706r20.pdf' which is actually an NSA document :-) */
end_comment

begin_define
define|#
directive|define
name|OBJ_dsaWithSHA1_2
value|OBJ_algorithm,27L
end_define

begin_define
define|#
directive|define
name|SN_netscape_cert_type
value|"nsCertType"
end_define

begin_define
define|#
directive|define
name|LN_netscape_cert_type
value|"Netscape Cert Type"
end_define

begin_define
define|#
directive|define
name|NID_netscape_cert_type
value|71
end_define

begin_define
define|#
directive|define
name|OBJ_netscape_cert_type
value|OBJ_netscape_cert_extension,1L
end_define

begin_define
define|#
directive|define
name|SN_netscape_base_url
value|"nsBaseUrl"
end_define

begin_define
define|#
directive|define
name|LN_netscape_base_url
value|"Netscape Base Url"
end_define

begin_define
define|#
directive|define
name|NID_netscape_base_url
value|72
end_define

begin_define
define|#
directive|define
name|OBJ_netscape_base_url
value|OBJ_netscape_cert_extension,2L
end_define

begin_define
define|#
directive|define
name|SN_netscape_revocation_url
value|"nsRevocationUrl"
end_define

begin_define
define|#
directive|define
name|LN_netscape_revocation_url
value|"Netscape Revocation Url"
end_define

begin_define
define|#
directive|define
name|NID_netscape_revocation_url
value|73
end_define

begin_define
define|#
directive|define
name|OBJ_netscape_revocation_url
value|OBJ_netscape_cert_extension,3L
end_define

begin_define
define|#
directive|define
name|SN_netscape_ca_revocation_url
value|"nsCaRevocationUrl"
end_define

begin_define
define|#
directive|define
name|LN_netscape_ca_revocation_url
value|"Netscape CA Revocation Url"
end_define

begin_define
define|#
directive|define
name|NID_netscape_ca_revocation_url
value|74
end_define

begin_define
define|#
directive|define
name|OBJ_netscape_ca_revocation_url
value|OBJ_netscape_cert_extension,4L
end_define

begin_define
define|#
directive|define
name|SN_netscape_renewal_url
value|"nsRenewalUrl"
end_define

begin_define
define|#
directive|define
name|LN_netscape_renewal_url
value|"Netscape Renewal Url"
end_define

begin_define
define|#
directive|define
name|NID_netscape_renewal_url
value|75
end_define

begin_define
define|#
directive|define
name|OBJ_netscape_renewal_url
value|OBJ_netscape_cert_extension,7L
end_define

begin_define
define|#
directive|define
name|SN_netscape_ca_policy_url
value|"nsCaPolicyUrl"
end_define

begin_define
define|#
directive|define
name|LN_netscape_ca_policy_url
value|"Netscape CA Policy Url"
end_define

begin_define
define|#
directive|define
name|NID_netscape_ca_policy_url
value|76
end_define

begin_define
define|#
directive|define
name|OBJ_netscape_ca_policy_url
value|OBJ_netscape_cert_extension,8L
end_define

begin_define
define|#
directive|define
name|SN_netscape_ssl_server_name
value|"nsSslServerName"
end_define

begin_define
define|#
directive|define
name|LN_netscape_ssl_server_name
value|"Netscape SSL Server Name"
end_define

begin_define
define|#
directive|define
name|NID_netscape_ssl_server_name
value|77
end_define

begin_define
define|#
directive|define
name|OBJ_netscape_ssl_server_name
value|OBJ_netscape_cert_extension,12L
end_define

begin_define
define|#
directive|define
name|SN_netscape_comment
value|"nsComment"
end_define

begin_define
define|#
directive|define
name|LN_netscape_comment
value|"Netscape Comment"
end_define

begin_define
define|#
directive|define
name|NID_netscape_comment
value|78
end_define

begin_define
define|#
directive|define
name|OBJ_netscape_comment
value|OBJ_netscape_cert_extension,13L
end_define

begin_define
define|#
directive|define
name|SN_netscape_cert_sequence
value|"nsCertSequence"
end_define

begin_define
define|#
directive|define
name|LN_netscape_cert_sequence
value|"Netscape Certificate Sequence"
end_define

begin_define
define|#
directive|define
name|NID_netscape_cert_sequence
value|79
end_define

begin_define
define|#
directive|define
name|OBJ_netscape_cert_sequence
value|OBJ_netscape_data_type,5L
end_define

begin_define
define|#
directive|define
name|SN_desx_cbc
value|"DESX-CBC"
end_define

begin_define
define|#
directive|define
name|LN_desx_cbc
value|"desx-cbc"
end_define

begin_define
define|#
directive|define
name|NID_desx_cbc
value|80
end_define

begin_define
define|#
directive|define
name|SN_ld_ce
value|"ld-ce"
end_define

begin_define
define|#
directive|define
name|NID_ld_ce
value|81
end_define

begin_define
define|#
directive|define
name|OBJ_ld_ce
value|2L,5L,29L
end_define

begin_define
define|#
directive|define
name|SN_subject_key_identifier
value|"subjectKeyIdentifier"
end_define

begin_define
define|#
directive|define
name|LN_subject_key_identifier
value|"X509v3 Subject Key Identifier"
end_define

begin_define
define|#
directive|define
name|NID_subject_key_identifier
value|82
end_define

begin_define
define|#
directive|define
name|OBJ_subject_key_identifier
value|OBJ_ld_ce,14L
end_define

begin_define
define|#
directive|define
name|SN_key_usage
value|"keyUsage"
end_define

begin_define
define|#
directive|define
name|LN_key_usage
value|"X509v3 Key Usage"
end_define

begin_define
define|#
directive|define
name|NID_key_usage
value|83
end_define

begin_define
define|#
directive|define
name|OBJ_key_usage
value|OBJ_ld_ce,15L
end_define

begin_define
define|#
directive|define
name|SN_private_key_usage_period
value|"privateKeyUsagePeriod"
end_define

begin_define
define|#
directive|define
name|LN_private_key_usage_period
value|"X509v3 Private Key Usage Period"
end_define

begin_define
define|#
directive|define
name|NID_private_key_usage_period
value|84
end_define

begin_define
define|#
directive|define
name|OBJ_private_key_usage_period
value|OBJ_ld_ce,16L
end_define

begin_define
define|#
directive|define
name|SN_subject_alt_name
value|"subjectAltName"
end_define

begin_define
define|#
directive|define
name|LN_subject_alt_name
value|"X509v3 Subject Alternative Name"
end_define

begin_define
define|#
directive|define
name|NID_subject_alt_name
value|85
end_define

begin_define
define|#
directive|define
name|OBJ_subject_alt_name
value|OBJ_ld_ce,17L
end_define

begin_define
define|#
directive|define
name|SN_issuer_alt_name
value|"issuerAltName"
end_define

begin_define
define|#
directive|define
name|LN_issuer_alt_name
value|"X509v3 Issuer Alternative Name"
end_define

begin_define
define|#
directive|define
name|NID_issuer_alt_name
value|86
end_define

begin_define
define|#
directive|define
name|OBJ_issuer_alt_name
value|OBJ_ld_ce,18L
end_define

begin_define
define|#
directive|define
name|SN_basic_constraints
value|"basicConstraints"
end_define

begin_define
define|#
directive|define
name|LN_basic_constraints
value|"X509v3 Basic Constraints"
end_define

begin_define
define|#
directive|define
name|NID_basic_constraints
value|87
end_define

begin_define
define|#
directive|define
name|OBJ_basic_constraints
value|OBJ_ld_ce,19L
end_define

begin_define
define|#
directive|define
name|SN_crl_number
value|"crlNumber"
end_define

begin_define
define|#
directive|define
name|LN_crl_number
value|"X509v3 CRL Number"
end_define

begin_define
define|#
directive|define
name|NID_crl_number
value|88
end_define

begin_define
define|#
directive|define
name|OBJ_crl_number
value|OBJ_ld_ce,20L
end_define

begin_define
define|#
directive|define
name|SN_certificate_policies
value|"certificatePolicies"
end_define

begin_define
define|#
directive|define
name|LN_certificate_policies
value|"X509v3 Certificate Policies"
end_define

begin_define
define|#
directive|define
name|NID_certificate_policies
value|89
end_define

begin_define
define|#
directive|define
name|OBJ_certificate_policies
value|OBJ_ld_ce,32L
end_define

begin_define
define|#
directive|define
name|SN_authority_key_identifier
value|"authorityKeyIdentifier"
end_define

begin_define
define|#
directive|define
name|LN_authority_key_identifier
value|"X509v3 Authority Key Identifier"
end_define

begin_define
define|#
directive|define
name|NID_authority_key_identifier
value|90
end_define

begin_define
define|#
directive|define
name|OBJ_authority_key_identifier
value|OBJ_ld_ce,35L
end_define

begin_define
define|#
directive|define
name|SN_bf_cbc
value|"BF-CBC"
end_define

begin_define
define|#
directive|define
name|LN_bf_cbc
value|"bf-cbc"
end_define

begin_define
define|#
directive|define
name|NID_bf_cbc
value|91
end_define

begin_define
define|#
directive|define
name|OBJ_bf_cbc
value|1L,3L,6L,1L,4L,1L,3029L,1L,2L
end_define

begin_define
define|#
directive|define
name|SN_bf_ecb
value|"BF-ECB"
end_define

begin_define
define|#
directive|define
name|LN_bf_ecb
value|"bf-ecb"
end_define

begin_define
define|#
directive|define
name|NID_bf_ecb
value|92
end_define

begin_define
define|#
directive|define
name|SN_bf_cfb64
value|"BF-CFB"
end_define

begin_define
define|#
directive|define
name|LN_bf_cfb64
value|"bf-cfb"
end_define

begin_define
define|#
directive|define
name|NID_bf_cfb64
value|93
end_define

begin_define
define|#
directive|define
name|SN_bf_ofb64
value|"BF-OFB"
end_define

begin_define
define|#
directive|define
name|LN_bf_ofb64
value|"bf-ofb"
end_define

begin_define
define|#
directive|define
name|NID_bf_ofb64
value|94
end_define

begin_define
define|#
directive|define
name|SN_mdc2
value|"MDC2"
end_define

begin_define
define|#
directive|define
name|LN_mdc2
value|"mdc2"
end_define

begin_define
define|#
directive|define
name|NID_mdc2
value|95
end_define

begin_define
define|#
directive|define
name|OBJ_mdc2
value|2L,5L,8L,3L,101L
end_define

begin_comment
comment|/* An alternative?			1L,3L,14L,3L,2L,19L */
end_comment

begin_define
define|#
directive|define
name|SN_mdc2WithRSA
value|"RSA-MDC2"
end_define

begin_define
define|#
directive|define
name|LN_mdc2WithRSA
value|"mdc2withRSA"
end_define

begin_define
define|#
directive|define
name|NID_mdc2WithRSA
value|96
end_define

begin_define
define|#
directive|define
name|OBJ_mdc2WithRSA
value|2L,5L,8L,3L,100L
end_define

begin_define
define|#
directive|define
name|SN_rc4_40
value|"RC4-40"
end_define

begin_define
define|#
directive|define
name|LN_rc4_40
value|"rc4-40"
end_define

begin_define
define|#
directive|define
name|NID_rc4_40
value|97
end_define

begin_define
define|#
directive|define
name|SN_rc2_40_cbc
value|"RC2-40-CBC"
end_define

begin_define
define|#
directive|define
name|LN_rc2_40_cbc
value|"rc2-40-cbc"
end_define

begin_define
define|#
directive|define
name|NID_rc2_40_cbc
value|98
end_define

begin_define
define|#
directive|define
name|SN_givenName
value|"G"
end_define

begin_define
define|#
directive|define
name|LN_givenName
value|"givenName"
end_define

begin_define
define|#
directive|define
name|NID_givenName
value|99
end_define

begin_define
define|#
directive|define
name|OBJ_givenName
value|OBJ_X509,42L
end_define

begin_define
define|#
directive|define
name|SN_surname
value|"S"
end_define

begin_define
define|#
directive|define
name|LN_surname
value|"surname"
end_define

begin_define
define|#
directive|define
name|NID_surname
value|100
end_define

begin_define
define|#
directive|define
name|OBJ_surname
value|OBJ_X509,4L
end_define

begin_define
define|#
directive|define
name|SN_initials
value|"I"
end_define

begin_define
define|#
directive|define
name|LN_initials
value|"initials"
end_define

begin_define
define|#
directive|define
name|NID_initials
value|101
end_define

begin_define
define|#
directive|define
name|OBJ_initials
value|OBJ_X509,43L
end_define

begin_define
define|#
directive|define
name|SN_uniqueIdentifier
value|"UID"
end_define

begin_define
define|#
directive|define
name|LN_uniqueIdentifier
value|"uniqueIdentifier"
end_define

begin_define
define|#
directive|define
name|NID_uniqueIdentifier
value|102
end_define

begin_define
define|#
directive|define
name|OBJ_uniqueIdentifier
value|OBJ_X509,45L
end_define

begin_define
define|#
directive|define
name|SN_crl_distribution_points
value|"crlDistributionPoints"
end_define

begin_define
define|#
directive|define
name|LN_crl_distribution_points
value|"X509v3 CRL Distribution Points"
end_define

begin_define
define|#
directive|define
name|NID_crl_distribution_points
value|103
end_define

begin_define
define|#
directive|define
name|OBJ_crl_distribution_points
value|OBJ_ld_ce,31L
end_define

begin_define
define|#
directive|define
name|SN_md5WithRSA
value|"RSA-NP-MD5"
end_define

begin_define
define|#
directive|define
name|LN_md5WithRSA
value|"md5WithRSA"
end_define

begin_define
define|#
directive|define
name|NID_md5WithRSA
value|104
end_define

begin_define
define|#
directive|define
name|OBJ_md5WithRSA
value|OBJ_algorithm,3L
end_define

begin_define
define|#
directive|define
name|SN_serialNumber
value|"SN"
end_define

begin_define
define|#
directive|define
name|LN_serialNumber
value|"serialNumber"
end_define

begin_define
define|#
directive|define
name|NID_serialNumber
value|105
end_define

begin_define
define|#
directive|define
name|OBJ_serialNumber
value|OBJ_X509,5L
end_define

begin_define
define|#
directive|define
name|SN_title
value|"T"
end_define

begin_define
define|#
directive|define
name|LN_title
value|"title"
end_define

begin_define
define|#
directive|define
name|NID_title
value|106
end_define

begin_define
define|#
directive|define
name|OBJ_title
value|OBJ_X509,12L
end_define

begin_define
define|#
directive|define
name|SN_description
value|"D"
end_define

begin_define
define|#
directive|define
name|LN_description
value|"description"
end_define

begin_define
define|#
directive|define
name|NID_description
value|107
end_define

begin_define
define|#
directive|define
name|OBJ_description
value|OBJ_X509,13L
end_define

begin_comment
comment|/* CAST5 is CAST-128, I'm just sticking with the documentation */
end_comment

begin_define
define|#
directive|define
name|SN_cast5_cbc
value|"CAST5-CBC"
end_define

begin_define
define|#
directive|define
name|LN_cast5_cbc
value|"cast5-cbc"
end_define

begin_define
define|#
directive|define
name|NID_cast5_cbc
value|108
end_define

begin_define
define|#
directive|define
name|OBJ_cast5_cbc
value|1L,2L,840L,113533L,7L,66L,10L
end_define

begin_define
define|#
directive|define
name|SN_cast5_ecb
value|"CAST5-ECB"
end_define

begin_define
define|#
directive|define
name|LN_cast5_ecb
value|"cast5-ecb"
end_define

begin_define
define|#
directive|define
name|NID_cast5_ecb
value|109
end_define

begin_define
define|#
directive|define
name|SN_cast5_cfb64
value|"CAST5-CFB"
end_define

begin_define
define|#
directive|define
name|LN_cast5_cfb64
value|"cast5-cfb"
end_define

begin_define
define|#
directive|define
name|NID_cast5_cfb64
value|110
end_define

begin_define
define|#
directive|define
name|SN_cast5_ofb64
value|"CAST5-OFB"
end_define

begin_define
define|#
directive|define
name|LN_cast5_ofb64
value|"cast5-ofb"
end_define

begin_define
define|#
directive|define
name|NID_cast5_ofb64
value|111
end_define

begin_define
define|#
directive|define
name|LN_pbeWithMD5AndCast5_CBC
value|"pbeWithMD5AndCast5CBC"
end_define

begin_define
define|#
directive|define
name|NID_pbeWithMD5AndCast5_CBC
value|112
end_define

begin_define
define|#
directive|define
name|OBJ_pbeWithMD5AndCast5_CBC
value|1L,2L,840L,113533L,7L,66L,12L
end_define

begin_comment
comment|/* This is one sun will soon be using :-(  * id-dsa-with-sha1 ID  ::= {  *   iso(1) member-body(2) us(840) x9-57 (10040) x9cm(4) 3 }  */
end_comment

begin_define
define|#
directive|define
name|SN_dsaWithSHA1
value|"DSA-SHA1"
end_define

begin_define
define|#
directive|define
name|LN_dsaWithSHA1
value|"dsaWithSHA1"
end_define

begin_define
define|#
directive|define
name|NID_dsaWithSHA1
value|113
end_define

begin_define
define|#
directive|define
name|OBJ_dsaWithSHA1
value|1L,2L,840L,10040L,4L,3L
end_define

begin_define
define|#
directive|define
name|NID_md5_sha1
value|114
end_define

begin_define
define|#
directive|define
name|SN_md5_sha1
value|"MD5-SHA1"
end_define

begin_define
define|#
directive|define
name|LN_md5_sha1
value|"md5-sha1"
end_define

begin_define
define|#
directive|define
name|SN_sha1WithRSA
value|"RSA-SHA1-2"
end_define

begin_define
define|#
directive|define
name|LN_sha1WithRSA
value|"sha1WithRSA"
end_define

begin_define
define|#
directive|define
name|NID_sha1WithRSA
value|115
end_define

begin_define
define|#
directive|define
name|OBJ_sha1WithRSA
value|OBJ_algorithm,29L
end_define

begin_define
define|#
directive|define
name|SN_dsa
value|"DSA"
end_define

begin_define
define|#
directive|define
name|LN_dsa
value|"dsaEncryption"
end_define

begin_define
define|#
directive|define
name|NID_dsa
value|116
end_define

begin_define
define|#
directive|define
name|OBJ_dsa
value|1L,2L,840L,10040L,4L,1L
end_define

begin_define
define|#
directive|define
name|SN_ripemd160
value|"RIPEMD160"
end_define

begin_define
define|#
directive|define
name|LN_ripemd160
value|"ripemd160"
end_define

begin_define
define|#
directive|define
name|NID_ripemd160
value|117
end_define

begin_define
define|#
directive|define
name|OBJ_ripemd160
value|1L,3L,36L,3L,2L,1L
end_define

begin_comment
comment|/* The name should actually be rsaSignatureWithripemd160, but I'm going  * to continue using the convention I'm using with the other ciphers */
end_comment

begin_define
define|#
directive|define
name|SN_ripemd160WithRSA
value|"RSA-RIPEMD160"
end_define

begin_define
define|#
directive|define
name|LN_ripemd160WithRSA
value|"ripemd160WithRSA"
end_define

begin_define
define|#
directive|define
name|NID_ripemd160WithRSA
value|119
end_define

begin_define
define|#
directive|define
name|OBJ_ripemd160WithRSA
value|1L,3L,36L,3L,3L,1L,2L
end_define

begin_comment
comment|/* Taken from rfc2040  *  RC5_CBC_Parameters ::= SEQUENCE {  *	version           INTEGER (v1_0(16)),  *	rounds            INTEGER (8..127),  *	blockSizeInBits   INTEGER (64, 128),  *	iv                OCTET STRING OPTIONAL  *	}  */
end_comment

begin_define
define|#
directive|define
name|SN_rc5_cbc
value|"RC5-CBC"
end_define

begin_define
define|#
directive|define
name|LN_rc5_cbc
value|"rc5-cbc"
end_define

begin_define
define|#
directive|define
name|NID_rc5_cbc
value|120
end_define

begin_define
define|#
directive|define
name|OBJ_rc5_cbc
value|OBJ_rsadsi,3L,8L
end_define

begin_define
define|#
directive|define
name|SN_rc5_ecb
value|"RC5-ECB"
end_define

begin_define
define|#
directive|define
name|LN_rc5_ecb
value|"rc5-ecb"
end_define

begin_define
define|#
directive|define
name|NID_rc5_ecb
value|121
end_define

begin_define
define|#
directive|define
name|SN_rc5_cfb64
value|"RC5-CFB"
end_define

begin_define
define|#
directive|define
name|LN_rc5_cfb64
value|"rc5-cfb"
end_define

begin_define
define|#
directive|define
name|NID_rc5_cfb64
value|122
end_define

begin_define
define|#
directive|define
name|SN_rc5_ofb64
value|"RC5-OFB"
end_define

begin_define
define|#
directive|define
name|LN_rc5_ofb64
value|"rc5-ofb"
end_define

begin_define
define|#
directive|define
name|NID_rc5_ofb64
value|123
end_define

begin_define
define|#
directive|define
name|SN_rle_compression
value|"RLE"
end_define

begin_define
define|#
directive|define
name|LN_rle_compression
value|"run length compression"
end_define

begin_define
define|#
directive|define
name|NID_rle_compression
value|124
end_define

begin_define
define|#
directive|define
name|OBJ_rle_compression
value|1L,1L,1L,1L,666L,1L
end_define

begin_define
define|#
directive|define
name|SN_zlib_compression
value|"ZLIB"
end_define

begin_define
define|#
directive|define
name|LN_zlib_compression
value|"zlib compression"
end_define

begin_define
define|#
directive|define
name|NID_zlib_compression
value|125
end_define

begin_define
define|#
directive|define
name|OBJ_zlib_compression
value|1L,1L,1L,1L,666L,2L
end_define

begin_define
define|#
directive|define
name|SN_ext_key_usage
value|"extendedKeyUsage"
end_define

begin_define
define|#
directive|define
name|LN_ext_key_usage
value|"X509v3 Extended Key Usage"
end_define

begin_define
define|#
directive|define
name|NID_ext_key_usage
value|126
end_define

begin_define
define|#
directive|define
name|OBJ_ext_key_usage
value|OBJ_ld_ce,37
end_define

begin_define
define|#
directive|define
name|SN_id_pkix
value|"PKIX"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix
value|127
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix
value|1L,3L,6L,1L,5L,5L,7L
end_define

begin_define
define|#
directive|define
name|SN_id_kp
value|"id-kp"
end_define

begin_define
define|#
directive|define
name|NID_id_kp
value|128
end_define

begin_define
define|#
directive|define
name|OBJ_id_kp
value|OBJ_id_pkix,3L
end_define

begin_comment
comment|/* PKIX extended key usage OIDs */
end_comment

begin_define
define|#
directive|define
name|SN_server_auth
value|"serverAuth"
end_define

begin_define
define|#
directive|define
name|LN_server_auth
value|"TLS Web Server Authentication"
end_define

begin_define
define|#
directive|define
name|NID_server_auth
value|129
end_define

begin_define
define|#
directive|define
name|OBJ_server_auth
value|OBJ_id_kp,1L
end_define

begin_define
define|#
directive|define
name|SN_client_auth
value|"clientAuth"
end_define

begin_define
define|#
directive|define
name|LN_client_auth
value|"TLS Web Client Authentication"
end_define

begin_define
define|#
directive|define
name|NID_client_auth
value|130
end_define

begin_define
define|#
directive|define
name|OBJ_client_auth
value|OBJ_id_kp,2L
end_define

begin_define
define|#
directive|define
name|SN_code_sign
value|"codeSigning"
end_define

begin_define
define|#
directive|define
name|LN_code_sign
value|"Code Signing"
end_define

begin_define
define|#
directive|define
name|NID_code_sign
value|131
end_define

begin_define
define|#
directive|define
name|OBJ_code_sign
value|OBJ_id_kp,3L
end_define

begin_define
define|#
directive|define
name|SN_email_protect
value|"emailProtection"
end_define

begin_define
define|#
directive|define
name|LN_email_protect
value|"E-mail Protection"
end_define

begin_define
define|#
directive|define
name|NID_email_protect
value|132
end_define

begin_define
define|#
directive|define
name|OBJ_email_protect
value|OBJ_id_kp,4L
end_define

begin_define
define|#
directive|define
name|SN_time_stamp
value|"timeStamping"
end_define

begin_define
define|#
directive|define
name|LN_time_stamp
value|"Time Stamping"
end_define

begin_define
define|#
directive|define
name|NID_time_stamp
value|133
end_define

begin_define
define|#
directive|define
name|OBJ_time_stamp
value|OBJ_id_kp,8L
end_define

begin_comment
comment|/* Additional extended key usage OIDs: Microsoft */
end_comment

begin_define
define|#
directive|define
name|SN_ms_code_ind
value|"msCodeInd"
end_define

begin_define
define|#
directive|define
name|LN_ms_code_ind
value|"Microsoft Individual Code Signing"
end_define

begin_define
define|#
directive|define
name|NID_ms_code_ind
value|134
end_define

begin_define
define|#
directive|define
name|OBJ_ms_code_ind
value|1L,3L,6L,1L,4L,1L,311L,2L,1L,21L
end_define

begin_define
define|#
directive|define
name|SN_ms_code_com
value|"msCodeCom"
end_define

begin_define
define|#
directive|define
name|LN_ms_code_com
value|"Microsoft Commercial Code Signing"
end_define

begin_define
define|#
directive|define
name|NID_ms_code_com
value|135
end_define

begin_define
define|#
directive|define
name|OBJ_ms_code_com
value|1L,3L,6L,1L,4L,1L,311L,2L,1L,22L
end_define

begin_define
define|#
directive|define
name|SN_ms_ctl_sign
value|"msCTLSign"
end_define

begin_define
define|#
directive|define
name|LN_ms_ctl_sign
value|"Microsoft Trust List Signing"
end_define

begin_define
define|#
directive|define
name|NID_ms_ctl_sign
value|136
end_define

begin_define
define|#
directive|define
name|OBJ_ms_ctl_sign
value|1L,3L,6L,1L,4L,1L,311L,10L,3L,1L
end_define

begin_define
define|#
directive|define
name|SN_ms_sgc
value|"msSGC"
end_define

begin_define
define|#
directive|define
name|LN_ms_sgc
value|"Microsoft Server Gated Crypto"
end_define

begin_define
define|#
directive|define
name|NID_ms_sgc
value|137
end_define

begin_define
define|#
directive|define
name|OBJ_ms_sgc
value|1L,3L,6L,1L,4L,1L,311L,10L,3L,3L
end_define

begin_define
define|#
directive|define
name|SN_ms_efs
value|"msEFS"
end_define

begin_define
define|#
directive|define
name|LN_ms_efs
value|"Microsoft Encrypted File System"
end_define

begin_define
define|#
directive|define
name|NID_ms_efs
value|138
end_define

begin_define
define|#
directive|define
name|OBJ_ms_efs
value|1L,3L,6L,1L,4L,1L,311L,10L,3L,4L
end_define

begin_comment
comment|/* Additional usage: Netscape */
end_comment

begin_define
define|#
directive|define
name|SN_ns_sgc
value|"nsSGC"
end_define

begin_define
define|#
directive|define
name|LN_ns_sgc
value|"Netscape Server Gated Crypto"
end_define

begin_define
define|#
directive|define
name|NID_ns_sgc
value|139
end_define

begin_define
define|#
directive|define
name|OBJ_ns_sgc
value|OBJ_netscape,4L,1L
end_define

begin_define
define|#
directive|define
name|SN_delta_crl
value|"deltaCRL"
end_define

begin_define
define|#
directive|define
name|LN_delta_crl
value|"X509v3 Delta CRL Indicator"
end_define

begin_define
define|#
directive|define
name|NID_delta_crl
value|140
end_define

begin_define
define|#
directive|define
name|OBJ_delta_crl
value|OBJ_ld_ce,27L
end_define

begin_define
define|#
directive|define
name|SN_crl_reason
value|"CRLReason"
end_define

begin_define
define|#
directive|define
name|LN_crl_reason
value|"CRL Reason Code"
end_define

begin_define
define|#
directive|define
name|NID_crl_reason
value|141
end_define

begin_define
define|#
directive|define
name|OBJ_crl_reason
value|OBJ_ld_ce,21L
end_define

begin_define
define|#
directive|define
name|SN_invalidity_date
value|"invalidityDate"
end_define

begin_define
define|#
directive|define
name|LN_invalidity_date
value|"Invalidity Date"
end_define

begin_define
define|#
directive|define
name|NID_invalidity_date
value|142
end_define

begin_define
define|#
directive|define
name|OBJ_invalidity_date
value|OBJ_ld_ce,24L
end_define

begin_define
define|#
directive|define
name|SN_sxnet
value|"SXNetID"
end_define

begin_define
define|#
directive|define
name|LN_sxnet
value|"Strong Extranet ID"
end_define

begin_define
define|#
directive|define
name|NID_sxnet
value|143
end_define

begin_define
define|#
directive|define
name|OBJ_sxnet
value|1L,3L,101L,1L,4L,1L
end_define

begin_comment
comment|/* PKCS12 and related OBJECT IDENTIFIERS */
end_comment

begin_define
define|#
directive|define
name|OBJ_pkcs12
value|OBJ_pkcs,12L
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs12_pbeids
value|OBJ_pkcs12, 1
end_define

begin_define
define|#
directive|define
name|SN_pbe_WithSHA1And128BitRC4
value|"PBE-SHA1-RC4-128"
end_define

begin_define
define|#
directive|define
name|LN_pbe_WithSHA1And128BitRC4
value|"pbeWithSHA1And128BitRC4"
end_define

begin_define
define|#
directive|define
name|NID_pbe_WithSHA1And128BitRC4
value|144
end_define

begin_define
define|#
directive|define
name|OBJ_pbe_WithSHA1And128BitRC4
value|OBJ_pkcs12_pbeids, 1L
end_define

begin_define
define|#
directive|define
name|SN_pbe_WithSHA1And40BitRC4
value|"PBE-SHA1-RC4-40"
end_define

begin_define
define|#
directive|define
name|LN_pbe_WithSHA1And40BitRC4
value|"pbeWithSHA1And40BitRC4"
end_define

begin_define
define|#
directive|define
name|NID_pbe_WithSHA1And40BitRC4
value|145
end_define

begin_define
define|#
directive|define
name|OBJ_pbe_WithSHA1And40BitRC4
value|OBJ_pkcs12_pbeids, 2L
end_define

begin_define
define|#
directive|define
name|SN_pbe_WithSHA1And3_Key_TripleDES_CBC
value|"PBE-SHA1-3DES"
end_define

begin_define
define|#
directive|define
name|LN_pbe_WithSHA1And3_Key_TripleDES_CBC
value|"pbeWithSHA1And3-KeyTripleDES-CBC"
end_define

begin_define
define|#
directive|define
name|NID_pbe_WithSHA1And3_Key_TripleDES_CBC
value|146
end_define

begin_define
define|#
directive|define
name|OBJ_pbe_WithSHA1And3_Key_TripleDES_CBC
value|OBJ_pkcs12_pbeids, 3L
end_define

begin_define
define|#
directive|define
name|SN_pbe_WithSHA1And2_Key_TripleDES_CBC
value|"PBE-SHA1-2DES"
end_define

begin_define
define|#
directive|define
name|LN_pbe_WithSHA1And2_Key_TripleDES_CBC
value|"pbeWithSHA1And2-KeyTripleDES-CBC"
end_define

begin_define
define|#
directive|define
name|NID_pbe_WithSHA1And2_Key_TripleDES_CBC
value|147
end_define

begin_define
define|#
directive|define
name|OBJ_pbe_WithSHA1And2_Key_TripleDES_CBC
value|OBJ_pkcs12_pbeids, 4L
end_define

begin_define
define|#
directive|define
name|SN_pbe_WithSHA1And128BitRC2_CBC
value|"PBE-SHA1-RC2-128"
end_define

begin_define
define|#
directive|define
name|LN_pbe_WithSHA1And128BitRC2_CBC
value|"pbeWithSHA1And128BitRC2-CBC"
end_define

begin_define
define|#
directive|define
name|NID_pbe_WithSHA1And128BitRC2_CBC
value|148
end_define

begin_define
define|#
directive|define
name|OBJ_pbe_WithSHA1And128BitRC2_CBC
value|OBJ_pkcs12_pbeids, 5L
end_define

begin_define
define|#
directive|define
name|SN_pbe_WithSHA1And40BitRC2_CBC
value|"PBE-SHA1-RC2-40"
end_define

begin_define
define|#
directive|define
name|LN_pbe_WithSHA1And40BitRC2_CBC
value|"pbeWithSHA1And40BitRC2-CBC"
end_define

begin_define
define|#
directive|define
name|NID_pbe_WithSHA1And40BitRC2_CBC
value|149
end_define

begin_define
define|#
directive|define
name|OBJ_pbe_WithSHA1And40BitRC2_CBC
value|OBJ_pkcs12_pbeids, 6L
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs12_Version1
value|OBJ_pkcs12, 10L
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs12_BagIds
value|OBJ_pkcs12_Version1, 1L
end_define

begin_define
define|#
directive|define
name|LN_keyBag
value|"keyBag"
end_define

begin_define
define|#
directive|define
name|NID_keyBag
value|150
end_define

begin_define
define|#
directive|define
name|OBJ_keyBag
value|OBJ_pkcs12_BagIds, 1L
end_define

begin_define
define|#
directive|define
name|LN_pkcs8ShroudedKeyBag
value|"pkcs8ShroudedKeyBag"
end_define

begin_define
define|#
directive|define
name|NID_pkcs8ShroudedKeyBag
value|151
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs8ShroudedKeyBag
value|OBJ_pkcs12_BagIds, 2L
end_define

begin_define
define|#
directive|define
name|LN_certBag
value|"certBag"
end_define

begin_define
define|#
directive|define
name|NID_certBag
value|152
end_define

begin_define
define|#
directive|define
name|OBJ_certBag
value|OBJ_pkcs12_BagIds, 3L
end_define

begin_define
define|#
directive|define
name|LN_crlBag
value|"crlBag"
end_define

begin_define
define|#
directive|define
name|NID_crlBag
value|153
end_define

begin_define
define|#
directive|define
name|OBJ_crlBag
value|OBJ_pkcs12_BagIds, 4L
end_define

begin_define
define|#
directive|define
name|LN_secretBag
value|"secretBag"
end_define

begin_define
define|#
directive|define
name|NID_secretBag
value|154
end_define

begin_define
define|#
directive|define
name|OBJ_secretBag
value|OBJ_pkcs12_BagIds, 5L
end_define

begin_define
define|#
directive|define
name|LN_safeContentsBag
value|"safeContentsBag"
end_define

begin_define
define|#
directive|define
name|NID_safeContentsBag
value|155
end_define

begin_define
define|#
directive|define
name|OBJ_safeContentsBag
value|OBJ_pkcs12_BagIds, 6L
end_define

begin_define
define|#
directive|define
name|LN_friendlyName
value|"friendlyName"
end_define

begin_define
define|#
directive|define
name|NID_friendlyName
value|156
end_define

begin_define
define|#
directive|define
name|OBJ_friendlyName
value|OBJ_pkcs9, 20L
end_define

begin_define
define|#
directive|define
name|LN_localKeyID
value|"localKeyID"
end_define

begin_define
define|#
directive|define
name|NID_localKeyID
value|157
end_define

begin_define
define|#
directive|define
name|OBJ_localKeyID
value|OBJ_pkcs9, 21L
end_define

begin_define
define|#
directive|define
name|OBJ_certTypes
value|OBJ_pkcs9, 22L
end_define

begin_define
define|#
directive|define
name|LN_x509Certificate
value|"x509Certificate"
end_define

begin_define
define|#
directive|define
name|NID_x509Certificate
value|158
end_define

begin_define
define|#
directive|define
name|OBJ_x509Certificate
value|OBJ_certTypes, 1L
end_define

begin_define
define|#
directive|define
name|LN_sdsiCertificate
value|"sdsiCertificate"
end_define

begin_define
define|#
directive|define
name|NID_sdsiCertificate
value|159
end_define

begin_define
define|#
directive|define
name|OBJ_sdsiCertificate
value|OBJ_certTypes, 2L
end_define

begin_define
define|#
directive|define
name|OBJ_crlTypes
value|OBJ_pkcs9, 23L
end_define

begin_define
define|#
directive|define
name|LN_x509Crl
value|"x509Crl"
end_define

begin_define
define|#
directive|define
name|NID_x509Crl
value|160
end_define

begin_define
define|#
directive|define
name|OBJ_x509Crl
value|OBJ_crlTypes, 1L
end_define

begin_comment
comment|/* PKCS#5 v2 OIDs */
end_comment

begin_define
define|#
directive|define
name|LN_pbes2
value|"PBES2"
end_define

begin_define
define|#
directive|define
name|NID_pbes2
value|161
end_define

begin_define
define|#
directive|define
name|OBJ_pbes2
value|OBJ_pkcs,5L,13L
end_define

begin_define
define|#
directive|define
name|LN_pbmac1
value|"PBMAC1"
end_define

begin_define
define|#
directive|define
name|NID_pbmac1
value|162
end_define

begin_define
define|#
directive|define
name|OBJ_pbmac1
value|OBJ_pkcs,5L,14L
end_define

begin_define
define|#
directive|define
name|LN_hmacWithSHA1
value|"hmacWithSHA1"
end_define

begin_define
define|#
directive|define
name|NID_hmacWithSHA1
value|163
end_define

begin_define
define|#
directive|define
name|OBJ_hmacWithSHA1
value|OBJ_rsadsi,2L,7L
end_define

begin_comment
comment|/* Policy Qualifier Ids */
end_comment

begin_define
define|#
directive|define
name|LN_id_qt_cps
value|"Policy Qualifier CPS"
end_define

begin_define
define|#
directive|define
name|SN_id_qt_cps
value|"id-qt-cps"
end_define

begin_define
define|#
directive|define
name|NID_id_qt_cps
value|164
end_define

begin_define
define|#
directive|define
name|OBJ_id_qt_cps
value|OBJ_id_pkix,2L,1L
end_define

begin_define
define|#
directive|define
name|LN_id_qt_unotice
value|"Policy Qualifier User Notice"
end_define

begin_define
define|#
directive|define
name|SN_id_qt_unotice
value|"id-qt-unotice"
end_define

begin_define
define|#
directive|define
name|NID_id_qt_unotice
value|165
end_define

begin_define
define|#
directive|define
name|OBJ_id_qt_unotice
value|OBJ_id_pkix,2L,2L
end_define

begin_define
define|#
directive|define
name|SN_rc2_64_cbc
value|"RC2-64-CBC"
end_define

begin_define
define|#
directive|define
name|LN_rc2_64_cbc
value|"rc2-64-cbc"
end_define

begin_define
define|#
directive|define
name|NID_rc2_64_cbc
value|166
end_define

begin_define
define|#
directive|define
name|SN_SMIMECapabilities
value|"SMIME-CAPS"
end_define

begin_define
define|#
directive|define
name|LN_SMIMECapabilities
value|"S/MIME Capabilities"
end_define

begin_define
define|#
directive|define
name|NID_SMIMECapabilities
value|167
end_define

begin_define
define|#
directive|define
name|OBJ_SMIMECapabilities
value|OBJ_pkcs9,15L
end_define

begin_define
define|#
directive|define
name|SN_pbeWithMD2AndRC2_CBC
value|"PBE-MD2-RC2-64"
end_define

begin_define
define|#
directive|define
name|LN_pbeWithMD2AndRC2_CBC
value|"pbeWithMD2AndRC2-CBC"
end_define

begin_define
define|#
directive|define
name|NID_pbeWithMD2AndRC2_CBC
value|168
end_define

begin_define
define|#
directive|define
name|OBJ_pbeWithMD2AndRC2_CBC
value|OBJ_pkcs,5L,4L
end_define

begin_define
define|#
directive|define
name|SN_pbeWithMD5AndRC2_CBC
value|"PBE-MD5-RC2-64"
end_define

begin_define
define|#
directive|define
name|LN_pbeWithMD5AndRC2_CBC
value|"pbeWithMD5AndRC2-CBC"
end_define

begin_define
define|#
directive|define
name|NID_pbeWithMD5AndRC2_CBC
value|169
end_define

begin_define
define|#
directive|define
name|OBJ_pbeWithMD5AndRC2_CBC
value|OBJ_pkcs,5L,6L
end_define

begin_define
define|#
directive|define
name|SN_pbeWithSHA1AndDES_CBC
value|"PBE-SHA1-DES"
end_define

begin_define
define|#
directive|define
name|LN_pbeWithSHA1AndDES_CBC
value|"pbeWithSHA1AndDES-CBC"
end_define

begin_define
define|#
directive|define
name|NID_pbeWithSHA1AndDES_CBC
value|170
end_define

begin_define
define|#
directive|define
name|OBJ_pbeWithSHA1AndDES_CBC
value|OBJ_pkcs,5L,10L
end_define

begin_comment
comment|/* Extension request OIDs */
end_comment

begin_define
define|#
directive|define
name|LN_ms_ext_req
value|"Microsoft Extension Request"
end_define

begin_define
define|#
directive|define
name|SN_ms_ext_req
value|"msExtReq"
end_define

begin_define
define|#
directive|define
name|NID_ms_ext_req
value|171
end_define

begin_define
define|#
directive|define
name|OBJ_ms_ext_req
value|1L,3L,6L,1L,4L,1L,311L,2L,1L,14L
end_define

begin_define
define|#
directive|define
name|LN_ext_req
value|"Extension Request"
end_define

begin_define
define|#
directive|define
name|SN_ext_req
value|"extReq"
end_define

begin_define
define|#
directive|define
name|NID_ext_req
value|172
end_define

begin_define
define|#
directive|define
name|OBJ_ext_req
value|OBJ_pkcs9,14L
end_define

begin_define
define|#
directive|define
name|SN_name
value|"name"
end_define

begin_define
define|#
directive|define
name|LN_name
value|"name"
end_define

begin_define
define|#
directive|define
name|NID_name
value|173
end_define

begin_define
define|#
directive|define
name|OBJ_name
value|OBJ_X509,41L
end_define

begin_define
define|#
directive|define
name|SN_dnQualifier
value|"dnQualifier"
end_define

begin_define
define|#
directive|define
name|LN_dnQualifier
value|"dnQualifier"
end_define

begin_define
define|#
directive|define
name|NID_dnQualifier
value|174
end_define

begin_define
define|#
directive|define
name|OBJ_dnQualifier
value|OBJ_X509,46L
end_define

begin_define
define|#
directive|define
name|SN_id_pe
value|"id-pe"
end_define

begin_define
define|#
directive|define
name|NID_id_pe
value|175
end_define

begin_define
define|#
directive|define
name|OBJ_id_pe
value|OBJ_id_pkix,1L
end_define

begin_define
define|#
directive|define
name|SN_id_ad
value|"id-ad"
end_define

begin_define
define|#
directive|define
name|NID_id_ad
value|176
end_define

begin_define
define|#
directive|define
name|OBJ_id_ad
value|OBJ_id_pkix,48L
end_define

begin_define
define|#
directive|define
name|SN_info_access
value|"authorityInfoAccess"
end_define

begin_define
define|#
directive|define
name|LN_info_access
value|"Authority Information Access"
end_define

begin_define
define|#
directive|define
name|NID_info_access
value|177
end_define

begin_define
define|#
directive|define
name|OBJ_info_access
value|OBJ_id_pe,1L
end_define

begin_define
define|#
directive|define
name|SN_ad_OCSP
value|"OCSP"
end_define

begin_define
define|#
directive|define
name|LN_ad_OCSP
value|"OCSP"
end_define

begin_define
define|#
directive|define
name|NID_ad_OCSP
value|178
end_define

begin_define
define|#
directive|define
name|OBJ_ad_OCSP
value|OBJ_id_ad,1L
end_define

begin_define
define|#
directive|define
name|SN_ad_ca_issuers
value|"caIssuers"
end_define

begin_define
define|#
directive|define
name|LN_ad_ca_issuers
value|"CA Issuers"
end_define

begin_define
define|#
directive|define
name|NID_ad_ca_issuers
value|179
end_define

begin_define
define|#
directive|define
name|OBJ_ad_ca_issuers
value|OBJ_id_ad,2L
end_define

begin_define
define|#
directive|define
name|SN_OCSP_sign
value|"OCSPSigning"
end_define

begin_define
define|#
directive|define
name|LN_OCSP_sign
value|"OCSP Signing"
end_define

begin_define
define|#
directive|define
name|NID_OCSP_sign
value|180
end_define

begin_define
define|#
directive|define
name|OBJ_OCSP_sign
value|OBJ_id_kp,9L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_OBJ_MAC */
end_comment

begin_include
include|#
directive|include
file|<openssl/bio.h>
end_include

begin_include
include|#
directive|include
file|<openssl/asn1.h>
end_include

begin_define
define|#
directive|define
name|OBJ_NAME_TYPE_UNDEF
value|0x00
end_define

begin_define
define|#
directive|define
name|OBJ_NAME_TYPE_MD_METH
value|0x01
end_define

begin_define
define|#
directive|define
name|OBJ_NAME_TYPE_CIPHER_METH
value|0x02
end_define

begin_define
define|#
directive|define
name|OBJ_NAME_TYPE_PKEY_METH
value|0x03
end_define

begin_define
define|#
directive|define
name|OBJ_NAME_TYPE_COMP_METH
value|0x04
end_define

begin_define
define|#
directive|define
name|OBJ_NAME_TYPE_NUM
value|0x05
end_define

begin_define
define|#
directive|define
name|OBJ_NAME_ALIAS
value|0x8000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
struct|struct
name|obj_name_st
block|{
name|int
name|type
decl_stmt|;
name|int
name|alias
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|OBJ_NAME
typedef|;
define|#
directive|define
name|OBJ_create_and_add_object
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|OBJ_create(a,b,c)
name|int
name|OBJ_NAME_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|OBJ_NAME_new_index
argument_list|(
name|unsigned
name|long
argument_list|(
operator|*
name|hash_func
argument_list|)
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
argument_list|,
name|int
argument_list|(
operator|*
name|cmp_func
argument_list|)
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
argument_list|,
name|void
argument_list|(
operator|*
name|free_func
argument_list|)
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|OBJ_NAME_get
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
name|int
name|OBJ_NAME_add
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
name|int
name|OBJ_NAME_remove
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
name|void
name|OBJ_NAME_cleanup
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
comment|/* -1 for everything */
name|ASN1_OBJECT
modifier|*
name|OBJ_dup
parameter_list|(
name|ASN1_OBJECT
modifier|*
name|o
parameter_list|)
function_decl|;
name|ASN1_OBJECT
modifier|*
name|OBJ_nid2obj
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|OBJ_nid2ln
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|OBJ_nid2sn
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
name|int
name|OBJ_obj2nid
parameter_list|(
name|ASN1_OBJECT
modifier|*
name|o
parameter_list|)
function_decl|;
name|ASN1_OBJECT
modifier|*
name|OBJ_txt2obj
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|no_name
parameter_list|)
function_decl|;
name|int
name|OBJ_obj2txt
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|buf_len
parameter_list|,
name|ASN1_OBJECT
modifier|*
name|a
parameter_list|,
name|int
name|no_name
parameter_list|)
function_decl|;
name|int
name|OBJ_txt2nid
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
name|int
name|OBJ_ln2nid
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
name|int
name|OBJ_sn2nid
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
name|int
name|OBJ_cmp
parameter_list|(
name|ASN1_OBJECT
modifier|*
name|a
parameter_list|,
name|ASN1_OBJECT
modifier|*
name|b
parameter_list|)
function_decl|;
name|char
modifier|*
name|OBJ_bsearch
parameter_list|(
name|char
modifier|*
name|key
parameter_list|,
name|char
modifier|*
name|base
parameter_list|,
name|int
name|num
parameter_list|,
name|int
name|size
parameter_list|,
name|int
function_decl|(
modifier|*
name|cmp
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
name|void
name|ERR_load_OBJ_strings
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|OBJ_new_nid
parameter_list|(
name|int
name|num
parameter_list|)
function_decl|;
name|int
name|OBJ_add_object
parameter_list|(
name|ASN1_OBJECT
modifier|*
name|obj
parameter_list|)
function_decl|;
name|int
name|OBJ_create
parameter_list|(
name|char
modifier|*
name|oid
parameter_list|,
name|char
modifier|*
name|sn
parameter_list|,
name|char
modifier|*
name|ln
parameter_list|)
function_decl|;
name|void
name|OBJ_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|OBJ_create_objects
parameter_list|(
name|BIO
modifier|*
name|in
parameter_list|)
function_decl|;
comment|/* BEGIN ERROR CODES */
comment|/* The following lines are auto generated by the script mkerr.pl. Any changes  * made after this point may be overwritten when the script is next run.  */
comment|/* Error codes for the OBJ functions. */
comment|/* Function codes. */
define|#
directive|define
name|OBJ_F_OBJ_CREATE
value|100
define|#
directive|define
name|OBJ_F_OBJ_DUP
value|101
define|#
directive|define
name|OBJ_F_OBJ_NID2LN
value|102
define|#
directive|define
name|OBJ_F_OBJ_NID2OBJ
value|103
define|#
directive|define
name|OBJ_F_OBJ_NID2SN
value|104
comment|/* Reason codes. */
define|#
directive|define
name|OBJ_R_MALLOC_FAILURE
value|100
define|#
directive|define
name|OBJ_R_UNKNOWN_NID
value|101
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

