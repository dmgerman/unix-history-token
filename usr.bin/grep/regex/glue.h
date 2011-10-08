begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GLUE_H
end_ifndef

begin_define
define|#
directive|define
name|GLUE_H
end_define

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_undef
undef|#
directive|undef
name|RE_DUP_MAX
end_undef

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|TRE_WCHAR
value|1
end_define

begin_define
define|#
directive|define
name|TRE_MULTIBYTE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MBSTATE_T
value|1
end_define

begin_define
define|#
directive|define
name|TRE_CHAR
parameter_list|(
name|n
parameter_list|)
value|L##n
end_define

begin_define
define|#
directive|define
name|CHF
value|"%lc"
end_define

begin_define
define|#
directive|define
name|tre_char_t
value|wchar_t
end_define

begin_define
define|#
directive|define
name|tre_mbrtowc
parameter_list|(
name|pwc
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|,
name|ps
parameter_list|)
value|(mbrtowc((pwc), (s), (n), (ps)))
end_define

begin_define
define|#
directive|define
name|tre_strlen
value|wcslen
end_define

begin_define
define|#
directive|define
name|tre_isspace
value|iswspace
end_define

begin_define
define|#
directive|define
name|tre_isalnum
value|iswalnum
end_define

begin_define
define|#
directive|define
name|REG_OK
value|0
end_define

begin_define
define|#
directive|define
name|REG_LITERAL
value|0020
end_define

begin_define
define|#
directive|define
name|REG_WORD
value|0100
end_define

begin_define
define|#
directive|define
name|REG_GNU
value|0400
end_define

begin_define
define|#
directive|define
name|TRE_MB_CUR_MAX
value|MB_CUR_MAX
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_GREP_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|DPRINT
parameter_list|(
name|msg
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINT
parameter_list|(
name|msg
parameter_list|)
value|do {printf msg; fflush(stdout);} while(
comment|/*CONSTCOND*/
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a> b) ? (b) : (a))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a> b) ? (a) : (b))
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|STR_WIDE
block|,
name|STR_BYTE
block|,
name|STR_MBS
block|,
name|STR_USER
block|}
name|tre_str_type_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CALL_WITH_OFFSET
parameter_list|(
name|fn
parameter_list|)
define|\
value|do									\     {									\       size_t slen = (size_t)(pmatch[0].rm_eo - pmatch[0].rm_so);	\       size_t offset = pmatch[0].rm_so;					\       int ret;								\ 									\       if ((long long)pmatch[0].rm_eo - pmatch[0].rm_so< 0)		\ 	return REG_NOMATCH;						\       ret = fn;								\       for (unsigned i = 0; (!(eflags& REG_NOSUB)&& (i< nmatch)); i++)\ 	{								\ 	  pmatch[i].rm_so += offset;					\ 	  pmatch[i].rm_eo += offset;					\ 	}								\       return ret;							\     } while (0
comment|/*CONSTCOND*/
value|)
end_define

begin_function_decl
name|int
name|tre_convert_pattern
parameter_list|(
specifier|const
name|char
modifier|*
name|regex
parameter_list|,
name|size_t
name|n
parameter_list|,
name|tre_char_t
modifier|*
modifier|*
name|w
parameter_list|,
name|size_t
modifier|*
name|wn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tre_free_pattern
parameter_list|(
name|tre_char_t
modifier|*
name|wregex
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

