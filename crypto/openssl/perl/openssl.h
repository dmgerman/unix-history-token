begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

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
include|#
directive|include
file|"EXTERN.h"
include|#
directive|include
file|"perl.h"
include|#
directive|include
file|"XSUB.h"
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|datum_st
block|{
name|char
modifier|*
name|dptr
decl_stmt|;
name|int
name|dsize
decl_stmt|;
block|}
name|datum
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<openssl/crypto.h>
end_include

begin_include
include|#
directive|include
file|<openssl/buffer.h>
end_include

begin_include
include|#
directive|include
file|<openssl/bio.h>
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ssl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|pr_name
parameter_list|(
name|name
parameter_list|)
value|printf("%s\n",name)
end_define

begin_define
define|#
directive|define
name|pr_name_d
parameter_list|(
name|name
parameter_list|,
name|p2
parameter_list|)
value|printf("%s %d\n",name,p2)
end_define

begin_define
define|#
directive|define
name|pr_name_dd
parameter_list|(
name|name
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
value|printf("%s %d %d\n",name,p2,p3)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|pr_name
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|pr_name_d
parameter_list|(
name|name
parameter_list|,
name|p2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|pr_name_dd
parameter_list|(
name|name
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|SV
modifier|*
name|new_ref
parameter_list|(
name|char
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|obj
parameter_list|,
name|int
name|mort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ex_new
parameter_list|(
name|char
modifier|*
name|obj
parameter_list|,
name|SV
modifier|*
name|data
parameter_list|,
name|CRYPTO_EX_DATA
modifier|*
name|ad
parameter_list|,
name|int
name|idx
parameter_list|,
name|long
name|argl
parameter_list|,
name|char
modifier|*
name|argp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ex_cleanup
parameter_list|(
name|char
modifier|*
name|obj
parameter_list|,
name|SV
modifier|*
name|data
parameter_list|,
name|CRYPTO_EX_DATA
modifier|*
name|ad
parameter_list|,
name|int
name|idx
parameter_list|,
name|long
name|argl
parameter_list|,
name|char
modifier|*
name|argp
parameter_list|)
function_decl|;
end_function_decl

end_unit

