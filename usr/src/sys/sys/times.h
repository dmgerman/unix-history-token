begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)times.h	8.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIMES_H_
end_ifndef

begin_define
define|#
directive|define
name|_TIMES_H_
end_define

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_CLOCK_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_CLOCK_T_
name|clock_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_CLOCK_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|tms
block|{
name|clock_t
name|tms_utime
decl_stmt|;
comment|/* User CPU time */
name|clock_t
name|tms_stime
decl_stmt|;
comment|/* System CPU time */
name|clock_t
name|tms_cutime
decl_stmt|;
comment|/* User CPU time of terminated child procs */
name|clock_t
name|tms_cstime
decl_stmt|;
comment|/* System CPU time of terminated child procs */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|clock_t
name|times
name|__P
argument_list|(
operator|(
expr|struct
name|tms
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TIMES_H_ */
end_comment

end_unit

