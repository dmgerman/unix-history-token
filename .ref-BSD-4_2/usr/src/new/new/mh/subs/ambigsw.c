begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|ambigsw
argument_list|(
argument|arg
argument_list|,
argument|swp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|invo_name
argument_list|()
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"-%s ambiguous.  It matches \n"
argument_list|,
name|arg
argument_list|)
expr_stmt|;
name|printsw
argument_list|(
name|arg
argument_list|,
name|swp
argument_list|,
literal|"-"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

