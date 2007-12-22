begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)pathnames.h	8.1 (Berkeley) 6/6/93  */
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

begin_define
define|#
directive|define
name|_PATH_CHKPRINTCAP
value|"/usr/sbin/chkprintcap"
end_define

end_unit

