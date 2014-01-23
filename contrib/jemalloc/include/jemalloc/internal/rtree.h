begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This radix tree implementation is tailored to the singular purpose of  * tracking which chunks are currently owned by jemalloc.  This functionality  * is mandatory for OS X, where jemalloc must be able to respond to object  * ownership queries.  *  *******************************************************************************  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|rtree_s
name|rtree_t
typedef|;
end_typedef

begin_comment
comment|/*  * Size of each radix tree node (must be a power of 2).  This impacts tree  * depth.  */
end_comment

begin_define
define|#
directive|define
name|RTREE_NODESIZE
value|(1U<< 16)
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
name|rtree_alloc_t
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|rtree_dalloc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_TYPES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_STRUCTS
end_ifdef

begin_struct
struct|struct
name|rtree_s
block|{
name|rtree_alloc_t
modifier|*
name|alloc
decl_stmt|;
name|rtree_dalloc_t
modifier|*
name|dalloc
decl_stmt|;
name|malloc_mutex_t
name|mutex
decl_stmt|;
name|void
modifier|*
modifier|*
name|root
decl_stmt|;
name|unsigned
name|height
decl_stmt|;
name|unsigned
name|level2bits
index|[
literal|1
index|]
decl_stmt|;
comment|/* Dynamically sized. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_STRUCTS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_EXTERNS
end_ifdef

begin_function_decl
name|rtree_t
modifier|*
name|rtree_new
parameter_list|(
name|unsigned
name|bits
parameter_list|,
name|rtree_alloc_t
modifier|*
name|alloc
parameter_list|,
name|rtree_dalloc_t
modifier|*
name|dalloc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtree_delete
parameter_list|(
name|rtree_t
modifier|*
name|rtree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtree_prefork
parameter_list|(
name|rtree_t
modifier|*
name|rtree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtree_postfork_parent
parameter_list|(
name|rtree_t
modifier|*
name|rtree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtree_postfork_child
parameter_list|(
name|rtree_t
modifier|*
name|rtree
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_EXTERNS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_INLINES
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_ENABLE_INLINE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_DEBUG
end_ifdef

begin_function_decl
name|uint8_t
name|rtree_get_locked
parameter_list|(
name|rtree_t
modifier|*
name|rtree
parameter_list|,
name|uintptr_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|uint8_t
name|rtree_get
parameter_list|(
name|rtree_t
modifier|*
name|rtree
parameter_list|,
name|uintptr_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|rtree_set
parameter_list|(
name|rtree_t
modifier|*
name|rtree
parameter_list|,
name|uintptr_t
name|key
parameter_list|,
name|uint8_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|JEMALLOC_ENABLE_INLINE
argument_list|)
operator|||
name|defined
argument_list|(
name|JEMALLOC_RTREE_C_
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|RTREE_GET_GENERATE
parameter_list|(
name|f
parameter_list|)
define|\
comment|/* The least significant bits of the key are ignored. */
define|\
value|JEMALLOC_INLINE uint8_t							\ f(rtree_t *rtree, uintptr_t key)					\ {									\ 	uint8_t ret;							\ 	uintptr_t subkey;						\ 	unsigned i, lshift, height, bits;				\ 	void **node, **child;						\ 									\ 	RTREE_LOCK(&rtree->mutex);					\ 	for (i = lshift = 0, height = rtree->height, node = rtree->root;\ 	    i< height - 1;						\ 	    i++, lshift += bits, node = child) {			\ 		bits = rtree->level2bits[i];				\ 		subkey = (key<< lshift)>> ((ZU(1)<< (LG_SIZEOF_PTR +	\ 		    3)) - bits);					\ 		child = (void**)node[subkey];				\ 		if (child == NULL) {					\ 			RTREE_UNLOCK(&rtree->mutex);			\ 			return (0);					\ 		}							\ 	}								\ 									\
comment|/*								\ 	 * node is a leaf, so it contains values rather than node	\ 	 * pointers.							\ 	 */
value|\ 	bits = rtree->level2bits[i];					\ 	subkey = (key<< lshift)>> ((ZU(1)<< (LG_SIZEOF_PTR+3)) -	\ 	    bits);							\ 	{								\ 		uint8_t *leaf = (uint8_t *)node;			\ 		ret = leaf[subkey];					\ 	}								\ 	RTREE_UNLOCK(&rtree->mutex);					\ 									\ 	RTREE_GET_VALIDATE						\ 	return (ret);							\ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|RTREE_LOCK
parameter_list|(
name|l
parameter_list|)
value|malloc_mutex_lock(l)
end_define

begin_define
define|#
directive|define
name|RTREE_UNLOCK
parameter_list|(
name|l
parameter_list|)
value|malloc_mutex_unlock(l)
end_define

begin_define
define|#
directive|define
name|RTREE_GET_VALIDATE
end_define

begin_macro
name|RTREE_GET_GENERATE
argument_list|(
argument|rtree_get_locked
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|RTREE_LOCK
end_undef

begin_undef
undef|#
directive|undef
name|RTREE_UNLOCK
end_undef

begin_undef
undef|#
directive|undef
name|RTREE_GET_VALIDATE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RTREE_LOCK
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RTREE_UNLOCK
parameter_list|(
name|l
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_DEBUG
end_ifdef

begin_comment
comment|/*     * Suppose that it were possible for a jemalloc-allocated chunk to be     * munmap()ped, followed by a different allocator in another thread re-using     * overlapping virtual memory, all without invalidating the cached rtree     * value.  The result would be a false positive (the rtree would claim that     * jemalloc owns memory that it had actually discarded).  This scenario     * seems impossible, but the following assertion is a prudent sanity check.     */
end_comment

begin_define
define|#
directive|define
name|RTREE_GET_VALIDATE
define|\
value|assert(rtree_get_locked(rtree, key) == ret);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RTREE_GET_VALIDATE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|RTREE_GET_GENERATE
argument_list|(
argument|rtree_get
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|RTREE_LOCK
end_undef

begin_undef
undef|#
directive|undef
name|RTREE_UNLOCK
end_undef

begin_undef
undef|#
directive|undef
name|RTREE_GET_VALIDATE
end_undef

begin_function
name|JEMALLOC_INLINE
name|bool
name|rtree_set
parameter_list|(
name|rtree_t
modifier|*
name|rtree
parameter_list|,
name|uintptr_t
name|key
parameter_list|,
name|uint8_t
name|val
parameter_list|)
block|{
name|uintptr_t
name|subkey
decl_stmt|;
name|unsigned
name|i
decl_stmt|,
name|lshift
decl_stmt|,
name|height
decl_stmt|,
name|bits
decl_stmt|;
name|void
modifier|*
modifier|*
name|node
decl_stmt|,
modifier|*
modifier|*
name|child
decl_stmt|;
name|malloc_mutex_lock
argument_list|(
operator|&
name|rtree
operator|->
name|mutex
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|lshift
operator|=
literal|0
operator|,
name|height
operator|=
name|rtree
operator|->
name|height
operator|,
name|node
operator|=
name|rtree
operator|->
name|root
init|;
name|i
operator|<
name|height
operator|-
literal|1
condition|;
name|i
operator|++
operator|,
name|lshift
operator|+=
name|bits
operator|,
name|node
operator|=
name|child
control|)
block|{
name|bits
operator|=
name|rtree
operator|->
name|level2bits
index|[
name|i
index|]
expr_stmt|;
name|subkey
operator|=
operator|(
name|key
operator|<<
name|lshift
operator|)
operator|>>
operator|(
operator|(
name|ZU
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|LG_SIZEOF_PTR
operator|+
literal|3
operator|)
operator|)
operator|-
name|bits
operator|)
expr_stmt|;
name|child
operator|=
operator|(
name|void
operator|*
operator|*
operator|)
name|node
index|[
name|subkey
index|]
expr_stmt|;
if|if
condition|(
name|child
operator|==
name|NULL
condition|)
block|{
name|size_t
name|size
init|=
operator|(
operator|(
name|i
operator|+
literal|1
operator|<
name|height
operator|-
literal|1
operator|)
condition|?
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
else|:
operator|(
sizeof|sizeof
argument_list|(
name|uint8_t
argument_list|)
operator|)
operator|)
operator|<<
name|rtree
operator|->
name|level2bits
index|[
name|i
operator|+
literal|1
index|]
decl_stmt|;
name|child
operator|=
operator|(
name|void
operator|*
operator|*
operator|)
name|rtree
operator|->
name|alloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|child
operator|==
name|NULL
condition|)
block|{
name|malloc_mutex_unlock
argument_list|(
operator|&
name|rtree
operator|->
name|mutex
argument_list|)
expr_stmt|;
return|return
operator|(
name|true
operator|)
return|;
block|}
name|memset
argument_list|(
name|child
argument_list|,
literal|0
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|node
index|[
name|subkey
index|]
operator|=
name|child
expr_stmt|;
block|}
block|}
comment|/* node is a leaf, so it contains values rather than node pointers. */
name|bits
operator|=
name|rtree
operator|->
name|level2bits
index|[
name|i
index|]
expr_stmt|;
name|subkey
operator|=
operator|(
name|key
operator|<<
name|lshift
operator|)
operator|>>
operator|(
operator|(
name|ZU
argument_list|(
literal|1
argument_list|)
operator|<<
operator|(
name|LG_SIZEOF_PTR
operator|+
literal|3
operator|)
operator|)
operator|-
name|bits
operator|)
expr_stmt|;
block|{
name|uint8_t
modifier|*
name|leaf
init|=
operator|(
name|uint8_t
operator|*
operator|)
name|node
decl_stmt|;
name|leaf
index|[
name|subkey
index|]
operator|=
name|val
expr_stmt|;
block|}
name|malloc_mutex_unlock
argument_list|(
operator|&
name|rtree
operator|->
name|mutex
argument_list|)
expr_stmt|;
return|return
operator|(
name|false
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_INLINES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

end_unit

