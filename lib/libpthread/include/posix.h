begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== posix.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@athena.mit.edu	  *  * Description : Convert a system to a more or less POSIX system.  *  *  1.00 93/07/20 proven  *      -Started coding this file.  */
end_comment

begin_include
include|#
directive|include
file|<pthread/copyright.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|O_NONBLOCK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|FNDELAY
end_ifdef

begin_define
define|#
directive|define
name|O_NONBLOCK
value|FNDELAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_ACCMODE
end_ifndef

begin_define
define|#
directive|define
name|O_ACCMODE
value|(O_RDONLY|O_RDWR|O_WRONLY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|x
parameter_list|)
value|((x& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ibm032__
end_ifndef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

