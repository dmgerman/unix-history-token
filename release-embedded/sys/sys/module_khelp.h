begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Lawrence Stewart<lstewart@freebsd.org>  * Copyright (c) 2010 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Lawrence Stewart while studying at the Centre  * for Advanced Internet Architectures, Swinburne University of Technology, made  * possible in part by grants from the FreeBSD Foundation and Cisco University  * Research Program Fund at Community Foundation Silicon Valley.  *  * Portions of this software were developed at the Centre for Advanced  * Internet Architectures, Swinburne University of Technology, Melbourne,  * Australia by Lawrence Stewart under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MODULE_KHELP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MODULE_KHELP_H_
end_define

begin_comment
comment|/* XXXLAS: Needed for uma related typedefs. */
end_comment

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_comment
comment|/* Helper flags. */
end_comment

begin_define
define|#
directive|define
name|HELPER_NEEDS_OSD
value|0x0001
end_define

begin_struct
struct|struct
name|helper
block|{
name|int
function_decl|(
modifier|*
name|mod_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|mod_destroy
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
define|#
directive|define
name|HELPER_NAME_MAXLEN
value|16
name|char
name|h_name
index|[
name|HELPER_NAME_MAXLEN
index|]
decl_stmt|;
name|uma_zone_t
name|h_zone
decl_stmt|;
name|struct
name|hookinfo
modifier|*
name|h_hooks
decl_stmt|;
name|uint32_t
name|h_nhooks
decl_stmt|;
name|uint32_t
name|h_classes
decl_stmt|;
name|int32_t
name|h_id
decl_stmt|;
specifier|volatile
name|uint32_t
name|h_refcount
decl_stmt|;
name|uint16_t
name|h_flags
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|helper
argument_list|)
name|h_next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|khelp_modevent_data
block|{
name|char
name|name
index|[
name|HELPER_NAME_MAXLEN
index|]
decl_stmt|;
name|struct
name|helper
modifier|*
name|helper
decl_stmt|;
name|struct
name|hookinfo
modifier|*
name|hooks
decl_stmt|;
name|int
name|nhooks
decl_stmt|;
name|int
name|uma_zsize
decl_stmt|;
name|uma_ctor
name|umactor
decl_stmt|;
name|uma_dtor
name|umadtor
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KHELP_DECLARE_MOD_UMA
parameter_list|(
name|hname
parameter_list|,
name|hdata
parameter_list|,
name|hhooks
parameter_list|,
name|version
parameter_list|,
name|size
parameter_list|,
name|ctor
parameter_list|,
name|dtor
parameter_list|)
define|\
value|static struct khelp_modevent_data kmd_##hname = {		\ 		.name = #hname,						\ 		.helper = hdata,					\ 		.hooks = hhooks,					\ 		.nhooks = sizeof(hhooks) / sizeof(hhooks[0]),		\ 		.uma_zsize = size,					\ 		.umactor = ctor,					\ 		.umadtor = dtor						\ 	};								\ 	static moduledata_t h_##hname = {				\ 		.name = #hname,						\ 		.evhand = khelp_modevent,				\ 		.priv =&kmd_##hname					\ 	};								\ 	DECLARE_MODULE(hname, h_##hname, SI_SUB_KLD, SI_ORDER_ANY);	\ 	MODULE_VERSION(hname, version)
end_define

begin_define
define|#
directive|define
name|KHELP_DECLARE_MOD
parameter_list|(
name|hname
parameter_list|,
name|hdata
parameter_list|,
name|hhooks
parameter_list|,
name|version
parameter_list|)
define|\
value|KHELP_DECLARE_MOD_UMA(hname, hdata, hhooks, version, 0, NULL, NULL)
end_define

begin_function_decl
name|int
name|khelp_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_MODULE_KHELP_H_ */
end_comment

end_unit

