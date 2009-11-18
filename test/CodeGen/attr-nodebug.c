begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -g -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: not grep 'call void @llvm.dbg.func.start' %t
end_comment

begin_function_decl
name|void
name|t1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(nodebug
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t1
parameter_list|()
block|{
name|int
name|a
init|=
literal|10
decl_stmt|;
name|a
operator|++
expr_stmt|;
block|}
end_function

end_unit

