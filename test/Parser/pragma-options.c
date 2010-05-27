begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -fsyntax-only -verify %s
end_comment

begin_comment
comment|/* expected-warning {{expected 'align' following '#pragma options'}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|options
end_pragma

begin_comment
comment|/* expected-warning {{expected '=' following '#pragma options align'}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|options
name|align
end_pragma

begin_comment
comment|/* expected-warning {{expected identifier in '#pragma options'}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
end_pragma

begin_comment
comment|/* expected-warning {{invalid alignment option in '#pragma options align'}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|foo
end_pragma

begin_comment
comment|/* expected-warning {{extra tokens at end of '#pragma options'}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|reset
name|foo
end_pragma

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|natural
end_pragma

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|reset
end_pragma

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|mac68k
end_pragma

begin_comment
comment|/* expected-warning {{unsupported alignment option}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|power
end_pragma

end_unit

