begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o %t
end_comment

begin_function
name|int
name|a
parameter_list|()
block|{
name|A
label|:
empty_stmt|;
specifier|static
name|void
modifier|*
name|a
init|=
operator|&&
name|A
decl_stmt|;
block|}
end_function

end_unit

