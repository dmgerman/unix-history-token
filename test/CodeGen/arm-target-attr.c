begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumb-apple-darwin -emit-llvm -o - %s | FileCheck --check-prefix CHECKPOS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumb-apple-darwin -emit-llvm -o - %s | FileCheck --check-prefix CHECKNEG %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-apple-darwin -emit-llvm -o - %s | FileCheck --check-prefix CHECKPOS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-apple-darwin -emit-llvm -o - %s | FileCheck --check-prefix CHECKNEG %s
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(target(
literal|"arm"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|test_target_arm
parameter_list|()
block|{
comment|// CHECKPOS: define void @test_target_arm() [[ARM_ATTRS:#[0-9]+]]
comment|// CHECKNEG: define void @test_target_arm() [[ARM_ATTRS:#[0-9]+]]
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(target(
literal|"thumb"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|test_target_thumb
parameter_list|()
block|{
comment|// CHECKPOS: define void @test_target_thumb() [[THUMB_ATTRS:#[0-9]+]]
comment|// CHECKNEG: define void @test_target_thumb() [[THUMB_ATTRS:#[0-9]+]]
block|}
end_function

begin_comment
comment|// CHECKPOS: attributes [[ARM_ATTRS]] = { {{.*}} "target-features"="{{.*}}-thumb-mode{{.*}}"
end_comment

begin_comment
comment|// CHECKPOS: attributes [[THUMB_ATTRS]] = { {{.*}} "target-features"="{{.*}}+thumb-mode{{.*}}"
end_comment

begin_comment
comment|// CHECKNEG-NOT: attributes [[ARM_ATTRS]] = { {{.*}} "target-features"="{{.*}}+thumb-mode{{.*}}"
end_comment

begin_comment
comment|// CHECKNEG-NOT: attributes [[THUMB_ATTRS]] = { {{.*}} "target-features"="{{.*}}-thumb-mode{{.*}}"
end_comment

end_unit

