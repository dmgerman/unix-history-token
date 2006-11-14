begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b daemon - location of files  *	------------------------------  *  *	$Id: pathnames.h,v 1.11 2000/10/09 11:17:07 hm Exp $   *  * $FreeBSD$  *  *      last edit-date: [Mon Oct  2 22:55:28 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATHNAMES_H_
end_ifndef

begin_define
define|#
directive|define
name|_PATHNAMES_H_
end_define

begin_define
define|#
directive|define
name|I4BDEVICE
value|"/dev/i4b"
end_define

begin_define
define|#
directive|define
name|ETCPATH
value|"/etc/isdn"
end_define

begin_define
define|#
directive|define
name|CONFIG_FILE_DEF
value|"/etc/isdn/isdnd.rc"
end_define

begin_define
define|#
directive|define
name|RATES_FILE_DEF
value|"/etc/isdn/isdnd.rates"
end_define

begin_define
define|#
directive|define
name|HOLIDAY_FILE_DEF
value|"/etc/isdn/holidays"
end_define

begin_define
define|#
directive|define
name|TINA_FILE_DEF
value|"/etc/isdn/tinainitprog"
end_define

begin_define
define|#
directive|define
name|LOG_FILE_DEF
value|"/var/log/isdnd.log"
end_define

begin_define
define|#
directive|define
name|ACCT_FILE_DEF
value|"/var/log/isdnd.acct"
end_define

begin_define
define|#
directive|define
name|PIDFILE
value|"/var/run/isdnd.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATHNAMES_H_ */
end_comment

begin_comment
comment|/* EOF */
end_comment

end_unit

