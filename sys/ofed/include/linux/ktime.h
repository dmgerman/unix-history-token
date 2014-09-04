begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_KTIME_H
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_KTIME_H
end_define

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/jiffies.h>
end_include

begin_comment
comment|/* Get the monotonic time in timespec format: */
end_comment

begin_define
define|#
directive|define
name|ktime_get_ts
value|getnanouptime
end_define

begin_define
define|#
directive|define
name|NSEC_PER_USEC
value|1000L
end_define

begin_define
define|#
directive|define
name|NSEC_PER_SEC
value|1000000000L
end_define

begin_comment
comment|/*  * ktime_t:  *  * On 64-bit CPUs a single 64-bit variable is used to store the hrtimers  * internal representation of time values in scalar nanoseconds. The  * design plays out best on 64-bit CPUs, where most conversions are  * NOPs and most arithmetic ktime_t operations are plain arithmetic  * operations.  *  * On 32-bit CPUs an optimized representation of the timespec structure  * is used to avoid expensive conversions from and to timespecs. The  * endian-aware order of the tv struct members is chosen to allow  * mathematical operations on the tv64 member of the union too, which  * for certain operations produces better code.  *  * For architectures with efficient support for 64/32-bit conversions the  * plain scalar nanosecond based representation can be selected by the  * config switch CONFIG_KTIME_SCALAR.  */
end_comment

begin_union
union|union
name|ktime
block|{
name|s64
name|tv64
decl_stmt|;
if|#
directive|if
name|BITS_PER_LONG
operator|!=
literal|64
operator|&&
operator|!
name|defined
argument_list|(
name|CONFIG_KTIME_SCALAR
argument_list|)
struct|struct
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN
name|s32
name|sec
decl_stmt|,
name|nsec
decl_stmt|;
else|#
directive|else
name|s32
name|nsec
decl_stmt|,
name|sec
decl_stmt|;
endif|#
directive|endif
block|}
name|tv
struct|;
endif|#
directive|endif
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|ktime
name|ktime_t
typedef|;
end_typedef

begin_comment
comment|/* Kill this */
end_comment

begin_define
define|#
directive|define
name|KTIME_MAX
value|((s64)~((u64)1<< 63))
end_define

begin_define
define|#
directive|define
name|KTIME_SEC_MAX
value|(KTIME_MAX / NSEC_PER_SEC)
end_define

begin_comment
comment|/*  * ktime_t definitions when using the 64-bit scalar representation:  */
end_comment

begin_if
if|#
directive|if
operator|(
name|BITS_PER_LONG
operator|==
literal|64
operator|)
operator|||
name|defined
argument_list|(
name|CONFIG_KTIME_SCALAR
argument_list|)
end_if

begin_comment
comment|/**  * ktime_set - Set a ktime_t variable from a seconds/nanoseconds value  * @secs:	seconds to set  * @nsecs:	nanoseconds to set  *  * Return the ktime_t representation of the value  */
end_comment

begin_function
specifier|static
specifier|inline
name|ktime_t
name|ktime_set
parameter_list|(
specifier|const
name|long
name|secs
parameter_list|,
specifier|const
name|unsigned
name|long
name|nsecs
parameter_list|)
block|{
if|#
directive|if
operator|(
name|BITS_PER_LONG
operator|==
literal|64
operator|)
if|if
condition|(
name|unlikely
argument_list|(
name|secs
operator|>=
name|KTIME_SEC_MAX
argument_list|)
condition|)
return|return
operator|(
name|ktime_t
operator|)
block|{
operator|.
name|tv64
operator|=
name|KTIME_MAX
block|}
return|;
endif|#
directive|endif
return|return
operator|(
name|ktime_t
operator|)
block|{
operator|.
name|tv64
operator|=
operator|(
name|s64
operator|)
name|secs
operator|*
name|NSEC_PER_SEC
operator|+
operator|(
name|s64
operator|)
name|nsecs
block|}
return|;
block|}
end_function

