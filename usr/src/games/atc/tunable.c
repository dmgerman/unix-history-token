begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 by Ed James, UC Berkeley.  All rights reserved.  *  * Copy permission is hereby granted provided that this notice is  * retained on all partial or complete copies.  *  * For more info on this and all of my stuff, mail edjames@berkeley.edu.  */
end_comment

begin_comment
comment|/*  * SPECIAL_DIR - Where the special files are kept.  * Change this to whatever you want.  Be sure to have to path end   * with a '/', like "/usr/games/lib/atc/".  */
end_comment

begin_decl_stmt
name|char
name|SPECIAL_DIR
index|[]
init|=
name|DEST
decl_stmt|;
end_decl_stmt

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

