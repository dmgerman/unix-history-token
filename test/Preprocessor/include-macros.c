begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -Dtest=FOO -imacros %S/pr2086.h %s | grep 'HERE: test'
end_comment

begin_comment
comment|// This should not be expanded into FOO because pr2086.h undefs 'test'.
end_comment

begin_label
name|HERE
label|:
end_label

begin_macro
name|test
end_macro

end_unit

