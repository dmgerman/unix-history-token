begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_WSTATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_WSTATE_H_
end_define

begin_comment
comment|/*  * Window State Register (WSTATE)  *  *   |------------|  *   |OTHER|NORMAL|  *   |-----|------|  *    5	  3 2    0  */
end_comment

begin_define
define|#
directive|define
name|WSTATE_BAD
value|0
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|WSTATE_U32
value|1
end_define

begin_comment
comment|/* 32b stack */
end_comment

begin_define
define|#
directive|define
name|WSTATE_U64
value|2
end_define

begin_comment
comment|/* 64b stack */
end_comment

begin_define
define|#
directive|define
name|WSTATE_CLEAN32
value|3
end_define

begin_comment
comment|/* cleanwin workaround, 32b stack */
end_comment

begin_define
define|#
directive|define
name|WSTATE_CLEAN64
value|4
end_define

begin_comment
comment|/* cleanwin workaround, 64b stack */
end_comment

begin_define
define|#
directive|define
name|WSTATE_K32
value|5
end_define

begin_comment
comment|/* priv 32b stack */
end_comment

begin_define
define|#
directive|define
name|WSTATE_K64
value|6
end_define

begin_comment
comment|/* priv 64b stack */
end_comment

begin_define
define|#
directive|define
name|WSTATE_KMIX
value|7
end_define

begin_comment
comment|/* priv mixed stack */
end_comment

begin_define
define|#
directive|define
name|WSTATE_CLEAN_OFFSET
value|2
end_define

begin_define
define|#
directive|define
name|WSTATE_SHIFT
value|3
end_define

begin_comment
comment|/* normal-to-other shift */
end_comment

begin_define
define|#
directive|define
name|WSTATE_MASK
value|7
end_define

begin_comment
comment|/* mask for each set */
end_comment

begin_define
define|#
directive|define
name|WSTATE
parameter_list|(
name|o
parameter_list|,
name|n
parameter_list|)
value|(((o)<< WSTATE_SHIFT) | (n))
end_define

begin_define
define|#
directive|define
name|WSTATE_USER32
value|WSTATE(WSTATE_BAD, WSTATE_U32)
end_define

begin_define
define|#
directive|define
name|WSTATE_USER64
value|WSTATE(WSTATE_BAD, WSTATE_U64)
end_define

begin_define
define|#
directive|define
name|WSTATE_KERN
value|WSTATE(WSTATE_U32, WSTATE_K64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_WSTATE_H_ */
end_comment

end_unit

