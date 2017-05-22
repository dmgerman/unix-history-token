begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mips-linux-gnu -emit-llvm  -o  - %s | FileCheck %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|micromips
operator|)
argument_list|)
name|foo
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// CHECK: define void @foo() [[MICROMIPS:#[0-9]+]]
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|nomicromips
operator|)
argument_list|)
name|nofoo
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// CHECK: define void @nofoo() [[NOMICROMIPS:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: attributes [[MICROMIPS]] = { noinline nounwind {{.*}} "micromips" {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[NOMICROMIPS]]  = { noinline nounwind {{.*}} "nomicromips" {{.*}} }
end_comment

end_unit

