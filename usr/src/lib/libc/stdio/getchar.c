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
literal|"@(#)getchar.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * A subroutine version of the macro getchar.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|getchar
end_undef

begin_macro
name|getchar
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|getc
argument_list|(
name|stdin
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

