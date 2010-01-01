begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep '@g0 = external hidden constant i32' %t
end_comment

begin_comment
comment|// RUN: grep '@g1 = hidden constant i32 1' %t
end_comment

begin_decl_stmt
name|__private_extern__
specifier|const
name|int
name|g0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
specifier|const
name|int
name|g1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|g0
return|;
block|}
end_function

end_unit

