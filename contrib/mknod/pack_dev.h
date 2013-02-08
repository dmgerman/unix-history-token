begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pack_dev.h,v 1.7 2008/04/28 20:23:09 martin Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Charles M. Hannum.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PACK_DEV_H
end_ifndef

begin_define
define|#
directive|define
name|_PACK_DEV_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__CYGWIN__
end_ifdef

begin_typedef
typedef|typedef
name|__dev32_t
name|portdev_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|dev_t
name|portdev_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|portdev_t
name|pack_t
parameter_list|(
name|int
parameter_list|,
name|u_long
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|pack_t
modifier|*
name|pack_find
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|pack_t
name|pack_native
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|major_netbsd
parameter_list|(
name|x
parameter_list|)
value|((int32_t)((((x)& 0x000fff00)>>  8)))
end_define

begin_define
define|#
directive|define
name|minor_netbsd
parameter_list|(
name|x
parameter_list|)
value|((int32_t)((((x)& 0xfff00000)>> 12) | \ 					   (((x)& 0x000000ff)>>  0)))
end_define

begin_define
define|#
directive|define
name|makedev_netbsd
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((dev_t)((((x)<<  8)& 0x000fff00) | \ 					 (((y)<< 12)& 0xfff00000) | \ 					 (((y)<<  0)& 0x000000ff)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PACK_DEV_H */
end_comment

end_unit

