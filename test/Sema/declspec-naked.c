begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-unknown-windows-msvc -fsyntax-only -fdeclspec -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-unknown-windows-msvc -fsyntax-only -fdeclspec -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-windows-msvc -fsyntax-only -fdeclspec -verify %s
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_ARM
argument_list|)
end_if

begin_comment
comment|// CHECK: expected-no-diagnostics
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|__declspec
parameter_list|(
name|naked
parameter_list|)
function|f
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_M_ARM
argument_list|)
end_if

begin_comment
comment|// expected-error@-2{{'naked' attribute is not supported on 'x86_64'}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

