begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbfndflag() searchs for flag in buffer and returns integer YES if found,  * otherwise NO.  */
end_comment

begin_include
include|#
directive|include
file|"pdbuf.h"
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

begin_expr_stmt
name|pbfndflag
argument_list|(
name|flag
argument_list|)
specifier|register
name|char
operator|*
name|flag
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flag string */
end_comment

begin_block
block|{
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
comment|/* buffer pointer */
name|char
modifier|*
name|pbskipfield
parameter_list|()
function_decl|;
comment|/* skip to next non-key field */
name|bp
operator|=
name|CURPBUF
expr_stmt|;
while|while
condition|(
operator|*
operator|(
name|bp
operator|=
name|pbskipfield
argument_list|(
name|bp
argument_list|)
operator|)
operator|!=
literal|'\0'
condition|)
if|if
condition|(
name|bp
index|[
literal|0
index|]
operator|==
name|flag
index|[
literal|0
index|]
operator|&&
name|bp
index|[
literal|1
index|]
operator|==
name|flag
index|[
literal|1
index|]
operator|&&
operator|(
name|bp
index|[
literal|2
index|]
operator|==
name|_PBFS
operator|||
name|bp
index|[
literal|2
index|]
operator|==
literal|'\0'
operator|)
condition|)
return|return
operator|(
name|YES
operator|)
return|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
end_block

end_unit

