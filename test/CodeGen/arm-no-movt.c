begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-ios5  -target-feature +no-movt -emit-llvm -o - %s | FileCheck -check-prefix=NO-MOVT %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-ios5 -emit-llvm -o - %s | FileCheck -check-prefix=MOVT %s
end_comment

begin_comment
comment|// NO-MOVT: attributes #0 = { {{.*}} "target-features"="+no-movt,+thumb-mode"
end_comment

begin_comment
comment|// MOVT-NOT: attributes #0 = { {{.*}} "target-features"="+no-movt,+thumb-mode"
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

