begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lib/obj/obj_mac.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1997 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* THIS FILE IS GENERATED FROM objects.txt by objects.pl via the  * following command:  * perl objects.pl objects.txt obj_mac.num obj_mac.h  */
end_comment

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
name|SN_iso
value|"ISO"
end_define

begin_define
define|#
directive|define
name|LN_iso
value|"iso"
end_define

begin_define
define|#
directive|define
name|NID_iso
value|181
end_define

begin_define
define|#
directive|define
name|OBJ_iso
value|1L
end_define

begin_define
define|#
directive|define
name|SN_member_body
value|"member-body"
end_define

begin_define
define|#
directive|define
name|LN_member_body
value|"ISO Member Body"
end_define

begin_define
define|#
directive|define
name|NID_member_body
value|182
end_define

begin_define
define|#
directive|define
name|OBJ_member_body
value|OBJ_iso,2L
end_define

begin_define
define|#
directive|define
name|SN_ISO_US
value|"ISO-US"
end_define

begin_define
define|#
directive|define
name|LN_ISO_US
value|"ISO US Member Body"
end_define

begin_define
define|#
directive|define
name|NID_ISO_US
value|183
end_define

begin_define
define|#
directive|define
name|OBJ_ISO_US
value|OBJ_member_body,840L
end_define

begin_define
define|#
directive|define
name|SN_X9_57
value|"X9-57"
end_define

begin_define
define|#
directive|define
name|LN_X9_57
value|"X9.57"
end_define

begin_define
define|#
directive|define
name|NID_X9_57
value|184
end_define

begin_define
define|#
directive|define
name|OBJ_X9_57
value|OBJ_ISO_US,10040L
end_define

begin_define
define|#
directive|define
name|SN_X9cm
value|"X9cm"
end_define

begin_define
define|#
directive|define
name|LN_X9cm
value|"X9.57 CM ?"
end_define

begin_define
define|#
directive|define
name|NID_X9cm
value|185
end_define

begin_define
define|#
directive|define
name|OBJ_X9cm
value|OBJ_X9_57,4L
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
value|OBJ_X9cm,1L
end_define

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
value|OBJ_X9cm,3L
end_define

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
value|OBJ_ISO_US,113533L,7L,66L,10L
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
value|OBJ_ISO_US,113533L,7L,66L,12L
end_define

begin_define
define|#
directive|define
name|SN_rsadsi
value|"rsadsi"
end_define

begin_define
define|#
directive|define
name|LN_rsadsi
value|"RSA Data Security, Inc."
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
value|OBJ_ISO_US,113549L
end_define

begin_define
define|#
directive|define
name|SN_pkcs
value|"pkcs"
end_define

begin_define
define|#
directive|define
name|LN_pkcs
value|"RSA Data Security, Inc. PKCS"
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
name|SN_pkcs1
value|"pkcs1"
end_define

begin_define
define|#
directive|define
name|NID_pkcs1
value|186
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs1
value|OBJ_pkcs,1L
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
value|OBJ_pkcs1,1L
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
value|OBJ_pkcs1,2L
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
value|OBJ_pkcs1,4L
end_define

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
value|OBJ_pkcs1,5L
end_define

begin_define
define|#
directive|define
name|SN_pkcs3
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
name|SN_pkcs5
value|"pkcs5"
end_define

begin_define
define|#
directive|define
name|NID_pkcs5
value|187
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs5
value|OBJ_pkcs,5L
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
value|OBJ_pkcs5,1L
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
value|OBJ_pkcs5,3L
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
value|OBJ_pkcs5,4L
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
value|OBJ_pkcs5,6L
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
value|OBJ_pkcs5,10L
end_define

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
value|OBJ_pkcs5,11L
end_define

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
value|OBJ_pkcs5,12L
end_define

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
value|OBJ_pkcs5,13L
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
value|OBJ_pkcs5,14L
end_define

begin_define
define|#
directive|define
name|SN_pkcs7
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
name|SN_pkcs9
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
name|SN_ext_req
value|"extReq"
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
name|SN_SMIME
value|"SMIME"
end_define

begin_define
define|#
directive|define
name|LN_SMIME
value|"S/MIME"
end_define

begin_define
define|#
directive|define
name|NID_SMIME
value|188
end_define

