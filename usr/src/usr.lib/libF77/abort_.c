begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_macro
name|abort_
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Fortran abort routine called\n"
argument_list|)
expr_stmt|;
name|f_exit
argument_list|()
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_macro
name|abort_
argument_list|(
argument|msg
argument_list|,
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|msg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"abort: "
argument_list|)
expr_stmt|;
if|if
condition|(
name|nargs
argument_list|()
condition|)
while|while
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
name|fputc
argument_list|(
operator|*
name|msg
operator|++
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"called"
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|f_exit
argument_list|()
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

