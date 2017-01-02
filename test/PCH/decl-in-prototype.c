begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that we serialize the enum decl in the function prototype somehow.
end_comment

begin_comment
comment|// These decls aren't serialized quite the same way as parameters.
end_comment

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

begin_comment
comment|// CHECK-LABEL: define {{.*}}i32 @main()
end_comment

begin_comment
comment|// CHECK:   ret i32 1
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

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(always_inline)
argument_list|)
name|f
argument_list|(
argument|enum { x
argument_list|,
argument|y } p
argument_list|)
block|{
return|return
name|y
return|;
block|}
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
name|f
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

