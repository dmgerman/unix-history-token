begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_ATOMIC_GCC_SYNC_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_ATOMIC_GCC_SYNC_H
end_define

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
name|void
name|atomic_fence
parameter_list|(
name|atomic_memory_order_t
name|mo
parameter_list|)
block|{
comment|/* Easy cases first: no barrier, and full barrier. */
if|if
condition|(
name|mo
operator|==
name|atomic_memory_order_relaxed
condition|)
block|{
asm|asm
specifier|volatile
asm|("" ::: "memory");
return|return;
block|}
if|if
condition|(
name|mo
operator|==
name|atomic_memory_order_seq_cst
condition|)
block|{
asm|asm
specifier|volatile
asm|("" ::: "memory");
name|__sync_synchronize
argument_list|()
expr_stmt|;
asm|asm
specifier|volatile
asm|("" ::: "memory");
return|return;
block|}
asm|asm
specifier|volatile
asm|("" ::: "memory");
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
comment|/* This is implicit on x86. */
elif|#
directive|elif
name|defined
argument_list|(
name|__ppc__
argument_list|)
asm|asm
specifier|volatile
asm|("lwsync");
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__arch64__
argument_list|)
if|if
condition|(
name|mo
operator|==
name|atomic_memory_order_acquire
condition|)
block|{
asm|asm
specifier|volatile
asm|("membar #LoadLoad | #LoadStore");
block|}
elseif|else
if|if
condition|(
name|mo
operator|==
name|atomic_memory_order_release
condition|)
block|{
asm|asm
specifier|volatile
asm|("membar #LoadStore | #StoreStore");
block|}
else|else
block|{
asm|asm
specifier|volatile
asm|("membar #LoadLoad | #LoadStore | #StoreStore");
block|}
else|#
directive|else
name|__sync_synchronize
argument_list|()
expr_stmt|;
endif|#
directive|endif
asm|asm
specifier|volatile
asm|("" ::: "memory");
block|}
end_function

begin_comment
comment|/*  * A correct implementation of seq_cst loads and stores on weakly ordered  * architectures could do either of the following:  *   1. store() is weak-fence -> store -> strong fence, load() is load ->  *      strong-fence.  *   2. store() is strong-fence -> store, load() is strong-fence -> load ->  *      weak-fence.  * The tricky thing is, load() and store() above can be the load or store  * portions of a gcc __sync builtin, so we have to follow GCC's lead, which  * means going with strategy 2.  * On strongly ordered architectures, the natural strategy is to stick a strong  * fence after seq_cst stores, and have naked loads.  So we want the strong  * fences in different places on different architectures.  * atomic_pre_sc_load_fence and atomic_post_sc_store_fence allow us to  * accomplish this.  */
end_comment

begin_function
name|ATOMIC_INLINE
name|void
name|atomic_pre_sc_load_fence
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|)
name|atomic_fence
argument_list|(
name|atomic_memory_order_relaxed
argument_list|)
expr_stmt|;
else|#
directive|else
name|atomic_fence
argument_list|(
name|atomic_memory_order_seq_cst
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|ATOMIC_INLINE
name|void
name|atomic_post_sc_store_fence
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|)
name|atomic_fence
argument_list|(
name|atomic_memory_order_seq_cst
argument_list|)
expr_stmt|;
else|#
directive|else
name|atomic_fence
argument_list|(
name|atomic_memory_order_relaxed
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
value|typedef struct {							\ 	type volatile repr;						\ } atomic_##short_type##_t;						\ 									\ ATOMIC_INLINE type							\ atomic_load_##short_type(const atomic_##short_type##_t *a,		\     atomic_memory_order_t mo) {						\ 	if (mo == atomic_memory_order_seq_cst) {			\ 		atomic_pre_sc_load_fence();				\ 	}								\ 	type result = a->repr;						\ 	if (mo != atomic_memory_order_relaxed) {			\ 		atomic_fence(atomic_memory_order_acquire);		\ 	}								\ 	return result;							\ }									\ 									\ ATOMIC_INLINE void							\ atomic_store_##short_type(atomic_##short_type##_t *a,			\     type val, atomic_memory_order_t mo) {				\ 	if (mo != atomic_memory_order_relaxed) {			\ 		atomic_fence(atomic_memory_order_release);		\ 	}								\ 	a->repr = val;							\ 	if (mo == atomic_memory_order_seq_cst) {			\ 		atomic_post_sc_store_fence();				\ 	}								\ }									\ 									\ ATOMIC_INLINE type							\ atomic_exchange_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\
comment|/*								\ 	 * Because of FreeBSD, we care about gcc 4.2, which doesn't have\ 	 * an atomic exchange builtin.  We fake it with a CAS loop.	\ 	 */
value|\ 	while (true) {							\ 		type old = a->repr;					\ 		if (__sync_bool_compare_and_swap(&a->repr, old, val)) {	\ 			return old;					\ 		}							\ 	}								\ }									\ 									\ ATOMIC_INLINE bool							\ atomic_compare_exchange_weak_##short_type(atomic_##short_type##_t *a,	\     type *expected, type desired, atomic_memory_order_t success_mo,	\     atomic_memory_order_t failure_mo) {					\ 	type prev = __sync_val_compare_and_swap(&a->repr, *expected,	\ 	    desired);							\ 	if (prev == *expected) {					\ 		return true;						\ 	} else {							\ 		*expected = prev;					\ 		return false;						\ 	}								\ }									\ ATOMIC_INLINE bool							\ atomic_compare_exchange_strong_##short_type(atomic_##short_type##_t *a,	\     type *expected, type desired, atomic_memory_order_t success_mo,	\     atomic_memory_order_t failure_mo) {					\ 	type prev = __sync_val_compare_and_swap(&a->repr, *expected,	\ 	    desired);							\ 	if (prev == *expected) {					\ 		return true;						\ 	} else {							\ 		*expected = prev;					\ 		return false;						\ 	}								\ }
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
value|lg_size)	\ 									\ ATOMIC_INLINE type							\ atomic_fetch_add_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	return __sync_fetch_and_add(&a->repr, val);			\ }									\ 									\ ATOMIC_INLINE type							\ atomic_fetch_sub_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	return __sync_fetch_and_sub(&a->repr, val);			\ }									\ 									\ ATOMIC_INLINE type							\ atomic_fetch_and_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	return __sync_fetch_and_and(&a->repr, val);			\ }									\ 									\ ATOMIC_INLINE type							\ atomic_fetch_or_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	return __sync_fetch_and_or(&a->repr, val);			\ }									\ 									\ ATOMIC_INLINE type							\ atomic_fetch_xor_##short_type(atomic_##short_type##_t *a, type val,	\     atomic_memory_order_t mo) {						\ 	return __sync_fetch_and_xor(&a->repr, val);			\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_ATOMIC_GCC_SYNC_H */
end_comment

end_unit

