begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)tk_screen.c	8.9 (Berkeley) 5/24/96"
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
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"../common/common.h"
end_include

begin_include
include|#
directive|include
file|"tki.h"
end_include

begin_comment
comment|/*  * tk_screen --  *	Initialize/shutdown the Tcl/Tk screen.  *  * PUBLIC: int tk_screen __P((SCR *, u_int32_t));  */
end_comment

begin_function
name|int
name|tk_screen
parameter_list|(
name|sp
parameter_list|,
name|flags
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
block|{
name|TK_PRIVATE
modifier|*
name|tkp
decl_stmt|;
name|tkp
operator|=
name|TKP
argument_list|(
name|sp
argument_list|)
expr_stmt|;
comment|/* See if we're already in the right mode. */
if|if
condition|(
name|LF_ISSET
argument_list|(
name|SC_VI
argument_list|)
operator|&&
name|F_ISSET
argument_list|(
name|sp
argument_list|,
name|SC_SCR_VI
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Ex isn't possible. */
if|if
condition|(
name|LF_ISSET
argument_list|(
name|SC_EX
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Initialize terminal based information. */
if|if
condition|(
name|tk_term_init
argument_list|(
name|sp
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Put up the first file name. */
if|if
condition|(
name|tk_rename
argument_list|(
name|sp
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|F_SET
argument_list|(
name|tkp
argument_list|,
name|TK_SCR_VI_INIT
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * tk_quit --  *	Shutdown the screens.  *  * PUBLIC: int tk_quit __P((GS *));  */
end_comment

begin_function
name|int
name|tk_quit
parameter_list|(
name|gp
parameter_list|)
name|GS
modifier|*
name|gp
decl_stmt|;
block|{
name|TK_PRIVATE
modifier|*
name|tkp
decl_stmt|;
name|int
name|rval
decl_stmt|;
comment|/* Clean up the terminal mappings. */
name|rval
operator|=
name|tk_term_end
argument_list|(
name|gp
argument_list|)
expr_stmt|;
name|tkp
operator|=
name|GTKP
argument_list|(
name|gp
argument_list|)
expr_stmt|;
name|F_CLR
argument_list|(
name|tkp
argument_list|,
name|TK_SCR_VI_INIT
argument_list|)
expr_stmt|;
return|return
operator|(
name|rval
operator|)
return|;
block|}
end_function

end_unit

