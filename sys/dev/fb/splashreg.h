begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Kazutaka YOKOTA<yokota@zodiac.mech.utsunomiya-u.ac.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_FB_SPLASHREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_FB_SPLASHREG_H_
end_define

begin_define
define|#
directive|define
name|SPLASH_IMAGE
value|"splash_image_data"
end_define

begin_struct_decl
struct_decl|struct
name|video_adapter
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|image_decoder
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|video_adapter
modifier|*
name|adp
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|term
function_decl|)
parameter_list|(
name|struct
name|video_adapter
modifier|*
name|adp
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|splash
function_decl|)
parameter_list|(
name|struct
name|video_adapter
modifier|*
name|adp
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
name|char
modifier|*
name|data_type
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|size_t
name|data_size
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_decoder
name|splash_decoder_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|image_decoder
name|scrn_saver_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SPLASH_DECODER
parameter_list|(
name|name
parameter_list|,
name|sw
parameter_list|)
define|\
value|static int name##_modevent(module_t mod, int type, void *data) \ 	{							\ 		switch ((modeventtype_t)type) {			\ 		case MOD_LOAD:					\ 			return splash_register(&sw);		\ 		case MOD_UNLOAD:				\ 			return splash_unregister(&sw);		\ 		default:					\ 			break;					\ 		}						\ 		return 0;					\ 	}							\ 	static moduledata_t name##_mod = {			\ 		#name, 						\ 		name##_modevent,				\ 		NULL						\ 	};							\ 	DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS, SI_ORDER_ANY)
end_define

begin_define
define|#
directive|define
name|SAVER_MODULE
parameter_list|(
name|name
parameter_list|,
name|sw
parameter_list|)
define|\
value|static int name##_modevent(module_t mod, int type, void *data) \ 	{							\ 		switch ((modeventtype_t)type) {			\ 		case MOD_LOAD:					\ 			return splash_register(&sw);		\ 		case MOD_UNLOAD:				\ 			return splash_unregister(&sw);		\ 		default:					\ 			break;					\ 		}						\ 		return 0;					\ 	}							\ 	static moduledata_t name##_mod = {			\ 		#name, 						\ 		name##_modevent,				\ 		NULL						\ 	};							\ 	DECLARE_MODULE(name, name##_mod, SI_SUB_PSEUDO, SI_ORDER_MIDDLE)
end_define

begin_comment
comment|/* entry point for the splash image decoder */
end_comment

begin_function_decl
name|int
name|splash_register
parameter_list|(
name|splash_decoder_t
modifier|*
name|decoder
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|splash_unregister
parameter_list|(
name|splash_decoder_t
modifier|*
name|decoder
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* entry points for the console driver */
end_comment

begin_function_decl
name|int
name|splash_init
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|splash_term
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|splash
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* event types for the callback function */
end_comment

begin_define
define|#
directive|define
name|SPLASH_INIT
value|0
end_define

begin_define
define|#
directive|define
name|SPLASH_TERM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_FB_SPLASHREG_H_ */
end_comment

end_unit

