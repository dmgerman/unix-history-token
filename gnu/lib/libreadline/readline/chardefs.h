begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* chardefs.h -- Character definitions for readline. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CHARDEFS_
end_ifndef

begin_define
define|#
directive|define
name|_CHARDEFS_
end_define

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|savestring
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|savestring
parameter_list|(
name|x
parameter_list|)
value|strcpy (xmalloc (1 + strlen (x)), (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|whitespace
end_ifndef

begin_define
define|#
directive|define
name|whitespace
parameter_list|(
name|c
parameter_list|)
value|(((c) == ' ') || ((c) == '\t'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CTRL
end_ifdef

begin_undef
undef|#
directive|undef
name|CTRL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some character stuff. */
end_comment

begin_define
define|#
directive|define
name|control_character_threshold
value|0x020
end_define

begin_comment
comment|/* Smaller than this is control. */
end_comment

begin_define
define|#
directive|define
name|meta_character_threshold
value|0x07f
end_define

begin_comment
comment|/* Larger than this is Meta. */
end_comment

begin_define
define|#
directive|define
name|control_character_bit
value|0x40
end_define

begin_comment
comment|/* 0x000000, must be off. */
end_comment

begin_define
define|#
directive|define
name|meta_character_bit
value|0x080
end_define

begin_comment
comment|/* x0000000, must be on. */
end_comment

begin_define
define|#
directive|define
name|largest_char
value|255
end_define

begin_comment
comment|/* Largest character value. */
end_comment

begin_define
define|#
directive|define
name|META_CHAR
parameter_list|(
name|c
parameter_list|)
value|((c)> meta_character_threshold&& (c)<= largest_char)
end_define

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|c
parameter_list|)
value|((c)& (~control_character_bit))
end_define

begin_define
define|#
directive|define
name|META
parameter_list|(
name|c
parameter_list|)
value|((c) | meta_character_bit)
end_define

begin_define
define|#
directive|define
name|UNMETA
parameter_list|(
name|c
parameter_list|)
value|((c)& (~meta_character_bit))
end_define

begin_define
define|#
directive|define
name|UNCTRL
parameter_list|(
name|c
parameter_list|)
value|to_upper(((c)|control_character_bit))
end_define

begin_define
define|#
directive|define
name|lowercase_p
parameter_list|(
name|c
parameter_list|)
value|(((c)> ('a' - 1)&& (c)< ('z' + 1)))
end_define

begin_define
define|#
directive|define
name|uppercase_p
parameter_list|(
name|c
parameter_list|)
value|(((c)> ('A' - 1)&& (c)< ('Z' + 1)))
end_define

begin_define
define|#
directive|define
name|pure_alphabetic
parameter_list|(
name|c
parameter_list|)
value|(lowercase_p(c) || uppercase_p(c))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|to_upper
end_ifndef

begin_define
define|#
directive|define
name|to_upper
parameter_list|(
name|c
parameter_list|)
value|(lowercase_p(c) ? ((c) - 32) : (c))
end_define

begin_define
define|#
directive|define
name|to_lower
parameter_list|(
name|c
parameter_list|)
value|(uppercase_p(c) ? ((c) + 32) : (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CTRL_P
parameter_list|(
name|c
parameter_list|)
value|((c)< control_character_threshold)
end_define

begin_define
define|#
directive|define
name|META_P
parameter_list|(
name|c
parameter_list|)
value|((c)> meta_character_threshold)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NEWLINE
end_ifndef

begin_define
define|#
directive|define
name|NEWLINE
value|'\n'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RETURN
end_ifndef

begin_define
define|#
directive|define
name|RETURN
value|CTRL('M')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RUBOUT
end_ifndef

begin_define
define|#
directive|define
name|RUBOUT
value|0x07f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TAB
end_ifndef

begin_define
define|#
directive|define
name|TAB
value|'\t'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ABORT_CHAR
end_ifdef

begin_undef
undef|#
directive|undef
name|ABORT_CHAR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ABORT_CHAR
value|CTRL('G')
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PAGE
end_ifdef

begin_undef
undef|#
directive|undef
name|PAGE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PAGE
value|CTRL('L')
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SPACE
end_ifdef

begin_undef
undef|#
directive|undef
name|SPACE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPACE
value|0x020
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ESC
end_ifdef

begin_undef
undef|#
directive|undef
name|ESC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ESC
value|CTRL('[')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CHARDEFS_ */
end_comment

end_unit

