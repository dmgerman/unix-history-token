begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// PR3459
end_comment

begin_struct
struct|struct
name|bar
block|{
name|char
name|n
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|foo
block|{
name|char
name|name
index|[
operator|(
name|int
operator|)
operator|&
operator|(
operator|(
expr|struct
name|bar
operator|*
block|)
literal|0
end_struct

begin_expr_stmt
unit|)
operator|->
name|n
expr|]
expr_stmt|;
end_expr_stmt

begin_macro
name|char
end_macro

begin_expr_stmt
name|name2
index|[
operator|(
name|int
operator|)
operator|&
operator|(
operator|(
expr|struct
name|bar
operator|*
end_expr_stmt

begin_expr_stmt
unit|)
literal|0
end_expr_stmt

begin_expr_stmt
unit|)
operator|->
name|n
operator|-
literal|1
expr|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|//expected-error{{array size is negative}}
end_comment

begin_comment
unit|};
comment|// PR3430
end_comment

begin_struct
struct|struct
name|s
block|{
struct|struct
name|st
block|{
name|int
name|v
decl_stmt|;
block|}
modifier|*
name|ts
struct|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|st
struct_decl|;
end_struct_decl

begin_function
name|int
name|foo
parameter_list|()
block|{
name|struct
name|st
modifier|*
name|f
decl_stmt|;
return|return
name|f
operator|->
name|v
operator|+
name|f
index|[
literal|0
index|]
operator|.
name|v
return|;
block|}
end_function

begin_comment
comment|// PR3642, PR3671
end_comment

begin_struct
struct|struct
name|pppoe_tag
block|{
name|short
name|tag_type
decl_stmt|;
name|char
name|tag_data
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|datatag
block|{
name|struct
name|pppoe_tag
name|hdr
decl_stmt|;
comment|//expected-warning{{field 'hdr' with variable sized type 'struct pppoe_tag' not at the end of a struct or class is a GNU extension}}
name|char
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// PR4092
end_comment

begin_struct
struct|struct
name|s0
block|{
name|char
name|a
decl_stmt|;
comment|// expected-note {{previous declaration is here}}
name|char
name|a
decl_stmt|;
comment|// expected-error {{duplicate member 'a'}}
block|}
struct|;
end_struct

begin_function
name|struct
name|s0
name|f0
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

end_unit

