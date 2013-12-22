begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fno-builtin -emit-llvm -o - %s -triple i386-unknown-unknown | FileCheck -check-prefix CHECK-YES %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s -triple i386-unknown-unknown | FileCheck -check-prefix CHECK-NO %s
end_comment

begin_function_decl
specifier|extern
name|float
name|crealf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|creal
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|double
name|creall
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|float
name|cimagf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|cimag
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|double
name|cimagl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|double
name|test_creal
parameter_list|(
name|double
specifier|_Complex
name|z
parameter_list|)
block|{
return|return
name|creal
argument_list|(
name|z
argument_list|)
return|;
comment|// CHECK-NO-NOT: call double @creal
comment|// CHECK-YES: call double @creal
block|}
end_function

begin_function
name|long
name|double
name|test_creall
parameter_list|(
name|double
specifier|_Complex
name|z
parameter_list|)
block|{
return|return
name|creall
argument_list|(
name|z
argument_list|)
return|;
comment|// CHECK-NO-NOT: call x86_fp80 @creall
comment|// CHECK-YES: call x86_fp80 @creall
block|}
end_function

begin_function
name|float
name|test_crealf
parameter_list|(
name|double
specifier|_Complex
name|z
parameter_list|)
block|{
return|return
name|crealf
argument_list|(
name|z
argument_list|)
return|;
comment|// CHECK-NO-NOT: call float @crealf
comment|// CHECK-YES: call float @crealf
block|}
end_function

begin_function
name|double
name|test_cimag
parameter_list|(
name|double
specifier|_Complex
name|z
parameter_list|)
block|{
return|return
name|cimag
argument_list|(
name|z
argument_list|)
return|;
comment|// CHECK-NO-NOT: call double @cimag
comment|// CHECK-YES: call double @cimag
block|}
end_function

begin_function
name|long
name|double
name|test_cimagl
parameter_list|(
name|double
specifier|_Complex
name|z
parameter_list|)
block|{
return|return
name|cimagl
argument_list|(
name|z
argument_list|)
return|;
comment|// CHECK-NO-NOT: call x86_fp80 @cimagl
comment|// CHECK-YES: call x86_fp80 @cimagl
block|}
end_function

begin_function
name|float
name|test_cimagf
parameter_list|(
name|double
specifier|_Complex
name|z
parameter_list|)
block|{
return|return
name|cimagf
argument_list|(
name|z
argument_list|)
return|;
comment|// CHECK-NO-NOT: call float @cimagf
comment|// CHECK-YES: call float @cimagf
block|}
end_function

end_unit

