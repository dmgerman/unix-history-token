begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Generate instrumentation and sampling profile data.
end_comment

begin_comment
comment|// RUN: llvm-profdata merge \
end_comment

begin_comment
comment|// RUN:     %S/Inputs/optimization-remark-with-hotness.proftext \
end_comment

begin_comment
comment|// RUN:     -o %t.profdata
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -sample \
end_comment

begin_comment
comment|// RUN:     %S/Inputs/optimization-remark-with-hotness-sample.proftext \
end_comment

begin_comment
comment|// RUN:     -o %t-sample.profdata
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name \
end_comment

begin_comment
comment|// RUN:     optimization-remark-with-hotness.c %s -emit-llvm-only \
end_comment

begin_comment
comment|// RUN:     -fprofile-instrument-use-path=%t.profdata -Rpass=inline \
end_comment

begin_comment
comment|// RUN:     -Rpass-analysis=inline -Rpass-missed=inline \
end_comment

begin_comment
comment|// RUN:     -fdiagnostics-show-hotness -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name \
end_comment

begin_comment
comment|// RUN:     optimization-remark-with-hotness.c %s -emit-llvm-only \
end_comment

begin_comment
comment|// RUN:     -fprofile-sample-use=%t-sample.profdata -Rpass=inline \
end_comment

begin_comment
comment|// RUN:     -Rpass-analysis=inline -Rpass-missed=inline \
end_comment

begin_comment
comment|// RUN:     -fdiagnostics-show-hotness -verify
end_comment

begin_comment
comment|// The clang version of the previous test.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx10.9 %s -c -emit-llvm -o /dev/null \
end_comment

begin_comment
comment|// RUN:     -fprofile-instr-use=%t.profdata -Rpass=inline \
end_comment

begin_comment
comment|// RUN:     -Rpass-analysis=inline -Rpass-missed=inline \
end_comment

begin_comment
comment|// RUN:     -fdiagnostics-show-hotness -Xclang -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name \
end_comment

begin_comment
comment|// RUN:     optimization-remark-with-hotness.c %s -emit-llvm-only \
end_comment

begin_comment
comment|// RUN:     -fprofile-instrument-use-path=%t.profdata -Rpass=inline \
end_comment

begin_comment
comment|// RUN:     -Rpass-analysis=inline 2>&1 | FileCheck -check-prefix=HOTNESS_OFF %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name \
end_comment

begin_comment
comment|// RUN:     optimization-remark-with-hotness.c %s -emit-llvm-only \
end_comment

begin_comment
comment|// RUN:     -fprofile-instrument-use-path=%t.profdata -Rpass=inline \
end_comment

begin_comment
comment|// RUN:     -Rpass-analysis=inline -Rno-pass-with-hotness  2>&1 | FileCheck \
end_comment

begin_comment
comment|// RUN:     -check-prefix=HOTNESS_OFF %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name \
end_comment

begin_comment
comment|// RUN:     optimization-remark-with-hotness.c %s -emit-llvm-only \
end_comment

begin_comment
comment|// RUN:     -Rpass=inline -Rpass-analysis=inline -fdiagnostics-show-hotness  2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck -check-prefix=NO_PGO %s
end_comment

begin_function_decl
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(always_inline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
return|return
name|x
operator|+
name|y
return|;
block|}
end_function

begin_decl_stmt
name|int
name|sum
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// HOTNESS_OFF: foo inlined into bar
comment|// HOTNESS_OFF-NOT: hotness:
comment|// NO_PGO: '-fdiagnostics-show-hotness' requires profile-guided optimization information
comment|// expected-remark@+2 {{foo should always be inlined (cost=always) (hotness: 30)}}
comment|// expected-remark@+1 {{foo inlined into bar (hotness: 30)}}
name|sum
operator|+=
name|foo
argument_list|(
name|x
argument_list|,
name|x
operator|-
literal|2
argument_list|)
expr_stmt|;
block|}
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
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|30
condition|;
name|i
operator|++
control|)
comment|// expected-remark@+1 {{bar not inlined into main because it should never be inlined}}
name|bar
argument_list|(
name|argc
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

end_unit

