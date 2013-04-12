begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"ldns/config.h"
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
name|ldns_rr
modifier|*
name|rr
init|=
name|ldns_rr_new
argument_list|()
decl_stmt|;
name|ldns_rr_free
argument_list|(
name|rr
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

