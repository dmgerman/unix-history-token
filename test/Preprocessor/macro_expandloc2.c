begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E 2>&1 | grep '#include'
end_comment

begin_define
define|#
directive|define
name|FOO
value|BAR
end_define

begin_comment
comment|// The error message should be on the #include line, not the 1.
end_comment

begin_include
include|#
directive|include
include|FOO
end_include

end_unit

