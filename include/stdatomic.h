begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Ed Schouten<ed@FreeBSD.org>  *                    David Chisnall<theraven@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_STDATOMIC_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|c_atomic
argument_list|)
operator|||
name|__has_extension
argument_list|(
name|cxx_atomic
argument_list|)
end_if

begin_define
define|#
directive|define
name|__CLANG_ATOMICS
end_define

begin_elif
elif|#
directive|elif
name|__GNUC_PREREQ__
argument_list|(
literal|4
operator|,
literal|7
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__GNUC_ATOMICS
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_error
error|#
directive|error
literal|"stdatomic.h does not support your compiler"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__CLANG_ATOMICS
argument_list|)
end_if

begin_define
define|#
directive|define
name|_Atomic
parameter_list|(
name|T
parameter_list|)
value|struct { volatile T __val; }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 7.17.2 Initialization.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CLANG_ATOMICS
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATOMIC_VAR_INIT
parameter_list|(
name|value
parameter_list|)
value|(value)
end_define

begin_define
define|#
directive|define
name|atomic_init
parameter_list|(
name|obj
parameter_list|,
name|value
parameter_list|)
value|__c11_atomic_init(obj, value)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATOMIC_VAR_INIT
parameter_list|(
name|value
parameter_list|)
value|{ .__val = (value) }
end_define

begin_define
define|#
directive|define
name|atomic_init
parameter_list|(
name|obj
parameter_list|,
name|value
parameter_list|)
value|((void)((obj)->__val = (value)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Clang and recent GCC both provide predefined macros for the memory  * orderings.  If we are using a compiler that doesn't define them, use the  * clang values - these will be ignored in the fallback path.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ATOMIC_RELAXED
end_ifndef

begin_define
define|#
directive|define
name|__ATOMIC_RELAXED
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ATOMIC_CONSUME
end_ifndef

begin_define
define|#
directive|define
name|__ATOMIC_CONSUME
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ATOMIC_ACQUIRE
end_ifndef

begin_define
define|#
directive|define
name|__ATOMIC_ACQUIRE
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ATOMIC_RELEASE
end_ifndef

begin_define
define|#
directive|define
name|__ATOMIC_RELEASE
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ATOMIC_ACQ_REL
end_ifndef

begin_define
define|#
directive|define
name|__ATOMIC_ACQ_REL
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ATOMIC_SEQ_CST
end_ifndef

begin_define
define|#
directive|define
name|__ATOMIC_SEQ_CST
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 7.17.3 Order and consistency.  *  * The memory_order_* constants that denote the barrier behaviour of the  * atomic operations.  */
end_comment

begin_enum
enum|enum
name|memory_order
block|{
name|memory_order_relaxed
init|=
name|__ATOMIC_RELAXED
block|,
name|memory_order_consume
init|=
name|__ATOMIC_CONSUME
block|,
name|memory_order_acquire
init|=
name|__ATOMIC_ACQUIRE
block|,
name|memory_order_release
init|=
name|__ATOMIC_RELEASE
block|,
name|memory_order_acq_rel
init|=
name|__ATOMIC_ACQ_REL
block|,
name|memory_order_seq_cst
init|=
name|__ATOMIC_SEQ_CST
block|}
enum|;
end_enum

begin_comment
comment|/*  * 7.17.4 Fences.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__CLANG_ATOMICS
end_ifdef

begin_define
define|#
directive|define
name|atomic_thread_fence
parameter_list|(
name|order
parameter_list|)
value|__c11_atomic_thread_fence(order)
end_define

begin_define
define|#
directive|define
name|atomic_signal_fence
parameter_list|(
name|order
parameter_list|)
value|__c11_atomic_signal_fence(order)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC_ATOMICS
argument_list|)
end_elif

begin_define
define|#
directive|define
name|atomic_thread_fence
parameter_list|(
name|order
parameter_list|)
value|__atomic_thread_fence(order)
end_define

begin_define
define|#
directive|define
name|atomic_signal_fence
parameter_list|(
name|order
parameter_list|)
value|__atomic_signal_fence(order)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|atomic_thread_fence
parameter_list|(
name|order
parameter_list|)
value|((void)(order), __sync_synchronize())
end_define

begin_define
define|#
directive|define
name|atomic_signal_fence
parameter_list|(
name|order
parameter_list|)
value|__extension__ ({		\ 	(void)(order);							\ 	__asm volatile ("" ::: "memory");				\ 	(void)0;							\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 7.17.5 Lock-free property.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CLANG_ATOMICS
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC_ATOMICS
argument_list|)
end_if

begin_define
define|#
directive|define
name|atomic_is_lock_free
parameter_list|(
name|obj
parameter_list|)
define|\
value|__atomic_is_lock_free(sizeof((obj)->__val),&(obj)->__val)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|atomic_is_lock_free
parameter_list|(
name|obj
parameter_list|)
define|\
value|((void)(obj), sizeof((obj)->__val)<= sizeof(void *))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 7.17.6 Atomic integer types.  */
end_comment

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|_Bool
argument_list|)
name|atomic_bool
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|char
argument_list|)
name|atomic_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|signed
name|char
argument_list|)
name|atomic_schar
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|unsigned
name|char
argument_list|)
name|atomic_uchar
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|short
argument_list|)
name|atomic_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|unsigned
name|short
argument_list|)
name|atomic_ushort
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|atomic_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|unsigned
name|int
argument_list|)
name|atomic_uint
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|long
argument_list|)
name|atomic_long
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|unsigned
name|long
argument_list|)
name|atomic_ulong
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|long
name|long
argument_list|)
name|atomic_llong
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|unsigned
name|long
name|long
argument_list|)
name|atomic_ullong
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|typedef _Atomic(__char16_t)		atomic_char16_t; typedef _Atomic(__char32_t)		atomic_char32_t;
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|___wchar_t
argument_list|)
name|atomic_wchar_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__int_least8_t
argument_list|)
name|atomic_int_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__uint_least8_t
argument_list|)
name|atomic_uint_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__int_least16_t
argument_list|)
name|atomic_int_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__uint_least16_t
argument_list|)
name|atomic_uint_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__int_least32_t
argument_list|)
name|atomic_int_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__uint_least32_t
argument_list|)
name|atomic_uint_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__int_least64_t
argument_list|)
name|atomic_int_least64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__uint_least64_t
argument_list|)
name|atomic_uint_least64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__int_fast8_t
argument_list|)
name|atomic_int_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__uint_fast8_t
argument_list|)
name|atomic_uint_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__int_fast16_t
argument_list|)
name|atomic_int_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__uint_fast16_t
argument_list|)
name|atomic_uint_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__int_fast32_t
argument_list|)
name|atomic_int_fast32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__uint_fast32_t
argument_list|)
name|atomic_uint_fast32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__int_fast64_t
argument_list|)
name|atomic_int_fast64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__uint_fast64_t
argument_list|)
name|atomic_uint_fast64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__intptr_t
argument_list|)
name|atomic_intptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__uintptr_t
argument_list|)
name|atomic_uintptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__size_t
argument_list|)
name|atomic_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__ptrdiff_t
argument_list|)
name|atomic_ptrdiff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__intmax_t
argument_list|)
name|atomic_intmax_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|__uintmax_t
argument_list|)
name|atomic_uintmax_t
typedef|;
end_typedef

