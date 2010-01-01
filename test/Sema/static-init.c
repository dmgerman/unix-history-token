begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -fsyntax-only -verify %s
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|f
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|b
init|=
name|f
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{initializer element is not a compile-time constant}}
end_comment

begin_decl_stmt
name|float
name|r
init|=
call|(
name|float
call|)
argument_list|(
name|intptr_t
argument_list|)
operator|&
name|r
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{initializer element is not a compile-time constant}}
end_comment

begin_decl_stmt
name|intptr_t
name|s
init|=
operator|(
name|intptr_t
operator|)
operator|&
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_Bool
name|t
init|=
operator|&
name|t
decl_stmt|;
end_decl_stmt

begin_union
union|union
name|bar
block|{
name|int
name|i
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|foo
block|{
name|unsigned
name|ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|union
name|bar
name|u
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|foo
name|x
init|=
block|{
operator|(
name|intptr_t
operator|)
name|u
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no-error
end_comment

begin_decl_stmt
name|struct
name|foo
name|y
init|=
block|{
operator|(
name|char
operator|)
name|u
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{initializer element is not a compile-time constant}}
end_comment

end_unit

