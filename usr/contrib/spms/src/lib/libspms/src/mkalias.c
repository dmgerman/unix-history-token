begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * mkalias() constructs a project directory alias from a pathname.  */
end_comment

begin_include
include|#
directive|include
file|"path.h"
end_include

begin_function
name|char
modifier|*
name|mkalias
parameter_list|(
name|pathname
parameter_list|)
name|char
modifier|*
name|pathname
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|ls
decl_stmt|;
comment|/* last separator character */
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
comment|/* pathname pointer */
for|for
control|(
name|ls
operator|=
name|p
operator|=
name|pathname
init|;
operator|*
name|p
operator|!=
literal|'\0'
condition|;
name|p
operator|++
control|)
if|if
condition|(
operator|(
operator|*
name|p
operator|==
name|_PSC
operator|||
operator|*
name|p
operator|==
name|_PPSC
operator|)
operator|&&
name|p
index|[
literal|1
index|]
operator|!=
literal|'\0'
condition|)
name|ls
operator|=
name|p
operator|+
literal|1
expr_stmt|;
return|return
operator|(
name|ls
operator|)
return|;
block|}
end_function

end_unit

