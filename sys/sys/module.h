begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MODULE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MODULE_H_
end_define

begin_typedef
typedef|typedef
enum|enum
name|modeventtype
block|{
name|MOD_LOAD
block|,
name|MOD_UNLOAD
block|,
name|MOD_SHUTDOWN
block|}
name|modeventtype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|module
modifier|*
name|module_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|modeventhand_t
function_decl|)
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
comment|/*modeventtype_t*/
name|what
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Struct for registering modules statically via SYSINIT.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|moduledata
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* module name */
name|modeventhand_t
name|evhand
decl_stmt|;
comment|/* event handler */
name|void
modifier|*
name|priv
decl_stmt|;
comment|/* extra data */
block|}
name|moduledata_t
typedef|;
end_typedef

begin_comment
comment|/*  * A module can use this to report module specific data to  * the user via kldstat(2).  */
end_comment

begin_typedef
typedef|typedef
union|union
name|modspecific
block|{
name|int
name|intval
decl_stmt|;
name|u_int
name|uintval
decl_stmt|;
name|long
name|longval
decl_stmt|;
name|u_long
name|ulongval
decl_stmt|;
block|}
name|modspecific_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MODULE_METADATA
parameter_list|(
name|uniquifier
parameter_list|,
name|type
parameter_list|,
name|data
parameter_list|,
name|cval
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_DEPEND
parameter_list|(
name|mod
parameter_list|,
name|dep
parameter_list|,
name|min
parameter_list|,
name|pref
parameter_list|,
name|max
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DECLARE_MODULE
parameter_list|(
name|name
parameter_list|,
name|data
parameter_list|,
name|sub
parameter_list|,
name|order
parameter_list|)
define|\
value|SYSINIT(name##module, sub, order, module_register_init,&data) \     struct __hack
end_define

begin_define
define|#
directive|define
name|MODULE_VERSION
parameter_list|(
name|mod
parameter_list|,
name|ver
parameter_list|)
end_define

begin_function_decl
name|void
name|module_register_init
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|linker_file
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|module_register
parameter_list|(
specifier|const
name|struct
name|moduledata
modifier|*
name|data
parameter_list|,
name|struct
name|linker_file
modifier|*
name|lf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|module_t
name|module_lookupbyname
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|module_t
name|module_lookupbyid
parameter_list|(
name|int
name|modid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|module_reference
parameter_list|(
name|module_t
name|mod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|module_release
parameter_list|(
name|module_t
name|mod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|module_unload
parameter_list|(
name|module_t
name|mod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|module_getid
parameter_list|(
name|module_t
name|mod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|module_t
name|module_getfnext
parameter_list|(
name|module_t
name|mod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|module_setspecific
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|modspecific_t
modifier|*
name|datap
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|MOD_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|mod_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MOD_DEBUG_REFS
value|1
end_define

begin_define
define|#
directive|define
name|MOD_DPF
parameter_list|(
name|cat
parameter_list|,
name|args
parameter_list|)
define|\
value|do {							\ 		if (mod_debug& MOD_DEBUG_##cat) printf args;	\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MOD_DPF
parameter_list|(
name|cat
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|MAXMODNAME
value|32
end_define

begin_struct
struct|struct
name|module_stat
block|{
name|int
name|version
decl_stmt|;
comment|/* set to sizeof(struct module_stat) */
name|char
name|name
index|[
name|MAXMODNAME
index|]
decl_stmt|;
name|int
name|refs
decl_stmt|;
name|int
name|id
decl_stmt|;
name|modspecific_t
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|modnext
parameter_list|(
name|int
name|_modid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|modfnext
parameter_list|(
name|int
name|_modid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|modstat
parameter_list|(
name|int
name|_modid
parameter_list|,
name|struct
name|module_stat
modifier|*
name|_stat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|modfind
parameter_list|(
specifier|const
name|char
modifier|*
name|_name
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_MODULE_H_ */
end_comment

end_unit

