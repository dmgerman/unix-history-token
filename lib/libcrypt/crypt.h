begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1996  *	Brandon Gillespie.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Brandon Gillespie AND CONTRIBUTORS ``AS IS''  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Brandon Gillespie OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/* // -------------------------------------------------------------------------- // to add a new algorithm, have it export the function 'crypt_<algo>' // (where<algo> is whichever algorithm, such as 'des' or 'md5), with // the arguments ordered as follows, and the return value 'char *': // //    register const unsigned char *  -- word to encrypt //    const unsigned int              -- length of word to encrypt //    register const unsigned char *  -- salt to encrypt with //    const unsigned int              -- salt length //    char *                          -- output buffer, _CRYPT_OUTPUT_SIZE max //    char *                          -- identifier token // // such as: // //    char * //    crypt_des(register const unsigned char *pw, //              const unsigned int pl, //              register const unsigned char *sp, //              const unsigned int sl, //              char * passwd, //              char * token); // // Prototype the function below, include libraries here. // You can use the macro CRYPT_HOOK() to make it easy. */
end_comment

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|"shs.h"
end_include

begin_define
define|#
directive|define
name|_DES_CRYPT
value|0
end_define

begin_define
define|#
directive|define
name|_MD5_CRYPT
value|1
end_define

begin_define
define|#
directive|define
name|_MD5_CRYPT_OLD
value|3
end_define

begin_define
define|#
directive|define
name|_BF_CRYPT
value|2
end_define

begin_define
define|#
directive|define
name|_BF_CRYPT_OpenBSD
value|4
end_define

begin_define
define|#
directive|define
name|_SHS_CRYPT
value|5
end_define

begin_comment
comment|/* // -------------------------------------------------------------------------- // Prototypes */
end_comment

begin_define
define|#
directive|define
name|_CRYPT_HOOK
parameter_list|(
name|_type_
parameter_list|)
define|\
value|char * crypt_ ## _type_ ( \           register const unsigned char * pw, \           const unsigned int pl, \           register const unsigned char * sw, \           const unsigned int sp, \           char * passwd, \           char * token)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DES_CRYPT
end_ifdef

begin_expr_stmt
name|_CRYPT_HOOK
argument_list|(
name|des
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|_CRYPT_HOOK
argument_list|(
name|md5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_CRYPT_HOOK
argument_list|(
name|shs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|_CRYPT_HOOK
end_undef

begin_comment
comment|/* // -------------------------------------------------------------------------- // What is the default? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_CRYPT_DEFAULT_DES
end_ifdef

begin_comment
comment|/* use the 'best' encryption */
end_comment

begin_comment
comment|/* currently SHA-1 */
end_comment

begin_define
define|#
directive|define
name|_CRYPT_DEFAULT_VERSION
value|_SHS_CRYPT
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* else use DES encryption */
end_comment

begin_define
define|#
directive|define
name|_CRYPT_DEFAULT_VERSION
value|_DES_CRYPT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* // -------------------------------------------------------------------------- // other unimportant magic, enlarge as algorithms warrant, do not reduce. */
end_comment

begin_comment
comment|/* largest size of encrypted password */
end_comment

begin_define
define|#
directive|define
name|_CRYPT_OUTPUT_SIZE
value|_PASSWORD_LEN
end_define

begin_define
define|#
directive|define
name|_CRYPT_MAX_SALT_LEN
value|24
end_define

begin_comment
comment|/* token=5 salt=16 extra=4 */
end_comment

begin_comment
comment|/* magic sizes not defined elsewhere, cleaner through defs */
end_comment

begin_define
define|#
directive|define
name|_MD5_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|_SHS_SIZE
value|20
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_CRYPT_C_
end_ifndef

begin_function_decl
specifier|extern
name|void
name|to64
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|unsigned
name|long
name|v
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

