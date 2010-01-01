begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// FIXME: Disable pending PR4941.
end_comment

begin_comment
comment|// RUX: clang -ccc-host-triple x86_64-apple-darwin9 -arch arm -### -fsyntax-only %s 2> %t&&
end_comment

begin_comment
comment|// RUX: grep -- "-fno-builtin-strcat" %t&&
end_comment

begin_comment
comment|// RUX: grep -- "-fno-builtin-strcpy" %t&&
end_comment

begin_comment
comment|// FIXME: Disable pending PR4941.
end_comment

begin_comment
comment|// RUX: clang -ccc-host-triple x86_64-apple-darwin9 -arch arm -### -fsyntax-only %s -fbuiltin-strcat -fbuiltin-strcpy 2> %t&&
end_comment

begin_comment
comment|// RUX: not grep -- "-fno-builtin-strcat" %t&&
end_comment

begin_comment
comment|// RUX: not grep -- "-fno-builtin-strcpy" %t&&
end_comment

begin_comment
comment|// RUN: %clang -ccc-no-clang -ccc-host-triple x86_64-apple-darwin9 -arch arm -### -fsyntax-only %s -fbuiltin-strcat -fbuiltin-strcpy 2> %t
end_comment

begin_comment
comment|// RUN: not grep -- "-fno-builtin-strcat" %t
end_comment

begin_comment
comment|// RUN: not grep -- "-fno-builtin-strcpy" %t
end_comment

end_unit

