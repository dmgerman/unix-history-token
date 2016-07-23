begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_esan_frag -O0 %s -o %t 2>&1
end_comment

begin_comment
comment|// RUN: %env_esan_opts=verbosity=1 %run %t 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
name|void
modifier|*
name|Map
init|=
name|mmap
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0x0000016000000000ULL
argument_list|,
literal|0x1000
argument_list|,
name|PROT_READ
argument_list|,
name|MAP_ANON
operator||
name|MAP_PRIVATE
operator||
name|MAP_FIXED
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|Map
operator|==
operator|(
name|void
operator|*
operator|)
operator|-
literal|1
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"map failed\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"mapped %p\n"
argument_list|,
name|Map
argument_list|)
expr_stmt|;
name|Map
operator|=
name|mmap
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0x0000016000000000ULL
argument_list|,
literal|0x1000
argument_list|,
name|PROT_READ
argument_list|,
name|MAP_ANON
operator||
name|MAP_PRIVATE
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"mapped %p\n"
argument_list|,
name|Map
argument_list|)
expr_stmt|;
comment|// CHECK:      in esan::initializeLibrary
comment|// (There can be a re-exec for stack limit here.)
comment|// CHECK:      Shadow scale=2 offset=0x440000000000
comment|// CHECK-NEXT: Shadow #0: [110000000000-114000000000) (256GB)
comment|// CHECK-NEXT: Shadow #1: [124000000000-12c000000000) (512GB)
comment|// CHECK-NEXT: Shadow #2: [148000000000-150000000000) (512GB)
comment|// CHECK-NEXT: mmap conflict: {{.*}}
comment|// CHECK-NEXT: map failed
comment|// CHECK-NEXT: mmap conflict: {{.*}}
comment|// CHECK-NEXT: mapped {{.*}}
comment|// CHECK-NEXT: in esan::finalizeLibrary
return|return
literal|0
return|;
block|}
end_function

end_unit

