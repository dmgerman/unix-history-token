begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2005, 2007, 2009, 2011, 2012  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
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

begin_comment
comment|/*!\file  * static inline isc_int32_t  * isc_atomic_xadd(isc_int32_t *p, isc_int32_t val);  *  * This routine atomically increments the value stored in 'p' by 'val', and  * returns the previous value.  *  * static inline void  * isc_atomic_store(void *p, isc_int32_t val);  *  * This routine atomically stores the value 'val' in 'p'.  *  * static inline isc_int32_t  * isc_atomic_cmpxchg(isc_int32_t *p, isc_int32_t cmpval, isc_int32_t val);  *  * This routine atomically replaces the value in 'p' with 'val', if the  * original value is equal to 'cmpval'.  The original value is returned in any  * case.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_AIX
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/atomic_op.h>
end_include

begin_define
define|#
directive|define
name|isc_atomic_store
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|_clear_lock(p, v)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function
specifier|static
specifier|inline
name|isc_int32_t
else|#
directive|else
specifier|static
name|isc_int32_t
endif|#
directive|endif
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
name|int
name|ret
decl_stmt|;
ifdef|#
directive|ifdef
name|__GNUC__
asm|asm("ics");
else|#
directive|else
name|__isync
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|ret
operator|=
name|fetch_and_add
argument_list|(
operator|(
name|atomic_p
operator|)
name|p
argument_list|,
operator|(
name|int
operator|)
name|val
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__GNUC__
asm|asm("ics");
else|#
directive|else
name|__isync
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function
specifier|static
specifier|inline
name|int
else|#
directive|else
specifier|static
name|int
endif|#
directive|endif
name|isc_atomic_cmpxchg
parameter_list|(
name|atomic_p
name|p
parameter_list|,
name|int
name|old
parameter_list|,
name|int
name|new
parameter_list|)
block|{
name|int
name|orig
init|=
name|old
decl_stmt|;
ifdef|#
directive|ifdef
name|__GNUC__
asm|asm("ics");
else|#
directive|else
name|__isync
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|compare_and_swap
argument_list|(
name|p
argument_list|,
operator|&
name|orig
argument_list|,
name|new
argument_list|)
condition|)
name|orig
operator|=
name|old
expr_stmt|;
ifdef|#
directive|ifdef
name|__GNUC__
asm|asm("ics");
else|#
directive|else
name|__isync
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|orig
operator|)
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ISC_PLATFORM_USEGCCASM
argument_list|)
operator|||
name|defined
argument_list|(
name|ISC_PLATFORM_USEMACASM
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
name|orig
decl_stmt|;
asm|__asm__
specifier|volatile
asm|(
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USEMACASM
asm|"1:" 		"lwarx r6, 0, %1\n" 		"mr %0, r6\n" 		"add r6, r6, %2\n" 		"stwcx. r6, 0, %1\n" 		"bne- 1b\n" 		"sync"
else|#
directive|else
asm|"1:" 		"lwarx 6, 0, %1\n" 		"mr %0, 6\n" 		"add 6, 6, %2\n" 		"stwcx. 6, 0, %1\n" 		"bne- 1b\n" 		"sync"
endif|#
directive|endif
asm|: "=&r"(orig) 		: "r"(p), "r"(val) 		: "r6", "memory" 		);
return|return
operator|(
name|orig
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
name|void
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|(
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USEMACASM
asm|"1:" 		"lwarx r6, 0, %0\n" 		"lwz r6, %1\n" 		"stwcx. r6, 0, %0\n" 		"bne- 1b\n" 		"sync"
else|#
directive|else
asm|"1:" 		"lwarx 6, 0, %0\n" 		"lwz 6, %1\n" 		"stwcx. 6, 0, %0\n" 		"bne- 1b\n" 		"sync"
endif|#
directive|endif
asm|: 		: "r"(p), "m"(val) 		: "r6", "memory" 		);
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
name|orig
decl_stmt|;
asm|__asm__
specifier|volatile
asm|(
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USEMACASM
asm|"1:" 		"lwarx r6, 0, %1\n" 		"mr %0,r6\n" 		"cmpw r6, %2\n" 		"bne 2f\n" 		"mr r6, %3\n" 		"stwcx. r6, 0, %1\n" 		"bne- 1b\n" 		"2:\n" 		"sync"
else|#
directive|else
asm|"1:" 		"lwarx 6, 0, %1\n" 		"mr %0,6\n" 		"cmpw 6, %2\n" 		"bne 2f\n" 		"mr 6, %3\n" 		"stwcx. 6, 0, %1\n" 		"bne- 1b\n" 		"2:\n" 		"sync"
endif|#
directive|endif
asm|: "=&r" (orig) 		: "r"(p), "r"(cmpval), "r"(val) 		: "r6", "memory" 		);
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

