begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * netof - return the net address part of an ip address  *         (zero out host part)  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_function
name|u_int32
name|netof
parameter_list|(
name|u_int32
name|num
parameter_list|)
block|{
specifier|register
name|u_int32
name|netnum
decl_stmt|;
name|netnum
operator|=
name|num
expr_stmt|;
if|if
condition|(
name|IN_CLASSC
argument_list|(
name|netnum
argument_list|)
condition|)
name|netnum
operator|&=
name|IN_CLASSC_NET
expr_stmt|;
elseif|else
if|if
condition|(
name|IN_CLASSB
argument_list|(
name|netnum
argument_list|)
condition|)
name|netnum
operator|&=
name|IN_CLASSB_NET
expr_stmt|;
else|else
comment|/* treat all other like class A */
name|netnum
operator|&=
name|IN_CLASSA_NET
expr_stmt|;
return|return
name|netnum
return|;
block|}
end_function

end_unit

