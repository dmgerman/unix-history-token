begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)pathnames.h	5.6 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_define
define|#
directive|define
name|_PATH_MASTERLOG
value|"/usr/adm/timed.masterlog"
end_define

begin_define
define|#
directive|define
name|_PATH_TIMEDLOG
value|"/usr/adm/timed.log"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_MASTERLOG
value|"/var/log/timed.masterlog"
end_define

begin_define
define|#
directive|define
name|_PATH_TIMEDLOG
value|"/var/log/timed.log"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

