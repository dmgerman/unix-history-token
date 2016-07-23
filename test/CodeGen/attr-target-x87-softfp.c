begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -target-cpu x86-64 -emit-llvm %s -o - | FileCheck %s -check-prefix=CHECK -check-prefix=HARD
end_comment

begin_comment
comment|// RUN: %clang_cc1 -msoft-float -triple x86_64-linux-gnu -target-cpu x86-64 -emit-llvm %s -o - | FileCheck %s -check-prefix=CHECK -check-prefix=SOFT
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|(
literal|"x87"
argument_list|)
operator|)
argument_list|)
name|foo
argument_list|(
name|int
name|a
argument_list|)
block|{
return|return
literal|4
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|(
literal|"no-x87"
argument_list|)
operator|)
argument_list|)
name|bar
argument_list|(
name|int
name|a
argument_list|)
block|{
return|return
literal|4
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK: foo{{.*}} #0
end_comment

begin_comment
comment|// CHECK: bar{{.*}} #1
end_comment

begin_comment
comment|// CHECK: #0 = {{.*}}"target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87"
end_comment

begin_comment
comment|// HARD: "use-soft-float"="false"
end_comment

begin_comment
comment|// SOFT: "use-soft-float"="true"
end_comment

begin_comment
comment|// CHECK: #1 = {{.*}}"target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,-x87"
end_comment

begin_comment
comment|// HARD: "use-soft-float"="false"
end_comment

begin_comment
comment|// SOFT: "use-soft-float"="true"
end_comment

end_unit

