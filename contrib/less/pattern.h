begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1984-2017  Mark Nudelman  *  * You may distribute under the terms of either the GNU General Public  * License or the Less License, as specified in the README file.  *  * For more information, see the README file.  */
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
name|PATTERN_TYPE
value|struct re_pattern_buffer *
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

begin_decl_stmt
specifier|extern
name|int
name|less_is_more
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REGCOMP_FLAG
value|(less_is_more ? 0 : REG_EXTENDED)
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
name|PATTERN_TYPE
value|regex_t *
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
name|PATTERN_TYPE
value|pcre *
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

begin_decl_stmt
name|char
modifier|*
name|re_comp
name|LESSPARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|re_exec
name|LESSPARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PATTERN_TYPE
value|int
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

begin_decl_stmt
name|char
modifier|*
name|regcmp
name|LESSPARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|regex
name|LESSPARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|PATTERN_TYPE
value|char **
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
name|PATTERN_TYPE
value|struct regexp *
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
name|PATTERN_TYPE
value|void *
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

