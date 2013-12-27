begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant D-Bus control interface - common definitions  * Copyright (c) 2006, Dan Williams<dcbw@redhat.com> and Red Hat, Inc.  * Copyright (c) 2009, Witold Sowa<witold.sowa@gmail.com>  * Copyright (c) 2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DBUS_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|DBUS_COMMON_H
end_define

begin_struct_decl
struct_decl|struct
name|wpas_dbus_priv
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wpa_global
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|wpas_dbus_priv
modifier|*
name|wpas_dbus_init
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_deinit
parameter_list|(
name|struct
name|wpas_dbus_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DBUS_COMMON_H */
end_comment

end_unit

