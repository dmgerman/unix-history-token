begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	from: @(#)sys_process.c	7.22 (Berkeley) 5/11/91  */
end_comment

begin_define
define|#
directive|define
name|IPCREG
end_define

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
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
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"ptrace.h"
end_include

begin_include
include|#
directive|include
file|"machine/reg.h"
end_include

begin_include
include|#
directive|include
file|"machine/psl.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm_page.h"
end_include

begin_include
include|#
directive|include
file|"user.h"
end_include

begin_comment
comment|/*  * Process debugging system call.  */
end_comment

begin_macro
name|ptrace
argument_list|(
argument|curp
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|curp
decl_stmt|;
end_decl_stmt

begin_struct
specifier|register
struct|struct
name|args
block|{
name|int
name|req
decl_stmt|;
name|int
name|pid
decl_stmt|;
name|int
modifier|*
name|addr
decl_stmt|;
name|int
name|data
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

begin_expr_stmt
name|procxmt
argument_list|(
name|p
argument_list|)
specifier|register
expr|struct
name|proc
operator|*
name|p
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Enable process profiling system call.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|profil
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_struct
specifier|register
struct|struct
name|args
block|{
name|short
modifier|*
name|bufbase
decl_stmt|;
name|unsigned
name|bufsize
decl_stmt|;
name|unsigned
name|pcoffset
decl_stmt|;
name|unsigned
name|pcscale
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

