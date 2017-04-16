begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -target-feature +htm -triple powerpc64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|long
name|int
modifier|*
name|r
parameter_list|,
name|int
name|code
parameter_list|,
name|long
name|int
modifier|*
name|a
parameter_list|,
name|long
name|int
modifier|*
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test1
name|r
index|[
literal|0
index|]
operator|=
name|__builtin_tbegin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.tbegin
name|r
index|[
literal|1
index|]
operator|=
name|__builtin_tbegin
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.tbegin
name|r
index|[
literal|2
index|]
operator|=
name|__builtin_tend
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.tend
name|r
index|[
literal|3
index|]
operator|=
name|__builtin_tendall
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.tendall
name|r
index|[
literal|4
index|]
operator|=
name|__builtin_tabort
argument_list|(
name|code
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.tabort
name|r
index|[
literal|5
index|]
operator|=
name|__builtin_tabort
argument_list|(
literal|0x1
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.tabort
name|r
index|[
literal|6
index|]
operator|=
name|__builtin_tabortdc
argument_list|(
literal|0xf
argument_list|,
name|a
index|[
literal|0
index|]
argument_list|,
name|b
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.tabortdc
name|r
index|[
literal|7
index|]
operator|=
name|__builtin_tabortdci
argument_list|(
literal|0xf
argument_list|,
name|a
index|[
literal|1
index|]
argument_list|,
literal|0x1
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.tabortdc
name|r
index|[
literal|8
index|]
operator|=
name|__builtin_tabortwc
argument_list|(
literal|0xf
argument_list|,
name|a
index|[
literal|2
index|]
argument_list|,
name|b
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.tabortwc
name|r
index|[
literal|9
index|]
operator|=
name|__builtin_tabortwci
argument_list|(
literal|0xf
argument_list|,
name|a
index|[
literal|3
index|]
argument_list|,
literal|0x1
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.tabortwc
name|r
index|[
literal|10
index|]
operator|=
name|__builtin_tcheck
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.tcheck
name|r
index|[
literal|11
index|]
operator|=
name|__builtin_trechkpt
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.trechkpt
name|r
index|[
literal|12
index|]
operator|=
name|__builtin_treclaim
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.treclaim
name|r
index|[
literal|13
index|]
operator|=
name|__builtin_tresume
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.tresume
name|r
index|[
literal|14
index|]
operator|=
name|__builtin_tsuspend
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.tsuspend
name|r
index|[
literal|15
index|]
operator|=
name|__builtin_tsr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.tsr
name|r
index|[
literal|16
index|]
operator|=
name|__builtin_ttest
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.ttest
name|r
index|[
literal|17
index|]
operator|=
name|__builtin_get_texasr
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.get.texasr
name|r
index|[
literal|18
index|]
operator|=
name|__builtin_get_texasru
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.get.texasru
name|r
index|[
literal|19
index|]
operator|=
name|__builtin_get_tfhar
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.get.tfhar
name|r
index|[
literal|20
index|]
operator|=
name|__builtin_get_tfiar
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.ppc.get.tfiar
name|__builtin_set_texasr
argument_list|(
name|a
index|[
literal|21
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.set.texasr
name|__builtin_set_texasru
argument_list|(
name|a
index|[
literal|22
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.set.texasru
name|__builtin_set_tfhar
argument_list|(
name|a
index|[
literal|23
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.set.tfhar
name|__builtin_set_tfiar
argument_list|(
name|a
index|[
literal|24
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.ppc.set.tfiar
block|}
end_function

end_unit

