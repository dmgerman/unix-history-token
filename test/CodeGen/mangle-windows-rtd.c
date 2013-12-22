begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -mrtd %s -o - -triple=i386-mingw32 | FileCheck %s
end_comment

begin_function
name|void
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
name|__stdcall
name|f2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_stdcallcc void @"\01_f2@0"
end_comment

begin_function
name|void
name|__fastcall
name|f3
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define x86_fastcallcc void @"\01@f3@0"
end_comment

end_unit

