begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	from: @(#)kern_exec.c	7.43 (Berkeley) 5/9/91  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"filedesc.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"mount.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_include
include|#
directive|include
file|"namei.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"seg.h"
end_include

begin_include
include|#
directive|include
file|"file.h"
end_include

begin_include
include|#
directive|include
file|"acct.h"
end_include

begin_include
include|#
directive|include
file|"exec.h"
end_include

begin_include
include|#
directive|include
file|"ktrace.h"
end_include

begin_include
include|#
directive|include
file|"resourcevar.h"
end_include

begin_include
include|#
directive|include
file|"machine/cpu.h"
end_include

begin_include
include|#
directive|include
file|"machine/reg.h"
end_include

begin_include
include|#
directive|include
file|"mman.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm_param.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm_map.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm_kern.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm_pager.h"
end_include

begin_include
include|#
directive|include
file|"signalvar.h"
end_include

begin_include
include|#
directive|include
file|"kinfo_proc.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HPUXCOMPAT
end_ifdef

begin_include
include|#
directive|include
file|"user.h"
end_include

begin_comment
comment|/* for pcb */
end_comment

begin_include
include|#
directive|include
file|"hp300/hpux/hpux_exec.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COPY_SIGCODE
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|sigcode
index|[]
decl_stmt|,
name|esigcode
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|szsigcode
value|(esigcode - sigcode)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|szsigcode
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * exec system call  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_expr_stmt
name|execve
argument_list|(
name|p
argument_list|,
name|uap
argument_list|,
name|retval
argument_list|)
specifier|register
expr|struct
name|proc
operator|*
name|p
expr_stmt|;
end_expr_stmt

begin_struct
specifier|register
struct|struct
name|args
block|{
name|char
modifier|*
name|fname
decl_stmt|;
name|char
modifier|*
modifier|*
name|argp
decl_stmt|;
name|char
modifier|*
modifier|*
name|envp
decl_stmt|;
block|}
modifier|*
name|uap
struct|;
end_struct

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_block

end_unit

