begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1984-2016  Mark Nudelman  *  * You may distribute under the terms of either the GNU General Public  * License or the Less License, as specified in the README file.  *  * For more information, see the README file.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_GNU_REGEX
end_if

begin_define
define|#
directive|define
name|__USE_GNU
value|1
end_define

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_define
define|#
directive|define
name|DEFINE_PATTERN
parameter_list|(
name|name
parameter_list|)
value|struct re_pattern_buffer *name
end_define

begin_define
define|#
directive|define
name|CLEAR_PATTERN
parameter_list|(
name|name
parameter_list|)
value|name = NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_POSIX_REGCOMP
end_if

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|REG_EXTENDED
end_ifdef

begin_define
define|#
directive|define
name|REGCOMP_FLAG
value|REG_EXTENDED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REGCOMP_FLAG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFINE_PATTERN
parameter_list|(
name|name
parameter_list|)
value|regex_t *name
end_define

begin_define
define|#
directive|define
name|CLEAR_PATTERN
parameter_list|(
name|name
parameter_list|)
value|name = NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_PCRE
end_if

begin_include
include|#
directive|include
file|<pcre.h>
end_include

begin_define
define|#
directive|define
name|DEFINE_PATTERN
parameter_list|(
name|name
parameter_list|)
value|pcre *name
end_define

begin_define
define|#
directive|define
name|CLEAR_PATTERN
parameter_list|(
name|name
parameter_list|)
value|name = NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_RE_COMP
end_if

begin_function_decl
name|char
modifier|*
name|re_comp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|re_exec
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DEFINE_PATTERN
parameter_list|(
name|name
parameter_list|)
value|int name
end_define

begin_define
define|#
directive|define
name|CLEAR_PATTERN
parameter_list|(
name|name
parameter_list|)
value|name = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_REGCMP
end_if

begin_function_decl
name|char
modifier|*
name|regcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|regex
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__loc1
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEFINE_PATTERN
parameter_list|(
name|name
parameter_list|)
value|char *name
end_define

begin_define
define|#
directive|define
name|CLEAR_PATTERN
parameter_list|(
name|name
parameter_list|)
value|name = NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_V8_REGCOMP
end_if

begin_include
include|#
directive|include
file|"regexp.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|reg_show_error
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEFINE_PATTERN
parameter_list|(
name|name
parameter_list|)
value|struct regexp *name
end_define

begin_define
define|#
directive|define
name|CLEAR_PATTERN
parameter_list|(
name|name
parameter_list|)
value|name = NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NO_REGEX
end_if

begin_define
define|#
directive|define
name|DEFINE_PATTERN
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CLEAR_PATTERN
parameter_list|(
name|name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

