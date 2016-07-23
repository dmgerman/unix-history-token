begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E -CC -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -CC -DPEDANTIC -pedantic -verify
end_comment

begin_define
define|#
directive|define
name|FOO
value|&& 1
end_define

begin_if
if|#
directive|if
name|defined
name|FOO
name|FOO
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|A
end_define

begin_define
define|#
directive|define
name|B
value|defined(A)
end_define

begin_if
if|#
directive|if
name|B
end_if

begin_comment
comment|// expected-warning{{macro expansion producing 'defined' has undefined behavior}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|m_foo
end_define

begin_define
define|#
directive|define
name|TEST
parameter_list|(
name|a
parameter_list|)
value|(defined(m_##a)&& a)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PEDANTIC
argument_list|)
end_if

begin_comment
comment|// expected-warning@+4{{macro expansion producing 'defined' has undefined behavior}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// This shouldn't warn by default, only with pedantic:
end_comment

begin_if
if|#
directive|if
name|TEST
argument_list|(
name|foo
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Only one diagnostic for this case:
end_comment

begin_define
define|#
directive|define
name|INVALID
value|defined(
end_define

begin_if
if|#
directive|if
name|INVALID
end_if

begin_comment
comment|// expected-error{{macro name missing}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

