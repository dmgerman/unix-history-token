begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we can operate on files from /dev/fd.
end_comment

begin_comment
comment|// REQUIRES: dev-fd-fs
end_comment

begin_comment
comment|// Check reading from named pipes. We cat the input here instead of redirecting
end_comment

begin_comment
comment|// it to ensure that /dev/fd/0 is a named pipe, not just a redirected file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: cat %s | %clang -x c /dev/fd/0 -E> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix DEV-FD-INPUT< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// DEV-FD-INPUT: int x;
end_comment

begin_comment
comment|// Check writing to /dev/fd named pipes. We use cat here as before to ensure we
end_comment

begin_comment
comment|// get a named pipe.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -x c %s -E -o /dev/fd/1 | cat> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix DEV-FD-FIFO-OUTPUT< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// DEV-FD-FIFO-OUTPUT: int x;
end_comment

begin_comment
comment|// Check writing to /dev/fd regular files.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -x c %s -E -o /dev/fd/1> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix DEV-FD-REG-OUTPUT< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// DEV-FD-REG-OUTPUT: int x;
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

end_unit

