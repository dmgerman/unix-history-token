begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * exit(status) - exit process with specified status, defaults to 0.  */
end_comment

begin_macro
name|Xexit
argument_list|(
argument|nargs
argument_list|,
argument|arg1
argument_list|)
end_macro

begin_decl_stmt
name|int
name|nargs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|arg1
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|defshort
argument_list|(
operator|&
name|arg1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|c_exit
argument_list|(
name|INTVAL
argument_list|(
name|arg1
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|Procblock
argument_list|(
argument|exit
argument_list|,
literal|1
argument_list|)
end_macro

end_unit

