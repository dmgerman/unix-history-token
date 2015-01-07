begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_dfsan -DLIB -m64 -c %s -o %t.lib.o&& \
end_comment

begin_comment
comment|// RUN: %clang_dfsan       -m64 -c %s -o %t.o&& \
end_comment

begin_comment
comment|// RUN: %clang_dfsan -m64 %t.lib.o %t.o -o %t.bin&& \
end_comment

begin_comment
comment|// RUN: %run %t.bin
end_comment

begin_comment
comment|// RUN: %clang_dfsan -mllvm -dfsan-args-abi -m64 -DLIB -c %s -o %t.lib.o&& \
end_comment

begin_comment
comment|// RUN: %clang_dfsan -mllvm -dfsan-args-abi -m64 -c %s -o %t.o&& \
end_comment

begin_comment
comment|// RUN: %clang_dfsan -mllvm -dfsan-args-abi -m64 %t.o %t.lib.o -o %t.bin&& \
end_comment

begin_comment
comment|// RUN: %run %t.bin
end_comment

begin_include
include|#
directive|include
file|<sanitizer/dfsan_interface.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LIB
end_ifdef

begin_comment
comment|// Compiling this file with and without LIB defined allows this file to be
end_comment

begin_comment
comment|// built as two separate translation units.  This ensures that the code
end_comment

begin_comment
comment|// can not be optimized in a way that removes behavior we wish to test.  For
end_comment

begin_comment
comment|// example, computing a value should cause labels to be allocated only if
end_comment

begin_comment
comment|// the computation is actually done.  Putting the computation here prevents
end_comment

begin_comment
comment|// the compiler from optimizing away the computation (and labeling) that
end_comment

begin_comment
comment|// tests wish to verify.
end_comment

begin_function
name|int
name|add_in_separate_translation_unit
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|int
name|multiply_in_separate_translation_unit
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|add_in_separate_translation_unit
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|multiply_in_separate_translation_unit
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|size_t
name|label_count
decl_stmt|;
comment|// No labels allocated yet.
name|label_count
operator|=
name|dfsan_get_label_count
argument_list|()
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|==
name|label_count
argument_list|)
expr_stmt|;
name|int
name|i
init|=
literal|1
decl_stmt|;
name|dfsan_label
name|i_label
init|=
name|dfsan_create_label
argument_list|(
literal|"i"
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|dfsan_set_label
argument_list|(
name|i_label
argument_list|,
operator|&
name|i
argument_list|,
sizeof|sizeof
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
comment|// One label allocated for i.
name|label_count
operator|=
name|dfsan_get_label_count
argument_list|()
expr_stmt|;
name|assert
argument_list|(
literal|1u
operator|==
name|label_count
argument_list|)
expr_stmt|;
name|int
name|j
init|=
literal|2
decl_stmt|;
name|dfsan_label
name|j_label
init|=
name|dfsan_create_label
argument_list|(
literal|"j"
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|dfsan_set_label
argument_list|(
name|j_label
argument_list|,
operator|&
name|j
argument_list|,
sizeof|sizeof
argument_list|(
name|j
argument_list|)
argument_list|)
expr_stmt|;
comment|// Check that a new label was allocated for j.
name|label_count
operator|=
name|dfsan_get_label_count
argument_list|()
expr_stmt|;
name|assert
argument_list|(
literal|2u
operator|==
name|label_count
argument_list|)
expr_stmt|;
comment|// Create a value that combines i and j.
name|int
name|i_plus_j
init|=
name|add_in_separate_translation_unit
argument_list|(
name|i
argument_list|,
name|j
argument_list|)
decl_stmt|;
comment|// Check that a label was created for the union of i and j.
name|label_count
operator|=
name|dfsan_get_label_count
argument_list|()
expr_stmt|;
name|assert
argument_list|(
literal|3u
operator|==
name|label_count
argument_list|)
expr_stmt|;
comment|// Combine i and j in a different way.  Check that the existing label is
comment|// reused, and a new label is not created.
name|int
name|j_times_i
init|=
name|multiply_in_separate_translation_unit
argument_list|(
name|j
argument_list|,
name|i
argument_list|)
decl_stmt|;
name|label_count
operator|=
name|dfsan_get_label_count
argument_list|()
expr_stmt|;
name|assert
argument_list|(
literal|3u
operator|==
name|label_count
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|dfsan_get_label
argument_list|(
name|i_plus_j
argument_list|)
operator|==
name|dfsan_get_label
argument_list|(
name|j_times_i
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifdef LIB
end_comment

end_unit

