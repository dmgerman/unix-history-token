begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check for proper handling of --sysroot and -isysroot flags.
end_comment

begin_comment
comment|// RUN: %clang -### -fsyntax-only -isysroot /foo/bar %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck %s -check-prefix=ISYSROOT
end_comment

begin_comment
comment|// ISYSROOT: "-isysroot" "{{[^"]*}}/foo/bar"
end_comment

begin_comment
comment|// Check that we get both isysroot for headers, and pass --sysroot on to GCC to
end_comment

begin_comment
comment|// produce the final binary.
end_comment

begin_comment
comment|// RUN: %clang -### -ccc-host-triple x86_64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN:   --sysroot=/foo/bar -o /dev/null %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck %s -check-prefix=SYSROOT_EQ
end_comment

begin_comment
comment|// SYSROOT_EQ: "-isysroot" "{{[^"]*}}/foo/bar"
end_comment

begin_comment
comment|// SYSROOT_EQ: "--sysroot{{" "|=}}{{[^"]*}}/foo/bar"
end_comment

begin_comment
comment|// Check for overriding the header sysroot by providing both --sysroot and
end_comment

begin_comment
comment|// -isysroot.
end_comment

begin_comment
comment|// RUN: %clang -### -ccc-host-triple x86_64-unknown-linux-gnu -isysroot /baz \
end_comment

begin_comment
comment|// RUN:   --sysroot=/foo/bar -o /dev/null %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=ISYSROOT_AND_SYSROOT
end_comment

begin_comment
comment|// ISYSROOT_AND_SYSROOT: "-isysroot" "{{[^"]*}}/baz"
end_comment

begin_comment
comment|// ISYSROOT_AND_SYSROOT: "--sysroot{{" "|=}}{{[^"]*}}/foo/bar"
end_comment

begin_comment
comment|// Check that omitting the equals works as well.
end_comment

begin_comment
comment|// RUN: %clang -### -ccc-host-triple x86_64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN:   --sysroot /foo/bar -o /dev/null %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck %s -check-prefix=SYSROOT_SEPARATE
end_comment

begin_comment
comment|// SYSROOT_SEPARATE: "-isysroot" "{{[^"]*}}/foo/bar"
end_comment

begin_comment
comment|// SYSROOT_SEPARATE: "--sysroot{{" "|=}}{{[^"]*}}/foo/bar"
end_comment

end_unit

