begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)pathnames.h	6.5 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILCF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILCF
value|"/etc/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILFC
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILFC
value|"/etc/sendmail.fc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_4
end_ifdef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/var/run/sendmail.pid"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

