begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pdma.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_struct
struct|struct
name|pdma
block|{
name|struct
name|dzdevice
modifier|*
name|p_addr
decl_stmt|;
name|char
modifier|*
name|p_mem
decl_stmt|;
name|char
modifier|*
name|p_end
decl_stmt|;
name|int
name|p_arg
decl_stmt|;
name|int
function_decl|(
modifier|*
name|p_fcn
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

end_unit

