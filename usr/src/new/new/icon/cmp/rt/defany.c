begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * defany(dp,def) - if dp is null, default to def.  */
end_comment

begin_macro
name|defany
argument_list|(
argument|dp
argument_list|,
argument|def
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|descrip
modifier|*
name|dp
decl_stmt|,
modifier|*
name|def
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|deref
argument_list|(
name|dp
argument_list|)
expr_stmt|;
if|if
condition|(
name|NULLDESC
argument_list|(
operator|*
name|dp
argument_list|)
condition|)
block|{
operator|*
name|dp
operator|=
operator|*
name|def
expr_stmt|;
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_block

end_unit

