begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1990 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	from: @(#)kern_physio.c	7.20 (Berkeley) 5/11/91  */
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
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"seg.h"
end_include

begin_include
include|#
directive|include
file|"trace.h"
end_include

begin_include
include|#
directive|include
file|"map.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"specdev.h"
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This routine does raw device I/O for a user process.  *  * If the user has the proper access privileges, the process is  * marked 'delayed unlock' and the pages involved in the I/O are  * faulted and locked. After the completion of the I/O, the pages  * are unlocked.  */
end_comment

begin_macro
name|physio
argument_list|(
argument|strat
argument_list|,
argument|bp
argument_list|,
argument|dev
argument_list|,
argument|rw
argument_list|,
argument|mincnt
argument_list|,
argument|uio
argument_list|)
end_macro

begin_function_decl
name|int
function_decl|(
modifier|*
name|strat
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|register
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rw
decl_stmt|;
end_decl_stmt

begin_function_decl
name|u_int
function_decl|(
modifier|*
name|mincnt
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|EIO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Calculate the maximum size of I/O request that can be requested  * in a single operation. This limit is necessary to prevent a single  * process from being able to lock more than a fixed amount of memory  * in the kernel.  */
end_comment

begin_function
name|u_int
name|minphys
parameter_list|(
name|bp
parameter_list|)
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_function

begin_comment
comment|/*  * Do a read on a device for a user process.  */
end_comment

begin_macro
name|rawread
argument_list|(
argument|dev
argument_list|,
argument|uio
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|physio
argument_list|(
name|cdevsw
index|[
name|major
argument_list|(
name|dev
argument_list|)
index|]
operator|.
name|d_strategy
argument_list|,
operator|(
expr|struct
name|buf
operator|*
operator|)
name|NULL
argument_list|,
name|dev
argument_list|,
name|B_READ
argument_list|,
name|minphys
argument_list|,
name|uio
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Do a write on a device for a user process.  */
end_comment

begin_macro
name|rawwrite
argument_list|(
argument|dev
argument_list|,
argument|uio
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|physio
argument_list|(
name|cdevsw
index|[
name|major
argument_list|(
name|dev
argument_list|)
index|]
operator|.
name|d_strategy
argument_list|,
operator|(
expr|struct
name|buf
operator|*
operator|)
name|NULL
argument_list|,
name|dev
argument_list|,
name|B_WRITE
argument_list|,
name|minphys
argument_list|,
name|uio
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

