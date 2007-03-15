begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/md/md2.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1997 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_MD2_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_MD2_H
end_define

begin_include
include|#
directive|include
file|<openssl/opensslconf.h>
end_include

begin_comment
comment|/* OPENSSL_NO_MD2, MD2_INT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_NO_MD2
end_ifdef

begin_error
error|#
directive|error
error|MD2 is disabled.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|MD2_DIGEST_LENGTH
value|16
end_define

begin_define
define|#
directive|define
name|MD2_BLOCK
value|16
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
name|MD2state_st
block|{
name|unsigned
name|int
name|num
decl_stmt|;
name|unsigned
name|char
name|data
index|[
name|MD2_BLOCK
index|]
decl_stmt|;
name|MD2_INT
name|cksm
index|[
name|MD2_BLOCK
index|]
decl_stmt|;
name|MD2_INT
name|state
index|[
name|MD2_BLOCK
index|]
decl_stmt|;
block|}
name|MD2_CTX
typedef|;
specifier|const
name|char
modifier|*
name|MD2_options
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|MD2_Init
parameter_list|(
name|MD2_CTX
modifier|*
name|c
parameter_list|)
function_decl|;
name|int
name|MD2_Update
parameter_list|(
name|MD2_CTX
modifier|*
name|c
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
name|int
name|MD2_Final
parameter_list|(
name|unsigned
name|char
modifier|*
name|md
parameter_list|,
name|MD2_CTX
modifier|*
name|c
parameter_list|)
function_decl|;
name|unsigned
name|char
modifier|*
name|MD2
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|d
parameter_list|,
name|size_t
name|n
parameter_list|,
name|unsigned
name|char
modifier|*
name|md
parameter_list|)
function_decl|;
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

