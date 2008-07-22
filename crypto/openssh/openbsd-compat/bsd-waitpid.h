begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: bsd-waitpid.h,v 1.5 2003/08/29 16:59:52 mouring Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Ben Lindstrom.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_WAITPID_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_WAITPID_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_WAITPID
end_ifndef

begin_comment
comment|/* Clean out any potental issues */
end_comment

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WIFSTOPPED
end_undef

begin_undef
undef|#
directive|undef
name|WIFSIGNALED
end_undef

begin_comment
comment|/* Define required functions to mimic a POSIX look and feel */
end_comment

begin_define
define|#
directive|define
name|_W_INT
parameter_list|(
name|w
parameter_list|)
value|(*(int*)&(w))
end_define

begin_comment
comment|/* convert union wait to int */
end_comment

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|w
parameter_list|)
value|(!((_W_INT(w))& 0377))
end_define

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|w
parameter_list|)
value|((_W_INT(w))& 0100)
end_define

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|w
parameter_list|)
value|(!WIFEXITED(w)&& !WIFSTOPPED(w))
end_define

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|w
parameter_list|)
value|(int)(WIFEXITED(w) ? ((_W_INT(w)>> 8)& 0377) : -1)
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|w
parameter_list|)
value|(int)(WIFSIGNALED(w) ? (_W_INT(w)& 0177) : -1)
end_define

begin_define
define|#
directive|define
name|WCOREFLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|w
parameter_list|)
value|((_W_INT(w))& WCOREFLAG)
end_define

begin_comment
comment|/* Prototype */
end_comment

begin_function_decl
name|pid_t
name|waitpid
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_WAITPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_WAITPID_H */
end_comment

end_unit

