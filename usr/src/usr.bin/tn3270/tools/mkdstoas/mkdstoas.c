begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(unix) */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(unix) */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"../ascii/ascebc.h"
end_include

begin_include
include|#
directive|include
file|"../ctlr/ebc_disp.h"
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|/* For each display code, find the ascii code that matches */
name|printf
argument_list|(
literal|"unsigned char disp_asc[256] = {"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
name|disp_ebc
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
literal|8
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\t0x%2x,"
argument_list|,
name|ebcasc
index|[
literal|0
index|]
index|[
name|disp_ebc
index|[
name|i
index|]
index|]
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
sizeof|sizeof
name|disp_ebc
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|i
operator|%
literal|8
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\t0x%2x,"
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n};\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

