begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	"@(#)pow_ci.c	1.1"  */
end_comment

begin_include
include|#
directive|include
file|"complex"
end_include

begin_macro
name|pow_ci
argument_list|(
argument|p
argument_list|,
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_comment
comment|/* p = a**b  */
end_comment

begin_decl_stmt
name|complex
modifier|*
name|p
decl_stmt|,
modifier|*
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|dcomplex
name|p1
decl_stmt|,
name|a1
decl_stmt|;
name|a1
operator|.
name|dreal
operator|=
name|a
operator|->
name|real
expr_stmt|;
name|a1
operator|.
name|dimag
operator|=
name|a
operator|->
name|imag
expr_stmt|;
name|pow_zi
argument_list|(
operator|&
name|p1
argument_list|,
operator|&
name|a1
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|p
operator|->
name|real
operator|=
name|p1
operator|.
name|dreal
expr_stmt|;
name|p
operator|->
name|imag
operator|=
name|p1
operator|.
name|dimag
expr_stmt|;
block|}
end_block

end_unit

