begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_dfsan -m64 %s -fsanitize-blacklist=%S/Inputs/flags_abilist.txt -mllvm -dfsan-debug-nonzero-labels -o %t&& %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_dfsan -m64 %s -fsanitize-blacklist=%S/Inputs/flags_abilist.txt -mllvm -dfsan-debug-nonzero-labels -o %t&& DFSAN_OPTIONS=warn_unimplemented=0 %run %t 2>&1 | count 0
end_comment

begin_comment
comment|// RUN: %clang_dfsan -m64 %s -fsanitize-blacklist=%S/Inputs/flags_abilist.txt -mllvm -dfsan-debug-nonzero-labels -o %t&& DFSAN_OPTIONS=warn_nonzero_labels=1 %run %t 2>&1 | FileCheck --check-prefix=CHECK-NONZERO %s
end_comment

begin_comment
comment|// Tests that flags work correctly.
end_comment

begin_include
include|#
directive|include
file|<sanitizer/dfsan_interface.h>
end_include

begin_function
name|int
name|f
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
init|=
literal|1
decl_stmt|;
name|dfsan_label
name|i_label
init|=
name|dfsan_create_label
argument_list|(
literal|"i"
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|dfsan_set_label
argument_list|(
name|i_label
argument_list|,
operator|&
name|i
argument_list|,
sizeof|sizeof
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
comment|// CHECK: WARNING: DataFlowSanitizer: call to uninstrumented function f
comment|// CHECK-NOT: WARNING: DataFlowSanitizer: saw nonzero label
comment|// CHECK-NONZERO: WARNING: DataFlowSanitizer: saw nonzero label
name|f
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

