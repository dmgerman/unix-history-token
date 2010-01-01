begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep xxx-xxx
end_comment

begin_define
define|#
directive|define
name|foo
parameter_list|(
define|return) return-return
end_define

begin_macro
name|foo
argument_list|(
argument|xxx
argument_list|)
end_macro

end_unit

