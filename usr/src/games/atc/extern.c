begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ed James.  *  * %sccs.include.redist.c%  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987 by Ed James, UC Berkeley.  All rights reserved.  *  * Copy permission is hereby granted provided that this notice is  * retained on all partial or complete copies.  *  * For more info on this and all of my stuff, mail edjames@berkeley.edu.  */
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
file|"include.h"
end_include

begin_decl_stmt
name|char
name|GAMES
index|[]
init|=
literal|"Game_List"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|clock
decl_stmt|,
name|safe_planes
decl_stmt|,
name|start_time
decl_stmt|,
name|test_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|filein
decl_stmt|,
modifier|*
name|fileout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|C_SCREEN
name|screen
decl_stmt|,
modifier|*
name|sp
init|=
operator|&
name|screen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIST
name|air
decl_stmt|,
name|ground
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sgttyb
name|tty_start
decl_stmt|,
name|tty_new
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DISPLACEMENT
name|displacement
index|[
name|MAXDIR
index|]
init|=
block|{
block|{
literal|0
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|1
block|,
literal|0
block|}
block|,
block|{
literal|1
block|,
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|1
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|1
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|}
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

