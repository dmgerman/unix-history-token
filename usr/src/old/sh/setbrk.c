begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	setbrk.c	4.1	82/05/07	*/
end_comment

begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	UNIX shell  *  *	S. R. Bourne  *	Bell Telephone Laboratories  *  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_macro
name|setbrk
argument_list|(
argument|incr
argument_list|)
end_macro

begin_block
block|{
name|REG
name|BYTPTR
name|a
init|=
name|sbrk
argument_list|(
name|incr
argument_list|)
decl_stmt|;
name|brkend
operator|=
name|a
operator|+
name|incr
expr_stmt|;
return|return
operator|(
name|a
operator|)
return|;
block|}
end_block

end_unit

