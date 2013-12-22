begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple "i686-unknown-unknown"   -emit-llvm -x c %s -o - -O3 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple "x86_64-unknown-unknown" -emit-llvm -x c %s -o - -O3 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple "x86_64-mingw32"         -emit-llvm -x c %s -o - -O3 | FileCheck %s
end_comment

begin_function
name|unsigned
name|char
name|test_addcb
parameter_list|(
name|unsigned
name|char
name|x
parameter_list|,
name|unsigned
name|char
name|y
parameter_list|,
name|unsigned
name|char
name|carryin
parameter_list|,
name|unsigned
name|char
modifier|*
name|z
parameter_list|)
block|{
comment|// CHECK: @test_addcb
comment|// CHECK: %{{.+}} = {{.*}} call { i8, i1 } @llvm.uadd.with.overflow.i8(i8 %x, i8 %y)
comment|// CHECK: %{{.+}} = extractvalue { i8, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i8, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = {{.*}} call { i8, i1 } @llvm.uadd.with.overflow.i8(i8 %{{.+}}, i8 %carryin)
comment|// CHECK: %{{.+}} = extractvalue { i8, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i8, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = or i1 %{{.+}}, %{{.+}}
comment|// CHECK: %{{.+}} = zext i1 %{{.+}} to i8
comment|// CHECK: store i8 %{{.+}}, i8* %z, align 1
name|unsigned
name|char
name|carryout
decl_stmt|;
operator|*
name|z
operator|=
name|__builtin_addcb
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|carryin
argument_list|,
operator|&
name|carryout
argument_list|)
expr_stmt|;
return|return
name|carryout
return|;
block|}
end_function

begin_function
name|unsigned
name|short
name|test_addcs
parameter_list|(
name|unsigned
name|short
name|x
parameter_list|,
name|unsigned
name|short
name|y
parameter_list|,
name|unsigned
name|short
name|carryin
parameter_list|,
name|unsigned
name|short
modifier|*
name|z
parameter_list|)
block|{
comment|// CHECK: @test_addcs
comment|// CHECK: %{{.+}} = {{.*}} call { i16, i1 } @llvm.uadd.with.overflow.i16(i16 %x, i16 %y)
comment|// CHECK: %{{.+}} = extractvalue { i16, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i16, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = {{.*}} call { i16, i1 } @llvm.uadd.with.overflow.i16(i16 %{{.+}}, i16 %carryin)
comment|// CHECK: %{{.+}} = extractvalue { i16, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i16, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = or i1 %{{.+}}, %{{.+}}
comment|// CHECK: %{{.+}} = zext i1 %{{.+}} to i16
comment|// CHECK: store i16 %{{.+}}, i16* %z, align 2
name|unsigned
name|short
name|carryout
decl_stmt|;
operator|*
name|z
operator|=
name|__builtin_addcs
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|carryin
argument_list|,
operator|&
name|carryout
argument_list|)
expr_stmt|;
return|return
name|carryout
return|;
block|}
end_function

