begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"ctlmod.h"
end_include

begin_include
include|#
directive|include
file|"pipes.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)pb_tput.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  PB_TPUT -- tagged put ** **	Puts the symbol out to the pipe with the tag. ** **	Parameters: **		tag -- the type of this symbol. **		dp -- the pointer to the data. **		len -- the length of the data. **		ppb -- the pipe buffer to write it on. ** **	Returns: **		none ** **	Side Effects: **		none ** **	Trace Flags: **		none */
end_comment

begin_macro
name|pb_tput
argument_list|(
argument|tag
argument_list|,
argument|dp
argument_list|,
argument|len
argument_list|,
argument|ppb
argument_list|)
end_macro

begin_decl_stmt
name|int
name|tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|pb_t
modifier|*
name|ppb
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|auto
name|char
name|xt
decl_stmt|;
specifier|auto
name|short
name|xlen
decl_stmt|;
name|xt
operator|=
name|tag
expr_stmt|;
name|pb_put
argument_list|(
operator|&
name|xt
argument_list|,
literal|1
argument_list|,
name|ppb
argument_list|)
expr_stmt|;
name|xlen
operator|=
name|len
expr_stmt|;
name|pb_put
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|xlen
argument_list|,
literal|2
argument_list|,
name|ppb
argument_list|)
expr_stmt|;
name|pb_put
argument_list|(
name|dp
argument_list|,
name|len
argument_list|,
name|ppb
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

