begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: pathnames.h,v 8.35 2001/03/23 22:09:44 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_PATHNAMES_H
end_ifndef

begin_define
define|#
directive|define
name|SM_PATHNAMES_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILCF
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_VENDOR_CF_PATH
argument_list|)
operator|&&
name|defined
argument_list|(
name|_PATH_VENDOR_CF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_SENDMAILCF
value|_PATH_VENDOR_CF
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(USE_VENDOR_CF_PATH)&& defined(_PATH_VENDOR_CF) */
end_comment

begin_define
define|#
directive|define
name|_PATH_SENDMAILCF
value|"/etc/mail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(USE_VENDOR_CF_PATH)&& defined(_PATH_VENDOR_CF) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILCF */
end_comment

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

begin_comment
comment|/* BSD4_4 */
end_comment

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/mail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4_4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAIL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAIL
value|"/usr/lib/sendmail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAIL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_MAILDIR
end_ifndef

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|"/var/spool/mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_MAILDIR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_LOCTMP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_LOCTMP
value|"/tmp/local.XXXXXX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_LOCTMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_HOSTS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_HOSTS
value|"/etc/hosts"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_HOSTS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIR_SENDMAILCF
end_ifndef

begin_define
define|#
directive|define
name|_DIR_SENDMAILCF
value|"/etc/mail/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _DIR_SENDMAILCF */
end_comment

begin_define
define|#
directive|define
name|SM_GET_RIGHT_CF
value|0
end_define

begin_comment
comment|/* get "right" .cf */
end_comment

begin_define
define|#
directive|define
name|SM_GET_SENDMAIL_CF
value|1
end_define

begin_comment
comment|/* always use sendmail.cf */
end_comment

begin_define
define|#
directive|define
name|SM_GET_SUBMIT_CF
value|2
end_define

begin_comment
comment|/* always use submit.cf */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getcfname
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_PATHNAMES_H */
end_comment

end_unit