begin_define
define|#
directive|define
name|OBJ_SMIME
value|OBJ_pkcs9,16L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_mod
value|"id-smime-mod"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_mod
value|189
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_mod
value|OBJ_SMIME,0L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_ct
value|"id-smime-ct"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_ct
value|190
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_ct
value|OBJ_SMIME,1L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa
value|"id-smime-aa"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa
value|191
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa
value|OBJ_SMIME,2L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_alg
value|"id-smime-alg"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_alg
value|192
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_alg
value|OBJ_SMIME,3L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_cd
value|"id-smime-cd"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_cd
value|193
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_cd
value|OBJ_SMIME,4L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_spq
value|"id-smime-spq"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_spq
value|194
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_spq
value|OBJ_SMIME,5L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_cti
value|"id-smime-cti"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_cti
value|195
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_cti
value|OBJ_SMIME,6L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_mod_cms
value|"id-smime-mod-cms"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_mod_cms
value|196
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_mod_cms
value|OBJ_id_smime_mod,1L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_mod_ess
value|"id-smime-mod-ess"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_mod_ess
value|197
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_mod_ess
value|OBJ_id_smime_mod,2L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_mod_oid
value|"id-smime-mod-oid"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_mod_oid
value|198
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_mod_oid
value|OBJ_id_smime_mod,3L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_mod_msg_v3
value|"id-smime-mod-msg-v3"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_mod_msg_v3
value|199
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_mod_msg_v3
value|OBJ_id_smime_mod,4L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_mod_ets_eSignature_88
value|"id-smime-mod-ets-eSignature-88"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_mod_ets_eSignature_88
value|200
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_mod_ets_eSignature_88
value|OBJ_id_smime_mod,5L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_mod_ets_eSignature_97
value|"id-smime-mod-ets-eSignature-97"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_mod_ets_eSignature_97
value|201
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_mod_ets_eSignature_97
value|OBJ_id_smime_mod,6L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_mod_ets_eSigPolicy_88
value|"id-smime-mod-ets-eSigPolicy-88"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_mod_ets_eSigPolicy_88
value|202
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_mod_ets_eSigPolicy_88
value|OBJ_id_smime_mod,7L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_mod_ets_eSigPolicy_97
value|"id-smime-mod-ets-eSigPolicy-97"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_mod_ets_eSigPolicy_97
value|203
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_mod_ets_eSigPolicy_97
value|OBJ_id_smime_mod,8L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_ct_receipt
value|"id-smime-ct-receipt"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_ct_receipt
value|204
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_ct_receipt
value|OBJ_id_smime_ct,1L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_ct_authData
value|"id-smime-ct-authData"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_ct_authData
value|205
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_ct_authData
value|OBJ_id_smime_ct,2L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_ct_publishCert
value|"id-smime-ct-publishCert"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_ct_publishCert
value|206
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_ct_publishCert
value|OBJ_id_smime_ct,3L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_ct_TSTInfo
value|"id-smime-ct-TSTInfo"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_ct_TSTInfo
value|207
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_ct_TSTInfo
value|OBJ_id_smime_ct,4L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_ct_TDTInfo
value|"id-smime-ct-TDTInfo"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_ct_TDTInfo
value|208
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_ct_TDTInfo
value|OBJ_id_smime_ct,5L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_ct_contentInfo
value|"id-smime-ct-contentInfo"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_ct_contentInfo
value|209
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_ct_contentInfo
value|OBJ_id_smime_ct,6L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_ct_DVCSRequestData
value|"id-smime-ct-DVCSRequestData"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_ct_DVCSRequestData
value|210
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_ct_DVCSRequestData
value|OBJ_id_smime_ct,7L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_ct_DVCSResponseData
value|"id-smime-ct-DVCSResponseData"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_ct_DVCSResponseData
value|211
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_ct_DVCSResponseData
value|OBJ_id_smime_ct,8L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_receiptRequest
value|"id-smime-aa-receiptRequest"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_receiptRequest
value|212
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_receiptRequest
value|OBJ_id_smime_aa,1L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_securityLabel
value|"id-smime-aa-securityLabel"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_securityLabel
value|213
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_securityLabel
value|OBJ_id_smime_aa,2L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_mlExpandHistory
value|"id-smime-aa-mlExpandHistory"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_mlExpandHistory
value|214
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_mlExpandHistory
value|OBJ_id_smime_aa,3L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_contentHint
value|"id-smime-aa-contentHint"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_contentHint
value|215
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_contentHint
value|OBJ_id_smime_aa,4L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_msgSigDigest
value|"id-smime-aa-msgSigDigest"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_msgSigDigest
value|216
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_msgSigDigest
value|OBJ_id_smime_aa,5L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_encapContentType
value|"id-smime-aa-encapContentType"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_encapContentType
value|217
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_encapContentType
value|OBJ_id_smime_aa,6L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_contentIdentifier
value|"id-smime-aa-contentIdentifier"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_contentIdentifier
value|218
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_contentIdentifier
value|OBJ_id_smime_aa,7L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_macValue
value|"id-smime-aa-macValue"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_macValue
value|219
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_macValue
value|OBJ_id_smime_aa,8L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_equivalentLabels
value|"id-smime-aa-equivalentLabels"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_equivalentLabels
value|220
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_equivalentLabels
value|OBJ_id_smime_aa,9L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_contentReference
value|"id-smime-aa-contentReference"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_contentReference
value|221
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_contentReference
value|OBJ_id_smime_aa,10L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_encrypKeyPref
value|"id-smime-aa-encrypKeyPref"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_encrypKeyPref
value|222
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_encrypKeyPref
value|OBJ_id_smime_aa,11L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_signingCertificate
value|"id-smime-aa-signingCertificate"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_signingCertificate
value|223
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_signingCertificate
value|OBJ_id_smime_aa,12L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_smimeEncryptCerts
value|"id-smime-aa-smimeEncryptCerts"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_smimeEncryptCerts
value|224
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_smimeEncryptCerts
value|OBJ_id_smime_aa,13L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_timeStampToken
value|"id-smime-aa-timeStampToken"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_timeStampToken
value|225
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_timeStampToken
value|OBJ_id_smime_aa,14L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_sigPolicyId
value|"id-smime-aa-ets-sigPolicyId"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_sigPolicyId
value|226
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_sigPolicyId
value|OBJ_id_smime_aa,15L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_commitmentType
value|"id-smime-aa-ets-commitmentType"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_commitmentType
value|227
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_commitmentType
value|OBJ_id_smime_aa,16L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_signerLocation
value|"id-smime-aa-ets-signerLocation"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_signerLocation
value|228
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_signerLocation
value|OBJ_id_smime_aa,17L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_signerAttr
value|"id-smime-aa-ets-signerAttr"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_signerAttr
value|229
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_signerAttr
value|OBJ_id_smime_aa,18L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_otherSigCert
value|"id-smime-aa-ets-otherSigCert"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_otherSigCert
value|230
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_otherSigCert
value|OBJ_id_smime_aa,19L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_contentTimestamp
value|"id-smime-aa-ets-contentTimestamp"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_contentTimestamp
value|231
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_contentTimestamp
value|OBJ_id_smime_aa,20L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_CertificateRefs
value|"id-smime-aa-ets-CertificateRefs"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_CertificateRefs
value|232
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_CertificateRefs
value|OBJ_id_smime_aa,21L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_RevocationRefs
value|"id-smime-aa-ets-RevocationRefs"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_RevocationRefs
value|233
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_RevocationRefs
value|OBJ_id_smime_aa,22L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_certValues
value|"id-smime-aa-ets-certValues"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_certValues
value|234
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_certValues
value|OBJ_id_smime_aa,23L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_revocationValues
value|"id-smime-aa-ets-revocationValues"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_revocationValues
value|235
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_revocationValues
value|OBJ_id_smime_aa,24L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_escTimeStamp
value|"id-smime-aa-ets-escTimeStamp"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_escTimeStamp
value|236
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_escTimeStamp
value|OBJ_id_smime_aa,25L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_certCRLTimestamp
value|"id-smime-aa-ets-certCRLTimestamp"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_certCRLTimestamp
value|237
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_certCRLTimestamp
value|OBJ_id_smime_aa,26L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_ets_archiveTimeStamp
value|"id-smime-aa-ets-archiveTimeStamp"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_ets_archiveTimeStamp
value|238
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_ets_archiveTimeStamp
value|OBJ_id_smime_aa,27L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_signatureType
value|"id-smime-aa-signatureType"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_signatureType
value|239
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_signatureType
value|OBJ_id_smime_aa,28L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_aa_dvcs_dvc
value|"id-smime-aa-dvcs-dvc"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_aa_dvcs_dvc
value|240
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_aa_dvcs_dvc
value|OBJ_id_smime_aa,29L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_alg_ESDHwith3DES
value|"id-smime-alg-ESDHwith3DES"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_alg_ESDHwith3DES
value|241
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_alg_ESDHwith3DES
value|OBJ_id_smime_alg,1L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_alg_ESDHwithRC2
value|"id-smime-alg-ESDHwithRC2"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_alg_ESDHwithRC2
value|242
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_alg_ESDHwithRC2
value|OBJ_id_smime_alg,2L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_alg_3DESwrap
value|"id-smime-alg-3DESwrap"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_alg_3DESwrap
value|243
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_alg_3DESwrap
value|OBJ_id_smime_alg,3L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_alg_RC2wrap
value|"id-smime-alg-RC2wrap"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_alg_RC2wrap
value|244
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_alg_RC2wrap
value|OBJ_id_smime_alg,4L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_alg_ESDH
value|"id-smime-alg-ESDH"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_alg_ESDH
value|245
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_alg_ESDH
value|OBJ_id_smime_alg,5L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_alg_CMS3DESwrap
value|"id-smime-alg-CMS3DESwrap"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_alg_CMS3DESwrap
value|246
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_alg_CMS3DESwrap
value|OBJ_id_smime_alg,6L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_alg_CMSRC2wrap
value|"id-smime-alg-CMSRC2wrap"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_alg_CMSRC2wrap
value|247
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_alg_CMSRC2wrap
value|OBJ_id_smime_alg,7L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_cd_ldap
value|"id-smime-cd-ldap"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_cd_ldap
value|248
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_cd_ldap
value|OBJ_id_smime_cd,1L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_spq_ets_sqt_uri
value|"id-smime-spq-ets-sqt-uri"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_spq_ets_sqt_uri
value|249
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_spq_ets_sqt_uri
value|OBJ_id_smime_spq,1L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_spq_ets_sqt_unotice
value|"id-smime-spq-ets-sqt-unotice"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_spq_ets_sqt_unotice
value|250
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_spq_ets_sqt_unotice
value|OBJ_id_smime_spq,2L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_cti_ets_proofOfOrigin
value|"id-smime-cti-ets-proofOfOrigin"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_cti_ets_proofOfOrigin
value|251
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_cti_ets_proofOfOrigin
value|OBJ_id_smime_cti,1L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_cti_ets_proofOfReceipt
value|"id-smime-cti-ets-proofOfReceipt"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_cti_ets_proofOfReceipt
value|252
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_cti_ets_proofOfReceipt
value|OBJ_id_smime_cti,2L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_cti_ets_proofOfDelivery
value|"id-smime-cti-ets-proofOfDelivery"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_cti_ets_proofOfDelivery
value|253
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_cti_ets_proofOfDelivery
value|OBJ_id_smime_cti,3L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_cti_ets_proofOfSender
value|"id-smime-cti-ets-proofOfSender"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_cti_ets_proofOfSender
value|254
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_cti_ets_proofOfSender
value|OBJ_id_smime_cti,4L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_cti_ets_proofOfApproval
value|"id-smime-cti-ets-proofOfApproval"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_cti_ets_proofOfApproval
value|255
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_cti_ets_proofOfApproval
value|OBJ_id_smime_cti,5L
end_define

