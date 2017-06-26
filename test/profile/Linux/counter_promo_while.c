begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -fr %t.promo.prof
end_comment

begin_comment
comment|// RUN: rm -fr %t.nopromo.prof
end_comment

begin_comment
comment|// RUN: %clang_pgogen=%t.promo.prof/ -o %t.promo.gen -O2 %s
end_comment

begin_comment
comment|// RUN: %clang_pgogen=%t.promo.prof/ -o %t.promo.gen.ll -emit-llvm -S -O2 %s
end_comment

begin_comment
comment|// RUN: cat %t.promo.gen.ll | FileCheck --check-prefix=PROMO %s
end_comment

begin_comment
comment|// RUN: %run %t.promo.gen
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.promo.profdata %t.promo.prof/
end_comment

begin_comment
comment|// RUN: llvm-profdata show --counts --all-functions %t.promo.profdata> %t.promo.dump
end_comment

begin_comment
comment|// RUN: %clang_pgogen=%t.nopromo.prof/ -mllvm -do-counter-promotion=false -o %t.nopromo.gen -O2 %s
end_comment

begin_comment
comment|// RUN: %clang_pgogen=%t.nopromo.prof/ -mllvm -do-counter-promotion=false -o %t.nopromo.gen.ll -emit-llvm -S -O2 %s
end_comment

begin_comment
comment|// RUN: cat %t.nopromo.gen.ll | FileCheck --check-prefix=NOPROMO %s
end_comment

begin_comment
comment|// RUN: %run %t.nopromo.gen
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.nopromo.profdata %t.nopromo.prof/
end_comment

begin_comment
comment|// RUN: llvm-profdata show --counts --all-functions %t.nopromo.profdata> %t.nopromo.dump
end_comment

begin_comment
comment|// RUN: diff %t.promo.profdata %t.nopromo.profdata
end_comment

begin_decl_stmt
name|int
name|g
decl_stmt|;
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|void
name|bar
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|g
operator|+=
name|i
expr_stmt|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|void
name|foo
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|N
parameter_list|)
block|{
comment|// PROMO-LABEL: @foo
comment|// PROMO: load{{.*}}@__profc_foo{{.*}} 0){{.*}}
comment|// PROMO-NEXT: add
comment|// PROMO-NEXT: store{{.*}}@__profc_foo{{.*}} 0){{.*}}
comment|// PROMO-NEXT: load{{.*}}@__profc_foo{{.*}} 1){{.*}}
comment|// PROMO-NEXT: add
comment|// PROMO-NEXT: store{{.*}}@__profc_foo{{.*}} 1){{.*}}
comment|// PROMO-NEXT: load{{.*}}@__profc_foo{{.*}} 2){{.*}}
comment|// PROMO-NEXT: add
comment|// PROMO-NEXT: store{{.*}}@__profc_foo{{.*}} 2){{.*}}
comment|//
comment|// NOPROMO-LABEL: @foo
comment|// NOPROMO: load{{.*}}@__profc_foo{{.*}} 0){{.*}}
comment|// NOPROMO-NEXT: add
comment|// NOPROMO-NEXT: store{{.*}}@__profc_foo{{.*}} 0){{.*}}
comment|// NOPROMO: load{{.*}}@__profc_foo{{.*}} 1){{.*}}
comment|// NOPROMO-NEXT: add
comment|// NOPROMO-NEXT: store{{.*}}@__profc_foo{{.*}} 1){{.*}}
comment|// NOPROMO: load{{.*}}@__profc_foo{{.*}} 2){{.*}}
comment|// NOPROMO-NEXT: add
comment|// NOPROMO-NEXT: store{{.*}}@__profc_foo{{.*}} 2){{.*}}
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|N
condition|)
block|{
if|if
condition|(
name|i
operator|<
name|n
operator|+
literal|1
condition|)
name|bar
argument_list|(
literal|1
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|i
operator|<
name|n
operator|-
literal|1
condition|)
name|bar
argument_list|(
literal|2
argument_list|)
expr_stmt|;
else|else
name|bar
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|foo
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

