begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Apush.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_macro
name|push
argument_list|(
argument|infop
argument_list|,
argument|longword
argument_list|)
end_macro

begin_decl_stmt
name|process_info
modifier|*
name|infop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|longword
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* /*	Push the given datum on the current stack. /* /******************************************/
end_comment

begin_block
block|{
name|struct
name|oprnd
name|temp
decl_stmt|;
name|temp
operator|.
name|mode
operator|=
name|Add
operator||
name|W
expr_stmt|;
name|sp
operator|-=
literal|4
expr_stmt|;
name|temp
operator|.
name|address
operator|=
name|sp
expr_stmt|;
name|temp
operator|.
name|length
operator|=
literal|4
expr_stmt|;
name|write_back
argument_list|(
name|infop
argument_list|,
name|longword
argument_list|,
operator|&
name|temp
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

