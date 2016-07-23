begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -mllvm --enable-value-profiling=true -mllvm -vp-static-alloc=true -mllvm -vp-counters-per-site=3 -O2 -o %t %s
end_comment

begin_comment
comment|// RUN: %run %t %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions --counts --ic-targets %t.profdata> %t.profdump
end_comment

begin_comment
comment|// RUN: FileCheck --input-file %t.profdump  %s --check-prefix=FOO
end_comment

begin_comment
comment|// RUN: FileCheck --input-file %t.profdump  %s --check-prefix=BAR
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

begin_decl_stmt
name|int
name|__llvm_profile_runtime
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|__llvm_profile_write_file
parameter_list|()
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

begin_function_decl
name|void
name|__llvm_profile_set_filename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|__llvm_profile_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ValueProfData
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|lprofMergeValueProfData
parameter_list|(
name|struct
name|ValueProfData
modifier|*
parameter_list|,
name|struct
name|__llvm_profile_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Force the vp merger module to be linked in.  */
end_comment

begin_decl_stmt
name|void
modifier|*
name|Dummy
init|=
operator|&
name|lprofMergeValueProfData
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|callee1
parameter_list|()
block|{}
end_function

begin_function
name|void
name|callee2
parameter_list|()
block|{}
end_function

begin_function
name|void
name|callee3
parameter_list|()
block|{}
end_function

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|FP
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|FP
name|Fps
index|[
literal|3
index|]
init|=
block|{
name|callee1
block|,
name|callee2
block|,
name|callee3
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|int
name|N
parameter_list|)
block|{
name|int
name|I
decl_stmt|,
name|J
decl_stmt|;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<
literal|3
condition|;
name|I
operator|++
control|)
for|for
control|(
name|J
operator|=
literal|0
init|;
name|J
operator|<
name|I
operator|*
literal|2
operator|+
literal|1
condition|;
name|J
operator|++
control|)
name|Fps
index|[
name|I
index|]
operator|(
operator|)
expr_stmt|;
if|if
condition|(
name|N
operator|<
literal|2
condition|)
return|return;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<
literal|3
condition|;
name|I
operator|++
control|)
for|for
control|(
name|J
operator|=
literal|0
init|;
name|J
operator|<
name|I
operator|*
literal|2
operator|+
literal|1
condition|;
name|J
operator|++
control|)
name|Fps
index|[
literal|2
operator|-
name|I
index|]
operator|(
operator|)
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
name|void
parameter_list|)
block|{
name|int
name|I
decl_stmt|;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<
literal|20
condition|;
name|I
operator|++
control|)
name|Fps
index|[
name|I
operator|%
literal|3
index|]
operator|(
operator|)
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
literal|2
condition|)
return|return
literal|1
return|;
specifier|const
name|char
modifier|*
name|FileN
init|=
name|argv
index|[
literal|1
index|]
decl_stmt|;
name|__llvm_profile_set_filename
argument_list|(
name|FileN
argument_list|)
expr_stmt|;
comment|/* Start profiling. */
name|__llvm_profile_reset_counters
argument_list|()
expr_stmt|;
name|foo
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* End profiling by freezing counters and    * dump them to the file. */
if|if
condition|(
name|__llvm_profile_write_file
argument_list|()
condition|)
return|return
literal|1
return|;
comment|/* Read profile data into buffer. */
name|FILE
modifier|*
name|File
init|=
name|fopen
argument_list|(
name|FileN
argument_list|,
literal|"r"
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
name|fseek
argument_list|(
name|File
argument_list|,
literal|0
argument_list|,
name|SEEK_END
argument_list|)
expr_stmt|;
name|uint64_t
name|Size
init|=
name|ftell
argument_list|(
name|File
argument_list|)
decl_stmt|;
name|fseek
argument_list|(
name|File
argument_list|,
literal|0
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
name|char
modifier|*
name|Buffer
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|Size
argument_list|)
decl_stmt|;
if|if
condition|(
name|Size
operator|!=
name|fread
argument_list|(
name|Buffer
argument_list|,
literal|1
argument_list|,
name|Size
argument_list|,
name|File
argument_list|)
condition|)
return|return
literal|1
return|;
name|fclose
argument_list|(
name|File
argument_list|)
expr_stmt|;
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
argument_list|()
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
literal|2
argument_list|)
expr_stmt|;
comment|/* End profiling. */
name|truncate
argument_list|(
name|FileN
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|__llvm_profile_write_file
argument_list|()
condition|)
return|return
literal|1
return|;
comment|/* Its profile will be discarded. */
name|bar
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// FOO-LABEL:  foo:
end_comment

begin_comment
comment|// FOO:    Indirect Target Results:
end_comment

begin_comment
comment|// FOO-NEXT:	[ 0, callee3, 10 ]
end_comment

begin_comment
comment|// FOO-NEXT:	[ 0, callee2, 6 ]
end_comment

begin_comment
comment|// FOO-NEXT:	[ 0, callee1, 2 ]
end_comment

begin_comment
comment|// FOO-NEXT:	[ 1, callee1, 5 ]
end_comment

begin_comment
comment|// FOO-NEXT:	[ 1, callee2, 3 ]
end_comment

begin_comment
comment|// FOO-NEXT:	[ 1, callee3, 1 ]
end_comment

begin_comment
comment|// BAR-LABEL: bar:
end_comment

begin_comment
comment|// BAR:         [ 0, callee1, 0 ]
end_comment

begin_comment
comment|// BAR-NEXT:    [ 0, callee2, 0 ]
end_comment

begin_comment
comment|// BAR-NEXT:    [ 0, callee3, 0 ]
end_comment

end_unit

