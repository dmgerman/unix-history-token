begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_tsan -O1 %s -o %t&& %deflake %run %t | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_decl_stmt
name|pthread_mutex_t
name|Mtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Global
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
name|pthread_mutex_init
argument_list|(
operator|&
name|Mtx
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|Mtx
argument_list|)
expr_stmt|;
name|Global
operator|=
literal|42
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|Mtx
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
name|Mtx
argument_list|)
expr_stmt|;
name|Global
operator|=
literal|43
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|Mtx
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
name|pthread_t
name|t
index|[
literal|2
index|]
decl_stmt|;
name|pthread_create
argument_list|(
operator|&
name|t
index|[
literal|0
index|]
argument_list|,
name|NULL
argument_list|,
name|Thread1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|pthread_create
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|,
name|NULL
argument_list|,
name|Thread2
argument_list|,
name|NULL
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
name|pthread_mutex_destroy
argument_list|(
operator|&
name|Mtx
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK:      WARNING: ThreadSanitizer: data race
end_comment

begin_comment
comment|// CHECK-NEXT:   Atomic read of size 1 at {{.*}} by thread T2:
end_comment

begin_comment
comment|// CHECK-NEXT:     #0 pthread_mutex_lock
end_comment

begin_comment
comment|// CHECK-NEXT:     #1 Thread2{{.*}} {{.*}}race_on_mutex.c:18{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK:        Previous write of size 1 at {{.*}} by thread T1:
end_comment

begin_comment
comment|// CHECK-NEXT:     #0 pthread_mutex_init {{.*}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #1 Thread1{{.*}} {{.*}}race_on_mutex.c:8{{(:3)?}} ({{.*}})
end_comment

end_unit

