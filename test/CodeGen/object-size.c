begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple x86_64-apple-darwin -S %s -o - | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|strcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|((__builtin_object_size(dest, 0) != -1ULL) \    ? __builtin___strcpy_chk (dest, src, __builtin_object_size(dest, 1)) \    : __inline_strcpy_chk(dest, src))
end_define

begin_function
specifier|static
name|char
modifier|*
name|__inline_strcpy_chk
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
block|{
return|return
name|__builtin___strcpy_chk
argument_list|(
name|dest
argument_list|,
name|src
argument_list|,
name|__builtin_object_size
argument_list|(
name|dest
argument_list|,
literal|1
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|char
name|gbuf
index|[
literal|63
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|gp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gi
decl_stmt|,
name|gj
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test1
parameter_list|()
block|{
comment|// CHECK:       movabsq $59, %rdx
comment|// CHECK-NEXT:  movq
comment|// CHECK-NEXT:  movq
comment|// CHECK-NEXT:  call    ___strcpy_chk
name|strcpy
argument_list|(
operator|&
name|gbuf
index|[
literal|4
index|]
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test2
parameter_list|()
block|{
comment|// CHECK:       movabsq $63, %rdx
comment|// CHECK-NEXT:  movq
comment|// CHECK-NEXT:  movq
comment|// CHECK-NEXT:  call    ___strcpy_chk
name|strcpy
argument_list|(
name|gbuf
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test3
parameter_list|()
block|{
comment|// CHECK:       movabsq $0, %rdx
comment|// CHECK-NEXT:  movq
comment|// CHECK-NEXT:  movq
comment|// CHECK-NEXT:  call    ___strcpy_chk
name|strcpy
argument_list|(
operator|&
name|gbuf
index|[
literal|100
index|]
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test4
parameter_list|()
block|{
comment|// CHECK:       movabsq $0, %rdx
comment|// CHECK-NEXT:  movq
comment|// CHECK-NEXT:  movq
comment|// CHECK-NEXT:  call    ___strcpy_chk
name|strcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
operator|&
name|gbuf
index|[
operator|-
literal|1
index|]
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test5
parameter_list|()
block|{
comment|// CHECK:       movq    $-1, %rax
comment|// CHECK-NEXT:  cmpq    $-1, %rax
comment|// CHECK:       call    ___inline_strcpy_chk
name|strcpy
argument_list|(
name|gp
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test6
parameter_list|()
block|{
name|char
name|buf
index|[
literal|57
index|]
decl_stmt|;
comment|// CHECK:       movabsq $53, %rdx
comment|// CHECK-NEXT:  movq
comment|// CHECK-NEXT:  movq
comment|// CHECK-NEXT:  call    ___strcpy_chk
name|strcpy
argument_list|(
operator|&
name|buf
index|[
literal|4
index|]
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test7
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|// CHECK-NOT:   call    ___strcpy_chk
comment|// CHECK:       call    ___inline_strcpy_chk
name|strcpy
argument_list|(
operator|(
operator|++
name|i
operator|,
name|gbuf
operator|)
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test8
parameter_list|()
block|{
name|char
modifier|*
name|buf
index|[
literal|50
index|]
decl_stmt|;
comment|// CHECK-NOT:   call    ___strcpy_chk
comment|// CHECK:       call    ___inline_strcpy_chk
name|strcpy
argument_list|(
name|buf
index|[
operator|++
name|gi
index|]
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test9
parameter_list|()
block|{
comment|// CHECK-NOT:   call    ___strcpy_chk
comment|// CHECK:       call    ___inline_strcpy_chk
name|strcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
operator|(
operator|++
name|gi
operator|)
operator|+
name|gj
operator|)
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|char
modifier|*
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test10
parameter_list|()
block|{
comment|// CHECK-NOT:   call    ___strcpy_chk
comment|// CHECK:       call    ___inline_strcpy_chk
name|strcpy
argument_list|(
operator|*
operator|(
operator|++
name|p
operator|)
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test11
parameter_list|()
block|{
comment|// CHECK-NOT:   call    ___strcpy_chk
comment|// CHECK:       call    ___inline_strcpy_chk
name|strcpy
argument_list|(
name|gp
operator|=
name|gbuf
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test12
parameter_list|()
block|{
comment|// CHECK-NOT:   call    ___strcpy_chk
comment|// CHECK:       call    ___inline_strcpy_chk
name|strcpy
argument_list|(
operator|++
name|gp
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test13
parameter_list|()
block|{
comment|// CHECK-NOT:   call    ___strcpy_chk
comment|// CHECK:       call    ___inline_strcpy_chk
name|strcpy
argument_list|(
name|gp
operator|++
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test14
parameter_list|()
block|{
comment|// CHECK-NOT:   call    ___strcpy_chk
comment|// CHECK:       call    ___inline_strcpy_chk
name|strcpy
argument_list|(
operator|--
name|gp
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test15
parameter_list|()
block|{
comment|// CHECK-NOT:   call    ___strcpy_chk
comment|// CHECK:       call    ___inline_strcpy_chk
name|strcpy
argument_list|(
name|gp
operator|--
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test16
parameter_list|()
block|{
comment|// CHECK-NOT:   call    ___strcpy_chk
comment|// CHECK:       call    ___inline_strcpy_chk
name|strcpy
argument_list|(
name|gp
operator|+=
literal|1
argument_list|,
literal|"Hi there"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

