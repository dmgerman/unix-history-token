begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * yes() returns 1 if the user replies with a word starting with `y',  * otherwise zero. yes() eats up the rest of the line.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|yes
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|c
decl_stmt|;
comment|/* current character */
name|int
name|status
init|=
literal|0
decl_stmt|;
comment|/* return status */
while|while
condition|(
operator|(
name|c
operator|=
name|getchar
argument_list|()
operator|)
operator|==
literal|' '
operator|||
name|c
operator|==
literal|'\t'
condition|)
continue|continue;
if|if
condition|(
name|c
operator|==
literal|'y'
condition|)
name|status
operator|=
literal|1
expr_stmt|;
while|while
condition|(
name|c
operator|!=
literal|'\n'
condition|)
name|c
operator|=
name|getchar
argument_list|()
expr_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
end_block

end_unit

