begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// cl.exe /c vars.c
end_comment

begin_comment
comment|// link /dll /nodefaultlib /entry:dllmain /export:var,@1,NONAME,DATA \
end_comment

begin_comment
comment|//   /export:fn /export:_name_with_underscore vars.obj
end_comment

begin_comment
comment|// will be exported by ordinal
end_comment

begin_decl_stmt
name|int
name|var
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// will be exported by name
end_comment

begin_function
name|int
name|fn
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|4
return|;
block|}
end_function

begin_comment
comment|// will be exported by name
end_comment

begin_function
name|int
name|_name_with_underscore
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|5
return|;
block|}
end_function

begin_function
name|int
name|dllmain
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

end_unit

