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
parameter_list|()
block|{
name|g
operator|++
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|c
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
comment|// PROMO-LABEL: @main
comment|// PROMO: load{{.*}}@__profc_main{{.*}}
comment|// PROMO-NEXT: add
comment|// PROMO-NEXT: store{{.*}}@__profc_main{{.*}}
comment|// PROMO-NEXT: load{{.*}}@__profc_main{{.*}}
comment|// PROMO-NEXT: add
comment|// PROMO-NEXT: store{{.*}}@__profc_main{{.*}}
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|;
name|g
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|c
condition|;
name|i
operator|++
control|)
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|c
condition|;
name|j
operator|++
control|)
for|for
control|(
name|k
operator|=
literal|0
init|;
name|k
operator|<
name|c
condition|;
name|k
operator|++
control|)
name|bar
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|c
condition|;
name|i
operator|++
control|)
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
literal|10
operator|*
name|c
condition|;
name|j
operator|++
control|)
name|bar
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|100
operator|*
name|c
condition|;
name|i
operator|++
control|)
name|bar
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

