begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|vidnorm
argument_list|()
end_macro

begin_block
block|{
name|_video
operator|=
name|NORMAL
expr_stmt|;
block|}
end_block

begin_macro
name|vidinv
argument_list|()
end_macro

begin_block
block|{
name|_video
operator|=
name|INVERSE
expr_stmt|;
block|}
end_block

begin_macro
name|togvid
argument_list|()
end_macro

begin_block
block|{
name|_video
operator|=
operator|(
name|_video
operator|==
name|NORMAL
operator|)
condition|?
name|INVERSE
else|:
name|NORMAL
expr_stmt|;
name|escseq
argument_list|(
name|ESCM
argument_list|)
expr_stmt|;
name|outstr
argument_list|(
literal|"3a1b0 0 719 359e"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

