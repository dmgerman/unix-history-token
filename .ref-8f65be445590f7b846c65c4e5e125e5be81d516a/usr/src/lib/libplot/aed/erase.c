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
literal|"@(#)erase.c	4.1 (Berkeley) 11/11/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"aed.h"
end_include

begin_comment
comment|/*---------------------------------------------------------  *	This routine erases the screen.  *  *	Results:	None.  *	Side Effects:	The screen is cleared.  *---------------------------------------------------------  */
end_comment

begin_macro
name|erase
argument_list|()
end_macro

begin_block
block|{
name|setcolor
argument_list|(
literal|"FF"
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\14'
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\33'
argument_list|,
name|stdout
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
name|curx
argument_list|,
name|cury
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
block|}
end_block

end_unit

