begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/des/des_opts.c */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* define PART1, PART2, PART3 or PART4 to build only with a few of the options.  * This is for machines with 64k code segment size restrictions. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|__DECC
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|TIMES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_include
include|#
directive|include
file|<openssl/e_os2.h>
end_include

begin_include
include|#
directive|include
include|OPENSSL_UNISTD
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_IRIX
end_ifndef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TIMES
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Depending on the VMS version, the tms structure is perhaps defined.    The __TMS macro will show if it was.  If it wasn't defined, we should    undefine TIMES, since that tells the rest of the program how things    should be handled.				-- Richard Levitte */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
operator|&&
name|defined
argument_list|(
name|__DECC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__TMS
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|TIMES
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIMES
end_ifndef

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|__ultrix
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<openssl/des.h>
end_include

begin_include
include|#
directive|include
file|"spr.h"
end_include

begin_define
define|#
directive|define
name|DES_DEFAULT_OPTIONS
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PART1
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PART2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PART3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PART4
argument_list|)
end_if

begin_define
define|#
directive|define
name|PART1
end_define

begin_define
define|#
directive|define
name|PART2
end_define

begin_define
define|#
directive|define
name|PART3
end_define

begin_define
define|#
directive|define
name|PART4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PART1
end_ifdef

begin_undef
undef|#
directive|undef
name|DES_UNROLL
end_undef

begin_undef
undef|#
directive|undef
name|DES_RISC1
end_undef

begin_undef
undef|#
directive|undef
name|DES_RISC2
end_undef

begin_undef
undef|#
directive|undef
name|DES_PTR
end_undef

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u4_cisc_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u4_cisc_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u4_cisc_idx
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u4_cisc_idx
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_undef
undef|#
directive|undef
name|DES_RISC1
end_undef

begin_undef
undef|#
directive|undef
name|DES_RISC2
end_undef

begin_undef
undef|#
directive|undef
name|DES_PTR
end_undef

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt1
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt2
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt3
end_undef

begin_undef
undef|#
directive|undef
name|des_decrypt3
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u16_cisc_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u16_cisc_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u16_cisc_idx
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u16_cisc_idx
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_undef
undef|#
directive|undef
name|DES_UNROLL
end_undef

begin_define
define|#
directive|define
name|DES_RISC1
end_define

begin_undef
undef|#
directive|undef
name|DES_RISC2
end_undef

begin_undef
undef|#
directive|undef
name|DES_PTR
end_undef

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt1
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt2
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt3
end_undef

begin_undef
undef|#
directive|undef
name|des_decrypt3
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u4_risc1_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u4_risc1_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u4_risc1_idx
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u4_risc1_idx
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PART2
end_ifdef

begin_undef
undef|#
directive|undef
name|DES_UNROLL
end_undef

begin_undef
undef|#
directive|undef
name|DES_RISC1
end_undef

begin_define
define|#
directive|define
name|DES_RISC2
end_define

begin_undef
undef|#
directive|undef
name|DES_PTR
end_undef

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt1
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt2
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt3
end_undef

begin_undef
undef|#
directive|undef
name|des_decrypt3
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u4_risc2_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u4_risc2_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u4_risc2_idx
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u4_risc2_idx
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_define
define|#
directive|define
name|DES_RISC1
end_define

begin_undef
undef|#
directive|undef
name|DES_RISC2
end_undef

begin_undef
undef|#
directive|undef
name|DES_PTR
end_undef

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt1
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt2
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt3
end_undef

begin_undef
undef|#
directive|undef
name|des_decrypt3
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u16_risc1_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u16_risc1_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u16_risc1_idx
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u16_risc1_idx
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_undef
undef|#
directive|undef
name|DES_RISC1
end_undef

begin_define
define|#
directive|define
name|DES_RISC2
end_define

begin_undef
undef|#
directive|undef
name|DES_PTR
end_undef

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt1
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt2
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt3
end_undef

begin_undef
undef|#
directive|undef
name|des_decrypt3
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u16_risc2_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u16_risc2_idx
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u16_risc2_idx
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u16_risc2_idx
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PART3
end_ifdef

begin_undef
undef|#
directive|undef
name|DES_UNROLL
end_undef

begin_undef
undef|#
directive|undef
name|DES_RISC1
end_undef

begin_undef
undef|#
directive|undef
name|DES_RISC2
end_undef

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt1
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt2
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt3
end_undef

