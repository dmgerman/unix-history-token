begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_ATOMIC_C11_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_ATOMIC_C11_H
end_define

begin_include
include|#
directive|include
file|<stdatomic.h>
end_include

begin_define
define|#
directive|define
name|ATOMIC_INIT
parameter_list|(
modifier|...
parameter_list|)
value|ATOMIC_VAR_INIT(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|atomic_memory_order_t
value|memory_order
end_define

begin_define
define|#
directive|define
name|atomic_memory_order_relaxed
value|memory_order_relaxed
end_define

begin_define
define|#
directive|define
name|atomic_memory_order_acquire
value|memory_order_acquire
end_define

begin_define
define|#
directive|define
name|atomic_memory_order_release
value|memory_order_release
end_define

begin_define
define|#
directive|define
name|atomic_memory_order_acq_rel
value|memory_order_acq_rel
end_define

begin_define
define|#
directive|define
name|atomic_memory_order_seq_cst
value|memory_order_seq_cst
end_define

begin_define
define|#
directive|define
name|atomic_fence
value|atomic_thread_fence
end_define

begin_define
define|#
directive|define
name|JEMALLOC_GENERATE_ATOMICS
parameter_list|(
name|type
parameter_list|,
name|short_type
parameter_list|,			\
comment|/* unused */
name|lg_size
parameter_list|)
define|\
value|typedef _Atomic(type) atomic_##short_type##_t;				\ 									\ ATOMIC_INLINE type							\ atomic_load_##short_type(const atomic_##short_type##_t *a,		\     atomic_memory_order_t mo) {						\
comment|/*								\ 	 * A strict interpretation of the C standard prevents		\ 	 * atomic_load from taking a const argument, but it's		\ 	 * convenient for our purposes. This cast is a workaround.	\ 	 */
value|\ 	atomic_##short_type##_t* a_nonconst =				\ 	    (atomic_##short_type##_t*)a;				\ 	return atomic_load_explicit(a_nonconst, mo);			\ }									\ 									\ ATOMIC_INLINE void							\ atomic_store_##short_type(atomic_##short_type##_t *a,			\     type val, atomic_memory_order_t mo) {				\ 	atomic_store_explicit(a, val, mo);				\ }									\ 									\ ATOMIC_INLINE type							\ atomic_exchange_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	return atomic_exchange_explicit(a, val, mo);			\ }									\ 									\ ATOMIC_INLINE bool							\ atomic_compare_exchange_weak_##short_type(atomic_##short_type##_t *a,	\     type *expected, type desired, atomic_memory_order_t success_mo,	\     atomic_memory_order_t failure_mo) {					\ 	return atomic_compare_exchange_weak_explicit(a, expected,	\ 	    desired, success_mo, failure_mo);				\ }									\ 									\ ATOMIC_INLINE bool							\ atomic_compare_exchange_strong_##short_type(atomic_##short_type##_t *a,	\     type *expected, type desired, atomic_memory_order_t success_mo,	\     atomic_memory_order_t failure_mo) {					\ 	return atomic_compare_exchange_strong_explicit(a, expected,	\ 	    desired, success_mo, failure_mo);				\ }
end_define

begin_comment
comment|/*  * Integral types have some special operations available that non-integral ones  * lack.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_GENERATE_INT_ATOMICS
parameter_list|(
name|type
parameter_list|,
name|short_type
parameter_list|, 		\
comment|/* unused */
name|lg_size
parameter_list|)
define|\
value|JEMALLOC_GENERATE_ATOMICS(type, short_type,
comment|/* unused */
value|lg_size)	\ 									\ ATOMIC_INLINE type							\ atomic_fetch_add_##short_type(atomic_##short_type##_t *a,		\     type val, atomic_memory_order_t mo) {				\ 	return atomic_fetch_add_explicit(a, val, mo);			\ }									\ 									\ ATOMIC_INLINE type							\ atomic_fetch_sub_##short_type(atomic_##short_type##_t *a,		\     type val, atomic_memory_order_t mo) {				\ 	return atomic_fetch_sub_explicit(a, val, mo);			\ }									\ ATOMIC_INLINE type							\ atomic_fetch_and_##short_type(atomic_##short_type##_t *a,		\     type val, atomic_memory_order_t mo) {				\ 	return atomic_fetch_and_explicit(a, val, mo);			\ }									\ ATOMIC_INLINE type							\ atomic_fetch_or_##short_type(atomic_##short_type##_t *a,		\     type val, atomic_memory_order_t mo) {				\ 	return atomic_fetch_or_explicit(a, val, mo);			\ }									\ ATOMIC_INLINE type							\ atomic_fetch_xor_##short_type(atomic_##short_type##_t *a,		\     type val, atomic_memory_order_t mo) {				\ 	return atomic_fetch_xor_explicit(a, val, mo);			\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_ATOMIC_C11_H */
end_comment

end_unit

