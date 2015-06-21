begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -target-cpu x86-64 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|int
name|baz
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
literal|4
return|;
block|}
end_function

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|(
literal|"avx,sse4.2,arch=ivybridge"
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
literal|"tune=sandybridge"
argument_list|)
operator|)
argument_list|)
name|walrus
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
literal|"fpmath=387"
argument_list|)
operator|)
argument_list|)
name|koala
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
literal|"mno-sse2"
argument_list|)
operator|)
argument_list|)
name|echidna
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

begin_function
name|int
name|bar
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|baz
argument_list|(
name|a
argument_list|)
operator|+
name|foo
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Check that we emit the additional subtarget and cpu features for foo and not for baz or bar.
end_comment

begin_comment
comment|// CHECK: baz{{.*}} #0
end_comment

begin_comment
comment|// CHECK: foo{{.*}} #1
end_comment

begin_comment
comment|// We ignore the tune attribute so walrus should be identical to baz and bar.
end_comment

begin_comment
comment|// CHECK: walrus{{.*}} #0
end_comment

begin_comment
comment|// We're currently ignoring the fpmath attribute so koala should be identical to baz and bar.
end_comment

begin_comment
comment|// CHECK: koala{{.*}} #0
end_comment

begin_comment
comment|// CHECK: echidna{{.*}} #2
end_comment

begin_comment
comment|// CHECK: bar{{.*}} #0
end_comment

begin_comment
comment|// CHECK: #0 = {{.*}}"target-cpu"="x86-64" "target-features"="+sse,+sse2"
end_comment

begin_comment
comment|// CHECK: #1 = {{.*}}"target-cpu"="ivybridge" "target-features"="+sse,+sse2,+avx,+sse4.2"
end_comment

begin_comment
comment|// CHECK: #2 = {{.*}}"target-cpu"="x86-64" "target-features"="+sse,+sse2,-sse2"
end_comment

end_unit

