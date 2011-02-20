begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -Wno-unused-value -Wmicrosoft -verify -fms-extensions
end_comment

begin_struct
struct|struct
name|A
block|{
name|int
name|a
index|[]
decl_stmt|;
comment|/* expected-warning {{flexible array member 'a' in otherwise empty struct is a Microsoft extension}} */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|C
block|{
name|int
name|l
decl_stmt|;
union|union
block|{
name|int
name|c1
index|[]
decl_stmt|;
comment|/* expected-warning {{flexible array member 'c1' in a union is a Microsoft extension}}  */
name|char
name|c2
index|[]
decl_stmt|;
comment|/* expected-warning {{flexible array member 'c2' in a union is a Microsoft extension}} */
block|}
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|D
block|{
name|int
name|l
decl_stmt|;
name|int
name|D
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum_decl
enum_decl|enum
name|ENUM1
enum_decl|;
end_enum_decl

begin_comment
comment|// expected-warning {{forward references to 'enum' types are a Microsoft extension}}
end_comment

begin_decl_stmt
name|enum
name|ENUM1
name|var1
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|ENUM1
modifier|*
name|var2
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|ENUM2
block|{
name|ENUM2_a
init|=
operator|(
expr|enum
name|ENUM2
operator|)
literal|4
block|,
name|ENUM2_b
init|=
literal|0x9FFFFFFF
block|,
comment|// expected-warning {{enumerator value is not representable in the underlying type 'int'}}
name|ENUM2_c
init|=
literal|0x100000000
comment|// expected-warning {{enumerator value is not representable in the underlying type 'int'}}
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|notnested
block|{
name|long
name|bad1
decl_stmt|;
name|long
name|bad2
decl_stmt|;
block|}
name|NOTNESTED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nested1
block|{
name|long
name|a
decl_stmt|;
name|struct
name|notnested
name|var1
decl_stmt|;
name|NOTNESTED
name|var2
decl_stmt|;
block|}
name|NESTED1
typedef|;
end_typedef

begin_struct
struct|struct
name|nested2
block|{
name|long
name|b
decl_stmt|;
name|NESTED1
expr_stmt|;
comment|// expected-warning {{anonymous structs are a Microsoft extension}}
block|}
struct|;
end_struct

begin_struct
struct|struct
name|test
block|{
name|int
name|c
decl_stmt|;
struct_decl|struct
name|nested2
struct_decl|;
comment|// expected-warning {{anonymous structs are a Microsoft extension}}
block|}
struct|;
end_struct

begin_function
name|void
name|foo
parameter_list|()
block|{
name|struct
name|test
name|var
decl_stmt|;
name|var
operator|.
name|a
expr_stmt|;
name|var
operator|.
name|b
expr_stmt|;
name|var
operator|.
name|c
expr_stmt|;
name|var
operator|.
name|bad1
expr_stmt|;
comment|// expected-error {{no member named 'bad1' in 'struct test'}}
name|var
operator|.
name|bad2
expr_stmt|;
comment|// expected-error {{no member named 'bad2' in 'struct test'}}
block|}
end_function

end_unit

