begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1992 The University of Utah and the Center  *	for Software Science (CSS).  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Center for Software Science of the University of Utah Computer  * Science Department.  CSS requests users of this software to return  * to css-dist@cs.utah.edu any improvements that they make and grant  * CSS redistribution rights.  *  * %sccs.include.redist.c%  *  *	@(#)pathnames.h	8.1 (Berkeley) %G%  *  * Utah $Hdr: pathnames.h 3.1 92/07/06$  * Author: Jeff Forys, University of Utah CSS  */
end_comment

begin_define
define|#
directive|define
name|_PATH_BPF
value|"/dev/bpf%d"
end_define

begin_define
define|#
directive|define
name|_PATH_RBOOTDCONF
value|"/etc/rbootd.conf"
end_define

begin_define
define|#
directive|define
name|_PATH_RBOOTDDBG
value|"/tmp/rbootd.dbg"
end_define

begin_define
define|#
directive|define
name|_PATH_RBOOTDLIB
value|"/usr/mdec/rbootd"
end_define

begin_define
define|#
directive|define
name|_PATH_RBOOTDPID
value|"/var/run/rbootd.pid"
end_define

end_unit

