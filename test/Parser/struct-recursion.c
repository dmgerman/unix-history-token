begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only
end_comment

begin_comment
comment|// C99 6.7.2.3p11
end_comment

begin_comment
comment|// mutually recursive structs
end_comment

begin_struct
struct|struct
name|s1
block|{
name|struct
name|s2
modifier|*
name|A
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s2
block|{
name|struct
name|s1
modifier|*
name|B
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// both types are complete now.
end_comment

begin_decl_stmt
name|struct
name|s1
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|s2
name|b
decl_stmt|;
end_decl_stmt

end_unit

