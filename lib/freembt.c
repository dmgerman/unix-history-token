begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * $Id: freembt.c,v 1.3.2.2 2012/07/22 08:04:24 darren_r Exp $  */
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_function
name|void
name|freembt
parameter_list|(
name|m
parameter_list|)
name|mb_t
modifier|*
name|m
decl_stmt|;
block|{
name|free
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