begin_define
define|#
directive|define
name|SN_id_smime_cti_ets_proofOfCreation
value|"id-smime-cti-ets-proofOfCreation"
end_define

begin_define
define|#
directive|define
name|NID_id_smime_cti_ets_proofOfCreation
value|256
end_define

begin_define
define|#
directive|define
name|OBJ_id_smime_cti_ets_proofOfCreation
value|OBJ_id_smime_cti,6L
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
value|OBJ_pkcs9,20L
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
value|OBJ_pkcs9,21L
end_define

begin_define
define|#
directive|define
name|OBJ_certTypes
value|OBJ_pkcs9,22L
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
value|OBJ_certTypes,1L
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
value|OBJ_certTypes,2L
end_define

begin_define
define|#
directive|define
name|OBJ_crlTypes
value|OBJ_pkcs9,23L
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
value|OBJ_crlTypes,1L
end_define

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
value|OBJ_pkcs12,1L
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
value|OBJ_pkcs12_pbeids,1L
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
value|OBJ_pkcs12_pbeids,2L
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
value|OBJ_pkcs12_pbeids,3L
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
value|OBJ_pkcs12_pbeids,4L
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
value|OBJ_pkcs12_pbeids,5L
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
value|OBJ_pkcs12_pbeids,6L
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs12_Version1
value|OBJ_pkcs12,10L
end_define

begin_define
define|#
directive|define
name|OBJ_pkcs12_BagIds
value|OBJ_pkcs12_Version1,1L
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
value|OBJ_pkcs12_BagIds,1L
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
value|OBJ_pkcs12_BagIds,2L
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
value|OBJ_pkcs12_BagIds,3L
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
value|OBJ_pkcs12_BagIds,4L
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
value|OBJ_pkcs12_BagIds,5L
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
value|OBJ_pkcs12_BagIds,6L
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
name|SN_md4
value|"MD4"
end_define

begin_define
define|#
directive|define
name|LN_md4
value|"md4"
end_define

begin_define
define|#
directive|define
name|NID_md4
value|257
end_define

begin_define
define|#
directive|define
name|OBJ_md4
value|OBJ_rsadsi,2L,4L
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
name|NID_md5_sha1
value|114
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
name|SN_ms_ext_req
value|"msExtReq"
end_define

begin_define
define|#
directive|define
name|LN_ms_ext_req
value|"Microsoft Extension Request"
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
name|SN_id_pkix_mod
value|"id-pkix-mod"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_mod
value|258
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_mod
value|OBJ_id_pkix,0L
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
name|SN_id_qt
value|"id-qt"
end_define

begin_define
define|#
directive|define
name|NID_id_qt
value|259
end_define

begin_define
define|#
directive|define
name|OBJ_id_qt
value|OBJ_id_pkix,2L
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

begin_define
define|#
directive|define
name|SN_id_it
value|"id-it"
end_define

begin_define
define|#
directive|define
name|NID_id_it
value|260
end_define

begin_define
define|#
directive|define
name|OBJ_id_it
value|OBJ_id_pkix,4L
end_define

begin_define
define|#
directive|define
name|SN_id_pkip
value|"id-pkip"
end_define

begin_define
define|#
directive|define
name|NID_id_pkip
value|261
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkip
value|OBJ_id_pkix,5L
end_define

begin_define
define|#
directive|define
name|SN_id_alg
value|"id-alg"
end_define

begin_define
define|#
directive|define
name|NID_id_alg
value|262
end_define

begin_define
define|#
directive|define
name|OBJ_id_alg
value|OBJ_id_pkix,6L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc
value|"id-cmc"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc
value|263
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc
value|OBJ_id_pkix,7L
end_define

begin_define
define|#
directive|define
name|SN_id_on
value|"id-on"
end_define

begin_define
define|#
directive|define
name|NID_id_on
value|264
end_define

begin_define
define|#
directive|define
name|OBJ_id_on
value|OBJ_id_pkix,8L
end_define

begin_define
define|#
directive|define
name|SN_id_pda
value|"id-pda"
end_define

begin_define
define|#
directive|define
name|NID_id_pda
value|265
end_define

begin_define
define|#
directive|define
name|OBJ_id_pda
value|OBJ_id_pkix,9L
end_define

begin_define
define|#
directive|define
name|SN_id_aca
value|"id-aca"
end_define

begin_define
define|#
directive|define
name|NID_id_aca
value|266
end_define

begin_define
define|#
directive|define
name|OBJ_id_aca
value|OBJ_id_pkix,10L
end_define

begin_define
define|#
directive|define
name|SN_id_qcs
value|"id-qcs"
end_define

begin_define
define|#
directive|define
name|NID_id_qcs
value|267
end_define

begin_define
define|#
directive|define
name|OBJ_id_qcs
value|OBJ_id_pkix,11L
end_define

begin_define
define|#
directive|define
name|SN_id_cct
value|"id-cct"
end_define

begin_define
define|#
directive|define
name|NID_id_cct
value|268
end_define

