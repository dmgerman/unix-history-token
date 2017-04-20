begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Regression test. Disabler should not depend on TSD validity.
end_comment

begin_comment
comment|// RUN: LSAN_BASE="report_objects=1:use_registers=0:use_stacks=0:use_globals=0:use_tls=1:use_ld_allocations=0"
end_comment

begin_comment
comment|// RUN: %clang_lsan %s -o %t
end_comment

begin_comment
comment|// RUN: %env_lsan_opts=$LSAN_BASE %run %t
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"sanitizer/lsan_interface.h"
end_include

begin_decl_stmt
name|pthread_key_t
name|key
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|key_destructor
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|__lsan_disable
argument_list|()
expr_stmt|;
name|void
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|1337
argument_list|)
decl_stmt|;
comment|// Break optimization.
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Test alloc: %p.\n"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|pthread_setspecific
argument_list|(
name|key
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|__lsan_enable
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
modifier|*
name|thread_func
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|int
name|res
init|=
name|pthread_setspecific
argument_list|(
name|key
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|1
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|res
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|res
init|=
name|pthread_key_create
argument_list|(
operator|&
name|key
argument_list|,
operator|&
name|key_destructor
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|res
operator|==
literal|0
argument_list|)
expr_stmt|;
name|pthread_t
name|thread_id
decl_stmt|;
name|res
operator|=
name|pthread_create
argument_list|(
operator|&
name|thread_id
argument_list|,
literal|0
argument_list|,
name|thread_func
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|res
operator|==
literal|0
argument_list|)
expr_stmt|;
name|res
operator|=
name|pthread_join
argument_list|(
name|thread_id
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|res
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

