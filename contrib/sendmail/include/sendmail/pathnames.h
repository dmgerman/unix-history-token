begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998-2000 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: pathnames.h,v 8.16.8.8 2000/09/28 21:26:39 gshapiro Exp $  */
end_comment

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

end_unit

