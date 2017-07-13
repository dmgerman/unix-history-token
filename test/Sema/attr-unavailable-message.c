begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// rdar: //6734520
end_comment

begin_function_decl
name|void
name|tooManyArgs
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(unavailable
parameter_list|(
function_decl|"a"
operator|,
function_decl|"b"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'unavailable' attribute takes no more than 1 argument}}
end_comment

begin_function_decl
name|int
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__unavailable__
parameter_list|(
function_decl|"USE IFOO INSTEAD"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'foo' has been explicitly marked unavailable here}}
end_comment

begin_function_decl
name|double
name|dfoo
parameter_list|(
name|double
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__unavailable__
parameter_list|(
function_decl|"NO LONGER"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note 2 {{'dfoo' has been explicitly marked unavailable here}}
end_comment

begin_function_decl
name|void
name|bar
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(__unavailable__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{explicitly marked unavailable}}
end_comment

begin_function_decl
name|int
name|quux
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__unavailable__
parameter_list|(
function_decl|12
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'__unavailable__' attribute requires a string}}
end_comment

begin_define
define|#
directive|define
name|ACCEPTABLE
value|"Use something else"
end_define

begin_function_decl
name|int
name|quux2
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__unavailable__
parameter_list|(
name|ACCEPTABLE
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test_foo
parameter_list|()
block|{
name|int
name|ir
init|=
name|foo
argument_list|(
literal|1
argument_list|)
decl_stmt|;
comment|// expected-error {{'foo' is unavailable: USE IFOO INSTEAD}}
name|double
name|dr
init|=
name|dfoo
argument_list|(
literal|1.0
argument_list|)
decl_stmt|;
comment|// expected-error {{'dfoo' is unavailable: NO LONGER}}
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|()
init|=
operator|&
name|bar
function_decl|;
comment|// expected-error {{'bar' is unavailable}}
name|double
function_decl|(
modifier|*
name|fp4
function_decl|)
parameter_list|(
name|double
parameter_list|)
init|=
name|dfoo
function_decl|;
comment|// expected-error {{'dfoo' is unavailable: NO LONGER}}
block|}
end_function

begin_decl_stmt
name|char
name|test2
index|[
name|__has_feature
argument_list|(
name|attribute_unavailable_with_message
argument_list|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// rdar://9623855
end_comment

begin_function_decl
name|void
name|unavail
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__unavailable__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|unavail
parameter_list|(
name|void
parameter_list|)
block|{
comment|// No complains inside an unavailable function.
name|int
name|ir
init|=
name|foo
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|double
name|dr
init|=
name|dfoo
argument_list|(
literal|1.0
argument_list|)
decl_stmt|;
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|()
init|=
operator|&
name|bar
function_decl|;
name|double
function_decl|(
modifier|*
name|fp4
function_decl|)
parameter_list|(
name|double
parameter_list|)
init|=
name|dfoo
function_decl|;
block|}
end_function

begin_comment
comment|// rdar://10201690
end_comment

begin_enum
enum|enum
name|foo
block|{
name|a
init|=
literal|1
block|,
name|b
name|__attribute__
argument_list|(
operator|(
name|deprecated
argument_list|()
operator|)
argument_list|)
init|=
literal|2
block|,
comment|// expected-note {{'b' has been explicitly marked deprecated here}}
name|c
init|=
literal|3
block|}
name|__attribute__
argument_list|(
operator|(
name|deprecated
argument_list|()
operator|)
argument_list|)
enum|;
end_enum

begin_comment
comment|// expected-note {{'foo' has been explicitly marked deprecated here}}
end_comment

begin_enum
enum|enum
name|fee
block|{
comment|// expected-note 2 {{'fee' has been explicitly marked unavailable here}}
name|r
init|=
literal|1
block|,
name|s
init|=
literal|2
block|,
name|t
init|=
literal|3
block|}
name|__attribute__
argument_list|(
operator|(
name|unavailable
argument_list|()
operator|)
argument_list|)
enum|;
end_enum

begin_function
name|enum
name|fee
name|f
parameter_list|()
block|{
comment|// expected-error {{'fee' is unavailable}}
name|int
name|i
init|=
name|a
decl_stmt|;
comment|// expected-warning {{'a' is deprecated}}
name|i
operator|=
name|b
expr_stmt|;
comment|// expected-warning {{'b' is deprecated}}
return|return
name|r
return|;
comment|// expected-error {{'r' is unavailable}}
block|}
end_function

end_unit

