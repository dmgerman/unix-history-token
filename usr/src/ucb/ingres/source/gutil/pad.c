begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)pad.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  PAD STRING OUT WITH BLANKS ** **	This routine is an in-place pmove which always pads **	with blanks. */
end_comment

begin_macro
name|pad
argument_list|(
argument|s
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|ss
decl_stmt|;
name|ss
operator|=
name|s
expr_stmt|;
name|pmove
argument_list|(
name|ss
argument_list|,
name|ss
argument_list|,
name|n
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

