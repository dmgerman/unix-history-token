begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ncurses.h>
end_include

begin_include
include|#
directive|include
file|<dialog.h>
end_include

begin_include
include|#
directive|include
file|<forms.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|form
modifier|*
name|form
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"Testing forms code\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|init_forms
argument_list|(
literal|"example.frm"
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|edit_form
argument_list|(
name|form
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

