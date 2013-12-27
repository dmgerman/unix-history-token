begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * version.h  *   * Xen version, type, and compile information.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2005, Nguyen Anh Quynh<aquynh@gmail.com>  * Copyright (c) 2005, Keir Fraser<keir@xensource.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_VERSION_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_VERSION_H__
end_define

begin_comment
comment|/* NB. All ops return zero on success, except XENVER_{version,pagesize} */
end_comment

begin_comment
comment|/* arg == NULL; returns major:minor (16:16). */
end_comment

begin_define
define|#
directive|define
name|XENVER_version
value|0
end_define

begin_comment
comment|/* arg == xen_extraversion_t. */
end_comment

begin_define
define|#
directive|define
name|XENVER_extraversion
value|1
end_define

begin_typedef
typedef|typedef
name|char
name|xen_extraversion_t
index|[
literal|16
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XEN_EXTRAVERSION_LEN
value|(sizeof(xen_extraversion_t))
end_define

begin_comment
comment|/* arg == xen_compile_info_t. */
end_comment

begin_define
define|#
directive|define
name|XENVER_compile_info
value|2
end_define

begin_struct
struct|struct
name|xen_compile_info
block|{
name|char
name|compiler
index|[
literal|64
index|]
decl_stmt|;
name|char
name|compile_by
index|[
literal|16
index|]
decl_stmt|;
name|char
name|compile_domain
index|[
literal|32
index|]
decl_stmt|;
name|char
name|compile_date
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_compile_info
name|xen_compile_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XENVER_capabilities
value|3
end_define

begin_typedef
typedef|typedef
name|char
name|xen_capabilities_info_t
index|[
literal|1024
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XEN_CAPABILITIES_INFO_LEN
value|(sizeof(xen_capabilities_info_t))
end_define

begin_define
define|#
directive|define
name|XENVER_changeset
value|4
end_define

begin_typedef
typedef|typedef
name|char
name|xen_changeset_info_t
index|[
literal|64
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XEN_CHANGESET_INFO_LEN
value|(sizeof(xen_changeset_info_t))
end_define

begin_define
define|#
directive|define
name|XENVER_platform_parameters
value|5
end_define

begin_struct
struct|struct
name|xen_platform_parameters
block|{
name|unsigned
name|long
name|virt_start
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_platform_parameters
name|xen_platform_parameters_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XENVER_get_features
value|6
end_define

begin_struct
struct|struct
name|xen_feature_info
block|{
name|unsigned
name|int
name|submap_idx
decl_stmt|;
comment|/* IN: which 32-bit submap to return */
name|uint32_t
name|submap
decl_stmt|;
comment|/* OUT: 32-bit submap */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_feature_info
name|xen_feature_info_t
typedef|;
end_typedef

begin_comment
comment|/* Declares the features reported by XENVER_get_features. */
end_comment

begin_include
include|#
directive|include
file|"features.h"
end_include

begin_comment
comment|/* arg == NULL; returns host memory page size. */
end_comment

begin_define
define|#
directive|define
name|XENVER_pagesize
value|7
end_define

begin_comment
comment|/* arg == xen_domain_handle_t. */
end_comment

begin_define
define|#
directive|define
name|XENVER_guest_handle
value|8
end_define

begin_define
define|#
directive|define
name|XENVER_commandline
value|9
end_define

begin_typedef
typedef|typedef
name|char
name|xen_commandline_t
index|[
literal|1024
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_VERSION_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

