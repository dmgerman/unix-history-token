begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

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
specifier|_Complex
name|int
name|i
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
specifier|_Complex
name|int
argument_list|)
decl_stmt|;
comment|// CHECK: %[[VAR40:[A-Za-z0-9.]+]] = load i8*, i8** %[[VAR100:[A-Za-z0-9.]+]]
comment|// CHECK-NEXT: %[[VAR41:[A-Za-z0-9.]+]] = getelementptr inbounds i8, i8* %[[VAR40]], i64 16
comment|// CHECK-NEXT: store i8* %[[VAR41]], i8** %[[VAR100]]
comment|// CHECK-NEXT: %[[VAR3:[A-Za-z0-9.]+]] = getelementptr inbounds i8, i8* %[[VAR40]], i64 8
comment|// CHECK-NEXT: %[[VAR4:[A-Za-z0-9.]+]] = bitcast i8* %[[VAR40]] to i32*
comment|// CHECK-NEXT: %[[VAR5:[A-Za-z0-9.]+]] = bitcast i8* %[[VAR3]] to i32*
comment|// CHECK-NEXT: %[[VAR6:[A-Za-z0-9.]+]] = load i32, i32* %[[VAR4]], align 8
comment|// CHECK-NEXT: %[[VAR7:[A-Za-z0-9.]+]] = load i32, i32* %[[VAR5]], align 8
comment|// CHECK-NEXT: %[[VAR8:[A-Za-z0-9.]+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* %[[VAR0:[A-Za-z0-9.]+]], i32 0, i32 0
comment|// CHECK-NEXT: %[[VAR9:[A-Za-z0-9.]+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* %[[VAR0]], i32 0, i32 1
comment|// CHECK-NEXT: store i32 %[[VAR6]], i32* %[[VAR8]]
comment|// CHECK-NEXT: store i32 %[[VAR7]], i32* %[[VAR9]]
specifier|_Complex
name|short
name|s
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
specifier|_Complex
name|short
argument_list|)
decl_stmt|;
comment|// CHECK: %[[VAR50:[A-Za-z0-9.]+]] = load i8*, i8** %[[VAR100:[A-Za-z0-9.]+]]
comment|// CHECK-NEXT: %[[VAR51:[A-Za-z0-9.]+]] = getelementptr inbounds i8, i8* %[[VAR50]], i64 16
comment|// CHECK-NEXT: store i8* %[[VAR51]], i8** %[[VAR100]]
comment|// CHECK-NEXT: %[[VAR13:[A-Za-z0-9.]+]] = getelementptr inbounds i8, i8* %[[VAR50]], i64 8
comment|// CHECK-NEXT: %[[VAR14:[A-Za-z0-9.]+]] = bitcast i8* %[[VAR50]] to i16*
comment|// CHECK-NEXT: %[[VAR15:[A-Za-z0-9.]+]] = bitcast i8* %[[VAR13]] to i16*
comment|// CHECK-NEXT: %[[VAR16:[A-Za-z0-9.]+]] = load i16, i16* %[[VAR14]], align 8
comment|// CHECK-NEXT: %[[VAR17:[A-Za-z0-9.]+]] = load i16, i16* %[[VAR15]], align 8
comment|// CHECK-NEXT: %[[VAR18:[A-Za-z0-9.]+]] = getelementptr inbounds { i16, i16 }, { i16, i16 }* %[[VAR10:[A-Za-z0-9.]+]], i32 0, i32 0
comment|// CHECK-NEXT: %[[VAR19:[A-Za-z0-9.]+]] = getelementptr inbounds { i16, i16 }, { i16, i16 }* %[[VAR10]], i32 0, i32 1
comment|// CHECK-NEXT: store i16 %[[VAR16]], i16* %[[VAR18]]
comment|// CHECK-NEXT: store i16 %[[VAR17]], i16* %[[VAR19]]
specifier|_Complex
name|char
name|c
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
specifier|_Complex
name|char
argument_list|)
decl_stmt|;
comment|// CHECK: %[[VAR60:[A-Za-z0-9.]+]] = load i8*, i8** %[[VAR100:[A-Za-z0-9.]+]]
comment|// CHECK-NEXT: %[[VAR61:[A-Za-z0-9.]+]] = getelementptr inbounds i8, i8* %[[VAR60]], i64 16
comment|// CHECK-NEXT: store i8* %[[VAR61]], i8** %[[VAR100]]
comment|// CHECK-NEXT: %[[VAR25:[A-Za-z0-9.]+]] = getelementptr inbounds i8, i8* %[[VAR60]], i64 8
comment|// CHECK-NEXT: %[[VAR26:[A-Za-z0-9.]+]] = load i8, i8* %[[VAR60]], align 8
comment|// CHECK-NEXT: %[[VAR27:[A-Za-z0-9.]+]] = load i8, i8* %[[VAR25]], align 8
comment|// CHECK-NEXT: %[[VAR28:[A-Za-z0-9.]+]] = getelementptr inbounds { i8, i8 }, { i8, i8 }* %[[VAR20:[A-Za-z0-9.]+]], i32 0, i32 0
comment|// CHECK-NEXT: %[[VAR29:[A-Za-z0-9.]+]] = getelementptr inbounds { i8, i8 }, { i8, i8 }* %[[VAR20]], i32 0, i32 1
comment|// CHECK-NEXT: store i8 %[[VAR26]], i8* %[[VAR28]]
comment|// CHECK-NEXT: store i8 %[[VAR27]], i8* %[[VAR29]]
specifier|_Complex
name|float
name|f
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
specifier|_Complex
name|float
argument_list|)
decl_stmt|;
comment|// CHECK: %[[VAR70:[A-Za-z0-9.]+]] = load i8*, i8** %[[VAR100:[A-Za-z0-9.]+]]
comment|// CHECK-NEXT: %[[VAR71:[A-Za-z0-9.]+]] = getelementptr inbounds i8, i8* %[[VAR70]], i64 16
comment|// CHECK-NEXT: store i8* %[[VAR71]], i8** %[[VAR100]]
comment|// CHECK-NEXT: %[[VAR33:[A-Za-z0-9.]+]] = getelementptr inbounds i8, i8* %[[VAR70]], i64 8
comment|// CHECK-NEXT: %[[VAR34:[A-Za-z0-9.]+]] = bitcast i8* %[[VAR70]] to float*
comment|// CHECK-NEXT: %[[VAR35:[A-Za-z0-9.]+]] = bitcast i8* %[[VAR33]] to float*
comment|// CHECK-NEXT: %[[VAR36:[A-Za-z0-9.]+]] = load float, float* %[[VAR34]], align 8
comment|// CHECK-NEXT: %[[VAR37:[A-Za-z0-9.]+]] = load float, float* %[[VAR35]], align 8
comment|// CHECK-NEXT: %[[VAR38:[A-Za-z0-9.]+]] = getelementptr inbounds { float, float }, { float, float }* %[[VAR30:[A-Za-z0-9.]+]], i32 0, i32 0
comment|// CHECK-NEXT: %[[VAR39:[A-Za-z0-9.]+]] = getelementptr inbounds { float, float }, { float, float }* %[[VAR30]], i32 0, i32 1
comment|// CHECK-NEXT: store float %[[VAR36]], float* %[[VAR38]]
comment|// CHECK-NEXT: store float %[[VAR37]], float* %[[VAR39]]
block|}
end_function

end_unit

