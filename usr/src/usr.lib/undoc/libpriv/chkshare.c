begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)chkshare.c	4.1	(Melbourne)	82/01/25	*/
end_comment

begin_macro
name|chkshare
argument_list|(
argument|share
argument_list|,
argument|uid
argument_list|)
end_macro

begin_decl_stmt
name|float
name|share
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* eventually, we check whether its legal for someone 	   with a share as given to log on now */
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

end_unit

