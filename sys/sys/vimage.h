begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2008 University of Zagreb  * Copyright (c) 2006-2008 FreeBSD Foundation  *  * This software was developed by the University of Zagreb and the  * FreeBSD Foundation under sponsorship by the Stichting NLnet and the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VIMAGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VIMAGE_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct_decl
struct_decl|struct
name|kld_sym_lookup
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|vnet_symmap
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
name|base
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vnet_modinfo
block|{
name|char
modifier|*
name|vmi_name
decl_stmt|;
name|struct
name|vnet_symmap
modifier|*
name|vmi_symmap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vnet_modlink
block|{
name|TAILQ_ENTRY
argument_list|(
argument|vnet_modlink
argument_list|)
name|vml_mod_le
expr_stmt|;
specifier|const
name|struct
name|vnet_modinfo
modifier|*
name|vml_modinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VNET_MOD_DECLARE
parameter_list|(
name|m_name_uc
parameter_list|,
name|m_name_lc
parameter_list|,
name|m_iattach
parameter_list|,
name|m_idetach
parameter_list|, 	\
name|m_dependson
parameter_list|,
name|m_symmap
parameter_list|)
define|\
value|static const struct vnet_modinfo vnet_##m_name_lc##_modinfo = {	\ 		.vmi_name		= #m_name_lc,			\ 		.vmi_symmap		= m_symmap			\ };
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|VSYM
parameter_list|(
name|base
parameter_list|,
name|sym
parameter_list|)
value|(sym)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_error
error|#
directive|error
literal|"No option VIMAGE yet!"
end_error

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VSYM
parameter_list|(
name|base
parameter_list|,
name|sym
parameter_list|)
value|(base ## _0._ ## sym)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VNET_SYMMAP
parameter_list|(
name|mod
parameter_list|,
name|name
parameter_list|)
define|\
value|{ #name,&(vnet_ ## mod ## _0._ ## name),			\ 	sizeof(vnet_ ## mod ## _0._ ## name) }
end_define

begin_define
define|#
directive|define
name|VNET_SYMMAP_END
value|{ NULL, 0 }
end_define

begin_comment
comment|/* Non-VIMAGE null-macros */
end_comment

begin_define
define|#
directive|define
name|CURVNET_SET
parameter_list|(
name|arg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CURVNET_SET_QUIET
parameter_list|(
name|arg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CURVNET_RESTORE
parameter_list|()
end_define

begin_define
define|#
directive|define
name|VNET_ASSERT
parameter_list|(
name|condition
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INIT_FROM_VNET
parameter_list|(
name|vnet
parameter_list|,
name|modindex
parameter_list|,
name|modtype
parameter_list|,
name|sym
parameter_list|)
end_define

begin_define
define|#
directive|define
name|VNET_ITERATOR_DECL
parameter_list|(
name|arg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|VNET_FOREACH
parameter_list|(
name|arg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|VNET_LIST_RLOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|VNET_LIST_RUNLOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|INIT_VPROCG
parameter_list|(
name|arg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INIT_VCPU
parameter_list|(
name|arg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TD_TO_VIMAGE
parameter_list|(
name|td
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TD_TO_VNET
parameter_list|(
name|td
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TD_TO_VPROCG
parameter_list|(
name|td
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TD_TO_VCPU
parameter_list|(
name|td
parameter_list|)
end_define

begin_define
define|#
directive|define
name|P_TO_VIMAGE
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|P_TO_VNET
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|P_TO_VPROCG
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|P_TO_VCPU
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* XXX those defines bellow should probably go into vprocg.h and vcpu.h */
end_comment

begin_define
define|#
directive|define
name|VPROCG
parameter_list|(
name|sym
parameter_list|)
value|(sym)
end_define

begin_define
define|#
directive|define
name|VCPU
parameter_list|(
name|sym
parameter_list|)
value|(sym)
end_define

begin_define
define|#
directive|define
name|V_hostname
value|VPROCG(hostname)
end_define

begin_define
define|#
directive|define
name|G_hostname
value|VPROCG(hostname)
end_define

begin_comment
comment|/* global hostname */
end_comment

begin_define
define|#
directive|define
name|V_domainname
value|VPROCG(domainname)
end_define

begin_function_decl
name|int
name|vi_symlookup
parameter_list|(
name|struct
name|kld_sym_lookup
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_mod_register
parameter_list|(
specifier|const
name|struct
name|vnet_modinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_VIMAGE_H_ */
end_comment

end_unit

