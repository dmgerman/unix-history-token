begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rodney Ruddock of the University of Guelph.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)equal.c	5.3 (Berkeley) %G%"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DBI
end_ifdef

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ed.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/*  * Print out what the line number of the address given is; default to  * end-of-buffer ($).  */
end_comment

begin_function
name|void
name|equal
parameter_list|(
name|inputt
parameter_list|,
name|errnum
parameter_list|)
name|FILE
modifier|*
name|inputt
decl_stmt|;
name|int
modifier|*
name|errnum
decl_stmt|;
block|{
if|if
condition|(
name|End_default
condition|)
name|start
operator|=
name|bottom
expr_stmt|;
else|else
name|start
operator|=
name|End
expr_stmt|;
name|start_default
operator|=
name|End_default
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|rol
argument_list|(
name|inputt
argument_list|,
name|errnum
argument_list|)
condition|)
return|return;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|line_number
argument_list|(
name|start
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|errnum
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

