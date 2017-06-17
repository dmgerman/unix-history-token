begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_ATOMIC_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_ATOMIC_H
end_define

begin_define
define|#
directive|define
name|ATOMIC_INLINE
value|static inline
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|JEMALLOC_GCC_ATOMIC_ATOMICS
argument_list|)
end_if

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic_gcc_atomic.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|JEMALLOC_GCC_SYNC_ATOMICS
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic_gcc_sync.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic_msvc.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|JEMALLOC_C11_ATOMICS
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic_c11.h"
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Don't have atomics implemented on this platform."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This header gives more or less a backport of C11 atomics. The user can write  * JEMALLOC_GENERATE_ATOMICS(type, short_type, lg_sizeof_type); to generate  * counterparts of the C11 atomic functions for type, as so:  *   JEMALLOC_GENERATE_ATOMICS(int *, pi, 3);  * and then write things like:  *   int *some_ptr;  *   atomic_pi_t atomic_ptr_to_int;  *   atomic_store_pi(&atomic_ptr_to_int, some_ptr, ATOMIC_RELAXED);  *   int *prev_value = atomic_exchange_pi(&ptr_to_int, NULL, ATOMIC_ACQ_REL);  *   assert(some_ptr == prev_value);  * and expect things to work in the obvious way.  *  * Also included (with naming differences to avoid conflicts with the standard  * library):  *   atomic_fence(atomic_memory_order_t) (mimics C11's atomic_thread_fence).  *   ATOMIC_INIT (mimics C11's ATOMIC_VAR_INIT).  */
end_comment

begin_comment
comment|/*  * Pure convenience, so that we don't have to type "atomic_memory_order_"  * quite so often.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_RELAXED
value|atomic_memory_order_relaxed
end_define

begin_define
define|#
directive|define
name|ATOMIC_ACQUIRE
value|atomic_memory_order_acquire
end_define

begin_define
define|#
directive|define
name|ATOMIC_RELEASE
value|atomic_memory_order_release
end_define

begin_define
define|#
directive|define
name|ATOMIC_ACQ_REL
value|atomic_memory_order_acq_rel
end_define

begin_define
define|#
directive|define
name|ATOMIC_SEQ_CST
value|atomic_memory_order_seq_cst
end_define

begin_comment
comment|/*  * Not all platforms have 64-bit atomics.  If we do, this #define exposes that  * fact.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|LG_SIZEOF_PTR
operator|==
literal|3
operator|||
name|LG_SIZEOF_INT
operator|==
literal|3
operator|)
end_if

begin_define
define|#
directive|define
name|JEMALLOC_ATOMIC_U64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|JEMALLOC_GENERATE_ATOMICS
argument_list|(
argument|void *
argument_list|,
argument|p
argument_list|,
argument|LG_SIZEOF_PTR
argument_list|)
end_macro

begin_comment
comment|/*  * There's no actual guarantee that sizeof(bool) == 1, but it's true on the only  * platform that actually needs to know the size, MSVC.  */
end_comment

begin_macro
name|JEMALLOC_GENERATE_ATOMICS
argument_list|(
argument|bool
argument_list|,
argument|b
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|JEMALLOC_GENERATE_INT_ATOMICS
argument_list|(
argument|unsigned
argument_list|,
argument|u
argument_list|,
argument|LG_SIZEOF_INT
argument_list|)
end_macro

begin_macro
name|JEMALLOC_GENERATE_INT_ATOMICS
argument_list|(
argument|size_t
argument_list|,
argument|zu
argument_list|,
argument|LG_SIZEOF_PTR
argument_list|)
end_macro

begin_macro
name|JEMALLOC_GENERATE_INT_ATOMICS
argument_list|(
argument|ssize_t
argument_list|,
argument|zd
argument_list|,
argument|LG_SIZEOF_PTR
argument_list|)
end_macro

begin_macro
name|JEMALLOC_GENERATE_INT_ATOMICS
argument_list|(
argument|uint32_t
argument_list|,
argument|u32
argument_list|,
literal|2
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_ATOMIC_U64
end_ifdef

begin_macro
name|JEMALLOC_GENERATE_INT_ATOMICS
argument_list|(
argument|uint64_t
argument_list|,
argument|u64
argument_list|,
literal|3
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ATOMIC_INLINE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_ATOMIC_H */
end_comment

end_unit

