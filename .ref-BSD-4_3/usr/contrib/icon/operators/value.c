begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * .x - produce value of x by dereferencing it.  */
end_comment

begin_macro
name|value
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
name|DclSave
name|SetBound
decl_stmt|;
name|arg0
operator|=
name|arg1
expr_stmt|;
name|DeRef
argument_list|(
argument|arg0
argument_list|)
name|ClearBound
expr_stmt|;
block|}
end_block

begin_macro
name|Opblock
argument_list|(
argument|value
argument_list|,
literal|1
argument_list|,
literal|"."
argument_list|)
end_macro

end_unit

