begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

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
literal|"@(#)extern.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"hangman.h"
end_include

begin_decl_stmt
name|bool
name|Guessed
index|[
literal|26
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Word
index|[
name|BUFSIZ
index|]
decl_stmt|,
name|Known
index|[
name|BUFSIZ
index|]
decl_stmt|,
modifier|*
name|Noose_pict
index|[]
init|=
block|{
literal|"     ______"
block|,
literal|"     |    |"
block|,
literal|"     |"
block|,
literal|"     |"
block|,
literal|"     |"
block|,
literal|"     |"
block|,
literal|"   __|_____"
block|,
literal|"   |      |___"
block|,
literal|"   |_________|"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Errors
decl_stmt|,
name|Wordnum
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|Average
init|=
literal|0.0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ERR_POS
name|Err_pos
index|[
name|MAXERRS
index|]
init|=
block|{
block|{
literal|2
block|,
literal|10
block|,
literal|'O'
block|}
block|,
block|{
literal|3
block|,
literal|10
block|,
literal|'|'
block|}
block|,
block|{
literal|4
block|,
literal|10
block|,
literal|'|'
block|}
block|,
block|{
literal|5
block|,
literal|9
block|,
literal|'/'
block|}
block|,
block|{
literal|3
block|,
literal|9
block|,
literal|'/'
block|}
block|,
block|{
literal|3
block|,
literal|11
block|,
literal|'\\'
block|}
block|,
block|{
literal|5
block|,
literal|11
block|,
literal|'\\'
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|Dict
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|Dict_size
decl_stmt|;
end_decl_stmt

end_unit

