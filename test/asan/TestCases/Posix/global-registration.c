begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that globals from different shared objects all get registered.
end_comment

begin_comment
comment|// This source file is compiled into three different source object files. Each
end_comment

begin_comment
comment|// object file declares a global buffer. The first two are linked together, and
end_comment

begin_comment
comment|// the third is loaded at runtime. We make sure that out-of-bounds accesses
end_comment

begin_comment
comment|// are caught for all three buffers.
end_comment

begin_comment
comment|// RUN: %clang_asan -c -o %t-one.o -DMAIN_FILE %s
end_comment

begin_comment
comment|// RUN: %clang_asan -c -o %t-two.o -DSECONDARY_FILE %s
end_comment

begin_comment
comment|// RUN: %clang_asan -o %t %t-one.o %t-two.o %libdl
end_comment

begin_comment
comment|// RUN: %clang_asan -o %t-dynamic.so -shared -fPIC -DSHARED_LIBRARY_FILE %s
end_comment

begin_comment
comment|// RUN: not %run %t 1 2>&1 | FileCheck --check-prefix ASAN-CHECK-1 %s
end_comment

begin_comment
comment|// RUN: not %run %t 2 2>&1 | FileCheck --check-prefix ASAN-CHECK-2 %s
end_comment

begin_comment
comment|// RUN: not %run %t 3 2>&1 | FileCheck --check-prefix ASAN-CHECK-3 %s
end_comment

begin_if
if|#
directive|if
name|MAIN_FILE
end_if

begin_include
include|#
directive|include
file|<dlfcn.h>
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
file|<string.h>
end_include

begin_decl_stmt
specifier|extern
name|char
name|buffer1
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|buffer2
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|buffer1
index|[
literal|1
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|n
init|=
name|atoi
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
operator|==
literal|1
condition|)
block|{
name|buffer1
index|[
name|argc
index|]
operator|=
literal|0
expr_stmt|;
comment|// ASAN-CHECK-1: {{0x.* is located 1 bytes .* 'buffer1'}}
block|}
elseif|else
if|if
condition|(
name|n
operator|==
literal|2
condition|)
block|{
name|buffer2
index|[
name|argc
index|]
operator|=
literal|0
expr_stmt|;
comment|// ASAN-CHECK-2: {{0x.* is located 1 bytes .* 'buffer2'}}
block|}
elseif|else
if|if
condition|(
name|n
operator|==
literal|3
condition|)
block|{
name|char
modifier|*
name|libsuffix
init|=
literal|"-dynamic.so"
decl_stmt|;
name|char
modifier|*
name|libpath
init|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
operator|+
name|strlen
argument_list|(
name|libsuffix
argument_list|)
operator|+
literal|1
argument_list|)
decl_stmt|;
name|sprintf
argument_list|(
name|libpath
argument_list|,
literal|"%s%s"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|libsuffix
argument_list|)
expr_stmt|;
name|void
modifier|*
name|handle
init|=
name|dlopen
argument_list|(
name|libpath
argument_list|,
name|RTLD_NOW
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|handle
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"dlopen: %s\n"
argument_list|,
name|dlerror
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|char
modifier|*
name|buffer
init|=
operator|(
name|char
operator|*
operator|)
name|dlsym
argument_list|(
name|handle
argument_list|,
literal|"buffer3"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|buffer
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"dlsym: %s\n"
argument_list|,
name|dlerror
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|buffer
index|[
name|argc
index|]
operator|=
literal|0
expr_stmt|;
comment|// ASAN-CHECK-3: {{0x.* is located 1 bytes .* 'buffer3'}}
block|}
return|return
literal|0
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|SECONDARY_FILE
end_elif

begin_decl_stmt
specifier|extern
name|char
name|buffer2
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|buffer2
index|[
literal|1
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|SHARED_LIBRARY_FILE
end_elif

begin_decl_stmt
specifier|extern
name|char
name|buffer3
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|buffer3
index|[
literal|1
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

