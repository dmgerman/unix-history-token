begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9.0 -fsyntax-only -fapplication-extension %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-ios9.0 -fsyntax-only -fapplication-extension %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-tvos3.0 -fsyntax-only -fapplication-extension -DTVOS=1 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-tvos3.0 -fsyntax-only -fapplication-extension -verify %s
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|attribute_availability_app_extension
argument_list|)
end_if

begin_macro
name|__attribute__
argument_list|(
argument|(availability(macosx_app_extension,unavailable))
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|TVOS
end_ifndef

begin_macro
name|__attribute__
argument_list|(
argument|(availability(ios_app_extension,unavailable))
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|__attribute__
argument_list|(
argument|(availability(tvos_app_extension,unavailable))
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|f0
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{'f0' has been explicitly marked unavailable here}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(availability(macosx,unavailable))
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|TVOS
end_ifndef

begin_macro
name|__attribute__
argument_list|(
argument|(availability(ios,unavailable))
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|__attribute__
argument_list|(
argument|(availability(tvos,unavailable))
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|f1
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{'f1' has been explicitly marked unavailable here}}
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
name|f0
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{'f0' is unavailable: not available on}}
name|f1
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{'f1' is unavailable}}
block|}
end_function

end_unit

