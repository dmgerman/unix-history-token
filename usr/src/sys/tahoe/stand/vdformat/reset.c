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
literal|"@(#)reset.c	1.1 (Berkeley/CCI) 7/5/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"vdfmt.h"
end_include

begin_comment
comment|/* ** */
end_comment

begin_macro
name|reset
argument_list|()
end_macro

begin_block
block|{
name|indent
argument_list|()
expr_stmt|;
if|if
condition|(
name|get_yes_no
argument_list|(
literal|"Confirm delete all operations and reset variables"
argument_list|)
condition|)
block|{
name|print
argument_list|(
literal|"All operations specified have been deleted.\n"
argument_list|)
expr_stmt|;
name|exdent
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|_longjmp
argument_list|(
name|reset_environ
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|exdent
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

