begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple x86_64-windows-msvc | FileCheck %s --check-prefix=WINDOWS
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple x86_64-linux | FileCheck %s --check-prefix=LINUX
end_comment

begin_comment
comment|// Make it possible to pass NULL through variadic functions on platforms where
end_comment

begin_comment
comment|// NULL has an integer type that is more narrow than a pointer. On such
end_comment

begin_comment
comment|// platforms we widen null pointer constants to a pointer-sized integer.
end_comment

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_function_decl
name|void
name|v
parameter_list|(
specifier|const
name|char
modifier|*
name|f
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|(
specifier|const
name|char
modifier|*
name|f
parameter_list|)
block|{
name|v
argument_list|(
name|f
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// WINDOWS: define void @f(i8* %f)
end_comment

begin_comment
comment|// WINDOWS: call void (i8*, ...)* @v(i8* {{.*}}, i32 1, i32 2, i32 3, i64 0)
end_comment

begin_comment
comment|// LINUX: define void @f(i8* %f)
end_comment

begin_comment
comment|// LINUX: call void (i8*, ...)* @v(i8* {{.*}}, i32 1, i32 2, i32 3, i32 0)
end_comment

end_unit

