begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E -CC -pedantic -verify
end_comment

begin_define
define|#
directive|define
name|FOO
value|&& 1
end_define

begin_if
if|#
directive|if
name|defined
name|FOO
name|FOO
end_if

begin_endif
endif|#
directive|endif
end_endif

end_unit

