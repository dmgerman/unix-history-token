begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbaddstring() adds an id=string to the tail of the buffer. If id already  * exists the corresponding string is replaced. Returns integer NO if  * buffer space exceeded, otherwise YES.  */
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
name|pbaddstring
argument_list|(
name|id
argument_list|,
name|string
argument_list|)
specifier|register
name|char
operator|*
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* string identifier */
end_comment

begin_decl_stmt
name|char
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string argument */
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
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
comment|/* string copy */
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
comment|/* copy n characters */
name|int
name|chgflen
decl_stmt|;
comment|/* incremental field length */
name|int
name|flen
decl_stmt|;
comment|/* field length */
name|int
name|pbstretch
parameter_list|()
function_decl|;
comment|/* stretch buffer */
name|int
name|slen
decl_stmt|;
comment|/* string length */
name|int
name|strlen
parameter_list|()
function_decl|;
comment|/* string length */
name|bp
operator|=
name|CURPBUF
expr_stmt|;
name|slen
operator|=
name|strlen
argument_list|(
name|string
argument_list|)
expr_stmt|;
name|chgflen
operator|=
name|slen
operator|+
literal|4
expr_stmt|;
comment|/* add id= and field separator */
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
name|id
index|[
literal|0
index|]
operator|&&
name|bp
index|[
literal|1
index|]
operator|==
name|id
index|[
literal|1
index|]
operator|&&
name|bp
index|[
literal|2
index|]
operator|==
literal|'='
condition|)
block|{
name|flen
operator|=
name|pblenfield
argument_list|(
name|bp
argument_list|)
expr_stmt|;
name|chgflen
operator|-=
operator|(
name|bp
index|[
name|flen
index|]
operator|==
name|_PBFS
operator|)
condition|?
name|flen
operator|+
literal|1
else|:
name|flen
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|bp
operator|==
name|CURPBUF
condition|)
block|{
operator|*
name|bp
operator|++
operator|=
name|_PBFS
expr_stmt|;
comment|/* prepare virgin buffer */
operator|*
name|bp
operator|=
literal|'\0'
expr_stmt|;
block|}
if|if
condition|(
name|pbstretch
argument_list|(
name|bp
argument_list|,
name|chgflen
argument_list|)
operator|==
name|NO
condition|)
return|return
operator|(
name|NO
operator|)
return|;
name|bp
index|[
literal|0
index|]
operator|=
name|id
index|[
literal|0
index|]
expr_stmt|;
comment|/* add id= */
name|bp
index|[
literal|1
index|]
operator|=
name|id
index|[
literal|1
index|]
expr_stmt|;
name|bp
index|[
literal|2
index|]
operator|=
literal|'='
expr_stmt|;
name|strncpy
argument_list|(
name|bp
operator|+
literal|3
argument_list|,
name|string
argument_list|,
name|slen
argument_list|)
expr_stmt|;
comment|/* insert string */
name|bp
index|[
name|slen
operator|+
literal|3
index|]
operator|=
name|_PBFS
expr_stmt|;
comment|/* add field separator */
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

end_unit

