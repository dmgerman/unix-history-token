begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-ios5  -target-feature +long-calls -emit-llvm -o - %s | FileCheck -check-prefix=LONGCALL %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-ios5 -emit-llvm -o - %s | FileCheck -check-prefix=NOLONGCALL %s
end_comment

begin_comment
comment|// LONGCALL: attributes #0 = { {{.*}} "target-features"="+long-calls,+thumb-mode"
end_comment

begin_comment
comment|// NOLONGCALL-NOT: attributes #0 = { {{.*}} "target-features"="+long-calls,+thumb-mode"
end_comment

begin_function
name|int
name|foo1
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

end_unit

