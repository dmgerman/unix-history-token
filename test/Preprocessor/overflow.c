begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Eonly %s -verify -triple i686-pc-linux-gnu
end_comment

begin_comment
comment|// Multiply signed overflow
end_comment

begin_if
if|#
directive|if
literal|0x7FFFFFFFFFFFFFFF
operator|*
literal|2
end_if

begin_comment
comment|// expected-warning {{overflow}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Multiply unsigned overflow
end_comment

begin_if
if|#
directive|if
literal|0xFFFFFFFFFFFFFFFF
operator|*
literal|2
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Add signed overflow
end_comment

begin_if
if|#
directive|if
literal|0x7FFFFFFFFFFFFFFF
operator|+
literal|1
end_if

begin_comment
comment|// expected-warning {{overflow}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Add unsigned overflow
end_comment

begin_if
if|#
directive|if
literal|0xFFFFFFFFFFFFFFFF
operator|+
literal|1
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Subtract signed overflow
end_comment

begin_if
if|#
directive|if
literal|0x7FFFFFFFFFFFFFFF
operator|-
operator|-
literal|1
end_if

begin_comment
comment|// expected-warning {{overflow}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Subtract unsigned overflow
end_comment

begin_if
if|#
directive|if
literal|0xFFFFFFFFFFFFFFFF
operator|-
operator|-
literal|1
end_if

begin_comment
comment|// expected-warning {{converted from negative value}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

