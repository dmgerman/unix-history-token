begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Define malloc and friends.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ntp_malloc_h
end_ifndef

begin_define
define|#
directive|define
name|_ntp_malloc_h
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NTP_POSIX_SOURCE
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NTP_POSIX_SOURCE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MALLOC_H
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ntp_malloc_h */
end_comment

end_unit

