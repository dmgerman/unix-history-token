begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	"@(#)d_cnjg.c	1.1"  */
end_comment

begin_include
include|#
directive|include
file|"complex"
end_include

begin_macro
name|d_cnjg
argument_list|(
argument|r
argument_list|,
argument|z
argument_list|)
end_macro

begin_decl_stmt
name|dcomplex
modifier|*
name|r
decl_stmt|,
modifier|*
name|z
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|r
operator|->
name|dreal
operator|=
name|z
operator|->
name|dreal
expr_stmt|;
name|r
operator|->
name|dimag
operator|=
operator|-
name|z
operator|->
name|dimag
expr_stmt|;
block|}
end_block

end_unit

