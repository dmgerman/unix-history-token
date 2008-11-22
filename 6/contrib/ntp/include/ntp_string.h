begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Define string ops: strchr strrchr memcmp memmove memset   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ntp_string_h
end_ifndef

begin_define
define|#
directive|define
name|_ntp_string_h
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|STDC_HEADERS
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRCHR
end_ifndef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|strchr
argument_list|()
decl_stmt|,
modifier|*
name|strrchr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MEMCPY
end_ifndef

begin_define
define|#
directive|define
name|NTP_NEED_BOPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STDC_HEADERS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NTP_NEED_BOPS
end_ifdef

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
value|bcmp(a,b,(int)c)
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
value|bcopy(f,t,(int)c)
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
value|bcopy(f,t,(int)c)
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
value|if (x == 0x00) bzero(a,(int)c); else ntp_memset((char*)a,x,c)
end_define

begin_decl_stmt
name|void
name|ntp_memset
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* _ntp_string_h */
end_comment

end_unit

