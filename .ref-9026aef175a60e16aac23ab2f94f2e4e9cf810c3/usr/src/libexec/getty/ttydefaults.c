begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)ttydefaults.c	8.1 (Berkeley) %G%"
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
file|<sys/termios.h>
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_function
name|void
name|set_ttydefaults
parameter_list|(
name|fd
parameter_list|)
name|int
name|fd
decl_stmt|;
block|{
name|struct
name|termios
name|term
decl_stmt|;
name|tcgetattr
argument_list|(
name|fd
argument_list|,
operator|&
name|term
argument_list|)
expr_stmt|;
name|term
operator|.
name|c_iflag
operator|=
name|TTYDEF_IFLAG
expr_stmt|;
name|term
operator|.
name|c_oflag
operator|=
name|TTYDEF_OFLAG
expr_stmt|;
name|term
operator|.
name|c_lflag
operator|=
name|TTYDEF_LFLAG
expr_stmt|;
name|term
operator|.
name|c_cflag
operator|=
name|TTYDEF_CFLAG
expr_stmt|;
name|tcsetattr
argument_list|(
name|fd
argument_list|,
name|TCSAFLUSH
argument_list|,
operator|&
name|term
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

