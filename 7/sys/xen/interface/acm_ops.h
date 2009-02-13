begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * acm_ops.h: Xen access control module hypervisor commands  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Reiner Sailer<sailer@watson.ibm.com>  * Copyright (c) 2005,2006 International Business Machines Corporation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ACM_OPS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_ACM_OPS_H__
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_include
include|#
directive|include
file|"acm.h"
end_include

begin_comment
comment|/*  * Make sure you increment the interface version whenever you modify this file!  * This makes sure that old versions of acm tools will stop working in a  * well-defined way (rather than crashing the machine, for instance).  */
end_comment

begin_define
define|#
directive|define
name|ACM_INTERFACE_VERSION
value|0xAAAA000A
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*  * Prototype for this hypercall is:  *  int acm_op(int cmd, void *args)  * @cmd  == ACMOP_??? (access control module operation).  * @args == Operation-specific extra arguments (NULL if none).  */
end_comment

begin_define
define|#
directive|define
name|ACMOP_setpolicy
value|1
end_define

begin_struct
struct|struct
name|acm_setpolicy
block|{
comment|/* IN */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|void
argument_list|)
name|pushcache
expr_stmt|;
name|uint32_t
name|pushcache_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACMOP_getpolicy
value|2
end_define

begin_struct
struct|struct
name|acm_getpolicy
block|{
comment|/* IN */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|void
argument_list|)
name|pullcache
expr_stmt|;
name|uint32_t
name|pullcache_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACMOP_dumpstats
value|3
end_define

begin_struct
struct|struct
name|acm_dumpstats
block|{
comment|/* IN */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|void
argument_list|)
name|pullcache
expr_stmt|;
name|uint32_t
name|pullcache_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACMOP_getssid
value|4
end_define

begin_define
define|#
directive|define
name|ACM_GETBY_ssidref
value|1
end_define

begin_define
define|#
directive|define
name|ACM_GETBY_domainid
value|2
end_define

begin_struct
struct|struct
name|acm_getssid
block|{
comment|/* IN */
name|uint32_t
name|get_ssid_by
decl_stmt|;
comment|/* ACM_GETBY_* */
union|union
block|{
name|domaintype_t
name|domainid
decl_stmt|;
name|ssidref_t
name|ssidref
decl_stmt|;
block|}
name|id
union|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|void
argument_list|)
name|ssidbuf
expr_stmt|;
name|uint32_t
name|ssidbuf_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACMOP_getdecision
value|5
end_define

begin_struct
struct|struct
name|acm_getdecision
block|{
comment|/* IN */
name|uint32_t
name|get_decision_by1
decl_stmt|;
comment|/* ACM_GETBY_* */
name|uint32_t
name|get_decision_by2
decl_stmt|;
comment|/* ACM_GETBY_* */
union|union
block|{
name|domaintype_t
name|domainid
decl_stmt|;
name|ssidref_t
name|ssidref
decl_stmt|;
block|}
name|id1
union|;
union|union
block|{
name|domaintype_t
name|domainid
decl_stmt|;
name|ssidref_t
name|ssidref
decl_stmt|;
block|}
name|id2
union|;
name|uint32_t
name|hook
decl_stmt|;
comment|/* OUT */
name|uint32_t
name|acm_decision
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACMOP_chgpolicy
value|6
end_define

begin_struct
struct|struct
name|acm_change_policy
block|{
comment|/* IN */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|void
argument_list|)
name|policy_pushcache
expr_stmt|;
name|uint32_t
name|policy_pushcache_size
decl_stmt|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|void
argument_list|)
name|del_array
expr_stmt|;
name|uint32_t
name|delarray_size
decl_stmt|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|void
argument_list|)
name|chg_array
expr_stmt|;
name|uint32_t
name|chgarray_size
decl_stmt|;
comment|/* OUT */
comment|/* array with error code */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|void
argument_list|)
name|err_array
expr_stmt|;
name|uint32_t
name|errarray_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACMOP_relabeldoms
value|7
end_define

begin_struct
struct|struct
name|acm_relabel_doms
block|{
comment|/* IN */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|void
argument_list|)
name|relabel_map
expr_stmt|;
name|uint32_t
name|relabel_map_size
decl_stmt|;
comment|/* OUT */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|void
argument_list|)
name|err_array
expr_stmt|;
name|uint32_t
name|errarray_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* future interface to Xen */
end_comment

begin_struct
struct|struct
name|xen_acmctl
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|interface_version
decl_stmt|;
union|union
block|{
name|struct
name|acm_setpolicy
name|setpolicy
decl_stmt|;
name|struct
name|acm_getpolicy
name|getpolicy
decl_stmt|;
name|struct
name|acm_dumpstats
name|dumpstats
decl_stmt|;
name|struct
name|acm_getssid
name|getssid
decl_stmt|;
name|struct
name|acm_getdecision
name|getdecision
decl_stmt|;
name|struct
name|acm_change_policy
name|change_policy
decl_stmt|;
name|struct
name|acm_relabel_doms
name|relabel_doms
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_acmctl
name|xen_acmctl_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_acmctl_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_ACM_OPS_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

