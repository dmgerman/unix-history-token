begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /mit/kerberos/src/lib/des/RCS/make_p.c,v $  * $Author: jtkohl $  *  * Copyright 1985, 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please  * see the file<mit-copyright.h>.  *  * This routine generates the P permutation code for the DES.  */
end_comment

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"des_internal.h"
end_include

begin_include
include|#
directive|include
file|"tables.h"
end_include

begin_function
name|void
name|gen
parameter_list|(
name|stream
parameter_list|)
name|FILE
modifier|*
name|stream
decl_stmt|;
block|{
comment|/* P permutes 32 bit input R1 into 32 bit output R2 */
comment|/* clear the output */
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    L2 = 0;\n"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|BIG
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    R2 = 0;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"/* P operations */\n/* from right to right */\n"
argument_list|)
expr_stmt|;
comment|/* first list mapping from left to left */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
literal|31
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|P
index|[
name|i
index|]
operator|<
literal|32
condition|)
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    if (R1& (1<<%d)) R2 |= 1<<%d;\n"
argument_list|,
name|P
index|[
name|i
index|]
argument_list|,
name|i
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* BIG */
comment|/* flip p into p_temp */
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    P_temp = R1;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    P_temp_p = (unsigned char *)&P_temp;\n"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|LSBFIRST
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    R2 = P_prime[0][*P_temp_p++];\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    R2 |= P_prime[1][*P_temp_p++];\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    R2 |= P_prime[2][*P_temp_p++];\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    R2 |= P_prime[3][*P_temp_p];\n"
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* MSBFIRST */
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    R2 = P_prime[3][*P_temp_p++];\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    R2 |= P_prime[2][*P_temp_p++];\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    R2 |= P_prime[1][*P_temp_p++];\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stream
argument_list|,
literal|"    R2 |= P_prime[0][*P_temp_p];\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MSBFIRST */
endif|#
directive|endif
comment|/* BIG */
block|}
end_function

end_unit

