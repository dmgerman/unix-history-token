begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ppsapi_timepps.h */
end_comment

begin_comment
comment|/*  * This logic first tries to get the timepps.h file from a standard  * location, and then from our include/ subdirectory.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIMEPPS_H
end_ifdef

begin_include
include|#
directive|include
file|<timepps.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIMEPPS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/timepps.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CIOGETEV
end_ifdef

begin_include
include|#
directive|include
file|"timepps-SunOS.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIOCGPPSEV
end_ifdef

begin_include
include|#
directive|include
file|"timepps-Solaris.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCDCDTIMESTAMP
end_ifdef

begin_include
include|#
directive|include
file|"timepps-SCO.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

