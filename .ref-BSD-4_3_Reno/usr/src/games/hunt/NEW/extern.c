begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Hunt  *  Copyright (c) 1985 Conrad C. Huang, Gregory S. Couch, Kenneth C.R.C. Arnold  *  San Francisco, California  *  *  Copyright (c) 1985 Regents of the University of California.  *  All rights reserved.  The Berkeley software License Agreement  *  specifies the terms and conditions for redistribution.  */
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
name|Status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stat socket */
end_comment

begin_decl_stmt
name|long
name|Stat_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* select mask for stat socket */
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
name|EXPL
modifier|*
name|Last_expl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last explosion on Expl[0] */
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

begin_ifdef
ifdef|#
directive|ifdef
name|BOOTS
end_ifdef

begin_decl_stmt
name|PLAYER
name|Boot
index|[
name|NBOOTS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* all the boots */
end_comment

begin_endif
endif|#
directive|endif
endif|BOOTS
end_endif

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

begin_decl_stmt
name|int
name|shot_req
index|[
name|MAXBOMB
index|]
init|=
block|{
name|BULREQ
block|,
name|GRENREQ
block|,
name|SATREQ
block|,
name|BOMB7REQ
block|,
name|BOMB9REQ
block|,
name|BOMB11REQ
block|,
name|BOMB13REQ
block|,
name|BOMB15REQ
block|,
name|BOMB17REQ
block|,
name|BOMB19REQ
block|,
name|BOMB21REQ
block|, 			}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|shot_type
index|[
name|MAXBOMB
index|]
init|=
block|{
name|SHOT
block|,
name|GRENADE
block|,
name|SATCHEL
block|,
name|BOMB
block|,
name|BOMB
block|,
name|BOMB
block|,
name|BOMB
block|,
name|BOMB
block|,
name|BOMB
block|,
name|BOMB
block|,
name|BOMB
block|, 			}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|slime_req
index|[
name|MAXSLIME
index|]
init|=
block|{
name|SLIMEREQ
block|,
name|SSLIMEREQ
block|,
name|SLIME2REQ
block|,
name|SLIME3REQ
block|, 			}
decl_stmt|;
end_decl_stmt

end_unit

