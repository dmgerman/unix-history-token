begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * defint - if dp is null, default to def; otherwise, convert to integer.  *  Note that *lp gets the value.  */
end_comment

begin_macro
name|defint
argument_list|(
argument|dp
argument_list|,
argument|lp
argument_list|,
argument|def
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|descrip
modifier|*
name|dp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
modifier|*
name|lp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|def
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|DeRef
argument_list|(
argument|*dp
argument_list|)
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
name|lp
operator|=
operator|(
name|long
operator|)
name|def
expr_stmt|;
return|return
literal|1
return|;
block|}
if|if
condition|(
name|cvint
argument_list|(
name|dp
argument_list|,
name|lp
argument_list|)
operator|==
name|NULL
condition|)
name|runerr
argument_list|(
literal|101
argument_list|,
name|dp
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

end_unit

