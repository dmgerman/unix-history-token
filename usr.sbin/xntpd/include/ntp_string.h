begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Define bcopy, bzero, and bcmp and string op's  */
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
name|NTP_POSIX_SOURCE
end_ifdef

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

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|memcpy(s2, s1, n)
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset(s, 0, n)
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|memcmp(s1, s2, n)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NTP_POSIX_SOURCE */
end_comment

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  NTP_POSIX_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ntp_string_h */
end_comment

end_unit

