begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2005, 2007, 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: atomic.h,v 1.7 2009/04/08 06:48:23 tbox Exp $ */
end_comment

begin_comment
comment|/*  * This code was written based on FreeBSD's kernel source whose copyright  * follows:  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD: src/sys/alpha/include/atomic.h,v 1.18.6.1 2004/09/13 21:52:04 wilko Exp $  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USEOSFASM
end_ifdef

begin_include
include|#
directive|include
file|<c_asm.h>
end_include

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|asm
name|)
end_pragma

begin_comment
comment|/*  * This routine atomically increments the value stored in 'p' by 'val', and  * returns the previous value.  Memory access ordering around this function  * can be critical, so we add explicit memory block instructions at the  * beginning and the end of it (same for other functions).  */
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
return|return
operator|(
asm|asm("mb;" 		    "1:" 		    "ldl_l %t0, 0(%a0);"
comment|/* load old value */
asm|"mov %t0, %v0;"
comment|/* copy the old value */
asm|"addl %t0, %a1, %t0;"
comment|/* calculate new value */
asm|"stl_c %t0, 0(%a0);"
comment|/* attempt to store */
asm|"beq %t0, 1b;"
comment|/* spin if failed */
asm|"mb;", 		    p, val));
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
operator|(
name|void
operator|)
asm|asm("mb;" 		  "1:" 		  "ldl_l %t0, 0(%a0);"
comment|/* load old value */
asm|"mov %a1, %t0;"
comment|/* value to store */
asm|"stl_c %t0, 0(%a0);"
comment|/* attempt to store */
asm|"beq %t0, 1b;"
comment|/* spin if failed */
asm|"mb;", 		  p, val);
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
return|return
operator|(
asm|asm("mb;" 		   "1:" 		   "ldl_l %t0, 0(%a0);"
comment|/* load old value */
asm|"mov %t0, %v0;"
comment|/* copy the old value */
asm|"cmpeq %t0, %a1, %t0;"
comment|/* compare */
asm|"beq %t0, 2f;"
comment|/* exit if not equal */
asm|"mov %a2, %t0;"
comment|/* value to store */
asm|"stl_c %t0, 0(%a0);"
comment|/* attempt to store */
asm|"beq %t0, 1b;"
comment|/* if it failed, spin */
asm|"2:" 		   "mb;", 		   p, cmpval, val));
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ISC_PLATFORM_USEGCCASM
argument_list|)
end_elif

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
name|temp
decl_stmt|,
name|prev
decl_stmt|;
asm|__asm__
specifier|volatile
asm|( 		"mb;" 		"1:" 		"ldl_l %0, %1;"
comment|/* load old value */
asm|"mov %0, %2;"
comment|/* copy the old value */
asm|"addl %0, %3, %0;"
comment|/* calculate new value */
asm|"stl_c %0, %1;"
comment|/* attempt to store */
asm|"beq %0, 1b;"
comment|/* spin if failed */
asm|"mb;" 		: "=&r"(temp), "+m"(*p), "=&r"(prev) 		: "r"(val) 		: "memory");
return|return
operator|(
name|prev
operator|)
return|;
block|}
end_function

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
name|temp
decl_stmt|;
asm|__asm__
specifier|volatile
asm|( 		"mb;" 		"1:" 		"ldl_l %0, %1;"
comment|/* load old value */
asm|"mov %2, %0;"
comment|/* value to store */
asm|"stl_c %0, %1;"
comment|/* attempt to store */
asm|"beq %0, 1b;"
comment|/* if it failed, spin */
asm|"mb;" 		: "=&r"(temp), "+m"(*p) 		: "r"(val) 		: "memory");
block|}
end_function

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
decl_stmt|,
name|prev
decl_stmt|;
asm|__asm__
specifier|volatile
asm|( 		"mb;" 		"1:" 		"ldl_l %0, %1;"
comment|/* load old value */
asm|"mov %0, %2;"
comment|/* copy the old value */
asm|"cmpeq %0, %3, %0;"
comment|/* compare */
asm|"beq %0, 2f;"
comment|/* exit if not equal */
asm|"mov %4, %0;"
comment|/* value to store */
asm|"stl_c %0, %1;"
comment|/* attempt to store */
asm|"beq %0, 1b;"
comment|/* if it failed, spin */
asm|"2:" 		"mb;" 		: "=&r"(temp), "+m"(*p), "=&r"(prev) 		: "r"(cmpval), "r"(val) 		: "memory");
return|return
operator|(
name|prev
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"unsupported compiler.  disable atomic ops by --disable-atomic"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_ATOMIC_H */
end_comment

end_unit

