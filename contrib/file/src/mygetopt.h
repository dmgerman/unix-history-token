begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: getopt.h,v 1.8 2007/11/06 19:21:18 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Dieter Baron and Thomas Klausner.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GETOPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_GETOPT_H_
end_define

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/*  * Gnu like getopt_long() and BSD4.4 getsubopt()/optreset extensions  */
end_comment

begin_define
define|#
directive|define
name|no_argument
value|0
end_define

begin_define
define|#
directive|define
name|required_argument
value|1
end_define

begin_define
define|#
directive|define
name|optional_argument
value|2
end_define

begin_struct
struct|struct
name|option
block|{
comment|/* name of long option */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* 	 * one of no_argument, required_argument, and optional_argument: 	 * whether option takes an argument 	 */
name|int
name|has_arg
decl_stmt|;
comment|/* if not NULL, set *flag to val when option found */
name|int
modifier|*
name|flag
decl_stmt|;
comment|/* if flag not NULL, value to set *flag to; else return value */
name|int
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|getopt_long
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|option
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GETOPT_H_ */
end_comment

end_unit

