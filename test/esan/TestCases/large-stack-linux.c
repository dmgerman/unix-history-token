begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_esan_wset -O0 %s -o %t 2>&1
end_comment

begin_comment
comment|// RUN: %env_esan_opts="verbosity=1 record_snapshots=0" %run %t %t 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
specifier|static
name|void
name|testChildStackLimit
parameter_list|(
name|rlim_t
name|StackLimit
parameter_list|,
name|char
modifier|*
name|ToRun
parameter_list|)
block|{
name|int
name|Res
decl_stmt|;
name|struct
name|rlimit
name|Limit
decl_stmt|;
name|Limit
operator|.
name|rlim_cur
operator|=
name|RLIM_INFINITY
expr_stmt|;
name|Limit
operator|.
name|rlim_max
operator|=
name|RLIM_INFINITY
expr_stmt|;
name|Res
operator|=
name|setrlimit
argument_list|(
name|RLIMIT_STACK
argument_list|,
operator|&
name|Limit
argument_list|)
expr_stmt|;
if|if
condition|(
name|Res
operator|!=
literal|0
condition|)
block|{
comment|// Probably our environment had a large limit and we ourselves got
comment|// re-execed and can no longer raise our limit.
comment|// We have to bail and emulate the regular test.
comment|// We'd prefer to have branches in our FileCheck output to ensure the
comment|// initial program was re-execed but this is the best we can do for now.
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"in esan::initializeLibrary\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"==1234==The stack size limit is beyond the maximum supported.\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Re-execing with a stack size below 1TB.\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"in esan::initializeLibrary\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"done\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"in esan::finalizeLibrary\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|pid_t
name|Child
init|=
name|fork
argument_list|()
decl_stmt|;
name|assert
argument_list|(
name|Child
operator|>=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|Child
operator|>
literal|0
condition|)
block|{
name|pid_t
name|WaitRes
init|=
name|waitpid
argument_list|(
name|Child
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|WaitRes
operator|==
name|Child
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|char
modifier|*
name|Args
index|[
literal|2
index|]
decl_stmt|;
name|Args
index|[
literal|0
index|]
operator|=
name|ToRun
expr_stmt|;
name|Args
index|[
literal|1
index|]
operator|=
name|NULL
expr_stmt|;
name|Res
operator|=
name|execv
argument_list|(
name|ToRun
argument_list|,
name|Args
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// Should not be reached.
block|}
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
comment|// The path to the program to exec must be passed in the first time.
if|if
condition|(
name|argc
operator|==
literal|2
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Testing child with infinite stack\n"
argument_list|)
expr_stmt|;
name|testChildStackLimit
argument_list|(
name|RLIM_INFINITY
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Testing child with 1TB stack\n"
argument_list|)
expr_stmt|;
name|testChildStackLimit
argument_list|(
literal|1ULL
operator|<<
literal|40
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"done\n"
argument_list|)
expr_stmt|;
comment|// CHECK:      in esan::initializeLibrary
comment|// CHECK:      Testing child with infinite stack
comment|// CHECK-NEXT: in esan::initializeLibrary
comment|// CHECK-NEXT: =={{[0-9]+}}==The stack size limit is beyond the maximum supported.
comment|// CHECK-NEXT: Re-execing with a stack size below 1TB.
comment|// CHECK-NEXT: in esan::initializeLibrary
comment|// CHECK:      done
comment|// CHECK:      in esan::finalizeLibrary
comment|// CHECK:      Testing child with 1TB stack
comment|// CHECK-NEXT: in esan::initializeLibrary
comment|// CHECK-NEXT: =={{[0-9]+}}==The stack size limit is beyond the maximum supported.
comment|// CHECK-NEXT: Re-execing with a stack size below 1TB.
comment|// CHECK-NEXT: in esan::initializeLibrary
comment|// CHECK:      done
comment|// CHECK-NEXT: in esan::finalizeLibrary
comment|// CHECK:      done
comment|// CHECK-NEXT: in esan::finalizeLibrary
return|return
literal|0
return|;
block|}
end_function

end_unit