begin_comment
comment|/*  * 7.17.7 Operations on atomic types.  */
end_comment

begin_comment
comment|/*  * Compiler-specific operations.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CLANG_ATOMICS
argument_list|)
end_if

begin_define
define|#
directive|define
name|atomic_compare_exchange_strong_explicit
parameter_list|(
name|object
parameter_list|,
name|expected
parameter_list|,	\
name|desired
parameter_list|,
name|success
parameter_list|,
name|failure
parameter_list|)
define|\
value|__c11_atomic_compare_exchange_strong(object, expected, desired,	\ 	    success, failure)
end_define

begin_define
define|#
directive|define
name|atomic_compare_exchange_weak_explicit
parameter_list|(
name|object
parameter_list|,
name|expected
parameter_list|,		\
name|desired
parameter_list|,
name|success
parameter_list|,
name|failure
parameter_list|)
define|\
value|__c11_atomic_compare_exchange_weak(object, expected, desired,	\ 	    success, failure)
end_define

begin_define
define|#
directive|define
name|atomic_exchange_explicit
parameter_list|(
name|object
parameter_list|,
name|desired
parameter_list|,
name|order
parameter_list|)
define|\
value|__c11_atomic_exchange(object, desired, order)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_add_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|__c11_atomic_fetch_add(object, operand, order)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_and_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|__c11_atomic_fetch_and(object, operand, order)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_or_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|__c11_atomic_fetch_or(object, operand, order)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_sub_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|__c11_atomic_fetch_sub(object, operand, order)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_xor_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|__c11_atomic_fetch_xor(object, operand, order)
end_define

begin_define
define|#
directive|define
name|atomic_load_explicit
parameter_list|(
name|object
parameter_list|,
name|order
parameter_list|)
define|\
value|__c11_atomic_load(object, order)
end_define

begin_define
define|#
directive|define
name|atomic_store_explicit
parameter_list|(
name|object
parameter_list|,
name|desired
parameter_list|,
name|order
parameter_list|)
define|\
value|__c11_atomic_store(object, desired, order)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC_ATOMICS
argument_list|)
end_elif

begin_define
define|#
directive|define
name|atomic_compare_exchange_strong_explicit
parameter_list|(
name|object
parameter_list|,
name|expected
parameter_list|,	\
name|desired
parameter_list|,
name|success
parameter_list|,
name|failure
parameter_list|)
define|\
value|__atomic_compare_exchange_n(&(object)->__val, expected,		\ 	    desired, 0, success, failure)
end_define

begin_define
define|#
directive|define
name|atomic_compare_exchange_weak_explicit
parameter_list|(
name|object
parameter_list|,
name|expected
parameter_list|,		\
name|desired
parameter_list|,
name|success
parameter_list|,
name|failure
parameter_list|)
define|\
value|__atomic_compare_exchange_n(&(object)->__val, expected,		\ 	    desired, 1, success, failure)
end_define

begin_define
define|#
directive|define
name|atomic_exchange_explicit
parameter_list|(
name|object
parameter_list|,
name|desired
parameter_list|,
name|order
parameter_list|)
define|\
value|__atomic_exchange_n(&(object)->__val, desired, order)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_add_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|__atomic_fetch_add(&(object)->__val, operand, order)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_and_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|__atomic_fetch_and(&(object)->__val, operand, order)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_or_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|__atomic_fetch_or(&(object)->__val, operand, order)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_sub_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|__atomic_fetch_sub(&(object)->__val, operand, order)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_xor_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|__atomic_fetch_xor(&(object)->__val, operand, order)
end_define

begin_define
define|#
directive|define
name|atomic_load_explicit
parameter_list|(
name|object
parameter_list|,
name|order
parameter_list|)
define|\
value|__atomic_load_n(&(object)->__val, order)
end_define

begin_define
define|#
directive|define
name|atomic_store_explicit
parameter_list|(
name|object
parameter_list|,
name|desired
parameter_list|,
name|order
parameter_list|)
define|\
value|__atomic_store_n(&(object)->__val, desired, order)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|atomic_compare_exchange_strong_explicit
parameter_list|(
name|object
parameter_list|,
name|expected
parameter_list|,	\
name|desired
parameter_list|,
name|success
parameter_list|,
name|failure
parameter_list|)
value|__extension__ ({			\ 	__typeof__(expected) __ep = (expected);				\ 	__typeof__(*__ep) __e = *__ep;					\ 	(void)(success); (void)(failure);				\ 	(_Bool)((*__ep = __sync_val_compare_and_swap(&(object)->__val,	\ 	    __e, desired)) == __e);					\ })
end_define

begin_define
define|#
directive|define
name|atomic_compare_exchange_weak_explicit
parameter_list|(
name|object
parameter_list|,
name|expected
parameter_list|,		\
name|desired
parameter_list|,
name|success
parameter_list|,
name|failure
parameter_list|)
define|\
value|atomic_compare_exchange_strong_explicit(object, expected,	\ 		desired, success, failure)
end_define

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__sync_swap
argument_list|)
end_if

begin_comment
comment|/* Clang provides a full-barrier atomic exchange - use it if available. */
end_comment

