begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== posix.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@athena.mit.edu	  *  * Description : Convert an Ultrix-4.2 system to a more or less POSIX system.  *  *  1.00 93/07/20 proven  *      -Started coding this file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTHREAD_POSIX_H_
end_ifndef

begin_define
define|#
directive|define
name|_PTHREAD_POSIX_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* Make sure we have size_t defined */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

