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

begin_comment
comment|/*  * Module metadata types  */
end_comment

begin_define
define|#
directive|define
name|MDT_DEPEND
value|1
end_define

begin_comment
comment|/* argument is a module name */
end_comment

begin_define
define|#
directive|define
name|MDT_MODULE
value|2
end_define

begin_comment
comment|/* module declaration */
end_comment

begin_define
define|#
directive|define
name|MDT_VERSION
value|3
end_define

begin_comment
comment|/* module version(s) */
end_comment

begin_define
define|#
directive|define
name|MDT_PNP_INFO
value|4
end_define

begin_comment
comment|/* Plug and play hints record */
end_comment

begin_define
define|#
directive|define
name|MDT_STRUCT_VERSION
value|1
end_define

begin_comment
comment|/* version of metadata structure */
end_comment

begin_define
define|#
directive|define
name|MDT_SETNAME
value|"modmetadata_set"
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
block|,
name|MOD_QUIESCE
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
parameter_list|,
name|int
comment|/* modeventtype_t */
parameter_list|,
name|void
modifier|*
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
specifier|const
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
comment|/*  * A module can use this to report module specific data to the user via  * kldstat(2).  */
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

begin_comment
comment|/*  * Module dependency declaration  */
end_comment

begin_struct
struct|struct
name|mod_depend
block|{
name|int
name|md_ver_minimum
decl_stmt|;
name|int
name|md_ver_preferred
decl_stmt|;
name|int
name|md_ver_maximum
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Module version declaration  */
end_comment

begin_struct
struct|struct
name|mod_version
block|{
name|int
name|mv_version
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mod_metadata
block|{
name|int
name|md_version
decl_stmt|;
comment|/* structure version MDTV_* */
name|int
name|md_type
decl_stmt|;
comment|/* type of entry MDT_* */
specifier|const
name|void
modifier|*
name|md_data
decl_stmt|;
comment|/* specific data */
specifier|const
name|char
modifier|*
name|md_cval
decl_stmt|;
comment|/* common string label */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mod_pnp_match_info
block|{
specifier|const
name|char
modifier|*
name|descr
decl_stmt|;
comment|/* Description of the table */
specifier|const
name|char
modifier|*
name|bus
decl_stmt|;
comment|/* Name of the bus for this table */
specifier|const
name|void
modifier|*
name|table
decl_stmt|;
comment|/* Pointer to pnp table */
name|int
name|entry_len
decl_stmt|;
comment|/* Length of each entry in the table (may be */
comment|/*   longer than descr describes). */
name|int
name|num_entry
decl_stmt|;
comment|/* Number of entries in the table */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_define
define|#
directive|define
name|MODULE_METADATA_CONCAT
parameter_list|(
name|uniquifier
parameter_list|)
value|_mod_metadata##uniquifier
end_define

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
define|\
value|static struct mod_metadata MODULE_METADATA_CONCAT(uniquifier) = {	\ 		MDT_STRUCT_VERSION,					\ 		type,							\ 		data,							\ 		cval							\ 	};								\ 	DATA_SET(modmetadata_set, MODULE_METADATA_CONCAT(uniquifier))
end_define

begin_define
define|#
directive|define
name|MODULE_DEPEND
parameter_list|(
name|module
parameter_list|,
name|mdepend
parameter_list|,
name|vmin
parameter_list|,
name|vpref
parameter_list|,
name|vmax
parameter_list|)
define|\
value|static struct mod_depend _##module##_depend_on_##mdepend	\ 	    __section(".data") = {					\ 		vmin,							\ 		vpref,							\ 		vmax							\ 	};								\ 	MODULE_METADATA(_md_##module##_on_##mdepend, MDT_DEPEND,	\&_##module##_depend_on_##mdepend, #mdepend)
end_define

begin_comment
comment|/*  * Every kernel has a 'kernel' module with the version set to  * __FreeBSD_version.  We embed a MODULE_DEPEND() inside every module  * that depends on the 'kernel' module.  It uses the current value of  * __FreeBSD_version as the minimum and preferred versions.  For the  * maximum version it rounds the version up to the end of its branch  * (i.e. M99999 for M.x).  This allows a module built on M.x to work  * on M.y systems where y>= x, but fail on M.z systems where z< x.  */
end_comment

begin_define
define|#
directive|define
name|MODULE_KERNEL_MAXVER
value|(roundup(__FreeBSD_version, 100000) - 1)
end_define

begin_define
define|#
directive|define
name|DECLARE_MODULE_WITH_MAXVER
parameter_list|(
name|name
parameter_list|,
name|data
parameter_list|,
name|sub
parameter_list|,
name|order
parameter_list|,
name|maxver
parameter_list|)
define|\
value|MODULE_DEPEND(name, kernel, __FreeBSD_version,			\ 	    __FreeBSD_version, maxver);			\ 	MODULE_METADATA(_md_##name, MDT_MODULE,&data, __XSTRING(name));\ 	SYSINIT(name##module, sub, order, module_register_init,&data);	\ 	struct __hack
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
value|DECLARE_MODULE_WITH_MAXVER(name, data, sub, order, MODULE_KERNEL_MAXVER)
end_define

begin_comment
comment|/*  * The module declared with DECLARE_MODULE_TIED can only be loaded  * into the kernel with exactly the same __FreeBSD_version.  *  * Use it for modules that use kernel interfaces that are not stable  * even on STABLE/X branches.  */
end_comment

begin_define
define|#
directive|define
name|DECLARE_MODULE_TIED
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
value|DECLARE_MODULE_WITH_MAXVER(name, data, sub, order, __FreeBSD_version)
end_define

begin_define
define|#
directive|define
name|MODULE_VERSION_CONCAT
parameter_list|(
name|module
parameter_list|,
name|version
parameter_list|)
value|_##module##_version
end_define

begin_define
define|#
directive|define
name|MODULE_VERSION
parameter_list|(
name|module
parameter_list|,
name|version
parameter_list|)
define|\
value|static struct mod_version MODULE_VERSION_CONCAT(module, version)\ 	    __section(".data") = {					\ 		version							\ 	};								\ 	MODULE_METADATA(MODULE_VERSION_CONCAT(module, version), MDT_VERSION,\&MODULE_VERSION_CONCAT(module, version), __XSTRING(module))
end_define

begin_comment
comment|/**  * Generic macros to create pnp info hints that modules may export  * to allow external tools to parse their internal device tables  * to make an informed guess about what driver(s) to load.  */
end_comment

begin_define
define|#
directive|define
name|MODULE_PNP_INFO
parameter_list|(
name|d
parameter_list|,
name|b
parameter_list|,
name|unique
parameter_list|,
name|t
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|)
define|\
value|static const struct mod_pnp_match_info _module_pnp_##b##_##unique = {	\ 		.descr = d,						\ 		.bus = #b,						\ 		.table = t,						\ 		.entry_len = l,						\ 		.num_entry = n						\ 	};								\ 	MODULE_METADATA(_md_##b##_pnpinfo_##unique, MDT_PNP_INFO,	\&_module_pnp_##b##_##unique, #b);
end_define

begin_comment
comment|/**  * descr is a string that describes each entry in the table. The general  * form is (TYPE:pnp_name[/pnp_name];)*  * where TYPE is one of the following:  *	U8	uint8_t element  *	V8	like U8 and 0xff means match any  *	G16	uint16_t element, any value>= matches  *	L16	uint16_t element, any value<= matches  *	M16	uint16_t element, mask of which of the following fields to use.  *	U16	uint16_t element  *	V16	like U16 and 0xffff means match any  *	U32	uint32_t element  *	V32	like U32 and 0xffffffff means match any  *	W32	Two 16-bit values with first pnp_name in LSW and second in MSW.  *	Z	pointer to a string to match exactly  *	D	like Z, but is the string passed to device_set_descr()  *	P	A pointer that should be ignored  *	E	EISA PNP Identifier (in binary, but bus publishes string)  *	K	Key for whole table. pnp_name=value. must be last, if present.  *  * The pnp_name "#" is reserved for other fields that should be ignored.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|modules_sx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MOD_XLOCK
value|sx_xlock(&modules_sx)
end_define

begin_define
define|#
directive|define
name|MOD_SLOCK
value|sx_slock(&modules_sx)
end_define

begin_define
define|#
directive|define
name|MOD_XUNLOCK
value|sx_xunlock(&modules_sx)
end_define

begin_define
define|#
directive|define
name|MOD_SUNLOCK
value|sx_sunlock(&modules_sx)
end_define

begin_define
define|#
directive|define
name|MOD_LOCK_ASSERT
value|sx_assert(&modules_sx, SX_LOCKED)
end_define

begin_define
define|#
directive|define
name|MOD_XLOCK_ASSERT
value|sx_assert(&modules_sx, SX_XLOCKED)
end_define

begin_struct_decl
struct_decl|struct
name|linker_file
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|module_register_init
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|module_register
parameter_list|(
specifier|const
name|struct
name|moduledata
modifier|*
parameter_list|,
name|struct
name|linker_file
modifier|*
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|module_t
name|module_lookupbyid
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|module_quiesce
parameter_list|(
name|module_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|module_reference
parameter_list|(
name|module_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|module_release
parameter_list|(
name|module_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|module_unload
parameter_list|(
name|module_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|module_getid
parameter_list|(
name|module_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|module_t
name|module_getfnext
parameter_list|(
name|module_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|module_getname
parameter_list|(
name|module_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|module_setspecific
parameter_list|(
name|module_t
parameter_list|,
name|modspecific_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|linker_file
modifier|*
name|module_file
parameter_list|(
name|module_t
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
value|do {						\ 	if (mod_debug& MOD_DEBUG_##cat)				\ 		printf args;						\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MOD_DEBUG */
end_comment

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

