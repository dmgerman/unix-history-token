begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_typedef
typedef|typedef
name|char
name|T
index|[
literal|4
index|]
typedef|;
end_typedef

begin_function
name|T
name|foo
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|m
parameter_list|)
block|{  }
end_function

begin_comment
comment|// expected-error {{cannot return array or function}}
end_comment

begin_decl_stmt
name|void
name|foof
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|__format__
argument_list|(
name|__printf__
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
decl_stmt|,
name|barf
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|int
end_macro

begin_typedef
typedef|typedef
name|validTypeDecl
argument_list|()
block|{ }
end_typedef

begin_comment
comment|// expected-error {{function definition declared 'typedef'}}
end_comment

begin_struct
struct|struct
name|_zend_module_entry
block|{ }
decl|typedef struct
name|_zend_function_entry
block|{ }
comment|// expected-error {{cannot combine with previous 'struct' declaration specifier}}
decl|static
name|void
name|buggy
argument_list|(
name|int
operator|*
name|x
argument_list|)
block|{ }
comment|// expected-error {{function definition declared 'typedef'}} \
comment|// expected-error {{cannot combine with previous 'typedef' declaration specifier}} \
comment|// expected-error {{cannot combine with previous 'struct' declaration specifier}}
comment|// Type qualifiers.
decl|typedef
name|int
name|f
argument_list|(
name|void
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|f
modifier|*
name|fptr
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|f
modifier|*
name|v1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{qualifier on function type 'f' (aka 'int (void)') has unspecified behavior}}
end_comment

begin_decl_stmt
name|__restrict__
name|f
modifier|*
name|v2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{restrict requires a pointer or reference ('f' (aka 'int (void)') is invalid)}}
end_comment

begin_decl_stmt
name|__restrict__
name|fptr
name|v3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{pointer to function type 'f' (aka 'int (void)') may not be 'restrict' qualified}}
end_comment

begin_decl_stmt
name|f
modifier|*
name|__restrict__
name|v4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{pointer to function type 'f' (aka 'int (void)') may not be 'restrict' qualified}}
end_comment

begin_struct_decl
specifier|restrict
struct_decl|struct
name|hallo
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-error {{restrict requires a pointer or reference}}
end_comment

end_unit

