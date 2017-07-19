begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-linux-gnu -emit-llvm< %s | FileCheck -check-prefix=LINUX %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-pc-win32 -emit-llvm< %s | FileCheck -check-prefix=WIN64 %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|ms_abi
operator|)
argument_list|)
name|f1
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
comment|// LINUX-LABEL: define void @f3()
comment|// WIN64-LABEL: define void @f3()
name|f1
argument_list|()
expr_stmt|;
comment|// LINUX: call win64cc void @f1()
comment|// WIN64: call void @f1()
name|f2
argument_list|()
expr_stmt|;
comment|// LINUX: call void @f2()
comment|// WIN64: call void @f2()
block|}
end_function

begin_comment
comment|// LINUX: declare win64cc void @f1()
end_comment

begin_comment
comment|// LINUX: declare void @f2()
end_comment

begin_comment
comment|// WIN64: declare void @f1()
end_comment

begin_comment
comment|// WIN64: declare void @f2()
end_comment

begin_comment
comment|// Win64 ABI varargs
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|ms_abi
operator|)
argument_list|)
name|f4
argument_list|(
name|int
name|a
argument_list|,
operator|...
argument_list|)
block|{
comment|// LINUX-LABEL: define win64cc void @f4
comment|// WIN64-LABEL: define void @f4
name|__builtin_ms_va_list
name|ap
decl_stmt|;
name|__builtin_ms_va_start
argument_list|(
name|ap
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// LINUX: %[[AP:.*]] = alloca i8*
comment|// LINUX: call void @llvm.va_start
comment|// WIN64: %[[AP:.*]] = alloca i8*
comment|// WIN64: call void @llvm.va_start
name|int
name|b
init|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
name|int
argument_list|)
decl_stmt|;
comment|// LINUX: %[[AP_CUR:.*]] = load i8*, i8** %[[AP]]
comment|// LINUX-NEXT: %[[AP_NEXT:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR]], i64 8
comment|// LINUX-NEXT: store i8* %[[AP_NEXT]], i8** %[[AP]]
comment|// LINUX-NEXT: bitcast i8* %[[AP_CUR]] to i32*
comment|// WIN64: %[[AP_CUR:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: %[[AP_NEXT:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR]], i64 8
comment|// WIN64-NEXT: store i8* %[[AP_NEXT]], i8** %[[AP]]
comment|// WIN64-NEXT: bitcast i8* %[[AP_CUR]] to i32*
name|__builtin_ms_va_list
name|ap2
decl_stmt|;
name|__builtin_ms_va_copy
argument_list|(
name|ap2
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// LINUX: %[[AP_VAL:.*]] = load i8*, i8** %[[AP]]
comment|// LINUX-NEXT: store i8* %[[AP_VAL]], i8** %[[AP2:.*]]
comment|// WIN64: %[[AP_VAL:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: store i8* %[[AP_VAL]], i8** %[[AP2:.*]]
name|__builtin_ms_va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
comment|// LINUX: call void @llvm.va_end
comment|// WIN64: call void @llvm.va_end
block|}
end_decl_stmt

begin_comment
comment|// Let's verify that normal va_lists work right on Win64, too.
end_comment

begin_function
name|void
name|f5
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// WIN64-LABEL: define void @f5
name|__builtin_va_list
name|ap
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|ap
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// WIN64: %[[AP:.*]] = alloca i8*
comment|// WIN64: call void @llvm.va_start
name|int
name|b
init|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
name|int
argument_list|)
decl_stmt|;
comment|// WIN64: %[[AP_CUR:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: %[[AP_NEXT:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR]], i64 8
comment|// WIN64-NEXT: store i8* %[[AP_NEXT]], i8** %[[AP]]
comment|// WIN64-NEXT: bitcast i8* %[[AP_CUR]] to i32*
name|__builtin_va_list
name|ap2
decl_stmt|;
name|__builtin_va_copy
argument_list|(
name|ap2
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// WIN64: call void @llvm.va_copy
name|__builtin_va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
comment|// WIN64: call void @llvm.va_end
block|}
end_function

end_unit

