begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/store/str_locl.h -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* Written by Richard Levitte (richard@levitte.org) for the OpenSSL  * project 2003.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2003 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_STORE_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_STORE_LOCL_H
end_define

begin_include
include|#
directive|include
file|<openssl/crypto.h>
end_include

begin_include
include|#
directive|include
file|<openssl/store.h>
end_include

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
struct|struct
name|store_method_st
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* All the functions return a positive integer or non-NULL for success 	   and 0, a negative integer or NULL for failure */
comment|/* Initialise the STORE with private data */
name|STORE_INITIALISE_FUNC_PTR
name|init
decl_stmt|;
comment|/* Initialise the STORE with private data */
name|STORE_CLEANUP_FUNC_PTR
name|clean
decl_stmt|;
comment|/* Generate an object of a given type */
name|STORE_GENERATE_OBJECT_FUNC_PTR
name|generate_object
decl_stmt|;
comment|/* Get an object of a given type.  This function isn't really very 	   useful since the listing functions (below) can be used for the 	   same purpose and are much more general. */
name|STORE_GET_OBJECT_FUNC_PTR
name|get_object
decl_stmt|;
comment|/* Store an object of a given type. */
name|STORE_STORE_OBJECT_FUNC_PTR
name|store_object
decl_stmt|;
comment|/* Modify the attributes bound to an object of a given type. */
name|STORE_MODIFY_OBJECT_FUNC_PTR
name|modify_object
decl_stmt|;
comment|/* Revoke an object of a given type. */
name|STORE_HANDLE_OBJECT_FUNC_PTR
name|revoke_object
decl_stmt|;
comment|/* Delete an object of a given type. */
name|STORE_HANDLE_OBJECT_FUNC_PTR
name|delete_object
decl_stmt|;
comment|/* List a bunch of objects of a given type and with the associated 	   attributes. */
name|STORE_START_OBJECT_FUNC_PTR
name|list_object_start
decl_stmt|;
name|STORE_NEXT_OBJECT_FUNC_PTR
name|list_object_next
decl_stmt|;
name|STORE_END_OBJECT_FUNC_PTR
name|list_object_end
decl_stmt|;
name|STORE_END_OBJECT_FUNC_PTR
name|list_object_endp
decl_stmt|;
comment|/* Store-level function to make any necessary update operations. */
name|STORE_GENERIC_FUNC_PTR
name|update_store
decl_stmt|;
comment|/* Store-level function to get exclusive access to the store. */
name|STORE_GENERIC_FUNC_PTR
name|lock_store
decl_stmt|;
comment|/* Store-level function to release exclusive access to the store. */
name|STORE_GENERIC_FUNC_PTR
name|unlock_store
decl_stmt|;
comment|/* Generic control function */
name|STORE_CTRL_FUNC_PTR
name|ctrl
decl_stmt|;
block|}
struct|;
struct|struct
name|store_st
block|{
specifier|const
name|STORE_METHOD
modifier|*
name|meth
decl_stmt|;
comment|/* functional reference if 'meth' is ENGINE-provided */
name|ENGINE
modifier|*
name|engine
decl_stmt|;
name|CRYPTO_EX_DATA
name|ex_data
decl_stmt|;
name|int
name|references
decl_stmt|;
block|}
struct|;
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

