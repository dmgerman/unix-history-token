begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* apps/eay.c */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|MONOLITH
end_define

begin_define
define|#
directive|define
name|USE_SOCKETS
end_define

begin_include
include|#
directive|include
file|"openssl/e_os.h"
end_include

begin_include
include|#
directive|include
file|<openssl/bio.h>
end_include

begin_include
include|#
directive|include
file|<openssl/stack.h>
end_include

begin_include
include|#
directive|include
file|<openssl/lhash.h>
end_include

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rand.h>
end_include

begin_include
include|#
directive|include
file|<openssl/conf.h>
end_include

begin_include
include|#
directive|include
file|<openssl/txt_db.h>
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
file|<openssl/pkcs7.h>
end_include

begin_include
include|#
directive|include
file|<openssl/pem.h>
end_include

begin_include
include|#
directive|include
file|<openssl/asn1.h>
end_include

begin_include
include|#
directive|include
file|<openssl/objects.h>
end_include

begin_define
define|#
directive|define
name|MONOLITH
end_define

begin_include
include|#
directive|include
file|"openssl.c"
end_include

begin_include
include|#
directive|include
file|"apps.c"
end_include

begin_include
include|#
directive|include
file|"asn1pars.c"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_RSA
end_ifndef

begin_include
include|#
directive|include
file|"ca.c"
end_include

begin_include
include|#
directive|include
file|"genrsa.c"
end_include

begin_include
include|#
directive|include
file|"req.c"
end_include

begin_include
include|#
directive|include
file|"rsa.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DH
end_ifndef

begin_include
include|#
directive|include
file|"gendh.c"
end_include

begin_include
include|#
directive|include
file|"dh.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"crl.c"
end_include

begin_include
include|#
directive|include
file|"crl2p7.c"
end_include

begin_include
include|#
directive|include
file|"dgst.c"
end_include

begin_include
include|#
directive|include
file|"enc.c"
end_include

begin_include
include|#
directive|include
file|"errstr.c"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_SSL2
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|NO_SSL3
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SOCK
end_ifndef

begin_include
include|#
directive|include
file|"s_cb.c"
end_include

begin_include
include|#
directive|include
file|"s_client.c"
end_include

begin_include
include|#
directive|include
file|"s_server.c"
end_include

begin_include
include|#
directive|include
file|"s_socket.c"
end_include

begin_include
include|#
directive|include
file|"s_time.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"speed.c"
end_include

begin_include
include|#
directive|include
file|"verify.c"
end_include

begin_include
include|#
directive|include
file|"version.c"
end_include

begin_include
include|#
directive|include
file|"x509.c"
end_include

begin_include
include|#
directive|include
file|"ciphers.c"
end_include

begin_include
include|#
directive|include
file|"sess_id.c"
end_include

begin_include
include|#
directive|include
file|"pkcs7.c"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DSA
end_ifndef

begin_include
include|#
directive|include
file|"dsaparam.c"
end_include

begin_include
include|#
directive|include
file|"dsa.c"
end_include

begin_include
include|#
directive|include
file|"gendsa.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

