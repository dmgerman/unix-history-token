begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_ihfc_ext.h - ihfc common prototypes  *	---------------------------------------  *  *      last edit-date: [Wed Jul 19 09:40:59 2000]  *  *      $Id: i4b_ihfc_ext.h,v 1.6 2000/08/20 07:14:08 hm Exp $  *  * $FreeBSD$  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I4B_IHFC_EXT_H_
end_ifndef

begin_define
define|#
directive|define
name|I4B_IHFC_EXT_H_
end_define

begin_include
include|#
directive|include
file|<i4b/include/i4b_l3l4.h>
end_include

begin_comment
comment|/* prototypes from i4b_ihfc_l1if.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|i4b_l1mux_func
name|ihfc_l1mux_func
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ihfc_B_linkinit
parameter_list|(
name|ihfc_sc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ihfc_getmbuf
parameter_list|(
name|ihfc_sc_t
modifier|*
name|sc
parameter_list|,
name|u_char
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ihfc_putmbuf
parameter_list|(
name|ihfc_sc_t
modifier|*
name|sc
parameter_list|,
name|u_char
name|chan
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* prototypes from i4b_ihfc_drv.c */
end_comment

begin_function_decl
name|void
name|ihfc_intr1
parameter_list|(
name|ihfc_sc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ihfc_intr2
parameter_list|(
name|ihfc_sc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ihfc_control
parameter_list|(
name|ihfc_sc_t
modifier|*
name|sc
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ihfc_fsm
parameter_list|(
name|ihfc_sc_t
modifier|*
name|sc
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ihfc_init
parameter_list|(
name|ihfc_sc_t
modifier|*
name|sc
parameter_list|,
name|u_char
name|chan
parameter_list|,
name|int
name|prot
parameter_list|,
name|int
name|activate
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I4B_IHFC_EXT_H_ */
end_comment

end_unit

