begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)pathnames.h	5.4 (Berkeley) 6/1/90  */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|_PATH_DEFDEVLP
value|"/dev/lp"
end_define

begin_define
define|#
directive|define
name|_PATH_DEFSPOOL
value|"/var/spool/output/lpd"
end_define

begin_define
define|#
directive|define
name|_PATH_HOSTSEQUIV
value|"/etc/hosts.equiv"
end_define

begin_define
define|#
directive|define
name|_PATH_HOSTSLPD
value|"/etc/hosts.lpd"
end_define

begin_define
define|#
directive|define
name|_PATH_MASTERLOCK
value|"/var/spool/output/lpd.lock"
end_define

begin_define
define|#
directive|define
name|_PATH_PR
value|"/usr/bin/pr"
end_define

begin_define
define|#
directive|define
name|_PATH_PRINTCAP
value|"/etc/printcap"
end_define

begin_define
define|#
directive|define
name|_PATH_SOCKETNAME
value|"/var/run/printer"
end_define

begin_define
define|#
directive|define
name|_PATH_VFONT
value|"/usr/libdata/vfont/"
end_define

begin_define
define|#
directive|define
name|_PATH_VFONTB
value|"/usr/libdata/vfont/B"
end_define

begin_define
define|#
directive|define
name|_PATH_VFONTI
value|"/usr/libdata/vfont/I"
end_define

begin_define
define|#
directive|define
name|_PATH_VFONTR
value|"/usr/libdata/vfont/R"
end_define

begin_define
define|#
directive|define
name|_PATH_VFONTS
value|"/usr/libdata/vfont/S"
end_define

end_unit