begin_define
define|#
directive|define
name|atomic_exchange_explicit
parameter_list|(
name|object
parameter_list|,
name|desired
parameter_list|,
name|order
parameter_list|)
define|\
value|((void)(order), __sync_swap(&(object)->__val, desired))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * __sync_lock_test_and_set() is only an acquire barrier in theory (although in  * practice it is usually a full barrier) so we need an explicit barrier before  * it.  */
end_comment

begin_define
define|#
directive|define
name|atomic_exchange_explicit
parameter_list|(
name|object
parameter_list|,
name|desired
parameter_list|,
name|order
parameter_list|)
define|\
value|__extension__ ({							\ 	__typeof__(object) __o = (object);				\ 	__typeof__(desired) __d = (desired);				\ 	(void)(order);							\ 	__sync_synchronize();						\ 	__sync_lock_test_and_set(&(__o)->__val, __d);			\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|atomic_fetch_add_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|((void)(order), __sync_fetch_and_add(&(object)->__val, operand))
end_define

begin_define
define|#
directive|define
name|atomic_fetch_and_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|((void)(order), __sync_fetch_and_and(&(object)->__val, operand))
end_define

begin_define
define|#
directive|define
name|atomic_fetch_or_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|((void)(order), __sync_fetch_and_or(&(object)->__val, operand))
end_define

begin_define
define|#
directive|define
name|atomic_fetch_sub_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|((void)(order), __sync_fetch_and_sub(&(object)->__val, operand))
end_define

begin_define
define|#
directive|define
name|atomic_fetch_xor_explicit
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|,
name|order
parameter_list|)
define|\
value|((void)(order), __sync_fetch_and_xor(&(object)->__val, operand))
end_define

begin_define
define|#
directive|define
name|atomic_load_explicit
parameter_list|(
name|object
parameter_list|,
name|order
parameter_list|)
define|\
value|((void)(order), __sync_fetch_and_add(&(object)->__val, 0))
end_define

begin_define
define|#
directive|define
name|atomic_store_explicit
parameter_list|(
name|object
parameter_list|,
name|desired
parameter_list|,
name|order
parameter_list|)
define|\
value|((void)atomic_exchange_explicit(object, desired, order))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Convenience functions.  */
end_comment

begin_define
define|#
directive|define
name|atomic_compare_exchange_strong
parameter_list|(
name|object
parameter_list|,
name|expected
parameter_list|,
name|desired
parameter_list|)
define|\
value|atomic_compare_exchange_strong_explicit(object, expected,	\ 	    desired, memory_order_seq_cst, memory_order_seq_cst)
end_define

begin_define
define|#
directive|define
name|atomic_compare_exchange_weak
parameter_list|(
name|object
parameter_list|,
name|expected
parameter_list|,
name|desired
parameter_list|)
define|\
value|atomic_compare_exchange_weak_explicit(object, expected,		\ 	    desired, memory_order_seq_cst, memory_order_seq_cst)
end_define

begin_define
define|#
directive|define
name|atomic_exchange
parameter_list|(
name|object
parameter_list|,
name|desired
parameter_list|)
define|\
value|atomic_exchange_explicit(object, desired, memory_order_seq_cst)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_add
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|)
define|\
value|atomic_fetch_add_explicit(object, operand, memory_order_seq_cst)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_and
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|)
define|\
value|atomic_fetch_and_explicit(object, operand, memory_order_seq_cst)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_or
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|)
define|\
value|atomic_fetch_or_explicit(object, operand, memory_order_seq_cst)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_sub
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|)
define|\
value|atomic_fetch_sub_explicit(object, operand, memory_order_seq_cst)
end_define

