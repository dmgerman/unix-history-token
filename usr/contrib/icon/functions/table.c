begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * table(x) - create a table with default value x.  */
end_comment

begin_macro
name|Xtable
argument_list|(
argument|nargs
argument_list|,
argument|arg1
argument_list|,
argument|arg0
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
decl_stmt|,
name|arg0
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|struct
name|b_table
modifier|*
name|alctable
parameter_list|()
function_decl|;
name|hneed
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|b_table
argument_list|)
argument_list|)
expr_stmt|;
name|DeRef
argument_list|(
argument|arg1
argument_list|)
name|arg0
operator|.
name|type
operator|=
name|D_TABLE
expr_stmt|;
name|BLKLOC
argument_list|(
name|arg0
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
name|alctable
argument_list|(
operator|&
name|arg1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|Procblock
argument_list|(
argument|table
argument_list|,
literal|1
argument_list|)
end_macro

end_unit

