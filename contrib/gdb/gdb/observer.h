begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GDB Notifications to Observers.    Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OBSERVER_H
end_ifndef

begin_define
define|#
directive|define
name|OBSERVER_H
end_define

begin_struct_decl
struct_decl|struct
name|observer
struct_decl|;
end_struct_decl

begin_comment
comment|/* normal_stop notifications.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|observer_normal_stop_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|struct
name|observer
modifier|*
name|observer_attach_normal_stop
parameter_list|(
name|observer_normal_stop_ftype
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|observer_detach_normal_stop
parameter_list|(
name|struct
name|observer
modifier|*
name|observer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|observer_notify_normal_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBSERVER_H */
end_comment

end_unit

