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
literal|"@(#)cmdtab.c	2.6 (Berkeley) %G%"
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
file|"timedc.h"
end_include

begin_decl_stmt
name|int
name|clockdiff
argument_list|()
decl_stmt|,
name|help
argument_list|()
decl_stmt|,
name|msite
argument_list|()
decl_stmt|,
name|quit
argument_list|()
decl_stmt|,
name|testing
argument_list|()
decl_stmt|,
name|tracing
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|clockdiffhelp
index|[]
init|=
literal|"measures clock differences between machines"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|helphelp
index|[]
init|=
literal|"gets help on commands"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|msitehelp
index|[]
init|=
literal|"finds location of master"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|quithelp
index|[]
init|=
literal|"exits timedc"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|testinghelp
index|[]
init|=
literal|"causes election timers to expire"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|tracinghelp
index|[]
init|=
literal|"turns tracing on or off"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cmd
name|cmdtab
index|[]
init|=
block|{
block|{
literal|"clockdiff"
block|,
name|clockdiffhelp
block|,
name|clockdiff
block|,
literal|0
block|}
block|,
block|{
literal|"election"
block|,
name|testinghelp
block|,
name|testing
block|,
literal|1
block|}
block|,
block|{
literal|"help"
block|,
name|helphelp
block|,
name|help
block|,
literal|0
block|}
block|,
block|{
literal|"msite"
block|,
name|msitehelp
block|,
name|msite
block|,
literal|0
block|}
block|,
block|{
literal|"quit"
block|,
name|quithelp
block|,
name|quit
block|,
literal|0
block|}
block|,
block|{
literal|"trace"
block|,
name|tracinghelp
block|,
name|tracing
block|,
literal|1
block|}
block|,
block|{
literal|"?"
block|,
name|helphelp
block|,
name|help
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|NCMDS
init|=
sizeof|sizeof
argument_list|(
name|cmdtab
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|cmdtab
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

