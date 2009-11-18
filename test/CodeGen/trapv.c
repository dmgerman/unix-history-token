begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -ftrapv %s -emit-llvm -o %t
end_comment

begin_comment
comment|// RUN: grep "__overflow_handler" %t | count 2
end_comment

begin_decl_stmt
name|unsigned
name|int
name|ui
decl_stmt|,
name|uj
decl_stmt|,
name|uk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|ui
operator|=
name|uj
operator|+
name|uk
expr_stmt|;
name|i
operator|=
name|j
operator|+
name|k
expr_stmt|;
block|}
end_function

end_unit

