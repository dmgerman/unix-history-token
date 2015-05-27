begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-cygwin -E -x c %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -E -fshort-wchar -x c %s
end_comment

begin_if
if|#
directive|if
operator|(
literal|L'
name|\0'
operator|-
literal|1
operator|<
literal|0
operator|)
end_if

begin_error
error|#
directive|error
literal|"Unexpected expression evaluation result"
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