begin_comment
comment|/* Subtract two ktime_t variables. rem = lhs -rhs: */
end_comment

begin_define
define|#
directive|define
name|ktime_sub
parameter_list|(
name|lhs
parameter_list|,
name|rhs
parameter_list|)
define|\
value|({ (ktime_t){ .tv64 = (lhs).tv64 - (rhs).tv64 }; })
end_define

begin_comment
comment|/* Add two ktime_t variables. res = lhs + rhs: */
end_comment

begin_define
define|#
directive|define
name|ktime_add
parameter_list|(
name|lhs
parameter_list|,
name|rhs
parameter_list|)
define|\
value|({ (ktime_t){ .tv64 = (lhs).tv64 + (rhs).tv64 }; })
end_define

begin_comment
comment|/*  * Add a ktime_t variable and a scalar nanosecond value.  * res = kt + nsval:  */
end_comment

begin_define
define|#
directive|define
name|ktime_add_ns
parameter_list|(
name|kt
parameter_list|,
name|nsval
parameter_list|)
define|\
value|({ (ktime_t){ .tv64 = (kt).tv64 + (nsval) }; })
end_define

begin_comment
comment|/*  * Subtract a scalar nanosecod from a ktime_t variable  * res = kt - nsval:  */
end_comment

begin_define
define|#
directive|define
name|ktime_sub_ns
parameter_list|(
name|kt
parameter_list|,
name|nsval
parameter_list|)
define|\
value|({ (ktime_t){ .tv64 = (kt).tv64 - (nsval) }; })
end_define

begin_comment
comment|/* convert a timespec to ktime_t format: */
end_comment

