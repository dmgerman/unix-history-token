begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * %sccs.include.redist.c%  *  *	@(#)local.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Things of local interest.  */
end_comment

begin_define
define|#
directive|define
name|RUNCOM
value|".windowrc"
end_define

begin_define
define|#
directive|define
name|ESCAPEC
value|ctrl('p')
end_define

begin_define
define|#
directive|define
name|NLINE
value|48
end_define

begin_comment
comment|/* default text buffer size */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TERMINFO
end_ifdef

begin_define
define|#
directive|define
name|_PATH_CAPTOINFO
value|"/usr/5bin/captoinfo"
end_define

begin_define
define|#
directive|define
name|_PATH_TIC
value|"/usr/5bin/tic"
end_define

begin_define
define|#
directive|define
name|_PATH_RM
value|"/bin/rm"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

