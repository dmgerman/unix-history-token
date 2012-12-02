begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -emit-llvm< %s| FileCheck %s
end_comment

begin_comment
comment|// CHECK: @test1
end_comment

begin_comment
comment|// CHECK: call void @llvm.memset.p0i8.i32
end_comment

begin_comment
comment|// CHECK: call void @llvm.memset.p0i8.i32
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i32
end_comment

begin_comment
comment|// CHECK: call void @llvm.memmove.p0i8.p0i8.i32
end_comment

begin_comment
comment|// CHECK-NOT: __builtin
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|int
name|test1
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
name|unsigned
name|char
name|a
init|=
literal|0x11223344
decl_stmt|;
name|unsigned
name|char
name|b
init|=
literal|0x11223344
decl_stmt|;
name|__builtin_bzero
argument_list|(
operator|&
name|a
argument_list|,
sizeof|sizeof
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
name|__builtin_memset
argument_list|(
operator|&
name|a
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
name|__builtin_memcpy
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
name|__builtin_memmove
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// rdar://9289468
end_comment

begin_comment
comment|// CHECK: @test2
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i32
end_comment

begin_function
name|char
modifier|*
name|test2
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|char
modifier|*
name|b
parameter_list|)
block|{
return|return
name|__builtin_memcpy
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test3
end_comment

begin_comment
comment|// CHECK: call void @llvm.memset
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|char
modifier|*
name|P
parameter_list|)
block|{
name|__builtin___memset_chk
argument_list|(
name|P
argument_list|,
literal|42
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test4
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|char
modifier|*
name|P
parameter_list|,
name|char
modifier|*
name|Q
parameter_list|)
block|{
name|__builtin___memcpy_chk
argument_list|(
name|P
argument_list|,
name|Q
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test5
end_comment

begin_comment
comment|// CHECK: call void @llvm.memmove
end_comment

begin_function
name|void
name|test5
parameter_list|(
name|char
modifier|*
name|P
parameter_list|,
name|char
modifier|*
name|Q
parameter_list|)
block|{
name|__builtin___memmove_chk
argument_list|(
name|P
argument_list|,
name|Q
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test6
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy
end_comment

begin_function
name|int
name|test6
parameter_list|(
name|char
modifier|*
name|X
parameter_list|)
block|{
return|return
name|__builtin___memcpy_chk
argument_list|(
name|X
argument_list|,
name|X
argument_list|,
literal|42
argument_list|,
literal|42
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test7
end_comment

begin_comment
comment|// PR12094
end_comment

begin_function
name|int
name|test7
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|struct
name|snd_pcm_hw_params_t
modifier|*
name|hwparams
decl_stmt|;
comment|// incomplete type.
comment|// CHECK: call void @llvm.memset{{.*}}256, i32 4, i1 false)
name|__builtin_memset
argument_list|(
name|p
argument_list|,
literal|0
argument_list|,
literal|256
argument_list|)
expr_stmt|;
comment|// Should be alignment = 4
comment|// CHECK: call void @llvm.memset{{.*}}256, i32 1, i1 false)
name|__builtin_memset
argument_list|(
operator|(
name|char
operator|*
operator|)
name|p
argument_list|,
literal|0
argument_list|,
literal|256
argument_list|)
expr_stmt|;
comment|// Should be alignment = 1
name|__builtin_memset
argument_list|(
name|hwparams
argument_list|,
literal|0
argument_list|,
literal|256
argument_list|)
expr_stmt|;
comment|// No crash alignment = 1
comment|// CHECK: call void @llvm.memset{{.*}}256, i32 1, i1 false)
block|}
end_function

begin_comment
comment|//<rdar://problem/11314941>
end_comment

begin_comment
comment|// Make sure we don't over-estimate the alignment of fields of
end_comment

begin_comment
comment|// packed structs.
end_comment

begin_struct
struct|struct
name|PS
block|{
name|int
name|modes
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_decl_stmt
name|struct
name|PS
name|ps
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test8
parameter_list|(
name|int
modifier|*
name|arg
parameter_list|)
block|{
comment|// CHECK: @test8
comment|// CHECK: call void @llvm.memcpy{{.*}} 16, i32 1, i1 false)
name|__builtin_memcpy
argument_list|(
name|arg
argument_list|,
name|ps
operator|.
name|modes
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|PS
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|__attribute
argument_list|(
argument|(aligned(
literal|16
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
index|[
literal|4
index|]
decl_stmt|,
name|y
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test9
parameter_list|()
block|{
comment|// CHECK: @test9
comment|// CHECK: call void @llvm.memcpy{{.*}} 16, i32 16, i1 false)
name|__builtin_memcpy
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
sizeof|sizeof
argument_list|(
name|y
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

