begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)pathnames.h	8.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|_PATH_MSGS
value|"/var/msgs"
end_define

begin_define
define|#
directive|define
name|_PATH_MAIL
value|"/usr/bin/Mail -f %s"
end_define

begin_define
define|#
directive|define
name|_PATH_PAGER
value|"/usr/bin/more -%d"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_TMP
end_undef

begin_define
define|#
directive|define
name|_PATH_TMP
value|"/tmp/msgXXXXXX"
end_define

end_unit

