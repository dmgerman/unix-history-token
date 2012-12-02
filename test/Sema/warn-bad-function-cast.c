begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -Wno-unused-value -Wbad-function-cast -triple x86_64-unknown-unknown -verify
end_comment

begin_comment
comment|// rdar://9103192
end_comment

begin_function_decl
name|void
name|vf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
name|if2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|if3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|rf1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|rf2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|_Complex
name|double
name|cf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|e
block|{
name|E1
block|}
name|ef
argument_list|(
name|void
argument_list|)
enum|;
end_enum

begin_function_decl
name|_Bool
name|bf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pf1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
modifier|*
name|pf2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Casts to void types are always OK.  */
operator|(
name|void
operator|)
name|vf
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|if1
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|cf
argument_list|()
expr_stmt|;
operator|(
specifier|const
name|void
operator|)
name|bf
argument_list|()
expr_stmt|;
comment|/* Casts to the same type or similar types are OK.  */
operator|(
name|int
operator|)
name|if1
argument_list|()
expr_stmt|;
operator|(
name|long
operator|)
name|if2
argument_list|()
expr_stmt|;
operator|(
name|char
operator|)
name|if3
argument_list|()
expr_stmt|;
operator|(
name|float
operator|)
name|rf1
argument_list|()
expr_stmt|;
operator|(
name|long
name|double
operator|)
name|rf2
argument_list|()
expr_stmt|;
operator|(
specifier|_Complex
name|float
operator|)
name|cf
argument_list|()
expr_stmt|;
operator|(
expr|enum
name|f
block|{
name|F1
block|}
operator|)
name|ef
argument_list|()
expr_stmt|;
operator|(
name|_Bool
operator|)
name|bf
argument_list|()
expr_stmt|;
operator|(
name|void
operator|*
operator|)
name|pf1
argument_list|()
expr_stmt|;
operator|(
name|char
operator|*
operator|)
name|pf2
argument_list|()
expr_stmt|;
comment|/* All following casts issue warning */
operator|(
name|float
operator|)
name|if1
argument_list|()
expr_stmt|;
comment|/* expected-warning {{cast from function call of type 'int' to non-matching type 'float'}} */
operator|(
name|double
operator|)
name|if2
argument_list|()
expr_stmt|;
comment|/* expected-warning {{cast from function call of type 'char' to non-matching type 'double'}} */
operator|(
name|_Bool
operator|)
name|if3
argument_list|()
expr_stmt|;
comment|/* expected-warning {{cast from function call of type 'long' to non-matching type '_Bool'}} */
operator|(
name|int
operator|)
name|rf1
argument_list|()
expr_stmt|;
comment|/* expected-warning {{cast from function call of type 'float' to non-matching type 'int'}} */
operator|(
name|long
operator|)
name|rf2
argument_list|()
expr_stmt|;
comment|/* expected-warning {{cast from function call of type 'double' to non-matching type 'long'}} */
operator|(
name|double
operator|)
name|cf
argument_list|()
expr_stmt|;
comment|/* expected-warning {{cast from function call of type '_Complex double' to non-matching type 'double'}} */
operator|(
name|int
operator|)
name|ef
argument_list|()
expr_stmt|;
comment|/* expected-warning {{cast from function call of type 'enum e' to non-matching type 'int'}} */
operator|(
name|int
operator|)
name|bf
argument_list|()
expr_stmt|;
comment|/* expected-warning {{cast from function call of type '_Bool' to non-matching type 'int'}} */
operator|(
name|__SIZE_TYPE__
operator|)
name|pf1
argument_list|()
expr_stmt|;
comment|/* expected-warning {{cast from function call of type 'char *' to non-matching type 'unsigned long'}} */
operator|(
name|__PTRDIFF_TYPE__
operator|)
name|pf2
argument_list|()
expr_stmt|;
comment|/* expected-warning {{cast from function call of type 'int *' to non-matching type 'long'}} */
block|}
end_function

end_unit

