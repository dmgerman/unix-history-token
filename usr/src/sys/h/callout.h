begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)callout.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * The callout structure is for  * a routine arranging  * to be called by the clock interrupt  * (clock.c) with a specified argument,  * in a specified amount of time.  * Used, for example, to time tab  * delays on typewriters.  */
end_comment

begin_struct
struct|struct
name|callout
block|{
name|int
name|c_time
decl_stmt|;
comment|/* incremental time */
name|caddr_t
name|c_arg
decl_stmt|;
comment|/* argument to routine */
name|int
function_decl|(
modifier|*
name|c_func
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine */
name|struct
name|callout
modifier|*
name|c_next
decl_stmt|;
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

