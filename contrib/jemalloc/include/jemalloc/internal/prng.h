begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_comment
comment|/*  * Simple linear congruential pseudo-random number generator:  *  *   prng(y) = (a*x + c) % m  *  * where the following constants ensure maximal period:  *  *   a == Odd number (relatively prime to 2^n), and (a-1) is a multiple of 4.  *   c == Odd number (relatively prime to 2^n).  *   m == 2^32  *  * See Knuth's TAOCP 3rd Ed., Vol. 2, pg. 17 for details on these constraints.  *  * This choice of m has the disadvantage that the quality of the bits is  * proportional to bit position.  For example, the lowest bit has a cycle of 2,  * the next has a cycle of 4, etc.  For this reason, we prefer to use the upper  * bits.  */
end_comment

begin_define
define|#
directive|define
name|PRNG_A
value|UINT64_C(6364136223846793005)
end_define

begin_define
define|#
directive|define
name|PRNG_C
value|UINT64_C(1442695040888963407)
end_define

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

begin_function_decl
name|uint64_t
name|prng_lg_range
parameter_list|(
name|uint64_t
modifier|*
name|state
parameter_list|,
name|unsigned
name|lg_range
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|prng_range
parameter_list|(
name|uint64_t
modifier|*
name|state
parameter_list|,
name|uint64_t
name|range
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
name|JEMALLOC_PRNG_C_
argument_list|)
operator|)
end_if

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|uint64_t
name|prng_lg_range
parameter_list|(
name|uint64_t
modifier|*
name|state
parameter_list|,
name|unsigned
name|lg_range
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
name|assert
argument_list|(
name|lg_range
operator|>
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|lg_range
operator|<=
literal|64
argument_list|)
expr_stmt|;
name|ret
operator|=
operator|(
operator|*
name|state
operator|*
name|PRNG_A
operator|)
operator|+
name|PRNG_C
expr_stmt|;
operator|*
name|state
operator|=
name|ret
expr_stmt|;
name|ret
operator|>>=
operator|(
literal|64
operator|-
name|lg_range
operator|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|uint64_t
name|prng_range
parameter_list|(
name|uint64_t
modifier|*
name|state
parameter_list|,
name|uint64_t
name|range
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
name|unsigned
name|lg_range
decl_stmt|;
name|assert
argument_list|(
name|range
operator|>
literal|1
argument_list|)
expr_stmt|;
comment|/* Compute the ceiling of lg(range). */
name|lg_range
operator|=
name|ffs_u64
argument_list|(
name|pow2_ceil_u64
argument_list|(
name|range
argument_list|)
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* Generate a result in [0..range) via repeated trial. */
do|do
block|{
name|ret
operator|=
name|prng_lg_range
argument_list|(
name|state
argument_list|,
name|lg_range
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|ret
operator|>=
name|range
condition|)
do|;
return|return
operator|(
name|ret
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

