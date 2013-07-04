begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / VLAN netlink api  * Copyright (c) 2012, Michael Braun<michael-dev@fami-braun.de>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VLAN_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|VLAN_UTIL_H
end_define

begin_function_decl
name|int
name|vlan_add
parameter_list|(
specifier|const
name|char
modifier|*
name|if_name
parameter_list|,
name|int
name|vid
parameter_list|,
specifier|const
name|char
modifier|*
name|vlan_if_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vlan_rem
parameter_list|(
specifier|const
name|char
modifier|*
name|if_name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VLAN_UTIL_H */
end_comment

end_unit

