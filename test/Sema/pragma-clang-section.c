begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -triple arm-none-eabi
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|bss
name|=
literal|"mybss.1"
name|data
name|=
literal|"mydata.1"
name|rodata
name|=
literal|"myrodata.1"
name|text
name|=
literal|"mytext.1"
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|bss
name|=
literal|""
name|data
name|=
literal|""
name|rodata
name|=
literal|""
name|text
name|=
literal|""
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|dss
name|=
literal|"mybss.2"
end_pragma

begin_comment
comment|// expected-error {{expected one of [bss|data|rodata|text] section kind in '#pragma clang section'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|deta
name|=
literal|"mydata.2"
end_pragma

begin_comment
comment|// expected-error {{expected one of [bss|data|rodata|text] section kind in '#pragma clang section'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|rodeta
name|=
literal|"rodata.2"
end_pragma

begin_comment
comment|// expected-error {{expected one of [bss|data|rodata|text] section kind in '#pragma clang section'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|taxt
name|=
literal|"text.2"
end_pragma

begin_comment
comment|// expected-error {{expected one of [bss|data|rodata|text] section kind in '#pragma clang section'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|section
name|bss
name|=
literal|"mybss.2"
end_pragma

begin_comment
comment|// expected-error {{expected one of [bss|data|rodata|text] section kind in '#pragma clang section'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|bss
literal|"mybss.2"
end_pragma

begin_comment
comment|// expected-error {{expected '=' following '#pragma clang section bss'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|data
literal|"mydata.2"
end_pragma

begin_comment
comment|// expected-error {{expected '=' following '#pragma clang section data'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|rodata
literal|"myrodata.2"
end_pragma

begin_comment
comment|// expected-error {{expected '=' following '#pragma clang section rodata'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|bss
name|=
literal|""
name|data
name|=
literal|""
name|rodata
name|=
literal|""
name|text
name|=
literal|""
name|more
end_pragma

begin_comment
comment|//expected-error {{expected one of [bss|data|rodata|text] section kind in '#pragma clang section'}}
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

end_unit

