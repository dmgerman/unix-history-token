begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -verify %s
end_comment

begin_comment
comment|//<rdar://problem/12415959>
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
block|}
end_function

end_unit

