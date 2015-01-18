begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check for warnings in non-C11 mode:
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -std=c99 -verify -Wc11-extensions %s
end_comment

begin_comment
comment|// Expect no warnings in C11 mode:
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -std=c11 -pedantic -Werror %s
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|a
decl_stmt|;
struct|struct
block|{
comment|// expected-warning{{anonymous structs are a C11 extension}}
name|int
name|b
decl_stmt|;
block|}
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t
block|{
name|int
name|a
decl_stmt|;
union|union
block|{
comment|// expected-warning{{anonymous unions are a C11 extension}}
name|int
name|b
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

end_unit

