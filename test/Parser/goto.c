begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -fsyntax-only -verify %s */
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
goto|goto ;
comment|/* expected-error {{expected identifier}} */
block|}
end_function

begin_function
name|void
name|test2
parameter_list|()
block|{
name|l
label|:
comment|/* expected-note {{previous definition is here}} */
block|{
name|__label__
name|l
decl_stmt|;
name|l
label|:
goto|goto
name|l
goto|;
block|}
block|{
name|__label__
name|l
decl_stmt|;
name|__label__
name|h
decl_stmt|;
comment|/* expected-error {{use of undeclared label 'h'}} */
name|l
label|:
goto|goto
name|l
goto|;
block|}
comment|/* PR3429& rdar://8287027    */
block|{
name|l
label|:
comment|/* expected-error {{redefinition of label 'l'}} */
empty_stmt|;
block|}
block|}
end_function

end_unit

