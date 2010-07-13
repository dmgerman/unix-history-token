begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fno-spell-checking -verify %s
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|Point
typedef|;
end_typedef

begin_decl_stmt
name|point
name|p1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{unknown type name 'point'}}
end_comment

end_unit

