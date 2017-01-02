begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mipsel-linux-gnu -emit-llvm  -o  - %s | FileCheck %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|mips16
operator|)
argument_list|)
name|foo
argument_list|(
name|void
argument_list|)
block|{  }
end_decl_stmt

begin_comment
comment|// CHECK: define void @foo() [[MIPS16:#[0-9]+]]
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|nomips16
operator|)
argument_list|)
name|nofoo
argument_list|(
name|void
argument_list|)
block|{  }
end_decl_stmt

begin_comment
comment|// CHECK: define void @nofoo() [[NOMIPS16:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: attributes [[MIPS16]] = { noinline nounwind {{.*}} "mips16" {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[NOMIPS16]]  = { noinline nounwind {{.*}} "nomips16" {{.*}} }
end_comment

end_unit

