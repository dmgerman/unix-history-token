begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.2 $ ** **  DBZ compatibility routines, for use if DBZ isn't patched */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_function
name|int
name|dbzwritethrough
parameter_list|(
name|value
parameter_list|)
name|int
name|value
decl_stmt|;
block|{
return|return
name|value
return|;
block|}
end_function

begin_function
name|long
name|dbztagmask
parameter_list|(
name|size
parameter_list|)
name|long
name|size
decl_stmt|;
block|{
return|return
name|size
return|;
block|}
end_function

end_unit

