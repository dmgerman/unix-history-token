begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GCC for Intel i386 running System V Release 4.  */
end_comment

begin_include
include|#
directive|include
file|"i386/xm-i386.h"
end_include

begin_include
include|#
directive|include
file|"xm-svr4.h"
end_include

begin_comment
comment|/* If not compiled with GNU C, use the portable alloca.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|USE_C_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__HIGHC__
end_ifdef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_comment
comment|/* for MetaWare High-C on NCR System 3000 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Univel, at least, has a small ARG_MAX.  Defining this is harmless    except for causing extra stat calls in the driver program.  */
end_comment

begin_define
define|#
directive|define
name|SMALL_ARG_MAX
end_define

end_unit

