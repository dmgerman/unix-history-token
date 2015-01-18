begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fms-compatibility -fexceptions -fcxx-exceptions -DMS_MODE -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fms-compatibility -fexceptions -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MS_MODE
argument_list|)
operator|&&
name|defined
argument_list|(
name|__EXCEPTIONS
argument_list|)
end_if

begin_error
error|#
directive|error
error|__EXCEPTIONS should not be defined.
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

