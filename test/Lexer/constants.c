begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -pedantic -ftrigraphs %s
end_comment

begin_decl_stmt
name|int
name|x
init|=
literal|000000080
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid digit}}
end_comment

begin_decl_stmt
name|int
name|y
init|=
literal|0000
expr|\
literal|00080
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid digit}}
end_comment

begin_decl_stmt
name|float
name|X
init|=
literal|1.17549435e-38F
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|Y
init|=
literal|08.123456
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR2252
end_comment

begin_if
if|#
directive|if
operator|-
literal|0x8000000000000000
end_if

begin_comment
comment|// should not warn.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|-
literal|01000000000000000000000
end_if

begin_comment
comment|// should not warn.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|9223372036854775808
end_if

begin_comment
comment|// expected-warning {{integer literal is too large to be represented in a signed integer type, interpreting as unsigned}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0x10000000000000000
end_if

begin_comment
comment|// expected-error {{integer literal is too large to be represented in any integer type}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|c
index|[]
init|=
block|{
literal|'df'
block|,
comment|// expected-warning {{multi-character character constant}}
literal|'\t'
block|,
literal|'\\ t'
block|,
literal|'??!'
block|,
comment|// expected-warning {{trigraph converted to '|' character}}
literal|'abcd'
comment|// expected-warning {{multi-character character constant}}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//  PR4499
end_comment

begin_decl_stmt
name|int
name|m0
init|=
literal|'0'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|m1
init|=
literal|'\\\''
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{multi-character character constant}}
end_comment

begin_decl_stmt
name|int
name|m2
init|=
literal|'\\\\'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{multi-character character constant}}
end_comment

begin_decl_stmt
name|int
name|m3
init|=
literal|'\\\ '
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wmultichar"
end_pragma

begin_decl_stmt
name|int
name|d
init|=
literal|'df'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no warning.
end_comment

begin_decl_stmt
name|int
name|e
init|=
literal|'abcd'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// still warn: expected-warning {{multi-character character constant}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wfour-char-constants"
end_pragma

begin_decl_stmt
name|int
name|f
init|=
literal|'abcd'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ignored.
end_comment

begin_comment
comment|// rdar://problem/6974641
end_comment

begin_decl_stmt
name|float
name|t0
index|[]
init|=
block|{
literal|1.9e20f
block|,
literal|1.9e-20f
block|,
literal|1.9e50f
block|,
comment|// expected-warning {{too large}}
literal|1.9e-50f
block|,
comment|// expected-warning {{too small}}
operator|-
literal|1.9e20f
block|,
operator|-
literal|1.9e-20f
block|,
operator|-
literal|1.9e50f
block|,
comment|// expected-warning {{too large}}
operator|-
literal|1.9e-50f
comment|// expected-warning {{too small}}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|t1
index|[]
init|=
block|{
literal|1.9e50
block|,
literal|1.9e-50
block|,
literal|1.9e500
block|,
comment|// expected-warning {{too large}}
literal|1.9e-500
block|,
comment|// expected-warning {{too small}}
operator|-
literal|1.9e50
block|,
operator|-
literal|1.9e-50
block|,
operator|-
literal|1.9e500
block|,
comment|// expected-warning {{too large}}
operator|-
literal|1.9e-500
comment|// expected-warning {{too small}}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR7888
end_comment

begin_decl_stmt
name|double
name|g
init|=
literal|1e100000000
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{too large}}
end_comment

begin_decl_stmt
name|char
name|h
init|=
literal|'\u1234'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{character too large for enclosing character literal type}}
end_comment

end_unit

