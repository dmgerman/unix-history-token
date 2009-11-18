begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -pedantic -fixit %s -o - | clang-cc -pedantic -Werror -x c -
end_comment

begin_comment
comment|/* This is a test of the various code modification hints that are    provided as part of warning or extension diagnostics. All of the    warnings will be fixed by -fixit, and the resulting file should    compile cleanly with -Werror -pedantic. */
end_comment

begin_comment
comment|// FIXME: If you put a space at the end of the line, it doesn't work yet!
end_comment

begin_decl_stmt
name|char
modifier|*
name|s
init|=
literal|"hi\ there"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The following line isn't terminated, don't fix it.
end_comment

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{no newline at end of file}}
end_comment

end_unit

