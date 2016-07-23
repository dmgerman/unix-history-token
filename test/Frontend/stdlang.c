begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x cuda -std=c++11 -DCUDA %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x cl -DOPENCL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x cl -cl-std=cl -DOPENCL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x cl -cl-std=cl1.1 -DOPENCL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x cl -cl-std=cl1.2 -DOPENCL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x cl -cl-std=cl2.0 -DOPENCL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x cl -cl-std=CL -DOPENCL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x cl -cl-std=CL1.1 -DOPENCL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x cl -cl-std=CL1.2 -DOPENCL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x cl -cl-std=CL2.0 -DOPENCL %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -x cl -std=c99 -DOPENCL %s 2>&1 | FileCheck --check-prefix=CHECK-C99 %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -x cl -cl-std=invalid -DOPENCL %s 2>&1 | FileCheck --check-prefix=CHECK-INVALID %s
end_comment

begin_comment
comment|// CHECK-C99: error: invalid argument '-std=c99' not allowed with 'OpenCL'
end_comment

begin_comment
comment|// CHECK-INVALID: error: invalid value 'invalid' in '-cl-std=invalid'
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CUDA
argument_list|)
end_if

begin_macro
name|__attribute__
argument_list|(
argument|(device)
argument_list|)
end_macro

begin_function_decl
name|void
name|f_device
parameter_list|()
function_decl|;
end_function_decl

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OPENCL
argument_list|)
end_elif

begin_function_decl
name|kernel
name|void
name|func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

