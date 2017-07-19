begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-freebsd10.0 -emit-llvm< %s | FileCheck -check-prefix=FREEBSD %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-win32 -emit-llvm< %s | FileCheck -check-prefix=WIN64 %s
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
name|char
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// FREEBSD: %[[STRUCT_FOO:.*]] = type { i32, float, i8 }
end_comment

begin_comment
comment|// WIN64: %[[STRUCT_FOO:.*]] = type { i32, float, i8 }
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

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|sysv_abi
operator|)
argument_list|)
name|f2
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
comment|// FREEBSD-LABEL: define void @f3()
comment|// WIN64-LABEL: define void @f3()
name|f1
argument_list|()
expr_stmt|;
comment|// FREEBSD: call win64cc void @f1()
comment|// WIN64: call void @f1()
name|f2
argument_list|()
expr_stmt|;
comment|// FREEBSD: call void @f2()
comment|// WIN64: call x86_64_sysvcc void @f2()
block|}
end_function

begin_comment
comment|// FREEBSD: declare win64cc void @f1()
end_comment

begin_comment
comment|// FREEBSD: declare void @f2()
end_comment

begin_comment
comment|// WIN64: declare void @f1()
end_comment

begin_comment
comment|// WIN64: declare x86_64_sysvcc void @f2()
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
comment|// FREEBSD-LABEL: define win64cc void @f4
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
comment|// FREEBSD: %[[AP:.*]] = alloca i8*
comment|// FREEBSD: call void @llvm.va_start
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
comment|// FREEBSD: %[[AP_CUR:.*]] = load i8*, i8** %[[AP]]
comment|// FREEBSD-NEXT: %[[AP_NEXT:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR]], i64 8
comment|// FREEBSD-NEXT: store i8* %[[AP_NEXT]], i8** %[[AP]]
comment|// FREEBSD-NEXT: bitcast i8* %[[AP_CUR]] to i32*
comment|// WIN64: %[[AP_CUR:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: %[[AP_NEXT:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR]], i64 8
comment|// WIN64-NEXT: store i8* %[[AP_NEXT]], i8** %[[AP]]
comment|// WIN64-NEXT: bitcast i8* %[[AP_CUR]] to i32*
comment|// FIXME: These are different now. We probably need __builtin_ms_va_arg.
name|double
specifier|_Complex
name|c
init|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
name|double
specifier|_Complex
argument_list|)
decl_stmt|;
comment|// FREEBSD: %[[AP_CUR2:.*]] = load i8*, i8** %[[AP]]
comment|// FREEBSD-NEXT: %[[AP_NEXT2:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR2]], i64 16
comment|// FREEBSD-NEXT: store i8* %[[AP_NEXT2]], i8** %[[AP]]
comment|// FREEBSD-NEXT: bitcast i8* %[[AP_CUR2]] to { double, double }*
comment|// WIN64: %[[AP_CUR2:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: %[[AP_NEXT2:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR2]], i64 8
comment|// WIN64-NEXT: store i8* %[[AP_NEXT2]], i8** %[[AP]]
comment|// WIN64-NEXT: %[[CUR2:.*]] = bitcast i8* %[[AP_CUR2]] to { double, double }**
comment|// WIN64-NEXT: load { double, double }*, { double, double }** %[[CUR2]]
name|struct
name|foo
name|d
init|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|foo
argument_list|)
decl_stmt|;
comment|// FREEBSD: %[[AP_CUR3:.*]] = load i8*, i8** %[[AP]]
comment|// FREEBSD-NEXT: %[[AP_NEXT3:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR3]], i64 16
comment|// FREEBSD-NEXT: store i8* %[[AP_NEXT3]], i8** %[[AP]]
comment|// FREEBSD-NEXT: bitcast i8* %[[AP_CUR3]] to %[[STRUCT_FOO]]*
comment|// WIN64: %[[AP_CUR3:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: %[[AP_NEXT3:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR3]], i64 8
comment|// WIN64-NEXT: store i8* %[[AP_NEXT3]], i8** %[[AP]]
comment|// WIN64-NEXT: %[[CUR3:.*]] = bitcast i8* %[[AP_CUR3]] to %[[STRUCT_FOO]]*
comment|// WIN64-NEXT: load %[[STRUCT_FOO]]*, %[[STRUCT_FOO]]** %[[CUR3]]
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
comment|// FREEBSD: %[[AP_VAL:.*]] = load i8*, i8** %[[AP]]
comment|// FREEBSD-NEXT: store i8* %[[AP_VAL]], i8** %[[AP2:.*]]
comment|// WIN64: %[[AP_VAL:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: store i8* %[[AP_VAL]], i8** %[[AP2:.*]]
name|__builtin_ms_va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
comment|// FREEBSD: call void @llvm.va_end
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
name|double
specifier|_Complex
name|c
init|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
name|double
specifier|_Complex
argument_list|)
decl_stmt|;
comment|// WIN64: %[[AP_CUR2:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: %[[AP_NEXT2:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR2]], i64 8
comment|// WIN64-NEXT: store i8* %[[AP_NEXT2]], i8** %[[AP]]
comment|// WIN64-NEXT: bitcast i8* %[[AP_CUR2]] to { double, double }*
name|struct
name|foo
name|d
init|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|foo
argument_list|)
decl_stmt|;
comment|// WIN64: %[[AP_CUR3:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: %[[AP_NEXT3:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR3]], i64 8
comment|// WIN64-NEXT: store i8* %[[AP_NEXT3]], i8** %[[AP]]
comment|// WIN64-NEXT: bitcast i8* %[[AP_CUR3]] to %[[STRUCT_FOO]]*
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

