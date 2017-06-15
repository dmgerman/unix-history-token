begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_ATOMIC_GCC_ATOMIC_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_ATOMIC_GCC_ATOMIC_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/assert.h"
end_include

begin_define
define|#
directive|define
name|ATOMIC_INIT
parameter_list|(
modifier|...
parameter_list|)
value|{__VA_ARGS__}
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|atomic_memory_order_relaxed
block|,
name|atomic_memory_order_acquire
block|,
name|atomic_memory_order_release
block|,
name|atomic_memory_order_acq_rel
block|,
name|atomic_memory_order_seq_cst
block|}
name|atomic_memory_order_t
typedef|;
end_typedef

begin_function
name|ATOMIC_INLINE
name|int
name|atomic_enum_to_builtin
parameter_list|(
name|atomic_memory_order_t
name|mo
parameter_list|)
block|{
switch|switch
condition|(
name|mo
condition|)
block|{
case|case
name|atomic_memory_order_relaxed
case|:
return|return
name|__ATOMIC_RELAXED
return|;
case|case
name|atomic_memory_order_acquire
case|:
return|return
name|__ATOMIC_ACQUIRE
return|;
case|case
name|atomic_memory_order_release
case|:
return|return
name|__ATOMIC_RELEASE
return|;
case|case
name|atomic_memory_order_acq_rel
case|:
return|return
name|__ATOMIC_ACQ_REL
return|;
case|case
name|atomic_memory_order_seq_cst
case|:
return|return
name|__ATOMIC_SEQ_CST
return|;
block|}
comment|/* Can't happen; the switch is exhaustive. */
name|not_reached
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|ATOMIC_INLINE
name|void
name|atomic_fence
parameter_list|(
name|atomic_memory_order_t
name|mo
parameter_list|)
block|{
name|__atomic_thread_fence
argument_list|(
name|atomic_enum_to_builtin
argument_list|(
name|mo
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

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
value|typedef struct {							\ 	type repr;							\ } atomic_##short_type##_t;						\ 									\ ATOMIC_INLINE type							\ atomic_load_##short_type(const atomic_##short_type##_t *a,		\     atomic_memory_order_t mo) {						\ 	type result;							\ 	__atomic_load(&a->repr,&result, atomic_enum_to_builtin(mo));	\ 	return result;							\ }									\ 									\ ATOMIC_INLINE void							\ atomic_store_##short_type(atomic_##short_type##_t *a, type val,		\     atomic_memory_order_t mo) {						\ 	__atomic_store(&a->repr,&val, atomic_enum_to_builtin(mo));	\ }									\ 									\ ATOMIC_INLINE type							\ atomic_exchange_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	type result;							\ 	__atomic_exchange(&a->repr,&val,&result,			\ 	    atomic_enum_to_builtin(mo));				\ 	return result;							\ }									\ 									\ ATOMIC_INLINE bool							\ atomic_compare_exchange_weak_##short_type(atomic_##short_type##_t *a,	\     type *expected, type desired, atomic_memory_order_t success_mo,	\     atomic_memory_order_t failure_mo) {					\ 	return __atomic_compare_exchange(&a->repr, expected,&desired,	\ 	    true, atomic_enum_to_builtin(success_mo),			\ 	    atomic_enum_to_builtin(failure_mo));			\ }									\ 									\ ATOMIC_INLINE bool							\ atomic_compare_exchange_strong_##short_type(atomic_##short_type##_t *a,	\     type *expected, type desired, atomic_memory_order_t success_mo,	\     atomic_memory_order_t failure_mo) {					\ 	return __atomic_compare_exchange(&a->repr, expected,&desired,	\ 	    false,							\ 	    atomic_enum_to_builtin(success_mo),				\ 	    atomic_enum_to_builtin(failure_mo));			\ }
end_define

begin_define
define|#
directive|define
name|JEMALLOC_GENERATE_INT_ATOMICS
parameter_list|(
name|type
parameter_list|,
name|short_type
parameter_list|,			\
comment|/* unused */
name|lg_size
parameter_list|)
define|\
value|JEMALLOC_GENERATE_ATOMICS(type, short_type,
comment|/* unused */
value|lg_size)	\ 									\ ATOMIC_INLINE type							\ atomic_fetch_add_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	return __atomic_fetch_add(&a->repr, val,			\ 	    atomic_enum_to_builtin(mo));				\ }									\ 									\ ATOMIC_INLINE type							\ atomic_fetch_sub_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	return __atomic_fetch_sub(&a->repr, val,			\ 	    atomic_enum_to_builtin(mo));				\ }									\ 									\ ATOMIC_INLINE type							\ atomic_fetch_and_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	return __atomic_fetch_and(&a->repr, val,			\ 	    atomic_enum_to_builtin(mo));				\ }									\ 									\ ATOMIC_INLINE type							\ atomic_fetch_or_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	return __atomic_fetch_or(&a->repr, val,				\ 	    atomic_enum_to_builtin(mo));				\ }									\ 									\ ATOMIC_INLINE type							\ atomic_fetch_xor_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	return __atomic_fetch_xor(&a->repr, val,			\ 	    atomic_enum_to_builtin(mo));				\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_ATOMIC_GCC_ATOMIC_H */
end_comment

end_unit

