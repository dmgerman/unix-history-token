begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clangxx_msan -DGETC -m64 -O0 -g -xc++ %s -o %t&& %run %t
end_comment

begin_comment
comment|// RUN: %clangxx_msan -DGETC -m64 -O3 -g -xc++ %s -o %t&& %run %t
end_comment

begin_comment
comment|// RUN: %clang_msan -DGETC -m64 -O0 -g %s -o %t&& %run %t
end_comment

begin_comment
comment|// RUN: %clang_msan -DGETC -m64 -O3 -g %s -o %t&& %run %t
end_comment

begin_comment
comment|// RUN: %clangxx_msan -DGETCHAR -m64 -O0 -g -xc++ %s -o %t&& %run %t
end_comment

begin_comment
comment|// RUN: %clangxx_msan -DGETCHAR -m64 -O3 -g -xc++ %s -o %t&& %run %t
end_comment

begin_comment
comment|// RUN: %clang_msan -DGETCHAR -m64 -O0 -g %s -o %t&& %run %t
end_comment

begin_comment
comment|// RUN: %clang_msan -DGETCHAR -m64 -O3 -g %s -o %t&& %run %t
end_comment

begin_include
include|#
directive|include
file|<assert.h>
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

begin_function
name|int
name|main
parameter_list|()
block|{
name|FILE
modifier|*
name|stream
init|=
name|fopen
argument_list|(
literal|"/dev/zero"
argument_list|,
literal|"r"
argument_list|)
decl_stmt|;
name|flockfile
argument_list|(
name|stream
argument_list|)
expr_stmt|;
name|int
name|c
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|GETCHAR
argument_list|)
name|int
name|res
init|=
name|dup2
argument_list|(
name|fileno
argument_list|(
name|stream
argument_list|)
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|res
operator|==
literal|0
argument_list|)
expr_stmt|;
name|c
operator|=
name|getchar_unlocked
argument_list|()
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|GETC
argument_list|)
name|c
operator|=
name|getc_unlocked
argument_list|(
name|stream
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|funlockfile
argument_list|(
name|stream
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
name|EOF
condition|)
return|return
literal|1
return|;
name|printf
argument_list|(
literal|"%c\n"
argument_list|,
operator|(
name|char
operator|)
name|c
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|stream
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

