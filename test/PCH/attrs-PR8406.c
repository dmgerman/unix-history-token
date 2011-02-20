begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %s -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -emit-llvm -o - %s | FileCheck %s
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_struct
struct|struct
name|Bar
block|{
comment|// CHECK: align 512
name|int
name|buffer
index|[
literal|123
index|]
name|__attribute__
argument_list|(
operator|(
name|__aligned__
argument_list|(
literal|512
argument_list|)
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_function
name|void
name|foo
parameter_list|()
block|{
name|struct
name|Bar
name|bar
decl_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

