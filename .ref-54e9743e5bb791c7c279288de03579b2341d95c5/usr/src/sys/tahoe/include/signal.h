begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986, 1989, 1991 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)signal.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Machine-dependent signal definitions  */
end_comment

begin_typedef
typedef|typedef
name|int
name|sig_atomic_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_comment
comment|/* codes for SIGILL, SIGFPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Information pushed on stack when a signal is delivered.  * This is used by the kernel to restore state following  * execution of the signal handler.  It is also made available  * to the handler to allow it to restore state properly if  * a non-standard exit is performed.  */
end_comment

begin_struct
struct|struct
name|sigcontext
block|{
name|int
name|sc_onstack
decl_stmt|;
comment|/* sigstack state to restore */
name|int
name|sc_mask
decl_stmt|;
comment|/* signal mask to restore */
name|int
name|sc_sp
decl_stmt|;
comment|/* sp to restore */
name|int
name|sc_fp
decl_stmt|;
comment|/* fp to restore */
name|int
name|sc_ap
decl_stmt|;
comment|/* ap to restore */
name|int
name|sc_pc
decl_stmt|;
comment|/* pc to restore */
name|int
name|sc_ps
decl_stmt|;
comment|/* psl to restore */
block|}
struct|;
end_struct

end_unit

