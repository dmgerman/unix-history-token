begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* chardefs.h -- Character definitions for readline. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CHARDEFS_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|savestring
end_ifndef

begin_define
define|#
directive|define
name|savestring
parameter_list|(
name|x
parameter_list|)
value|(char *)strcpy (xmalloc (1 + strlen (x)), (x))
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
comment|/* smaller than this is control */
end_comment

begin_define
define|#
directive|define
name|meta_character_threshold
value|0x07f
end_define

begin_comment
comment|/* larger than this is Meta. */
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

begin_define
define|#
directive|define
name|NEWLINE
value|'\n'
end_define

begin_define
define|#
directive|define
name|RETURN
value|CTRL('M')
end_define

begin_define
define|#
directive|define
name|RUBOUT
value|0x07f
end_define

begin_define
define|#
directive|define
name|TAB
value|'\t'
end_define

begin_define
define|#
directive|define
name|ABORT_CHAR
value|CTRL('G')
end_define

begin_define
define|#
directive|define
name|PAGE
value|CTRL('L')
end_define

begin_define
define|#
directive|define
name|SPACE
value|0x020
end_define

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

