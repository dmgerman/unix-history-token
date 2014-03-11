begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * xen/xen-os.h  *   * Random collection of macros and definition  *  * Copyright (c) 2003, 2004 Keir Fraser (on behalf of the Xen team)  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE   * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER   * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING   * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER   * DEALINGS IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_XEN_OS_H_
end_ifndef

begin_define
define|#
directive|define
name|_XEN_XEN_OS_H_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__XEN_INTERFACE_VERSION__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__XEN_INTERFACE_VERSION__
value|0x00030208
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GRANT_REF_INVALID
value|0xffffffff
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_define
define|#
directive|define
name|__ASSEMBLY__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/xen/xen-os.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/xen.h>
end_include

begin_comment
comment|/* Everything below this point is not included by assembler (.S) files. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_comment
comment|/* Force a proper event-channel callback from Xen. */
end_comment

begin_function_decl
name|void
name|force_evtchn_callback
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|shared_info_t
modifier|*
name|HYPERVISOR_shared_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|start_info_t
modifier|*
name|HYPERVISOR_start_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX: we need to get rid of this and use HYPERVISOR_start_info directly */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|xenstore_domain_interface
modifier|*
name|xen_store
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|xen_domain_type
block|{
name|XEN_NATIVE
block|,
comment|/* running on bare hardware    */
name|XEN_PV_DOMAIN
block|,
comment|/* running in a PV domain      */
name|XEN_HVM_DOMAIN
block|,
comment|/* running in a Xen hvm domain */
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|xen_domain_type
name|xen_domain_type
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|int
name|xen_domain
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xen_domain_type
operator|!=
name|XEN_NATIVE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|xen_pv_domain
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xen_domain_type
operator|==
name|XEN_PV_DOMAIN
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|xen_hvm_domain
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xen_domain_type
operator|==
name|XEN_HVM_DOMAIN
operator|)
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|xen_mb
end_ifndef

begin_define
define|#
directive|define
name|xen_mb
parameter_list|()
value|mb()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|xen_rmb
end_ifndef

begin_define
define|#
directive|define
name|xen_rmb
parameter_list|()
value|rmb()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|xen_wmb
end_ifndef

begin_define
define|#
directive|define
name|xen_wmb
parameter_list|()
value|wmb()
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
comment|/* !__ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEN_XEN_OS_H_ */
end_comment

end_unit

