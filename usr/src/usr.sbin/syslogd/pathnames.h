begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)pathnames.h	8.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|_PATH_KLOG
value|"/dev/klog"
end_define

begin_define
define|#
directive|define
name|_PATH_LOGCONF
value|"/etc/syslog.conf"
end_define

begin_define
define|#
directive|define
name|_PATH_LOGPID
value|"/var/run/syslog.pid"
end_define

end_unit

