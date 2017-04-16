begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_pgogen -o %t %s
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE="%t.d/%m.profraw"
end_comment

begin_comment
comment|// RUN: rm -fr %t.d
end_comment

begin_comment
comment|// RUN: %run %t %t.d
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
if|if
condition|(
name|access
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
name|F_OK
argument_list|)
operator|==
literal|0
condition|)
return|return
literal|1
return|;
comment|// %t.d should not exist yet.
return|return
operator|!
operator|(
name|errno
operator|==
name|ENOENT
operator|)
return|;
block|}
end_function

end_unit

