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
comment|// expected-warning {{'ms_struct' attribute ignored}}
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

end_unit

