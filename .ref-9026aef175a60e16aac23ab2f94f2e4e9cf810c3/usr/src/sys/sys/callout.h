begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)callout.h	8.2 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|callout
block|{
name|struct
name|callout
modifier|*
name|c_next
decl_stmt|;
comment|/* next callout in queue */
name|void
modifier|*
name|c_arg
decl_stmt|;
comment|/* function argument */
name|void
argument_list|(
argument|*c_func
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* function to call */
name|int
name|c_time
decl_stmt|;
comment|/* ticks to the event */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|callout
modifier|*
name|callfree
decl_stmt|,
modifier|*
name|callout
decl_stmt|,
name|calltodo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncallout
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

