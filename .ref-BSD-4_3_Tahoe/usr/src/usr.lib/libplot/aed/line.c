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
literal|"@(#)line.c	5.2 (Berkeley) 6/6/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"aed.h"
end_include

begin_comment
comment|/*---------------------------------------------------------  *	Line draws a line between two points.  *  *	Results:	None.  *  *	Side Effects:  *	A line is drawn on the screen between (x1, y1) and (x2, y2).  *---------------------------------------------------------  */
end_comment

begin_macro
name|line
argument_list|(
argument|x1
argument_list|,
argument|y1
argument_list|,
argument|x2
argument_list|,
argument|y2
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x1
decl_stmt|,
name|y1
decl_stmt|,
name|x2
decl_stmt|,
name|y2
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|setcolor
argument_list|(
literal|"01"
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'Q'
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|outxy20
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'A'
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|outxy20
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|curx
operator|=
name|x2
expr_stmt|;
name|cury
operator|=
name|y2
expr_stmt|;
block|}
end_block

end_unit

