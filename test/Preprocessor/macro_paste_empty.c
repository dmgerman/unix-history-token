begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E %s | grep 'a:Y'
end_comment

begin_comment
comment|// RUN: clang-cc -E %s | grep 'b:Y'
end_comment

begin_comment
comment|// RUN: clang-cc -E %s | grep 'c:YY'
end_comment

begin_define
define|#
directive|define
name|FOO
parameter_list|(
name|X
parameter_list|)
value|X ## Y
end_define

begin_label
name|a
label|:
end_label

begin_macro
name|FOO
argument_list|()
end_macro

begin_define
define|#
directive|define
name|FOO2
parameter_list|(
name|X
parameter_list|)
value|Y ## X
end_define

begin_label
name|b
label|:
end_label

begin_macro
name|FOO2
argument_list|()
end_macro

begin_define
define|#
directive|define
name|FOO3
parameter_list|(
name|X
parameter_list|)
value|X ## Y ## X ## Y ## X ## X
end_define

begin_label
name|c
label|:
end_label

begin_macro
name|FOO3
argument_list|()
end_macro

end_unit

