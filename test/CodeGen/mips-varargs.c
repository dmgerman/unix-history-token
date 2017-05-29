begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mips-unknown-linux -o - -emit-llvm %s | FileCheck %s -check-prefixes=ALL,O32 -enable-var-scope
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mipsel-unknown-linux -o - -emit-llvm %s | FileCheck %s -check-prefixes=ALL,O32 -enable-var-scope
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-linux -o - -emit-llvm  -target-abi n32 %s | FileCheck %s -check-prefixes=ALL,N32,NEW -enable-var-scope
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-linux -o - -emit-llvm  -target-abi n32 %s | FileCheck %s -check-prefixes=ALL,N32,NEW -enable-var-scope
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-linux -o - -emit-llvm %s | FileCheck %s -check-prefixes=ALL,N64,NEW -enable-var-scope
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64el-unknown-linux -o - -emit-llvm %s | FileCheck %s -check-prefixes=ALL,N64,NEW -enable-var-scope
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
comment|// O32:   %va = alloca i8*, align [[$PTRALIGN:4]]
end_comment

begin_comment
comment|// N32:   %va = alloca i8*, align [[$PTRALIGN:4]]
end_comment

begin_comment
comment|// N64:   %va = alloca i8*, align [[$PTRALIGN:8]]
end_comment

begin_comment
comment|// ALL:   [[V:%.*]] = alloca i32, align 4
end_comment

