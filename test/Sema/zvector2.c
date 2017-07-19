begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -fzvector -target-cpu z14 \
end_comment

begin_comment
comment|// RUN:  -fno-lax-vector-conversions -W -Wall -Wconversion \
end_comment

begin_comment
comment|// RUN:  -Werror -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|vector
name|signed
name|char
name|sc
decl_stmt|,
name|sc2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|char
name|uc
decl_stmt|,
name|uc2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|char
name|bc
decl_stmt|,
name|bc2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|short
name|ss
decl_stmt|,
name|ss2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|short
name|us
decl_stmt|,
name|us2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|short
name|bs
decl_stmt|,
name|bs2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|int
name|si
decl_stmt|,
name|si2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|int
name|ui
decl_stmt|,
name|ui2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|int
name|bi
decl_stmt|,
name|bi2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|long
name|long
name|sl
decl_stmt|,
name|sl2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|long
name|long
name|ul
decl_stmt|,
name|ul2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|long
name|long
name|bl
decl_stmt|,
name|bl2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|double
name|fd
decl_stmt|,
name|fd2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|float
name|ff
decl_stmt|,
name|ff2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
comment|// -------------------------------------------------------------------------
comment|// Test assignment.
comment|// -------------------------------------------------------------------------
name|ff
operator|=
name|ff2
expr_stmt|;
name|sc
operator|=
name|ff2
expr_stmt|;
comment|// expected-error {{incompatible type}}
name|ff
operator|=
name|sc2
expr_stmt|;
comment|// expected-error {{incompatible type}}
name|uc
operator|=
name|ff2
expr_stmt|;
comment|// expected-error {{incompatible type}}
name|ff
operator|=
name|uc2
expr_stmt|;
comment|// expected-error {{incompatible type}}
name|bc
operator|=
name|ff2
expr_stmt|;
comment|// expected-error {{incompatible type}}
name|ff
operator|=
name|bc2
expr_stmt|;
comment|// expected-error {{incompatible type}}
name|fd
operator|=
name|ff2
expr_stmt|;
comment|// expected-error {{incompatible type}}
name|ff
operator|=
name|fd2
expr_stmt|;
comment|// expected-error {{incompatible type}}
comment|// -------------------------------------------------------------------------
comment|// Test casts to same element width.
comment|// -------------------------------------------------------------------------
name|ui
operator|=
operator|(
name|vector
name|unsigned
name|int
operator|)
name|ff2
expr_stmt|;
name|ff
operator|=
operator|(
name|vector
name|float
operator|)
name|si2
expr_stmt|;
comment|// -------------------------------------------------------------------------
comment|// Test casts to different element width.
comment|// -------------------------------------------------------------------------
name|uc
operator|=
operator|(
name|vector
name|unsigned
name|char
operator|)
name|ff2
expr_stmt|;
name|us
operator|=
operator|(
name|vector
name|unsigned
name|short
operator|)
name|ff2
expr_stmt|;
name|ul
operator|=
operator|(
name|vector
name|unsigned
name|long
name|long
operator|)
name|ff2
expr_stmt|;
name|ff
operator|=
operator|(
name|vector
name|float
operator|)
name|sc2
expr_stmt|;
name|ff
operator|=
operator|(
name|vector
name|float
operator|)
name|ss2
expr_stmt|;
name|ff
operator|=
operator|(
name|vector
name|float
operator|)
name|sl2
expr_stmt|;
comment|// -------------------------------------------------------------------------
comment|// Test unary operators.
comment|// -------------------------------------------------------------------------
operator|++
name|ff2
expr_stmt|;
name|ff
operator|++
expr_stmt|;
operator|--
name|ff2
expr_stmt|;
name|ff
operator|--
expr_stmt|;
name|ff
operator|=
operator|+
name|ff2
expr_stmt|;
name|ff
operator|=
operator|-
name|ff2
expr_stmt|;
name|ff
operator|=
operator|~
name|ff2
expr_stmt|;
comment|// expected-error {{invalid argument}}
comment|// -------------------------------------------------------------------------
comment|// Test binary arithmetic operators.
comment|// -------------------------------------------------------------------------
name|ff
operator|=
name|ff
operator|+
name|ff2
expr_stmt|;
name|ff
operator|=
name|ff
operator|+
name|ui2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|si
operator|+
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|fd
operator|+
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|+=
name|ff2
expr_stmt|;
name|ff
operator|+=
name|fd2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|sc
operator|+=
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|ff
operator|-
name|ff2
expr_stmt|;
name|ff
operator|=
name|ff
operator|-
name|ui2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|si
operator|-
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|fd
operator|-
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|-=
name|ff2
expr_stmt|;
name|ff
operator|-=
name|fd2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|sc
operator|-=
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|ff
operator|*
name|ff2
expr_stmt|;
name|ff
operator|=
name|ff
operator|*
name|ui2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|si
operator|*
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|fd
operator|*
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|*=
name|ff2
expr_stmt|;
name|ff
operator|*=
name|fd2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|sc
operator|*=
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|ff
operator|/
name|ff2
expr_stmt|;
name|ff
operator|=
name|ff
operator|/
name|ui2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|si
operator|/
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|fd
operator|/
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|/=
name|ff2
expr_stmt|;
name|ff
operator|/=
name|fd2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|sc
operator|/=
name|ff2
expr_stmt|;
comment|// expected-error {{cannot convert}}
name|ff
operator|=
name|ff
operator|%
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator|%
name|ui2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|si
operator|%
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|fd
operator|%
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|%=
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|%=
name|fd2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|sc
operator|%=
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
comment|// -------------------------------------------------------------------------
comment|// Test bitwise binary operators.
comment|// -------------------------------------------------------------------------
name|ff
operator|=
name|ff
operator|&
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|bi
operator|&
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|fd
operator|&
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator|&
name|bi2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator|&
name|si2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator|&
name|ui2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|sc
operator|&=
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|&=
name|bc2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|&=
name|fd2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator||
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|bi
operator||
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|fd
operator||
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator||
name|bi2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator||
name|si2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator||
name|ui2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|sc
operator||=
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator||=
name|bc2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator||=
name|fd2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator|^
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|bi
operator|^
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|fd
operator|^
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator|^
name|bi2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator|^
name|si2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|=
name|ff
operator|^
name|ui2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|sc
operator|^=
name|ff2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|^=
name|bc2
expr_stmt|;
comment|// expected-error {{invalid operands}}
name|ff
operator|^=
name|fd2
expr_stmt|;
comment|// expected-error {{invalid operands}}
comment|// -------------------------------------------------------------------------
comment|// Test shift operators.
comment|// -------------------------------------------------------------------------
name|ff
operator|=
name|ff
operator|<<
name|ff2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|ff
operator|=
name|ff
operator|<<
name|fd2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|ff
operator|=
name|ff
operator|<<
name|ui2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|ff
operator|=
name|sl
operator|<<
name|ff2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|sc
operator|<<=
name|ff2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|ff
operator|<<=
name|ff2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|fd
operator|<<=
name|ff2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|ff
operator|=
name|ff
operator|>>
name|ff2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|ff
operator|=
name|ff
operator|>>
name|fd2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|ff
operator|=
name|ff
operator|>>
name|ui2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|ff
operator|=
name|sl
operator|>>
name|ff2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|sc
operator|>>=
name|ff2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|ff
operator|>>=
name|ff2
expr_stmt|;
comment|// expected-error {{integer is required}}
name|fd
operator|>>=
name|ff2
expr_stmt|;
comment|// expected-error {{integer is required}}
comment|// -------------------------------------------------------------------------
comment|// Test comparison operators.
comment|// -------------------------------------------------------------------------
call|(
name|void
call|)
argument_list|(
name|ff
operator|==
name|ff2
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|ff
operator|==
name|fd2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ff
operator|==
name|ui2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ui
operator|==
name|ff2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ff
operator|!=
name|ff2
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|ff
operator|!=
name|fd2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ff
operator|!=
name|ui2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ui
operator|!=
name|ff2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ff
operator|<=
name|ff2
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|ff
operator|<=
name|fd2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ff
operator|<=
name|ui2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ui
operator|<=
name|ff2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ff
operator|>=
name|ff2
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|ff
operator|>=
name|fd2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ff
operator|>=
name|ui2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ui
operator|>=
name|ff2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ff
operator|<
name|ff2
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|ff
operator|<
name|fd2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ff
operator|<
name|ui2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ui
operator|<
name|ff2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ff
operator|>
name|ff2
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|ff
operator|>
name|fd2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ff
operator|>
name|ui2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
call|(
name|void
call|)
argument_list|(
name|ui
operator|>
name|ff2
argument_list|)
expr_stmt|;
comment|// expected-error {{cannot convert}}
block|}
end_function

end_unit

