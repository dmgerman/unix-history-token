begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)ex_extern.c	7.4 (Berkeley) 6/7/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Provide defs of the global variables.  * This crock is brought to you by the turkeys  * who broke Unix on the Bell Labs 3B machine,  * all in the name of "but that's what the C  * book says!"  */
end_comment

begin_define
define|#
directive|define
name|var
end_define

begin_comment
comment|/* nothing */
end_comment

begin_include
include|#
directive|include
file|"ex.h"
end_include

begin_include
include|#
directive|include
file|"ex_argv.h"
end_include

begin_include
include|#
directive|include
file|"ex_re.h"
end_include

begin_include
include|#
directive|include
file|"ex_temp.h"
end_include

begin_include
include|#
directive|include
file|"ex_tty.h"
end_include

begin_include
include|#
directive|include
file|"ex_tune.h"
end_include

begin_include
include|#
directive|include
file|"ex_vars.h"
end_include

begin_include
include|#
directive|include
file|"ex_vis.h"
end_include

end_unit

