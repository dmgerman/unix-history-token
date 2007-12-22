begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * vkbd_var.h  *  * Copyright (c) 2004 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: vkbd_var.h,v 1.4 2004/08/17 17:43:14 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VKBD_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_VKBD_VAR_H_
end_define

begin_define
define|#
directive|define
name|VKBD_Q_SIZE
value|64
end_define

begin_comment
comment|/* vkbd input queue size */
end_comment

begin_struct
struct|struct
name|vkbd_status
block|{
name|int
name|mode
decl_stmt|;
comment|/* keyboard mode */
name|int
name|leds
decl_stmt|;
comment|/* keyboard LEDs */
name|int
name|lock
decl_stmt|;
comment|/* keyboard lock key state */
name|int
name|delay
decl_stmt|;
comment|/* keyboard delay */
name|int
name|rate
decl_stmt|;
comment|/* keyboard rate */
name|int
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vkbd_status
name|vkbd_status_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|vkbd_status
modifier|*
name|vkbd_status_p
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _VKBD_VAR_H_ */
end_comment

end_unit

