begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)frame.c	1.1 (CWI) 85/07/19"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"grap.h"
end_include

begin_include
include|#
directive|include
file|"y.tab.h"
end_include

begin_decl_stmt
name|double
name|frame_ht
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default frame height */
end_comment

begin_decl_stmt
name|double
name|frame_wid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and width */
end_comment

begin_decl_stmt
name|int
name|nsides
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many sides given on this frame */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sides
index|[]
init|=
block|{
literal|"\tline from Frame.nw to Frame.ne"
block|,
literal|"\tline from Frame.sw to Frame.se"
block|,
literal|"\tline from Frame.sw to Frame.nw"
block|,
literal|"\tline from Frame.se to Frame.ne"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|newsides
index|[
literal|4
index|]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filled in later */
end_comment

begin_macro
name|frame
argument_list|()
end_macro

begin_comment
comment|/* pump out frame definition, reset for next */
end_comment

begin_block
block|{
name|int
name|i
decl_stmt|;
name|fprintf
argument_list|(
name|tfd
argument_list|,
literal|"\tframeht = %g\n"
argument_list|,
name|frame_ht
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tfd
argument_list|,
literal|"\tframewid = %g\n"
argument_list|,
name|frame_wid
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|tfd
argument_list|,
literal|"Frame:\tbox ht frameht wid framewid with .sw at 0,0 "
argument_list|)
expr_stmt|;
if|if
condition|(
name|nsides
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|tfd
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
else|else
block|{
name|fprintf
argument_list|(
name|tfd
argument_list|,
literal|"invis\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|newsides
index|[
name|i
index|]
condition|)
block|{
name|fprintf
argument_list|(
name|tfd
argument_list|,
literal|"%s\n"
argument_list|,
name|newsides
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|newsides
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|newsides
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|fprintf
argument_list|(
name|tfd
argument_list|,
literal|"%s\n"
argument_list|,
name|sides
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|nsides
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|frameht
argument_list|(
argument|f
argument_list|)
end_macro

begin_comment
comment|/* set height of frame */
end_comment

begin_decl_stmt
name|double
name|f
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|frame_ht
operator|=
name|f
expr_stmt|;
block|}
end_block

begin_macro
name|framewid
argument_list|(
argument|f
argument_list|)
end_macro

begin_comment
comment|/* set width of frame */
end_comment

begin_decl_stmt
name|double
name|f
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|frame_wid
operator|=
name|f
expr_stmt|;
block|}
end_block

begin_macro
name|frameside
argument_list|(
argument|type
argument_list|,
argument|desc
argument_list|)
end_macro

begin_comment
comment|/* create and remember sides */
end_comment

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Attr
modifier|*
name|desc
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|n
decl_stmt|;
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|nsides
operator|++
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
literal|0
case|:
comment|/* no side specified; kludge up all */
name|frameside
argument_list|(
name|TOP
argument_list|,
name|desc
argument_list|)
expr_stmt|;
name|frameside
argument_list|(
name|BOT
argument_list|,
name|desc
argument_list|)
expr_stmt|;
name|frameside
argument_list|(
name|LEFT
argument_list|,
name|desc
argument_list|)
expr_stmt|;
name|frameside
argument_list|(
name|RIGHT
argument_list|,
name|desc
argument_list|)
expr_stmt|;
return|return;
case|case
name|TOP
case|:
name|n
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|BOT
case|:
name|n
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|LEFT
case|:
name|n
operator|=
literal|2
expr_stmt|;
break|break;
case|case
name|RIGHT
case|:
name|n
operator|=
literal|3
expr_stmt|;
break|break;
block|}
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s %s"
argument_list|,
name|sides
index|[
name|n
index|]
argument_list|,
name|desc_str
argument_list|(
name|desc
argument_list|)
argument_list|)
expr_stmt|;
name|newsides
index|[
name|n
index|]
operator|=
name|tostring
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

