begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)setbrk.c	4.2 8/11/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

