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
comment|/*  * Simple linear congruential pseudo-random number generator:  *  *   prng(y) = (a*x + c) % m  *  * where the following constants ensure maximal period:  *  *   a == Odd number (relatively prime to 2^n), and (a-1) is a multiple of 4.  *   c == Odd number (relatively prime to 2^n).  *   m == 2^32  *  * See Knuth's TAOCP 3rd Ed., Vol. 2, pg. 17 for details on these constraints.  *  * This choice of m has the disadvantage that the quality of the bits is  * proportional to bit position.  For example. the lowest bit has a cycle of 2,  * the next has a cycle of 4, etc.  For this reason, we prefer to use the upper  * bits.  *  * Macro parameters:  *   uint32_t r          : Result.  *   unsigned lg_range   : (0..32], number of least significant bits to return.  *   uint32_t state      : Seed value.  *   const uint32_t a, c : See above discussion.  */
end_comment

begin_define
define|#
directive|define
name|prng32
parameter_list|(
name|r
parameter_list|,
name|lg_range
parameter_list|,
name|state
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
value|do {				\ 	assert(lg_range> 0);						\ 	assert(lg_range<= 32);						\ 									\ 	r = (state * (a)) + (c);					\ 	state = r;							\ 	r>>= (32 - lg_range);						\ } while (false)
end_define

begin_comment
comment|/* Same as prng32(), but 64 bits of pseudo-randomness, using uint64_t. */
end_comment

begin_define
define|#
directive|define
name|prng64
parameter_list|(
name|r
parameter_list|,
name|lg_range
parameter_list|,
name|state
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
value|do {				\ 	assert(lg_range> 0);						\ 	assert(lg_range<= 64);						\ 									\ 	r = (state * (a)) + (c);					\ 	state = r;							\ 	r>>= (64 - lg_range);						\ } while (false)
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