begin_define
define|#
directive|define
name|atomic_fetch_xor
parameter_list|(
name|object
parameter_list|,
name|operand
parameter_list|)
define|\
value|atomic_fetch_xor_explicit(object, operand, memory_order_seq_cst)
end_define

begin_define
define|#
directive|define
name|atomic_load
parameter_list|(
name|object
parameter_list|)
define|\
value|atomic_load_explicit(object, memory_order_seq_cst)
end_define

begin_define
define|#
directive|define
name|atomic_store
parameter_list|(
name|object
parameter_list|,
name|desired
parameter_list|)
define|\
value|atomic_store_explicit(object, desired, memory_order_seq_cst)
end_define

begin_comment
comment|/*  * 7.17.8 Atomic flag type and operations.  */
end_comment

begin_typedef
typedef|typedef
name|atomic_bool
name|atomic_flag
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATOMIC_FLAG_INIT
value|ATOMIC_VAR_INIT(0)
end_define

begin_define
define|#
directive|define
name|atomic_flag_clear_explicit
parameter_list|(
name|object
parameter_list|,
name|order
parameter_list|)
define|\
value|atomic_store_explicit(object, 0, order)
end_define

begin_define
define|#
directive|define
name|atomic_flag_test_and_set_explicit
parameter_list|(
name|object
parameter_list|,
name|order
parameter_list|)
define|\
value|atomic_exchange_explicit(object, 1, order)
end_define

begin_define
define|#
directive|define
name|atomic_flag_clear
parameter_list|(
name|object
parameter_list|)
define|\
value|atomic_flag_clear_explicit(object, memory_order_seq_cst)
end_define

begin_define
define|#
directive|define
name|atomic_flag_test_and_set
parameter_list|(
name|object
parameter_list|)
define|\
value|atomic_flag_test_and_set_explicit(object, memory_order_seq_cst)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_STDATOMIC_H_ */
end_comment

end_unit

