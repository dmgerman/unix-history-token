begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Define string ops: strchr strrchr memcmp memmove memset  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_STRING_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_STRING_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MEMORY_H
end_ifdef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BSTRING_H
end_ifdef

begin_include
include|#
directive|include
file|<bstring.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NTP_NEED_BOPS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_comment
comment|/* bcmp, bcopy, bzero */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ntp_memset
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcmp(a, b, (int)(c))
end_define

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|,
name|c
parameter_list|)
value|bcopy(f, t, (int)(c))
end_define

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|,
name|c
parameter_list|)
value|bcopy(f, t, (int)(c))
end_define

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|,
name|c
parameter_list|)
value|if (0 == (x)) \ 					bzero(a, (int)(c)); \ 				else \ 					ntp_memset((char *)(a), x, c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  NTP_NEED_BOPS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_STRING_H */
end_comment

end_unit

