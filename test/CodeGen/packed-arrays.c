begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unk-unk -emit-llvm -Os -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_struct
struct|struct
name|s0
block|{
name|unsigned
name|int
name|x
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s1
block|{
name|unsigned
name|int
name|x
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|y
decl_stmt|;
name|unsigned
name|int
name|z
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s2
block|{
name|unsigned
name|int
name|x
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|y
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|z
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|s3
block|{
name|unsigned
name|int
name|x
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|int
name|y
decl_stmt|;
name|unsigned
name|int
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: @align0 = global i32 1
end_comment

begin_decl_stmt
name|int
name|align0
init|=
name|__alignof
argument_list|(
expr|struct
name|s0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @align1 = global i32 4
end_comment

begin_decl_stmt
name|int
name|align1
init|=
name|__alignof
argument_list|(
expr|struct
name|s1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @align2 = global i32 1
end_comment

begin_decl_stmt
name|int
name|align2
init|=
name|__alignof
argument_list|(
expr|struct
name|s2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @align3 = global i32 1
end_comment

begin_decl_stmt
name|int
name|align3
init|=
name|__alignof
argument_list|(
expr|struct
name|s3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @align0_x = global i32 1
end_comment

begin_decl_stmt
name|int
name|align0_x
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s0
operator|*
operator|)
literal|0
operator|)
operator|->
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: @align1_x = global i32 1
end_comment

begin_decl_stmt
name|int
name|align1_x
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s1
operator|*
operator|)
literal|0
operator|)
operator|->
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @align2_x = global i32 1
end_comment

begin_decl_stmt
name|int
name|align2_x
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s2
operator|*
operator|)
literal|0
operator|)
operator|->
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @align3_x = global i32 1
end_comment

begin_decl_stmt
name|int
name|align3_x
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s3
operator|*
operator|)
literal|0
operator|)
operator|->
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @align0_x0 = global i32 4
end_comment

begin_decl_stmt
name|int
name|align0_x0
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s0
operator|*
operator|)
literal|0
operator|)
operator|->
name|x
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @align1_x0 = global i32 4
end_comment

begin_decl_stmt
name|int
name|align1_x0
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s1
operator|*
operator|)
literal|0
operator|)
operator|->
name|x
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @align2_x0 = global i32 4
end_comment

begin_decl_stmt
name|int
name|align2_x0
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s2
operator|*
operator|)
literal|0
operator|)
operator|->
name|x
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @align3_x0 = global i32 4
end_comment

begin_decl_stmt
name|int
name|align3_x0
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s3
operator|*
operator|)
literal|0
operator|)
operator|->
name|x
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @f0_a
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f0_b
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 4
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|int
name|f0_a
parameter_list|(
name|struct
name|s0
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|x
index|[
literal|1
index|]
return|;
block|}
end_function

begin_function
name|int
name|f0_b
parameter_list|(
name|struct
name|s0
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|*
operator|(
name|a
operator|->
name|x
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|// Note that we are incompatible with GCC on this example.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f1_a
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f1_b
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 4
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// Note that we are incompatible with GCC on this example.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f1_c
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 4
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f1_d
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|int
name|f1_a
parameter_list|(
name|struct
name|s1
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|x
index|[
literal|1
index|]
return|;
block|}
end_function

begin_function
name|int
name|f1_b
parameter_list|(
name|struct
name|s1
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|*
operator|(
name|a
operator|->
name|x
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|int
name|f1_c
parameter_list|(
name|struct
name|s1
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|y
return|;
block|}
end_function

begin_function
name|int
name|f1_d
parameter_list|(
name|struct
name|s1
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|z
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @f2_a
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f2_b
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 4
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f2_c
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f2_d
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|int
name|f2_a
parameter_list|(
name|struct
name|s2
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|x
index|[
literal|1
index|]
return|;
block|}
end_function

begin_function
name|int
name|f2_b
parameter_list|(
name|struct
name|s2
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|*
operator|(
name|a
operator|->
name|x
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|int
name|f2_c
parameter_list|(
name|struct
name|s2
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|y
return|;
block|}
end_function

begin_function
name|int
name|f2_d
parameter_list|(
name|struct
name|s2
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|z
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @f3_a
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f3_b
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 4
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f3_c
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f3_d
end_comment

begin_comment
comment|// CHECK:   load i32* %{{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|int
name|f3_a
parameter_list|(
name|struct
name|s3
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|x
index|[
literal|1
index|]
return|;
block|}
end_function

begin_function
name|int
name|f3_b
parameter_list|(
name|struct
name|s3
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|*
operator|(
name|a
operator|->
name|x
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|int
name|f3_c
parameter_list|(
name|struct
name|s3
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|y
return|;
block|}
end_function

begin_function
name|int
name|f3_d
parameter_list|(
name|struct
name|s3
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|z
return|;
block|}
end_function

begin_comment
comment|// Verify we don't claim things are overaligned.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define double @f4
end_comment

begin_comment
comment|// CHECK:   load double* {{.*}}, align 8
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_decl_stmt
specifier|extern
name|double
name|g4
index|[
literal|5
index|]
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|double
name|f4
parameter_list|()
block|{
return|return
name|g4
index|[
literal|1
index|]
return|;
block|}
end_function

end_unit

