begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -pg -mfentry -triple i386-unknown-unknown -emit-llvm -o - %s | FileCheck  %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -mfentry -triple x86_64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -mfentry -triple i386-unknown-unknown -emit-llvm -o - %s | FileCheck -check-prefix=NOPG %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -mfentry -triple x86_64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck -check-prefix=NOPG %s
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|//CHECK: attributes #{{[0-9]+}} = { {{.*}}"fentry-call"="true"{{.*}} }
end_comment

begin_comment
comment|//NOPG-NOT: attributes #{{[0-9]+}} = { {{.*}}"fentry-call"{{.*}} }
end_comment

end_unit

