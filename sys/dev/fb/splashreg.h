begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * $Id: $  */
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

begin_typedef
typedef|typedef
struct|struct
name|splash_decoder
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
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|size
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
block|}
name|splash_decoder_t
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
value|static int name##_modevent(module_t mod, int type, void *data) \ 	{							\ 		switch ((modeventtype_t)type) {			\ 		case MOD_LOAD:					\ 			return splash_register(&sw);		\ 		case MOD_UNLOAD:				\ 			return splash_unregister(&sw);		\ 		}						\ 		return 0;					\ 	}							\ 	static moduledata_t name##_mod = {			\ 		#name, 						\ 		name##_modevent,				\ 		NULL						\ 	};							\ 	DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS, SI_ORDER_ANY)
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
parameter_list|)
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

