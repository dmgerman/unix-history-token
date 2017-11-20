begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007, Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CFICTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CFICTL_H_
end_define

begin_comment
comment|/*  * Allow reading of the CFI query structure.  */
end_comment

begin_struct
struct|struct
name|cfiocqry
block|{
name|unsigned
name|long
name|offset
decl_stmt|;
name|unsigned
name|long
name|count
decl_stmt|;
name|u_char
modifier|*
name|buffer
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CFIOCQRY
value|_IOWR('q', 0, struct cfiocqry)
end_define

begin_comment
comment|/* Intel StrataFlash Protection Register support */
end_comment

begin_define
define|#
directive|define
name|CFIOCGFACTORYPR
value|_IOR('q', 1, uint64_t)
end_define

begin_comment
comment|/* get factory protection reg */
end_comment

begin_define
define|#
directive|define
name|CFIOCGOEMPR
value|_IOR('q', 2, uint64_t)
end_define

begin_comment
comment|/* get oem protection reg */
end_comment

begin_define
define|#
directive|define
name|CFIOCSOEMPR
value|_IOW('q', 3, uint64_t)
end_define

begin_comment
comment|/* set oem protection reg */
end_comment

begin_define
define|#
directive|define
name|CFIOCGPLR
value|_IOR('q', 4, uint32_t)
end_define

begin_comment
comment|/* get protection lock reg */
end_comment

begin_define
define|#
directive|define
name|CFIOCSPLR
value|_IO('q', 5)
end_define

begin_comment
comment|/* set protection log reg */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_CFICTL_H_ */
end_comment

end_unit

