begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -emit-module -fmodules-cache-path=%t -fmodule-name=diag_pragma %S/Inputs/module.map
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -verify -fmodules-cache-path=%t -I %S/Inputs %s
end_comment

begin_comment
comment|// FIXME: When we have a syntax for modules in C, use that.
end_comment

begin_decl_stmt
unit|@
name|import
name|diag_pragma
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|=
name|DIAG_PRAGMA_MACRO
condition|)
comment|// expected-warning {{using the result of an assignment as a condition without parentheses}} \
comment|// expected-note {{place parentheses}} expected-note {{use '=='}}
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

end_unit