begin_define
define|#
directive|define
name|OBJ_id_cct
value|OBJ_id_pkix,12L
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
name|SN_id_pkix1_explicit_88
value|"id-pkix1-explicit-88"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix1_explicit_88
value|269
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix1_explicit_88
value|OBJ_id_pkix_mod,1L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix1_implicit_88
value|"id-pkix1-implicit-88"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix1_implicit_88
value|270
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix1_implicit_88
value|OBJ_id_pkix_mod,2L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix1_explicit_93
value|"id-pkix1-explicit-93"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix1_explicit_93
value|271
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix1_explicit_93
value|OBJ_id_pkix_mod,3L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix1_implicit_93
value|"id-pkix1-implicit-93"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix1_implicit_93
value|272
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix1_implicit_93
value|OBJ_id_pkix_mod,4L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_crmf
value|"id-mod-crmf"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_crmf
value|273
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_crmf
value|OBJ_id_pkix_mod,5L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_cmc
value|"id-mod-cmc"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_cmc
value|274
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_cmc
value|OBJ_id_pkix_mod,6L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_kea_profile_88
value|"id-mod-kea-profile-88"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_kea_profile_88
value|275
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_kea_profile_88
value|OBJ_id_pkix_mod,7L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_kea_profile_93
value|"id-mod-kea-profile-93"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_kea_profile_93
value|276
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_kea_profile_93
value|OBJ_id_pkix_mod,8L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_cmp
value|"id-mod-cmp"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_cmp
value|277
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_cmp
value|OBJ_id_pkix_mod,9L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_qualified_cert_88
value|"id-mod-qualified-cert-88"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_qualified_cert_88
value|278
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_qualified_cert_88
value|OBJ_id_pkix_mod,10L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_qualified_cert_93
value|"id-mod-qualified-cert-93"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_qualified_cert_93
value|279
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_qualified_cert_93
value|OBJ_id_pkix_mod,11L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_attribute_cert
value|"id-mod-attribute-cert"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_attribute_cert
value|280
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_attribute_cert
value|OBJ_id_pkix_mod,12L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_timestamp_protocol
value|"id-mod-timestamp-protocol"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_timestamp_protocol
value|281
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_timestamp_protocol
value|OBJ_id_pkix_mod,13L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_ocsp
value|"id-mod-ocsp"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_ocsp
value|282
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_ocsp
value|OBJ_id_pkix_mod,14L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_dvcs
value|"id-mod-dvcs"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_dvcs
value|283
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_dvcs
value|OBJ_id_pkix_mod,15L
end_define

begin_define
define|#
directive|define
name|SN_id_mod_cmp2000
value|"id-mod-cmp2000"
end_define

begin_define
define|#
directive|define
name|NID_id_mod_cmp2000
value|284
end_define

begin_define
define|#
directive|define
name|OBJ_id_mod_cmp2000
value|OBJ_id_pkix_mod,16L
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
name|SN_biometricInfo
value|"biometricInfo"
end_define

begin_define
define|#
directive|define
name|LN_biometricInfo
value|"Biometric Info"
end_define

begin_define
define|#
directive|define
name|NID_biometricInfo
value|285
end_define

begin_define
define|#
directive|define
name|OBJ_biometricInfo
value|OBJ_id_pe,2L
end_define

begin_define
define|#
directive|define
name|SN_qcStatements
value|"qcStatements"
end_define

begin_define
define|#
directive|define
name|NID_qcStatements
value|286
end_define

begin_define
define|#
directive|define
name|OBJ_qcStatements
value|OBJ_id_pe,3L
end_define

begin_define
define|#
directive|define
name|SN_ac_auditEntity
value|"ac-auditEntity"
end_define

begin_define
define|#
directive|define
name|NID_ac_auditEntity
value|287
end_define

begin_define
define|#
directive|define
name|OBJ_ac_auditEntity
value|OBJ_id_pe,4L
end_define

begin_define
define|#
directive|define
name|SN_ac_targeting
value|"ac-targeting"
end_define

begin_define
define|#
directive|define
name|NID_ac_targeting
value|288
end_define

begin_define
define|#
directive|define
name|OBJ_ac_targeting
value|OBJ_id_pe,5L
end_define

begin_define
define|#
directive|define
name|SN_aaControls
value|"aaControls"
end_define

begin_define
define|#
directive|define
name|NID_aaControls
value|289
end_define

begin_define
define|#
directive|define
name|OBJ_aaControls
value|OBJ_id_pe,6L
end_define

begin_define
define|#
directive|define
name|SN_sbqp_ipAddrBlock
value|"sbqp-ipAddrBlock"
end_define

begin_define
define|#
directive|define
name|NID_sbqp_ipAddrBlock
value|290
end_define

begin_define
define|#
directive|define
name|OBJ_sbqp_ipAddrBlock
value|OBJ_id_pe,7L
end_define

begin_define
define|#
directive|define
name|SN_sbqp_autonomousSysNum
value|"sbqp-autonomousSysNum"
end_define

begin_define
define|#
directive|define
name|NID_sbqp_autonomousSysNum
value|291
end_define

begin_define
define|#
directive|define
name|OBJ_sbqp_autonomousSysNum
value|OBJ_id_pe,8L
end_define

begin_define
define|#
directive|define
name|SN_sbqp_routerIdentifier
value|"sbqp-routerIdentifier"
end_define

begin_define
define|#
directive|define
name|NID_sbqp_routerIdentifier
value|292
end_define

begin_define
define|#
directive|define
name|OBJ_sbqp_routerIdentifier
value|OBJ_id_pe,9L
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
name|LN_id_qt_cps
value|"Policy Qualifier CPS"
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
value|OBJ_id_qt,1L
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
name|LN_id_qt_unotice
value|"Policy Qualifier User Notice"
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
value|OBJ_id_qt,2L
end_define

begin_define
define|#
directive|define
name|SN_textNotice
value|"textNotice"
end_define

begin_define
define|#
directive|define
name|NID_textNotice
value|293
end_define

begin_define
define|#
directive|define
name|OBJ_textNotice
value|OBJ_id_qt,3L
end_define

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
name|SN_ipsecEndSystem
value|"ipsecEndSystem"
end_define

begin_define
define|#
directive|define
name|LN_ipsecEndSystem
value|"IPSec End System"
end_define

begin_define
define|#
directive|define
name|NID_ipsecEndSystem
value|294
end_define

begin_define
define|#
directive|define
name|OBJ_ipsecEndSystem
value|OBJ_id_kp,5L
end_define

begin_define
define|#
directive|define
name|SN_ipsecTunnel
value|"ipsecTunnel"
end_define

begin_define
define|#
directive|define
name|LN_ipsecTunnel
value|"IPSec Tunnel"
end_define

begin_define
define|#
directive|define
name|NID_ipsecTunnel
value|295
end_define

begin_define
define|#
directive|define
name|OBJ_ipsecTunnel
value|OBJ_id_kp,6L
end_define

begin_define
define|#
directive|define
name|SN_ipsecUser
value|"ipsecUser"
end_define

begin_define
define|#
directive|define
name|LN_ipsecUser
value|"IPSec User"
end_define

begin_define
define|#
directive|define
name|NID_ipsecUser
value|296
end_define

begin_define
define|#
directive|define
name|OBJ_ipsecUser
value|OBJ_id_kp,7L
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

begin_define
define|#
directive|define
name|SN_dvcs
value|"DVCS"
end_define

begin_define
define|#
directive|define
name|LN_dvcs
value|"dvcs"
end_define

begin_define
define|#
directive|define
name|NID_dvcs
value|297
end_define

begin_define
define|#
directive|define
name|OBJ_dvcs
value|OBJ_id_kp,10L
end_define

begin_define
define|#
directive|define
name|SN_id_it_caProtEncCert
value|"id-it-caProtEncCert"
end_define

begin_define
define|#
directive|define
name|NID_id_it_caProtEncCert
value|298
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_caProtEncCert
value|OBJ_id_it,1L
end_define

begin_define
define|#
directive|define
name|SN_id_it_signKeyPairTypes
value|"id-it-signKeyPairTypes"
end_define

begin_define
define|#
directive|define
name|NID_id_it_signKeyPairTypes
value|299
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_signKeyPairTypes
value|OBJ_id_it,2L
end_define

