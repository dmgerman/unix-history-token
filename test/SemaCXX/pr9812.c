begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_define
define|#
directive|define
name|bool
value|_Bool
end_define

begin_function
name|int
name|test1
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|bool
name|signed
decl_stmt|;
comment|// expected-error {{'bool' cannot be signed or unsigned}} expected-warning {{declaration does not declare anything}}
return|return
literal|0
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|bool
end_undef

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_function
name|int
name|test2
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|bool
name|signed
decl_stmt|;
comment|// expected-error {{'type-name' cannot be signed or unsigned}} expected-warning {{declaration does not declare anything}}
name|_Bool
name|signed
decl_stmt|;
comment|// expected-error {{'_Bool' cannot be signed or unsigned}} expected-warning {{declaration does not declare anything}}
return|return
literal|0
return|;
block|}
end_function

end_unit

