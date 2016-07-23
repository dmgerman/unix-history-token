begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_esan_frag -O0 %s -o %t 2>&1
end_comment

begin_comment
comment|// RUN: %env_esan_opts="verbosity=1 log_exe_name=1" %run %t 2>&1 | FileCheck %s
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
comment|// CHECK:      in esan::initializeLibrary
comment|// (There can be a re-exec for stack limit here.)
comment|// CHECK:      Shadow scale=2 offset=0x440000000000
comment|// CHECK-NEXT: Shadow #0: [110000000000-114000000000) (256GB)
comment|// CHECK-NEXT: Shadow #1: [124000000000-12c000000000) (512GB)
comment|// CHECK-NEXT: Shadow #2: [148000000000-150000000000) (512GB)
comment|// CHECK-NEXT: in esan::finalizeLibrary
comment|// CHECK-NEXT: ==verbose-simple{{.*}}EfficiencySanitizer: total struct field access count = 0
return|return
literal|0
return|;
block|}
end_function

end_unit

