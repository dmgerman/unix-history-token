begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- fixsfti.c - Implement __fixsfti -----------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __fixsfti for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_HAS_128BIT
end_ifdef

begin_comment
comment|/* Returns: convert a to a signed long long, rounding toward zero. */
end_comment

begin_comment
comment|/* Assumption: float is a IEEE 32 bit floating point type   *             su_int is a 32 bit integral type  *             value in float is representable in ti_int (no range checking performed)  */
end_comment

begin_comment
comment|/* seee eeee emmm mmmm mmmm mmmm mmmm mmmm */
end_comment

begin_function
name|ti_int
name|__fixsfti
parameter_list|(
name|float
name|a
parameter_list|)
block|{
name|float_bits
name|fb
decl_stmt|;
name|fb
operator|.
name|f
operator|=
name|a
expr_stmt|;
name|int
name|e
init|=
operator|(
operator|(
name|fb
operator|.
name|u
operator|&
literal|0x7F800000
operator|)
operator|>>
literal|23
operator|)
operator|-
literal|127
decl_stmt|;
if|if
condition|(
name|e
operator|<
literal|0
condition|)
return|return
literal|0
return|;
name|ti_int
name|s
init|=
call|(
name|si_int
call|)
argument_list|(
name|fb
operator|.
name|u
operator|&
literal|0x80000000
argument_list|)
operator|>>
literal|31
decl_stmt|;
name|ti_int
name|r
init|=
operator|(
name|fb
operator|.
name|u
operator|&
literal|0x007FFFFF
operator|)
operator||
literal|0x00800000
decl_stmt|;
if|if
condition|(
name|e
operator|>
literal|23
condition|)
name|r
operator|<<=
operator|(
name|e
operator|-
literal|23
operator|)
expr_stmt|;
else|else
name|r
operator|>>=
operator|(
literal|23
operator|-
name|e
operator|)
expr_stmt|;
return|return
operator|(
name|r
operator|^
name|s
operator|)
operator|-
name|s
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRT_HAS_128BIT */
end_comment

end_unit

