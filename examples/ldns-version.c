begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ldns-version shows ldns's version   *  * (c) NLnet Labs, 2005 - 2008  * See the file LICENSE for the license  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<ldns/ldns.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|ldns_version
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

