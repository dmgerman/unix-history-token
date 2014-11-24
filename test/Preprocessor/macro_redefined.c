begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -Eonly -verify -Wno-all -Wmacro-redefined -DCLI_MACRO=1 -DWMACRO_REDEFINED
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Eonly -verify -Wno-all -Wno-macro-redefined -DCLI_MACRO=1
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WMACRO_REDEFINED
end_ifndef

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WMACRO_REDEFINED
end_ifdef

begin_comment
comment|// expected-note@1 {{previous definition is here}}
end_comment

begin_comment
comment|// expected-warning@+2 {{macro redefined}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CLI_MACRO
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WMACRO_REDEFINED
end_ifdef

begin_comment
comment|// expected-note@+3 {{previous definition is here}}
end_comment

begin_comment
comment|// expected-warning@+3 {{macro redefined}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|REGULAR_MACRO
end_define

begin_define
define|#
directive|define
name|REGULAR_MACRO
value|1
end_define

end_unit

