begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_STATUS_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_STATUS_H__
end_define

begin_enum
enum|enum
name|_ecore_status_t
block|{
name|ECORE_CONN_REFUSED
init|=
operator|-
literal|14
block|,
name|ECORE_CONN_RESET
init|=
operator|-
literal|13
block|,
name|ECORE_UNKNOWN_ERROR
init|=
operator|-
literal|12
block|,
name|ECORE_NORESOURCES
init|=
operator|-
literal|11
block|,
name|ECORE_NODEV
init|=
operator|-
literal|10
block|,
name|ECORE_ABORTED
init|=
operator|-
literal|9
block|,
name|ECORE_AGAIN
init|=
operator|-
literal|8
block|,
name|ECORE_NOTIMPL
init|=
operator|-
literal|7
block|,
name|ECORE_EXISTS
init|=
operator|-
literal|6
block|,
name|ECORE_IO
init|=
operator|-
literal|5
block|,
name|ECORE_TIMEOUT
init|=
operator|-
literal|4
block|,
name|ECORE_INVAL
init|=
operator|-
literal|3
block|,
name|ECORE_BUSY
init|=
operator|-
literal|2
block|,
name|ECORE_NOMEM
init|=
operator|-
literal|1
block|,
name|ECORE_SUCCESS
init|=
literal|0
block|,
comment|/* PENDING is not an error and should be positive */
name|ECORE_PENDING
init|=
literal|1
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_STATUS_H__ */
end_comment

end_unit

