begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-linux-gnueabihf -emit-llvm -o - %s | FileCheck --check-prefix THUMB %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7eb-linux-gnueabihf -emit-llvm -o - %s | FileCheck --check-prefix THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-linux-gnueabihf -mthumb -S -emit-llvm -o - %s | FileCheck --check-prefix THUMB-CLANG %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-linux-gnueabihf -emit-llvm -o - %s | FileCheck --check-prefix ARM %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7eb-linux-gnueabihf -emit-llvm -o - %s | FileCheck --check-prefix ARM %s
end_comment

begin_function
name|void
name|t1
parameter_list|()
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(target(
literal|"no-thumb-mode"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|t2
parameter_list|()
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(target(
literal|"thumb-mode"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|t3
parameter_list|()
block|{}
end_function

begin_comment
comment|// THUMB: void @t1() [[ThumbAttr:#[0-7]]]
end_comment

begin_comment
comment|// THUMB: void @t2() [[NoThumbAttr:#[0-7]]]
end_comment

begin_comment
comment|// THUMB: void @t3() [[ThumbAttr:#[0-7]]]
end_comment

begin_comment
comment|// THUMB: attributes [[ThumbAttr]] = { {{.*}} "target-features"="+thumb-mode"
end_comment

begin_comment
comment|// THUMB: attributes [[NoThumbAttr]] = { {{.*}} "target-features"="-thumb-mode"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THUMB-CLANG: void @t1() [[ThumbAttr:#[0-7]]]
end_comment

begin_comment
comment|// THUMB-CLANG: void @t2() [[NoThumbAttr:#[0-7]]]
end_comment

begin_comment
comment|// THUMB-CLANG: void @t3() [[ThumbAttr:#[0-7]]]
end_comment

begin_comment
comment|// THUMB-CLANG: attributes [[ThumbAttr]] = { {{.*}} "target-features"="{{.*}}+thumb-mode
end_comment

begin_comment
comment|// THUMB-CLANG: attributes [[NoThumbAttr]] = { {{.*}} "target-features"="{{.*}}-thumb-mode
end_comment

begin_comment
comment|// ARM: void @t1() [[NoThumbAtr:#[0-7]]]
end_comment

begin_comment
comment|// ARM: void @t2() [[NoThumbAttr:#[0-7]]]
end_comment

begin_comment
comment|// ARM: void @t3() [[ThumbAttr:#[0-7]]]
end_comment

begin_comment
comment|// ARM: attributes [[NoThumbAttr]] = { {{.*}} "target-features"="-thumb-mode"
end_comment

begin_comment
comment|// ARM: attributes [[ThumbAttr]] = { {{.*}} "target-features"="+thumb-mode"
end_comment

end_unit

