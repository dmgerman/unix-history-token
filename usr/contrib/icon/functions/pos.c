begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * pos(i) - test if&pos is at position i in&subject.  */
end_comment

begin_macro
name|Xpos
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
specifier|register
name|int
name|i
decl_stmt|;
name|long
name|l
decl_stmt|;
comment|/*     * i must be an integer.     */
if|if
condition|(
name|cvint
argument_list|(
operator|&
name|arg1
argument_list|,
operator|&
name|l
argument_list|)
operator|==
name|NULL
condition|)
name|runerr
argument_list|(
literal|101
argument_list|,
operator|&
name|arg1
argument_list|)
expr_stmt|;
comment|/*     * Fail if&pos isn't equivalent to i, return i otherwise.     */
if|if
condition|(
operator|(
name|i
operator|=
name|cvpos
argument_list|(
name|l
argument_list|,
name|STRLEN
argument_list|(
name|k_subject
argument_list|)
argument_list|)
operator|)
operator|!=
name|k_pos
condition|)
name|fail
argument_list|()
expr_stmt|;
name|arg0
operator|.
name|type
operator|=
name|D_INTEGER
expr_stmt|;
name|INTVAL
argument_list|(
name|arg0
argument_list|)
operator|=
name|i
expr_stmt|;
block|}
end_block

begin_macro
name|Procblock
argument_list|(
argument|pos
argument_list|,
literal|1
argument_list|)
end_macro

end_unit

