begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)paths.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATHS_H_
end_ifndef

begin_define
define|#
directive|define
name|_PATHS_H_
end_define

begin_comment
comment|/* Default search path. */
end_comment

begin_define
define|#
directive|define
name|_PATH_DEFPATH
value|"/usr/bin:/bin"
end_define

begin_comment
comment|/* All standard utilities path. */
end_comment

begin_define
define|#
directive|define
name|_PATH_STDPATH
define|\
value|"/usr/bin:/bin:/usr/sbin:/sbin:/usr/contrib/bin:/usr/old/bin"
end_define

begin_define
define|#
directive|define
name|_PATH_BSHELL
value|"/bin/sh"
end_define

begin_define
define|#
directive|define
name|_PATH_CONSOLE
value|"/dev/console"
end_define

begin_define
define|#
directive|define
name|_PATH_CSHELL
value|"/bin/csh"
end_define

begin_define
define|#
directive|define
name|_PATH_DEVDB
value|"/var/run/dev.db"
end_define

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
end_define

begin_define
define|#
directive|define
name|_PATH_DRUM
value|"/dev/drum"
end_define

begin_define
define|#
directive|define
name|_PATH_KMEM
value|"/dev/kmem"
end_define

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|"/var/mail"
end_define

begin_define
define|#
directive|define
name|_PATH_MAN
value|"/usr/share/man"
end_define

begin_define
define|#
directive|define
name|_PATH_MEM
value|"/dev/mem"
end_define

begin_define
define|#
directive|define
name|_PATH_NOLOGIN
value|"/etc/nologin"
end_define

begin_define
define|#
directive|define
name|_PATH_SENDMAIL
value|"/usr/sbin/sendmail"
end_define

begin_define
define|#
directive|define
name|_PATH_SHELLS
value|"/etc/shells"
end_define

begin_define
define|#
directive|define
name|_PATH_TTY
value|"/dev/tty"
end_define

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/vmunix"
end_define

begin_define
define|#
directive|define
name|_PATH_VI
value|"/usr/bin/vi"
end_define

begin_comment
comment|/* Provide trailing slash, since mostly used for building pathnames. */
end_comment

begin_define
define|#
directive|define
name|_PATH_DEV
value|"/dev/"
end_define

begin_define
define|#
directive|define
name|_PATH_TMP
value|"/tmp/"
end_define

begin_define
define|#
directive|define
name|_PATH_VARDB
value|"/var/db/"
end_define

begin_define
define|#
directive|define
name|_PATH_VARRUN
value|"/var/run/"
end_define

begin_define
define|#
directive|define
name|_PATH_VARTMP
value|"/var/tmp/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATHS_H_ */
end_comment

end_unit

