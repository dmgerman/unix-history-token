begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_esan_frag -O0 %s -o %t 2>&1
end_comment

begin_comment
comment|// RUN: %env_esan_opts="verbosity=1 log_exe_name=1" %run %t 2>&1 | FileCheck --check-prefix=%arch --check-prefix=CHECK %s
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
comment|// x86_64:      Shadow scale=2 offset=0x440000000000
comment|// x86_64-NEXT: Shadow #0: [110000000000-114000000000) (256GB)
comment|// x86_64-NEXT: Shadow #1: [124000000000-12c000000000) (512GB)
comment|// x86_64-NEXT: Shadow #2: [148000000000-150000000000) (512GB)
comment|// mips64:      Shadow scale=2 offset=0x4400000000
comment|// mips64-NEXT: Shadow #0: [1140000000-1180000000) (1GB)
comment|// mips64-NEXT: Shadow #1: [1380000000-13c0000000) (1GB)
comment|// mips64-NEXT: Shadow #2: [14c0000000-1500000000) (1GB)
comment|// CHECK: in esan::finalizeLibrary
comment|// CHECK: ==verbose-simple{{.*}}EfficiencySanitizer: total struct field access count = 0
return|return
literal|0
return|;
block|}
end_function

end_unit

