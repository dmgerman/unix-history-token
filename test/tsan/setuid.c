begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_tsan -O1 %s -o %t&& %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// setuid(0) hangs on powerpc64 big endian.  When this is fixed remove
end_comment

begin_comment
comment|// the unsupported flag.
end_comment

begin_comment
comment|// https://llvm.org/bugs/show_bug.cgi?id=25799
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// UNSUPPORTED: powerpc64-unknown-linux-gnu
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|// Setuid call used to hang because the background tsan thread did not handle
end_comment

begin_comment
comment|// SIGSETXID signal. Note that we don't care whether setuid call succeeds
end_comment

begin_comment
comment|// or not.
end_comment

begin_function
specifier|static
name|void
modifier|*
name|thread
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
operator|(
name|void
operator|)
name|arg
expr_stmt|;
name|sleep
argument_list|(
literal|1
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
comment|// Create another thread just for completeness of the picture.
name|pthread_t
name|th
decl_stmt|;
name|pthread_create
argument_list|(
operator|&
name|th
argument_list|,
literal|0
argument_list|,
name|thread
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setuid
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|pthread_join
argument_list|(
name|th
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"DONE\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: DONE
end_comment

end_unit

