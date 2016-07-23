begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -O2 -o %t %s
end_comment

begin_comment
comment|// RUN: %run %t %t.profraw 1 1
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions --counts %t.profraw  | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
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

begin_decl_stmt
name|int
name|__llvm_profile_runtime
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
name|uint64_t
name|__llvm_profile_get_size_for_buffer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__llvm_profile_write_buffer
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__llvm_profile_reset_counters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__llvm_profile_merge_from_buffer
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|dumpBuffer
parameter_list|(
specifier|const
name|char
modifier|*
name|FileN
parameter_list|,
specifier|const
name|char
modifier|*
name|Buffer
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
name|FILE
modifier|*
name|File
init|=
name|fopen
argument_list|(
name|FileN
argument_list|,
literal|"w"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|File
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|fwrite
argument_list|(
name|Buffer
argument_list|,
literal|1
argument_list|,
name|Size
argument_list|,
name|File
argument_list|)
operator|!=
name|Size
condition|)
return|return
literal|1
return|;
return|return
name|fclose
argument_list|(
name|File
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|int
name|g
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|char
name|c
parameter_list|)
block|{
if|if
condition|(
name|c
operator|==
literal|'1'
condition|)
name|g
operator|++
expr_stmt|;
else|else
name|g
operator|--
expr_stmt|;
block|}
end_function

begin_comment
comment|/* This function is not profiled */
end_comment

begin_function
name|void
name|bar
parameter_list|(
name|int
name|M
parameter_list|)
block|{
name|g
operator|+=
name|M
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|4
condition|)
return|return
literal|1
return|;
specifier|const
name|uint64_t
name|MaxSize
init|=
literal|10000
decl_stmt|;
specifier|static
name|char
name|Buffer
index|[
name|MaxSize
index|]
decl_stmt|;
name|uint64_t
name|Size
init|=
name|__llvm_profile_get_size_for_buffer
argument_list|()
decl_stmt|;
if|if
condition|(
name|Size
operator|>
name|MaxSize
condition|)
return|return
literal|1
return|;
comment|/* Start profiling. */
name|__llvm_profile_reset_counters
argument_list|()
expr_stmt|;
name|foo
argument_list|(
name|argv
index|[
literal|2
index|]
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* End profiling by freezing counters. */
if|if
condition|(
name|__llvm_profile_write_buffer
argument_list|(
name|Buffer
argument_list|)
condition|)
return|return
literal|1
return|;
comment|/* Its profile will be discarded. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
name|bar
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Start profiling again and merge in previously      saved counters in buffer. */
name|__llvm_profile_reset_counters
argument_list|()
expr_stmt|;
name|__llvm_profile_merge_from_buffer
argument_list|(
name|Buffer
argument_list|,
name|Size
argument_list|)
expr_stmt|;
name|foo
argument_list|(
name|argv
index|[
literal|3
index|]
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* End profiling */
if|if
condition|(
name|__llvm_profile_write_buffer
argument_list|(
name|Buffer
argument_list|)
condition|)
return|return
literal|1
return|;
comment|/* Its profile will be discarded. */
name|bar
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/* Now it is time to dump the profile to file.  */
return|return
name|dumpBuffer
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
name|Buffer
argument_list|,
name|Size
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Not profiled
end_comment

begin_comment
comment|// CHECK-LABEL: dumpBuffer:
end_comment

begin_comment
comment|// CHECK:        Counters: 3
end_comment

begin_comment
comment|// CHECK-NEXT:   Function count: 0
end_comment

begin_comment
comment|// CHECK-NEXT:   Block counts: [0, 0]
end_comment

begin_comment
comment|// Profiled with entry count == 2
end_comment

begin_comment
comment|// CHECK-LABEL:  foo:
end_comment

begin_comment
comment|// CHECK:         Counters: 2
end_comment

begin_comment
comment|// CHECK-NEXT:    Function count: 2
end_comment

begin_comment
comment|// CHECK-NEXT:    Block counts: [2]
end_comment

begin_comment
comment|// Not profiled
end_comment

begin_comment
comment|// CHECK-LABEL:  bar:
end_comment

begin_comment
comment|// CHECK:         Counters: 1
end_comment

begin_comment
comment|// CHECK-NEXT     Function count: 0
end_comment

begin_comment
comment|// CHECK-NEXT     Block counts: []
end_comment

begin_comment
comment|// Not profiled
end_comment

begin_comment
comment|// CHECK-LABEL:  main:
end_comment

begin_comment
comment|// CHECK:         Counters: 6
end_comment

begin_comment
comment|// CHECK-NEXT:    Function count: 0
end_comment

begin_comment
comment|// CHECK-NEXT:    Block counts: [0, 0, 0, 0, 0]
end_comment

end_unit

