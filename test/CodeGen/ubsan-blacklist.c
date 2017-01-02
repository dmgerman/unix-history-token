begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Verify ubsan doesn't emit checks for blacklisted functions and files
end_comment

begin_comment
comment|// RUN: echo "fun:hash"> %t-func.blacklist
end_comment

begin_comment
comment|// RUN: echo "src:%s" | sed -e 's/\\/\\\\/g'> %t-file.blacklist
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsanitize=unsigned-integer-overflow -emit-llvm %s -o - | FileCheck %s --check-prefix=DEFAULT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsanitize=unsigned-integer-overflow -fsanitize-blacklist=%t-func.blacklist -emit-llvm %s -o - | FileCheck %s --check-prefix=FUNC
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsanitize=unsigned-integer-overflow -fsanitize-blacklist=%t-file.blacklist -emit-llvm %s -o - | FileCheck %s --check-prefix=FILE
end_comment

begin_decl_stmt
name|unsigned
name|i
decl_stmt|;
end_decl_stmt

begin_comment
comment|// DEFAULT: @hash
end_comment

begin_comment
comment|// FUNC: @hash
end_comment

begin_comment
comment|// FILE: @hash
end_comment

begin_function
name|unsigned
name|hash
parameter_list|()
block|{
comment|// DEFAULT: call {{.*}}void @__ubsan
comment|// FUNC-NOT: call {{.*}}void @__ubsan
comment|// FILE-NOT: call {{.*}}void @__ubsan
return|return
name|i
operator|*
literal|37
return|;
block|}
end_function

begin_comment
comment|// DEFAULT: @add
end_comment

begin_comment
comment|// FUNC: @add
end_comment

begin_comment
comment|// FILE: @add
end_comment

begin_function
name|unsigned
name|add
parameter_list|()
block|{
comment|// DEFAULT: call {{.*}}void @__ubsan
comment|// FUNC: call {{.*}}void @__ubsan
comment|// FILE-NOT: call {{.*}}void @__ubsan
return|return
name|i
operator|+
literal|1
return|;
block|}
end_function

end_unit