begin_define
define|#
directive|define
name|SN_id_it_encKeyPairTypes
value|"id-it-encKeyPairTypes"
end_define

begin_define
define|#
directive|define
name|NID_id_it_encKeyPairTypes
value|300
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_encKeyPairTypes
value|OBJ_id_it,3L
end_define

begin_define
define|#
directive|define
name|SN_id_it_preferredSymmAlg
value|"id-it-preferredSymmAlg"
end_define

begin_define
define|#
directive|define
name|NID_id_it_preferredSymmAlg
value|301
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_preferredSymmAlg
value|OBJ_id_it,4L
end_define

begin_define
define|#
directive|define
name|SN_id_it_caKeyUpdateInfo
value|"id-it-caKeyUpdateInfo"
end_define

begin_define
define|#
directive|define
name|NID_id_it_caKeyUpdateInfo
value|302
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_caKeyUpdateInfo
value|OBJ_id_it,5L
end_define

begin_define
define|#
directive|define
name|SN_id_it_currentCRL
value|"id-it-currentCRL"
end_define

begin_define
define|#
directive|define
name|NID_id_it_currentCRL
value|303
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_currentCRL
value|OBJ_id_it,6L
end_define

begin_define
define|#
directive|define
name|SN_id_it_unsupportedOIDs
value|"id-it-unsupportedOIDs"
end_define

begin_define
define|#
directive|define
name|NID_id_it_unsupportedOIDs
value|304
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_unsupportedOIDs
value|OBJ_id_it,7L
end_define

begin_define
define|#
directive|define
name|SN_id_it_subscriptionRequest
value|"id-it-subscriptionRequest"
end_define

begin_define
define|#
directive|define
name|NID_id_it_subscriptionRequest
value|305
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_subscriptionRequest
value|OBJ_id_it,8L
end_define

begin_define
define|#
directive|define
name|SN_id_it_subscriptionResponse
value|"id-it-subscriptionResponse"
end_define

begin_define
define|#
directive|define
name|NID_id_it_subscriptionResponse
value|306
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_subscriptionResponse
value|OBJ_id_it,9L
end_define

begin_define
define|#
directive|define
name|SN_id_it_keyPairParamReq
value|"id-it-keyPairParamReq"
end_define

begin_define
define|#
directive|define
name|NID_id_it_keyPairParamReq
value|307
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_keyPairParamReq
value|OBJ_id_it,10L
end_define

begin_define
define|#
directive|define
name|SN_id_it_keyPairParamRep
value|"id-it-keyPairParamRep"
end_define

begin_define
define|#
directive|define
name|NID_id_it_keyPairParamRep
value|308
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_keyPairParamRep
value|OBJ_id_it,11L
end_define

begin_define
define|#
directive|define
name|SN_id_it_revPassphrase
value|"id-it-revPassphrase"
end_define

begin_define
define|#
directive|define
name|NID_id_it_revPassphrase
value|309
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_revPassphrase
value|OBJ_id_it,12L
end_define

begin_define
define|#
directive|define
name|SN_id_it_implicitConfirm
value|"id-it-implicitConfirm"
end_define

begin_define
define|#
directive|define
name|NID_id_it_implicitConfirm
value|310
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_implicitConfirm
value|OBJ_id_it,13L
end_define

begin_define
define|#
directive|define
name|SN_id_it_confirmWaitTime
value|"id-it-confirmWaitTime"
end_define

begin_define
define|#
directive|define
name|NID_id_it_confirmWaitTime
value|311
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_confirmWaitTime
value|OBJ_id_it,14L
end_define

begin_define
define|#
directive|define
name|SN_id_it_origPKIMessage
value|"id-it-origPKIMessage"
end_define

begin_define
define|#
directive|define
name|NID_id_it_origPKIMessage
value|312
end_define

begin_define
define|#
directive|define
name|OBJ_id_it_origPKIMessage
value|OBJ_id_it,15L
end_define

begin_define
define|#
directive|define
name|SN_id_regCtrl
value|"id-regCtrl"
end_define

begin_define
define|#
directive|define
name|NID_id_regCtrl
value|313
end_define

begin_define
define|#
directive|define
name|OBJ_id_regCtrl
value|OBJ_id_pkip,1L
end_define

begin_define
define|#
directive|define
name|SN_id_regInfo
value|"id-regInfo"
end_define

begin_define
define|#
directive|define
name|NID_id_regInfo
value|314
end_define

begin_define
define|#
directive|define
name|OBJ_id_regInfo
value|OBJ_id_pkip,2L
end_define

begin_define
define|#
directive|define
name|SN_id_regCtrl_regToken
value|"id-regCtrl-regToken"
end_define

begin_define
define|#
directive|define
name|NID_id_regCtrl_regToken
value|315
end_define

begin_define
define|#
directive|define
name|OBJ_id_regCtrl_regToken
value|OBJ_id_regCtrl,1L
end_define

begin_define
define|#
directive|define
name|SN_id_regCtrl_authenticator
value|"id-regCtrl-authenticator"
end_define

begin_define
define|#
directive|define
name|NID_id_regCtrl_authenticator
value|316
end_define

begin_define
define|#
directive|define
name|OBJ_id_regCtrl_authenticator
value|OBJ_id_regCtrl,2L
end_define

begin_define
define|#
directive|define
name|SN_id_regCtrl_pkiPublicationInfo
value|"id-regCtrl-pkiPublicationInfo"
end_define

begin_define
define|#
directive|define
name|NID_id_regCtrl_pkiPublicationInfo
value|317
end_define

begin_define
define|#
directive|define
name|OBJ_id_regCtrl_pkiPublicationInfo
value|OBJ_id_regCtrl,3L
end_define

begin_define
define|#
directive|define
name|SN_id_regCtrl_pkiArchiveOptions
value|"id-regCtrl-pkiArchiveOptions"
end_define

begin_define
define|#
directive|define
name|NID_id_regCtrl_pkiArchiveOptions
value|318
end_define

begin_define
define|#
directive|define
name|OBJ_id_regCtrl_pkiArchiveOptions
value|OBJ_id_regCtrl,4L
end_define

begin_define
define|#
directive|define
name|SN_id_regCtrl_oldCertID
value|"id-regCtrl-oldCertID"
end_define

begin_define
define|#
directive|define
name|NID_id_regCtrl_oldCertID
value|319
end_define

begin_define
define|#
directive|define
name|OBJ_id_regCtrl_oldCertID
value|OBJ_id_regCtrl,5L
end_define

begin_define
define|#
directive|define
name|SN_id_regCtrl_protocolEncrKey
value|"id-regCtrl-protocolEncrKey"
end_define

begin_define
define|#
directive|define
name|NID_id_regCtrl_protocolEncrKey
value|320
end_define

begin_define
define|#
directive|define
name|OBJ_id_regCtrl_protocolEncrKey
value|OBJ_id_regCtrl,6L
end_define

begin_define
define|#
directive|define
name|SN_id_regInfo_utf8Pairs
value|"id-regInfo-utf8Pairs"
end_define

begin_define
define|#
directive|define
name|NID_id_regInfo_utf8Pairs
value|321
end_define

begin_define
define|#
directive|define
name|OBJ_id_regInfo_utf8Pairs
value|OBJ_id_regInfo,1L
end_define

begin_define
define|#
directive|define
name|SN_id_regInfo_certReq
value|"id-regInfo-certReq"
end_define

