begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -pedantic -verify %s
end_comment

begin_struct
struct|struct
name|one
block|{
name|int
name|a
decl_stmt|;
name|int
name|values
index|[]
decl_stmt|;
comment|// expected-note 3{{initialized flexible array member 'values' is here}}
block|}
name|x
init|=
block|{
literal|5
block|,
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
block|}
struct|;
end_struct

begin_comment
comment|// expected-warning{{flexible array initialization is a GNU extension}}
end_comment

begin_decl_stmt
name|struct
name|one
name|x2
init|=
block|{
literal|5
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{flexible array initialization is a GNU extension}}
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
name|struct
name|one
name|x3
init|=
block|{
literal|5
block|,
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
block|}
decl_stmt|;
comment|// expected-warning{{flexible array initialization is a GNU extension}}
block|}
end_function

begin_struct
struct|struct
name|foo
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
index|[]
decl_stmt|;
comment|// expected-note 6 {{initialized flexible array member 'y' is here}}
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bar
block|{
name|struct
name|foo
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// expected-warning {{'z' may not be nested in a struct due to flexible array member}}
end_comment

begin_decl_stmt
name|struct
name|foo
name|a
init|=
block|{
literal|1
block|,
block|{
literal|2
block|,
literal|3
block|,
literal|4
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{flexible array initialization is a GNU extension}}
end_comment

begin_decl_stmt
name|struct
name|bar
name|b
init|=
block|{
block|{
literal|1
block|,
block|{
literal|2
block|,
literal|3
block|,
literal|4
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{non-empty initialization of flexible array member inside subobject}}
end_comment

begin_decl_stmt
name|struct
name|bar
name|c
init|=
block|{
block|{
literal|1
block|,
block|{ }
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// // expected-warning{{flexible array initialization is a GNU extension}} \
end_comment

begin_comment
comment|// expected-warning{{use of GNU empty initializer extension}} \
end_comment

begin_comment
comment|// expected-warning{{zero size arrays are an extension}}
end_comment

begin_decl_stmt
name|struct
name|foo
name|d
index|[
literal|1
index|]
init|=
block|{
block|{
literal|1
block|,
block|{
literal|2
block|,
literal|3
block|,
literal|4
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'struct foo' may not be used as an array element due to flexible array member}} \
end_comment

begin_comment
comment|// expected-error{{non-empty initialization of flexible array member inside subobject}}
end_comment

begin_decl_stmt
name|struct
name|foo
name|desig_foo
init|=
block|{
operator|.
name|y
operator|=
block|{
literal|2
block|,
literal|3
block|,
literal|4
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bar
name|desig_bar
init|=
block|{
operator|.
name|z
operator|.
name|y
operator|=
block|{ }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{use of GNU empty initializer extension}} \
end_comment

begin_comment
comment|// expected-warning{{zero size arrays are an extension}}
end_comment

begin_decl_stmt
name|struct
name|bar
name|desig_bar2
init|=
block|{
operator|.
name|z
operator|.
name|y
operator|=
block|{
literal|2
block|,
literal|3
block|,
literal|4
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{non-empty initialization of flexible array member inside subobject}}
end_comment

begin_decl_stmt
name|struct
name|foo
name|design_foo2
init|=
block|{
operator|.
name|y
operator|=
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{flexible array requires brace-enclosed initializer}}
end_comment

begin_struct
struct|struct
name|point
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|polygon
block|{
name|int
name|numpoints
decl_stmt|;
name|struct
name|point
name|points
index|[]
decl_stmt|;
comment|// expected-note{{initialized flexible array member 'points' is here}}
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|polygon
name|poly
init|=
block|{
operator|.
name|points
index|[
literal|2
index|]
operator|=
block|{
literal|1
block|,
literal|2
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{designator into flexible array member subobject}}
end_comment

begin_comment
comment|// PR3540
end_comment

begin_struct
struct|struct
name|X
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
name|char
name|data
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Y
block|{
name|int
name|a
range|:
literal|4
decl_stmt|;
name|int
name|b
range|:
literal|4
decl_stmt|;
name|int
name|c
decl_stmt|;
name|int
name|d
decl_stmt|;
name|int
name|e
decl_stmt|;
name|struct
name|X
name|xs
index|[]
decl_stmt|;
comment|// expected-warning{{'struct X' may not be used as an array element due to flexible array member}}
block|}
struct|;
end_struct

end_unit

