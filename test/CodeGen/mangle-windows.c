begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=i386-pc-win32 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=i386-mingw32 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=x86_64-pc-win32 | FileCheck %s --check-prefix=X64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=x86_64-mingw32 | FileCheck %s --check-prefix=X64
end_comment

begin_function
name|void
name|__stdcall
name|f1
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_stdcallcc void @"\01_f1@0"
end_comment

begin_comment
comment|// X64: define void @f1(
end_comment

begin_function
name|void
name|__fastcall
name|f2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_fastcallcc void @"\01@f2@0"
end_comment

begin_comment
comment|// X64: define void @f2(
end_comment

begin_function
name|void
name|__stdcall
name|f3
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define x86_stdcallcc void @"\01_f3@0"
end_comment

begin_comment
comment|// X64: define void @f3(
end_comment

begin_function
name|void
name|__fastcall
name|f4
parameter_list|(
name|char
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_fastcallcc void @"\01@f4@4"
end_comment

begin_comment
comment|// X64: define void @f4(
end_comment

begin_function
name|void
name|__fastcall
name|f5
parameter_list|(
name|short
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_fastcallcc void @"\01@f5@4"
end_comment

begin_comment
comment|// X64: define void @f5(
end_comment

begin_function
name|void
name|__fastcall
name|f6
parameter_list|(
name|int
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_fastcallcc void @"\01@f6@4"
end_comment

begin_comment
comment|// X64: define void @f6(
end_comment

begin_function
name|void
name|__fastcall
name|f7
parameter_list|(
name|long
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_fastcallcc void @"\01@f7@4"
end_comment

begin_comment
comment|// X64: define void @f7(
end_comment

begin_function
name|void
name|__fastcall
name|f8
parameter_list|(
name|long
name|long
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_fastcallcc void @"\01@f8@8"
end_comment

begin_comment
comment|// X64: define void @f8(
end_comment

begin_function
name|void
name|__fastcall
name|f9
parameter_list|(
name|long
name|long
name|a
parameter_list|,
name|char
name|b
parameter_list|,
name|char
name|c
parameter_list|,
name|short
name|d
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_fastcallcc void @"\01@f9@20"(i64 %a, i8 signext %b, i8 signext %c, i16 signext %d)
end_comment

begin_comment
comment|// X64: define void @f9(
end_comment

begin_function
name|void
name|f12
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @f12(
end_comment

begin_comment
comment|// X64: define void @f12(
end_comment

begin_function
name|void
name|__vectorcall
name|v1
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01v1@@0"(
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01v1@@0"(
end_comment

begin_function
name|void
name|__vectorcall
name|v2
parameter_list|(
name|char
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01v2@@4"(
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01v2@@8"(
end_comment

begin_function
name|void
name|__vectorcall
name|v3
parameter_list|(
name|short
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01v3@@4"(
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01v3@@8"(
end_comment

begin_function
name|void
name|__vectorcall
name|v4
parameter_list|(
name|int
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01v4@@4"(
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01v4@@8"(
end_comment

begin_function
name|void
name|__vectorcall
name|v5
parameter_list|(
name|long
name|long
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01v5@@8"(
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01v5@@8"(
end_comment

begin_function
name|void
name|__vectorcall
name|v6
parameter_list|(
name|char
name|a
parameter_list|,
name|char
name|b
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_vectorcallcc void @"\01v6@@8"(
end_comment

begin_comment
comment|// X64: define x86_vectorcallcc void @"\01v6@@16"(
end_comment

end_unit