begin_define
define|#
directive|define
name|NID_id_regInfo_certReq
value|322
end_define

begin_define
define|#
directive|define
name|OBJ_id_regInfo_certReq
value|OBJ_id_regInfo,2L
end_define

begin_define
define|#
directive|define
name|SN_id_alg_des40
value|"id-alg-des40"
end_define

begin_define
define|#
directive|define
name|NID_id_alg_des40
value|323
end_define

begin_define
define|#
directive|define
name|OBJ_id_alg_des40
value|OBJ_id_alg,1L
end_define

begin_define
define|#
directive|define
name|SN_id_alg_noSignature
value|"id-alg-noSignature"
end_define

begin_define
define|#
directive|define
name|NID_id_alg_noSignature
value|324
end_define

begin_define
define|#
directive|define
name|OBJ_id_alg_noSignature
value|OBJ_id_alg,2L
end_define

begin_define
define|#
directive|define
name|SN_id_alg_dh_sig_hmac_sha1
value|"id-alg-dh-sig-hmac-sha1"
end_define

begin_define
define|#
directive|define
name|NID_id_alg_dh_sig_hmac_sha1
value|325
end_define

begin_define
define|#
directive|define
name|OBJ_id_alg_dh_sig_hmac_sha1
value|OBJ_id_alg,3L
end_define

begin_define
define|#
directive|define
name|SN_id_alg_dh_pop
value|"id-alg-dh-pop"
end_define

begin_define
define|#
directive|define
name|NID_id_alg_dh_pop
value|326
end_define

begin_define
define|#
directive|define
name|OBJ_id_alg_dh_pop
value|OBJ_id_alg,4L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_statusInfo
value|"id-cmc-statusInfo"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_statusInfo
value|327
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_statusInfo
value|OBJ_id_cmc,1L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_identification
value|"id-cmc-identification"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_identification
value|328
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_identification
value|OBJ_id_cmc,2L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_identityProof
value|"id-cmc-identityProof"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_identityProof
value|329
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_identityProof
value|OBJ_id_cmc,3L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_dataReturn
value|"id-cmc-dataReturn"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_dataReturn
value|330
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_dataReturn
value|OBJ_id_cmc,4L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_transactionId
value|"id-cmc-transactionId"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_transactionId
value|331
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_transactionId
value|OBJ_id_cmc,5L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_senderNonce
value|"id-cmc-senderNonce"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_senderNonce
value|332
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_senderNonce
value|OBJ_id_cmc,6L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_recipientNonce
value|"id-cmc-recipientNonce"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_recipientNonce
value|333
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_recipientNonce
value|OBJ_id_cmc,7L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_addExtensions
value|"id-cmc-addExtensions"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_addExtensions
value|334
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_addExtensions
value|OBJ_id_cmc,8L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_encryptedPOP
value|"id-cmc-encryptedPOP"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_encryptedPOP
value|335
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_encryptedPOP
value|OBJ_id_cmc,9L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_decryptedPOP
value|"id-cmc-decryptedPOP"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_decryptedPOP
value|336
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_decryptedPOP
value|OBJ_id_cmc,10L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_lraPOPWitness
value|"id-cmc-lraPOPWitness"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_lraPOPWitness
value|337
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_lraPOPWitness
value|OBJ_id_cmc,11L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_getCert
value|"id-cmc-getCert"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_getCert
value|338
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_getCert
value|OBJ_id_cmc,15L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_getCRL
value|"id-cmc-getCRL"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_getCRL
value|339
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_getCRL
value|OBJ_id_cmc,16L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_revokeRequest
value|"id-cmc-revokeRequest"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_revokeRequest
value|340
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_revokeRequest
value|OBJ_id_cmc,17L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_regInfo
value|"id-cmc-regInfo"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_regInfo
value|341
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_regInfo
value|OBJ_id_cmc,18L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_responseInfo
value|"id-cmc-responseInfo"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_responseInfo
value|342
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_responseInfo
value|OBJ_id_cmc,19L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_queryPending
value|"id-cmc-queryPending"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_queryPending
value|343
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_queryPending
value|OBJ_id_cmc,21L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_popLinkRandom
value|"id-cmc-popLinkRandom"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_popLinkRandom
value|344
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_popLinkRandom
value|OBJ_id_cmc,22L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_popLinkWitness
value|"id-cmc-popLinkWitness"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_popLinkWitness
value|345
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_popLinkWitness
value|OBJ_id_cmc,23L
end_define

begin_define
define|#
directive|define
name|SN_id_cmc_confirmCertAcceptance
value|"id-cmc-confirmCertAcceptance"
end_define

begin_define
define|#
directive|define
name|NID_id_cmc_confirmCertAcceptance
value|346
end_define

begin_define
define|#
directive|define
name|OBJ_id_cmc_confirmCertAcceptance
value|OBJ_id_cmc,24L
end_define

begin_define
define|#
directive|define
name|SN_id_on_personalData
value|"id-on-personalData"
end_define

begin_define
define|#
directive|define
name|NID_id_on_personalData
value|347
end_define

begin_define
define|#
directive|define
name|OBJ_id_on_personalData
value|OBJ_id_on,1L
end_define

begin_define
define|#
directive|define
name|SN_id_pda_dateOfBirth
value|"id-pda-dateOfBirth"
end_define

begin_define
define|#
directive|define
name|NID_id_pda_dateOfBirth
value|348
end_define

begin_define
define|#
directive|define
name|OBJ_id_pda_dateOfBirth
value|OBJ_id_pda,1L
end_define

begin_define
define|#
directive|define
name|SN_id_pda_placeOfBirth
value|"id-pda-placeOfBirth"
end_define

begin_define
define|#
directive|define
name|NID_id_pda_placeOfBirth
value|349
end_define

begin_define
define|#
directive|define
name|OBJ_id_pda_placeOfBirth
value|OBJ_id_pda,2L
end_define

begin_define
define|#
directive|define
name|SN_id_pda_pseudonym
value|"id-pda-pseudonym"
end_define

begin_define
define|#
directive|define
name|NID_id_pda_pseudonym
value|350
end_define

begin_define
define|#
directive|define
name|OBJ_id_pda_pseudonym
value|OBJ_id_pda,3L
end_define

begin_define
define|#
directive|define
name|SN_id_pda_gender
value|"id-pda-gender"
end_define

begin_define
define|#
directive|define
name|NID_id_pda_gender
value|351
end_define

begin_define
define|#
directive|define
name|OBJ_id_pda_gender
value|OBJ_id_pda,4L
end_define

begin_define
define|#
directive|define
name|SN_id_pda_countryOfCitizenship
value|"id-pda-countryOfCitizenship"
end_define

begin_define
define|#
directive|define
name|NID_id_pda_countryOfCitizenship
value|352
end_define

begin_define
define|#
directive|define
name|OBJ_id_pda_countryOfCitizenship
value|OBJ_id_pda,5L
end_define

begin_define
define|#
directive|define
name|SN_id_pda_countryOfResidence
value|"id-pda-countryOfResidence"
end_define

begin_define
define|#
directive|define
name|NID_id_pda_countryOfResidence
value|353
end_define

begin_define
define|#
directive|define
name|OBJ_id_pda_countryOfResidence
value|OBJ_id_pda,6L
end_define

