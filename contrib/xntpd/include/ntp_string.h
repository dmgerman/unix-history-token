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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NTP_POSIX_SOURCE
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MEMORY_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_define
define|#
directive|define
name|strchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|index(s,c)
end_define

begin_define
define|#
directive|define
name|strrchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|rindex(s,c)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_NEED_BOPS
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
comment|/* NTP_POSIX_SOURCE */
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
value|bcmp(a,b,c)
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
value|bcopy(f,t,c)
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
value|if (x == 0x00) bzero(a,c); else ntp_memset((char*)a,x,c)
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

