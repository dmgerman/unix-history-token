begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_comment
comment|/*  * Auxillary functions to aid portability to other systems.  * These are 4.4BSD routines that are often not found on other systems.  *  * !!!USE THIS FILE ONLY IF YOU ARE NOT RUNNING 4.4BSD!!!  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PREPOSIX
end_ifdef

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NO_RINDEX
end_ifdef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSDWAIT
end_ifdef

begin_define
define|#
directive|define
name|WAITARG_T
parameter_list|(
name|a
parameter_list|)
value|((int *)(a))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WAITARG_T
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SETPGID
end_ifdef

begin_define
define|#
directive|define
name|setpgrp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|setpgid((pid_t)(a), (pid_t)(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FD_COPY
end_ifndef

begin_define
define|#
directive|define
name|FD_COPY
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|memcpy((char *)t, (char *)f, sizeof(*(f)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NO_SNPRINTF
end_ifdef

begin_decl_stmt
name|int
name|snprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
name|str
operator|,
name|size_t
name|n
operator|,
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

