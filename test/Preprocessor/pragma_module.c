begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -cc1 -E -fmodules %s -verify
end_comment

begin_comment
comment|// Just checking the syntax here; the semantics are tested elsewhere.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
end_pragma

begin_comment
comment|// expected-error {{expected identifier in module name}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|!
end_pragma

begin_comment
comment|// expected-error {{expected identifier in module name}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|if
end_pragma

begin_comment
comment|// expected-error {{expected identifier in module name}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|foo
name|?
name|bar
end_pragma

begin_comment
comment|// expected-error {{expected '.' or end of directive after module name}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|foo
name|.
end_pragma

begin_comment
comment|// expected-error {{expected identifier}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|foo
name|.
name|bar
name|.
name|baz
name|.
name|quux
end_pragma

begin_comment
comment|// expected-error {{module 'foo' not found}}
end_comment

begin_error
error|#
directive|error
error|here
end_error

begin_comment
comment|// expected-error {{here}}
end_comment

end_unit

