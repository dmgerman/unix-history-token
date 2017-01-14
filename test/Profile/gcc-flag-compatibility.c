begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Tests for -fprofile-generate and -fprofile-use flag compatibility. These two
end_comment

begin_comment
comment|// flags behave similarly to their GCC counterparts:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -fprofile-generate         Generates the profile file ./default.profraw
end_comment

begin_comment
comment|// -fprofile-generate=<dir>   Generates the profile file<dir>/default.profraw
end_comment

begin_comment
comment|// -fprofile-use              Uses the profile file ./default.profdata
end_comment

begin_comment
comment|// -fprofile-use=<dir>        Uses the profile file<dir>/default.profdata
end_comment

begin_comment
comment|// -fprofile-use=<dir>/file   Uses the profile file<dir>/file
end_comment

begin_comment
comment|// RUN: %clang %s -c -S -o - -emit-llvm -fprofile-generate | FileCheck -check-prefix=PROFILE-GEN %s
end_comment

begin_comment
comment|// PROFILE-GEN: __llvm_profile_filename
end_comment

begin_comment
comment|// Check that -fprofile-generate=/path/to generates /path/to/default.profraw
end_comment

begin_comment
comment|// RUN: %clang %s -c -S -o - -emit-llvm -fprofile-generate=/path/to | FileCheck -check-prefix=PROFILE-GEN-EQ %s
end_comment

begin_comment
comment|// PROFILE-GEN-EQ: constant [{{.*}} x i8] c"/path/to{{/|\\5C}}{{.*}}\00"
end_comment

begin_comment
comment|// Check that -fprofile-use=some/path reads some/path/default.profdata
end_comment

begin_comment
comment|// RUN: rm -rf %t.dir
end_comment

begin_comment
comment|// RUN: mkdir -p %t.dir/some/path
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/gcc-flag-compatibility.proftext -o %t.dir/some/path/default.profdata
end_comment

begin_comment
comment|// RUN: %clang %s -o - -Xclang -disable-llvm-passes -emit-llvm -S -fprofile-use=%t.dir/some/path | FileCheck -check-prefix=PROFILE-USE-2 %s
end_comment

begin_comment
comment|// PROFILE-USE-2: = !{!"branch_weights", i32 101, i32 2}
end_comment

begin_comment
comment|// Check that -fprofile-use=some/path/file.prof reads some/path/file.prof
end_comment

begin_comment
comment|// RUN: rm -rf %t.dir
end_comment

begin_comment
comment|// RUN: mkdir -p %t.dir/some/path
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/gcc-flag-compatibility.proftext -o %t.dir/some/path/file.prof
end_comment

begin_comment
comment|// RUN: %clang %s -o - -Xclang -disable-llvm-passes -emit-llvm -S -fprofile-use=%t.dir/some/path/file.prof | FileCheck -check-prefix=PROFILE-USE-3 %s
end_comment

begin_comment
comment|// PROFILE-USE-3: = !{!"branch_weights", i32 101, i32 2}
end_comment

begin_decl_stmt
name|int
name|X
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
name|i
operator|++
control|)
name|X
operator|+=
name|i
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

