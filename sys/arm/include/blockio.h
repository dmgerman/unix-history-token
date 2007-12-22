begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: blockio.h,v 1.2 2001/06/02 10:44:56 bjh21 Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Ben Harris  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * blockio.h - low level functions for bulk PIO data transfer  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BLOCKIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BLOCKIO_H_
end_define

begin_comment
comment|/*  * All these take three arguments:  * I/O address  * Memory address  * Number of bytes to copy  */
end_comment

begin_function_decl
name|void
name|read_multi_1
parameter_list|(
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_multi_1
parameter_list|(
name|u_int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|read_multi_2
value|insw16
end_define

begin_define
define|#
directive|define
name|write_multi_2
value|outsw16
end_define

begin_function_decl
name|void
name|insw
parameter_list|(
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outsw
parameter_list|(
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|insw16
parameter_list|(
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outsw16
parameter_list|(
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_BLOCKIO_H_ */
end_comment

end_unit

