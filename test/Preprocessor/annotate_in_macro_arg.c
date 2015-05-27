begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify %s
end_comment

begin_define
define|#
directive|define
name|M1
parameter_list|()
end_define

begin_comment
comment|// expected-note{{macro 'M1' defined here}}
end_comment

begin_macro
name|M1
argument_list|(
end_macro

begin_comment
comment|// expected-error{{unterminated function-like macro invocation}}
end_comment

begin_if
if|#
directive|if
name|M1
argument_list|()
end_if

begin_comment
comment|// expected-error{{expected value in expression}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

end_unit

