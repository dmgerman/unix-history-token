begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | grep 'pre: 1 1 X'
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E | grep 'nopre: 1A(X)'
end_comment

begin_comment
comment|/* Preexpansion of argument. */
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|X
parameter_list|)
value|1 X
end_define

begin_label
name|pre
label|:
end_label

begin_macro
name|A
argument_list|(
argument|A(X)
argument_list|)
end_macro

begin_comment
comment|/* The ## operator disables preexpansion. */
end_comment

begin_undef
undef|#
directive|undef
name|A
end_undef

begin_define
define|#
directive|define
name|A
parameter_list|(
name|X
parameter_list|)
value|1 ## X
end_define

begin_label
name|nopre
label|:
end_label

begin_macro
name|A
argument_list|(
argument|A(X)
argument_list|)
end_macro

end_unit

