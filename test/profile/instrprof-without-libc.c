begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -DCHECK_SYMBOLS -O3 -o %t.symbols %s
end_comment

begin_comment
comment|// RUN: llvm-nm %t.symbols | FileCheck %s --check-prefix=CHECK-SYMBOLS
end_comment

begin_comment
comment|// RUN: %clang_profgen -O3 -o %t %s
end_comment

begin_comment
comment|// RUN: %run %t %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %t.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.profdata -o - -S -emit-llvm %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CHECK_SYMBOLS
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|int
name|write_buffer
parameter_list|(
name|uint64_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|// CHECK-LABEL: define {{.*}} @main(
comment|// CHECK: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD1:[0-9]+]]
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
name|int
name|Write
init|=
name|__llvm_profile_write_buffer
argument_list|(
name|Buffer
argument_list|)
decl_stmt|;
if|if
condition|(
name|__llvm_profile_write_buffer
argument_list|(
name|Buffer
argument_list|)
condition|)
return|return
name|Write
return|;
ifdef|#
directive|ifdef
name|CHECK_SYMBOLS
comment|// Don't write it out.  Since we're checking the symbols, we don't have libc
comment|// available.
return|return
literal|0
return|;
else|#
directive|else
comment|// Actually write it out so we can FileCheck the output.
name|FILE
modifier|*
name|File
init|=
name|fopen
argument_list|(
name|argv
index|[
literal|1
index|]
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
endif|#
directive|endif
block|}
end_function

begin_comment
comment|// CHECK: ![[PD1]] = metadata !{metadata !"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// CHECK-SYMBOLS-NOT: ___cxx_global_var_init
end_comment

begin_comment
comment|// CHECK-SYMBOLS-NOT: ___llvm_profile_register_write_file_atexit
end_comment

begin_comment
comment|// CHECK-SYMBOLS-NOT: ___llvm_profile_set_filename
end_comment

begin_comment
comment|// CHECK-SYMBOLS-NOT: ___llvm_profile_write_file
end_comment

begin_comment
comment|// CHECK-SYMBOLS-NOT: _fdopen
end_comment

begin_comment
comment|// CHECK-SYMBOLS-NOT: _fopen
end_comment

begin_comment
comment|// CHECK-SYMBOLS-NOT: _fwrite
end_comment

begin_comment
comment|// CHECK-SYMBOLS-NOT: _getenv
end_comment

begin_comment
comment|// CHECK-SYMBOLS-NOT: _malloc
end_comment

begin_comment
comment|// CHECK-SYMBOLS-NOT: _open
end_comment

end_unit

