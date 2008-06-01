begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Objective C Runtime internal declarations    Copyright (C) 1993, 1995, 1996, 1997, 2002, 2004 Free Software Foundation, Inc.    Contributed by Kresten Krab Thorup  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled with    GCC to produce an executable, this does not cause the resulting executable    to be covered by the GNU General Public License. This exception does not    however invalidate any other reasons why the executable file might be    covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__objc_runtime_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__objc_runtime_INCLUDE_GNU
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|/* for varargs and va_list's */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* so noone else will get system versions */
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|"objc.h"
end_include

begin_comment
comment|/* core data types */
end_comment

begin_include
include|#
directive|include
file|"objc-api.h"
end_include

begin_comment
comment|/* runtime api functions */
end_comment

begin_include
include|#
directive|include
file|"thr.h"
end_include

begin_comment
comment|/* thread and mutex support */
end_comment

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_comment
comment|/* hash structures */
end_comment

begin_include
include|#
directive|include
file|"objc-list.h"
end_include

begin_comment
comment|/* linear lists */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
specifier|extern
name|void
name|__objc_add_class_to_hash
parameter_list|(
name|Class
parameter_list|)
function_decl|;
comment|/* (objc-class.c) */
specifier|extern
name|void
name|__objc_init_selector_tables
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* (objc-sel.c) */
specifier|extern
name|void
name|__objc_init_class_tables
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* (objc-class.c) */
specifier|extern
name|void
name|__objc_init_dispatch_tables
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* (objc-dispatch.c) */
specifier|extern
name|void
name|__objc_install_premature_dtable
parameter_list|(
name|Class
parameter_list|)
function_decl|;
comment|/* (objc-dispatch.c) */
specifier|extern
name|void
name|__objc_resolve_class_links
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* (objc-class.c) */
specifier|extern
name|void
name|__objc_register_selectors_from_class
parameter_list|(
name|Class
parameter_list|)
function_decl|;
comment|/* (objc-sel.c) */
specifier|extern
name|void
name|__objc_register_selectors_from_list
parameter_list|(
name|MethodList_t
parameter_list|)
function_decl|;
comment|/* (selector.c) */
specifier|extern
name|void
name|__objc_update_dispatch_table_for_class
parameter_list|(
name|Class
parameter_list|)
function_decl|;
comment|/* (objc-msg.c) */
specifier|extern
name|int
name|__objc_init_thread_system
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* thread.c */
specifier|extern
name|int
name|__objc_fini_thread_system
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* thread.c */
specifier|extern
name|void
name|__objc_print_dtable_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* sendmsg.c */
specifier|extern
name|void
name|class_add_method_list
parameter_list|(
name|Class
parameter_list|,
name|MethodList_t
parameter_list|)
function_decl|;
comment|/* Registering instance methods as class methods for root classes */
specifier|extern
name|void
name|__objc_register_instance_methods_to_class
parameter_list|(
name|Class
parameter_list|)
function_decl|;
specifier|extern
name|Method_t
name|search_for_method_in_list
parameter_list|(
name|MethodList_t
name|list
parameter_list|,
name|SEL
name|op
parameter_list|)
function_decl|;
comment|/* True when class links has been resolved */
specifier|extern
name|BOOL
name|__objc_class_links_resolved
decl_stmt|;
comment|/* Number of selectors stored in each of the selector  tables */
specifier|extern
name|unsigned
name|int
name|__objc_selector_max_index
decl_stmt|;
comment|/* Mutex locking __objc_selector_max_index and its arrays. */
specifier|extern
name|objc_mutex_t
name|__objc_runtime_mutex
decl_stmt|;
comment|/* Number of threads which are alive. */
specifier|extern
name|int
name|__objc_runtime_threads_alive
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
define|#
directive|define
name|DEBUG_PRINTF
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf (format, ## args)
else|#
directive|else
define|#
directive|define
name|DEBUG_PRINTF
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
endif|#
directive|endif
name|BOOL
name|__objc_responds_to
parameter_list|(
name|id
name|object
parameter_list|,
name|SEL
name|sel
parameter_list|)
function_decl|;
comment|/* for internal use only! */
name|SEL
name|__sel_register_typed_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|objc_selector
modifier|*
parameter_list|,
name|BOOL
name|is_const
parameter_list|)
function_decl|;
specifier|extern
name|void
name|__objc_generate_gc_type_description
parameter_list|(
name|Class
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __objc_runtime_INCLUDE_GNU */
end_comment

end_unit

