begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-apple-darwin %s
end_comment

begin_comment
comment|// This file tests -Wconstant-conversion, a subcategory of -Wconversion
end_comment

begin_comment
comment|// which is on by default.
end_comment

begin_comment
comment|// rdar://problem/6792488
end_comment

begin_function
name|void
name|test_6792488
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
init|=
literal|0x3ff0000000000000U
decl_stmt|;
comment|// expected-warning {{implicit conversion from 'unsigned long' to 'int' changes value from 4607182418800017408 to 0}}
block|}
end_function

begin_function
name|void
name|test_7809123
parameter_list|(
name|void
parameter_list|)
block|{
struct|struct
block|{
name|int
name|i5
range|:
literal|5
decl_stmt|;
block|}
name|a
struct|;
name|a
operator|.
name|i5
operator|=
literal|36
expr_stmt|;
comment|// expected-warning {{implicit truncation from 'int' to bitfield changes value from 36 to 4}}
block|}
end_function

begin_function
name|void
name|test
parameter_list|()
block|{
struct|struct
block|{
name|int
name|bit
range|:
literal|1
decl_stmt|;
block|}
name|a
struct|;
name|a
operator|.
name|bit
operator|=
literal|1
expr_stmt|;
comment|// shouldn't warn
block|}
end_function

begin_enum
enum|enum
name|Test2
block|{
name|K_zero
block|,
name|K_one
block|}
enum|;
end_enum

begin_function
name|enum
name|Test2
name|test2
parameter_list|(
name|enum
name|Test2
modifier|*
name|t
parameter_list|)
block|{
operator|*
name|t
operator|=
literal|20
expr_stmt|;
return|return
literal|10
return|;
comment|// shouldn't warn
block|}
end_function

begin_function
name|void
name|test3
parameter_list|()
block|{
struct|struct
name|A
block|{
name|unsigned
name|int
name|foo
range|:
literal|2
decl_stmt|;
name|int
name|bar
range|:
literal|2
decl_stmt|;
block|}
struct|;
name|struct
name|A
name|a
init|=
block|{
literal|0
block|,
literal|10
block|}
decl_stmt|;
comment|// expected-warning {{implicit truncation from 'int' to bitfield changes value from 10 to 2}}
name|struct
name|A
name|b
index|[]
init|=
block|{
literal|0
block|,
literal|10
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
comment|// expected-warning {{implicit truncation from 'int' to bitfield changes value from 10 to 2}}
name|struct
name|A
name|c
index|[]
init|=
block|{
block|{
literal|10
block|,
literal|0
block|}
block|}
decl_stmt|;
comment|// expected-warning {{implicit truncation from 'int' to bitfield changes value from 10 to 2}}
name|struct
name|A
name|d
init|=
operator|(
expr|struct
name|A
operator|)
block|{
literal|10
block|,
literal|0
block|}
decl_stmt|;
comment|// expected-warning {{implicit truncation from 'int' to bitfield changes value from 10 to 2}}
name|struct
name|A
name|e
init|=
block|{
operator|.
name|foo
operator|=
literal|10
block|}
decl_stmt|;
comment|// expected-warning {{implicit truncation from 'int' to bitfield changes value from 10 to 2}}
block|}
end_function

begin_function
name|void
name|test4
parameter_list|()
block|{
struct|struct
name|A
block|{
name|char
name|c
range|:
literal|2
decl_stmt|;
block|}
name|a
struct|;
name|a
operator|.
name|c
operator|=
literal|0x101
expr_stmt|;
comment|// expected-warning {{implicit truncation from 'int' to bitfield changes value from 257 to 1}}
block|}
end_function

begin_function
name|void
name|test5
parameter_list|()
block|{
struct|struct
name|A
block|{
name|_Bool
name|b
range|:
literal|1
decl_stmt|;
block|}
name|a
struct|;
comment|// Don't warn about this implicit conversion to bool, or at least
comment|// don't warn about it just because it's a bitfield.
name|a
operator|.
name|b
operator|=
literal|100
expr_stmt|;
block|}
end_function

end_unit

