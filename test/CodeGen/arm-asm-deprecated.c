begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv8 -target-feature +neon %s -S -o /dev/null -verify -DWARN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv8 -target-feature +neon %s -S -o /dev/null -Werror -verify
end_comment

begin_function
name|void
name|set_endian
parameter_list|()
block|{
asm|asm("setend be");
comment|// expected-note@1 {{instantiated into assembly here}}
ifdef|#
directive|ifdef
name|WARN
comment|// expected-warning@-3 {{deprecated}}
else|#
directive|else
comment|// expected-error@-5 {{deprecated}}
endif|#
directive|endif
block|}
end_function

end_unit

