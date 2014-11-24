begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-apple-darwin9 %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|ms_struct
name|on
end_pragma

begin_pragma
pragma|#
directive|pragma
name|ms_struct
name|off
end_pragma

begin_pragma
pragma|#
directive|pragma
name|ms_struct
name|reset
end_pragma

begin_pragma
pragma|#
directive|pragma
name|ms_struct
end_pragma

begin_comment
comment|// expected-warning {{incorrect use of '#pragma ms_struct on|off' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|ms_struct
name|on
name|top
name|of
name|spaghetti
end_pragma

begin_comment
comment|// expected-warning {{extra tokens at end of '#pragma ms_struct' - ignored}}
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|unsigned
name|long
name|bf_1
range|:
literal|12
decl_stmt|;
name|unsigned
name|long
range|:
literal|0
decl_stmt|;
name|unsigned
name|long
name|bf_2
range|:
literal|12
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__ms_struct__
operator|)
argument_list|)
name|t1
struct|;
end_struct

begin_struct
struct|struct
name|S
block|{
name|double
name|__attribute__
argument_list|(
operator|(
name|ms_struct
operator|)
argument_list|)
name|d
decl_stmt|;
comment|// expected-warning {{'ms_struct' attribute only applies to struct or union}}
name|unsigned
name|long
name|bf_1
range|:
literal|12
decl_stmt|;
name|unsigned
name|long
range|:
literal|0
decl_stmt|;
name|unsigned
name|long
name|bf_2
range|:
literal|12
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|ms_struct
operator|)
argument_list|)
name|t2
struct|;
end_struct

begin_enum
enum|enum
block|{
name|A
init|=
literal|0
block|,
name|B
block|,
name|C
block|}
name|__attribute__
argument_list|(
operator|(
name|ms_struct
operator|)
argument_list|)
name|e1
enum|;
end_enum

begin_comment
comment|// expected-warning {{'ms_struct' attribute only applies to struct or union}}
end_comment

begin_comment
comment|// rdar://10513599
end_comment

begin_pragma
pragma|#
directive|pragma
name|ms_struct
name|on
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|pv
decl_stmt|;
name|int
name|l
decl_stmt|;
block|}
name|Foo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|pv1
decl_stmt|;
name|Foo
name|foo
decl_stmt|;
name|unsigned
name|short
name|fInited
range|:
literal|1
decl_stmt|;
name|void
modifier|*
name|pv2
decl_stmt|;
block|}
name|PackOddity
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|ms_struct
name|off
end_pragma

begin_decl_stmt
specifier|static
name|int
name|arr
index|[
sizeof|sizeof
argument_list|(
name|PackOddity
argument_list|)
operator|==
literal|40
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|ms_struct
argument_list|)
name|bad
block|{
comment|// expected-warning {{__declspec attribute 'ms_struct' is not supported}}
block|}
struct|;
end_struct

end_unit

