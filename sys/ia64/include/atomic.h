begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_H_
end_define

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|__asm __volatile("mf")
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|mb()
end_define

begin_comment
comment|/*  * Various simple arithmetic on memory which is atomic in the presence  * of interrupts and SMP safe.  */
end_comment

begin_comment
comment|/*  * Everything is built out of cmpxchg.  */
end_comment

begin_define
define|#
directive|define
name|IA64_CMPXCHG
parameter_list|(
name|sz
parameter_list|,
name|sem
parameter_list|,
name|p
parameter_list|,
name|cmpval
parameter_list|,
name|newval
parameter_list|,
name|ret
parameter_list|)
define|\
value|__asm __volatile (						\ 		"mov ar.ccv=%2;;\n\t"					\ 		"cmpxchg" #sz "." #sem " %0=%4,%3,ar.ccv\n\t"		\ 		: "=r" (ret), "=m" (*p)					\ 		: "r" ((uint64_t)cmpval), "r" (newval), "m" (*p)	\ 		: "memory")
end_define

begin_comment
comment|/*  * Some common forms of cmpxch.  */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|ia64_cmpxchg_acq_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
name|IA64_CMPXCHG
argument_list|(
literal|4
argument_list|,
name|acq
argument_list|,
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|,
name|ret
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|ia64_cmpxchg_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
name|IA64_CMPXCHG
argument_list|(
literal|4
argument_list|,
name|rel
argument_list|,
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|,
name|ret
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|ia64_cmpxchg_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
name|IA64_CMPXCHG
argument_list|(
literal|8
argument_list|,
name|acq
argument_list|,
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|,
name|ret
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|ia64_cmpxchg_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
name|IA64_CMPXCHG
argument_list|(
literal|8
argument_list|,
name|rel
argument_list|,
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|,
name|ret
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ATOMIC_STORE_LOAD
parameter_list|(
name|type
parameter_list|,
name|width
parameter_list|,
name|size
parameter_list|)
define|\
value|static __inline uint##width##_t					\ 	ia64_ld_acq_##width(volatile uint##width##_t* p)		\ 	{								\ 		uint##width##_t v;					\ 		__asm __volatile ("ld" size ".acq %0=%1" : "=r" (v)	\ 		    : "m" (*p) : "memory");				\ 		return (v);						\ 	}								\ 									\ 	static __inline uint##width##_t					\ 	atomic_load_acq_##width(volatile uint##width##_t* p)		\ 	{								\ 		uint##width##_t v;					\ 		__asm __volatile ("ld" size ".acq %0=%1" : "=r" (v)	\ 		    : "m" (*p) : "memory");				\ 		return (v);						\ 	}								\ 									\ 	static __inline uint##width##_t					\ 	atomic_load_acq_##type(volatile uint##width##_t* p)		\ 	{								\ 		uint##width##_t v;					\ 		__asm __volatile ("ld" size ".acq %0=%1" : "=r" (v)	\ 		    : "m" (*p) : "memory");				\ 		return (v);						\ 	}								\ 								       	\ 	static __inline void						\ 	ia64_st_rel_##width(volatile uint##width##_t* p, uint##width##_t v) \ 	{								\ 		__asm __volatile ("st" size ".rel %0=%1" : "=m" (*p)	\ 		    : "r" (v) : "memory");				\ 	}								\ 									\ 	static __inline void						\ 	atomic_store_rel_##width(volatile uint##width##_t* p,		\ 	    uint##width##_t v)						\ 	{								\ 		__asm __volatile ("st" size ".rel %0=%1" : "=m" (*p)	\ 		    : "r" (v) : "memory");				\ 	}								\ 									\ 	static __inline void						\ 	atomic_store_rel_##type(volatile uint##width##_t* p,		\ 	    uint##width##_t v)						\ 	{								\ 		__asm __volatile ("st" size ".rel %0=%1" : "=m" (*p)	\ 		    : "r" (v) : "memory");				\ 	}
end_define

begin_macro
name|ATOMIC_STORE_LOAD
argument_list|(
argument|char
argument_list|,
literal|8
argument_list|,
literal|"1"
argument_list|)
end_macro

begin_macro
name|ATOMIC_STORE_LOAD
argument_list|(
argument|short
argument_list|,
literal|16
argument_list|,
literal|"2"
argument_list|)
end_macro

begin_macro
name|ATOMIC_STORE_LOAD
argument_list|(
argument|int
argument_list|,
literal|32
argument_list|,
literal|"4"
argument_list|)
end_macro

begin_macro
name|ATOMIC_STORE_LOAD
argument_list|(
argument|long
argument_list|,
literal|64
argument_list|,
literal|"8"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|ATOMIC_STORE_LOAD
end_undef

begin_define
define|#
directive|define
name|atomic_load_acq_ptr
parameter_list|(
name|p
parameter_list|)
define|\
value|((void *)atomic_load_acq_64((volatile uint64_t *)p))
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_store_rel_64((volatile uint64_t *)p, (uint64_t)v)
end_define

begin_define
define|#
directive|define
name|IA64_ATOMIC
parameter_list|(
name|sz
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|width
parameter_list|,
name|op
parameter_list|)
define|\
value|static __inline type						\ 	atomic_##name##_acq_##width(volatile type *p, type v)		\ 	{								\ 		type old, ret;						\ 		do {							\ 			old = *p;					\ 			IA64_CMPXCHG(sz, acq, p, old, old op v, ret);	\ 		} while (ret != old);					\ 		return (old);						\ 	}								\ 									\ 	static __inline type						\ 	atomic_##name##_rel_##width(volatile type *p, type v)		\ 	{								\ 		type old, ret;						\ 		do {							\ 			old = *p;					\ 			IA64_CMPXCHG(sz, rel, p, old, old op v, ret);	\ 		} while (ret != old);					\ 		return (old);						\ 	}
end_define

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
argument|set
argument_list|,
literal|8
argument_list|,
argument||
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
argument|set
argument_list|,
literal|16
argument_list|,
argument||
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|4
argument_list|,
argument|uint32_t
argument_list|,
argument|set
argument_list|,
literal|32
argument_list|,
argument||
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|8
argument_list|,
argument|uint64_t
argument_list|,
argument|set
argument_list|,
literal|64
argument_list|,
argument||
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
argument|clear
argument_list|,
literal|8
argument_list|,
argument|&~
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
argument|clear
argument_list|,
literal|16
argument_list|,
argument|&~
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|4
argument_list|,
argument|uint32_t
argument_list|,
argument|clear
argument_list|,
literal|32
argument_list|,
argument|&~
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|8
argument_list|,
argument|uint64_t
argument_list|,
argument|clear
argument_list|,
literal|64
argument_list|,
argument|&~
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
argument|add
argument_list|,
literal|8
argument_list|,
argument|+
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
argument|add
argument_list|,
literal|16
argument_list|,
argument|+
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|4
argument_list|,
argument|uint32_t
argument_list|,
argument|add
argument_list|,
literal|32
argument_list|,
argument|+
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|8
argument_list|,
argument|uint64_t
argument_list|,
argument|add
argument_list|,
literal|64
argument_list|,
argument|+
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
argument|subtract
argument_list|,
literal|8
argument_list|,
argument|-
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
argument|subtract
argument_list|,
literal|16
argument_list|,
argument|-
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|4
argument_list|,
argument|uint32_t
argument_list|,
argument|subtract
argument_list|,
literal|32
argument_list|,
argument|-
argument_list|)
end_macro

begin_macro
name|IA64_ATOMIC
argument_list|(
literal|8
argument_list|,
argument|uint64_t
argument_list|,
argument|subtract
argument_list|,
literal|64
argument_list|,
argument|-
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|IA64_ATOMIC
end_undef

begin_define
define|#
directive|define
name|atomic_set_8
value|atomic_set_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_clear_8
value|atomic_clear_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_add_8
value|atomic_add_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_subtract_8
value|atomic_subtract_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_set_16
value|atomic_set_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_clear_16
value|atomic_clear_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_add_16
value|atomic_add_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_subtract_16
value|atomic_subtract_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_set_32
value|atomic_set_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_32
value|atomic_clear_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_add_32
value|atomic_add_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_32
value|atomic_subtract_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_set_64
value|atomic_set_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_64
value|atomic_clear_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_add_64
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_64
value|atomic_subtract_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_set_char
value|atomic_set_8
end_define

begin_define
define|#
directive|define
name|atomic_clear_char
value|atomic_clear_8
end_define

begin_define
define|#
directive|define
name|atomic_add_char
value|atomic_add_8
end_define

begin_define
define|#
directive|define
name|atomic_subtract_char
value|atomic_subtract_8
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_char
value|atomic_set_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_char
value|atomic_clear_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_char
value|atomic_add_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_char
value|atomic_subtract_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_char
value|atomic_set_rel_8
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_char
value|atomic_clear_rel_8
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_char
value|atomic_add_rel_8
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_char
value|atomic_subtract_rel_8
end_define

begin_define
define|#
directive|define
name|atomic_set_short
value|atomic_set_16
end_define

begin_define
define|#
directive|define
name|atomic_clear_short
value|atomic_clear_16
end_define

begin_define
define|#
directive|define
name|atomic_add_short
value|atomic_add_16
end_define

begin_define
define|#
directive|define
name|atomic_subtract_short
value|atomic_subtract_16
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_short
value|atomic_set_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_short
value|atomic_clear_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_short
value|atomic_add_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_short
value|atomic_subtract_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_short
value|atomic_set_rel_16
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_short
value|atomic_clear_rel_16
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_short
value|atomic_add_rel_16
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_short
value|atomic_subtract_rel_16
end_define

begin_define
define|#
directive|define
name|atomic_set_int
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_int
value|atomic_clear_32
end_define

begin_define
define|#
directive|define
name|atomic_add_int
value|atomic_add_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_int
value|atomic_subtract_32
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_int
value|atomic_set_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_int
value|atomic_clear_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_int
value|atomic_add_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_int
value|atomic_subtract_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_int
value|atomic_set_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_int
value|atomic_clear_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_int
value|atomic_add_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_int
value|atomic_subtract_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_set_long
value|atomic_set_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_long
value|atomic_clear_64
end_define

begin_define
define|#
directive|define
name|atomic_add_long
value|atomic_add_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_long
value|atomic_subtract_64
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_long
value|atomic_set_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_long
value|atomic_clear_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_long
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_long
value|atomic_subtract_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_long
value|atomic_set_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_long
value|atomic_clear_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_long
value|atomic_add_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_long
value|atomic_subtract_rel_64
end_define

begin_comment
comment|/* XXX Needs casting. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_ptr
value|atomic_set_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_ptr
value|atomic_clear_64
end_define

begin_define
define|#
directive|define
name|atomic_add_ptr
value|atomic_add_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_ptr
value|atomic_subtract_64
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_ptr
value|atomic_set_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_ptr
value|atomic_clear_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_ptr
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_ptr
value|atomic_subtract_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_ptr
value|atomic_set_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_ptr
value|atomic_clear_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_ptr
value|atomic_add_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_ptr
value|atomic_subtract_rel_64
end_define

begin_undef
undef|#
directive|undef
name|IA64_CMPXCHG
end_undef

begin_comment
comment|/*  * Atomically compare the value stored at *p with cmpval and if the  * two values are equal, update the value of *p with newval. Returns  * zero if the compare failed, nonzero otherwise.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_acq_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
return|return
operator|(
name|ia64_cmpxchg_acq_32
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
operator|==
name|cmpval
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
return|return
operator|(
name|ia64_cmpxchg_rel_32
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
operator|==
name|cmpval
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Atomically compare the value stored at *p with cmpval and if the  * two values are equal, update the value of *p with newval. Returns  * zero if the compare failed, nonzero otherwise.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
return|return
operator|(
name|ia64_cmpxchg_acq_64
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
operator|==
name|cmpval
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
return|return
operator|(
name|ia64_cmpxchg_rel_64
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
operator|==
name|cmpval
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_cmpset_32
value|atomic_cmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_64
value|atomic_cmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_int
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_long
value|atomic_cmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_int
value|atomic_cmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_int
value|atomic_cmpset_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_long
value|atomic_cmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_long
value|atomic_cmpset_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
parameter_list|(
name|p
parameter_list|,
name|o
parameter_list|,
name|n
parameter_list|)
define|\
value|(atomic_cmpset_acq_64((volatile uint64_t *)p, (uint64_t)o, (uint64_t)n))
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
value|atomic_cmpset_acq_ptr
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|o
parameter_list|,
name|n
parameter_list|)
define|\
value|(atomic_cmpset_rel_64((volatile uint64_t *)p, (uint64_t)o, (uint64_t)n))
end_define

begin_function
specifier|static
name|__inline
name|uint32_t
name|atomic_readandclear_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|;
do|do
block|{
name|val
operator|=
operator|*
name|p
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|atomic_cmpset_32
argument_list|(
name|p
argument_list|,
name|val
argument_list|,
literal|0
argument_list|)
condition|)
do|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|atomic_readandclear_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|)
block|{
name|uint64_t
name|val
decl_stmt|;
do|do
block|{
name|val
operator|=
operator|*
name|p
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|atomic_cmpset_64
argument_list|(
name|p
argument_list|,
name|val
argument_list|,
literal|0
argument_list|)
condition|)
do|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_readandclear_int
value|atomic_readandclear_32
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long
value|atomic_readandclear_64
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
value|atomic_readandclear_64
end_define

begin_comment
comment|/*  * Atomically add the value of v to the integer pointed to by p and return  * the previous value of *p.  *  * XXX: Should we use the fetchadd instruction here?  */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|atomic_fetchadd_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
name|uint32_t
name|value
decl_stmt|;
do|do
block|{
name|value
operator|=
operator|*
name|p
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|atomic_cmpset_32
argument_list|(
name|p
argument_list|,
name|value
argument_list|,
name|value
operator|+
name|v
argument_list|)
condition|)
do|;
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_fetchadd_int
value|atomic_fetchadd_32
end_define

begin_function
specifier|static
name|__inline
name|u_long
name|atomic_fetchadd_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|v
parameter_list|)
block|{
name|u_long
name|value
decl_stmt|;
do|do
block|{
name|value
operator|=
operator|*
name|p
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|atomic_cmpset_64
argument_list|(
name|p
argument_list|,
name|value
argument_list|,
name|value
operator|+
name|v
argument_list|)
condition|)
do|;
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *<type> atomic_swap_<type>(volatile<type> *p,<type> v);  */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|atomic_swap_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
name|uint32_t
name|r
decl_stmt|;
asm|__asm __volatile ("xchg4 %0 = %3, %2;;" : "=r"(r), "=m"(*p) :
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|r
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_swap_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
name|uint64_t
name|r
decl_stmt|;
asm|__asm __volatile ("xchg8 %0 = %3, %2;;" : "=r"(r), "=m"(*p) :
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|r
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|atomic_swap_int
value|atomic_swap_32
end_define

begin_define
define|#
directive|define
name|atomic_swap_long
value|atomic_swap_64
end_define

begin_define
define|#
directive|define
name|atomic_swap_ptr
value|atomic_swap_64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_ATOMIC_H_ */
end_comment

end_unit

