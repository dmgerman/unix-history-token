begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  */
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_function
name|void
name|printdstlistpolicy
parameter_list|(
name|policy
parameter_list|)
name|ippool_policy_t
name|policy
decl_stmt|;
block|{
switch|switch
condition|(
name|policy
condition|)
block|{
case|case
name|IPLDP_NONE
case|:
name|PRINTF
argument_list|(
literal|"none"
argument_list|)
expr_stmt|;
break|break;
case|case
name|IPLDP_ROUNDROBIN
case|:
name|PRINTF
argument_list|(
literal|"round-robin"
argument_list|)
expr_stmt|;
break|break;
case|case
name|IPLDP_CONNECTION
case|:
name|PRINTF
argument_list|(
literal|"weighting connection"
argument_list|)
expr_stmt|;
break|break;
case|case
name|IPLDP_RANDOM
case|:
name|PRINTF
argument_list|(
literal|"random"
argument_list|)
expr_stmt|;
break|break;
default|default :
break|break;
block|}
block|}
end_function

end_unit