begin_comment
comment|// NEW:   [[PROMOTION_TEMP:%.*]] = alloca i32, align 4
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[VA:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_start(i8* [[VA]])
end_comment

begin_comment
comment|// ALL:   [[AP_CUR:%.+]] = load i8*, i8** %va, align [[$PTRALIGN]]
end_comment

begin_comment
comment|// O32:   [[AP_NEXT:%.+]] = getelementptr inbounds i8, i8* [[AP_CUR]], [[$INTPTR_T:i32]] [[$CHUNKSIZE:4]]
end_comment

begin_comment
comment|// NEW:   [[AP_NEXT:%.+]] = getelementptr inbounds i8, i8* [[AP_CUR]], [[$INTPTR_T:i32|i64]] [[$CHUNKSIZE:8]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   store i8* [[AP_NEXT]], i8** %va, align [[$PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32:   [[AP_CAST:%.+]] = bitcast i8* [[AP_CUR]] to [[CHUNK_T:i32]]*
end_comment

begin_comment
comment|// O32:   [[ARG:%.+]] = load i32, i32* [[AP_CAST]], align [[CHUNKALIGN:4]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// N32:   [[AP_CAST:%.+]] = bitcast i8* [[AP_CUR]] to [[CHUNK_T:i64]]*
end_comment

begin_comment
comment|// N32:   [[TMP:%.+]] = load i64, i64* [[AP_CAST]], align [[CHUNKALIGN:8]]
end_comment

begin_comment
comment|// N64:   [[AP_CAST:%.+]] = bitcast i8* [[AP_CUR]] to [[CHUNK_T:i64]]*
end_comment

begin_comment
comment|// N64:   [[TMP:%.+]] = load i64, i64* [[AP_CAST]], align [[CHUNKALIGN:8]]
end_comment

begin_comment
comment|// NEW:   [[TMP2:%.+]] = trunc i64 [[TMP]] to i32
end_comment

begin_comment
comment|// NEW:   store i32 [[TMP2]], i32* [[PROMOTION_TEMP]], align 4
end_comment

begin_comment
comment|// NEW:   [[ARG:%.+]] = load i32, i32* [[PROMOTION_TEMP]], align 4
end_comment

begin_comment
comment|// ALL:   store i32 [[ARG]], i32* [[V]], align 4
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[VA1:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_end(i8* [[VA1]])
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
comment|// ALL:   %va = alloca i8*, align [[$PTRALIGN]]
end_comment

begin_comment
comment|// ALL:   [[VA:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_start(i8* [[VA]])
end_comment

begin_comment
comment|// ALL:   [[AP_CUR:%.+]] = load i8*, i8** %va, align [[$PTRALIGN]]
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
comment|// O32:   [[TMP1:%.+]] = ptrtoint i8* [[AP_CUR]] to i32
end_comment

begin_comment
comment|// O32:   [[TMP2:%.+]] = add i32 [[TMP1]], 7
end_comment

begin_comment
comment|// O32:   [[TMP3:%.+]] = and i32 [[TMP2]], -8
end_comment

begin_comment
comment|// O32:   [[AP_CUR:%.+]] = inttoptr i32 [[TMP3]] to i8*
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[AP_NEXT:%.+]] = getelementptr inbounds i8, i8* [[AP_CUR]], [[$INTPTR_T]] 8
end_comment

begin_comment
comment|// ALL:   store i8* [[AP_NEXT]], i8** %va, align [[$PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[AP_CAST:%.*]] = bitcast i8* [[AP_CUR]] to i64*
end_comment

begin_comment
comment|// ALL:   [[ARG:%.+]] = load i64, i64* [[AP_CAST]], align 8
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[VA1:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_end(i8* [[VA1]])
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
comment|// ALL:   %va = alloca i8*, align [[$PTRALIGN]]
end_comment

begin_comment
comment|// ALL:   [[V:%.*]] = alloca i8*, align [[$PTRALIGN]]
end_comment

begin_comment
comment|// N32:   [[AP_CAST:%.+]] = alloca i8*, align 4
end_comment

begin_comment
comment|// ALL:   [[VA:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_start(i8* [[VA]])
end_comment

begin_comment
comment|// ALL:   [[AP_CUR:%.+]] = load i8*, i8** %va, align [[$PTRALIGN]]
end_comment

begin_comment
comment|// ALL:   [[AP_NEXT:%.+]] = getelementptr inbounds i8, i8* [[AP_CUR]], [[$INTPTR_T]] [[$CHUNKSIZE]]
end_comment

begin_comment
comment|// ALL:   store i8* [[AP_NEXT]], i8** %va, align [[$PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When the chunk size matches the pointer size, this is easy.
end_comment

begin_comment
comment|// O32:   [[AP_CAST:%.+]] = bitcast i8* [[AP_CUR]] to i8**
end_comment

begin_comment
comment|// N64:   [[AP_CAST:%.+]] = bitcast i8* [[AP_CUR]] to i8**
end_comment

begin_comment
comment|// Otherwise we need a promotion temporary.
end_comment

begin_comment
comment|// N32:   [[TMP1:%.+]] = bitcast i8* [[AP_CUR]] to i64*
end_comment

begin_comment
comment|// N32:   [[TMP2:%.+]] = load i64, i64* [[TMP1]], align 8
end_comment

begin_comment
comment|// N32:   [[TMP3:%.+]] = trunc i64 [[TMP2]] to i32
end_comment

begin_comment
comment|// N32:   [[PTR:%.+]] = inttoptr i32 [[TMP3]] to i8*
end_comment

begin_comment
comment|// N32:   store i8* [[PTR]], i8** [[AP_CAST]], align 4
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[ARG:%.+]] = load i8*, i8** [[AP_CAST]], align [[$PTRALIGN]]
end_comment

begin_comment
comment|// ALL:   store i8* [[ARG]], i8** [[V]], align [[$PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[VA1:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_end(i8* [[VA1]])
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
comment|// ALL:   %va = alloca i8*, align [[$PTRALIGN]]
end_comment

begin_comment
comment|// ALL:   [[V:%.+]] = alloca<4 x i32>, align 16
end_comment

begin_comment
comment|// ALL:   [[VA1:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_start(i8* [[VA1]])
end_comment

begin_comment
comment|// ALL:   [[AP_CUR:%.+]] = load i8*, i8** %va, align [[$PTRALIGN]]
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
comment|// O32:   [[TMP1:%.+]] = ptrtoint i8* [[AP_CUR]] to i32
end_comment

begin_comment
comment|// O32:   [[TMP2:%.+]] = add i32 [[TMP1]], 7
end_comment

begin_comment
comment|// O32:   [[TMP3:%.+]] = and i32 [[TMP2]], -8
end_comment

begin_comment
comment|// O32:   [[AP_CUR:%.+]] = inttoptr i32 [[TMP3]] to i8*
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NEW:   [[TMP1:%.+]] = ptrtoint i8* [[AP_CUR]] to [[$INTPTR_T]]
end_comment

begin_comment
comment|// NEW:   [[TMP2:%.+]] = add [[$INTPTR_T]] [[TMP1]], 15
end_comment

begin_comment
comment|// NEW:   [[TMP3:%.+]] = and [[$INTPTR_T]] [[TMP2]], -16
end_comment

begin_comment
comment|// NEW:   [[AP_CUR:%.+]] = inttoptr [[$INTPTR_T]] [[TMP3]] to i8*
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[AP_NEXT:%.+]] = getelementptr inbounds i8, i8* [[AP_CUR]], [[$INTPTR_T]] 16
end_comment

begin_comment
comment|// ALL:   store i8* [[AP_NEXT]], i8** %va, align [[$PTRALIGN]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[AP_CAST:%.+]] = bitcast i8* [[AP_CUR]] to<4 x i32>*
end_comment

begin_comment
comment|// O32:   [[ARG:%.+]] = load<4 x i32>,<4 x i32>* [[AP_CAST]], align 8
end_comment

begin_comment
comment|// N64:   [[ARG:%.+]] = load<4 x i32>,<4 x i32>* [[AP_CAST]], align 16
end_comment

begin_comment
comment|// N32:   [[ARG:%.+]] = load<4 x i32>,<4 x i32>* [[AP_CAST]], align 16
end_comment

begin_comment
comment|// ALL:   store<4 x i32> [[ARG]],<4 x i32>* [[V]], align 16
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ALL:   [[VA1:%.+]] = bitcast i8** %va to i8*
end_comment

begin_comment
comment|// ALL:   call void @llvm.va_end(i8* [[VA1]])
end_comment

begin_comment
comment|// ALL:   [[VECEXT:%.+]] = extractelement<4 x i32> {{.*}}, i32 0
end_comment

begin_comment
comment|// ALL:   ret i32 [[VECEXT]]
end_comment

begin_comment
comment|// ALL: }
end_comment

end_unit