begin_undef
undef|#
directive|undef
name|des_decrypt3
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u4_cisc_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u4_cisc_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u4_cisc_ptr
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u4_cisc_ptr
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_undef
undef|#
directive|undef
name|DES_RISC1
end_undef

begin_undef
undef|#
directive|undef
name|DES_RISC2
end_undef

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt1
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt2
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt3
end_undef

begin_undef
undef|#
directive|undef
name|des_decrypt3
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u16_cisc_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u16_cisc_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u16_cisc_ptr
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u16_cisc_ptr
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_undef
undef|#
directive|undef
name|DES_UNROLL
end_undef

begin_define
define|#
directive|define
name|DES_RISC1
end_define

begin_undef
undef|#
directive|undef
name|DES_RISC2
end_undef

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt1
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt2
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt3
end_undef

begin_undef
undef|#
directive|undef
name|des_decrypt3
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u4_risc1_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u4_risc1_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u4_risc1_ptr
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u4_risc1_ptr
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PART4
end_ifdef

begin_undef
undef|#
directive|undef
name|DES_UNROLL
end_undef

begin_undef
undef|#
directive|undef
name|DES_RISC1
end_undef

begin_define
define|#
directive|define
name|DES_RISC2
end_define

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt1
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt2
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt3
end_undef

begin_undef
undef|#
directive|undef
name|des_decrypt3
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u4_risc2_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u4_risc2_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u4_risc2_ptr
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u4_risc2_ptr
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_define
define|#
directive|define
name|DES_RISC1
end_define

begin_undef
undef|#
directive|undef
name|DES_RISC2
end_undef

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt1
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt2
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt3
end_undef

begin_undef
undef|#
directive|undef
name|des_decrypt3
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u16_risc1_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u16_risc1_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u16_risc1_ptr
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u16_risc1_ptr
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_define
define|#
directive|define
name|DES_UNROLL
end_define

begin_undef
undef|#
directive|undef
name|DES_RISC1
end_undef

begin_define
define|#
directive|define
name|DES_RISC2
end_define

begin_define
define|#
directive|define
name|DES_PTR
end_define

begin_undef
undef|#
directive|undef
name|D_ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt1
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt2
end_undef

begin_undef
undef|#
directive|undef
name|des_encrypt3
end_undef

begin_undef
undef|#
directive|undef
name|des_decrypt3
end_undef

begin_define
define|#
directive|define
name|des_encrypt1
value|des_encrypt_u16_risc2_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt2
value|des_encrypt2_u16_risc2_ptr
end_define

begin_define
define|#
directive|define
name|des_encrypt3
value|des_encrypt3_u16_risc2_ptr
end_define

begin_define
define|#
directive|define
name|des_decrypt3
value|des_decrypt3_u16_risc2_ptr
end_define

begin_undef
undef|#
directive|undef
name|HEADER_DES_LOCL_H
end_undef

begin_include
include|#
directive|include
file|"des_enc.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following if from times(3) man page.  It may need to be changed */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HZ
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|CLK_TCK
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_CLK_TCK_
end_ifndef

begin_comment
comment|/* FreeBSD fix */
end_comment

begin_define
define|#
directive|define
name|HZ
value|100.0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _BSD_CLK_TCK_ */
end_comment

begin_define
define|#
directive|define
name|HZ
value|((double)_BSD_CLK_TCK_)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CLK_TCK */
end_comment

