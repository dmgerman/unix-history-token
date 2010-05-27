begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang-cc1 -triple x86_64-apple-darwin10 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang-cc1 -triple i386-pc-linux-gnu -fsyntax-only -verify %s
end_comment

begin_comment
comment|/* expected-error {{mac68k alignment pragma is not supported}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|mac68k
end_pragma

end_unit

