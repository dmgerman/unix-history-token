begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Do all necessary includes here, so that we don't have to worry about  * overlapping includes in the files in missing.d.  */
end_comment

begin_include
include|#
directive|include
file|"awk.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|atarist
end_ifdef

begin_comment
comment|/*  * this will work with gcc compiler - for other compilers you may  * have to replace path separators in this file into backslashes  */
end_comment

begin_include
include|#
directive|include
file|"atari/stack.c"
end_include

begin_include
include|#
directive|include
file|"atari/tmpnam.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* atarist */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SYSTEM
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|atarist
end_ifdef

begin_include
include|#
directive|include
file|"atari/system.c"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"missing/system.c"
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
comment|/* HAVE_SYSTEM */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MEMCMP
end_ifndef

begin_include
include|#
directive|include
file|"missing/memcmp.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MEMCMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MEMCPY
end_ifndef

begin_include
include|#
directive|include
file|"missing/memcpy.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MEMCPY */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MEMSET
end_ifndef

begin_include
include|#
directive|include
file|"missing/memset.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MEMSET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRNCASECMP
end_ifndef

begin_include
include|#
directive|include
file|"missing/strncasecmp.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRCASE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRERROR
end_ifndef

begin_include
include|#
directive|include
file|"missing/strerror.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRERROR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRFTIME
end_ifndef

begin_include
include|#
directive|include
file|"missing/strftime.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRFTIME */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRCHR
end_ifndef

begin_include
include|#
directive|include
file|"missing/strchr.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRCHR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRTOD
end_ifndef

begin_include
include|#
directive|include
file|"missing/strtod.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRTOD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TZSET
end_ifndef

begin_include
include|#
directive|include
file|"missing/tzset.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TZSET */
end_comment

end_unit

