begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: fpsetsticky.c,v 1.3 2002/01/13 21:45:48 thorpej Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Dan Winship.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ieeefp.h>
end_include

begin_function
name|fp_except_t
name|fpsetsticky
parameter_list|(
name|fp_except_t
name|mask
parameter_list|)
block|{
name|u_int64_t
name|fpscr
decl_stmt|;
name|fp_rnd_t
name|old
decl_stmt|;
name|__asm__
name|__volatile
argument_list|(
literal|"mffs %0"
operator|:
literal|"=f"
operator|(
name|fpscr
operator|)
argument_list|)
decl_stmt|;
name|old
operator|=
call|(
name|fp_except_t
call|)
argument_list|(
operator|(
name|fpscr
operator|>>
literal|25
operator|)
operator|&
literal|0x1f
argument_list|)
expr_stmt|;
name|fpscr
operator|=
operator|(
name|fpscr
operator|&
literal|0xc1ffffff
operator|)
operator||
operator|(
name|mask
operator|<<
literal|25
operator|)
expr_stmt|;
name|__asm__
name|__volatile
argument_list|(
literal|"mtfsf 0xff,%0"
operator|::
literal|"f"
operator|(
name|fpscr
operator|)
argument_list|)
decl_stmt|;
return|return
operator|(
name|old
operator|)
return|;
block|}
end_function

end_unit

