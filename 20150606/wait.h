begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* NAME:  *	wait.h - compensate for what vendors leave out  *  * AUTHOR:  *	Simon J. Gerraty<sjg@crufty.net>  */
end_comment

begin_comment
comment|/*  * RCSid:  *	$Id: wait.h,v 1.6 2002/11/26 07:53:06 sjg Exp $  *  *      @(#)Copyright (c) 1994, Simon J. Gerraty.  *        *      This is free software.  It comes with NO WARRANTY.  *      Permission to use, modify and distribute this source code   *      is granted subject to the following conditions.  *      1/ that the above copyright notice and this notice   *      are preserved in all copies and that due credit be given   *      to the author.    *      2/ that any changes to this code are clearly commented   *      as such so that the author does not get blamed for bugs   *      other than his own.  *        *      Please send copies of changes and bug-fixes to:  *      sjg@crufty.net  */
end_comment

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|sun386
end_ifdef

begin_define
define|#
directive|define
name|UNION_WAIT
end_define

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|x
parameter_list|)
value|((&x)->w_retcode)
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|x
parameter_list|)
value|((&x)->w_termsig)
end_define

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|x
parameter_list|)
value|((&x)->w_stopsig)
end_define

begin_define
define|#
directive|define
name|HAVE_WAIT4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WAIT_T
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|UNION_WAIT
end_ifdef

begin_define
define|#
directive|define
name|WAIT_T
value|union wait
end_define

begin_define
define|#
directive|define
name|WAIT_STATUS
parameter_list|(
name|x
parameter_list|)
value|(x).w_status
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WAIT_T
value|int
end_define

begin_define
define|#
directive|define
name|WAIT_STATUS
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|_X
parameter_list|)
value|(((int)(_X)>>8)&0377)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSTOPPED
end_ifndef

begin_define
define|#
directive|define
name|WSTOPPED
value|0177
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSTOPSIG
end_ifndef

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|x
parameter_list|)
value|WSTOPPED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNION_WAIT
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|WSET_STOPCODE
end_ifndef

begin_define
define|#
directive|define
name|WSET_STOPCODE
parameter_list|(
name|x
parameter_list|,
name|sig
parameter_list|)
value|((&x)->w_stopsig = (sig))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSET_EXITCODE
end_ifndef

begin_define
define|#
directive|define
name|WSET_EXITCODE
parameter_list|(
name|x
parameter_list|,
name|ret
parameter_list|,
name|sig
parameter_list|)
value|((&x)->w_termsig = (sig), (&x)->w_retcode = (ret))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|WSET_STOPCODE
end_ifndef

begin_define
define|#
directive|define
name|WSET_STOPCODE
parameter_list|(
name|x
parameter_list|,
name|sig
parameter_list|)
value|((x) = ((sig)<< 8) | 0177)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSET_EXITCODE
end_ifndef

begin_define
define|#
directive|define
name|WSET_EXITCODE
parameter_list|(
name|x
parameter_list|,
name|ret
parameter_list|,
name|sig
parameter_list|)
value|((x) = (ret<< 8) | (sig))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_WAITPID
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_WAIT4
end_ifdef

begin_define
define|#
directive|define
name|waitpid
parameter_list|(
name|pid
parameter_list|,
name|statusp
parameter_list|,
name|flags
parameter_list|)
value|wait4(pid, statusp, flags, (char *)0)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_WAIT3
end_ifdef

begin_define
define|#
directive|define
name|waitpid
parameter_list|(
name|pid
parameter_list|,
name|statusp
parameter_list|,
name|flags
parameter_list|)
value|wait3(statusp, flags, (char *)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

