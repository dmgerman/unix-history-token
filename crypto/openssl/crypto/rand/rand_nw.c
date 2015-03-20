begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/rand/rand_nw.c */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *  * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *  * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from  *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *  * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2000 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|"cryptlib.h"
end_include

begin_include
include|#
directive|include
file|<openssl/rand.h>
end_include

begin_include
include|#
directive|include
file|"rand_lcl.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL_SYS_NETWARE
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NETWARE_LIBC
argument_list|)
end_if

begin_include
include|#
directive|include
file|<nks/thread.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<nwthread.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|GetProcessSwitchCount
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NETWARE_LIBC
argument_list|)
operator|||
operator|(
name|CURRENT_NDK_THRESHOLD
operator|<
literal|509220000
operator|)
end_if

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|RunningProcess
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* declare here same as found in newer NDKs */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|long
name|GetSuperHighResolutionTimer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*     * the FAQ indicates we need to provide at least 20 bytes (160 bits) of     * seed     */
end_comment

begin_function
name|int
name|RAND_poll
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|long
name|l
decl_stmt|;
name|unsigned
name|long
name|tsc
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/*      * There are several options to gather miscellaneous data but for now we      * will loop checking the time stamp counter (rdtsc) and the      * SuperHighResolutionTimer.  Each iteration will collect 8 bytes of data      * but it is treated as only 1 byte of entropy.  The call to      * ThreadSwitchWithDelay() will introduce additional variability into the      * data returned by rdtsc. Applications can agument the seed material by      * adding additional stuff with RAND_add() and should probably do so.      */
name|l
operator|=
name|GetProcessSwitchCount
argument_list|()
expr_stmt|;
name|RAND_add
argument_list|(
operator|&
name|l
argument_list|,
sizeof|sizeof
argument_list|(
name|l
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* need to cast the void* to unsigned long here */
name|l
operator|=
operator|(
name|unsigned
name|long
operator|)
name|RunningProcess
expr_stmt|;
name|RAND_add
argument_list|(
operator|&
name|l
argument_list|,
sizeof|sizeof
argument_list|(
name|l
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|2
init|;
name|i
operator|<
name|ENTROPY_NEEDED
condition|;
name|i
operator|++
control|)
block|{
ifdef|#
directive|ifdef
name|__MWERKS__
name|asm
block|{
name|rdtsc
name|mov
name|tsc
decl_stmt|,
name|eax
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__GNUC__
operator|>=
literal|2
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_ASM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_INLINE_ASM
argument_list|)
asm|asm
specifier|volatile
asm|("rdtsc":"=a" (tsc)::"edx");
endif|#
directive|endif
name|RAND_add
argument_list|(
operator|&
name|tsc
argument_list|,
sizeof|sizeof
argument_list|(
name|tsc
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|l
operator|=
name|GetSuperHighResolutionTimer
argument_list|()
expr_stmt|;
name|RAND_add
argument_list|(
operator|&
name|l
argument_list|,
sizeof|sizeof
argument_list|(
name|l
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|NETWARE_LIBC
argument_list|)
name|NXThreadYield
argument_list|()
expr_stmt|;
else|#
directive|else
comment|/* NETWARE_CLIB */
name|ThreadSwitchWithDelay
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
return|return
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