begin_define
define|#
directive|define
name|SN_id_aca_authenticationInfo
value|"id-aca-authenticationInfo"
end_define

begin_define
define|#
directive|define
name|NID_id_aca_authenticationInfo
value|354
end_define

begin_define
define|#
directive|define
name|OBJ_id_aca_authenticationInfo
value|OBJ_id_aca,1L
end_define

begin_define
define|#
directive|define
name|SN_id_aca_accessIdentity
value|"id-aca-accessIdentity"
end_define

begin_define
define|#
directive|define
name|NID_id_aca_accessIdentity
value|355
end_define

begin_define
define|#
directive|define
name|OBJ_id_aca_accessIdentity
value|OBJ_id_aca,2L
end_define

begin_define
define|#
directive|define
name|SN_id_aca_chargingIdentity
value|"id-aca-chargingIdentity"
end_define

begin_define
define|#
directive|define
name|NID_id_aca_chargingIdentity
value|356
end_define

begin_define
define|#
directive|define
name|OBJ_id_aca_chargingIdentity
value|OBJ_id_aca,3L
end_define

begin_define
define|#
directive|define
name|SN_id_aca_group
value|"id-aca-group"
end_define

begin_define
define|#
directive|define
name|NID_id_aca_group
value|357
end_define

begin_define
define|#
directive|define
name|OBJ_id_aca_group
value|OBJ_id_aca,4L
end_define

begin_define
define|#
directive|define
name|SN_id_aca_role
value|"id-aca-role"
end_define

begin_define
define|#
directive|define
name|NID_id_aca_role
value|358
end_define

begin_define
define|#
directive|define
name|OBJ_id_aca_role
value|OBJ_id_aca,5L
end_define

begin_define
define|#
directive|define
name|SN_id_qcs_pkixQCSyntax_v1
value|"id-qcs-pkixQCSyntax-v1"
end_define

begin_define
define|#
directive|define
name|NID_id_qcs_pkixQCSyntax_v1
value|359
end_define

begin_define
define|#
directive|define
name|OBJ_id_qcs_pkixQCSyntax_v1
value|OBJ_id_qcs,1L
end_define

begin_define
define|#
directive|define
name|SN_id_cct_crs
value|"id-cct-crs"
end_define

begin_define
define|#
directive|define
name|NID_id_cct_crs
value|360
end_define

begin_define
define|#
directive|define
name|OBJ_id_cct_crs
value|OBJ_id_cct,1L
end_define

begin_define
define|#
directive|define
name|SN_id_cct_PKIData
value|"id-cct-PKIData"
end_define

begin_define
define|#
directive|define
name|NID_id_cct_PKIData
value|361
end_define

begin_define
define|#
directive|define
name|OBJ_id_cct_PKIData
value|OBJ_id_cct,2L
end_define

begin_define
define|#
directive|define
name|SN_id_cct_PKIResponse
value|"id-cct-PKIResponse"
end_define

begin_define
define|#
directive|define
name|NID_id_cct_PKIResponse
value|362
end_define

begin_define
define|#
directive|define
name|OBJ_id_cct_PKIResponse
value|OBJ_id_cct,3L
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
name|SN_ad_timeStamping
value|"ad_timestamping"
end_define

begin_define
define|#
directive|define
name|LN_ad_timeStamping
value|"AD Time Stamping"
end_define

begin_define
define|#
directive|define
name|NID_ad_timeStamping
value|363
end_define

begin_define
define|#
directive|define
name|OBJ_ad_timeStamping
value|OBJ_id_ad,3L
end_define

begin_define
define|#
directive|define
name|SN_ad_dvcs
value|"AD_DVCS"
end_define

begin_define
define|#
directive|define
name|LN_ad_dvcs
value|"ad dvcs"
end_define

begin_define
define|#
directive|define
name|NID_ad_dvcs
value|364
end_define

begin_define
define|#
directive|define
name|OBJ_ad_dvcs
value|OBJ_id_ad,4L
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP
value|OBJ_ad_OCSP
end_define

begin_define
define|#
directive|define
name|SN_id_pkix_OCSP_basic
value|"basicOCSPResponse"
end_define

begin_define
define|#
directive|define
name|LN_id_pkix_OCSP_basic
value|"Basic OCSP Response"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_OCSP_basic
value|365
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP_basic
value|OBJ_id_pkix_OCSP,1L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix_OCSP_Nonce
value|"Nonce"
end_define

begin_define
define|#
directive|define
name|LN_id_pkix_OCSP_Nonce
value|"OCSP Nonce"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_OCSP_Nonce
value|366
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP_Nonce
value|OBJ_id_pkix_OCSP,2L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix_OCSP_CrlID
value|"CrlID"
end_define

begin_define
define|#
directive|define
name|LN_id_pkix_OCSP_CrlID
value|"OCSP CRL ID"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_OCSP_CrlID
value|367
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP_CrlID
value|OBJ_id_pkix_OCSP,3L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix_OCSP_acceptableResponses
value|"acceptableResponses"
end_define

begin_define
define|#
directive|define
name|LN_id_pkix_OCSP_acceptableResponses
value|"Acceptable OCSP Responses"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_OCSP_acceptableResponses
value|368
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP_acceptableResponses
value|OBJ_id_pkix_OCSP,4L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix_OCSP_noCheck
value|"noCheck"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_OCSP_noCheck
value|369
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP_noCheck
value|OBJ_id_pkix_OCSP,5L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix_OCSP_archiveCutoff
value|"archiveCutoff"
end_define

begin_define
define|#
directive|define
name|LN_id_pkix_OCSP_archiveCutoff
value|"OCSP Archive Cutoff"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_OCSP_archiveCutoff
value|370
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP_archiveCutoff
value|OBJ_id_pkix_OCSP,6L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix_OCSP_serviceLocator
value|"serviceLocator"
end_define

begin_define
define|#
directive|define
name|LN_id_pkix_OCSP_serviceLocator
value|"OCSP Service Locator"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_OCSP_serviceLocator
value|371
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP_serviceLocator
value|OBJ_id_pkix_OCSP,7L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix_OCSP_extendedStatus
value|"extendedStatus"
end_define

begin_define
define|#
directive|define
name|LN_id_pkix_OCSP_extendedStatus
value|"Extended OCSP Status"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_OCSP_extendedStatus
value|372
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP_extendedStatus
value|OBJ_id_pkix_OCSP,8L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix_OCSP_valid
value|"valid"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_OCSP_valid
value|373
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP_valid
value|OBJ_id_pkix_OCSP,9L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix_OCSP_path
value|"path"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_OCSP_path
value|374
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP_path
value|OBJ_id_pkix_OCSP,10L
end_define

begin_define
define|#
directive|define
name|SN_id_pkix_OCSP_trustRoot
value|"trustRoot"
end_define

begin_define
define|#
directive|define
name|LN_id_pkix_OCSP_trustRoot
value|"Trust Root"
end_define

begin_define
define|#
directive|define
name|NID_id_pkix_OCSP_trustRoot
value|375
end_define

begin_define
define|#
directive|define
name|OBJ_id_pkix_OCSP_trustRoot
value|OBJ_id_pkix_OCSP,11L
end_define

begin_define
define|#
directive|define
name|SN_algorithm
value|"algorithm"
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
value|376
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

begin_define
define|#
directive|define
name|OBJ_des_cbc
value|OBJ_algorithm,7L
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

