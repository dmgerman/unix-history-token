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
literal|"no-sse2"
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

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|(
literal|"sse4"
argument_list|)
operator|)
argument_list|)
name|panda
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

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|(
literal|"avx,      sse4.2,      arch=   ivybridge"
argument_list|)
operator|)
argument_list|)
name|qux
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
literal|"no-aes, arch=ivybridge"
argument_list|)
operator|)
argument_list|)
name|qax
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
literal|"no-mmx"
argument_list|)
operator|)
argument_list|)
name|qq
argument_list|(
name|int
name|a
argument_list|)
block|{
return|return
literal|40
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
literal|"arch=lakemont"
argument_list|)
operator|)
argument_list|)
name|lake
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
comment|// CHECK: panda{{.*}} #3
end_comment

begin_comment
comment|// CHECK: bar{{.*}} #0
end_comment

begin_comment
comment|// CHECK: qux{{.*}} #1
end_comment

begin_comment
comment|// CHECK: qax{{.*}} #4
end_comment

begin_comment
comment|// CHECK: qq{{.*}} #5
end_comment

begin_comment
comment|// CHECK: lake{{.*}} #6
end_comment

begin_comment
comment|// CHECK: #0 = {{.*}}"target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87"
end_comment

begin_comment
comment|// CHECK: #1 = {{.*}}"target-cpu"="ivybridge" "target-features"="+aes,+avx,+cx16,+f16c,+fsgsbase,+fxsr,+mmx,+pclmul,+popcnt,+rdrnd,+sse,+sse2,+sse3,+sse4.1,+sse4.2,+ssse3,+x87,+xsave,+xsaveopt"
end_comment

begin_comment
comment|// CHECK: #2 = {{.*}}"target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+x87,-aes,-avx,-avx2,-avx512bw,-avx512cd,-avx512dq,-avx512er,-avx512f,-avx512ifma,-avx512pf,-avx512vbmi,-avx512vl,-avx512vpopcntdq,-f16c,-fma,-fma4,-pclmul,-sha,-sse2,-sse3,-sse4.1,-sse4.2,-sse4a,-ssse3,-xop,-xsave,-xsaveopt"
end_comment

begin_comment
comment|// CHECK: #3 = {{.*}}"target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+popcnt,+sse,+sse2,+sse3,+sse4.1,+sse4.2,+ssse3,+x87"
end_comment

begin_comment
comment|// CHECK: #4 = {{.*}}"target-cpu"="ivybridge" "target-features"="+avx,+cx16,+f16c,+fsgsbase,+fxsr,+mmx,+pclmul,+popcnt,+rdrnd,+sse,+sse2,+sse3,+sse4.1,+sse4.2,+ssse3,+x87,+xsave,+xsaveopt,-aes"
end_comment

begin_comment
comment|// CHECK: #5 = {{.*}}"target-cpu"="x86-64" "target-features"="+fxsr,+sse,+sse2,+x87,-3dnow,-3dnowa,-mmx"
end_comment

begin_comment
comment|// CHECK: #6 = {{.*}}"target-cpu"="lakemont" "target-features"="+mmx,+sse,+sse2"
end_comment

end_unit

