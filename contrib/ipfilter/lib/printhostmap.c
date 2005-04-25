begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_function
name|void
name|printhostmap
parameter_list|(
name|hmp
parameter_list|,
name|hv
parameter_list|)
name|hostmap_t
modifier|*
name|hmp
decl_stmt|;
name|u_int
name|hv
decl_stmt|;
block|{
name|printf
argument_list|(
literal|"%s,"
argument_list|,
name|inet_ntoa
argument_list|(
name|hmp
operator|->
name|hm_srcip
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s -> "
argument_list|,
name|inet_ntoa
argument_list|(
name|hmp
operator|->
name|hm_dstip
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s "
argument_list|,
name|inet_ntoa
argument_list|(
name|hmp
operator|->
name|hm_mapip
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"(use = %d hv = %u)\n"
argument_list|,
name|hmp
operator|->
name|hm_ref
argument_list|,
name|hv
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

