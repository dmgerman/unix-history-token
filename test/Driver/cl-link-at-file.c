begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR17239 - The /link option, when inside a response file, should only extend
end_comment

begin_comment
comment|// until the end of the response file (and not the entire command line)
end_comment

begin_comment
comment|// Note: %s must be preceded by -- or bound to another option, otherwise it may
end_comment

begin_comment
comment|// be interpreted as a command-line option, e.g. on Mac where %s is commonly
end_comment

begin_comment
comment|// under /Users.
end_comment

begin_comment
comment|// RUN: echo /link bar.lib baz.lib> %t.args
end_comment

begin_comment
comment|// RUN: touch %t.obj
end_comment

begin_comment
comment|// RUN: %clang_cl -### @%t.args -- %t.obj 2>&1 | FileCheck %s -check-prefix=ARGS
end_comment

begin_comment
comment|// If the "/link" option captures all remaining args beyond its response file,
end_comment

begin_comment
comment|// it will also capture "--" and our input argument. In this case, Clang will
end_comment

begin_comment
comment|// be clueless and will emit "argument unused" warnings. If PR17239 is properly
end_comment

begin_comment
comment|// fixed, this should not happen because the "/link" option is restricted to
end_comment

begin_comment
comment|// consume only remaining args in its response file.
end_comment

begin_comment
comment|// ARGS-NOT: argument unused during compilation
end_comment

begin_comment
comment|// Identify the linker command
end_comment

begin_comment
comment|// ARGS: link.exe
end_comment

end_unit

