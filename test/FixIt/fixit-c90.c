begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: cp %s %t    RUN: %clang_cc1 -std=c90 -pedantic -fixit %t    RUN: %clang_cc1 -pedantic -x c -std=c90 -Werror %t  */
end_comment

begin_comment
comment|/* XPASS: *    This test passes because clang merely warns for this syntax error even with    -pedantic -Werror -std=c90.  */
end_comment

begin_comment
comment|/* This is a test of the various code modification hints that are    provided as part of warning or extension diagnostics. All of the    warnings will be fixed by -fixit, and the resulting file should    compile cleanly with -Werror -pedantic. */
end_comment

begin_enum
enum|enum
name|e0
block|{
name|e1
block|, }
enum|;
end_enum

end_unit

