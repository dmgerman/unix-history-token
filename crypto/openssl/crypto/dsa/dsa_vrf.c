begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/dsa/dsa_vrf.c */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* Original version from Steven Schoch<schoch@sheba.arc.nasa.gov> */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"cryptlib.h"
end_include

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_include
include|#
directive|include
file|<openssl/dsa.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rand.h>
end_include

begin_include
include|#
directive|include
file|<openssl/asn1.h>
end_include

begin_include
include|#
directive|include
file|<openssl/asn1_mac.h>
end_include

begin_function
name|int
name|DSA_do_verify
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|dgst
parameter_list|,
name|int
name|dgst_len
parameter_list|,
name|DSA_SIG
modifier|*
name|sig
parameter_list|,
name|DSA
modifier|*
name|dsa
parameter_list|)
block|{
return|return
name|dsa
operator|->
name|meth
operator|->
name|dsa_do_verify
argument_list|(
name|dgst
argument_list|,
name|dgst_len
argument_list|,
name|sig
argument_list|,
name|dsa
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* data has already been hashed (probably with SHA or SHA-1). */
end_comment

begin_comment
comment|/* returns  *      1: correct signature  *      0: incorrect signature  *     -1: error  */
end_comment

begin_function
name|int
name|DSA_verify
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|dgst
parameter_list|,
name|int
name|dgst_len
parameter_list|,
name|unsigned
name|char
modifier|*
name|sigbuf
parameter_list|,
name|int
name|siglen
parameter_list|,
name|DSA
modifier|*
name|dsa
parameter_list|)
block|{
name|DSA_SIG
modifier|*
name|s
decl_stmt|;
name|int
name|ret
init|=
operator|-
literal|1
decl_stmt|;
name|s
operator|=
name|DSA_SIG_new
argument_list|()
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
return|return
operator|(
name|ret
operator|)
return|;
if|if
condition|(
name|d2i_DSA_SIG
argument_list|(
operator|&
name|s
argument_list|,
operator|&
name|sigbuf
argument_list|,
name|siglen
argument_list|)
operator|==
name|NULL
condition|)
goto|goto
name|err
goto|;
name|ret
operator|=
name|DSA_do_verify
argument_list|(
name|dgst
argument_list|,
name|dgst_len
argument_list|,
name|s
argument_list|,
name|dsa
argument_list|)
expr_stmt|;
name|err
label|:
name|DSA_SIG_free
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

end_unit

