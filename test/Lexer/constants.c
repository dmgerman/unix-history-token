begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify -pedantic -trigraphs %s
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

begin_decl_stmt
name|char
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

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wmultichar"
end_pragma

begin_decl_stmt
name|char
name|d
init|=
literal|'df'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no warning.
end_comment

begin_decl_stmt
name|char
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
name|char
name|f
init|=
literal|'abcd'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ignored.
end_comment

end_unit

