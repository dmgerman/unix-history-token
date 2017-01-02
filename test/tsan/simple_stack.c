begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"test.h"
end_include

begin_decl_stmt
name|int
name|Global
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|noinline
operator|)
argument_list|)
name|foo1
argument_list|()
block|{
name|Global
operator|=
literal|42
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|noinline
operator|)
argument_list|)
name|bar1
argument_list|()
block|{
specifier|volatile
name|int
name|tmp
init|=
literal|42
decl_stmt|;
operator|(
name|void
operator|)
name|tmp
expr_stmt|;
name|foo1
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|noinline
operator|)
argument_list|)
name|foo2
argument_list|()
block|{
specifier|volatile
name|int
name|v
init|=
name|Global
decl_stmt|;
operator|(
name|void
operator|)
name|v
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|noinline
operator|)
argument_list|)
name|bar2
argument_list|()
block|{
specifier|volatile
name|int
name|tmp
init|=
literal|42
decl_stmt|;
operator|(
name|void
operator|)
name|tmp
expr_stmt|;
name|foo2
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|void
modifier|*
name|Thread1
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
block|{
name|barrier_wait
argument_list|(
operator|&
name|barrier
argument_list|)
expr_stmt|;
name|bar1
argument_list|()
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|Thread2
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
block|{
name|bar2
argument_list|()
expr_stmt|;
name|barrier_wait
argument_list|(
operator|&
name|barrier
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|void
name|StartThread
parameter_list|(
name|pthread_t
modifier|*
name|t
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
name|pthread_create
argument_list|(
name|t
argument_list|,
name|NULL
argument_list|,
name|f
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|barrier_init
argument_list|(
operator|&
name|barrier
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|pthread_t
name|t
index|[
literal|2
index|]
decl_stmt|;
name|StartThread
argument_list|(
operator|&
name|t
index|[
literal|0
index|]
argument_list|,
name|Thread1
argument_list|)
expr_stmt|;
name|StartThread
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|,
name|Thread2
argument_list|)
expr_stmt|;
name|pthread_join
argument_list|(
name|t
index|[
literal|0
index|]
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|pthread_join
argument_list|(
name|t
index|[
literal|1
index|]
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// RUN: %clang_tsan -O1 %s -o %t&& %deflake %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Also check that functions instrumentation can be configured by either driver
end_comment

begin_comment
comment|// or legacy flags:
end_comment

begin_comment
comment|// RUN: %clangxx_tsan -O1 %s -o %t -fno-sanitize-thread-func-entry-exit&& %deflake %run %t 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FUNC-ENTRY-EXIT-OFF %s
end_comment

begin_comment
comment|// RUN: %clangxx_tsan -O1 %s -o %t -mllvm -tsan-instrument-func-entry-exit=0&& %deflake %run %t 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FUNC-ENTRY-EXIT-OFF %s
end_comment

begin_comment
comment|// CHECK:      WARNING: ThreadSanitizer: data race
end_comment

begin_comment
comment|// CHECK-NEXT:   Write of size 4 at {{.*}} by thread T1:
end_comment

begin_comment
comment|// CHECK-NEXT:     #0 foo1{{.*}} {{.*}}simple_stack.c:6{{(:10)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #1 bar1{{.*}} {{.*}}simple_stack.c:11{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #2 Thread1{{.*}} {{.*}}simple_stack.c:25{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK:        Previous read of size 4 at {{.*}} by thread T2:
end_comment

begin_comment
comment|// CHECK-NEXT:     #0 foo2{{.*}} {{.*}}simple_stack.c:15{{(:20)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #1 bar2{{.*}} {{.*}}simple_stack.c:20{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #2 Thread2{{.*}} {{.*}}simple_stack.c:30{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK:        Thread T1 (tid={{.*}}, running) created by main thread at:
end_comment

begin_comment
comment|// CHECK-NEXT:     #0 pthread_create {{.*}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #1 StartThread{{.*}} {{.*}}simple_stack.c:36{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #2 main{{.*}} {{.*}}simple_stack.c:42{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK:        Thread T2 ({{.*}}) created by main thread at:
end_comment

begin_comment
comment|// CHECK-NEXT:     #0 pthread_create {{.*}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #1 StartThread{{.*}} {{.*}}simple_stack.c:36{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #2 main{{.*}} {{.*}}simple_stack.c:43{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-FUNC-ENTRY-EXIT-OFF:      WARNING: ThreadSanitizer: data race
end_comment

begin_comment
comment|// CHECK-FUNC-ENTRY-EXIT-OFF-NEXT:   Write of size 4 at {{.*}} by thread T1:
end_comment

begin_comment
comment|// CHECK-FUNC-ENTRY-EXIT-OFF-NEXT:     #0 foo1{{.*}} {{.*}}simple_stack.c:6{{(:10)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-FUNC-ENTRY-EXIT-OFF:        Previous read of size 4 at {{.*}} by thread T2:
end_comment

begin_comment
comment|// CHECK-FUNC-ENTRY-EXIT-OFF-NEXT:     #0 foo2{{.*}} {{.*}}simple_stack.c:15{{(:20)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-FUNC-ENTRY-EXIT-OFF:        Thread T1 (tid={{.*}}, running) created by main thread at:
end_comment

begin_comment
comment|// CHECK-FUNC-ENTRY-EXIT-OFF-NEXT:     #0 pthread_create {{.*}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-FUNC-ENTRY-EXIT-OFF:        Thread T2 ({{.*}}) created by main thread at:
end_comment

begin_comment
comment|// CHECK-FUNC-ENTRY-EXIT-OFF-NEXT:     #0 pthread_create {{.*}} ({{.*}})
end_comment

end_unit

