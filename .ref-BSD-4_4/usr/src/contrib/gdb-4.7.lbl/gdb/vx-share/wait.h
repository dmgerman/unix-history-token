begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* wait.h - header file for remote wait call */
end_comment

begin_comment
comment|/*  Copyright 1992 Free Software Foundation, Inc.      This code was donated by Wind River Systems, Inc. */
end_comment

begin_comment
comment|/* modification history -------------------- 01a,05jun90,llk  borrowed. */
end_comment

begin_comment
comment|/* Define how to access the structure that the wait system call stores.    On many systems, there is a structure defined for this.    But on vanilla-ish USG systems there is not.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_WAIT_STRUCT
end_ifndef

begin_define
define|#
directive|define
name|WAITTYPE
value|int
end_define

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|w
parameter_list|)
value|(((w)&0377) == 0177)
end_define

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|w
parameter_list|)
value|(((w)&0377) != 0177&& ((w)&~0377) == 0)
end_define

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|w
parameter_list|)
value|(((w)&0377) == 0)
end_define

begin_define
define|#
directive|define
name|WRETCODE
parameter_list|(
name|w
parameter_list|)
value|((w)>> 8)
end_define

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|w
parameter_list|)
value|((w)>> 8)
end_define

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|w
parameter_list|)
value|(((w)&0200) != 0)
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|w
parameter_list|)
value|((w)& 0177)
end_define

begin_define
define|#
directive|define
name|WSETEXIT
parameter_list|(
name|w
parameter_list|,
name|status
parameter_list|)
value|((w) = (status))
end_define

begin_define
define|#
directive|define
name|WSETSTOP
parameter_list|(
name|w
parameter_list|,
name|sig
parameter_list|)
value|((w) = (0177 | ((sig)<< 8)))
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|FALSE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|ORIG
end_ifndef

begin_comment
comment|/* don't include sys/wait.h */
end_comment

begin_else
else|#
directive|else
else|ORIG
end_else

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
endif|ORIG
end_endif

begin_endif
endif|#
directive|endif
endif|FALSE
end_endif

begin_define
define|#
directive|define
name|WAITTYPE
value|union wait
end_define

begin_define
define|#
directive|define
name|WRETCODE
parameter_list|(
name|w
parameter_list|)
value|(w).w_retcode
end_define

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|w
parameter_list|)
value|(w).w_stopsig
end_define

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|w
parameter_list|)
value|(w).w_coredump
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|w
parameter_list|)
value|(w).w_termsig
end_define

begin_define
define|#
directive|define
name|WSETEXIT
parameter_list|(
name|w
parameter_list|,
name|status
parameter_list|)
value|((w).w_status = (status))
end_define

begin_define
define|#
directive|define
name|WSETSTOP
parameter_list|(
name|w
parameter_list|,
name|sig
parameter_list|)
define|\
value|((w).w_stopsig = (sig), (w).w_coredump = 0, (w).w_termsig = 0177)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