begin_function
name|unsigned
name|test_addc
parameter_list|(
name|unsigned
name|x
parameter_list|,
name|unsigned
name|y
parameter_list|,
name|unsigned
name|carryin
parameter_list|,
name|unsigned
modifier|*
name|z
parameter_list|)
block|{
comment|// CHECK: @test_addc
comment|// CHECK: %{{.+}} = {{.*}} call { i32, i1 } @llvm.uadd.with.overflow.i32(i32 %x, i32 %y)
comment|// CHECK: %{{.+}} = extractvalue { i32, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i32, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = {{.*}} call { i32, i1 } @llvm.uadd.with.overflow.i32(i32 %{{.+}}, i32 %carryin)
comment|// CHECK: %{{.+}} = extractvalue { i32, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i32, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = or i1 %{{.+}}, %{{.+}}
comment|// CHECK: %{{.+}} = zext i1 %{{.+}} to i32
comment|// CHECK: store i32 %{{.+}}, i32* %z, align 4
name|unsigned
name|carryout
decl_stmt|;
operator|*
name|z
operator|=
name|__builtin_addc
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|carryin
argument_list|,
operator|&
name|carryout
argument_list|)
expr_stmt|;
return|return
name|carryout
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|test_addcl
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|,
name|unsigned
name|long
name|y
parameter_list|,
name|unsigned
name|long
name|carryin
parameter_list|,
name|unsigned
name|long
modifier|*
name|z
parameter_list|)
block|{
comment|// long is i32 on i686, i64 on x86_64.
comment|// CHECK: @test_addcl([[UL:i32|i64]] %x
comment|// CHECK: %{{.+}} = {{.*}} call { [[UL]], i1 } @llvm.uadd.with.overflow.[[UL]]([[UL]] %x, [[UL]] %y)
comment|// CHECK: %{{.+}} = extractvalue { [[UL]], i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { [[UL]], i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = {{.*}} call { [[UL]], i1 } @llvm.uadd.with.overflow.[[UL]]([[UL]] %{{.+}}, [[UL]] %carryin)
comment|// CHECK: %{{.+}} = extractvalue { [[UL]], i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { [[UL]], i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = or i1 %{{.+}}, %{{.+}}
comment|// CHECK: %{{.+}} = zext i1 %{{.+}} to [[UL]]
comment|// CHECK: store [[UL]] %{{.+}}, [[UL]]* %z
name|unsigned
name|long
name|carryout
decl_stmt|;
operator|*
name|z
operator|=
name|__builtin_addcl
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|carryin
argument_list|,
operator|&
name|carryout
argument_list|)
expr_stmt|;
return|return
name|carryout
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_addcll
parameter_list|(
name|unsigned
name|long
name|long
name|x
parameter_list|,
name|unsigned
name|long
name|long
name|y
parameter_list|,
name|unsigned
name|long
name|long
name|carryin
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
name|z
parameter_list|)
block|{
comment|// CHECK: @test_addcll
comment|// CHECK: %{{.+}} = {{.*}} call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %x, i64 %y)
comment|// CHECK: %{{.+}} = extractvalue { i64, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i64, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = {{.*}} call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %{{.+}}, i64 %carryin)
comment|// CHECK: %{{.+}} = extractvalue { i64, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i64, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = or i1 %{{.+}}, %{{.+}}
comment|// CHECK: %{{.+}} = zext i1 %{{.+}} to i64
comment|// CHECK: store i64 %{{.+}}, i64* %z
name|unsigned
name|long
name|long
name|carryout
decl_stmt|;
operator|*
name|z
operator|=
name|__builtin_addcll
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|carryin
argument_list|,
operator|&
name|carryout
argument_list|)
expr_stmt|;
return|return
name|carryout
return|;
block|}
end_function

begin_function
name|unsigned
name|char
name|test_subcb
parameter_list|(
name|unsigned
name|char
name|x
parameter_list|,
name|unsigned
name|char
name|y
parameter_list|,
name|unsigned
name|char
name|carryin
parameter_list|,
name|unsigned
name|char
modifier|*
name|z
parameter_list|)
block|{
comment|// CHECK: @test_subcb
comment|// CHECK: %{{.+}} = {{.*}} call { i8, i1 } @llvm.usub.with.overflow.i8(i8 %x, i8 %y)
comment|// CHECK: %{{.+}} = extractvalue { i8, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i8, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = {{.*}} call { i8, i1 } @llvm.usub.with.overflow.i8(i8 %{{.+}}, i8 %carryin)
comment|// CHECK: %{{.+}} = extractvalue { i8, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i8, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = or i1 %{{.+}}, %{{.+}}
comment|// CHECK: %{{.+}} = zext i1 %{{.+}} to i8
comment|// CHECK: store i8 %{{.+}}, i8* %z, align 1
name|unsigned
name|char
name|carryout
decl_stmt|;
operator|*
name|z
operator|=
name|__builtin_subcb
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|carryin
argument_list|,
operator|&
name|carryout
argument_list|)
expr_stmt|;
return|return
name|carryout
return|;
block|}
end_function

begin_function
name|unsigned
name|short
name|test_subcs
parameter_list|(
name|unsigned
name|short
name|x
parameter_list|,
name|unsigned
name|short
name|y
parameter_list|,
name|unsigned
name|short
name|carryin
parameter_list|,
name|unsigned
name|short
modifier|*
name|z
parameter_list|)
block|{
comment|// CHECK: @test_subcs
comment|// CHECK: %{{.+}} = {{.*}} call { i16, i1 } @llvm.usub.with.overflow.i16(i16 %x, i16 %y)
comment|// CHECK: %{{.+}} = extractvalue { i16, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i16, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = {{.*}} call { i16, i1 } @llvm.usub.with.overflow.i16(i16 %{{.+}}, i16 %carryin)
comment|// CHECK: %{{.+}} = extractvalue { i16, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i16, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = or i1 %{{.+}}, %{{.+}}
comment|// CHECK: %{{.+}} = zext i1 %{{.+}} to i16
comment|// CHECK: store i16 %{{.+}}, i16* %z, align 2
name|unsigned
name|short
name|carryout
decl_stmt|;
operator|*
name|z
operator|=
name|__builtin_subcs
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|carryin
argument_list|,
operator|&
name|carryout
argument_list|)
expr_stmt|;
return|return
name|carryout
return|;
block|}
end_function

