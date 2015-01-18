begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mips-unknown-linux -o - -O1 -emit-llvm %s | FileCheck %s -check-prefix=ALL -check-prefix=O32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mipsel-unknown-linux -o - -O1 -emit-llvm %s | FileCheck %s -check-prefix=ALL -check-prefix=O32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-linux -o - -O1 -emit-llvm  -target-abi n32 %s | FileCheck %s -check-prefix=ALL -check-prefix=N32 -check-prefix=NEW
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-linux -o - -O1 -emit-llvm  -target-abi n32 %s | FileCheck %s -check-prefix=ALL -check-prefix=N32 -check-prefix=NEW
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-linux -o - -O1 -emit-llvm %s | FileCheck %s -check-prefix=ALL -check-prefix=N64 -check-prefix=NEW
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64el-unknown-linux -o - -O1 -emit-llvm %s | FileCheck %s -check-prefix=ALL -check-prefix=N64 -check-prefix=NEW
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_typedef
typedef|typedef
name|int
name|v4i32
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_function
name|int
name|test_i32
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|int
name|v
init|=
name|va_arg
argument_list|(
name|va
argument_list|,
name|int
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_comment
comment|// ALL-LABEL: define i32 @test_i32(i8*{{.*}} %fmt, ...)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   %va = alloca i8*, align [[PTRALIGN:4]]
end_comment

begin_comment
comment|// N32:   %va = alloca i8*, align [[PTRALIGN:4]]
end_comment

begin_comment
comment|// N64:   %va = alloca i8*, align [[PTRALIGN:8]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[VA1:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_start(i8* [[VA1]])
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[TMP0:%.+]] = bitcast i8** %va to i32**
end_comment

begin_comment
comment|// O32:   [[AP_CUR:%.+]] = load i32** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|// NEW:   [[TMP0:%.+]] = bitcast i8** %va to i64**
end_comment

begin_comment
comment|// NEW:   [[AP_CUR:%.+]] = load i64** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[AP_NEXT:%.+]] = getelementptr i32* [[AP_CUR]], i32 1
end_comment

begin_comment
comment|// NEW:   [[AP_NEXT:%.+]] = getelementptr i64* [[AP_CUR]], {{i32|i64}} 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   store i32* [[AP_NEXT]], i32** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|// NEW:   store i64* [[AP_NEXT]], i64** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[ARG1:%.+]] = load i32* [[AP_CUR]], align 4
end_comment

begin_comment
comment|// NEW:   [[TMP2:%.+]] = load i64* [[AP_CUR]], align 8
end_comment

begin_comment
comment|// NEW:   [[ARG1:%.+]] = trunc i64 [[TMP2]] to i32
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_end(i8* [[VA1]])
end_comment

begin_comment
comment|// ALL:   ret i32 [[ARG1]]
end_comment

begin_comment
comment|// ALL: }
end_comment

begin_function
name|int
name|test_i32_2args
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|int
name|v1
init|=
name|va_arg
argument_list|(
name|va
argument_list|,
name|int
argument_list|)
decl_stmt|;
name|int
name|v2
init|=
name|va_arg
argument_list|(
name|va
argument_list|,
name|int
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
return|return
name|v1
operator|+
name|v2
return|;
block|}
end_function

begin_comment
comment|// ALL-LABEL: define i32 @test_i32_2args(i8*{{.*}} %fmt, ...)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   %va = alloca i8*, align [[PTRALIGN]]
end_comment

begin_comment
comment|// ALL:   [[VA1:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_start(i8* [[VA1]])
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[TMP0:%.+]] = bitcast i8** %va to i32**
end_comment

begin_comment
comment|// O32:   [[AP_CUR:%.+]] = load i32** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|// NEW:   [[TMP0:%.+]] = bitcast i8** %va to i64**
end_comment

begin_comment
comment|// NEW:   [[AP_CUR:%.+]] = load i64** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[AP_NEXT1:%.+]] = getelementptr i32* [[AP_CUR]], i32 1
end_comment

begin_comment
comment|// NEW:   [[AP_NEXT1:%.+]] = getelementptr i64* [[AP_CUR]], [[INTPTR_T:i32|i64]] 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   store i32* [[AP_NEXT1]], i32** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|// FIXME: N32 optimised this store out. Why only for this ABI?
end_comment

begin_comment
comment|// N64:   store i64* [[AP_NEXT1]], i64** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[ARG1:%.+]] = load i32* [[AP_CUR]], align 4
end_comment

begin_comment
comment|// NEW:   [[TMP3:%.+]] = load i64* [[AP_CUR]], align 8
end_comment

begin_comment
comment|// NEW:   [[ARG1:%.+]] = trunc i64 [[TMP3]] to i32
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[AP_NEXT2:%.+]] = getelementptr i32* [[AP_CUR]], i32 2
end_comment

