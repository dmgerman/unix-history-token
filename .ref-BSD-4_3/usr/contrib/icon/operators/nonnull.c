begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * \x - test x for non-null value.  */
end_comment

begin_macro
name|nonnull
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
comment|/*     * If x is not null, it is returned, otherwise, the function fails.     *  Because the pre-dereference value of x is the return value (if     *  any), x is copied into arg0.     */
name|arg0
operator|=
name|arg1
expr_stmt|;
name|DeRef
argument_list|(
argument|arg1
argument_list|)
if|if
condition|(
name|NULLDESC
argument_list|(
name|arg1
argument_list|)
condition|)
name|fail
argument_list|()
expr_stmt|;
name|ClearBound
expr_stmt|;
block|}
end_block

begin_macro
name|Opblock
argument_list|(
argument|nonnull
argument_list|,
literal|1
argument_list|,
literal|"\\"
argument_list|)
end_macro

end_unit

