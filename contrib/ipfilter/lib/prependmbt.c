begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * $Id: prependmbt.c,v 1.3.2.3 2012/07/22 08:04:24 darren_r Exp $  */
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_function
name|int
name|prependmbt
parameter_list|(
name|fin
parameter_list|,
name|m
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|mb_t
modifier|*
name|m
decl_stmt|;
block|{
name|m
operator|->
name|mb_next
operator|=
operator|*
name|fin
operator|->
name|fin_mp
expr_stmt|;
operator|*
name|fin
operator|->
name|fin_mp
operator|=
name|m
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

