begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2007 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_function
name|void
name|printtqtable
parameter_list|(
name|table
parameter_list|)
name|ipftq_t
modifier|*
name|table
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|printf
argument_list|(
literal|"TCP Entries per state\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|IPF_TCP_NSTATES
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|" %5d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|IPF_TCP_NSTATES
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|" %5d"
argument_list|,
name|table
index|[
name|i
index|]
operator|.
name|ifq_ref
operator|-
literal|1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

