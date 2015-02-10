begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clangxx_tsan %s -o %t
end_comment

begin_comment
comment|// RUN:                                 not %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: TSAN_OPTIONS=detect_deadlocks=1 not %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: TSAN_OPTIONS=detect_deadlocks=0     %run %t 2>&1 | FileCheck %s --check-prefix=DISABLED
end_comment

begin_comment
comment|// RUN: echo "deadlock:main"> %t.supp
end_comment

begin_comment
comment|// RUN: TSAN_OPTIONS="suppressions='%t.supp'" %run %t 2>&1 | FileCheck %s --check-prefix=DISABLED
end_comment

begin_comment
comment|// RUN: echo "deadlock:zzzz"> %t.supp
end_comment

begin_comment
comment|// RUN: TSAN_OPTIONS="suppressions='%t.supp'" not %run %t 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|pthread_mutex_t
name|mu1
decl_stmt|,
name|mu2
decl_stmt|;
name|pthread_mutex_init
argument_list|(
operator|&
name|mu1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|pthread_mutex_init
argument_list|(
operator|&
name|mu2
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// mu1 => mu2
name|pthread_mutex_lock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|mu2
argument_list|)
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mu2
argument_list|)
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
comment|// mu2 => mu1
name|pthread_mutex_lock
argument_list|(
operator|&
name|mu2
argument_list|)
expr_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
comment|// CHECK: ThreadSanitizer: lock-order-inversion (potential deadlock)
comment|// DISABLED-NOT: ThreadSanitizer
comment|// DISABLED: PASS
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mu2
argument_list|)
expr_stmt|;
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mu2
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"PASS\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

