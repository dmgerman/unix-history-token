begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test recovery mode.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_asan -fsanitize-recover=address %s -o %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: env not %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %env_asan_opts=halt_on_error=true not %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %env_asan_opts=halt_on_error=false %run %t 2>&1 | FileCheck %s --check-prefix CHECK-RECOVER
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_decl_stmt
specifier|volatile
name|int
name|ten
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|char
name|x
index|[
literal|10
index|]
decl_stmt|;
comment|// CHECK: WRITE of size 11
comment|// CHECK-RECOVER: WRITE of size 11
name|memset
argument_list|(
name|x
argument_list|,
literal|0
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK-NOT: READ of size 1
comment|// CHECK-RECOVER: READ of size 1
specifier|volatile
name|int
name|res
init|=
name|x
index|[
name|ten
index|]
decl_stmt|;
comment|// CHECK-NOT: WRITE of size 1
comment|// CHECK-RECOVER: WRITE of size 1
name|x
index|[
name|ten
index|]
operator|=
name|res
operator|+
literal|3
expr_stmt|;
comment|// CHECK-NOT: READ of size 1
comment|// CHECK-RECOVER: READ of size 1
name|res
operator|=
name|x
index|[
name|ten
index|]
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

