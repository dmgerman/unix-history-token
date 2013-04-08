begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -verify %s
end_comment

begin_define
define|#
directive|define
name|FOO
value|1
end_define

begin_comment
comment|// The error message should be on the #include line, not the 1.
end_comment

begin_comment
comment|// expected-error@+1 {{expected "FILENAME" or<FILENAME>}}
end_comment

begin_include
include|#
directive|include
include|FOO
end_include

begin_define
define|#
directive|define
name|BAR
value|BAZ
end_define

begin_comment
comment|// expected-error@+1 {{expected "FILENAME" or<FILENAME>}}
end_comment

begin_include
include|#
directive|include
include|BAR
end_include

end_unit

