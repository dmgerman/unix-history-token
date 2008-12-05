begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 2004 Christian Limpach.  * Copyright (c) 2004,2005 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christian Limpach.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_XENPMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_XEN_XENPMAP_H_
end_define

begin_include
include|#
directive|include
file|<xen/features.h>
end_include

begin_function_decl
name|void
name|_xen_queue_pt_update
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|vm_paddr_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_pt_switch
parameter_list|(
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_set_ldt
parameter_list|(
name|vm_paddr_t
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_pgdpt_pin
parameter_list|(
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_pgd_pin
parameter_list|(
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_pgd_unpin
parameter_list|(
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_pt_pin
parameter_list|(
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_pt_unpin
parameter_list|(
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_flush_queue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_check_queue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void pmap_ref(pt_entry_t *pte, vm_paddr_t ma);
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|xen_queue_pt_update
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_xen_queue_pt_update((a), (b), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xen_queue_pt_update
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_xen_queue_pt_update((a), (b), NULL, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PMAP_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|PMAP_REF
value|pmap_ref
end_define

begin_define
define|#
directive|define
name|PMAP_DEC_REF_PAGE
value|pmap_dec_ref_page
end_define

begin_define
define|#
directive|define
name|PMAP_MARK_PRIV
value|pmap_mark_privileged
end_define

begin_define
define|#
directive|define
name|PMAP_MARK_UNPRIV
value|pmap_mark_unprivileged
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PMAP_MARK_PRIV
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PMAP_MARK_UNPRIV
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PMAP_REF
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PMAP_DEC_REF_PAGE
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ALWAYS_SYNC
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PT_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|PT_LOG
parameter_list|()
value|printk("WP PT_SET %s:%d\n", __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PT_LOG
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INVALID_P2M_ENTRY
value|(~0UL)
end_define

begin_define
define|#
directive|define
name|pmap_valid_entry
parameter_list|(
name|E
parameter_list|)
value|((E)& PG_V)
end_define

begin_comment
comment|/* is PDE or PTE valid? */
end_comment

begin_define
define|#
directive|define
name|SH_PD_SET_VA
value|1
end_define

begin_define
define|#
directive|define
name|SH_PD_SET_VA_MA
value|2
end_define

begin_define
define|#
directive|define
name|SH_PD_SET_VA_CLEAR
value|3
end_define

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|pd_set
parameter_list|(
name|struct
name|pmap
modifier|*
name|pmap
parameter_list|,
name|int
name|ptepindex
parameter_list|,
name|vm_paddr_t
name|val
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_function
specifier|static
name|vm_paddr_t
name|vptetomachpte
parameter_list|(
name|vm_paddr_t
modifier|*
name|pte
parameter_list|)
block|{
name|vm_offset_t
name|offset
decl_stmt|,
name|ppte
decl_stmt|;
name|vm_paddr_t
name|pgoffset
decl_stmt|,
name|retval
decl_stmt|,
modifier|*
name|pdir_shadow_ptr
decl_stmt|;
name|int
name|pgindex
decl_stmt|;
name|ppte
operator|=
operator|(
name|vm_offset_t
operator|)
name|pte
expr_stmt|;
name|pgoffset
operator|=
operator|(
name|ppte
operator|&
name|PAGE_MASK
operator|)
expr_stmt|;
name|offset
operator|=
name|ppte
operator|-
operator|(
name|vm_offset_t
operator|)
name|PTmap
expr_stmt|;
name|pgindex
operator|=
name|ppte
operator|>>
name|PDRSHIFT
expr_stmt|;
name|pdir_shadow_ptr
operator|=
operator|(
name|vm_paddr_t
operator|*
operator|)
name|PCPU_GET
argument_list|(
name|pdir_shadow
argument_list|)
expr_stmt|;
name|retval
operator|=
operator|(
name|pdir_shadow_ptr
index|[
name|pgindex
index|]
operator|&
operator|~
name|PAGE_MASK
operator|)
operator|+
name|pgoffset
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PT_GET
parameter_list|(
name|_ptp
parameter_list|)
define|\
value|(pmap_valid_entry(*(_ptp)) ? xpmap_mtop(*(_ptp)) : (0))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WRITABLE_PAGETABLES
end_ifdef

begin_define
define|#
directive|define
name|PT_SET_VA
parameter_list|(
name|_ptp
parameter_list|,
name|_npte
parameter_list|,
name|sync
parameter_list|)
value|do {				\         PMAP_REF((_ptp), xpmap_ptom(_npte));                    \         PT_LOG();                                               \         *(_ptp) = xpmap_ptom((_npte));                          \ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PT_SET_VA_MA
parameter_list|(
name|_ptp
parameter_list|,
name|_npte
parameter_list|,
name|sync
parameter_list|)
value|do {		        \         PMAP_REF((_ptp), (_npte));                              \         PT_LOG();                                               \         *(_ptp) = (_npte);                                      \ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PT_CLEAR_VA
parameter_list|(
name|_ptp
parameter_list|,
name|sync
parameter_list|)
value|do {				\         PMAP_REF((pt_entry_t *)(_ptp), 0);                      \         PT_LOG();                                               \         *(_ptp) = 0;                                            \ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PD_SET_VA
parameter_list|(
name|_pmap
parameter_list|,
name|_ptp
parameter_list|,
name|_npte
parameter_list|,
name|sync
parameter_list|)
value|do {		\         PMAP_REF((_ptp), xpmap_ptom(_npte));                    \         pd_set((_pmap),(_ptp),(_npte), SH_PD_SET_VA);           \ 	if (sync || ALWAYS_SYNC) xen_flush_queue();     	\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PD_SET_VA_MA
parameter_list|(
name|_pmap
parameter_list|,
name|_ptp
parameter_list|,
name|_npte
parameter_list|,
name|sync
parameter_list|)
value|do {		\         PMAP_REF((_ptp), (_npte));                              \         pd_set((_pmap),(_ptp),(_npte), SH_PD_SET_VA_MA);        \ 	if (sync || ALWAYS_SYNC) xen_flush_queue();		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PD_CLEAR_VA
parameter_list|(
name|_pmap
parameter_list|,
name|_ptp
parameter_list|,
name|sync
parameter_list|)
value|do {			\         PMAP_REF((pt_entry_t *)(_ptp), 0);                      \         pd_set((_pmap),(_ptp), 0, SH_PD_SET_VA_CLEAR);  	\ 	if (sync || ALWAYS_SYNC) xen_flush_queue();		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !WRITABLE_PAGETABLES */
end_comment

begin_define
define|#
directive|define
name|PT_SET_VA
parameter_list|(
name|_ptp
parameter_list|,
name|_npte
parameter_list|,
name|sync
parameter_list|)
value|do {				\         PMAP_REF((_ptp), xpmap_ptom(_npte));                    \ 	xen_queue_pt_update(vtomach(_ptp), 	        \ 			    xpmap_ptom(_npte)); 		\ 	if (sync || ALWAYS_SYNC) xen_flush_queue();		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PT_SET_VA_MA
parameter_list|(
name|_ptp
parameter_list|,
name|_npte
parameter_list|,
name|sync
parameter_list|)
value|do {		        \         PMAP_REF((_ptp), (_npte));                              \ 	xen_queue_pt_update(vtomach(_ptp), _npte);        \ 	if (sync || ALWAYS_SYNC) xen_flush_queue();		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PT_CLEAR_VA
parameter_list|(
name|_ptp
parameter_list|,
name|sync
parameter_list|)
value|do {				\         PMAP_REF((pt_entry_t *)(_ptp), 0);                      \ 	xen_queue_pt_update(vtomach(_ptp), 0);            \ 	if (sync || ALWAYS_SYNC)				\ 		xen_flush_queue();				\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PD_SET_VA
parameter_list|(
name|_pmap
parameter_list|,
name|_ptepindex
parameter_list|,
name|_npte
parameter_list|,
name|sync
parameter_list|)
value|do {		\         PMAP_REF((_ptp), xpmap_ptom(_npte));                    \         pd_set((_pmap),(_ptepindex),(_npte), SH_PD_SET_VA);     \ 	if (sync || ALWAYS_SYNC) xen_flush_queue();     	\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PD_SET_VA_MA
parameter_list|(
name|_pmap
parameter_list|,
name|_ptepindex
parameter_list|,
name|_npte
parameter_list|,
name|sync
parameter_list|)
value|do {		\         PMAP_REF((_ptp), (_npte));                              \         pd_set((_pmap),(_ptepindex),(_npte), SH_PD_SET_VA_MA);  \ 	if (sync || ALWAYS_SYNC) xen_flush_queue();		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PD_CLEAR_VA
parameter_list|(
name|_pmap
parameter_list|,
name|_ptepindex
parameter_list|,
name|sync
parameter_list|)
value|do {		\         PMAP_REF((pt_entry_t *)(_ptp), 0);                      \         pd_set((_pmap),(_ptepindex), 0, SH_PD_SET_VA_CLEAR);    \ 	if (sync || ALWAYS_SYNC) xen_flush_queue();		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PT_SET_MA
parameter_list|(
name|_va
parameter_list|,
name|_ma
parameter_list|)
define|\
value|do {									\ 	int err;							\ 	err = HYPERVISOR_update_va_mapping(((unsigned long)(_va)),	\ 	    (_ma), UVMF_INVLPG| UVMF_ALL);				\ 	KASSERT(err>= 0, ("unexpected result from update_va_mapping")); \ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|PT_UPDATES_FLUSH
parameter_list|()
value|do {				        \         xen_flush_queue();                                      \ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_function
specifier|static
name|__inline
name|vm_paddr_t
name|xpmap_mtop
parameter_list|(
name|vm_paddr_t
name|mpa
parameter_list|)
block|{
name|vm_paddr_t
name|tmp
init|=
operator|(
name|mpa
operator|&
name|PG_FRAME
operator|)
decl_stmt|;
return|return
name|machtophys
argument_list|(
name|tmp
argument_list|)
operator||
operator|(
name|mpa
operator|&
operator|~
name|PG_FRAME
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|vm_paddr_t
name|xpmap_ptom
parameter_list|(
name|vm_paddr_t
name|ppa
parameter_list|)
block|{
name|vm_paddr_t
name|tmp
init|=
operator|(
name|ppa
operator|&
name|PG_FRAME
operator|)
decl_stmt|;
return|return
name|phystomach
argument_list|(
name|tmp
argument_list|)
operator||
operator|(
name|ppa
operator|&
operator|~
name|PG_FRAME
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|set_phys_to_machine
parameter_list|(
name|unsigned
name|long
name|pfn
parameter_list|,
name|unsigned
name|long
name|mfn
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|notyet
name|PANIC_IF
argument_list|(
name|max_mapnr
operator|&&
name|pfn
operator|>=
name|max_mapnr
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|xen_feature
argument_list|(
name|XENFEAT_auto_translated_physmap
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|notyet
name|PANIC_IF
argument_list|(
operator|(
name|pfn
operator|!=
name|mfn
operator|&&
name|mfn
operator|!=
name|INVALID_P2M_ENTRY
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
name|xen_phys_machine
index|[
name|pfn
index|]
operator|=
name|mfn
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEN_XENPMAP_H_ */
end_comment

end_unit

