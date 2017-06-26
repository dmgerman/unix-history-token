begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple i686--windows -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefixes CHECK,CHECK-32BIT-LONG
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple thumbv7--windows -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefixes CHECK,CHECK-32BIT-LONG
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple x86_64--windows -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefixes CHECK,CHECK-32BIT-LONG
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple i686--linux -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefixes CHECK,CHECK-32BIT-LONG
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple x86_64--linux -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefixes CHECK,CHECK-32BIT-LONG
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions \
end_comment

begin_comment
comment|// RUN:         -triple x86_64--darwin -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefixes CHECK,CHECK-32BIT-LONG
end_comment

begin_comment
comment|// LP64 targets use 'long' as 'int' for MS intrinsics (-fms-extensions)
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_define
define|#
directive|define
name|LONG
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LONG
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// rotate left
end_comment

begin_function
name|unsigned
name|char
name|test_rotl8
parameter_list|(
name|unsigned
name|char
name|value
parameter_list|,
name|unsigned
name|char
name|shift
parameter_list|)
block|{
return|return
name|_rotl8
argument_list|(
name|value
argument_list|,
name|shift
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: i8 @test_rotl8
end_comment

begin_comment
comment|// CHECK:   [[SHIFT:%[0-9]+]] = and i8 %{{[0-9]+}}, 7
end_comment

begin_comment
comment|// CHECK:   [[NEGSHIFT:%[0-9]+]] = sub i8 8, [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[HIGH:%[0-9]+]] = shl i8 [[VALUE:%[0-9]+]], [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[LOW:%[0-9]+]] = lshr i8 [[VALUE]], [[NEGSHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[ROTATED:%[0-9]+]] = or i8 [[HIGH]], [[LOW]]
end_comment

begin_comment
comment|// CHECK:   [[ISZERO:%[0-9]+]] = icmp eq i8 [[SHIFT]], 0
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = select i1 [[ISZERO]], i8 [[VALUE]], i8 [[ROTATED]]
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT]]
end_comment

begin_comment
comment|// CHECK  }
end_comment

