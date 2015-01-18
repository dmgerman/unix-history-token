begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -target-feature +avx -verify %s
end_comment

begin_comment
comment|//<rdar://problem/12415959>
end_comment

begin_comment
comment|// rdar://problem/11846140
end_comment

begin_comment
comment|// rdar://problem/17476970
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|u_int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int64_t
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|__m128
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|__m256
name|__attribute__
typedef|((
name|vector_size
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|__m512
name|__attribute__
typedef|((
name|vector_size
typedef|(64)));
end_typedef

begin_decl_stmt
name|__m128
name|val128
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__m256
name|val256
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__m512
name|val512
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|func1
parameter_list|()
block|{
comment|// Error out if size is> 32-bits.
name|uint32_t
name|msr
init|=
literal|0x8b
decl_stmt|;
name|uint64_t
name|val
init|=
literal|0
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("wrmsr"                    :                    : "c" (msr),                      "a" ((val& 0xFFFFFFFFUL)),
comment|// expected-error {{invalid input size for constraint 'a'}}
asm|"d" (((val>> 32)& 0xFFFFFFFFUL)));
comment|// Don't error out if the size of the destination is<= 32 bits.
name|unsigned
name|char
name|data
decl_stmt|;
name|unsigned
name|int
name|port
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("outb %0, %w1" : : "a" (data), "Nd" (port));
comment|// No error expected.
asm|__asm__
specifier|volatile
asm|("outb %0, %w1" : : "R" (val), "Nd" (port));
comment|// expected-error {{invalid input size for constraint 'R'}}
asm|__asm__
specifier|volatile
asm|("outb %0, %w1" : : "q" (val), "Nd" (port));
comment|// expected-error {{invalid input size for constraint 'q'}}
asm|__asm__
specifier|volatile
asm|("outb %0, %w1" : : "Q" (val), "Nd" (port));
comment|// expected-error {{invalid input size for constraint 'Q'}}
asm|__asm__
specifier|volatile
asm|("outb %0, %w1" : : "b" (val), "Nd" (port));
comment|// expected-error {{invalid input size for constraint 'b'}}
asm|__asm__
specifier|volatile
asm|("outb %0, %w1" : : "c" (val), "Nd" (port));
comment|// expected-error {{invalid input size for constraint 'c'}}
asm|__asm__
specifier|volatile
asm|("outb %0, %w1" : : "d" (val), "Nd" (port));
comment|// expected-error {{invalid input size for constraint 'd'}}
asm|__asm__
specifier|volatile
asm|("outb %0, %w1" : : "S" (val), "Nd" (port));
comment|// expected-error {{invalid input size for constraint 'S'}}
asm|__asm__
specifier|volatile
asm|("outb %0, %w1" : : "D" (val), "Nd" (port));
comment|// expected-error {{invalid input size for constraint 'D'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : : "A" (val128));
comment|// expected-error {{invalid input size for constraint 'A'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : : "f" (val256));
comment|// expected-error {{invalid input size for constraint 'f'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : : "t" (val256));
comment|// expected-error {{invalid input size for constraint 't'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : : "u" (val256));
comment|// expected-error {{invalid input size for constraint 'u'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : : "x" (val512));
comment|// expected-error {{invalid input size for constraint 'x'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=R" (val));
comment|// expected-error {{invalid output size for constraint '=R'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=q" (val));
comment|// expected-error {{invalid output size for constraint '=q'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=Q" (val));
comment|// expected-error {{invalid output size for constraint '=Q'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=a" (val));
comment|// expected-error {{invalid output size for constraint '=a'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=b" (val));
comment|// expected-error {{invalid output size for constraint '=b'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=c" (val));
comment|// expected-error {{invalid output size for constraint '=c'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=d" (val));
comment|// expected-error {{invalid output size for constraint '=d'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=S" (val));
comment|// expected-error {{invalid output size for constraint '=S'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=D" (val));
comment|// expected-error {{invalid output size for constraint '=D'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=A" (val128));
comment|// expected-error {{invalid output size for constraint '=A'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=t" (val256));
comment|// expected-error {{invalid output size for constraint '=t'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=u" (val256));
comment|// expected-error {{invalid output size for constraint '=u'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=x" (val512));
comment|// expected-error {{invalid output size for constraint '=x'}}
ifdef|#
directive|ifdef
name|__AVX__
asm|__asm__
specifier|volatile
asm|("foo1 %0" : : "x" (val256));
comment|// No error.
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=x" (val256));
comment|// No error.
else|#
directive|else
asm|__asm__
specifier|volatile
asm|("foo1 %0" : : "x" (val256));
comment|// expected-error {{invalid input size for constraint 'x'}}
asm|__asm__
specifier|volatile
asm|("foo1 %0" : "=x" (val256));
comment|// expected-error {{invalid output size for constraint '=x'}}
endif|#
directive|endif
block|}
end_function

end_unit

