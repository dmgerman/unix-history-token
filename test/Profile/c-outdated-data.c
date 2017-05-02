begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that outdated data is ignored.
end_comment

begin_comment
comment|// FIXME: It would be nice to use -verify here instead of FileCheck, but -verify
end_comment

begin_comment
comment|// doesn't play well with warnings that have no line number.
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/c-outdated-data.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-outdated-data.c %s -o /dev/null -emit-llvm -fprofile-instrument-use-path=%t.profdata 2>&1 | FileCheck %s -check-prefix=NO_MISSING
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-outdated-data.c %s -o /dev/null -emit-llvm -Wprofile-instr-missing -fprofile-instrument-use-path=%t.profdata 2>&1 | FileCheck %s -check-prefix=WITH_MISSING
end_comment

begin_comment
comment|// NO_MISSING: warning: profile data may be out of date: of 3 functions, 1 has mismatched data that will be ignored
end_comment

begin_comment
comment|// NO_MISSING-NOT: 1 has no data
end_comment

begin_comment
comment|// WITH_MISSING: warning: profile data may be out of date: of 3 functions, 1 has mismatched data that will be ignored
end_comment

begin_comment
comment|// WITH_MISSING: warning: profile data may be incomplete: of 3 functions, 1 has no data
end_comment

begin_function
name|void
name|no_usable_data
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|i
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|no_data
parameter_list|()
block|{ }
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
name|no_usable_data
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

