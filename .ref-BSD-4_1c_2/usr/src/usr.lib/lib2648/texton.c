begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	texton.c	4.1	83/03/09	*/
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|texton
argument_list|()
end_macro

begin_block
block|{
name|sync
argument_list|()
expr_stmt|;
name|escseq
argument_list|(
name|TEXT
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|textoff
argument_list|()
end_macro

begin_block
block|{
name|sync
argument_list|()
expr_stmt|;
comment|/* 	 * The following is needed because going into text mode 	 * leaves the pen where the cursor last was. 	 */
name|_penx
operator|=
operator|-
literal|40
expr_stmt|;
name|_peny
operator|=
literal|40
expr_stmt|;
name|escseq
argument_list|(
name|ESCP
argument_list|)
expr_stmt|;
name|outchar
argument_list|(
literal|'a'
argument_list|)
expr_stmt|;
name|motion
argument_list|(
name|_supx
argument_list|,
name|_supy
argument_list|)
expr_stmt|;
name|_penx
operator|=
name|_supx
expr_stmt|;
name|_peny
operator|=
name|_supy
expr_stmt|;
block|}
end_block

end_unit

