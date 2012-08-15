begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
name|char
operator|=
literal|4
expr_stmt|;
comment|// expected-error {{expected identifier}}
block|}
end_function

begin_comment
comment|// PR2400
end_comment

begin_typedef
typedef|typedef
name|xtype
function_decl|(
modifier|*
name|x
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// expected-error {{function cannot return function type}} expected-warning {{type specifier missing, defaults to 'int'}} expected-warning {{type specifier missing, defaults to 'int'}}
end_comment

begin_typedef
typedef|typedef
name|void
name|ytype
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_zend_module_entry
name|zend_module_entry
typedef|;
end_typedef

begin_struct
struct|struct
name|_zend_module_entry
block|{
name|ytype
name|globals_size
decl_stmt|;
comment|// expected-error {{field 'globals_size' declared as a function}}
block|}
struct|;
end_struct

begin_decl_stmt
name|zend_module_entry
name|openssl_module_entry
init|=
block|{
expr|sizeof
operator|(
name|zend_module_entry
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//<rdar://problem/11067144>
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|FunctionType
function_decl|)
parameter_list|(
name|int
modifier|*
name|value
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UndefinedType
name|undef
decl_stmt|;
comment|// expected-error {{unknown type name 'UndefinedType'}}
name|FunctionType
name|fun
decl_stmt|;
comment|// expected-error {{field 'fun' declared as a function}}
block|}
name|StructType
typedef|;
end_typedef

begin_function
name|void
name|f
parameter_list|(
name|StructType
modifier|*
name|buf
parameter_list|)
block|{
name|buf
operator|->
name|fun
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

