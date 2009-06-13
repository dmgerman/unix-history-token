begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from tahoe:	in_cksum.c	1.2	86/01/05  *	from:		@(#)in_cksum.c	1.3 (Berkeley) 1/19/91  *	from: Id: in_cksum.c,v 1.8 1995/12/03 18:35:19 bde Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IN_CKSUM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IN_CKSUM_H_
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
error|this file needs sys/cdefs.h as a prerequisite
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * MP safe (alfred)  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|in_cksum
parameter_list|(
name|m
parameter_list|,
name|len
parameter_list|)
value|in_cksum_skip(m, len, 0)
end_define

begin_comment
comment|/*  * It it useful to have an Internet checksum routine which is inlineable  * and optimized specifically for the task of computing IP header checksums  * in the normal case (where there are no options and the header length is  * therefore always exactly five 32-bit words.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUCLIKE_ASM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|u_int
name|in_cksum_hdr
parameter_list|(
specifier|const
name|struct
name|ip
modifier|*
name|ip
parameter_list|)
block|{
name|u_int
name|sum
init|=
literal|0
decl_stmt|;
asm|__asm(
literal|"addl %1, %0\n"
literal|"adcl %2, %0\n"
literal|"adcl %3, %0\n"
literal|"adcl %4, %0\n"
literal|"adcl %5, %0\n"
literal|"adcl $0, %0"
operator|:
literal|"+r"
operator|(
name|sum
operator|)
operator|:
literal|"g"
operator|(
operator|(
operator|(
specifier|const
name|u_int32_t
operator|*
operator|)
name|ip
operator|)
index|[
literal|0
index|]
operator|)
operator|,
literal|"g"
operator|(
operator|(
operator|(
specifier|const
name|u_int32_t
operator|*
operator|)
name|ip
operator|)
index|[
literal|1
index|]
operator|)
operator|,
literal|"g"
operator|(
operator|(
operator|(
specifier|const
name|u_int32_t
operator|*
operator|)
name|ip
operator|)
index|[
literal|2
index|]
operator|)
operator|,
literal|"g"
operator|(
operator|(
operator|(
specifier|const
name|u_int32_t
operator|*
operator|)
name|ip
operator|)
index|[
literal|3
index|]
operator|)
operator|,
literal|"g"
operator|(
operator|(
operator|(
specifier|const
name|u_int32_t
operator|*
operator|)
name|ip
operator|)
index|[
literal|4
index|]
operator|)
operator|:
literal|"cc"
block|)
function|;
end_function

begin_expr_stmt
name|sum
operator|=
operator|(
name|sum
operator|&
literal|0xffff
operator|)
operator|+
operator|(
name|sum
operator|>>
literal|16
operator|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|sum
operator|>
literal|0xffff
condition|)
name|sum
operator|-=
literal|0xffff
expr_stmt|;
end_if

begin_return
return|return
operator|~
name|sum
operator|&
literal|0xffff
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|in_cksum_update
parameter_list|(
name|struct
name|ip
modifier|*
name|ip
parameter_list|)
block|{
name|int
name|__tmpsum
decl_stmt|;
name|__tmpsum
operator|=
operator|(
name|int
operator|)
name|ntohs
argument_list|(
name|ip
operator|->
name|ip_sum
argument_list|)
operator|+
literal|256
expr_stmt|;
name|ip
operator|->
name|ip_sum
operator|=
name|htons
argument_list|(
name|__tmpsum
operator|+
operator|(
name|__tmpsum
operator|>>
literal|16
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_short
name|in_addword
parameter_list|(
name|u_short
name|sum
parameter_list|,
name|u_short
name|b
parameter_list|)
block|{
asm|__asm(
literal|"addw %1, %0\n"
literal|"adcw $0, %0"
operator|:
literal|"+r"
operator|(
name|sum
operator|)
operator|:
literal|"g"
operator|(
name|b
operator|)
operator|:
literal|"cc"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|sum
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|u_short
name|in_pseudo
parameter_list|(
name|u_int
name|sum
parameter_list|,
name|u_int
name|b
parameter_list|,
name|u_int
name|c
parameter_list|)
block|{
asm|__asm(
literal|"addl %1, %0\n"
literal|"adcl %2, %0\n"
literal|"adcl $0, %0"
operator|:
literal|"+r"
operator|(
name|sum
operator|)
operator|:
literal|"g"
operator|(
name|b
operator|)
operator|,
literal|"g"
operator|(
name|c
operator|)
operator|:
literal|"cc"
block|)
function|;
end_function

begin_expr_stmt
name|sum
operator|=
operator|(
name|sum
operator|&
literal|0xffff
operator|)
operator|+
operator|(
name|sum
operator|>>
literal|16
operator|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|sum
operator|>
literal|0xffff
condition|)
name|sum
operator|-=
literal|0xffff
expr_stmt|;
end_if

begin_return
return|return
operator|(
name|sum
operator|)
return|;
end_return

begin_else
unit|}
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|in_cksum_update
parameter_list|(
name|ip
parameter_list|)
define|\
value|do { \ 		int __tmpsum; \ 		__tmpsum = (int)ntohs(ip->ip_sum) + 256; \ 		ip->ip_sum = htons(__tmpsum + (__tmpsum>> 16)); \ 	} while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUCLIKE_ASM
argument_list|)
operator|||
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_expr_stmt
unit|u_int
name|in_cksum_hdr
argument_list|(
specifier|const
expr|struct
name|ip
operator|*
name|ip
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|u_short
name|in_addword
parameter_list|(
name|u_short
name|sum
parameter_list|,
name|u_short
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|in_pseudo
parameter_list|(
name|u_int
name|sum
parameter_list|,
name|u_int
name|b
parameter_list|,
name|u_int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|u_short
name|in_cksum_skip
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|skip
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_IN_CKSUM_H_ */
end_comment

end_unit

