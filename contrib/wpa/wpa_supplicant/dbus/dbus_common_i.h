begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant D-Bus control interface - internal definitions  * Copyright (c) 2006, Dan Williams<dcbw@redhat.com> and Red Hat, Inc.  * Copyright (c) 2009, Witold Sowa<witold.sowa@gmail.com>  * Copyright (c) 2009, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DBUS_COMMON_I_H
end_ifndef

begin_define
define|#
directive|define
name|DBUS_COMMON_I_H
end_define

begin_include
include|#
directive|include
file|<dbus/dbus.h>
end_include

begin_struct
struct|struct
name|wpas_dbus_priv
block|{
name|DBusConnection
modifier|*
name|con
decl_stmt|;
name|int
name|should_dispatch
decl_stmt|;
name|struct
name|wpa_global
modifier|*
name|global
decl_stmt|;
name|u32
name|next_objid
decl_stmt|;
name|int
name|dbus_new_initialized
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DBUS_COMMON_I_H */
end_comment

end_unit

