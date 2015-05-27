begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -DDECLARE_SETJMP -triple i686-windows-msvc   -emit-llvm %s -o - | FileCheck --check-prefix=I386 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -DDECLARE_SETJMP -triple x86_64-windows-msvc -emit-llvm %s -o - | FileCheck --check-prefix=X64 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -triple i686-windows-msvc   -emit-llvm %s -o - | FileCheck --check-prefix=I386 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -triple x86_64-windows-msvc -emit-llvm %s -o - | FileCheck --check-prefix=X64 %s
end_comment

begin_typedef
typedef|typedef
name|char
name|jmp_buf
index|[
literal|1
index|]
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|DECLARE_SETJMP
end_ifdef

begin_function_decl
name|int
name|_setjmp
parameter_list|(
name|jmp_buf
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_setjmpex
parameter_list|(
name|jmp_buf
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|jmp_buf
name|jb
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test_setjmp
parameter_list|()
block|{
return|return
name|_setjmp
argument_list|(
name|jb
argument_list|)
return|;
comment|// I386-LABEL: define i32 @test_setjmp
comment|// I386:       %[[call:.*]] = call i32 (i8*, i32, ...) @_setjmp3(i8* getelementptr inbounds ([1 x i8], [1 x i8]* @jb, i32 0, i32 0), i32 0)
comment|// I386-NEXT:  ret i32 %[[call]]
comment|// X64-LABEL: define i32 @test_setjmp
comment|// X64:       %[[addr:.*]] = call i8* @llvm.frameaddress(i32 0)
comment|// X64:       %[[call:.*]] = call i32 @_setjmp(i8* getelementptr inbounds ([1 x i8], [1 x i8]* @jb, i32 0, i32 0), i8* %[[addr]])
comment|// X64-NEXT:  ret i32 %[[call]]
block|}
end_function

begin_function
name|int
name|test_setjmpex
parameter_list|()
block|{
return|return
name|_setjmpex
argument_list|(
name|jb
argument_list|)
return|;
comment|// X64-LABEL: define i32 @test_setjmpex
comment|// X64:       %[[addr:.*]] = call i8* @llvm.frameaddress(i32 0)
comment|// X64:       %[[call:.*]] = call i32 @_setjmpex(i8* getelementptr inbounds ([1 x i8], [1 x i8]* @jb, i32 0, i32 0), i8* %[[addr]])
comment|// X64-NEXT:  ret i32 %[[call]]
block|}
end_function

end_unit

