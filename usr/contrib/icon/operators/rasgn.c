begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * x<- y - assign y to x.  * Reverses assignment if resumed.  */
end_comment

begin_macro
name|rasgn
argument_list|(
argument|nargs
argument_list|,
argument|arg2
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
name|arg2
decl_stmt|,
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
comment|/*     * x must be a variable.     */
if|if
condition|(
name|QUAL
argument_list|(
name|arg1
argument_list|)
operator|||
operator|!
name|VAR
argument_list|(
name|arg1
argument_list|)
condition|)
name|runerr
argument_list|(
literal|111
argument_list|,
operator|&
name|arg1
argument_list|)
expr_stmt|;
comment|/*     * The return value is the variable x, so make a copy of it before     *  it is dereferenced.     */
name|arg0
operator|=
name|arg1
expr_stmt|;
name|DeRef
argument_list|(
argument|arg1
argument_list|)
name|DeRef
argument_list|(
argument|arg2
argument_list|)
comment|/*     * Assign y to x and suspend.     */
name|doasgn
argument_list|(
operator|&
name|arg0
argument_list|,
operator|&
name|arg2
argument_list|)
expr_stmt|;
name|suspend
argument_list|()
expr_stmt|;
comment|/*     *<- has been resumed, reverse the assignment by assigning the old value     *  of x (present as arg1) back into x and fail.     */
name|doasgn
argument_list|(
operator|&
name|arg0
argument_list|,
operator|&
name|arg1
argument_list|)
expr_stmt|;
name|fail
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|Opblock
argument_list|(
argument|rasgn
argument_list|,
literal|2
argument_list|,
literal|"<-"
argument_list|)
end_macro

end_unit

