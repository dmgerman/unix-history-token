begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)open.c	8.1 (Berkeley) %G%"
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
comment|/*  * Displays plot files on an HP7221 plotter.  * Cloned from bgplot.c and gigiplot.c by Jim Kleckner  * Thu Jun 30 13:35:04 PDT 1983  *  * Requires a handshaking program such as hp7221cat to get the plotter  * open and ready.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"hp7221.h"
end_include

begin_decl_stmt
name|int
name|currentx
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|currenty
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|lowx
init|=
literal|0.0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|lowy
init|=
literal|0.0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|scale
init|=
literal|1.0
decl_stmt|;
end_decl_stmt

begin_macro
name|openpl
argument_list|()
end_macro

begin_block
block|{
name|void
name|closepl
parameter_list|()
function_decl|;
comment|/* catch interupts */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|closepl
argument_list|)
expr_stmt|;
name|currentx
operator|=
literal|0
expr_stmt|;
name|currenty
operator|=
literal|0
expr_stmt|;
name|printf
argument_list|(
literal|"~VR~W"
argument_list|)
expr_stmt|;
name|putMBP
argument_list|(
literal|800
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
name|putMBP
argument_list|(
literal|7600
argument_list|,
literal|9600
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"~S"
argument_list|)
expr_stmt|;
name|putMBP
argument_list|(
name|XMAX
argument_list|,
name|YMAX
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"vA~*z"
argument_list|)
expr_stmt|;
name|space
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|XMAX
argument_list|,
name|YMAX
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

