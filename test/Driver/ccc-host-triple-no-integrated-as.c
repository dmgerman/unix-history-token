begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that -no-integrated-as works when -ccc-host-triple i386-pc-win32-macho or
end_comment

begin_comment
comment|// -ccc-host-triple x86_64-pc-win32-macho is specified.
end_comment

begin_comment
comment|// RUN: %clang -### -c -ccc-host-triple i386-pc-win32-macho -no-integrated-as %s 2> %t1
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=X86< %t1 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ccc-host-triple x86_64-pc-win32-macho -no-integrated-as %s 2> %t2
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=X86_64< %t2 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86: "-cc1"
end_comment

begin_comment
comment|// X86-NOT: "-cc1as"
end_comment

begin_comment
comment|// X86: "-arch"
end_comment

begin_comment
comment|// X86: "i386"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64: "-cc1"
end_comment

begin_comment
comment|// X86_64-NOT: "-cc1as"
end_comment

begin_comment
comment|// X86_64: "-arch"
end_comment

begin_comment
comment|// X86_64: "x86_64"
end_comment

end_unit

