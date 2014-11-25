begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Devin Teske<dteske@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DPV_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_DPV_UTIL_H_
end_define

begin_comment
comment|/* Limits */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE_MAX
value|(2 * 1024 * 1024)
end_define

begin_comment
comment|/* Buffer size for read(2) input */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPHYS
end_ifndef

begin_define
define|#
directive|define
name|MAXPHYS
value|(128 * 1024)
end_define

begin_comment
comment|/* max raw I/O transfer size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Memory strategry threshold, in pages: if physmem is larger than this,  * use a large buffer.  */
end_comment

begin_define
define|#
directive|define
name|PHYSPAGES_THRESHOLD
value|(32 * 1024)
end_define

begin_comment
comment|/*  * Small (default) buffer size in bytes. It's inefficient for this to be  * smaller than MAXPHYS.  */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE_SMALL
value|(MAXPHYS)
end_define

begin_comment
comment|/*  * Math macros  */
end_comment

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)< (y) ? (x) : (y))
end_define

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)> (y) ? (x) : (y))
end_define

begin_comment
comment|/*  * Extra display information  */
end_comment

begin_define
define|#
directive|define
name|BYTE_STATUS_SOLO
value|"%'10lli bytes read @ %'9.1f bytes/sec."
end_define

begin_define
define|#
directive|define
name|BYTE_STATUS_MANY
value|(BYTE_STATUS_SOLO " [%i/%i busy/wait]")
end_define

begin_define
define|#
directive|define
name|LINE_STATUS_SOLO
value|"%'10lli lines read @ %'9.1f lines/sec."
end_define

begin_define
define|#
directive|define
name|LINE_STATUS_MANY
value|(LINE_STATUS_SOLO " [%i/%i busy/wait]")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DPV_UTIL_H_ */
end_comment

end_unit

