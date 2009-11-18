begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E %s | grep '^a: x$'
end_comment

begin_comment
comment|// RUN: clang-cc -E %s | grep '^b: x y, z,h$'
end_comment

begin_comment
comment|// RUN: clang-cc -E %s | grep '^c: foo(x)$'
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|b
parameter_list|,
name|c
modifier|...
parameter_list|)
value|b c
end_define

begin_label
name|a
label|:
end_label

begin_macro
name|A
argument_list|(
argument|x
argument_list|)
end_macro

begin_label
name|b
label|:
end_label

begin_macro
name|A
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|,
argument|z
argument_list|,
argument|h
argument_list|)
end_macro

begin_define
define|#
directive|define
name|B
parameter_list|(
name|b
parameter_list|,
name|c
modifier|...
parameter_list|)
value|foo(b, ## c)
end_define

begin_label
name|c
label|:
end_label

begin_macro
name|B
argument_list|(
argument|x
argument_list|)
end_macro

end_unit

