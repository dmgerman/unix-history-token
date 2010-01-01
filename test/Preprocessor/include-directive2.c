begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Eonly -verify %s
end_comment

begin_define
define|#
directive|define
name|HEADER
value|<float.h>
end_define

begin_include
include|#
directive|include
include|HEADER
end_include

begin_include
include|#
directive|include
file|<limits.h>
include|NON_EMPTY
end_include

begin_comment
comment|// expected-warning {{extra tokens at end of #include directive}}
end_comment

begin_comment
comment|// PR3916: these are ok.
end_comment

begin_define
define|#
directive|define
name|EMPTY
end_define

begin_include
include|#
directive|include
file|<limits.h>
include|EMPTY
end_include

begin_include
include|#
directive|include
include|HEADER  EMPTY
end_include

begin_comment
comment|// PR3916
end_comment

begin_define
define|#
directive|define
name|FN
value|limits.h>
end_define

begin_include
include|#
directive|include
file|<FN
end_include

begin_include
include|#
directive|include
file|<>
end_include

begin_comment
comment|// expected-error {{empty filename}}
end_comment

end_unit

