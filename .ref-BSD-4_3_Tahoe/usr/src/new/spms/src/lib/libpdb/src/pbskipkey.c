begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbskipkey() advances the buffer pointer bp to the next key field.  */
end_comment

begin_include
include|#
directive|include
file|"pdbuf.h"
end_include

begin_function
name|char
modifier|*
name|pbskipkey
parameter_list|(
name|bp
parameter_list|)
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
comment|/* buffer pointer */
block|{
while|while
condition|(
operator|*
name|bp
operator|!=
name|_PBKS
operator|&&
operator|*
name|bp
operator|!=
name|_PBFS
operator|&&
operator|*
name|bp
operator|!=
literal|'\0'
condition|)
name|bp
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|bp
operator|==
name|_PBKS
condition|)
name|bp
operator|++
expr_stmt|;
return|return
operator|(
name|bp
operator|)
return|;
block|}
end_function

end_unit

