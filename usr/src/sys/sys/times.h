begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)times.h	7.4 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<machine/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_CLOCK_T_
end_ifdef

begin_typedef
typedef|typedef
name|_CLOCK_T_
name|clock_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_CLOCK_T_
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

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
name|clock_t
name|times
parameter_list|(
name|struct
name|tms
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|clock_t
name|times
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

