begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ext_dat.h */
end_comment

begin_comment
comment|/* Written by Dr Stephen N Henson (shenson@bigfoot.com) for the OpenSSL  * project 1999.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1999 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_comment
comment|/* This file contains a table of "standard" extensions */
end_comment

begin_decl_stmt
specifier|extern
name|X509V3_EXT_METHOD
name|v3_bcons
decl_stmt|,
name|v3_nscert
decl_stmt|,
name|v3_key_usage
decl_stmt|,
name|v3_ext_ku
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|X509V3_EXT_METHOD
name|v3_pkey_usage_period
decl_stmt|,
name|v3_sxnet
decl_stmt|,
name|v3_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|X509V3_EXT_METHOD
name|v3_ns_ia5_list
index|[]
decl_stmt|,
name|v3_alt
index|[]
decl_stmt|,
name|v3_skey_id
decl_stmt|,
name|v3_akey_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|X509V3_EXT_METHOD
name|v3_crl_num
decl_stmt|,
name|v3_crl_reason
decl_stmt|,
name|v3_cpols
decl_stmt|,
name|v3_crld
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This table will be searched using OBJ_bsearch so it *must* kept in  * order of the ext_nid values.  */
end_comment

begin_decl_stmt
specifier|static
name|X509V3_EXT_METHOD
modifier|*
name|standard_exts
index|[]
init|=
block|{
operator|&
name|v3_nscert
block|,
operator|&
name|v3_ns_ia5_list
index|[
literal|0
index|]
block|,
operator|&
name|v3_ns_ia5_list
index|[
literal|1
index|]
block|,
operator|&
name|v3_ns_ia5_list
index|[
literal|2
index|]
block|,
operator|&
name|v3_ns_ia5_list
index|[
literal|3
index|]
block|,
operator|&
name|v3_ns_ia5_list
index|[
literal|4
index|]
block|,
operator|&
name|v3_ns_ia5_list
index|[
literal|5
index|]
block|,
operator|&
name|v3_ns_ia5_list
index|[
literal|6
index|]
block|,
operator|&
name|v3_skey_id
block|,
operator|&
name|v3_key_usage
block|,
operator|&
name|v3_pkey_usage_period
block|,
operator|&
name|v3_alt
index|[
literal|0
index|]
block|,
operator|&
name|v3_alt
index|[
literal|1
index|]
block|,
operator|&
name|v3_bcons
block|,
operator|&
name|v3_crl_num
block|,
operator|&
name|v3_cpols
block|,
operator|&
name|v3_akey_id
block|,
operator|&
name|v3_crld
block|,
operator|&
name|v3_ext_ku
block|,
operator|&
name|v3_crl_reason
block|,
operator|&
name|v3_sxnet
block|,
operator|&
name|v3_info
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of standard extensions */
end_comment

begin_define
define|#
directive|define
name|STANDARD_EXTENSION_COUNT
value|(sizeof(standard_exts)/sizeof(X509V3_EXT_METHOD *))
end_define

end_unit

