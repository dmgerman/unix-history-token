begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/tabs.c,v $  *	$Header: tabs.c,v 10.100 86/12/01 14:45:38 jg Rel $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_tabs_c
init|=
literal|"$Header: tabs.c,v 10.100 86/12/01 14:45:38 jg Rel $"
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
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1984	*/
end_comment

begin_comment
comment|/* tabs.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_comment
comment|/* @(#)tabs.c       X10/6.6B 12/26/86 */
end_comment

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_include
include|#
directive|include
file|"scrollbar.h"
end_include

begin_include
include|#
directive|include
file|"ptyx.h"
end_include

begin_comment
comment|/*  * This file presumes 32bits/word.  This is somewhat of a crock, and should  * be fixed sometime.  */
end_comment

begin_comment
comment|/*  * places tabstops at only every 8 columns  */
end_comment

begin_macro
name|TabReset
argument_list|(
argument|tabs
argument_list|)
end_macro

begin_decl_stmt
name|Tabs
name|tabs
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|TAB_ARRAY_SIZE
condition|;
operator|++
name|i
control|)
name|tabs
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAX_TABS
condition|;
name|i
operator|+=
literal|8
control|)
name|TabSet
argument_list|(
name|tabs
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * places a tabstop at col  */
end_comment

begin_macro
name|TabSet
argument_list|(
argument|tabs
argument_list|,
argument|col
argument_list|)
end_macro

begin_decl_stmt
name|Tabs
name|tabs
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|tabs
index|[
name|col
operator|>>
literal|5
index|]
operator||=
operator|(
literal|1
operator|<<
operator|(
name|col
operator|&
literal|31
operator|)
operator|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * clears a tabstop at col  */
end_comment

begin_macro
name|TabClear
argument_list|(
argument|tabs
argument_list|,
argument|col
argument_list|)
end_macro

begin_decl_stmt
name|Tabs
name|tabs
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|tabs
index|[
name|col
operator|>>
literal|5
index|]
operator|&=
operator|~
operator|(
literal|1
operator|<<
operator|(
name|col
operator|&
literal|31
operator|)
operator|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * returns the column of the next tabstop  * (or MAX_TABS - 1 if there are no more).  * A tabstop at col is ignored.  */
end_comment

begin_macro
name|TabNext
argument_list|(
argument|tabs
argument_list|,
argument|col
argument_list|)
end_macro

begin_decl_stmt
name|Tabs
name|tabs
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|Terminal
name|term
decl_stmt|;
specifier|register
name|Screen
modifier|*
name|screen
init|=
operator|&
name|term
operator|.
name|screen
decl_stmt|;
if|if
condition|(
name|screen
operator|->
name|curses
operator|&&
name|screen
operator|->
name|do_wrap
operator|&&
operator|(
name|term
operator|.
name|flags
operator|&
name|WRAPAROUND
operator|)
condition|)
block|{
name|Index
argument_list|(
name|screen
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|col
operator|=
name|screen
operator|->
name|cur_col
operator|=
name|screen
operator|->
name|do_wrap
operator|=
literal|0
expr_stmt|;
block|}
for|for
control|(
operator|++
name|col
init|;
name|col
operator|<
name|MAX_TABS
condition|;
operator|++
name|col
control|)
if|if
condition|(
name|tabs
index|[
name|col
operator|>>
literal|5
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|col
operator|&
literal|31
operator|)
operator|)
condition|)
return|return
operator|(
name|col
operator|)
return|;
return|return
operator|(
name|MAX_TABS
operator|-
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * clears all tabs  */
end_comment

begin_macro
name|TabZonk
argument_list|(
argument|tabs
argument_list|)
end_macro

begin_decl_stmt
name|Tabs
name|tabs
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|TAB_ARRAY_SIZE
condition|;
operator|++
name|i
control|)
name|tabs
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

