begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gsc.h - programming interface to the scanner device driver `gsc'  *  *  * Copyright (c) 1995 Gunther Schadow.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Gunther Schadow.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_GSC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_GSC_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|GSC_GRES
value|_IOR('S', 1, int)
end_define

begin_comment
comment|/* get resolution / dpi */
end_comment

begin_define
define|#
directive|define
name|GSC_SRES
value|_IOW('S', 2, int)
end_define

begin_comment
comment|/* set resolution / dpi */
end_comment

begin_define
define|#
directive|define
name|GSC_GWIDTH
value|_IOR('S', 3, int)
end_define

begin_comment
comment|/* get width / pixels */
end_comment

begin_define
define|#
directive|define
name|GSC_SWIDTH
value|_IOW('S', 4, int)
end_define

begin_comment
comment|/* set width / pixels */
end_comment

begin_define
define|#
directive|define
name|GSC_GHEIGHT
value|_IOR('S', 5, int)
end_define

begin_comment
comment|/* get height / pixels */
end_comment

begin_define
define|#
directive|define
name|GSC_SHEIGHT
value|_IOW('S', 6, int)
end_define

begin_comment
comment|/* set height / pixels */
end_comment

begin_define
define|#
directive|define
name|GSC_GBLEN
value|_IOR('S', 7, int)
end_define

begin_comment
comment|/* get buffer length / lines */
end_comment

begin_define
define|#
directive|define
name|GSC_SBLEN
value|_IOW('S', 8, int)
end_define

begin_comment
comment|/* set buffer length / lines */
end_comment

begin_define
define|#
directive|define
name|GSC_GBTIME
value|_IOR('S', 9, int)
end_define

begin_comment
comment|/* get buffer timeout / s */
end_comment

begin_define
define|#
directive|define
name|GSC_SBTIME
value|_IOW('S', 10, int)
end_define

begin_comment
comment|/* set buffer timeout / s */
end_comment

begin_define
define|#
directive|define
name|GSC_SRESSW
value|_IO('S', 11)
end_define

begin_comment
comment|/* set resolution by switch */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_GSC_H_ */
end_comment

end_unit

