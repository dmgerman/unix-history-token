begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * real(x) - convert x to real.  */
end_comment

begin_macro
name|Xreal
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
name|double
name|r
decl_stmt|;
comment|/*     * If x is already a real, just return it.  Otherwise convert it and     *  return it, failing if the conversion is unsuccessful.     */
name|DeRef
argument_list|(
argument|arg1
argument_list|)
if|if
condition|(
operator|!
name|QUAL
argument_list|(
name|arg1
argument_list|)
operator|&&
name|TYPE
argument_list|(
name|arg1
argument_list|)
operator|==
name|T_REAL
condition|)
name|arg0
operator|=
name|arg1
expr_stmt|;
elseif|else
if|if
condition|(
name|cvreal
argument_list|(
operator|&
name|arg1
argument_list|,
operator|&
name|r
argument_list|)
operator|==
name|T_REAL
condition|)
name|mkreal
argument_list|(
name|r
argument_list|,
operator|&
name|arg0
argument_list|)
expr_stmt|;
else|else
name|fail
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|Procblock
argument_list|(
argument|real
argument_list|,
literal|1
argument_list|)
end_macro

end_unit

