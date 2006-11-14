begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/ui/ui.h -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* Written by Richard Levitte (richard@levitte.org) for the OpenSSL  * project 2001.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2001 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_UI_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_UI_LOCL_H
end_define

begin_include
include|#
directive|include
file|<openssl/ui.h>
end_include

begin_struct
struct|struct
name|ui_method_st
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* All the functions return 1 or non-NULL for success and 0 or NULL 	   for failure */
comment|/* Open whatever channel for this, be it the console, an X window 	   or whatever. 	   This function should use the ex_data structure to save 	   intermediate data. */
name|int
function_decl|(
modifier|*
name|ui_open_session
function_decl|)
parameter_list|(
name|UI
modifier|*
name|ui
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ui_write_string
function_decl|)
parameter_list|(
name|UI
modifier|*
name|ui
parameter_list|,
name|UI_STRING
modifier|*
name|uis
parameter_list|)
function_decl|;
comment|/* Flush the output.  If a GUI dialog box is used, this function can 	   be used to actually display it. */
name|int
function_decl|(
modifier|*
name|ui_flush
function_decl|)
parameter_list|(
name|UI
modifier|*
name|ui
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ui_read_string
function_decl|)
parameter_list|(
name|UI
modifier|*
name|ui
parameter_list|,
name|UI_STRING
modifier|*
name|uis
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ui_close_session
function_decl|)
parameter_list|(
name|UI
modifier|*
name|ui
parameter_list|)
function_decl|;
comment|/* Construct a prompt in a user-defined manner.  object_desc is a 	   textual short description of the object, for example "pass phrase", 	   and object_name is the name of the object (might be a card name or 	   a file name. 	   The returned string shall always be allocated on the heap with 	   OPENSSL_malloc(), and need to be free'd with OPENSSL_free(). */
name|char
modifier|*
function_decl|(
modifier|*
name|ui_construct_prompt
function_decl|)
parameter_list|(
name|UI
modifier|*
name|ui
parameter_list|,
specifier|const
name|char
modifier|*
name|object_desc
parameter_list|,
specifier|const
name|char
modifier|*
name|object_name
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ui_string_st
block|{
name|enum
name|UI_string_types
name|type
decl_stmt|;
comment|/* Input */
specifier|const
name|char
modifier|*
name|out_string
decl_stmt|;
comment|/* Input */
name|int
name|input_flags
decl_stmt|;
comment|/* Flags from the user */
comment|/* The following parameters are completely irrelevant for UIT_INFO, 	   and can therefore be set to 0 or NULL */
name|char
modifier|*
name|result_buf
decl_stmt|;
comment|/* Input and Output: If not NULL, user-defined 				   with size in result_maxsize.  Otherwise, it 				   may be allocated by the UI routine, meaning 				   result_minsize is going to be overwritten.*/
union|union
block|{
struct|struct
block|{
name|int
name|result_minsize
decl_stmt|;
comment|/* Input: minimum required 						   size of the result. 						*/
name|int
name|result_maxsize
decl_stmt|;
comment|/* Input: maximum permitted 						   size of the result */
specifier|const
name|char
modifier|*
name|test_buf
decl_stmt|;
comment|/* Input: test string to verify 						   against */
block|}
name|string_data
struct|;
struct|struct
block|{
specifier|const
name|char
modifier|*
name|action_desc
decl_stmt|;
comment|/* Input */
specifier|const
name|char
modifier|*
name|ok_chars
decl_stmt|;
comment|/* Input */
specifier|const
name|char
modifier|*
name|cancel_chars
decl_stmt|;
comment|/* Input */
block|}
name|boolean_data
struct|;
block|}
name|_
union|;
define|#
directive|define
name|OUT_STRING_FREEABLE
value|0x01
name|int
name|flags
decl_stmt|;
comment|/* flags for internal use */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ui_st
block|{
specifier|const
name|UI_METHOD
modifier|*
name|meth
decl_stmt|;
name|STACK_OF
argument_list|(
name|UI_STRING
argument_list|)
operator|*
name|strings
expr_stmt|;
comment|/* We might want to prompt for more 					 than one thing at a time, and 					 with different echoing status.  */
name|void
modifier|*
name|user_data
decl_stmt|;
name|CRYPTO_EX_DATA
name|ex_data
decl_stmt|;
define|#
directive|define
name|UI_FLAG_REDOABLE
value|0x0001
define|#
directive|define
name|UI_FLAG_PRINT_ERRORS
value|0x0100
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

