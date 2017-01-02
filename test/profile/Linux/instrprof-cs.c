begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -fr %t.prof
end_comment

begin_comment
comment|// RUN: %clang_pgogen=%t.prof/ -o %t.gen.cs -O2 %s
end_comment

begin_comment
comment|// RUN: %run %t.gen.cs
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.cs.profdata %t.prof/
end_comment

begin_comment
comment|// Check context sensitive profile
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.cs.profdata  -O2 -emit-llvm -S %s -o - | FileCheck %s --check-prefix=CS
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_profgen=%t.profraw -o %t.gen.cis -O2 %s
end_comment

begin_comment
comment|// RUN: %run %t.gen.cis
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.cis.profdata %t.profraw
end_comment

begin_comment
comment|// Check context insenstive profile
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.cis.profdata  -O2 -emit-llvm -S %s -o - | FileCheck %s --check-prefix=CIS
end_comment

begin_decl_stmt
name|int
name|g1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
specifier|volatile
name|g2
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|toggle
parameter_list|(
name|int
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
operator|&
literal|1
condition|)
name|g1
operator|*=
name|t
expr_stmt|;
else|else
name|g2
operator|*=
name|t
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|// CS: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD1:[0-9]+]]
comment|// CIS: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD:[0-9]+]]
name|toggle
argument_list|(
name|g1
argument_list|)
expr_stmt|;
comment|// CS: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD2:[0-9]+]]
comment|// CIS: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD:[0-9]+]]
name|toggle
argument_list|(
name|g2
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CS: ![[PD1]] = !{!"branch_weights", i32 0, i32 1}
end_comment

begin_comment
comment|// CS: ![[PD2]] = !{!"branch_weights", i32 1, i32 0}
end_comment

begin_comment
comment|// CIS: ![[PD]] = !{!"branch_weights", i32 2, i32 2}
end_comment

end_unit

