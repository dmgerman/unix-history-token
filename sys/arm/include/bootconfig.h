begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: bootconfig.h,v 1.1 2001/05/13 13:46:23 bjh21 Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994 Mark Brinicombe.  * Copyright (c) 1994 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Brinicombe  *	for the NetBSD Project.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BOOTCONFIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BOOTCONFIG_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|BOOTOPT_TYPE_BOOLEAN
value|0
end_define

begin_define
define|#
directive|define
name|BOOTOPT_TYPE_STRING
value|1
end_define

begin_define
define|#
directive|define
name|BOOTOPT_TYPE_INT
value|2
end_define

begin_define
define|#
directive|define
name|BOOTOPT_TYPE_BININT
value|3
end_define

begin_define
define|#
directive|define
name|BOOTOPT_TYPE_HEXINT
value|4
end_define

begin_define
define|#
directive|define
name|BOOTOPT_TYPE_MASK
value|7
end_define

begin_function_decl
name|int
name|get_bootconf_option
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|boot_args
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|boot_file
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_BOOTCONFIG_H_ */
end_comment

end_unit

