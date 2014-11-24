begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsplit-stack -S %s -emit-llvm -o - | FileCheck -check-prefix=CHECK-SEGSTK %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -S %s -emit-llvm -o - | FileCheck -check-prefix=CHECK-NOSEGSTK %s
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(no_split_stack)
argument_list|)
end_macro

begin_function
name|int
name|nosplit
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
name|foo
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// CHECK-SEGSTK: define i32 @foo() [[SS:#[0-9]+]] {
end_comment

begin_comment
comment|// CHECK-SEGSTK: define i32 @nosplit() [[NSS:#[0-9]+]] {
end_comment

begin_comment
comment|// CHECK-SEGSTK: define i32 @main() [[SS]] {
end_comment

begin_comment
comment|// CHECK-SEGSTK-NOT: [[NSS]] = { {{.*}} "split-stack" {{.*}} }
end_comment

begin_comment
comment|// CHECK-SEGSTK: [[SS]] = { {{.*}} "split-stack" {{.*}} }
end_comment

begin_comment
comment|// CHECK-SEGSTK-NOT: [[NSS]] = { {{.*}} "split-stack" {{.*}} }
end_comment

begin_comment
comment|// CHECK-NOSEGSTK: define i32 @foo() #0 {
end_comment

begin_comment
comment|// CHECK-NOSEGSTK: define i32 @main() #0 {
end_comment

begin_comment
comment|// CHECK-NOSEGSTK-NOT: #0 = { {{.*}} "split-stack" {{.*}} }
end_comment

end_unit

