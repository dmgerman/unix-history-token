begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_include
include|#
directive|include
file|"kmem.h"
end_include

begin_function
name|int
name|kmemcpywrap
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|size
parameter_list|)
name|void
modifier|*
name|from
decl_stmt|,
decl|*
name|to
decl_stmt|;
end_function

begin_decl_stmt
name|size_t
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|ret
decl_stmt|;
name|ret
operator|=
name|kmemcpy
argument_list|(
operator|(
name|caddr_t
operator|)
name|to
argument_list|,
operator|(
name|u_long
operator|)
name|from
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

end_unit

