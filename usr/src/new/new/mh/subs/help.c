begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"mh.h"
end_include

begin_macro
name|help
argument_list|(
argument|str
argument_list|,
argument|swp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"syntax: %s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  switches are:\n"
argument_list|)
expr_stmt|;
name|printsw
argument_list|(
name|ALL
argument_list|,
name|swp
argument_list|,
literal|"-"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