begin_define
define|#
directive|define
name|HZ
value|((double)CLK_TCK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BUFSIZE
value|((long)1024)
end_define

begin_decl_stmt
name|long
name|run
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
name|double
name|Time_F
parameter_list|(
name|int
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SIGALRM
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|sgi
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGRETTYPE
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGRETTYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|SIGRETTYPE
name|sig_done
parameter_list|(
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|SIGRETTYPE
name|sig_done
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|sig_done
argument_list|)
expr_stmt|;
name|run
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|LINT
name|sig
operator|=
name|sig
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|START
value|0
end_define

begin_define
define|#
directive|define
name|STOP
value|1
end_define

begin_function
name|double
name|Time_F
parameter_list|(
name|int
name|s
parameter_list|)
block|{
name|double
name|ret
decl_stmt|;
ifdef|#
directive|ifdef
name|TIMES
specifier|static
name|struct
name|tms
name|tstart
decl_stmt|,
name|tend
decl_stmt|;
if|if
condition|(
name|s
operator|==
name|START
condition|)
block|{
name|times
argument_list|(
operator|&
name|tstart
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
block|{
name|times
argument_list|(
operator|&
name|tend
argument_list|)
expr_stmt|;
name|ret
operator|=
operator|(
call|(
name|double
call|)
argument_list|(
name|tend
operator|.
name|tms_utime
operator|-
name|tstart
operator|.
name|tms_utime
argument_list|)
operator|)
operator|/
name|HZ
expr_stmt|;
return|return
operator|(
operator|(
name|ret
operator|==
literal|0.0
operator|)
condition|?
literal|1e-6
else|:
name|ret
operator|)
return|;
block|}
else|#
directive|else
comment|/* !times() */
specifier|static
name|struct
name|timeb
name|tstart
decl_stmt|,
name|tend
decl_stmt|;
name|long
name|i
decl_stmt|;
if|if
condition|(
name|s
operator|==
name|START
condition|)
block|{
name|ftime
argument_list|(
operator|&
name|tstart
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
block|{
name|ftime
argument_list|(
operator|&
name|tend
argument_list|)
expr_stmt|;
name|i
operator|=
operator|(
name|long
operator|)
name|tend
operator|.
name|millitm
operator|-
operator|(
name|long
operator|)
name|tstart
operator|.
name|millitm
expr_stmt|;
name|ret
operator|=
operator|(
call|(
name|double
call|)
argument_list|(
name|tend
operator|.
name|time
operator|-
name|tstart
operator|.
name|time
argument_list|)
operator|)
operator|+
operator|(
operator|(
name|double
operator|)
name|i
operator|)
operator|/
literal|1000.0
expr_stmt|;
return|return
operator|(
operator|(
name|ret
operator|==
literal|0.0
operator|)
condition|?
literal|1e-6
else|:
name|ret
operator|)
return|;
block|}
endif|#
directive|endif
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|SIGALRM
end_ifdef

begin_define
define|#
directive|define
name|print_name
parameter_list|(
name|name
parameter_list|)
value|fprintf(stderr,"Doing %s's for 10 seconds\n",name); alarm(10);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|print_name
parameter_list|(
name|name
parameter_list|)
value|fprintf(stderr,"Doing %s %ld times\n",name,cb);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|time_it
parameter_list|(
name|func
parameter_list|,
name|name
parameter_list|,
name|index
parameter_list|)
define|\
value|print_name(name); \ 	Time_F(START); \ 	for (count=0,run=1; COND(cb); count++) \ 		{ \ 		unsigned long d[2]; \ 		func(d,&(sch[0]),DES_ENCRYPT); \ 		} \ 	tm[index]=Time_F(STOP); \ 	fprintf(stderr,"%ld %s's in %.2f second\n",count,name,tm[index]); \ 	tm[index]=((double)COUNT(cb))/tm[index];
end_define

begin_define
define|#
directive|define
name|print_it
parameter_list|(
name|name
parameter_list|,
name|index
parameter_list|)
define|\
value|fprintf(stderr,"%s bytes per sec = %12.2f (%5.1fuS)\n",name, \ 		tm[index]*8,1.0e6/tm[index]);
end_define

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|long
name|count
decl_stmt|;
specifier|static
name|unsigned
name|char
name|buf
index|[
name|BUFSIZE
index|]
decl_stmt|;
specifier|static
name|des_cblock
name|key
init|=
block|{
literal|0x12
block|,
literal|0x34
block|,
literal|0x56
block|,
literal|0x78
block|,
literal|0x9a
block|,
literal|0xbc
block|,
literal|0xde
block|,
literal|0xf0
block|}
decl_stmt|;
specifier|static
name|des_cblock
name|key2
init|=
block|{
literal|0x34
block|,
literal|0x56
block|,
literal|0x78
block|,
literal|0x9a
block|,
literal|0xbc
block|,
literal|0xde
block|,
literal|0xf0
block|,
literal|0x12
block|}
decl_stmt|;
specifier|static
name|des_cblock
name|key3
init|=
block|{
literal|0x56
block|,
literal|0x78
block|,
literal|0x9a
block|,
literal|0xbc
block|,
literal|0xde
block|,
literal|0xf0
block|,
literal|0x12
block|,
literal|0x34
block|}
decl_stmt|;
name|des_key_schedule
name|sch
decl_stmt|,
name|sch2
decl_stmt|,
name|sch3
decl_stmt|;
name|double
name|d
decl_stmt|,
name|tm
index|[
literal|16
index|]
decl_stmt|,
name|max
init|=
literal|0
decl_stmt|;
name|int
name|rank
index|[
literal|16
index|]
decl_stmt|;
name|char
modifier|*
name|str
index|[
literal|16
index|]
decl_stmt|;
name|int
name|max_idx
init|=
literal|0
decl_stmt|,
name|i
decl_stmt|,
name|num
init|=
literal|0
decl_stmt|,
name|j
decl_stmt|;
ifndef|#
directive|ifndef
name|SIGALARM
name|long
name|ca
decl_stmt|,
name|cb
decl_stmt|,
name|cc
decl_stmt|,
name|cd
decl_stmt|,
name|ce
decl_stmt|;
endif|#
directive|endif
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|12
condition|;
name|i
operator|++
control|)
block|{
name|tm
index|[
name|i
index|]
operator|=
literal|0.0
expr_stmt|;
name|rank
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|TIMES
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"To get the most accurate results, try to run this\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"program when this computer is idle.\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|des_set_key_unchecked
argument_list|(
operator|&
name|key
argument_list|,
name|sch
argument_list|)
expr_stmt|;
name|des_set_key_unchecked
argument_list|(
operator|&
name|key2
argument_list|,
name|sch2
argument_list|)
expr_stmt|;
name|des_set_key_unchecked
argument_list|(
operator|&
name|key3
argument_list|,
name|sch3
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|SIGALRM
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"First we calculate the approximate speed ...\n"
argument_list|)
expr_stmt|;
name|des_set_key_unchecked
argument_list|(
operator|&
name|key
argument_list|,
name|sch
argument_list|)
expr_stmt|;
name|count
operator|=
literal|10
expr_stmt|;
do|do
block|{
name|long
name|i
decl_stmt|;
name|unsigned
name|long
name|data
index|[
literal|2
index|]
decl_stmt|;
name|count
operator|*=
literal|2
expr_stmt|;
name|Time_F
argument_list|(
name|START
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|count
init|;
name|i
condition|;
name|i
operator|--
control|)
name|des_encrypt1
argument_list|(
name|data
argument_list|,
operator|&
operator|(
name|sch
index|[
literal|0
index|]
operator|)
argument_list|,
name|DES_ENCRYPT
argument_list|)
expr_stmt|;
name|d
operator|=
name|Time_F
argument_list|(
name|STOP
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|d
operator|<
literal|3.0
condition|)
do|;
name|ca
operator|=
name|count
expr_stmt|;
name|cb
operator|=
name|count
operator|*
literal|3
expr_stmt|;
name|cc
operator|=
name|count
operator|*
literal|3
operator|*
literal|8
operator|/
name|BUFSIZE
operator|+
literal|1
expr_stmt|;
name|cd
operator|=
name|count
operator|*
literal|8
operator|/
name|BUFSIZE
operator|+
literal|1
expr_stmt|;
name|ce
operator|=
name|count
operator|/
literal|20
operator|+
literal|1
expr_stmt|;
define|#
directive|define
name|COND
parameter_list|(
name|d
parameter_list|)
value|(count != (d))
define|#
directive|define
name|COUNT
parameter_list|(
name|d
parameter_list|)
value|(d)
else|#
directive|else
define|#
directive|define
name|COND
parameter_list|(
name|c
parameter_list|)
value|(run)
define|#
directive|define
name|COUNT
parameter_list|(
name|d
parameter_list|)
value|(count)
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|sig_done
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
literal|10
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PART1
name|time_it
argument_list|(
name|des_encrypt_u4_cisc_idx
argument_list|,
literal|"des_encrypt_u4_cisc_idx  "
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|time_it
argument_list|(
name|des_encrypt_u16_cisc_idx
argument_list|,
literal|"des_encrypt_u16_cisc_idx "
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|time_it
argument_list|(
name|des_encrypt_u4_risc1_idx
argument_list|,
literal|"des_encrypt_u4_risc1_idx "
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|num
operator|+=
literal|3
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PART2
name|time_it
argument_list|(
name|des_encrypt_u16_risc1_idx
argument_list|,
literal|"des_encrypt_u16_risc1_idx"
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|time_it
argument_list|(
name|des_encrypt_u4_risc2_idx
argument_list|,
literal|"des_encrypt_u4_risc2_idx "
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|time_it
argument_list|(
name|des_encrypt_u16_risc2_idx
argument_list|,
literal|"des_encrypt_u16_risc2_idx"
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|num
operator|+=
literal|3
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PART3
name|time_it
argument_list|(
name|des_encrypt_u4_cisc_ptr
argument_list|,
literal|"des_encrypt_u4_cisc_ptr  "
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|time_it
argument_list|(
name|des_encrypt_u16_cisc_ptr
argument_list|,
literal|"des_encrypt_u16_cisc_ptr "
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|time_it
argument_list|(
name|des_encrypt_u4_risc1_ptr
argument_list|,
literal|"des_encrypt_u4_risc1_ptr "
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|num
operator|+=
literal|3
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PART4
name|time_it
argument_list|(
name|des_encrypt_u16_risc1_ptr
argument_list|,
literal|"des_encrypt_u16_risc1_ptr"
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|time_it
argument_list|(
name|des_encrypt_u4_risc2_ptr
argument_list|,
literal|"des_encrypt_u4_risc2_ptr "
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|time_it
argument_list|(
name|des_encrypt_u16_risc2_ptr
argument_list|,
literal|"des_encrypt_u16_risc2_ptr"
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|num
operator|+=
literal|3
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PART1
name|str
index|[
literal|0
index|]
operator|=
literal|" 4  c i"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u4_cisc_idx  "
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|max
operator|=
name|tm
index|[
literal|0
index|]
expr_stmt|;
name|max_idx
operator|=
literal|0
expr_stmt|;
name|str
index|[
literal|1
index|]
operator|=
literal|"16  c i"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u16_cisc_idx "
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|max
operator|<
name|tm
index|[
literal|1
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
literal|1
index|]
expr_stmt|;
name|max_idx
operator|=
literal|1
expr_stmt|;
block|}
name|str
index|[
literal|2
index|]
operator|=
literal|" 4 r1 i"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u4_risc1_idx "
argument_list|,
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|max
operator|<
name|tm
index|[
literal|2
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
literal|2
index|]
expr_stmt|;
name|max_idx
operator|=
literal|2
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PART2
name|str
index|[
literal|3
index|]
operator|=
literal|"16 r1 i"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u16_risc1_idx"
argument_list|,
literal|3
argument_list|)
expr_stmt|;
if|if
condition|(
name|max
operator|<
name|tm
index|[
literal|3
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
literal|3
index|]
expr_stmt|;
name|max_idx
operator|=
literal|3
expr_stmt|;
block|}
name|str
index|[
literal|4
index|]
operator|=
literal|" 4 r2 i"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u4_risc2_idx "
argument_list|,
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|max
operator|<
name|tm
index|[
literal|4
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
literal|4
index|]
expr_stmt|;
name|max_idx
operator|=
literal|4
expr_stmt|;
block|}
name|str
index|[
literal|5
index|]
operator|=
literal|"16 r2 i"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u16_risc2_idx"
argument_list|,
literal|5
argument_list|)
expr_stmt|;
if|if
condition|(
name|max
operator|<
name|tm
index|[
literal|5
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
literal|5
index|]
expr_stmt|;
name|max_idx
operator|=
literal|5
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PART3
name|str
index|[
literal|6
index|]
operator|=
literal|" 4  c p"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u4_cisc_ptr  "
argument_list|,
literal|6
argument_list|)
expr_stmt|;
if|if
condition|(
name|max
operator|<
name|tm
index|[
literal|6
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
literal|6
index|]
expr_stmt|;
name|max_idx
operator|=
literal|6
expr_stmt|;
block|}
name|str
index|[
literal|7
index|]
operator|=
literal|"16  c p"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u16_cisc_ptr "
argument_list|,
literal|7
argument_list|)
expr_stmt|;
if|if
condition|(
name|max
operator|<
name|tm
index|[
literal|7
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
literal|7
index|]
expr_stmt|;
name|max_idx
operator|=
literal|7
expr_stmt|;
block|}
name|str
index|[
literal|8
index|]
operator|=
literal|" 4 r1 p"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u4_risc1_ptr "
argument_list|,
literal|8
argument_list|)
expr_stmt|;
if|if
condition|(
name|max
operator|<
name|tm
index|[
literal|8
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
literal|8
index|]
expr_stmt|;
name|max_idx
operator|=
literal|8
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PART4
name|str
index|[
literal|9
index|]
operator|=
literal|"16 r1 p"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u16_risc1_ptr"
argument_list|,
literal|9
argument_list|)
expr_stmt|;
if|if
condition|(
name|max
operator|<
name|tm
index|[
literal|9
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
literal|9
index|]
expr_stmt|;
name|max_idx
operator|=
literal|9
expr_stmt|;
block|}
name|str
index|[
literal|10
index|]
operator|=
literal|" 4 r2 p"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u4_risc2_ptr "
argument_list|,
literal|10
argument_list|)
expr_stmt|;
if|if
condition|(
name|max
operator|<
name|tm
index|[
literal|10
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
literal|10
index|]
expr_stmt|;
name|max_idx
operator|=
literal|10
expr_stmt|;
block|}
name|str
index|[
literal|11
index|]
operator|=
literal|"16 r2 p"
expr_stmt|;
name|print_it
argument_list|(
literal|"des_encrypt_u16_risc2_ptr"
argument_list|,
literal|11
argument_list|)
expr_stmt|;
if|if
condition|(
name|max
operator|<
name|tm
index|[
literal|11
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
literal|11
index|]
expr_stmt|;
name|max_idx
operator|=
literal|11
expr_stmt|;
block|}
endif|#
directive|endif
name|printf
argument_list|(
literal|"options    des ecb/s\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s %12.2f 100.0%%\n"
argument_list|,
name|str
index|[
name|max_idx
index|]
argument_list|,
name|tm
index|[
name|max_idx
index|]
argument_list|)
expr_stmt|;
name|d
operator|=
name|tm
index|[
name|max_idx
index|]
expr_stmt|;
name|tm
index|[
name|max_idx
index|]
operator|=
operator|-
literal|2.0
expr_stmt|;
name|max
operator|=
operator|-
literal|1.0
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|12
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|max
operator|<
name|tm
index|[
name|i
index|]
condition|)
block|{
name|max
operator|=
name|tm
index|[
name|i
index|]
expr_stmt|;
name|j
operator|=
name|i
expr_stmt|;
block|}
block|}
if|if
condition|(
name|max
operator|<
literal|0.0
condition|)
break|break;
name|printf
argument_list|(
literal|"%s %12.2f  %4.1f%%\n"
argument_list|,
name|str
index|[
name|j
index|]
argument_list|,
name|tm
index|[
name|j
index|]
argument_list|,
name|tm
index|[
name|j
index|]
operator|/
name|d
operator|*
literal|100.0
argument_list|)
expr_stmt|;
name|tm
index|[
name|j
index|]
operator|=
operator|-
literal|2.0
expr_stmt|;
name|max
operator|=
operator|-
literal|1.0
expr_stmt|;
block|}
switch|switch
condition|(
name|max_idx
condition|)
block|{
case|case
literal|0
case|:
name|printf
argument_list|(
literal|"-DDES_DEFAULT_OPTIONS\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|printf
argument_list|(
literal|"-DDES_UNROLL\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|printf
argument_list|(
literal|"-DDES_RISC1\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|printf
argument_list|(
literal|"-DDES_UNROLL -DDES_RISC1\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|4
case|:
name|printf
argument_list|(
literal|"-DDES_RISC2\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|5
case|:
name|printf
argument_list|(
literal|"-DDES_UNROLL -DDES_RISC2\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|6
case|:
name|printf
argument_list|(
literal|"-DDES_PTR\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|7
case|:
name|printf
argument_list|(
literal|"-DDES_UNROLL -DDES_PTR\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|8
case|:
name|printf
argument_list|(
literal|"-DDES_RISC1 -DDES_PTR\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|9
case|:
name|printf
argument_list|(
literal|"-DDES_UNROLL -DDES_RISC1 -DDES_PTR\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|10
case|:
name|printf
argument_list|(
literal|"-DDES_RISC2 -DDES_PTR\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|11
case|:
name|printf
argument_list|(
literal|"-DDES_UNROLL -DDES_RISC2 -DDES_PTR\n"
argument_list|)
expr_stmt|;
break|break;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|LINT
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

