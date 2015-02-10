begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_tsan -O1 %s -o %t
end_comment

begin_comment
comment|// RUN: %deflake %run %t | FileCheck %s --check-prefix=CHECK-NOZUPP
end_comment

begin_comment
comment|// RUN: TSAN_OPTIONS="suppressions='%s.supp' print_suppressions=1" %run %t 2>&1 | FileCheck %s --check-prefix=CHECK-SUPP
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_decl_stmt
name|int
modifier|*
name|mem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_mutex_t
name|mtx
decl_stmt|;
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
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|mem
argument_list|)
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx
argument_list|)
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
modifier|*
name|Thread2
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
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx
argument_list|)
expr_stmt|;
name|mem
index|[
literal|0
index|]
operator|=
literal|42
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
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
name|mem
operator|=
operator|(
name|int
operator|*
operator|)
name|malloc
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_t
name|t
decl_stmt|;
name|pthread_create
argument_list|(
operator|&
name|t
argument_list|,
name|NULL
argument_list|,
name|Thread1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|Thread2
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|pthread_join
argument_list|(
name|t
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-NOZUPP: WARNING: ThreadSanitizer: heap-use-after-free
end_comment

begin_comment
comment|// CHECK-NOZUPP:   Write of size 4 at {{.*}} by main thread{{.*}}:
end_comment

begin_comment
comment|// CHECK-NOZUPP:     #0 Thread2
end_comment

begin_comment
comment|// CHECK-NOZUPP:     #1 main
end_comment

begin_comment
comment|// CHECK-NOZUPP:   Previous write of size 8 at {{.*}} by thread T1{{.*}}:
end_comment

begin_comment
comment|// CHECK-NOZUPP:     #0 free
end_comment

begin_comment
comment|// CHECK-NOZUPP:     #{{(1|2)}} Thread1
end_comment

begin_comment
comment|// CHECK-NOZUPP: SUMMARY: ThreadSanitizer: heap-use-after-free{{.*}}Thread2
end_comment

begin_comment
comment|// CHECK-SUPP:   ThreadSanitizer: Matched 1 suppressions
end_comment

begin_comment
comment|// CHECK-SUPP:    1 race:^Thread2$
end_comment

end_unit

