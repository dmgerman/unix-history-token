begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -include %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Wpedantic -fsyntax-only %s -include %s -verify -DWARN_PEDANTIC
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|enable_if_ext_included
end_ifndef

begin_define
define|#
directive|define
name|enable_if_ext_included
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WARN_PEDANTIC
argument_list|)
end_if

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__attribute__
argument_list|(
argument|( enable_if(
literal|1
argument|,
literal|""
argument|) )
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WARN_PEDANTIC
argument_list|)
end_if

begin_comment
comment|// expected-warning@-2 {{'enable_if' is a clang extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|f
parameter_list|()
block|{ }
end_function

begin_macro
name|__attribute__
argument_list|(
argument|( __enable_if__(
literal|1
argument|,
literal|""
argument|) )
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WARN_PEDANTIC
argument_list|)
end_if

begin_comment
comment|// expected-warning@-2 {{'enable_if' is a clang extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|g
parameter_list|()
block|{ }
end_function

begin_macro
name|__attribute__
argument_list|(
argument|( enable_if(
literal|0
argument|,
literal|""
argument|) )
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WARN_PEDANTIC
argument_list|)
end_if

begin_comment
comment|// expected-warning@-2 {{'enable_if' is a clang extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|h
parameter_list|()
block|{ }
end_function

begin_macro
name|__attribute__
argument_list|(
argument|( __enable_if__(
literal|0
argument|,
literal|""
argument|) )
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WARN_PEDANTIC
argument_list|)
end_if

begin_comment
comment|// expected-warning@-2 {{'enable_if' is a clang extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|i
parameter_list|()
block|{ }
end_function

begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_macro
name|__attribute__
argument_list|(
argument|( enable_if(
literal|1
argument|,
literal|""
argument|) )
argument_list|)
end_macro

begin_function
name|void
name|j
parameter_list|()
block|{ }
end_function

begin_macro
name|__attribute__
argument_list|(
argument|( __enable_if__(
literal|1
argument|,
literal|""
argument|) )
argument_list|)
end_macro

begin_function
name|void
name|k
parameter_list|()
block|{ }
end_function

begin_macro
name|__attribute__
argument_list|(
argument|( enable_if(
literal|0
argument|,
literal|""
argument|) )
argument_list|)
end_macro

begin_function
name|void
name|l
parameter_list|()
block|{ }
end_function

begin_macro
name|__attribute__
argument_list|(
argument|( __enable_if__(
literal|0
argument|,
literal|""
argument|) )
argument_list|)
end_macro

begin_function
name|void
name|m
parameter_list|()
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

