begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)callout.h	7.2 (Berkeley) %G%  */
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
name|caddr_t
name|c_arg
decl_stmt|;
comment|/* function argument */
name|int
function_decl|(
modifier|*
name|c_func
function_decl|)
parameter_list|()
function_decl|;
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

