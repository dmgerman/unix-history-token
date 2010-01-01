begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1< %s -E -verify -triple i686-pc-linux-gnu
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
literal|'1234'
operator|>>
literal|24
operator|)
operator|!=
literal|'1'
operator|)
end_if

begin_error
error|#
directive|error
error|Bad multichar constant calculation!
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

