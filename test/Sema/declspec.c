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
comment|// expected-error {{cannot return array type}}
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
comment|// expected-error {{expected ';' after struct}}
name|int
name|gv1
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_zend_function_entry
block|{ }
comment|// expected-error {{expected ';' after struct}} \
comment|// expected-warning {{typedef requires a name}}
name|int
name|gv2
typedef|;
end_typedef

begin_function
specifier|static
name|void
name|buggy
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
block|{ }
end_function

begin_comment
comment|// Type qualifiers.
end_comment

begin_typedef
typedef|typedef
name|int
name|f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

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

begin_comment
comment|// PR6180
end_comment

begin_struct
struct|struct
name|test1
block|{ }
comment|// expected-error {{expected ';' after struct}}
name|void
name|test2
argument_list|()
block|{}
comment|// PR6423
decl|struct
name|test3s
block|{ }
comment|// expected-error {{expected ';' after struct}}
decl|typedef
name|int
name|test3g
struct|;
end_struct

begin_comment
comment|// PR8264
end_comment

begin_decl_stmt
specifier|const
specifier|const
name|int
name|pr8264_1
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{duplicate 'const' declaration specifier}}
end_comment

begin_decl_stmt
specifier|volatile
specifier|volatile
name|int
name|pr8264_2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{duplicate 'volatile' declaration specifier}}
end_comment

begin_decl_stmt
name|char
modifier|*
specifier|restrict
specifier|restrict
name|pr8264_3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{duplicate 'restrict' declaration specifier}}
end_comment

begin_decl_stmt
specifier|extern
specifier|extern
name|int
name|pr8264_4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{duplicate 'extern' declaration specifier}}
end_comment

begin_function
name|void
name|pr8264_5
parameter_list|()
block|{
specifier|register
specifier|register
name|int
name|x
decl_stmt|;
comment|// expected-warning {{duplicate 'register' declaration specifier}}
block|}
end_function

begin_function
specifier|inline
specifier|inline
name|void
name|pr8264_6
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning {{duplicate 'inline' declaration specifier}}
end_comment

begin_function_decl
specifier|_Noreturn
specifier|_Noreturn
name|void
name|pr8264_7
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{duplicate '_Noreturn' declaration specifier}}
end_comment

end_unit

