begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The NetBSD Foundation, Inc.  * Copyright (c) 2016 The FreeBSD Foundation, Inc.  * All rights reserved.  *  * Portions of this software were developed by Kurt Lidl  * under sponsorship from the FreeBSD Foundation.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BLACKLIST_CLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|BLACKLIST_CLIENT_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BLACKLIST_API_ENUM
end_ifndef

begin_enum
enum|enum
block|{
name|BLACKLIST_AUTH_OK
init|=
literal|0
block|,
name|BLACKLIST_AUTH_FAIL
block|,
name|BLACKLIST_ABUSIVE_BEHAVIOR
block|,
name|BLACKLIST_BAD_USER
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_BLACKLIST
end_ifdef

begin_function_decl
name|void
name|blacklist_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blacklist_notify
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BLACKLIST_INIT
parameter_list|()
value|blacklist_init()
end_define

begin_define
define|#
directive|define
name|BLACKLIST_NOTIFY
parameter_list|(
name|x
parameter_list|,
name|msg
parameter_list|)
value|blacklist_notify(x,msg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BLACKLIST_INIT
parameter_list|()
end_define

begin_define
define|#
directive|define
name|BLACKLIST_NOTIFY
parameter_list|(
name|x
parameter_list|,
name|msg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BLACKLIST_CLIENT_H */
end_comment

end_unit

