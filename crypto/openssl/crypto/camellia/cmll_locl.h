begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/camellia/camellia_locl.h -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright 2006 NTT (Nippon Telegraph and Telephone Corporation) .   * ALL RIGHTS RESERVED.  *  * Intellectual Property information for Camellia:  *     http://info.isl.ntt.co.jp/crypt/eng/info/chiteki.html  *  * News Release for Announcement of Camellia open source:  *     http://www.ntt.co.jp/news/news06e/0604/060413a.html  *  * The Camellia Code included herein is developed by  * NTT (Nippon Telegraph and Telephone Corporation), and is contributed  * to the OpenSSL project.  *  * The Camellia Code is licensed pursuant to the OpenSSL open source  * license provided below.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2006 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_CAMELLIA_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_CAMELLIA_LOCL_H
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u8
typedef|;
end_typedef

begin_function_decl
name|int
name|Camellia_Ekeygen
parameter_list|(
name|int
name|keyBitLength
parameter_list|,
specifier|const
name|u8
modifier|*
name|rawKey
parameter_list|,
name|KEY_TABLE_TYPE
name|keyTable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Camellia_EncryptBlock_Rounds
parameter_list|(
name|int
name|grandRounds
parameter_list|,
specifier|const
name|u8
name|plaintext
index|[]
parameter_list|,
specifier|const
name|KEY_TABLE_TYPE
name|keyTable
parameter_list|,
name|u8
name|ciphertext
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Camellia_DecryptBlock_Rounds
parameter_list|(
name|int
name|grandRounds
parameter_list|,
specifier|const
name|u8
name|ciphertext
index|[]
parameter_list|,
specifier|const
name|KEY_TABLE_TYPE
name|keyTable
parameter_list|,
name|u8
name|plaintext
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Camellia_EncryptBlock
parameter_list|(
name|int
name|keyBitLength
parameter_list|,
specifier|const
name|u8
name|plaintext
index|[]
parameter_list|,
specifier|const
name|KEY_TABLE_TYPE
name|keyTable
parameter_list|,
name|u8
name|ciphertext
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Camellia_DecryptBlock
parameter_list|(
name|int
name|keyBitLength
parameter_list|,
specifier|const
name|u8
name|ciphertext
index|[]
parameter_list|,
specifier|const
name|KEY_TABLE_TYPE
name|keyTable
parameter_list|,
name|u8
name|plaintext
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|private_Camellia_set_key
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|userKey
parameter_list|,
specifier|const
name|int
name|bits
parameter_list|,
name|CAMELLIA_KEY
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef HEADER_CAMELLIA_LOCL_H */
end_comment

end_unit

