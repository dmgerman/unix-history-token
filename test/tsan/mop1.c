begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_tsan -O1 %s -o %t&& %deflake %run %t | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_comment
comment|// We want to establish the following sequence of accesses to X:
end_comment

begin_comment
comment|// - main thread writes X
end_comment

begin_comment
comment|// - thread2 reads X, this read happens-before the write in main thread
end_comment

begin_comment
comment|// - thread1 reads X, this read is concurrent with the write in main thread
end_comment

begin_comment
comment|// Write in main thread and read in thread1 should be detected as a race.
end_comment

begin_comment
comment|// Previously tsan replaced write by main thread with read by thread1,
end_comment

begin_comment
comment|// as the result the race was not detected.
end_comment

begin_decl_stmt
specifier|volatile
name|long
name|X
decl_stmt|,
name|Y
decl_stmt|,
name|Z
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
name|barrier_wait
argument_list|(
operator|&
name|barrier
argument_list|)
expr_stmt|;
name|barrier_wait
argument_list|(
operator|&
name|barrier
argument_list|)
expr_stmt|;
name|Y
operator|=
name|X
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
name|Z
operator|=
name|X
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
literal|0
argument_list|,
name|Thread1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|X
operator|=
literal|42
expr_stmt|;
name|barrier_wait
argument_list|(
operator|&
name|barrier
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
literal|0
argument_list|,
name|Thread2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_join
argument_list|(
name|t
index|[
literal|0
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_join
argument_list|(
name|t
index|[
literal|1
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: WARNING: ThreadSanitizer: data race
end_comment

end_unit