begin_function
specifier|static
specifier|inline
name|ktime_t
name|timespec_to_ktime
parameter_list|(
name|struct
name|timespec
name|ts
parameter_list|)
block|{
return|return
name|ktime_set
argument_list|(
name|ts
operator|.
name|tv_sec
argument_list|,
name|ts
operator|.
name|tv_nsec
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* convert a timeval to ktime_t format: */
end_comment

begin_function
specifier|static
specifier|inline
name|ktime_t
name|timeval_to_ktime
parameter_list|(
name|struct
name|timeval
name|tv
parameter_list|)
block|{
return|return
name|ktime_set
argument_list|(
name|tv
operator|.
name|tv_sec
argument_list|,
name|tv
operator|.
name|tv_usec
operator|*
name|NSEC_PER_USEC
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Map the ktime_t to timespec conversion to ns_to_timespec function */
end_comment

begin_define
define|#
directive|define
name|ktime_to_timespec
parameter_list|(
name|kt
parameter_list|)
value|ns_to_timespec((kt).tv64)
end_define

begin_comment
comment|/* Map the ktime_t to timeval conversion to ns_to_timeval function */
end_comment

begin_define
define|#
directive|define
name|ktime_to_timeval
parameter_list|(
name|kt
parameter_list|)
value|ns_to_timeval((kt).tv64)
end_define

begin_comment
comment|/* Convert ktime_t to nanoseconds - NOP in the scalar storage format: */
end_comment

begin_define
define|#
directive|define
name|ktime_to_ns
parameter_list|(
name|kt
parameter_list|)
value|((kt).tv64)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !((BITS_PER_LONG == 64) || defined(CONFIG_KTIME_SCALAR)) */
end_comment

begin_comment
comment|/*  * Helper macros/inlines to get the ktime_t math right in the timespec  * representation. The macros are sometimes ugly - their actual use is  * pretty okay-ish, given the circumstances. We do all this for  * performance reasons. The pure scalar nsec_t based code was nice and  * simple, but created too many 64-bit / 32-bit conversions and divisions.  *  * Be especially aware that negative values are represented in a way  * that the tv.sec field is negative and the tv.nsec field is greater  * or equal to zero but less than nanoseconds per second. This is the  * same representation which is used by timespecs.  *  *   tv.sec< 0 and 0>= tv.nsec< NSEC_PER_SEC  */
end_comment

begin_comment
comment|/* Set a ktime_t variable to a value in sec/nsec representation: */
end_comment

begin_function
specifier|static
specifier|inline
name|ktime_t
name|ktime_set
parameter_list|(
specifier|const
name|long
name|secs
parameter_list|,
specifier|const
name|unsigned
name|long
name|nsecs
parameter_list|)
block|{
return|return
operator|(
name|ktime_t
operator|)
block|{
operator|.
name|tv
operator|=
block|{
operator|.
name|sec
operator|=
name|secs
block|,
operator|.
name|nsec
operator|=
name|nsecs
block|}
block|}
return|;
block|}
end_function

begin_comment
comment|/**  * ktime_sub - subtract two ktime_t variables  * @lhs:	minuend  * @rhs:	subtrahend  *  * Returns the remainder of the subtraction  */
end_comment

begin_function
specifier|static
specifier|inline
name|ktime_t
name|ktime_sub
parameter_list|(
specifier|const
name|ktime_t
name|lhs
parameter_list|,
specifier|const
name|ktime_t
name|rhs
parameter_list|)
block|{
name|ktime_t
name|res
decl_stmt|;
name|res
operator|.
name|tv64
operator|=
name|lhs
operator|.
name|tv64
operator|-
name|rhs
operator|.
name|tv64
expr_stmt|;
if|if
condition|(
name|res
operator|.
name|tv
operator|.
name|nsec
operator|<
literal|0
condition|)
name|res
operator|.
name|tv
operator|.
name|nsec
operator|+=
name|NSEC_PER_SEC
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/**  * ktime_add - add two ktime_t variables  * @add1:	addend1  * @add2:	addend2  *  * Returns the sum of @add1 and @add2.  */
end_comment

begin_function
specifier|static
specifier|inline
name|ktime_t
name|ktime_add
parameter_list|(
specifier|const
name|ktime_t
name|add1
parameter_list|,
specifier|const
name|ktime_t
name|add2
parameter_list|)
block|{
name|ktime_t
name|res
decl_stmt|;
name|res
operator|.
name|tv64
operator|=
name|add1
operator|.
name|tv64
operator|+
name|add2
operator|.
name|tv64
expr_stmt|;
comment|/* 	 * performance trick: the (u32) -NSEC gives 0x00000000Fxxxxxxx 	 * so we subtract NSEC_PER_SEC and add 1 to the upper 32 bit. 	 * 	 * it's equivalent to: 	 *   tv.nsec -= NSEC_PER_SEC 	 *   tv.sec ++; 	 */
if|if
condition|(
name|res
operator|.
name|tv
operator|.
name|nsec
operator|>=
name|NSEC_PER_SEC
condition|)
name|res
operator|.
name|tv64
operator|+=
operator|(
name|u32
operator|)
operator|-
name|NSEC_PER_SEC
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|/**  * ktime_add_ns - Add a scalar nanoseconds value to a ktime_t variable  * @kt:		addend  * @nsec:	the scalar nsec value to add  *  * Returns the sum of @kt and @nsec in ktime_t format  */
end_comment

begin_function_decl
specifier|extern
name|ktime_t
name|ktime_add_ns
parameter_list|(
specifier|const
name|ktime_t
name|kt
parameter_list|,
name|u64
name|nsec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ktime_sub_ns - Subtract a scalar nanoseconds value from a ktime_t variable  * @kt:		minuend  * @nsec:	the scalar nsec value to subtract  *  * Returns the subtraction of @nsec from @kt in ktime_t format  */
end_comment

begin_function_decl
specifier|extern
name|ktime_t
name|ktime_sub_ns
parameter_list|(
specifier|const
name|ktime_t
name|kt
parameter_list|,
name|u64
name|nsec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * timespec_to_ktime - convert a timespec to ktime_t format  * @ts:		the timespec variable to convert  *  * Returns a ktime_t variable with the converted timespec value  */
end_comment

begin_function
specifier|static
specifier|inline
name|ktime_t
name|timespec_to_ktime
parameter_list|(
specifier|const
name|struct
name|timespec
name|ts
parameter_list|)
block|{
return|return
operator|(
name|ktime_t
operator|)
block|{
operator|.
name|tv
operator|=
block|{
operator|.
name|sec
operator|=
operator|(
name|s32
operator|)
name|ts
operator|.
name|tv_sec
block|,
operator|.
name|nsec
operator|=
operator|(
name|s32
operator|)
name|ts
operator|.
name|tv_nsec
block|}
block|}
return|;
block|}
end_function

begin_comment
comment|/**  * timeval_to_ktime - convert a timeval to ktime_t format  * @tv:		the timeval variable to convert  *  * Returns a ktime_t variable with the converted timeval value  */
end_comment

begin_function
specifier|static
specifier|inline
name|ktime_t
name|timeval_to_ktime
parameter_list|(
specifier|const
name|struct
name|timeval
name|tv
parameter_list|)
block|{
return|return
operator|(
name|ktime_t
operator|)
block|{
operator|.
name|tv
operator|=
block|{
operator|.
name|sec
operator|=
operator|(
name|s32
operator|)
name|tv
operator|.
name|tv_sec
block|,
operator|.
name|nsec
operator|=
operator|(
name|s32
operator|)
operator|(
name|tv
operator|.
name|tv_usec
operator|*
name|NSEC_PER_USEC
operator|)
block|}
block|}
return|;
block|}
end_function

begin_comment
comment|/**  * ktime_to_timespec - convert a ktime_t variable to timespec format  * @kt:		the ktime_t variable to convert  *  * Returns the timespec representation of the ktime value  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|timespec
name|ktime_to_timespec
parameter_list|(
specifier|const
name|ktime_t
name|kt
parameter_list|)
block|{
return|return
operator|(
expr|struct
name|timespec
operator|)
block|{
operator|.
name|tv_sec
operator|=
operator|(
name|time_t
operator|)
name|kt
operator|.
name|tv
operator|.
name|sec
block|,
operator|.
name|tv_nsec
operator|=
operator|(
name|long
operator|)
name|kt
operator|.
name|tv
operator|.
name|nsec
block|}
return|;
block|}
end_function

begin_comment
comment|/**  * ktime_to_timeval - convert a ktime_t variable to timeval format  * @kt:		the ktime_t variable to convert  *  * Returns the timeval representation of the ktime value  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|timeval
name|ktime_to_timeval
parameter_list|(
specifier|const
name|ktime_t
name|kt
parameter_list|)
block|{
return|return
operator|(
expr|struct
name|timeval
operator|)
block|{
operator|.
name|tv_sec
operator|=
operator|(
name|time_t
operator|)
name|kt
operator|.
name|tv
operator|.
name|sec
block|,
operator|.
name|tv_usec
operator|=
operator|(
name|suseconds_t
operator|)
operator|(
name|kt
operator|.
name|tv
operator|.
name|nsec
operator|/
name|NSEC_PER_USEC
operator|)
block|}
return|;
block|}
end_function

begin_comment
comment|/**  * ktime_to_ns - convert a ktime_t variable to scalar nanoseconds  * @kt:		the ktime_t variable to convert  *  * Returns the scalar nanoseconds representation of @kt  */
end_comment

begin_function
specifier|static
specifier|inline
name|s64
name|ktime_to_ns
parameter_list|(
specifier|const
name|ktime_t
name|kt
parameter_list|)
block|{
return|return
operator|(
name|s64
operator|)
name|kt
operator|.
name|tv
operator|.
name|sec
operator|*
name|NSEC_PER_SEC
operator|+
name|kt
operator|.
name|tv
operator|.
name|nsec
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !((BITS_PER_LONG == 64) || defined(CONFIG_KTIME_SCALAR)) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_KTIME_H */
end_comment

end_unit

