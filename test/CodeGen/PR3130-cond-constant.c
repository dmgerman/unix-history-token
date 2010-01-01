begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_decl_stmt
name|int
name|a
init|=
literal|2.0
condition|?
literal|1
else|:
literal|2
decl_stmt|;
end_decl_stmt

end_unit