begin_function
name|unsigned
name|test_subc
parameter_list|(
name|unsigned
name|x
parameter_list|,
name|unsigned
name|y
parameter_list|,
name|unsigned
name|carryin
parameter_list|,
name|unsigned
modifier|*
name|z
parameter_list|)
block|{
comment|// CHECK: @test_subc
comment|// CHECK: %{{.+}} = {{.*}} call { i32, i1 } @llvm.usub.with.overflow.i32(i32 %x, i32 %y)
comment|// CHECK: %{{.+}} = extractvalue { i32, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i32, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = {{.*}} call { i32, i1 } @llvm.usub.with.overflow.i32(i32 %{{.+}}, i32 %carryin)
comment|// CHECK: %{{.+}} = extractvalue { i32, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i32, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = or i1 %{{.+}}, %{{.+}}
comment|// CHECK: %{{.+}} = zext i1 %{{.+}} to i32
comment|// CHECK: store i32 %{{.+}}, i32* %z, align 4
name|unsigned
name|carryout
decl_stmt|;
operator|*
name|z
operator|=
name|__builtin_subc
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|carryin
argument_list|,
operator|&
name|carryout
argument_list|)
expr_stmt|;
return|return
name|carryout
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|test_subcl
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|,
name|unsigned
name|long
name|y
parameter_list|,
name|unsigned
name|long
name|carryin
parameter_list|,
name|unsigned
name|long
modifier|*
name|z
parameter_list|)
block|{
comment|// CHECK: @test_subcl([[UL:i32|i64]] %x
comment|// CHECK: %{{.+}} = {{.*}} call { [[UL]], i1 } @llvm.usub.with.overflow.[[UL]]([[UL]] %x, [[UL]] %y)
comment|// CHECK: %{{.+}} = extractvalue { [[UL]], i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { [[UL]], i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = {{.*}} call { [[UL]], i1 } @llvm.usub.with.overflow.[[UL]]([[UL]] %{{.+}}, [[UL]] %carryin)
comment|// CHECK: %{{.+}} = extractvalue { [[UL]], i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { [[UL]], i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = or i1 %{{.+}}, %{{.+}}
comment|// CHECK: %{{.+}} = zext i1 %{{.+}} to [[UL]]
comment|// CHECK: store [[UL]] %{{.+}}, [[UL]]* %z
name|unsigned
name|long
name|carryout
decl_stmt|;
operator|*
name|z
operator|=
name|__builtin_subcl
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|carryin
argument_list|,
operator|&
name|carryout
argument_list|)
expr_stmt|;
return|return
name|carryout
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_subcll
parameter_list|(
name|unsigned
name|long
name|long
name|x
parameter_list|,
name|unsigned
name|long
name|long
name|y
parameter_list|,
name|unsigned
name|long
name|long
name|carryin
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
name|z
parameter_list|)
block|{
comment|// CHECK: @test_subcll
comment|// CHECK: %{{.+}} = {{.*}} call { i64, i1 } @llvm.usub.with.overflow.i64(i64 %x, i64 %y)
comment|// CHECK: %{{.+}} = extractvalue { i64, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i64, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = {{.*}} call { i64, i1 } @llvm.usub.with.overflow.i64(i64 %{{.+}}, i64 %carryin)
comment|// CHECK: %{{.+}} = extractvalue { i64, i1 } %{{.+}}, 1
comment|// CHECK: %{{.+}} = extractvalue { i64, i1 } %{{.+}}, 0
comment|// CHECK: %{{.+}} = or i1 %{{.+}}, %{{.+}}
comment|// CHECK: %{{.+}} = zext i1 %{{.+}} to i64
comment|// CHECK: store i64 %{{.+}}, i64* %z
name|unsigned
name|long
name|long
name|carryout
decl_stmt|;
operator|*
name|z
operator|=
name|__builtin_subcll
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|carryin
argument_list|,
operator|&
name|carryout
argument_list|)
expr_stmt|;
return|return
name|carryout
return|;
block|}
end_function

end_unit

