begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: kvm_alpha.c,v 1.7.2.1 1997/11/02 20:34:26 mellon Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_include
include|#
directive|include
file|<kvm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"kvm_private.h"
end_include

begin_function
name|void
name|_kvm_freevtop
parameter_list|(
name|kd
parameter_list|)
name|kvm_t
modifier|*
name|kd
decl_stmt|;
block|{
comment|/* Not actually used for anything right now, but safe. */
if|if
condition|(
name|kd
operator|->
name|vmst
operator|!=
literal|0
condition|)
name|free
argument_list|(
name|kd
operator|->
name|vmst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|_kvm_initvtop
parameter_list|(
name|kd
parameter_list|)
name|kvm_t
modifier|*
name|kd
decl_stmt|;
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|_kvm_kvatop
parameter_list|(
name|kd
parameter_list|,
name|va
parameter_list|,
name|pa
parameter_list|)
name|kvm_t
modifier|*
name|kd
decl_stmt|;
name|u_long
name|va
decl_stmt|;
name|u_long
modifier|*
name|pa
decl_stmt|;
block|{
if|#
directive|if
literal|0
block|cpu_kcore_hdr_t *cpu_kh; 	int rv, page_off; 	alpha_pt_entry_t pte; 	off_t pteoff;          if (ISALIVE(kd)) {                 _kvm_err(kd, 0, "vatop called in live kernel!");                 return(0);         }  	cpu_kh = kd->cpu_data; 	page_off = va& (cpu_kh->page_size - 1);  	if (va>= ALPHA_K0SEG_BASE&& va<= ALPHA_K0SEG_END) {
comment|/* 		 * Direct-mapped address: just convert it. 		 */
block|*pa = ALPHA_K0SEG_TO_PHYS(va); 		rv = cpu_kh->page_size - page_off; 	} else if (va>= ALPHA_K1SEG_BASE&& va<= ALPHA_K1SEG_END) {
comment|/* 		 * Real kernel virtual address: do the translation. 		 */
comment|/* Find and read the L1 PTE. */
block|pteoff = cpu_kh->lev1map_pa + 		    kvtol1pte(va) * sizeof(alpha_pt_entry_t); 		if (lseek(kd->pmfd, _kvm_pa2off(kd, pteoff), 0) == -1 || 		    read(kd->pmfd, (char *)&pte, sizeof(pte)) != sizeof(pte)) { 			_kvm_syserr(kd, 0, "could not read L1 PTE"); 			goto lose; 		}
comment|/* Find and read the L2 PTE. */
block|if ((pte& ALPHA_PTE_VALID) == 0) { 			_kvm_err(kd, 0, "invalid translation (invalid L1 PTE)"); 			goto lose; 		} 		pteoff = ALPHA_PTE_TO_PFN(pte) * cpu_kh->page_size + 		    vatoste(va) * sizeof(alpha_pt_entry_t); 		if (lseek(kd->pmfd, _kvm_pa2off(kd, pteoff), 0) == -1 || 		    read(kd->pmfd, (char *)&pte, sizeof(pte)) != sizeof(pte)) { 			_kvm_syserr(kd, 0, "could not read L2 PTE"); 			goto lose; 		}
comment|/* Find and read the L3 PTE. */
block|if ((pte& ALPHA_PTE_VALID) == 0) { 			_kvm_err(kd, 0, "invalid translation (invalid L2 PTE)"); 			goto lose; 		} 		pteoff = ALPHA_PTE_TO_PFN(pte) * cpu_kh->page_size + 		    vatopte(va) * sizeof(alpha_pt_entry_t); 		if (lseek(kd->pmfd, _kvm_pa2off(kd, pteoff), 0) == -1 || 		    read(kd->pmfd, (char *)&pte, sizeof(pte)) != sizeof(pte)) { 			_kvm_syserr(kd, 0, "could not read L3 PTE"); 			goto lose; 		}
comment|/* Fill in the PA. */
block|if ((pte& ALPHA_PTE_VALID) == 0) { 			_kvm_err(kd, 0, "invalid translation (invalid L3 PTE)"); 			goto lose; 		} 		*pa = ALPHA_PTE_TO_PFN(pte) * cpu_kh->page_size + page_off; 		rv = cpu_kh->page_size - page_off; 	} else {
comment|/* 		 * Bogus address (not in KV space): punt. 		 */
block|_kvm_err(kd, 0, "invalid kernel virtual address"); lose: 		*pa = -1; 		rv = 0; 	}  	return (rv);
else|#
directive|else
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Translate a physical address to a file-offset in the crash-dump.  */
end_comment

begin_function
name|off_t
name|_kvm_pa2off
parameter_list|(
name|kd
parameter_list|,
name|pa
parameter_list|)
name|kvm_t
modifier|*
name|kd
decl_stmt|;
name|u_long
name|pa
decl_stmt|;
block|{
if|#
directive|if
literal|0
block|off_t off; 	cpu_kcore_hdr_t *cpu_kh;  	cpu_kh = kd->cpu_data;  	off = 0; 	pa -= cpu_kh->core_seg.start;  	return (kd->dump_off + off + pa);
else|#
directive|else
return|return
literal|0
return|;
comment|/* XXX fixme */
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Machine-dependent initialization for ALL open kvm descriptors,  * not just those for a kernel crash dump.  Some architectures  * have to deal with these NOT being constants!  (i.e. m68k)  */
end_comment

begin_function
name|int
name|_kvm_mdopen
parameter_list|(
name|kd
parameter_list|)
name|kvm_t
modifier|*
name|kd
decl_stmt|;
block|{
if|#
directive|if
literal|0
comment|/* XXX fixme */
block|kd->usrstack = USRSTACK; 	kd->min_uva = VM_MIN_ADDRESS; 	kd->max_uva = VM_MAXUSER_ADDRESS;
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

