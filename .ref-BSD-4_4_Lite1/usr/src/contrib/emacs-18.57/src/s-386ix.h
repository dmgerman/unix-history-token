begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"s-usg5-3.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|ISC
end_ifndef

begin_define
define|#
directive|define
name|ISC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NO_SIOCTL_H
end_define

begin_define
define|#
directive|define
name|BROKEN_TIOCGETC
end_define

begin_comment
comment|/* There are some reports that the following is needed    with some version of this system. #undef LIBX11_SYSTEM #define LIBX11_SYSTEM -linet  #define HAVE_TIMEVAL #define USE_UTIME */
end_comment

end_unit

