begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek and Darren F. Provine.  *  * %sccs.include.redist.c%  *  *	@(#)scores.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Tetris scores.  */
end_comment

begin_struct
struct|struct
name|highscore
block|{
name|char
name|hs_name
index|[
literal|20
index|]
decl_stmt|;
comment|/* login name */
name|int
name|hs_score
decl_stmt|;
comment|/* raw score */
name|int
name|hs_level
decl_stmt|;
comment|/* play level */
name|time_t
name|hs_time
decl_stmt|;
comment|/* time at game end */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXHISCORES
value|80
end_define

begin_define
define|#
directive|define
name|MAXSCORES
value|9
end_define

begin_comment
comment|/* maximum high score entries per person */
end_comment

begin_define
define|#
directive|define
name|EXPIRATION
value|(5L * 365 * 24 * 60 * 60)
end_define

begin_decl_stmt
name|void
name|savescore
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|showscores
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

