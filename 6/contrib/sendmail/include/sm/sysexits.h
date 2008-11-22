begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sysexits.h,v 1.5 2001/03/10 17:30:01 ca Exp $  *	@(#)sysexits.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_SYSEXITS_H
end_ifndef

begin_define
define|#
directive|define
name|SM_SYSEXITS_H
end_define

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_comment
comment|/* **  SYSEXITS.H -- Exit status codes for system programs. ** **	This include file attempts to categorize possible error **	exit statuses for system programs, notably delivermail **	and the Berkeley network. ** **	Error numbers begin at EX__BASE to reduce the possibility of **	clashing with other exit statuses that random programs may **	already return.  The meaning of the codes is approximately **	as follows: ** **	EX_USAGE -- The command was used incorrectly, e.g., with **		the wrong number of arguments, a bad flag, a bad **		syntax in a parameter, or whatever. **	EX_DATAERR -- The input data was incorrect in some way. **		This should only be used for user's data& not **		system files. **	EX_NOINPUT -- An input file (not a system file) did not **		exist or was not readable.  This could also include **		errors like "No message" to a mailer (if it cared **		to catch it). **	EX_NOUSER -- The user specified did not exist.  This might **		be used for mail addresses or remote logins. **	EX_NOHOST -- The host specified did not exist.  This is used **		in mail addresses or network requests. **	EX_UNAVAILABLE -- A service is unavailable.  This can occur **		if a support program or file does not exist.  This **		can also be used as a catchall message when something **		you wanted to do doesn't work, but you don't know **		why. **	EX_SOFTWARE -- An internal software error has been detected. **		This should be limited to non-operating system related **		errors as possible. **	EX_OSERR -- An operating system error has been detected. **		This is intended to be used for such things as "cannot **		fork", "cannot create pipe", or the like.  It includes **		things like getuid returning a user that does not **		exist in the passwd file. **	EX_OSFILE -- Some system file (e.g., /etc/passwd, /etc/utmp, **		etc.) does not exist, cannot be opened, or has some **		sort of error (e.g., syntax error). **	EX_CANTCREAT -- A (user specified) output file cannot be **		created. **	EX_IOERR -- An error occurred while doing I/O on some file. **	EX_TEMPFAIL -- temporary failure, indicating something that **		is not really an error.  In sendmail, this means **		that a mailer (e.g.) could not create a connection, **		and the request should be reattempted later. **	EX_PROTOCOL -- the remote system returned something that **		was "not possible" during a protocol exchange. **	EX_NOPERM -- You did not have sufficient permission to **		perform the operation.  This is not intended for **		file system problems, which should use NOINPUT or **		CANTCREAT, but rather for higher level permissions. */
end_comment

begin_if
if|#
directive|if
name|SM_CONF_SYSEXITS_H
end_if

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CONF_SYSEXITS_H */
end_comment

begin_define
define|#
directive|define
name|EX_OK
value|0
end_define

begin_comment
comment|/* successful termination */
end_comment

begin_define
define|#
directive|define
name|EX__BASE
value|64
end_define

begin_comment
comment|/* base value for error messages */
end_comment

begin_define
define|#
directive|define
name|EX_USAGE
value|64
end_define

begin_comment
comment|/* command line usage error */
end_comment

begin_define
define|#
directive|define
name|EX_DATAERR
value|65
end_define

begin_comment
comment|/* data format error */
end_comment

begin_define
define|#
directive|define
name|EX_NOINPUT
value|66
end_define

begin_comment
comment|/* cannot open input */
end_comment

begin_define
define|#
directive|define
name|EX_NOUSER
value|67
end_define

begin_comment
comment|/* addressee unknown */
end_comment

begin_define
define|#
directive|define
name|EX_NOHOST
value|68
end_define

begin_comment
comment|/* host name unknown */
end_comment

begin_define
define|#
directive|define
name|EX_UNAVAILABLE
value|69
end_define

begin_comment
comment|/* service unavailable */
end_comment

begin_define
define|#
directive|define
name|EX_SOFTWARE
value|70
end_define

begin_comment
comment|/* internal software error */
end_comment

begin_define
define|#
directive|define
name|EX_OSERR
value|71
end_define

begin_comment
comment|/* system error (e.g., can't fork) */
end_comment

begin_define
define|#
directive|define
name|EX_OSFILE
value|72
end_define

begin_comment
comment|/* critical OS file missing */
end_comment

begin_define
define|#
directive|define
name|EX_CANTCREAT
value|73
end_define

begin_comment
comment|/* can't create (user) output file */
end_comment

begin_define
define|#
directive|define
name|EX_IOERR
value|74
end_define

begin_comment
comment|/* input/output error */
end_comment

begin_define
define|#
directive|define
name|EX_TEMPFAIL
value|75
end_define

begin_comment
comment|/* temp failure; user is invited to retry */
end_comment

begin_define
define|#
directive|define
name|EX_PROTOCOL
value|76
end_define

begin_comment
comment|/* remote error in protocol */
end_comment

begin_define
define|#
directive|define
name|EX_NOPERM
value|77
end_define

begin_comment
comment|/* permission denied */
end_comment

begin_define
define|#
directive|define
name|EX_CONFIG
value|78
end_define

begin_comment
comment|/* configuration error */
end_comment

begin_define
define|#
directive|define
name|EX__MAX
value|78
end_define

begin_comment
comment|/* maximum listed value */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SYSEXITS_H */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sm_strexit
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sm_sysexitmsg
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sm_sysexmsg
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_SYSEXITS_H */
end_comment

end_unit

