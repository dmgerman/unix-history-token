begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Do all necessary includes here, so that we don't have to worry about  * overlapping includes in the files in missing.d.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|VAXC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__DECC
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*VMS w/ VAXC or DECC*/
end_comment

begin_include
include|#
directive|include
file|<file.h>
end_include

begin_include
include|#
directive|include
file|<types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
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
name|TZSET_MISSING
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* #include "atari/textrd.c" */
end_comment

begin_comment
comment|/* current libraries are correct bug fix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* atarist */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSTEM_MISSING
end_ifdef

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
comment|/* SYSTEM_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MEMCMP_MISSING
end_ifdef

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
comment|/* MEMCMP_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MEMCPY_MISSING
end_ifdef

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
comment|/* MEMCPY_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MEMSET_MISSING
end_ifdef

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
comment|/* MEMSET_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RANDOM_MISSING
end_ifdef

begin_include
include|#
directive|include
file|"missing/random.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RANDOM_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STRCASE_MISSING
end_ifdef

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
comment|/* STRCASE_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STRERROR_MISSING
end_ifdef

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
comment|/* STRERROR_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STRFTIME_MISSING
end_ifdef

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
comment|/* STRFTIME_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STRCHR_MISSING
end_ifdef

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
comment|/* STRCHR_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STRTOD_MISSING
end_ifdef

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
comment|/* STRTOD_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TZSET_MISSING
end_ifdef

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
comment|/* TZSET_MISSING */
end_comment

end_unit

