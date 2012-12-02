begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -std=c99 -pedantic-errors %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -std=c99 -emit-pch -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -std=c99 -pedantic-errors -include-pch %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -std=c99 -pedantic-errors -DINCLUDED %s -verify
end_comment

begin_comment
comment|// This last one should warn for -Wempty-translation-unit (C99 6.9p1).
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INCLUDED
argument_list|)
end_if

begin_comment
comment|// empty except for the prefix header
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HEADER
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|int
name|my_int
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INCLUDED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HEADER
end_define

begin_include
include|#
directive|include
file|"empty-with-headers.c"
end_include

begin_comment
comment|// empty except for the header
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// This should only fire if the header is not included,
end_comment

begin_comment
comment|// either explicitly or as a prefix header.
end_comment

begin_comment
comment|// expected-error{{ISO C requires a translation unit to contain at least one declaration}}
end_comment

end_unit

