begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbstretch() stretches the buffer by n characters just before the point  * marked by buffer pointer bp. Negative n shrinks the buffer by n  * characters. Returns integer NO if buffer space exceeded, otherwise YES.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"path.h"
end_include

begin_include
include|#
directive|include
file|"pdb.h"
end_include

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CURPBUF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current database buffer */
end_comment

begin_decl_stmt
specifier|extern
name|PDB
modifier|*
name|CURPDB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current database stream */
end_comment

begin_expr_stmt
name|pbstretch
argument_list|(
name|bp
argument_list|,
name|n
argument_list|)
specifier|register
name|char
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* buffer pointer */
end_comment

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stretch amount */
end_comment

begin_block
block|{
specifier|register
name|char
modifier|*
name|lowerbp
decl_stmt|;
comment|/* lower roving buffer pointer */
specifier|register
name|char
modifier|*
name|upperbp
decl_stmt|;
comment|/* upper roving buffer pointer */
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
comment|/* print output to string */
if|if
condition|(
name|n
operator|>
literal|0
condition|)
block|{
for|for
control|(
name|lowerbp
operator|=
name|bp
init|;
operator|*
name|lowerbp
operator|!=
literal|'\0'
condition|;
name|lowerbp
operator|++
control|)
continue|continue;
name|upperbp
operator|=
name|lowerbp
operator|+
name|n
expr_stmt|;
if|if
condition|(
name|upperbp
operator|>=
name|CURPBUF
operator|+
name|PBUFSIZE
condition|)
block|{
name|sprintf
argument_list|(
name|CURPDB
operator|->
name|perr
argument_list|,
literal|"%s database buffer exceeded"
argument_list|,
name|CURPDB
operator|->
name|path
argument_list|)
expr_stmt|;
name|CURPDB
operator|->
name|flag
operator||=
name|_PERR
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
while|while
condition|(
name|lowerbp
operator|>=
name|bp
condition|)
operator|*
name|upperbp
operator|--
operator|=
operator|*
name|lowerbp
operator|--
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|n
operator|<
literal|0
condition|)
block|{
for|for
control|(
name|upperbp
operator|=
name|bp
init|;
operator|*
name|upperbp
operator|!=
literal|'\0'
condition|;
name|upperbp
operator|++
control|)
continue|continue;
name|lowerbp
operator|=
name|bp
operator|-
name|n
expr_stmt|;
if|if
condition|(
name|lowerbp
operator|>=
name|upperbp
condition|)
operator|*
name|bp
operator|=
literal|'\0'
expr_stmt|;
while|while
condition|(
name|lowerbp
operator|<=
name|upperbp
condition|)
operator|*
name|bp
operator|++
operator|=
operator|*
name|lowerbp
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

end_unit

