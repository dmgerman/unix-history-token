begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	set.c	4.1	83/03/09	*/
end_comment

begin_comment
comment|/*  * Routines to set line type.  */
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|setxor
argument_list|()
end_macro

begin_block
block|{
name|_supsmode
operator|=
name|MX
expr_stmt|;
block|}
end_block

begin_macro
name|setclear
argument_list|()
end_macro

begin_block
block|{
name|_supsmode
operator|=
name|_video
operator|==
name|INVERSE
condition|?
name|MS
else|:
name|MC
expr_stmt|;
block|}
end_block

begin_macro
name|setset
argument_list|()
end_macro

begin_block
block|{
name|_supsmode
operator|=
name|_video
operator|==
name|INVERSE
condition|?
name|MC
else|:
name|MS
expr_stmt|;
block|}
end_block

end_unit

