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
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1980 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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
literal|"@(#)version.c	5.1 (Berkeley) 6/5/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
name|char
name|version
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
name|long
name|time
parameter_list|()
function_decl|;
name|long
name|clock
decl_stmt|;
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
name|struct
name|tm
modifier|*
name|tmp
decl_stmt|;
name|int
name|major
decl_stmt|;
name|int
name|minor
decl_stmt|;
name|time
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|tmp
operator|=
name|localtime
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|sscanf
argument_list|(
name|version
argument_list|,
literal|"%d.%d"
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
expr_stmt|;
name|minor
operator|+=
literal|1
expr_stmt|;
name|printf
argument_list|(
literal|"char	version[] = \"%d.%d (%d/%d/%d)\";\n"
argument_list|,
name|major
argument_list|,
name|minor
argument_list|,
name|tmp
operator|->
name|tm_mon
operator|+
literal|1
argument_list|,
name|tmp
operator|->
name|tm_mday
argument_list|,
name|tmp
operator|->
name|tm_year
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

