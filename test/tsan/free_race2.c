begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_tsan -O1 %s -o %t&& %deflake %run %t | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|noinline
operator|)
argument_list|)
name|foo
argument_list|(
name|int
operator|*
name|mem
argument_list|)
block|{
name|free
argument_list|(
name|mem
argument_list|)
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
name|bar
argument_list|(
name|int
operator|*
name|mem
argument_list|)
block|{
name|mem
index|[
literal|0
index|]
operator|=
literal|42
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
modifier|*
name|mem
init|=
operator|(
name|int
operator|*
operator|)
name|malloc
argument_list|(
literal|100
argument_list|)
decl_stmt|;
name|foo
argument_list|(
name|mem
argument_list|)
expr_stmt|;
name|bar
argument_list|(
name|mem
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: WARNING: ThreadSanitizer: heap-use-after-free
end_comment

begin_comment
comment|// CHECK:   Write of size 4 at {{.*}} by main thread:
end_comment

begin_comment
comment|// CHECK:     #0 bar
end_comment

begin_comment
comment|// CHECK:     #1 main
end_comment

begin_comment
comment|// CHECK:   Previous write of size 8 at {{.*}} by main thread:
end_comment

begin_comment
comment|// CHECK:     #0 free
end_comment

begin_comment
comment|// CHECK:     #{{1|2}} foo
end_comment

begin_comment
comment|// CHECK:     #{{2|3}} main
end_comment

end_unit

