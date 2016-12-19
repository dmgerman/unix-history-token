begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_STOREVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_STOREVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"bhnd_nvram_plist.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_store.h"
end_include

begin_comment
comment|/** Index is only generated if minimum variable count is met */
end_comment

begin_define
define|#
directive|define
name|BHND_NV_IDX_VAR_THRESHOLD
value|15
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_ROOT_PATH
value|"/"
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_ROOT_PATH_LEN
value|sizeof(BHND_NVSTORE_ROOT_PATH)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_GET_FLAG
parameter_list|(
name|_value
parameter_list|,
name|_flag
parameter_list|)
define|\
value|(((_value)& BHND_NVSTORE_ ## _flag) != 0)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_GET_BITS
parameter_list|(
name|_value
parameter_list|,
name|_field
parameter_list|)
define|\
value|((_value)& BHND_NVSTORE_ ## _field ## _MASK)
end_define

begin_comment
comment|/* Forward declarations */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvstore_name_info
name|bhnd_nvstore_name_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvstore_index
name|bhnd_nvstore_index
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvstore_path
name|bhnd_nvstore_path
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvstore_alias
name|bhnd_nvstore_alias
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvstore_alias_list
name|bhnd_nvstore_alias_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvstore_update_list
name|bhnd_nvstore_update_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvstore_path_list
name|bhnd_nvstore_path_list
typedef|;
end_typedef

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|bhnd_nvstore_alias_list
argument_list|,
name|bhnd_nvstore_alias
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|bhnd_nvstore_update_list
argument_list|,
name|bhnd_nvstore_update
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|bhnd_nvstore_path_list
argument_list|,
name|bhnd_nvstore_path
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * NVRAM store variable entry types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_NVSTORE_VAR
init|=
literal|0
block|,
comment|/**< simple variable (var=...) */
name|BHND_NVSTORE_ALIAS_DECL
init|=
literal|1
block|,
comment|/**< alias declaration ('devpath0=pci/1/1') */
block|}
name|bhnd_nvstore_var_type
typedef|;
end_typedef

begin_comment
comment|/**  * NVRAM path descriptor types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_NVSTORE_PATH_STRING
init|=
literal|0
block|,
comment|/**< path is a string value */
name|BHND_NVSTORE_PATH_ALIAS
init|=
literal|1
comment|/**< path is an alias reference */
block|}
name|bhnd_nvstore_path_type
typedef|;
end_typedef

begin_comment
comment|/**  * NVRAM variable namespaces.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_NVSTORE_NAME_INTERNAL
init|=
literal|1
block|,
comment|/**< internal namespace. permits 						     use of reserved devpath and 						     alias name prefixes. */
name|BHND_NVSTORE_NAME_EXTERNAL
init|=
literal|2
block|,
comment|/**< external namespace. forbids 						     use of name prefixes used 						     for device path handling */
block|}
name|bhnd_nvstore_name_type
typedef|;
end_typedef

