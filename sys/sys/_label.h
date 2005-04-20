begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2002 Robert N. M. Watson  * Copyright (c) 2001-2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * This software was developed for the FreeBSD Project in part by Network  * Associates Laboratories, the Security Research Division of Network  * Associates, Inc. under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"),  * as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__LABEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__LABEL_H_
end_define

begin_comment
comment|/*  * XXXMAC: This shouldn't be exported to userland, but is because of ucred.h  * and various other messes.  */
end_comment

begin_define
define|#
directive|define
name|MAC_MAX_SLOTS
value|4
end_define

begin_define
define|#
directive|define
name|MAC_FLAG_INITIALIZED
value|0x0000001
end_define

begin_comment
comment|/* Is initialized for use. */
end_comment

begin_struct
struct|struct
name|label
block|{
name|int
name|l_flags
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|l_ptr
decl_stmt|;
name|long
name|l_long
decl_stmt|;
block|}
name|l_perpolicy
index|[
name|MAC_MAX_SLOTS
index|]
union|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__LABEL_H_ */
end_comment

end_unit

