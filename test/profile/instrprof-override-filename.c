begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t.dir&& mkdir -p %t.dir
end_comment

begin_comment
comment|// RUN: cd %t.dir
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_profgen=P_RAW -o %t -O3 %s
end_comment

begin_comment
comment|// RUN: %run %t P_RAW
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata P_RAW
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.profdata -o - -S -emit-llvm %s | FileCheck %s --check-prefix=FE
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_pgogen=I_RAW -o %t.2 %s
end_comment

begin_comment
comment|// RUN: %run %t.2 I_RAW
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t2.profdata I_RAW
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t2.profdata -o - -S -emit-llvm %s | FileCheck %s --check-prefix=IR
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
comment|// FE: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD1:[0-9]+]]
comment|// IR: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD1:[0-9]+]]
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
return|return
literal|1
return|;
name|bar
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// FE: ![[PD1]] = !{!"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// IR: ![[PD1]] = !{!"branch_weights", i32 0, i32 1}
end_comment

end_unit

