begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (C) 1996, 2000 N.M. Maclaren     Copyright (C) 1996, 2000 The University of Cambridge  This includes all of the kludges necessary for certain broken systems.  It is called after all other headers.  All of the modules set a flag to say which they are, but none of the current kludges critically need that information. */
end_comment

begin_comment
comment|/* stdlib.h is broken under SunOS4. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* stdio.h is also broken under SunOS4. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* netinet/in.h sometimes omits INADDR_LOOPBACK, or makes it conditional on peculiar preprocessor symbols. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INADDR_LOOPBACK
end_ifndef

begin_define
define|#
directive|define
name|INADDR_LOOPBACK
value|0x7f000001ul
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HP-UX up to version 9.x does not have adjtime, so make it fail.  This needs a flag setting in Makefile. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ADJTIME_MISSING
end_ifdef

begin_define
define|#
directive|define
name|adjtime
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* O_NONBLOCK doesn't work under Ultrix 4.3.  This needs a flag setting in Makefile. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NONBLOCK_BROKEN
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|O_NONBLOCK
end_ifdef

begin_undef
undef|#
directive|undef
name|O_NONBLOCK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|O_NONBLOCK
value|O_NDELAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some older systems use EWOULDBLOCK rather than EAGAIN, but don't assume that it is defined.  The differences are not relevant to this program. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EWOULDBLOCK
end_ifndef

begin_define
define|#
directive|define
name|EWOULDBLOCK
value|EAGAIN
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

