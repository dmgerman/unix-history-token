begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|foo
end_pragma

begin_comment
comment|// expected-warning{{expected identifier in '#pragma visibility' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|pop
name|foo
end_pragma

begin_comment
comment|// expected-warning{{extra tokens at end of '#pragma visibility' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
end_pragma

begin_comment
comment|// expected-warning{{missing '(' after '#pragma visibility'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
end_pragma

begin_comment
comment|// expected-warning{{expected identifier in '#pragma visibility' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|hidden
end_pragma

begin_comment
comment|// expected-warning{{missing ')' after '#pragma visibility' - ignoring}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|hidden
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|pop
end_pragma

end_unit

