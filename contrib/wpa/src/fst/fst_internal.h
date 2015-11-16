begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * FST module - auxiliary definitions  * Copyright (c) 2014, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FST_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|FST_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"utils/includes.h"
end_include

begin_include
include|#
directive|include
file|"utils/common.h"
end_include

begin_include
include|#
directive|include
file|"common/defs.h"
end_include

begin_include
include|#
directive|include
file|"common/ieee802_11_defs.h"
end_include

begin_include
include|#
directive|include
file|"fst/fst_iface.h"
end_include

begin_include
include|#
directive|include
file|"fst/fst_group.h"
end_include

begin_include
include|#
directive|include
file|"fst/fst_session.h"
end_include

begin_define
define|#
directive|define
name|fst_printf
parameter_list|(
name|level
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|wpa_printf((level), "FST: " format, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|fst_printf_group
parameter_list|(
name|group
parameter_list|,
name|level
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|wpa_printf((level), "FST: %s: " format, \ 		   fst_group_get_id(group), ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|fst_printf_iface
parameter_list|(
name|iface
parameter_list|,
name|level
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|fst_printf_group(fst_iface_get_group(iface), (level), "%s: " format, \ 			 fst_iface_get_name(iface), ##__VA_ARGS__)
end_define

begin_function_decl
name|enum
name|mb_band_id
name|fst_hw_mode_to_band
parameter_list|(
name|enum
name|hostapd_hw_mode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|fst_ctrl_handle
block|{
name|struct
name|fst_ctrl
name|ctrl
decl_stmt|;
name|struct
name|dl_list
name|global_ctrls_lentry
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|dl_list
name|fst_global_ctrls_list
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|foreach_fst_ctrl_call
parameter_list|(
name|clb
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { \ 		struct fst_ctrl_handle *__fst_ctrl_h; \ 		dl_list_for_each(__fst_ctrl_h,&fst_global_ctrls_list, \ 			struct fst_ctrl_handle, global_ctrls_lentry) \ 			if (__fst_ctrl_h->ctrl.clb) \ 				__fst_ctrl_h->ctrl.clb(__VA_ARGS__);\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FST_INTERNAL_H */
end_comment

end_unit

