begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 by Thomas Moestl<tmm@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	from tahoe:	in_cksum.c	1.2	86/01/05  *	from:		@(#)in_cksum.c	1.3 (Berkeley) 1/19/91  *	from: Id: in_cksum.c,v 1.8 1995/12/03 18:35:19 bde Exp  *	from: FreeBSD: src/sys/alpha/include/in_cksum.h,v 1.5 2000/05/06  *  * $FreeBSD$  */
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

begin_function
specifier|static
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
name|__tmp
decl_stmt|;
name|__tmp
operator|=
operator|(
name|int
operator|)
name|ip
operator|->
name|ip_sum
operator|+
literal|1
expr_stmt|;
name|ip
operator|->
name|ip_sum
operator|=
name|__tmp
operator|+
operator|(
name|__tmp
operator|>>
literal|16
operator|)
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
name|u_long
name|__ret
decl_stmt|,
name|__tmp
decl_stmt|;
asm|__asm(
literal|"sll %2, 16, %0\n"
literal|"sll %3, 16, %1\n"
literal|"addcc %0, %1, %0\n"
literal|"srl %0, 16, %0\n"
literal|"addc %0, 0, %0\n"
operator|:
literal|"=&r"
operator|(
name|__ret
operator|)
operator|,
literal|"=&r"
operator|(
name|__tmp
operator|)
operator|:
literal|"r"
operator|(
name|sum
operator|)
operator|,
literal|"r"
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
name|__ret
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
name|u_long
name|__tmp
decl_stmt|;
asm|__asm(
literal|"addcc %0, %3, %0\n"
literal|"addccc %0, %4, %0\n"
literal|"addc %0, 0, %0\n"
literal|"sll %0, 16, %1\n"
literal|"addcc %0, %1, %0\n"
literal|"srl %0, 16, %0\n"
literal|"addc %0, 0, %0\n"
operator|:
literal|"=r"
operator|(
name|sum
operator|)
operator|,
literal|"=&r"
operator|(
name|__tmp
operator|)
operator|:
literal|"0"
operator|(
name|sum
operator|)
operator|,
literal|"r"
operator|(
name|b
operator|)
operator|,
literal|"r"
operator|(
name|c
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
name|u_int
name|in_cksum_hdr
parameter_list|(
name|struct
name|ip
modifier|*
name|ip
parameter_list|)
block|{
name|u_long
name|__ret
decl_stmt|,
name|__tmp1
decl_stmt|,
name|__tmp2
decl_stmt|,
name|__tmp3
decl_stmt|,
name|__tmp4
decl_stmt|;
comment|/* 	 * Use 32-bit memory accesses and additions - addition with carry only 	 * works for 32 bits, and fixing up alignment issues for 64 is probably 	 * more trouble than it's worth. 	 * This may read outside of the ip header, but does not cross a page 	 * boundary in doing so, so that should be OK. 	 * Actually, this specialized implementation might be overkill - using 	 * a generic implementation for both in_cksum_skip and in_cksum_hdr 	 * should not be too much more expensive. 	 */
define|#
directive|define
name|__LD_ADD
parameter_list|(
name|addr
parameter_list|,
name|tmp
parameter_list|,
name|sum
parameter_list|,
name|offs
parameter_list|,
name|mod
parameter_list|)
define|\
value|"lduw [" #addr " + " #offs "], " #tmp "\n"				\     "add" # mod " " #sum ", " #tmp ", " #sum "\n"
asm|__asm(
literal|"and %5, 3, %3\n"
literal|"andn %5, 3, %1\n"
literal|"brz,pt %3, 0f\n"
literal|" lduw [%1], %0\n"
literal|"mov 4, %4\n"
literal|"sub %4, %3, %4\n"
literal|"sll %4, 3, %4\n"
comment|/* fix up unaligned buffers */
literal|"mov 1, %2\n"
literal|"sll %2, %4, %4\n"
literal|"sub %4, 1, %4\n"
literal|"lduw [%1 + 20], %2\n"
literal|"andn %2, %4, %2\n"
literal|"and %0, %4, %0\n"
literal|"or %0, %2, %0\n"
literal|"0:\n"
name|__LD_ADD
argument_list|(
argument|%
literal|1
argument_list|,
argument|%
literal|2
argument_list|,
argument|%
literal|0
argument_list|,
literal|4
argument_list|,
argument|cc
argument_list|)
name|__LD_ADD
argument_list|(
argument|%
literal|1
argument_list|,
argument|%
literal|2
argument_list|,
argument|%
literal|0
argument_list|,
literal|8
argument_list|,
argument|ccc
argument_list|)
name|__LD_ADD
argument_list|(
argument|%
literal|1
argument_list|,
argument|%
literal|2
argument_list|,
argument|%
literal|0
argument_list|,
literal|12
argument_list|,
argument|ccc
argument_list|)
name|__LD_ADD
argument_list|(
operator|%
literal|1
argument_list|,
operator|%
literal|2
argument_list|,
operator|%
literal|0
argument_list|,
literal|16
argument_list|,
name|ccc
argument_list|)
literal|"addc %0, 0, %0\n"
comment|/* reduce */
literal|"1:\n"
literal|"sll %0, 16, %2\n"
literal|"addcc %0, %2, %0\n"
literal|"srl %0, 16, %0\n"
literal|"addc %0, 0, %0\n"
literal|"andcc %3, 1, %3\n"
comment|/* need to byte-swap? */
literal|"clr %3\n"
literal|"bne,a,pn %%xcc, 1b\n"
literal|" sll %0, 8, %0\n"
literal|"not %0\n"
literal|"sll %0, 16, %0\n"
literal|"srl %0, 16, %0\n"
operator|:
literal|"=&r"
operator|(
name|__ret
operator|)
operator|,
literal|"=r"
operator|(
name|__tmp1
operator|)
operator|,
literal|"=&r"
operator|(
name|__tmp2
operator|)
operator|,
literal|"=&r"
operator|(
name|__tmp3
operator|)
operator|,
literal|"=&r"
operator|(
name|__tmp4
operator|)
operator|:
literal|"1"
operator|(
name|ip
operator|)
operator|:
literal|"cc"
block|)
function|;
end_function

begin_undef
undef|#
directive|undef
name|__LD_ADD
end_undef

begin_return
return|return
operator|(
name|__ret
operator|)
return|;
end_return

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_macro
unit|u_short
name|in_cksum_skip
argument_list|(
argument|struct mbuf *m
argument_list|,
argument|int len
argument_list|,
argument|int skip
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_IN_CKSUM_H_ */
end_comment

end_unit