begin_comment
comment|// Verify that using a Win64 va_list from a System V function works.
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|sysv_abi
operator|)
argument_list|)
name|f6
argument_list|(
name|__builtin_ms_va_list
name|ap
argument_list|)
block|{
comment|// FREEBSD-LABEL: define void @f6
comment|// FREEBSD: store i8* %ap, i8** %[[AP:.*]]
comment|// WIN64-LABEL: define x86_64_sysvcc void @f6
comment|// WIN64: store i8* %ap, i8** %[[AP:.*]]
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
comment|// FREEBSD: %[[AP_CUR:.*]] = load i8*, i8** %[[AP]]
comment|// FREEBSD-NEXT: %[[AP_NEXT:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR]], i64 8
comment|// FREEBSD-NEXT: store i8* %[[AP_NEXT]], i8** %[[AP]]
comment|// FREEBSD-NEXT: bitcast i8* %[[AP_CUR]] to i32*
comment|// WIN64: %[[AP_CUR:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: %[[AP_NEXT:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR]], i64 8
comment|// WIN64-NEXT: store i8* %[[AP_NEXT]], i8** %[[AP]]
comment|// WIN64-NEXT: bitcast i8* %[[AP_CUR]] to i32*
name|double
specifier|_Complex
name|c
init|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
name|double
specifier|_Complex
argument_list|)
decl_stmt|;
comment|// FREEBSD: %[[AP_CUR2:.*]] = load i8*, i8** %[[AP]]
comment|// FREEBSD-NEXT: %[[AP_NEXT2:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR2]], i64 16
comment|// FREEBSD-NEXT: store i8* %[[AP_NEXT2]], i8** %[[AP]]
comment|// FREEBSD-NEXT: bitcast i8* %[[AP_CUR2]] to { double, double }*
comment|// WIN64: %[[AP_CUR2:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: %[[AP_NEXT2:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR2]], i64 8
comment|// WIN64-NEXT: store i8* %[[AP_NEXT2]], i8** %[[AP]]
comment|// WIN64-NEXT: bitcast i8* %[[AP_CUR2]] to { double, double }*
name|struct
name|foo
name|d
init|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|foo
argument_list|)
decl_stmt|;
comment|// FREEBSD: %[[AP_CUR3:.*]] = load i8*, i8** %[[AP]]
comment|// FREEBSD-NEXT: %[[AP_NEXT3:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR3]], i64 16
comment|// FREEBSD-NEXT: store i8* %[[AP_NEXT3]], i8** %[[AP]]
comment|// FREEBSD-NEXT: bitcast i8* %[[AP_CUR3]] to %[[STRUCT_FOO]]*
comment|// WIN64: %[[AP_CUR3:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: %[[AP_NEXT3:.*]] = getelementptr inbounds i8, i8* %[[AP_CUR3]], i64 8
comment|// WIN64-NEXT: store i8* %[[AP_NEXT3]], i8** %[[AP]]
comment|// WIN64-NEXT: bitcast i8* %[[AP_CUR3]] to %[[STRUCT_FOO]]*
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
comment|// FREEBSD: %[[AP_VAL:.*]] = load i8*, i8** %[[AP]]
comment|// FREEBSD-NEXT: store i8* %[[AP_VAL]], i8** %[[AP2:.*]]
comment|// WIN64: %[[AP_VAL:.*]] = load i8*, i8** %[[AP]]
comment|// WIN64-NEXT: store i8* %[[AP_VAL]], i8** %[[AP2:.*]]
block|}
end_decl_stmt

end_unit

