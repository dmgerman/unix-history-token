begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -DBITCODE -emit-llvm-bc -o %t.bc %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -mlink-bitcode-file %t.bc -O3 -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-NO-BC %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple i386-pc-linux-gnu -DBITCODE -mlink-bitcode-file %t.bc -O3 -emit-llvm -o - %s 2>&1 | FileCheck -check-prefix=CHECK-BC %s
end_comment

begin_function_decl
name|int
name|f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BITCODE
end_ifdef

begin_comment
comment|// CHECK-BC: fatal error: cannot link module {{.*}}'f': symbol multiply defined
end_comment

begin_function
name|int
name|f
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|42
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|// CHECK-NO-BC-LABEL: define i32 @g
end_comment

begin_comment
comment|// CHECK-NO-BC: ret i32 42
end_comment

begin_function
name|int
name|g
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|f
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// CHECK-NO-BC-LABEL: define i32 @f
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

