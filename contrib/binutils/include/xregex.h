begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file redefines all regex external names before including    a renamed copy of glibc's regex.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XREGEX_H
end_ifndef

begin_define
define|#
directive|define
name|_XREGEX_H
value|1
end_define

begin_define
define|#
directive|define
name|regfree
value|xregfree
end_define

begin_define
define|#
directive|define
name|regexec
value|xregexec
end_define

begin_define
define|#
directive|define
name|regcomp
value|xregcomp
end_define

begin_define
define|#
directive|define
name|regerror
value|xregerror
end_define

begin_define
define|#
directive|define
name|re_set_registers
value|xre_set_registers
end_define

begin_define
define|#
directive|define
name|re_match_2
value|xre_match_2
end_define

begin_define
define|#
directive|define
name|re_match
value|xre_match
end_define

begin_define
define|#
directive|define
name|re_search
value|xre_search
end_define

begin_define
define|#
directive|define
name|re_compile_pattern
value|xre_compile_pattern
end_define

begin_define
define|#
directive|define
name|re_set_syntax
value|xre_set_syntax
end_define

begin_define
define|#
directive|define
name|re_search_2
value|xre_search_2
end_define

begin_define
define|#
directive|define
name|re_compile_fastmap
value|xre_compile_fastmap
end_define

begin_define
define|#
directive|define
name|re_syntax_options
value|xre_syntax_options
end_define

begin_define
define|#
directive|define
name|re_max_failures
value|xre_max_failures
end_define

begin_define
define|#
directive|define
name|_REGEX_RE_COMP
end_define

begin_define
define|#
directive|define
name|re_comp
value|xre_comp
end_define

begin_define
define|#
directive|define
name|re_exec
value|xre_exec
end_define

begin_include
include|#
directive|include
file|"xregex2.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* xregex.h */
end_comment

end_unit

