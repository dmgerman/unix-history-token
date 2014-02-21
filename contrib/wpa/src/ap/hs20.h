begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Hotspot 2.0 AP ANQP processing  * Copyright (c) 2011-2012, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HS20_H
end_ifndef

begin_define
define|#
directive|define
name|HS20_H
end_define

begin_struct_decl
struct_decl|struct
name|hostapd_data
struct_decl|;
end_struct_decl

begin_function_decl
name|u8
modifier|*
name|hostapd_eid_hs20_indication
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|u8
modifier|*
name|eid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HS20_H */
end_comment

end_unit

