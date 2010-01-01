begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -Wno-return-type -fsyntax-only -verify
end_comment

begin_function
name|int
name|t14
parameter_list|()
block|{
return|return;
block|}
end_function

begin_function
name|void
name|t15
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

end_unit

