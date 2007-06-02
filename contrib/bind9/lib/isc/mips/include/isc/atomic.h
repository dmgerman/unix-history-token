begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2005  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: atomic.h,v 1.1.2.1 2005/07/09 07:14:00 jinmei Exp $ */
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
name|int
name|val
parameter_list|)
block|{
name|isc_int32_t
name|orig
decl_stmt|;
comment|/* add is a cheat, since MIPS has no mov instruction */
asm|__asm__
specifier|volatile
asm|( 	    "1:" 	    "ll $3, %1\n" 	    "add %0, $0, $3\n" 	    "add $3, $3, %2\n" 	    "sc $3, %1\n" 	    "beq $3, 0, 1b" 	    : "=&r"(orig) 	    : "m"(*p), "r"(val) 	    : "memory", "$3" 		);
return|return
operator|(
name|orig
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
asm|__asm__
specifier|volatile
asm|( 	    "1:" 	    "ll $3, %0\n" 	    "add $3, $0, %1\n" 	    "sc $3, %0\n" 	    "beq $3, 0, 1b" 	    : 	    : "m"(*p), "r"(val) 	    : "memory", "$3" 		);
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
name|int
name|cmpval
parameter_list|,
name|int
name|val
parameter_list|)
block|{
name|isc_int32_t
name|orig
decl_stmt|;
asm|__asm__
specifier|volatile
asm|( 	    "1:" 	    "ll $3, %1\n" 	    "add %0, $0, $3\n" 	    "bne $3, %2, 2f\n" 	    "add $3, $0, %3\n" 	    "sc $3, %1\n" 	    "beq $3, 0, 1b\n" 	    "2:" 	    : "=&r"(orig) 	    : "m"(*p), "r"(cmpval), "r"(val) 	    : "memory", "$3" 		);
return|return
operator|(
name|orig
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !ISC_PLATFORM_USEGCCASM */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_ATOMIC_H */
end_comment

end_unit

