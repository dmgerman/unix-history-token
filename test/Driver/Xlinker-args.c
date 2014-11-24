begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we extract --no-demangle from '-Xlinker' and '-Wl,', since that
end_comment

begin_comment
comment|// was a collect2 argument.
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### \
end_comment

begin_comment
comment|// RUN:   -Xlinker one -Xlinker --no-demangle \
end_comment

begin_comment
comment|// RUN:   -Wl,two,--no-demangle,three -Xlinker four -z five %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=DARWIN< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:   -Xlinker one -Xlinker --no-demangle \
end_comment

begin_comment
comment|// RUN:   -Wl,two,--no-demangle,three -Xlinker four -z five %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=LINUX< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// DARWIN-NOT: --no-demangle
end_comment

begin_comment
comment|// DARWIN: "one" "two" "three" "four" "-z" "five"
end_comment

begin_comment
comment|// LINUX: "--no-demangle" "one" "two" "three" "four" "-z" "five"
end_comment

begin_comment
comment|// Check that we forward '-Xlinker' and '-Wl,' on Windows.
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-win32 -### \
end_comment

begin_comment
comment|// RUN:   -Xlinker one -Wl,two %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck -check-prefix=WIN %s
end_comment

begin_comment
comment|// WIN: link.exe
end_comment

begin_comment
comment|// WIN: "one"
end_comment

begin_comment
comment|// WIN: "two"
end_comment

end_unit

