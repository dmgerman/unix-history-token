begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2005, 2007  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: atomic.h,v 1.5 2007/06/19 23:47:18 tbox Exp $ */
end_comment

begin_comment
comment|/*  * This code was written based on FreeBSD's kernel source whose copyright  * follows:  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson.  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/i386/include/atomic.h,v 1.20 2001/02/11  * $FreeBSD: src/sys/sparc64/include/atomic.h,v 1.8 2004/05/22 00:52:16 marius Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_ATOMIC_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_ATOMIC_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_define
define|#
directive|define
name|ASI_P
value|0x80
end_define

begin_comment
comment|/* Primary Address Space Identifier */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USEGCCASM
end_ifdef

begin_comment
comment|/*  * This routine atomically increments the value stored in 'p' by 'val', and  * returns the previous value.  */
end_comment

begin_function
specifier|static
specifier|inline
name|isc_int32_t
name|isc_atomic_xadd
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
name|isc_int32_t
name|prev
decl_stmt|,
name|swapped
decl_stmt|;
for|for
control|(
name|prev
operator|=
operator|*
operator|(
specifier|volatile
name|isc_int32_t
operator|*
operator|)
name|p
init|;
condition|;
name|prev
operator|=
name|swapped
control|)
block|{
name|swapped
operator|=
name|prev
operator|+
name|val
expr_stmt|;
asm|__asm__
specifier|volatile
asm|( 			"casa [%1] %2, %3, %0" 			: "+r"(swapped) 			: "r"(p), "n"(ASI_P), "r"(prev));
if|if
condition|(
name|swapped
operator|==
name|prev
condition|)
break|break;
block|}
return|return
operator|(
name|prev
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * This routine atomically stores the value 'val' in 'p'.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|isc_atomic_store
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
name|isc_int32_t
name|prev
decl_stmt|,
name|swapped
decl_stmt|;
for|for
control|(
name|prev
operator|=
operator|*
operator|(
specifier|volatile
name|isc_int32_t
operator|*
operator|)
name|p
init|;
condition|;
name|prev
operator|=
name|swapped
control|)
block|{
name|swapped
operator|=
name|val
expr_stmt|;
asm|__asm__
specifier|volatile
asm|( 			"casa [%1] %2, %3, %0" 			: "+r"(swapped) 			: "r"(p), "n"(ASI_P), "r"(prev) 			: "memory");
if|if
condition|(
name|swapped
operator|==
name|prev
condition|)
break|break;
block|}
block|}
end_function

begin_comment
comment|/*  * This routine atomically replaces the value in 'p' with 'val', if the  * original value is equal to 'cmpval'.  The original value is returned in any  * case.  */
end_comment

begin_function
specifier|static
specifier|inline
name|isc_int32_t
name|isc_atomic_cmpxchg
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|cmpval
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
name|isc_int32_t
name|temp
init|=
name|val
decl_stmt|;
asm|__asm__
specifier|volatile
asm|( 		"casa [%1] %2, %3, %0" 		: "+r"(temp) 		: "r"(p), "n"(ASI_P), "r"(cmpval));
return|return
operator|(
name|temp
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ISC_PLATFORM_USEGCCASM */
end_comment

begin_error
error|#
directive|error
literal|"unsupported compiler.  disable atomic ops by --disable-atomic"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PLATFORM_USEGCCASM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_ATOMIC_H */
end_comment

end_unit

