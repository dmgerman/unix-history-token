begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | grep TheGlobal | not grep weak
end_comment

begin_decl_stmt
specifier|extern
name|int
name|TheGlobal
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|foo
parameter_list|()
block|{
return|return
name|TheGlobal
return|;
block|}
end_function

begin_decl_stmt
name|int
name|TheGlobal
init|=
literal|1
decl_stmt|;
end_decl_stmt

end_unit