begin_function_decl
name|bhnd_nvstore_path
modifier|*
name|bhnd_nvstore_path_new
parameter_list|(
specifier|const
name|char
modifier|*
name|path_str
parameter_list|,
name|size_t
name|path_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_nvstore_path_free
parameter_list|(
name|struct
name|bhnd_nvstore_path
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvstore_index
modifier|*
name|bhnd_nvstore_index_new
parameter_list|(
name|size_t
name|capacity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_nvstore_index_free
parameter_list|(
name|bhnd_nvstore_index
modifier|*
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvstore_index_append
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|bhnd_nvstore_index
modifier|*
name|index
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvstore_index_prepare
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|bhnd_nvstore_index
modifier|*
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|bhnd_nvstore_index_lookup
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|bhnd_nvstore_index
modifier|*
name|index
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvstore_path
modifier|*
name|bhnd_nvstore_get_root_path
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_nvstore_is_root_path
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|bhnd_nvstore_path
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|bhnd_nvstore_path_data_next
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|bhnd_nvstore_path
modifier|*
name|path
parameter_list|,
name|void
modifier|*
modifier|*
name|indexp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|bhnd_nvstore_path_data_lookup
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|bhnd_nvstore_path
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvram_prop
modifier|*
name|bhnd_nvstore_path_get_update
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|bhnd_nvstore_path
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvstore_path_register_update
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|bhnd_nvstore_path
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bhnd_nvram_val
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvstore_alias
modifier|*
name|bhnd_nvstore_find_alias
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvstore_alias
modifier|*
name|bhnd_nvstore_get_alias
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|u_long
name|alias_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvstore_path
modifier|*
name|bhnd_nvstore_get_path
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|size_t
name|path_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvstore_path
modifier|*
name|bhnd_nvstore_resolve_path_alias
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|u_long
name|aval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_nvstore_path
modifier|*
name|bhnd_nvstore_var_get_path
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|bhnd_nvstore_name_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvstore_var_register_path
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
name|bhnd_nvstore_name_info
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvstore_register_path
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|size_t
name|path_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvstore_register_alias
parameter_list|(
name|struct
name|bhnd_nvram_store
modifier|*
name|sc
parameter_list|,
specifier|const
name|bhnd_nvstore_name_info
modifier|*
name|info
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|bhnd_nvstore_parse_relpath
parameter_list|(
specifier|const
name|char
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvstore_parse_name_info
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bhnd_nvstore_name_type
name|name_type
parameter_list|,
name|uint32_t
name|data_caps
parameter_list|,
name|bhnd_nvstore_name_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * NVRAM variable name descriptor.  *   * For NVRAM data instances supporting BHND_NVRAM_DATA_CAP_DEVPATHS, the  * NVRAM-vended variable name will be in one of four formats:  *   * - Simple Variable:  * 	'variable'  * - Device Variable:  * 	'pci/1/1/variable'  * - Device Alias Variable:  * 	'0:variable'  * - Device Path Alias Definition:  * 	'devpath0=pci/1/1/variable'  *  * Device Paths:  *   * The device path format is device class-specific; the known supported device  * classes are:  * 	- sb:		BCMA/SIBA SoC core device path.  *	- pci:		PCI device path (and PCIe on some earlier devices).  *	- pcie:		PCIe device path.  *	- usb:		USB device path.  *  * The device path format is loosely defined as '[class]/[domain]/[bus]/[slot]',  * with missing values either assumed to be zero, a value specific to the  * device class, or irrelevant to the device class in question.  *   * Examples:  *	sb/1			BCMA/SIBA backplane 0, core 1.  *	pc/1/1			PCMCIA bus 1, slot 1  *	pci/1/1			PCI/PCIe domain 0, bus 1, device 1  *	pcie/1/1		PCIe domain 0, bus 1, device 1  *	usb/0xbd17		USB PID 0xbd17 (VID defaults to Broadcom 0x0a5c)  *  * Device Path Aliases:  *   * Device path aliases reduce duplication of device paths in the flash encoding  * of NVRAM data; a single devpath[alias]=[devpath] variable entry is defined,  * and then later variables may reference the device path via its alias:  * 	devpath1=usb/0xbd17  *	1:mcs5gpo0=0x1100  *   * Alias values are always positive, base 10 integers.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvstore_name_info
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< variable name */
name|bhnd_nvstore_var_type
name|type
decl_stmt|;
comment|/**< variable type */
name|bhnd_nvstore_path_type
name|path_type
decl_stmt|;
comment|/**< path type */
comment|/** Path information */
union|union
block|{
comment|/* BHND_NVSTORE_PATH_STRING */
struct|struct
block|{
specifier|const
name|char
modifier|*
name|value
decl_stmt|;
comment|/**< device path */
name|size_t
name|value_len
decl_stmt|;
comment|/**< device path length */
block|}
name|str
struct|;
comment|/** BHND_NVSTORE_PATH_ALIAS */
struct|struct
block|{
name|u_long
name|value
decl_stmt|;
comment|/**< device alias */
block|}
name|alias
struct|;
block|}
name|path
union|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * NVRAM variable index.  *   * Provides effecient name-based lookup by maintaining an array of cached  * cookiep values, sorted lexicographically by relative variable name.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvstore_index
block|{
name|size_t
name|count
decl_stmt|;
comment|/**< entry count */
name|size_t
name|capacity
decl_stmt|;
comment|/**< entry capacity */
name|void
modifier|*
name|cookiep
index|[]
decl_stmt|;
comment|/**< cookiep values */
block|}
struct|;
end_struct

begin_comment
comment|/**  * NVRAM device path.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvstore_path
block|{
name|char
modifier|*
name|path_str
decl_stmt|;
comment|/**< canonical path string */
name|size_t
name|num_vars
decl_stmt|;
comment|/**< per-path count of committed 							     (non-pending) variables */
name|bhnd_nvstore_index
modifier|*
name|index
decl_stmt|;
comment|/**< per-path index, or NULL if 							     this is a root path for 							     which the data source 							     may be queried directly. */
name|bhnd_nvram_plist
modifier|*
name|pending
decl_stmt|;
comment|/**< pending changes */
name|LIST_ENTRY
argument_list|(
argument|bhnd_nvstore_path
argument_list|)
name|np_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * NVRAM device path alias.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvstore_alias
block|{
name|bhnd_nvstore_path
modifier|*
name|path
decl_stmt|;
comment|/**< borrowed path reference */
name|void
modifier|*
name|cookiep
decl_stmt|;
comment|/**< NVRAM variable's cookiep value */
name|u_long
name|alias
decl_stmt|;
comment|/**< alias value */
name|LIST_ENTRY
argument_list|(
argument|bhnd_nvstore_alias
argument_list|)
name|na_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** bhnd nvram store instance state */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_store
block|{
ifdef|#
directive|ifdef
name|_KERNEL
name|struct
name|mtx
name|mtx
decl_stmt|;
else|#
directive|else
name|pthread_mutex_t
name|mtx
decl_stmt|;
endif|#
directive|endif
name|struct
name|bhnd_nvram_data
modifier|*
name|data
decl_stmt|;
comment|/**< backing data */
name|uint32_t
name|data_caps
decl_stmt|;
comment|/**< data capability flags */
name|bhnd_nvram_plist
modifier|*
name|data_opts
decl_stmt|;
comment|/**< data serialization options */
name|bhnd_nvstore_alias_list
name|aliases
index|[
literal|4
index|]
decl_stmt|;
comment|/**< path alias hash table */
name|size_t
name|num_aliases
decl_stmt|;
comment|/**< alias count */
name|bhnd_nvstore_path
modifier|*
name|root_path
decl_stmt|;
comment|/**< root path instance */
name|bhnd_nvstore_path_list
name|paths
index|[
literal|4
index|]
decl_stmt|;
comment|/**< path hash table */
name|size_t
name|num_paths
decl_stmt|;
comment|/**< path count */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->mtx, "BHND NVRAM store lock", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->mtx, what)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->mtx)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
value|do {				\ 	int error = pthread_mutex_init(&(sc)->mtx, NULL);		\ 	if (error)							\ 		BHND_NV_PANIC("pthread_mutex_init() failed: %d",	\ 		    error);						\ } while(0)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|pthread_mutex_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|pthread_mutex_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|pthread_mutex_destroy(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_STOREVAR_H_ */
end_comment

end_unit

