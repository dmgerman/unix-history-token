begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)user.h	7.17 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_comment
comment|/*  * Per process structure containing data that  * isn't needed in core when the process is swapped out.  */
end_comment

begin_struct
struct|struct
name|user
block|{
name|struct
name|pcb
name|u_pcb
decl_stmt|;
name|struct
name|proc
modifier|*
name|u_procp
decl_stmt|;
comment|/* pointer to proc structure XXX */
name|label_t
name|u_ssave
decl_stmt|;
comment|/* label variable for swapping XXX */
define|#
directive|define
name|curproc
value|u.u_procp
comment|/* XXX */
name|struct
name|sigacts
name|u_sigacts
decl_stmt|;
comment|/* p_sigacts points here (use it!) */
name|struct
name|pstats
name|u_stats
decl_stmt|;
comment|/* rusage, profiling& timers */
comment|/* 1.6 - resource controls */
name|int
name|u_spare
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* u_error codes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|user
name|u
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|swaputl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|forkutl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|xswaputl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|xswap2utl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|pushutl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
modifier|*
name|vfutl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

