begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- ctzsi2.c - Implement __ctzsi2 -------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __ctzsi2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_comment
comment|/* Returns: the number of trailing 0-bits */
end_comment

begin_comment
comment|/* Precondition: a != 0 */
end_comment

begin_function
name|COMPILER_RT_ABI
name|si_int
name|__ctzsi2
parameter_list|(
name|si_int
name|a
parameter_list|)
block|{
name|su_int
name|x
init|=
operator|(
name|su_int
operator|)
name|a
decl_stmt|;
name|si_int
name|t
init|=
operator|(
operator|(
name|x
operator|&
literal|0x0000FFFF
operator|)
operator|==
literal|0
operator|)
operator|<<
literal|4
decl_stmt|;
comment|/* if (x has no small bits) t = 16 else 0 */
name|x
operator|>>=
name|t
expr_stmt|;
comment|/* x = [0 - 0xFFFF] + higher garbage bits */
name|su_int
name|r
init|=
name|t
decl_stmt|;
comment|/* r = [0, 16]  */
comment|/* return r + ctz(x) */
name|t
operator|=
operator|(
operator|(
name|x
operator|&
literal|0x00FF
operator|)
operator|==
literal|0
operator|)
operator|<<
literal|3
expr_stmt|;
name|x
operator|>>=
name|t
expr_stmt|;
comment|/* x = [0 - 0xFF] + higher garbage bits */
name|r
operator|+=
name|t
expr_stmt|;
comment|/* r = [0, 8, 16, 24] */
comment|/* return r + ctz(x) */
name|t
operator|=
operator|(
operator|(
name|x
operator|&
literal|0x0F
operator|)
operator|==
literal|0
operator|)
operator|<<
literal|2
expr_stmt|;
name|x
operator|>>=
name|t
expr_stmt|;
comment|/* x = [0 - 0xF] + higher garbage bits */
name|r
operator|+=
name|t
expr_stmt|;
comment|/* r = [0, 4, 8, 12, 16, 20, 24, 28] */
comment|/* return r + ctz(x) */
name|t
operator|=
operator|(
operator|(
name|x
operator|&
literal|0x3
operator|)
operator|==
literal|0
operator|)
operator|<<
literal|1
expr_stmt|;
name|x
operator|>>=
name|t
expr_stmt|;
name|x
operator|&=
literal|3
expr_stmt|;
comment|/* x = [0 - 3] */
name|r
operator|+=
name|t
expr_stmt|;
comment|/* r = [0 - 30] and is even */
comment|/* return r + ctz(x) */
comment|/*  The branch-less return statement below is equivalent  *  to the following switch statement:  *     switch (x)  *    {  *     case 0:  *         return r + 2;  *     case 2:  *         return r + 1;  *     case 1:  *     case 3:  *         return r;  *     }  */
return|return
name|r
operator|+
operator|(
operator|(
literal|2
operator|-
operator|(
name|x
operator|>>
literal|1
operator|)
operator|)
operator|&
operator|-
operator|(
operator|(
name|x
operator|&
literal|1
operator|)
operator|==
literal|0
operator|)
operator|)
return|;
block|}
end_function

end_unit

