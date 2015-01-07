begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_dfsan -m64 %s -o %t
end_comment

begin_comment
comment|// RUN: DFSAN_OPTIONS=dump_labels_at_exit=/dev/stdout %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: DFSAN_OPTIONS=dump_labels_at_exit=/dev/stdout not %run %t c 2>&1 | FileCheck %s --check-prefix=CHECK-OOL
end_comment

begin_comment
comment|// RUN: DFSAN_OPTIONS=dump_labels_at_exit=/dev/stdout not %run %t u 2>&1 | FileCheck %s --check-prefix=CHECK-OOL
end_comment

begin_comment
comment|// Tests that labels are properly dumped at program termination.
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

begin_include
include|#
directive|include
file|<stdio.h>
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
name|int
name|k
init|=
literal|3
decl_stmt|;
name|dfsan_label
name|k_label
init|=
name|dfsan_create_label
argument_list|(
literal|"k"
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|dfsan_set_label
argument_list|(
name|k_label
argument_list|,
operator|&
name|k
argument_list|,
sizeof|sizeof
argument_list|(
name|k
argument_list|)
argument_list|)
expr_stmt|;
name|dfsan_label
name|ij_label
init|=
name|dfsan_get_label
argument_list|(
name|i
operator|+
name|j
argument_list|)
decl_stmt|;
name|dfsan_label
name|ijk_label
init|=
name|dfsan_get_label
argument_list|(
name|i
operator|+
name|j
operator|+
name|k
argument_list|)
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"i %d j %d k %d ij %d ijk %d\n"
argument_list|,
name|i_label
argument_list|,
name|j_label
argument_list|,
name|k_label
argument_list|,
name|ij_label
argument_list|,
name|ijk_label
argument_list|)
expr_stmt|;
comment|// CHECK: 1 0 0 i
comment|// CHECK: 2 0 0 j
comment|// CHECK: 3 0 0 k
comment|// CHECK: 4 1 2
comment|// CHECK: 5 3 4
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
comment|// Exhaust the labels.
name|unsigned
name|long
name|num_labels
init|=
literal|1
operator|<<
operator|(
sizeof|sizeof
argument_list|(
name|dfsan_label
argument_list|)
operator|*
literal|8
operator|)
decl_stmt|;
for|for
control|(
name|unsigned
name|long
name|i
init|=
name|ijk_label
operator|+
literal|1
init|;
name|i
operator|<
name|num_labels
operator|-
literal|2
condition|;
operator|++
name|i
control|)
block|{
name|dfsan_label
name|l
init|=
name|dfsan_create_label
argument_list|(
literal|"l"
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|l
operator|==
name|i
argument_list|)
expr_stmt|;
block|}
comment|// Consume the last available label.
name|dfsan_label
name|l
init|=
name|dfsan_union
argument_list|(
literal|5
argument_list|,
literal|6
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|l
operator|==
name|num_labels
operator|-
literal|2
argument_list|)
expr_stmt|;
comment|// Try to allocate another label (either explicitly or by unioning two
comment|// existing labels), but expect a crash.
if|if
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|==
literal|'c'
condition|)
block|{
name|l
operator|=
name|dfsan_create_label
argument_list|(
literal|"l"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|l
operator|=
name|dfsan_union
argument_list|(
literal|6
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
comment|// CHECK-OOL: FATAL: DataFlowSanitizer: out of labels
comment|// CHECK-OOL: 1 0 0 i
comment|// CHECK-OOL: 2 0 0 j
comment|// CHECK-OOL: 3 0 0 k
comment|// CHECK-OOL: 4 1 2
comment|// CHECK-OOL: 5 3 4
comment|// CHECK-OOL: 6 0 0
comment|// CHECK-OOL: 65534 5 6
comment|// CHECK-OOL: 65535 0 0<init label>
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

