begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|I
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
block|{
specifier|static
specifier|const
name|int
name|BelowMin
init|=
operator|-
literal|1
decl_stmt|;
specifier|static
specifier|const
name|int
name|AboveMax
init|=
literal|32
decl_stmt|;
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "I"(j));
comment|// expected-error{{constraint 'I' expects an integer constant expression}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "I"(BelowMin));
comment|// expected-error{{value '-1' out of range for constraint 'I'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "I"(AboveMax));
comment|// expected-error{{value '32' out of range for constraint 'I'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "I"(16));
comment|// expected-no-error
block|}
end_function

begin_function
name|void
name|J
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
block|{
specifier|static
specifier|const
name|int
name|BelowMin
init|=
operator|-
literal|1
decl_stmt|;
specifier|static
specifier|const
name|int
name|AboveMax
init|=
literal|64
decl_stmt|;
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "J"(j));
comment|// expected-error{{constraint 'J' expects an integer constant expression}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "J"(BelowMin));
comment|// expected-error{{value '-1' out of range for constraint 'J'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "J"(AboveMax));
comment|// expected-error{{value '64' out of range for constraint 'J'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "J"(32));
comment|// expected-no-error
block|}
end_function

begin_function
name|void
name|K
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
block|{
specifier|static
specifier|const
name|int
name|BelowMin
init|=
operator|-
literal|129
decl_stmt|;
specifier|static
specifier|const
name|int
name|AboveMax
init|=
literal|128
decl_stmt|;
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "K"(j));
comment|// expected-error{{constraint 'K' expects an integer constant expression}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "K"(BelowMin));
comment|// expected-error{{value '-129' out of range for constraint 'K'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "K"(AboveMax));
comment|// expected-error{{value '128' out of range for constraint 'K'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "K"(96));
comment|// expected-no-error
block|}
end_function

begin_function
name|void
name|M
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
block|{
specifier|static
specifier|const
name|int
name|BelowMin
init|=
operator|-
literal|1
decl_stmt|;
specifier|static
specifier|const
name|int
name|AboveMax
init|=
literal|4
decl_stmt|;
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "M"(j));
comment|// expected-error{{constraint 'M' expects an integer constant expression}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "M"(BelowMin));
comment|// expected-error{{value '-1' out of range for constraint 'M'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "M"(AboveMax));
comment|// expected-error{{value '4' out of range for constraint 'M'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "M"(2));
comment|// expected-no-error
block|}
end_function

begin_function
name|void
name|N
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
block|{
specifier|static
specifier|const
name|int
name|BelowMin
init|=
operator|-
literal|1
decl_stmt|;
specifier|static
specifier|const
name|int
name|AboveMax
init|=
literal|256
decl_stmt|;
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "N"(j));
comment|// expected-error{{constraint 'N' expects an integer constant expression}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "N"(BelowMin));
comment|// expected-error{{value '-1' out of range for constraint 'N'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "N"(AboveMax));
comment|// expected-error{{value '256' out of range for constraint 'N'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "N"(128));
comment|// expected-no-error
block|}
end_function

begin_function
name|void
name|O
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
block|{
specifier|static
specifier|const
name|int
name|BelowMin
init|=
operator|-
literal|1
decl_stmt|;
specifier|static
specifier|const
name|int
name|AboveMax
init|=
literal|128
decl_stmt|;
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "O"(j));
comment|// expected-error{{constraint 'O' expects an integer constant expression}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "O"(BelowMin));
comment|// expected-error{{value '-1' out of range for constraint 'O'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "O"(AboveMax));
comment|// expected-error{{value '128' out of range for constraint 'O'}}
asm|__asm__("xorl %0,%2"           : "=r"(i)           : "0"(i), "O"(64));
comment|// expected-no-error
block|}
end_function

end_unit

