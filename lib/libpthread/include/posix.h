begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== posix.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@athena.mit.edu	  *  * Description : Convert a system to a more or less POSIX system.  *  *  1.00 93/07/20 proven  *      -Started coding this file.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1993 by Chris Provenzano and contributors, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano,  *	the University of California, Berkeley, and contributors.  * 4. Neither the name of Chris Provenzano, the University, nor the names of  *	  contributors may be used to endorse or promote products derived  *	  from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO, THE REGENTS OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

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

