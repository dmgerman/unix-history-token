begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_include
include|#
directive|include
file|<unistd.h>
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
name|usleep
argument_list|(
literal|1000000
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
comment|// CHECK:      WARNING: ThreadSanitizer: data race
end_comment

begin_comment
comment|// CHECK-NEXT:   Write of size 4 at {{.*}} by thread 1:
end_comment

begin_comment
comment|// CHECK-NEXT:     #0 foo1 {{.*}}simple_stack.c:8{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #1 bar1 {{.*}}simple_stack.c:13{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #2 Thread1 {{.*}}simple_stack.c:27{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:   Previous read of size 4 at {{.*}} by thread 2:
end_comment

begin_comment
comment|// CHECK-NEXT:     #0 foo2 {{.*}}simple_stack.c:17{{(:26)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #1 bar2 {{.*}}simple_stack.c:22{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #2 Thread2 {{.*}}simple_stack.c:32{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:   Thread 1 (running) created at:
end_comment

begin_comment
comment|// CHECK-NEXT:     #0 pthread_create {{.*}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #1 StartThread {{.*}}simple_stack.c:37{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #2 main {{.*}}simple_stack.c:42{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:   Thread 2 ({{.*}}) created at:
end_comment

begin_comment
comment|// CHECK-NEXT:     #0 pthread_create {{.*}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #1 StartThread {{.*}}simple_stack.c:37{{(:3)?}} ({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:     #2 main {{.*}}simple_stack.c:43{{(:3)?}} ({{.*}})
end_comment

end_unit