begin_define
define|#
directive|define
name|OBJ_des_cfb64
value|OBJ_algorithm,9L
end_define

begin_define
define|#
directive|define
name|SN_rsaSignature
value|"rsaSignature"
end_define

begin_define
define|#
directive|define
name|NID_rsaSignature
value|377
end_define

begin_define
define|#
directive|define
name|OBJ_rsaSignature
value|OBJ_algorithm,11L
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

begin_define
define|#
directive|define
name|OBJ_dsaWithSHA1_2
value|OBJ_algorithm,27L
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

begin_define
define|#
directive|define
name|SN_X500
value|"X500"
end_define

begin_define
define|#
directive|define
name|LN_X500
value|"directory services (X.500)"
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
name|SN_X509
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
name|SN_X500algorithms
value|"X500algorithms"
end_define

begin_define
define|#
directive|define
name|LN_X500algorithms
value|"directory services - algorithms"
end_define

begin_define
define|#
directive|define
name|NID_X500algorithms
value|378
end_define

begin_define
define|#
directive|define
name|OBJ_X500algorithms
value|OBJ_X500,8L
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
value|OBJ_X500algorithms,1L,1L
end_define

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
value|"mdc2WithRSA"
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
value|OBJ_X500algorithms,3L,100L
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
value|OBJ_X500algorithms,3L,101L
end_define

begin_define
define|#
directive|define
name|SN_id_ce
value|"id-ce"
end_define

begin_define
define|#
directive|define
name|NID_id_ce
value|81
end_define

begin_define
define|#
directive|define
name|OBJ_id_ce
value|OBJ_X500,29L
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
value|OBJ_id_ce,14L
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
value|OBJ_id_ce,15L
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
value|OBJ_id_ce,16L
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
value|OBJ_id_ce,17L
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
value|OBJ_id_ce,18L
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
value|OBJ_id_ce,19L
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
value|OBJ_id_ce,20L
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
value|"X509v3 CRL Reason Code"
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
value|OBJ_id_ce,21L
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
value|OBJ_id_ce,24L
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
value|OBJ_id_ce,27L
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
value|OBJ_id_ce,31L
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
value|OBJ_id_ce,32L
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
value|OBJ_id_ce,35L
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
value|OBJ_id_ce,37L
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
name|SN_org
value|"ORG"
end_define

begin_define
define|#
directive|define
name|LN_org
value|"org"
end_define

begin_define
define|#
directive|define
name|NID_org
value|379
end_define

begin_define
define|#
directive|define
name|OBJ_org
value|OBJ_iso,3L
end_define

begin_define
define|#
directive|define
name|SN_dod
value|"DOD"
end_define

begin_define
define|#
directive|define
name|LN_dod
value|"dod"
end_define

begin_define
define|#
directive|define
name|NID_dod
value|380
end_define

begin_define
define|#
directive|define
name|OBJ_dod
value|OBJ_org,6L
end_define

begin_define
define|#
directive|define
name|SN_iana
value|"IANA"
end_define

begin_define
define|#
directive|define
name|LN_iana
value|"iana"
end_define

begin_define
define|#
directive|define
name|NID_iana
value|381
end_define

begin_define
define|#
directive|define
name|OBJ_iana
value|OBJ_dod,1L
end_define

begin_define
define|#
directive|define
name|OBJ_internet
value|OBJ_iana
end_define

begin_define
define|#
directive|define
name|SN_Directory
value|"directory"
end_define

begin_define
define|#
directive|define
name|LN_Directory
value|"Directory"
end_define

begin_define
define|#
directive|define
name|NID_Directory
value|382
end_define

begin_define
define|#
directive|define
name|OBJ_Directory
value|OBJ_internet,1L
end_define

begin_define
define|#
directive|define
name|SN_Management
value|"mgmt"
end_define

begin_define
define|#
directive|define
name|LN_Management
value|"Management"
end_define

begin_define
define|#
directive|define
name|NID_Management
value|383
end_define

begin_define
define|#
directive|define
name|OBJ_Management
value|OBJ_internet,2L
end_define

begin_define
define|#
directive|define
name|SN_Experimental
value|"experimental"
end_define

begin_define
define|#
directive|define
name|LN_Experimental
value|"Experimental"
end_define

begin_define
define|#
directive|define
name|NID_Experimental
value|384
end_define

begin_define
define|#
directive|define
name|OBJ_Experimental
value|OBJ_internet,3L
end_define

begin_define
define|#
directive|define
name|SN_Private
value|"private"
end_define

begin_define
define|#
directive|define
name|LN_Private
value|"Private"
end_define

begin_define
define|#
directive|define
name|NID_Private
value|385
end_define

begin_define
define|#
directive|define
name|OBJ_Private
value|OBJ_internet,4L
end_define

begin_define
define|#
directive|define
name|SN_Security
value|"security"
end_define

begin_define
define|#
directive|define
name|LN_Security
value|"Security"
end_define

begin_define
define|#
directive|define
name|NID_Security
value|386
end_define

begin_define
define|#
directive|define
name|OBJ_Security
value|OBJ_internet,5L
end_define

begin_define
define|#
directive|define
name|SN_SNMPv2
value|"snmpv2"
end_define

begin_define
define|#
directive|define
name|LN_SNMPv2
value|"SNMPv2"
end_define

begin_define
define|#
directive|define
name|NID_SNMPv2
value|387
end_define

begin_define
define|#
directive|define
name|OBJ_SNMPv2
value|OBJ_internet,6L
end_define

begin_define
define|#
directive|define
name|SN_Mail
value|"mail"
end_define

begin_define
define|#
directive|define
name|LN_Mail
value|"Mail"
end_define

begin_define
define|#
directive|define
name|NID_Mail
value|388
end_define

begin_define
define|#
directive|define
name|OBJ_Mail
value|OBJ_internet,7L
end_define

begin_define
define|#
directive|define
name|SN_Enterprises
value|"enterprises"
end_define

begin_define
define|#
directive|define
name|LN_Enterprises
value|"Enterprises"
end_define

begin_define
define|#
directive|define
name|NID_Enterprises
value|389
end_define

begin_define
define|#
directive|define
name|OBJ_Enterprises
value|OBJ_private,1L
end_define

begin_define
define|#
directive|define
name|SN_dcObject
value|"dcobject"
end_define

begin_define
define|#
directive|define
name|LN_dcObject
value|"dcObject"
end_define

begin_define
define|#
directive|define
name|NID_dcObject
value|390
end_define

begin_define
define|#
directive|define
name|OBJ_dcObject
value|OBJ_enterprises,1466L,344L
end_define

begin_define
define|#
directive|define
name|SN_domainComponent
value|"DC"
end_define

begin_define
define|#
directive|define
name|LN_domainComponent
value|"domainComponent"
end_define

begin_define
define|#
directive|define
name|NID_domainComponent
value|391
end_define

begin_define
define|#
directive|define
name|OBJ_domainComponent
value|0L,9L,2342L,19200300L,100L,1L,25L
end_define

begin_define
define|#
directive|define
name|SN_Domain
value|"domain"
end_define

begin_define
define|#
directive|define
name|LN_Domain
value|"Domain"
end_define

begin_define
define|#
directive|define
name|NID_Domain
value|392
end_define

begin_define
define|#
directive|define
name|OBJ_Domain
value|0L,9L,2342L,19200300L,100L,4L,13L
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

end_unit

