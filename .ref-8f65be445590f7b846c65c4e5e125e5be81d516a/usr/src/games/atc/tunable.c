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
literal|"@(#)tunable.c	5.4 (Berkeley) %G%"
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
comment|/*  * NUM_SCORES - Number of scores that are kept track of.  * Keep this greater than 0, but less than 100.  * 4 lines are printed above the score, one below + your prompt, so  * to prevent scrolling: 6 + NUM_SCORES<= 24 (lines on an average terminal).  */
end_comment

begin_decl_stmt
name|int
name|NUM_SCORES
init|=
literal|18
decl_stmt|;
end_decl_stmt

end_unit

