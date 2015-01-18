begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// REQUIRES: asserts
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-PPC
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_struct
struct|struct
name|x
block|{
name|long
name|a
decl_stmt|;
name|double
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|testva
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|struct
name|x
name|t
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|x
argument_list|)
decl_stmt|;
comment|// CHECK: bitcast i8* %{{[a-z.0-9]*}} to %struct.x*
comment|// CHECK: bitcast %struct.x* %t to i8*
comment|// CHECK: bitcast %struct.x* %{{[0-9]+}} to i8*
comment|// CHECK: call void @llvm.memcpy
comment|// CHECK-PPC:  [[ARRAYDECAY:%[a-z0-9]+]] = getelementptr inbounds [1 x %struct.__va_list_tag]* %ap, i32 0, i32 0
comment|// CHECK-PPC-NEXT:  [[GPRPTR:%[a-z0-9]+]] = bitcast %struct.__va_list_tag* [[ARRAYDECAY]] to i8*
comment|// CHECK-PPC-NEXT:  [[ZERO:%[0-9]+]] = ptrtoint i8* [[GPRPTR]] to i32
comment|// CHECK-PPC-NEXT:  [[ONE:%[0-9]+]] = add i32 [[ZERO]], 1
comment|// CHECK-PPC-NEXT:  [[TWO:%[0-9]+]] = inttoptr i32 [[ONE]] to i8*
comment|// CHECK-PPC-NEXT:  [[THREE:%[0-9]+]] = add i32 [[ONE]], 3
comment|// CHECK-PPC-NEXT:  [[FOUR:%[0-9]+]] = inttoptr i32 [[THREE]] to i8**
comment|// CHECK-PPC-NEXT:  [[FIVE:%[0-9]+]] = add i32 [[THREE]], 4
comment|// CHECK-PPC-NEXT:  [[SIX:%[0-9]+]] = inttoptr i32 [[FIVE]] to i8**
comment|// CHECK-PPC-NEXT:  [[GPR:%[a-z0-9]+]] = load i8* [[GPRPTR]]
comment|// CHECK-PPC-NEXT:  [[FPR:%[a-z0-9]+]] = load i8* [[TWO]]
comment|// CHECK-PPC-NEXT:  [[OVERFLOW_AREA:%[a-z_0-9]+]] = load i8** [[FOUR]]
comment|// CHECK-PPC-NEXT:  [[SEVEN:%[0-9]+]] = ptrtoint i8* [[OVERFLOW_AREA]] to i32
comment|// CHECK-PPC-NEXT:  [[REGSAVE_AREA:%[a-z_0-9]+]] = load i8** [[SIX]]
comment|// CHECK-PPC-NEXT:  [[EIGHT:%[0-9]+]] = ptrtoint i8* [[REGSAVE_AREA]] to i32
comment|// CHECK-PPC-NEXT:  [[COND:%[a-z0-9]+]] = icmp ult i8 [[GPR]], 8
comment|// CHECK-PPC-NEXT:  [[NINE:%[0-9]+]] = mul i8 [[GPR]], 4
comment|// CHECK-PPC-NEXT:  [[TEN:%[0-9]+]] = sext i8 [[NINE]] to i32
comment|// CHECK-PPC-NEXT:  [[ELEVEN:%[0-9]+]] = add i32 [[EIGHT]], [[TEN]]
comment|// CHECK-PPC-NEXT:  br i1 [[COND]], label [[USING_REGS:%[a-z_0-9]+]], label [[USING_OVERFLOW:%[a-z_0-9]+]]
comment|//
comment|// CHECK-PPC1:[[USING_REGS]]
comment|// CHECK-PPC:  [[TWELVE:%[0-9]+]] = inttoptr i32 [[ELEVEN]] to %struct.x*
comment|// CHECK-PPC-NEXT:  [[THIRTEEN:%[0-9]+]] = add i8 [[GPR]], 1
comment|// CHECK-PPC-NEXT:  store i8 [[THIRTEEN]], i8* [[GPRPTR]]
comment|// CHECK-PPC-NEXT:  br label [[CONT:%[a-z0-9]+]]
comment|//
comment|// CHECK-PPC1:[[USING_OVERFLOW]]
comment|// CHECK-PPC:  [[FOURTEEN:%[0-9]+]] = inttoptr i32 [[SEVEN]] to %struct.x*
comment|// CHECK-PPC-NEXT:  [[FIFTEEN:%[0-9]+]] = add i32 [[SEVEN]], 4
comment|// CHECK-PPC-NEXT:  [[SIXTEEN:%[0-9]+]] = inttoptr i32 [[FIFTEEN]] to i8*
comment|// CHECK-PPC-NEXT:  store i8* [[SIXTEEN]], i8** [[FOUR]]
comment|// CHECK-PPC-NEXT:  br label [[CONT]]
comment|//
comment|// CHECK-PPC1:[[CONT]]
comment|// CHECK-PPC:  [[VAARG_ADDR:%[a-z.0-9]+]] = phi %struct.x* [ [[TWELVE]], [[USING_REGS]] ], [ [[FOURTEEN]], [[USING_OVERFLOW]] ]
comment|// CHECK-PPC-NEXT:  [[AGGRPTR:%[a-z0-9]+]] = bitcast %struct.x* [[VAARG_ADDR]] to i8**
comment|// CHECK-PPC-NEXT:  [[AGGR:%[a-z0-9]+]] = load i8** [[AGGRPTR]]
comment|// CHECK-PPC-NEXT:  [[SEVENTEEN:%[0-9]+]] = bitcast %struct.x* %t to i8*
comment|// CHECK-PPC-NEXT:  call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[SEVENTEEN]], i8* [[AGGR]], i32 16, i32 8, i1 false)
name|int
name|v
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|int
argument_list|)
decl_stmt|;
comment|// CHECK: ptrtoint i8* %{{[a-z.0-9]*}} to i64
comment|// CHECK: add i64 %{{[0-9]+}}, 4
comment|// CHECK: inttoptr i64 %{{[0-9]+}} to i8*
comment|// CHECK: bitcast i8* %{{[0-9]+}} to i32*
comment|// CHECK-PPC:  [[ARRAYDECAY1:%[a-z0-9]+]] = getelementptr inbounds [1 x %struct.__va_list_tag]* %ap, i32 0, i32 0
comment|// CHECK-PPC-NEXT:  [[GPRPTR1:%[a-z0-9]+]] = bitcast %struct.__va_list_tag* [[ARRAYDECAY1]] to i8*
comment|// CHECK-PPC-NEXT:  [[EIGHTEEN:%[0-9]+]] = ptrtoint i8* [[GPRPTR1]] to i32
comment|// CHECK-PPC-NEXT:  [[NINETEEN:%[0-9]+]] = add i32 [[EIGHTEEN]], 1
comment|// CHECK-PPC-NEXT:  [[TWENTY:%[0-9]+]] = inttoptr i32 [[NINETEEN]] to i8*
comment|// CHECK-PPC-NEXT:  [[TWENTYONE:%[0-9]+]] = add i32 [[NINETEEN]], 3
comment|// CHECK-PPC-NEXT:  [[TWENTYTWO:%[0-9]+]] = inttoptr i32 [[TWENTYONE]] to i8**
comment|// CHECK-PPC-NEXT:  [[TWENTYTHREE:%[0-9]+]] = add i32 [[TWENTYONE]], 4
comment|// CHECK-PPC-NEXT:  [[TWENTYFOUR:%[0-9]+]] = inttoptr i32 [[TWENTYTHREE]] to i8**
comment|// CHECK-PPC-NEXT:  [[GPR1:%[a-z0-9]+]] = load i8* [[GPRPTR1]]
comment|// CHECK-PPC-NEXT:  [[FPR1:%[a-z0-9]+]] = load i8* [[TWENTY]]
comment|// CHECK-PPC-NEXT:  [[OVERFLOW_AREA1:%[a-z_0-9]+]] = load i8** [[TWENTYTWO]]
comment|// CHECK-PPC-NEXT:  [[TWENTYFIVE:%[0-9]+]] = ptrtoint i8* [[OVERFLOW_AREA1]] to i32
comment|// CHECK-PPC-NEXT:  [[REGSAVE_AREA1:%[a-z_0-9]+]] = load i8** [[TWENTYFOUR]]
comment|// CHECK-PPC-NEXT:  [[TWENTYSIX:%[0-9]+]] = ptrtoint i8* [[REGSAVE_AREA1]] to i32
comment|// CHECK-PPC-NEXT:  [[COND1:%[a-z0-9]+]] = icmp ult i8 [[GPR1]], 8
comment|// CHECK-PPC-NEXT:  [[TWENTYSEVEN:%[0-9]+]] = mul i8 [[GPR1]], 4
comment|// CHECK-PPC-NEXT:  [[TWENTYEIGHT:%[0-9]+]] = sext i8 [[TWENTYSEVEN]] to i32
comment|// CHECK-PPC-NEXT:  [[TWENTYNINE:%[0-9]+]] = add i32 [[TWENTYSIX]], [[TWENTYEIGHT]]
comment|// CHECK-PPC-NEXT:  br i1 [[COND1]], label [[USING_REGS1:%[a-z_0-9]+]], label [[USING_OVERFLOW1:%[a-z_0-9]+]]
comment|//
comment|// CHECK-PPC1:[[USING_REGS1]]:
comment|// CHECK-PPC:  [[THIRTY:%[0-9]+]] = inttoptr i32 [[TWENTYNINE]] to i32*
comment|// CHECK-PPC-NEXT:  [[THIRTYONE:%[0-9]+]] = add i8 [[GPR1]], 1
comment|// CHECK-PPC-NEXT:  store i8 [[THIRTYONE]], i8* [[GPRPTR1]]
comment|// CHECK-PPC-NEXT:  br label [[CONT1:%[a-z0-9]+]]
comment|//
comment|// CHECK-PPC1:[[USING_OVERFLOW1]]:
comment|// CHECK-PPC:  [[THIRTYTWO:%[0-9]+]] = inttoptr i32 [[TWENTYFIVE]] to i32*
comment|// CHECK-PPC-NEXT:  [[THIRTYTHREE:%[0-9]+]] = add i32 [[TWENTYFIVE]], 4
comment|// CHECK-PPC-NEXT:  [[THIRTYFOUR:%[0-9]+]] = inttoptr i32 [[THIRTYTHREE]] to i8*
comment|// CHECK-PPC-NEXT:  store i8* [[THIRTYFOUR]], i8** [[TWENTYTWO]]
comment|// CHECK-PPC-NEXT:  br label [[CONT1]]
comment|//
comment|// CHECK-PPC1:[[CONT1]]:
comment|// CHECK-PPC:  [[VAARG_ADDR1:%[a-z.0-9]+]] = phi i32* [ [[THIRTY]], [[USING_REGS1]] ], [ [[THIRTYTWO]], [[USING_OVERFLOW1]] ]
comment|// CHECK-PPC-NEXT:  [[THIRTYFIVE:%[0-9]+]] = load i32* [[VAARG_ADDR1]]
comment|// CHECK-PPC-NEXT:  store i32 [[THIRTYFIVE]], i32* %v, align 4
ifdef|#
directive|ifdef
name|__powerpc64__
name|__int128_t
name|u
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__int128_t
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|// CHECK: bitcast i8* %{{[a-z.0-9]+}} to i128*
comment|// CHECK-NEXT: load i128* %{{[0-9]+}}
block|}
end_function

end_unit

