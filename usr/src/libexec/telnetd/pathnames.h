begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)pathnames.h	5.5 (Berkeley) %G%  */
end_comment

begin_if
if|#
directive|if
name|BSD
operator|>
literal|43
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|_PATH_LOGIN
value|"/usr/bin/login"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_TTY
value|"/dev/tty"
end_define

begin_define
define|#
directive|define
name|_PATH_LOGIN
value|"/bin/login"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BFTPDAEMON
end_ifdef

begin_define
define|#
directive|define
name|BFTPPATH
value|"/usr/ucb/bftp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BFTPDAEMON */
end_comment

end_unit

