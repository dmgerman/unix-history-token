begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Timothy C. Stoehr.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1988 The Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)main.c	5.3 (Berkeley) %G%"
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
comment|/*  * main.c  *  * This source herein may be modified and/or distributed by anybody who  * so desires, with the following restrictions:  *    1.)  No portion of this notice shall be removed.  *    2.)  Credit shall not be taken for the creation of this source.  *    3.)  This code is not to be traded, sold, or used for personal  *         gain or profit.  *  */
end_comment

begin_include
include|#
directive|include
file|"rogue.h"
end_include

begin_decl_stmt
specifier|extern
name|short
name|party_room
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
if|if
condition|(
name|init
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
condition|)
block|{
comment|/* restored game */
goto|goto
name|PL
goto|;
block|}
for|for
control|(
init|;
condition|;
control|)
block|{
name|clear_level
argument_list|()
expr_stmt|;
name|make_level
argument_list|()
expr_stmt|;
name|put_objects
argument_list|()
expr_stmt|;
name|put_stairs
argument_list|()
expr_stmt|;
name|add_traps
argument_list|()
expr_stmt|;
name|put_mons
argument_list|()
expr_stmt|;
name|put_player
argument_list|(
name|party_room
argument_list|)
expr_stmt|;
name|print_stats
argument_list|(
name|STAT_ALL
argument_list|)
expr_stmt|;
name|PL
label|:
name|play_level
argument_list|()
expr_stmt|;
name|free_stuff
argument_list|(
operator|&
name|level_objects
argument_list|)
expr_stmt|;
name|free_stuff
argument_list|(
operator|&
name|level_monsters
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

