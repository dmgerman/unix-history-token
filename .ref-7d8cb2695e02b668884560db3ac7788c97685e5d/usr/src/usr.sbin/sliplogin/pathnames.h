begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)pathnames.h	5.4 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPAT
end_ifndef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_ACCESS
value|"/etc/sliphome/slip.hosts"
end_define

begin_define
define|#
directive|define
name|_PATH_LOGIN
value|"/etc/sliphome/slip.login"
end_define

begin_define
define|#
directive|define
name|_PATH_LOGOUT
value|"/etc/sliphome/slip.logout"
end_define

begin_define
define|#
directive|define
name|_PATH_DEBUG
value|"/tmp/sliplogin.XXXXXX"
end_define

end_unit

