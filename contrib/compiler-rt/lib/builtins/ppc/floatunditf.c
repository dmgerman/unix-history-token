begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is distributed under the University of Illinois Open Source  * License. See LICENSE.TXT for details.  */
end_comment

begin_comment
comment|/* long double __floatunditf(unsigned long long x); */
end_comment

begin_comment
comment|/* This file implements the PowerPC unsigned long long -> long double conversion */
end_comment

begin_include
include|#
directive|include
file|"DD.h"
end_include

begin_function
name|long
name|double
name|__floatunditf
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|/* Begins with an exact copy of the code from __floatundidf */
specifier|static
specifier|const
name|double
name|twop52
init|=
literal|0x1
literal|.0p52
decl_stmt|;
specifier|static
specifier|const
name|double
name|twop84
init|=
literal|0x1
literal|.0p84
decl_stmt|;
specifier|static
specifier|const
name|double
name|twop84_plus_twop52
init|=
literal|0x1
literal|.00000001p84
decl_stmt|;
name|doublebits
name|high
init|=
block|{
operator|.
name|d
operator|=
name|twop84
block|}
decl_stmt|;
name|doublebits
name|low
init|=
block|{
operator|.
name|d
operator|=
name|twop52
block|}
decl_stmt|;
name|high
operator|.
name|x
operator||=
name|a
operator|>>
literal|32
expr_stmt|;
comment|/* 0x1.0p84 + high 32 bits of a */
name|low
operator|.
name|x
operator||=
name|a
operator|&
name|UINT64_C
argument_list|(
literal|0x00000000ffffffff
argument_list|)
expr_stmt|;
comment|/* 0x1.0p52 + low 32 bits of a */
specifier|const
name|double
name|high_addend
init|=
name|high
operator|.
name|d
operator|-
name|twop84_plus_twop52
decl_stmt|;
comment|/* At this point, we have two double precision numbers 	 * high_addend and low.d, and we wish to return their sum 	 * as a canonicalized long double: 	 */
comment|/* This implementation sets the inexact flag spuriously. */
comment|/* This could be avoided, but at some substantial cost. */
name|DD
name|result
decl_stmt|;
name|result
operator|.
name|s
operator|.
name|hi
operator|=
name|high_addend
operator|+
name|low
operator|.
name|d
expr_stmt|;
name|result
operator|.
name|s
operator|.
name|lo
operator|=
operator|(
name|high_addend
operator|-
name|result
operator|.
name|s
operator|.
name|hi
operator|)
operator|+
name|low
operator|.
name|d
expr_stmt|;
return|return
name|result
operator|.
name|ld
return|;
block|}
end_function

end_unit

