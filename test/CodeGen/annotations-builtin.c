begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// END.
end_comment

begin_decl_stmt
specifier|static
name|long
name|long
name|llfoo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|intfoo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|short
name|shortfoo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|charfoo
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: private unnamed_addr constant [13 x i8] {{.*}}annotation_a{{.*}} section "llvm.metadata"
end_comment

begin_comment
comment|// CHECK-NOT: {{.*}}annotation_a{{.*}}
end_comment

begin_function
specifier|static
name|int
name|foo
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
operator|+
literal|1
return|;
block|}
end_function

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
name|char
name|barray
index|[
literal|16
index|]
decl_stmt|;
name|char
modifier|*
name|b
init|=
operator|(
name|char
operator|*
operator|)
name|__builtin_annotation
argument_list|(
operator|(
name|int
operator|)
name|barray
argument_list|,
literal|"annotation_a"
argument_list|)
decl_stmt|;
comment|// CHECK: ptrtoint i8* {{.*}} to i32
comment|// CHECK-NEXT: call i32 @llvm.annotation.i32
comment|// CHECK: inttoptr {{.*}} to i8*
name|int
name|call
init|=
name|__builtin_annotation
argument_list|(
name|foo
argument_list|(
name|argc
argument_list|)
argument_list|,
literal|"annotation_a"
argument_list|)
decl_stmt|;
comment|// CHECK: call {{.*}} @foo
comment|// CHECK: call i32 @llvm.annotation.i32
name|long
name|long
name|lla
init|=
name|__builtin_annotation
argument_list|(
name|llfoo
argument_list|,
literal|"annotation_a"
argument_list|)
decl_stmt|;
comment|// CHECK: trunc i64 {{.*}} to i32
comment|// CHECK-NEXT: call i32 @llvm.annotation.i32
comment|// CHECK-NEXT: zext i32 {{.*}} to i64
name|int
name|inta
init|=
name|__builtin_annotation
argument_list|(
name|intfoo
argument_list|,
literal|"annotation_a"
argument_list|)
decl_stmt|;
comment|// CHECK: load i32* @intfoo
comment|// CHECK-NEXT: call i32 @llvm.annotation.i32
comment|// CHECK-NEXT: store
name|short
name|shorta
init|=
name|__builtin_annotation
argument_list|(
name|shortfoo
argument_list|,
literal|"annotation_a"
argument_list|)
decl_stmt|;
comment|// CHECK: sext i16 {{.*}} to i32
comment|// CHECK-NEXT: call i32 @llvm.annotation.i32
comment|// CHECK-NEXT: trunc i32 {{.*}} to i16
name|char
name|chara
init|=
name|__builtin_annotation
argument_list|(
name|charfoo
argument_list|,
literal|"annotation_a"
argument_list|)
decl_stmt|;
comment|// CHECK: sext i8 {{.*}} to i32
comment|// CHECK-NEXT: call i32 @llvm.annotation.i32
comment|// CHECK-NEXT: trunc i32 {{.*}} to i8
comment|//
name|char
modifier|*
modifier|*
name|arg
init|=
operator|(
name|char
operator|*
operator|*
operator|)
name|__builtin_annotation
argument_list|(
operator|(
name|int
operator|)
name|argv
argument_list|,
literal|"annotation_a"
argument_list|)
decl_stmt|;
comment|// CHECK: ptrtoint i8** {{.*}} to
comment|// CHECK: call i32 @llvm.annotation.i32
comment|// CHECK: inttoptr {{.*}} to i8**
return|return
literal|0
return|;
block|}
end_function

end_unit

