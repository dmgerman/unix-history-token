begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wdate-time -Wno-builtin-macro-redefined %s -verify -E
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Wdate-time -Wno-builtin-macro-redefined %s -DIS_SYSHEADER -verify -E
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -Werror=date-time -Wno-builtin-macro-redefined %s -DIS_SYSHEADER -E 2>&1 | grep 'error: expansion' | count 3
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IS_HEADER
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|IS_SYSHEADER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|__TIME__
comment|// expected-warning {{expansion of date or time macro is not reproducible}}
name|__DATE__
comment|// expected-warning {{expansion of date or time macro is not reproducible}}
name|__TIMESTAMP__
comment|// expected-warning {{expansion of date or time macro is not reproducible}}
define|#
directive|define
name|__TIME__
name|__TIME__
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_HEADER
end_define

begin_include
include|#
directive|include
include|__FILE__
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