begin_comment
comment|// NEW:   [[AP_NEXT2:%.+]] = getelementptr i64* [[AP_CUR]], [[INTPTR_T]] 2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   store i32* [[AP_NEXT2]], i32** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|// NEW:   store i64* [[AP_NEXT2]], i64** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[ARG2:%.+]] = load i32* [[AP_NEXT1]], align 4
end_comment

begin_comment
comment|// NEW:   [[TMP4:%.+]] = load i64* [[AP_NEXT1]], align 8
end_comment

begin_comment
comment|// NEW:   [[ARG2:%.+]] = trunc i64 [[TMP4]] to i32
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_end(i8* [[VA1]])
end_comment

begin_comment
comment|// ALL:   [[ADD:%.+]] = add nsw i32 [[ARG2]], [[ARG1]]
end_comment

begin_comment
comment|// ALL:   ret i32 [[ADD]]
end_comment

begin_comment
comment|// ALL: }
end_comment

begin_function
name|long
name|long
name|test_i64
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|long
name|long
name|v
init|=
name|va_arg
argument_list|(
argument|va
argument_list|,
argument|long long
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_comment
comment|// ALL-LABEL: define i64 @test_i64(i8*{{.*}} %fmt, ...)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   %va = alloca i8*, align [[PTRALIGN]]
end_comment

begin_comment
comment|// ALL:   [[VA1:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_start(i8* [[VA1]])
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[AP_CUR:%.+]] = load i8** %va, align [[PTRALIGN]]
end_comment

begin_comment
comment|// NEW:   [[TMP0:%.+]] = bitcast i8** %va to i64**
end_comment

begin_comment
comment|// NEW:   [[AP_CUR:%.+]] = load i64** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// i64 is 8-byte aligned, while this is within O32's stack alignment there's no
end_comment

begin_comment
comment|// guarantee that the offset is still 8-byte aligned after earlier reads.
end_comment

begin_comment
comment|// O32:   [[PTR0:%.+]] = ptrtoint i8* [[AP_CUR]] to [[INTPTR_T:i32]]
end_comment

begin_comment
comment|// O32:   [[PTR1:%.+]] = add i32 [[PTR0]], 7
end_comment

begin_comment
comment|// O32:   [[PTR2:%.+]] = and i32 [[PTR1]], -8
end_comment

begin_comment
comment|// O32:   [[PTR3:%.+]] = inttoptr [[INTPTR_T]] [[PTR2]] to i64*
end_comment

begin_comment
comment|// O32:   [[PTR4:%.+]] = inttoptr [[INTPTR_T]] [[PTR2]] to i8*
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[AP_NEXT:%.+]] = getelementptr i8* [[PTR4]], [[INTPTR_T]] 8
end_comment

begin_comment
comment|// NEW:   [[AP_NEXT:%.+]] = getelementptr i64* [[AP_CUR]], [[INTPTR_T:i32|i64]] 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   store i8* [[AP_NEXT]], i8** %va, align [[PTRALIGN]]
end_comment

begin_comment
comment|// NEW:   store i64* [[AP_NEXT]], i64** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[ARG1:%.+]] = load i64* [[PTR3]], align 8
end_comment

begin_comment
comment|// NEW:   [[ARG1:%.+]] = load i64* [[AP_CUR]], align 8
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_end(i8* [[VA1]])
end_comment

begin_comment
comment|// ALL:   ret i64 [[ARG1]]
end_comment

begin_comment
comment|// ALL: }
end_comment

begin_function
name|char
modifier|*
name|test_ptr
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|char
modifier|*
name|v
init|=
name|va_arg
argument_list|(
name|va
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_comment
comment|// ALL-LABEL: define i8* @test_ptr(i8*{{.*}} %fmt, ...)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   %va = alloca i8*, align [[PTRALIGN:4]]
end_comment

begin_comment
comment|// N32:   %va = alloca i8*, align [[PTRALIGN:4]]
end_comment

begin_comment
comment|// N64:   %va = alloca i8*, align [[PTRALIGN:8]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[VA1:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_start(i8* [[VA1]])
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[TMP0:%.+]] = bitcast i8** %va to i8***
end_comment

begin_comment
comment|// O32:   [[AP_CUR:%.+]] = load i8*** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|// N32 differs because the vararg is not a N32 pointer. It's been promoted to 64-bit.
end_comment

begin_comment
comment|// N32:   [[TMP0:%.+]] = bitcast i8** %va to i64**
end_comment

begin_comment
comment|// N32:   [[AP_CUR:%.+]] = load i64** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|// N64:   [[TMP0:%.+]] = bitcast i8** %va to i8***
end_comment

