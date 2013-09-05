begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Backtrace debugging  * Copyright (c) 2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRACE_H
end_ifndef

begin_define
define|#
directive|define
name|TRACE_H
end_define

begin_define
define|#
directive|define
name|WPA_TRACE_LEN
value|16
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WPA_TRACE
end_ifdef

begin_include
include|#
directive|include
file|<execinfo.h>
end_include

begin_include
include|#
directive|include
file|"list.h"
end_include

begin_define
define|#
directive|define
name|WPA_TRACE_INFO
value|void *btrace[WPA_TRACE_LEN]; int btrace_num;
end_define

begin_struct
struct|struct
name|wpa_trace_ref
block|{
name|struct
name|dl_list
name|list
decl_stmt|;
specifier|const
name|void
modifier|*
name|addr
decl_stmt|;
name|WPA_TRACE_INFO
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WPA_TRACE_REF
parameter_list|(
name|name
parameter_list|)
value|struct wpa_trace_ref wpa_trace_ref_##name
end_define

begin_define
define|#
directive|define
name|wpa_trace_dump
parameter_list|(
name|title
parameter_list|,
name|ptr
parameter_list|)
define|\
value|wpa_trace_dump_func((title), (ptr)->btrace, (ptr)->btrace_num)
end_define

begin_function_decl
name|void
name|wpa_trace_dump_func
parameter_list|(
specifier|const
name|char
modifier|*
name|title
parameter_list|,
name|void
modifier|*
modifier|*
name|btrace
parameter_list|,
name|int
name|btrace_num
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|wpa_trace_record
parameter_list|(
name|ptr
parameter_list|)
define|\
value|(ptr)->btrace_num = backtrace((ptr)->btrace, WPA_TRACE_LEN)
end_define

begin_function_decl
name|void
name|wpa_trace_show
parameter_list|(
specifier|const
name|char
modifier|*
name|title
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|wpa_trace_add_ref
parameter_list|(
name|ptr
parameter_list|,
name|name
parameter_list|,
name|addr
parameter_list|)
define|\
value|wpa_trace_add_ref_func(&(ptr)->wpa_trace_ref_##name, (addr))
end_define

begin_function_decl
name|void
name|wpa_trace_add_ref_func
parameter_list|(
name|struct
name|wpa_trace_ref
modifier|*
name|ref
parameter_list|,
specifier|const
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|wpa_trace_remove_ref
parameter_list|(
name|ptr
parameter_list|,
name|name
parameter_list|,
name|addr
parameter_list|)
define|\
value|do { \ 		if ((addr)) \ 			dl_list_del(&(ptr)->wpa_trace_ref_##name.list); \ 	} while (0)
end_define

begin_function_decl
name|void
name|wpa_trace_check_ref
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* WPA_TRACE */
end_comment

begin_define
define|#
directive|define
name|WPA_TRACE_INFO
end_define

begin_define
define|#
directive|define
name|WPA_TRACE_REF
parameter_list|(
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|wpa_trace_dump
parameter_list|(
name|title
parameter_list|,
name|ptr
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_trace_record
parameter_list|(
name|ptr
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_trace_show
parameter_list|(
name|title
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_trace_add_ref
parameter_list|(
name|ptr
parameter_list|,
name|name
parameter_list|,
name|addr
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_trace_remove_ref
parameter_list|(
name|ptr
parameter_list|,
name|name
parameter_list|,
name|addr
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|wpa_trace_check_ref
parameter_list|(
name|addr
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPA_TRACE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WPA_TRACE_BFD
end_ifdef

begin_function_decl
name|void
name|wpa_trace_dump_funcname
parameter_list|(
specifier|const
name|char
modifier|*
name|title
parameter_list|,
name|void
modifier|*
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* WPA_TRACE_BFD */
end_comment

begin_define
define|#
directive|define
name|wpa_trace_dump_funcname
parameter_list|(
name|title
parameter_list|,
name|pc
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPA_TRACE_BFD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRACE_H */
end_comment

end_unit

