begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// cygming have not supported integrated-as yet.
end_comment

begin_comment
comment|// XFAIL: cygwin,mingw32
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check to make sure clang is somewhat picky about -g options.
end_comment

begin_comment
comment|// (Delived from debug-options.c)
end_comment

begin_comment
comment|// rdar://10383444
end_comment

begin_comment
comment|// RUN: %clang -### -c -save-temps -g %s 2>&1 | FileCheck -check-prefix=SAVE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SAVE: "-cc1as"
end_comment

begin_comment
comment|// SAVE-NOT: "-g"
end_comment

begin_comment
comment|// Check to make sure clang with -g on a .s file gets passed.
end_comment

begin_comment
comment|// rdar://9275556
end_comment

begin_comment
comment|// RUN: touch %t.s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %t.s 2>&1 | FileCheck -check-prefix=S %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S: "-cc1as"
end_comment

begin_comment
comment|// S: "-g"
end_comment

end_unit

