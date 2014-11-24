begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify %s -triple i686-apple-darwin
end_comment

begin_comment
comment|// Insist upon warnings for inappropriate weak attributes.
end_comment

begin_comment
comment|// O.K.
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ext_weak_import
name|__attribute__
argument_list|(
operator|(
name|__weak_import__
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// These are inappropriate, and should generate warnings:
end_comment

begin_decl_stmt
name|int
name|decl_weak_import
name|__attribute__
argument_list|(
operator|(
name|__weak_import__
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'weak_import' attribute cannot be specified on a definition}}
end_comment

begin_decl_stmt
name|int
name|decl_initialized_weak_import
name|__attribute__
argument_list|(
operator|(
name|__weak_import__
operator|)
argument_list|)
init|=
literal|13
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'weak_import' attribute cannot be specified on a definition}}
end_comment

begin_comment
comment|// O.K.
end_comment

begin_function_decl
specifier|extern
name|int
name|ext_f
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__weak_import__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// These are inappropriate, and should generate warnings:
end_comment

begin_function_decl
name|int
name|def_f
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__weak_import__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|__weak_import__
operator|)
argument_list|)
name|decl_f
argument_list|(
name|void
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