begin_function
name|unsigned
name|short
name|test_rotl16
parameter_list|(
name|unsigned
name|short
name|value
parameter_list|,
name|unsigned
name|char
name|shift
parameter_list|)
block|{
return|return
name|_rotl16
argument_list|(
name|value
argument_list|,
name|shift
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: i16 @test_rotl16
end_comment

begin_comment
comment|// CHECK:   [[SHIFT:%[0-9]+]] = and i16 %{{[0-9]+}}, 15
end_comment

begin_comment
comment|// CHECK:   [[NEGSHIFT:%[0-9]+]] = sub i16 16, [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[HIGH:%[0-9]+]] = shl i16 [[VALUE:%[0-9]+]], [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[LOW:%[0-9]+]] = lshr i16 [[VALUE]], [[NEGSHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[ROTATED:%[0-9]+]] = or i16 [[HIGH]], [[LOW]]
end_comment

begin_comment
comment|// CHECK:   [[ISZERO:%[0-9]+]] = icmp eq i16 [[SHIFT]], 0
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = select i1 [[ISZERO]], i16 [[VALUE]], i16 [[ROTATED]]
end_comment

begin_comment
comment|// CHECK:   ret i16 [[RESULT]]
end_comment

begin_comment
comment|// CHECK  }
end_comment

begin_function
name|unsigned
name|int
name|test_rotl
parameter_list|(
name|unsigned
name|int
name|value
parameter_list|,
name|int
name|shift
parameter_list|)
block|{
return|return
name|_rotl
argument_list|(
name|value
argument_list|,
name|shift
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: i32 @test_rotl
end_comment

begin_comment
comment|// CHECK:   [[SHIFT:%[0-9]+]] = and i32 %{{[0-9]+}}, 31
end_comment

begin_comment
comment|// CHECK:   [[NEGSHIFT:%[0-9]+]] = sub i32 32, [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[HIGH:%[0-9]+]] = shl i32 [[VALUE:%[0-9]+]], [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[LOW:%[0-9]+]] = lshr i32 [[VALUE]], [[NEGSHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[ROTATED:%[0-9]+]] = or i32 [[HIGH]], [[LOW]]
end_comment

begin_comment
comment|// CHECK:   [[ISZERO:%[0-9]+]] = icmp eq i32 [[SHIFT]], 0
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = select i1 [[ISZERO]], i32 [[VALUE]], i32 [[ROTATED]]
end_comment

begin_comment
comment|// CHECK:   ret i32 [[RESULT]]
end_comment

begin_comment
comment|// CHECK  }
end_comment

begin_function
name|unsigned
name|LONG
name|test_lrotl
parameter_list|(
name|unsigned
name|LONG
name|value
parameter_list|,
name|int
name|shift
parameter_list|)
block|{
return|return
name|_lrotl
argument_list|(
name|value
argument_list|,
name|shift
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-32BIT-LONG: i32 @test_lrotl
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[SHIFT:%[0-9]+]] = and i32 %{{[0-9]+}}, 31
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[NEGSHIFT:%[0-9]+]] = sub i32 32, [[SHIFT]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[HIGH:%[0-9]+]] = shl i32 [[VALUE:%[0-9]+]], [[SHIFT]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[LOW:%[0-9]+]] = lshr i32 [[VALUE]], [[NEGSHIFT]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[ROTATED:%[0-9]+]] = or i32 [[HIGH]], [[LOW]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[ISZERO:%[0-9]+]] = icmp eq i32 [[SHIFT]], 0
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[RESULT:%[0-9]+]] = select i1 [[ISZERO]], i32 [[VALUE]], i32 [[ROTATED]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   ret i32 [[RESULT]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG  }
end_comment

begin_function
name|unsigned
name|__int64
name|test_rotl64
parameter_list|(
name|unsigned
name|__int64
name|value
parameter_list|,
name|int
name|shift
parameter_list|)
block|{
return|return
name|_rotl64
argument_list|(
name|value
argument_list|,
name|shift
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: i64 @test_rotl64
end_comment

begin_comment
comment|// CHECK:   [[SHIFT:%[0-9]+]] = and i64 %{{[0-9]+}}, 63
end_comment

begin_comment
comment|// CHECK:   [[NEGSHIFT:%[0-9]+]] = sub i64 64, [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[HIGH:%[0-9]+]] = shl i64 [[VALUE:%[0-9]+]], [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[LOW:%[0-9]+]] = lshr i64 [[VALUE]], [[NEGSHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[ROTATED:%[0-9]+]] = or i64 [[HIGH]], [[LOW]]
end_comment

begin_comment
comment|// CHECK:   [[ISZERO:%[0-9]+]] = icmp eq i64 [[SHIFT]], 0
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = select i1 [[ISZERO]], i64 [[VALUE]], i64 [[ROTATED]]
end_comment

begin_comment
comment|// CHECK:   ret i64 [[RESULT]]
end_comment

begin_comment
comment|// CHECK  }
end_comment

begin_comment
comment|// rotate right
end_comment

begin_function
name|unsigned
name|char
name|test_rotr8
parameter_list|(
name|unsigned
name|char
name|value
parameter_list|,
name|unsigned
name|char
name|shift
parameter_list|)
block|{
return|return
name|_rotr8
argument_list|(
name|value
argument_list|,
name|shift
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: i8 @test_rotr8
end_comment

begin_comment
comment|// CHECK:   [[SHIFT:%[0-9]+]] = and i8 %{{[0-9]+}}, 7
end_comment

begin_comment
comment|// CHECK:   [[NEGSHIFT:%[0-9]+]] = sub i8 8, [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[LOW:%[0-9]+]] = lshr i8 [[VALUE:%[0-9]+]], [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[HIGH:%[0-9]+]] = shl i8 [[VALUE]], [[NEGSHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[ROTATED:%[0-9]+]] = or i8 [[HIGH]], [[LOW]]
end_comment

begin_comment
comment|// CHECK:   [[ISZERO:%[0-9]+]] = icmp eq i8 [[SHIFT]], 0
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = select i1 [[ISZERO]], i8 [[VALUE]], i8 [[ROTATED]]
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT]]
end_comment

begin_comment
comment|// CHECK  }
end_comment

begin_function
name|unsigned
name|short
name|test_rotr16
parameter_list|(
name|unsigned
name|short
name|value
parameter_list|,
name|unsigned
name|char
name|shift
parameter_list|)
block|{
return|return
name|_rotr16
argument_list|(
name|value
argument_list|,
name|shift
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: i16 @test_rotr16
end_comment

begin_comment
comment|// CHECK:   [[SHIFT:%[0-9]+]] = and i16 %{{[0-9]+}}, 15
end_comment

begin_comment
comment|// CHECK:   [[NEGSHIFT:%[0-9]+]] = sub i16 16, [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[LOW:%[0-9]+]] = lshr i16 [[VALUE:%[0-9]+]], [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[HIGH:%[0-9]+]] = shl i16 [[VALUE]], [[NEGSHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[ROTATED:%[0-9]+]] = or i16 [[HIGH]], [[LOW]]
end_comment

begin_comment
comment|// CHECK:   [[ISZERO:%[0-9]+]] = icmp eq i16 [[SHIFT]], 0
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = select i1 [[ISZERO]], i16 [[VALUE]], i16 [[ROTATED]]
end_comment

begin_comment
comment|// CHECK:   ret i16 [[RESULT]]
end_comment

begin_comment
comment|// CHECK  }
end_comment

begin_function
name|unsigned
name|int
name|test_rotr
parameter_list|(
name|unsigned
name|int
name|value
parameter_list|,
name|int
name|shift
parameter_list|)
block|{
return|return
name|_rotr
argument_list|(
name|value
argument_list|,
name|shift
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: i32 @test_rotr
end_comment

begin_comment
comment|// CHECK:   [[SHIFT:%[0-9]+]] = and i32 %{{[0-9]+}}, 31
end_comment

begin_comment
comment|// CHECK:   [[NEGSHIFT:%[0-9]+]] = sub i32 32, [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[LOW:%[0-9]+]] = lshr i32 [[VALUE:%[0-9]+]], [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[HIGH:%[0-9]+]] = shl i32 [[VALUE]], [[NEGSHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[ROTATED:%[0-9]+]] = or i32 [[HIGH]], [[LOW]]
end_comment

begin_comment
comment|// CHECK:   [[ISZERO:%[0-9]+]] = icmp eq i32 [[SHIFT]], 0
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = select i1 [[ISZERO]], i32 [[VALUE]], i32 [[ROTATED]]
end_comment

begin_comment
comment|// CHECK:   ret i32 [[RESULT]]
end_comment

begin_comment
comment|// CHECK  }
end_comment

begin_function
name|unsigned
name|LONG
name|test_lrotr
parameter_list|(
name|unsigned
name|LONG
name|value
parameter_list|,
name|int
name|shift
parameter_list|)
block|{
return|return
name|_lrotr
argument_list|(
name|value
argument_list|,
name|shift
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-32BIT-LONG: i32 @test_lrotr
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[SHIFT:%[0-9]+]] = and i32 %{{[0-9]+}}, 31
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[NEGSHIFT:%[0-9]+]] = sub i32 32, [[SHIFT]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[LOW:%[0-9]+]] = lshr i32 [[VALUE:%[0-9]+]], [[SHIFT]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[HIGH:%[0-9]+]] = shl i32 [[VALUE]], [[NEGSHIFT]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[ROTATED:%[0-9]+]] = or i32 [[HIGH]], [[LOW]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[ISZERO:%[0-9]+]] = icmp eq i32 [[SHIFT]], 0
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   [[RESULT:%[0-9]+]] = select i1 [[ISZERO]], i32 [[VALUE]], i32 [[ROTATED]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG:   ret i32 [[RESULT]]
end_comment

begin_comment
comment|// CHECK-32BIT-LONG  }
end_comment

begin_function
name|unsigned
name|__int64
name|test_rotr64
parameter_list|(
name|unsigned
name|__int64
name|value
parameter_list|,
name|int
name|shift
parameter_list|)
block|{
return|return
name|_rotr64
argument_list|(
name|value
argument_list|,
name|shift
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: i64 @test_rotr64
end_comment

begin_comment
comment|// CHECK:   [[SHIFT:%[0-9]+]] = and i64 %{{[0-9]+}}, 63
end_comment

begin_comment
comment|// CHECK:   [[NEGSHIFT:%[0-9]+]] = sub i64 64, [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[LOW:%[0-9]+]] = lshr i64 [[VALUE:%[0-9]+]], [[SHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[HIGH:%[0-9]+]] = shl i64 [[VALUE]], [[NEGSHIFT]]
end_comment

begin_comment
comment|// CHECK:   [[ROTATED:%[0-9]+]] = or i64 [[HIGH]], [[LOW]]
end_comment

begin_comment
comment|// CHECK:   [[ISZERO:%[0-9]+]] = icmp eq i64 [[SHIFT]], 0
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = select i1 [[ISZERO]], i64 [[VALUE]], i64 [[ROTATED]]
end_comment

begin_comment
comment|// CHECK:   ret i64 [[RESULT]]
end_comment

begin_comment
comment|// CHECK  }
end_comment

end_unit

