begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * poll.h  *  * Copyright (c) 1997-8 Graham Barr<gbarr@pobox.com>. All rights reserved.  * This program is free software; you can redistribute it and/or  * modify it under the same terms as Perl itself.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POLL_H
end_ifndef

begin_define
define|#
directive|define
name|POLL_H
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|HAS_POLL
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_POLL
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|POLLWRBAND
argument_list|)
end_if

begin_include
include|#
directive|include
file|<poll.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SELECT
end_ifdef

begin_comment
comment|/* We shall emulate poll using select */
end_comment

begin_define
define|#
directive|define
name|EMULATE_POLL_WITH_SELECT
end_define

begin_typedef
typedef|typedef
struct|struct
name|pollfd
block|{
name|int
name|fd
decl_stmt|;
name|short
name|events
decl_stmt|;
name|short
name|revents
decl_stmt|;
block|}
name|pollfd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|POLLIN
value|0x0001
end_define

begin_define
define|#
directive|define
name|POLLPRI
value|0x0002
end_define

begin_define
define|#
directive|define
name|POLLOUT
value|0x0004
end_define

begin_define
define|#
directive|define
name|POLLRDNORM
value|0x0040
end_define

begin_define
define|#
directive|define
name|POLLWRNORM
value|POLLOUT
end_define

begin_define
define|#
directive|define
name|POLLRDBAND
value|0x0080
end_define

begin_define
define|#
directive|define
name|POLLWRBAND
value|0x0100
end_define

begin_define
define|#
directive|define
name|POLLNORM
value|POLLRDNORM
end_define

begin_comment
comment|/* Return ONLY events (NON testable) */
end_comment

begin_define
define|#
directive|define
name|POLLERR
value|0x0008
end_define

begin_define
define|#
directive|define
name|POLLHUP
value|0x0010
end_define

begin_define
define|#
directive|define
name|POLLNVAL
value|0x0020
end_define

begin_function_decl
name|int
name|poll
parameter_list|(
name|struct
name|pollfd
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_POLL
end_ifndef

begin_define
define|#
directive|define
name|HAS_POLL
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
comment|/* HAS_SELECT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I_POLL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POLL_H */
end_comment

end_unit

