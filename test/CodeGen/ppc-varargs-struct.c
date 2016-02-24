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
comment|// CHECK-PPC:  [[ARRAYDECAY:%.+]] = getelementptr inbounds [1 x %struct.__va_list_tag], [1 x %struct.__va_list_tag]* %ap, i32 0, i32 0
comment|// CHECK-PPC-NEXT:  [[GPRPTR:%.+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* [[ARRAYDECAY]], i32 0, i32 0
comment|// CHECK-PPC-NEXT:  [[GPR:%.+]] = load i8, i8* [[GPRPTR]], align 4
comment|// CHECK-PPC-NEXT:  [[COND:%.+]] = icmp ult i8 [[GPR]], 8
comment|// CHECK-PPC-NEXT:  br i1 [[COND]], label %[[USING_REGS:[a-z_0-9]+]], label %[[USING_OVERFLOW:[a-z_0-9]+]]
comment|//
comment|// CHECK-PPC:[[USING_REGS]]
comment|// CHECK-PPC-NEXT:  [[REGSAVE_AREA_P:%.+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* [[ARRAYDECAY]], i32 0, i32 4
comment|// CHECK-PPC-NEXT:  [[REGSAVE_AREA:%.+]] = load i8*, i8** [[REGSAVE_AREA_P]], align 4
comment|// CHECK-PPC-NEXT:  [[OFFSET:%.+]] = mul i8 [[GPR]], 4
comment|// CHECK-PPC-NEXT:  [[RAW_REGADDR:%.+]] = getelementptr inbounds i8, i8* [[REGSAVE_AREA]], i8 [[OFFSET]]
comment|// CHECK-PPC-NEXT:  [[REGADDR:%.+]] = bitcast i8* [[RAW_REGADDR]] to %struct.x**
comment|// CHECK-PPC-NEXT:  [[USED_GPR:%[0-9]+]] = add i8 [[GPR]], 1
comment|// CHECK-PPC-NEXT:  store i8 [[USED_GPR]], i8* [[GPRPTR]], align 4
comment|// CHECK-PPC-NEXT:  br label %[[CONT:[a-z0-9]+]]
comment|//
comment|// CHECK-PPC:[[USING_OVERFLOW]]
comment|// CHECK-PPC-NEXT:  store i8 8, i8* [[GPRPTR]], align 4
comment|// CHECK-PPC-NEXT:  [[OVERFLOW_AREA_P:%[0-9]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* [[ARRAYDECAY]], i32 0, i32 3
comment|// CHECK-PPC-NEXT:  [[OVERFLOW_AREA:%.+]] = load i8*, i8** [[OVERFLOW_AREA_P]], align 4
comment|// CHECK-PPC-NEXT:  %{{[0-9]+}} =  ptrtoint i8* %argp.cur to i32
comment|// CHECK-PPC-NEXT:  %{{[0-9]+}} = add i32 %{{[0-9]+}}, 7
comment|// CHECK-PPC-NEXT:  %{{[0-9]+}} = and i32 %{{[0-9]+}}, -8
comment|// CHECK-PPC-NEXT:  %argp.cur.aligned = inttoptr i32 %{{[0-9]+}} to i8*
comment|// CHECK-PPC-NEXT:  [[MEMADDR:%.+]] = bitcast i8* %argp.cur.aligned to %struct.x**
comment|// CHECK-PPC-NEXT:  [[NEW_OVERFLOW_AREA:%[0-9]+]] = getelementptr inbounds i8, i8* %argp.cur.aligned, i32 4
comment|// CHECK-PPC-NEXT:  store i8* [[NEW_OVERFLOW_AREA:%[0-9]+]], i8** [[OVERFLOW_AREA_P]], align 4
comment|// CHECK-PPC-NEXT:  br label %[[CONT]]
comment|//
comment|// CHECK-PPC:[[CONT]]
comment|// CHECK-PPC-NEXT:  [[VAARG_ADDR:%[a-z.0-9]+]] = phi %struct.x** [ [[REGADDR]], %[[USING_REGS]] ], [ [[MEMADDR]], %[[USING_OVERFLOW]] ]
comment|// CHECK-PPC-NEXT:  [[AGGR:%[a-z0-9]+]] = load %struct.x*, %struct.x** [[VAARG_ADDR]]
comment|// CHECK-PPC-NEXT:  [[DEST:%[0-9]+]] = bitcast %struct.x* %t to i8*
comment|// CHECK-PPC-NEXT:  [[SRC:%.+]] = bitcast %struct.x* [[AGGR]] to i8*
comment|// CHECK-PPC-NEXT:  call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[DEST]], i8* [[SRC]], i32 16, i32 8, i1 false)
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
comment|// CHECK: getelementptr inbounds i8, i8* %{{[a-z.0-9]*}}, i64 4
comment|// CHECK: bitcast i8* %{{[0-9]+}} to i32*
comment|// CHECK-PPC:       [[ARRAYDECAY:%[a-z0-9]+]] = getelementptr inbounds [1 x %struct.__va_list_tag], [1 x %struct.__va_list_tag]* %ap, i32 0, i32 0
comment|// CHECK-PPC-NEXT:  [[GPRPTR:%.+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* [[ARRAYDECAY]], i32 0, i32 0
comment|// CHECK-PPC-NEXT:  [[GPR:%.+]] = load i8, i8* [[GPRPTR]], align 4
comment|// CHECK-PPC-NEXT:  [[COND:%.+]] = icmp ult i8 [[GPR]], 8
comment|// CHECK-PPC-NEXT:  br i1 [[COND]], label %[[USING_REGS:.+]], label %[[USING_OVERFLOW:.+]]{{$}}
comment|//
comment|// CHECK-PPC:[[USING_REGS]]
comment|// CHECK-PPC-NEXT:  [[REGSAVE_AREA_P:%.+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* [[ARRAYDECAY]], i32 0, i32 4
comment|// CHECK-PPC-NEXT:  [[REGSAVE_AREA:%.+]] = load i8*, i8** [[REGSAVE_AREA_P]], align 4
comment|// CHECK-PPC-NEXT:  [[OFFSET:%.+]] = mul i8 [[GPR]], 4
comment|// CHECK-PPC-NEXT:  [[RAW_REGADDR:%.+]] = getelementptr inbounds i8, i8* [[REGSAVE_AREA]], i8 [[OFFSET]]
comment|// CHECK-PPC-NEXT:  [[REGADDR:%.+]] = bitcast i8* [[RAW_REGADDR]] to i32*
comment|// CHECK-PPC-NEXT:  [[USED_GPR:%[0-9]+]] = add i8 [[GPR]], 1
comment|// CHECK-PPC-NEXT:  store i8 [[USED_GPR]], i8* [[GPRPTR]], align 4
comment|// CHECK-PPC-NEXT:  br label %[[CONT:[a-z0-9]+]]
comment|//
comment|// CHECK-PPC:[[USING_OVERFLOW]]
comment|// CHECK-PPC-NEXT:  store i8 8, i8* [[GPRPTR]], align 4
comment|// CHECK-PPC-NEXT:  [[OVERFLOW_AREA_P:%[0-9]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* [[ARRAYDECAY]], i32 0, i32 3
comment|// CHECK-PPC-NEXT:  [[OVERFLOW_AREA:%.+]] = load i8*, i8** [[OVERFLOW_AREA_P]], align 4
comment|// CHECK-PPC-NEXT:  [[MEMADDR:%.+]] = bitcast i8* [[OVERFLOW_AREA]] to i32*
comment|// CHECK-PPC-NEXT:  [[NEW_OVERFLOW_AREA:%[0-9]+]] = getelementptr inbounds i8, i8* [[OVERFLOW_AREA]], i32 4
comment|// CHECK-PPC-NEXT:  store i8* [[NEW_OVERFLOW_AREA]], i8** [[OVERFLOW_AREA_P]]
comment|// CHECK-PPC-NEXT:  br label %[[CONT]]
comment|//
comment|// CHECK-PPC:[[CONT]]
comment|// CHECK-PPC-NEXT:  [[VAARG_ADDR:%[a-z.0-9]+]] = phi i32* [ [[REGADDR]], %[[USING_REGS]] ], [ [[MEMADDR]], %[[USING_OVERFLOW]] ]
comment|// CHECK-PPC-NEXT:  [[THIRTYFIVE:%[0-9]+]] = load i32, i32* [[VAARG_ADDR]]
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
comment|// CHECK-NEXT: load i128, i128* %{{[0-9]+}}
block|}
end_function

end_unit

