begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=i386-pc-win32 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple=i386-mingw32 | FileCheck %s
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
comment|// CHECK: define x86_fastcallcc void @"\01@f9@20"(i64 %a, i8 signext %b, i8
end_comment

begin_comment
comment|// signext %c, i16 signext %d)
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

end_unit

