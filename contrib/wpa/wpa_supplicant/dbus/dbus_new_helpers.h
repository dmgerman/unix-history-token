begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / dbus-based control interface  * Copyright (c) 2006, Dan Williams<dcbw@redhat.com> and Red Hat, Inc.  * Copyright (c) 2009, Witold Sowa<witold.sowa@gmail.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPA_DBUS_CTRL_H
end_ifndef

begin_define
define|#
directive|define
name|WPA_DBUS_CTRL_H
end_define

begin_include
include|#
directive|include
file|<dbus/dbus.h>
end_include

begin_typedef
typedef|typedef
name|DBusMessage
modifier|*
function_decl|(
modifier|*
name|WPADBusMethodHandler
function_decl|)
parameter_list|(
name|DBusMessage
modifier|*
name|message
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|WPADBusArgumentFreeFunction
function_decl|)
parameter_list|(
name|void
modifier|*
name|handler_arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|DBusMessage
modifier|*
function_decl|(
modifier|*
name|WPADBusPropertyAccessor
function_decl|)
parameter_list|(
name|DBusMessage
modifier|*
name|message
parameter_list|,
specifier|const
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|wpa_dbus_object_desc
block|{
name|DBusConnection
modifier|*
name|connection
decl_stmt|;
name|char
modifier|*
name|path
decl_stmt|;
comment|/* list of methods, properties and signals registered with object */
specifier|const
name|struct
name|wpa_dbus_method_desc
modifier|*
name|methods
decl_stmt|;
specifier|const
name|struct
name|wpa_dbus_signal_desc
modifier|*
name|signals
decl_stmt|;
specifier|const
name|struct
name|wpa_dbus_property_desc
modifier|*
name|properties
decl_stmt|;
comment|/* property changed flags */
name|u8
modifier|*
name|prop_changed_flags
decl_stmt|;
comment|/* argument for method handlers and properties 	 * getter and setter functions */
name|void
modifier|*
name|user_data
decl_stmt|;
comment|/* function used to free above argument */
name|WPADBusArgumentFreeFunction
name|user_data_free_func
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|dbus_prop_access
block|{
name|R
block|,
name|W
block|,
name|RW
block|}
enum|;
end_enum

begin_enum
enum|enum
name|dbus_arg_direction
block|{
name|ARG_IN
block|,
name|ARG_OUT
block|}
enum|;
end_enum

begin_struct
struct|struct
name|wpa_dbus_argument
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|type
decl_stmt|;
name|enum
name|dbus_arg_direction
name|dir
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|END_ARGS
value|{ NULL, NULL, ARG_IN }
end_define

begin_comment
comment|/**  * struct wpa_dbus_method_desc - DBus method description  */
end_comment

begin_struct
struct|struct
name|wpa_dbus_method_desc
block|{
comment|/* method name */
specifier|const
name|char
modifier|*
name|dbus_method
decl_stmt|;
comment|/* method interface */
specifier|const
name|char
modifier|*
name|dbus_interface
decl_stmt|;
comment|/* method handling function */
name|WPADBusMethodHandler
name|method_handler
decl_stmt|;
comment|/* array of arguments */
name|struct
name|wpa_dbus_argument
name|args
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wpa_dbus_signal_desc - DBus signal description  */
end_comment

begin_struct
struct|struct
name|wpa_dbus_signal_desc
block|{
comment|/* signal name */
specifier|const
name|char
modifier|*
name|dbus_signal
decl_stmt|;
comment|/* signal interface */
specifier|const
name|char
modifier|*
name|dbus_interface
decl_stmt|;
comment|/* array of arguments */
name|struct
name|wpa_dbus_argument
name|args
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wpa_dbus_property_desc - DBus property description  */
end_comment

begin_struct
struct|struct
name|wpa_dbus_property_desc
block|{
comment|/* property name */
specifier|const
name|char
modifier|*
name|dbus_property
decl_stmt|;
comment|/* property interface */
specifier|const
name|char
modifier|*
name|dbus_interface
decl_stmt|;
comment|/* property type signature in DBus type notation */
specifier|const
name|char
modifier|*
name|type
decl_stmt|;
comment|/* property getter function */
name|WPADBusPropertyAccessor
name|getter
decl_stmt|;
comment|/* property setter function */
name|WPADBusPropertyAccessor
name|setter
decl_stmt|;
comment|/* property access permissions */
name|enum
name|dbus_prop_access
name|access
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WPAS_DBUS_OBJECT_PATH_MAX
value|150
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_INTERFACE_MAX
value|150
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_METHOD_SIGNAL_PROP_MAX
value|50
end_define

begin_define
define|#
directive|define
name|WPA_DBUS_INTROSPECTION_INTERFACE
value|"org.freedesktop.DBus.Introspectable"
end_define

begin_define
define|#
directive|define
name|WPA_DBUS_INTROSPECTION_METHOD
value|"Introspect"
end_define

begin_define
define|#
directive|define
name|WPA_DBUS_PROPERTIES_INTERFACE
value|"org.freedesktop.DBus.Properties"
end_define

begin_define
define|#
directive|define
name|WPA_DBUS_PROPERTIES_GET
value|"Get"
end_define

begin_define
define|#
directive|define
name|WPA_DBUS_PROPERTIES_SET
value|"Set"
end_define

begin_define
define|#
directive|define
name|WPA_DBUS_PROPERTIES_GETALL
value|"GetAll"
end_define

begin_function_decl
name|void
name|free_dbus_object_desc
parameter_list|(
name|struct
name|wpa_dbus_object_desc
modifier|*
name|obj_dsc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_dbus_ctrl_iface_init
parameter_list|(
name|struct
name|wpas_dbus_priv
modifier|*
name|iface
parameter_list|,
name|char
modifier|*
name|dbus_path
parameter_list|,
name|char
modifier|*
name|dbus_service
parameter_list|,
name|struct
name|wpa_dbus_object_desc
modifier|*
name|obj_desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_dbus_register_object_per_iface
parameter_list|(
name|struct
name|wpas_dbus_priv
modifier|*
name|ctrl_iface
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
name|struct
name|wpa_dbus_object_desc
modifier|*
name|obj_desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_dbus_unregister_object_per_iface
parameter_list|(
name|struct
name|wpas_dbus_priv
modifier|*
name|ctrl_iface
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_dbus_get_object_properties
parameter_list|(
name|struct
name|wpas_dbus_priv
modifier|*
name|iface
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|interface
parameter_list|,
name|DBusMessageIter
modifier|*
name|dict_iter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_dbus_flush_all_changed_properties
parameter_list|(
name|DBusConnection
modifier|*
name|con
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_dbus_flush_object_changed_properties
parameter_list|(
name|DBusConnection
modifier|*
name|con
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_dbus_mark_property_changed
parameter_list|(
name|struct
name|wpas_dbus_priv
modifier|*
name|iface
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|interface
parameter_list|,
specifier|const
name|char
modifier|*
name|property
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DBusMessage
modifier|*
name|wpa_dbus_introspect
parameter_list|(
name|DBusMessage
modifier|*
name|message
parameter_list|,
name|struct
name|wpa_dbus_object_desc
modifier|*
name|obj_dsc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPA_DBUS_CTRL_H */
end_comment

end_unit

