begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pgetent() loads next database entry into buffer pdbp->pbuf. Also resets  * buffer pointers and makes pdbp the current working database CURPDB.  * Returns length of entry or EOF.  */
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

begin_decl_stmt
name|char
modifier|*
name|CURPBUF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current database buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|FP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next non-key field */
end_comment

begin_decl_stmt
name|char
modifier|*
name|KP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next key field */
end_comment

begin_decl_stmt
name|PDB
modifier|*
name|CURPDB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current database stream */
end_comment

begin_expr_stmt
name|pgetent
argument_list|(
name|pdbp
argument_list|)
specifier|register
name|PDB
operator|*
name|pdbp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* database stream */
end_comment

begin_block
block|{
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
comment|/* buffer pointer */
specifier|register
name|int
name|c
decl_stmt|;
comment|/* next character */
if|if
condition|(
operator|(
name|pdbp
operator|->
name|flag
operator|&
name|_PREAD
operator|)
operator|==
literal|0
operator|||
operator|(
name|pdbp
operator|->
name|flag
operator|&
operator|(
name|_PEOF
operator||
name|_PERR
operator|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|EOF
operator|)
return|;
name|CURPDB
operator|=
name|pdbp
expr_stmt|;
name|CURPBUF
operator|=
name|FP
operator|=
name|KP
operator|=
name|bp
operator|=
name|pdbp
operator|->
name|pbuf
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|pdbp
operator|->
name|fp
argument_list|)
operator|)
operator|!=
name|EOF
operator|&&
name|c
operator|!=
literal|'\n'
condition|)
operator|*
name|bp
operator|++
operator|=
name|c
expr_stmt|;
operator|*
name|bp
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|c
operator|==
name|EOF
condition|)
block|{
name|pdbp
operator|->
name|flag
operator||=
name|_PEOF
expr_stmt|;
return|return
operator|(
name|EOF
operator|)
return|;
block|}
else|else
return|return
operator|(
name|bp
operator|-
name|pdbp
operator|->
name|pbuf
operator|)
return|;
block|}
end_block

end_unit

