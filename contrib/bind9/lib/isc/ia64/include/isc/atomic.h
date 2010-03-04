begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2006, 2007, 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: atomic.h,v 1.4.326.2 2009/02/06 23:47:11 tbox Exp $ */
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
comment|/*  * This routine atomically increments the value stored in 'p' by 'val', and  * returns the previous value.  *  * Open issue: can 'fetchadd' make the code faster for some particular values  * (e.g., 1 and -1)?  */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|isc_int32_t
ifdef|#
directive|ifdef
name|__GNUC__
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
endif|#
directive|endif
name|isc_atomic_xadd
argument_list|(
name|isc_int32_t
operator|*
name|p
argument_list|,
name|isc_int32_t
name|val
argument_list|)
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
asm|( 			"mov ar.ccv=%2;;" 			"cmpxchg4.acq %0=%4,%3,ar.ccv" 			: "=r" (swapped), "=m" (*p) 			: "r" (prev), "r" (swapped), "m" (*p) 			: "memory");
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
end_decl_stmt

begin_comment
comment|/*  * This routine atomically stores the value 'val' in 'p'.  */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|void
ifdef|#
directive|ifdef
name|__GNUC__
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
endif|#
directive|endif
name|isc_atomic_store
argument_list|(
name|isc_int32_t
operator|*
name|p
argument_list|,
name|isc_int32_t
name|val
argument_list|)
block|{
asm|__asm__
specifier|volatile
asm|( 		"st4.rel %0=%1" 		: "=m" (*p) 		: "r" (val) 		: "memory" 		);
block|}
end_decl_stmt

begin_comment
comment|/*  * This routine atomically replaces the value in 'p' with 'val', if the  * original value is equal to 'cmpval'.  The original value is returned in any  * case.  */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|isc_int32_t
ifdef|#
directive|ifdef
name|__GNUC__
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
endif|#
directive|endif
name|isc_atomic_cmpxchg
argument_list|(
name|isc_int32_t
operator|*
name|p
argument_list|,
name|isc_int32_t
name|cmpval
argument_list|,
name|isc_int32_t
name|val
argument_list|)
block|{
name|isc_int32_t
name|ret
decl_stmt|;
asm|__asm__
specifier|volatile
asm|( 		"mov ar.ccv=%2;;" 		"cmpxchg4.acq %0=%4,%3,ar.ccv" 		: "=r" (ret), "=m" (*p) 		: "r" (cmpval), "r" (val), "m" (*p) 		: "memory");
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_decl_stmt

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