begin_comment
comment|// N64:   [[AP_CUR:%.+]] = load i8*** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[AP_NEXT:%.+]] = getelementptr i8** [[AP_CUR]], i32 1
end_comment

begin_comment
comment|// N32 differs because the vararg is not a N32 pointer. It's been promoted to 64-bit.
end_comment

begin_comment
comment|// N32:   [[AP_NEXT:%.+]] = getelementptr i64* [[AP_CUR]], {{i32|i64}} 1
end_comment

begin_comment
comment|// N64:   [[AP_NEXT:%.+]] = getelementptr i8** [[AP_CUR]], {{i32|i64}} 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   store i8** [[AP_NEXT]], i8*** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|// N32 differs because the vararg is not a N32 pointer. It's been promoted to 64-bit.
end_comment

begin_comment
comment|// N32:   store i64* [[AP_NEXT]], i64** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|// N64:   store i8** [[AP_NEXT]], i8*** [[TMP0]], align [[PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[ARG1:%.+]] = load i8** [[AP_CUR]], align 4
end_comment

begin_comment
comment|// N32 differs because the vararg is not a N32 pointer. It's been promoted to
end_comment

begin_comment
comment|// 64-bit so we must truncate the excess and bitcast to a N32 pointer.
end_comment

begin_comment
comment|// N32:   [[TMP2:%.+]] = load i64* [[AP_CUR]], align 8
end_comment

begin_comment
comment|// N32:   [[TMP3:%.+]] = trunc i64 [[TMP2]] to i32
end_comment

begin_comment
comment|// N32:   [[ARG1:%.+]] = inttoptr i32 [[TMP3]] to i8*
end_comment

begin_comment
comment|// N64:   [[ARG1:%.+]] = load i8** [[AP_CUR]], align 8
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_end(i8* [[VA1]])
end_comment

begin_comment
comment|// ALL:   ret i8* [[ARG1]]
end_comment

begin_comment
comment|// ALL: }
end_comment

begin_function
name|int
name|test_v4i32
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|v4i32
name|v
init|=
name|va_arg
argument_list|(
name|va
argument_list|,
name|v4i32
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
return|return
name|v
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|// ALL-LABEL: define i32 @test_v4i32(i8*{{.*}} %fmt, ...)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   %va = alloca i8*, align [[PTRALIGN]]
end_comment

begin_comment
comment|// ALL:   [[VA1:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_start(i8* [[VA1]])
end_comment

begin_comment
comment|// ALL:   [[AP_CUR:%.+]] = load i8** %va, align [[PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[PTR0:%.+]] = ptrtoint i8* [[AP_CUR]] to [[INTPTR_T:i32]]
end_comment

begin_comment
comment|// N32:   [[PTR0:%.+]] = ptrtoint i8* [[AP_CUR]] to [[INTPTR_T:i32]]
end_comment

begin_comment
comment|// N64:   [[PTR0:%.+]] = ptrtoint i8* [[AP_CUR]] to [[INTPTR_T:i64]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Vectors are 16-byte aligned, however the O32 ABI has a maximum alignment of
end_comment

begin_comment
comment|// 8-bytes since the base of the stack is 8-byte aligned.
end_comment

begin_comment
comment|// O32:   [[PTR1:%.+]] = add i32 [[PTR0]], 7
end_comment

begin_comment
comment|// O32:   [[PTR2:%.+]] = and i32 [[PTR1]], -8
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NEW:   [[PTR1:%.+]] = add [[INTPTR_T]] [[PTR0]], 15
end_comment

begin_comment
comment|// NEW:   [[PTR2:%.+]] = and [[INTPTR_T]] [[PTR1]], -16
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[PTR3:%.+]] = inttoptr [[INTPTR_T]] [[PTR2]] to<4 x i32>*
end_comment

begin_comment
comment|// ALL:   [[PTR4:%.+]] = inttoptr [[INTPTR_T]] [[PTR2]] to i8*
end_comment

begin_comment
comment|// ALL:   [[AP_NEXT:%.+]] = getelementptr i8* [[PTR4]], [[INTPTR_T]] 16
end_comment

begin_comment
comment|// ALL:   store i8* [[AP_NEXT]], i8** %va, align [[PTRALIGN]]
end_comment

begin_comment
comment|// ALL:   [[PTR5:%.+]] = load<4 x i32>* [[PTR3]], align 16
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_end(i8* [[VA1]])
end_comment

begin_comment
comment|// ALL:   [[VECEXT:%.+]] = extractelement<4 x i32> [[PTR5]], i32 0
end_comment

begin_comment
comment|// ALL:   ret i32 [[VECEXT]]
end_comment

begin_comment
comment|// ALL: }
end_comment

end_unit

