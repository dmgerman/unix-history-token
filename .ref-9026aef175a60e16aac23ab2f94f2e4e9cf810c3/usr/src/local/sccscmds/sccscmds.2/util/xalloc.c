begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../hdr/macros.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_expr_stmt
name|SCCSID
argument_list|(
argument|@
operator|(
operator|#
operator|)
name|xalloc
literal|2.1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|xalloc
argument_list|(
argument|asize
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|asize
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Call to xalloc!?!\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|xfree
argument_list|(
argument|aptr
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|aptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Call to xfree!?!\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|xfreeall
argument_list|()
end_macro

begin_block
block|{  }
end_block

end_unit

