begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)extern.c	5.2 (Berkeley) 6/27/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  *  Hunt  *  Copyright (c) 1985 Conrad C. Huang, Gregory S. Couch, Kenneth C.R.C. Arnold  *  San Francisco, California  */
end_comment

begin_include
include|#
directive|include
file|"hunt.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MONITOR
end_ifdef

begin_decl_stmt
name|FLAG
name|Am_monitor
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current process is a monitor */
end_comment

begin_endif
endif|#
directive|endif
endif|MONITOR
end_endif

begin_decl_stmt
name|char
name|Buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general scribbling buffer */
end_comment

begin_decl_stmt
name|char
name|Maze
index|[
name|HEIGHT
index|]
index|[
name|WIDTH2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the maze */
end_comment

begin_decl_stmt
name|char
name|Orig_maze
index|[
name|HEIGHT
index|]
index|[
name|WIDTH2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the original maze */
end_comment

begin_decl_stmt
name|long
name|Fds_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mask for the file descriptors */
end_comment

begin_decl_stmt
name|int
name|Have_inp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which file descriptors have input */
end_comment

begin_decl_stmt
name|int
name|Nplayer
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of players */
end_comment

begin_decl_stmt
name|int
name|Num_fds
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of maximum file descriptor */
end_comment

begin_decl_stmt
name|int
name|Socket
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* main socket */
end_comment

begin_decl_stmt
name|long
name|Sock_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* select mask for main socket */
end_comment

begin_decl_stmt
name|int
name|See_over
index|[
name|NASCII
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup table for determining whether 					 * character represents "transparent" 					 * item */
end_comment

begin_decl_stmt
name|BULLET
modifier|*
name|Bullets
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* linked list of bullets */
end_comment

begin_decl_stmt
name|EXPL
modifier|*
name|Expl
index|[
name|EXPLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* explosion lists */
end_comment

begin_decl_stmt
name|PLAYER
name|Player
index|[
name|MAXPL
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* all the players */
end_comment

begin_decl_stmt
name|PLAYER
modifier|*
name|End_player
init|=
name|Player
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last active player slot */
end_comment

begin_decl_stmt
name|IDENT
modifier|*
name|Scores
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* score cache */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MONITOR
end_ifdef

begin_decl_stmt
name|PLAYER
name|Monitor
index|[
name|MAXMON
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* all the monitors */
end_comment

begin_decl_stmt
name|PLAYER
modifier|*
name|End_monitor
init|=
name|Monitor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last active monitor slot */
end_comment

begin_endif
endif|#
directive|endif
endif|MONITOR
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VOLCANO
end_ifdef

begin_decl_stmt
name|int
name|volcano
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Explosion size */
end_comment

begin_endif
endif|#
directive|endif
endif|VOLCANO
end_endif

end_unit

