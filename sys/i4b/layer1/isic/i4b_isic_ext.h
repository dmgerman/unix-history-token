begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2001 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------*  *  *	i4b_l1.h - isdn4bsd layer 1 header file  *	---------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Wed Jan 24 09:11:12 2001]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_ISIC_EXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_ISIC_EXT_H_
end_define

begin_include
include|#
directive|include
file|<i4b/include/i4b_l3l4.h>
end_include

begin_function_decl
name|int
name|isic_ph_data_req
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|freeflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isic_ph_activate_req
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isic_mph_command_req
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|command
parameter_list|,
name|void
modifier|*
name|parm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isic_set_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|,
name|drvr_link_t
modifier|*
name|dlt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isdn_link_t
modifier|*
name|isic_ret_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_ISIC_H_ */
end_comment

end_unit

