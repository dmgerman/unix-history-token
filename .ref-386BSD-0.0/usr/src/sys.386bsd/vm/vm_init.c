begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vm_init.c	7.3 (Berkeley) 4/21/91  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Initialize the Virtual Memory subsystem.  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"vm.h"
end_include

begin_include
include|#
directive|include
file|"vm_page.h"
end_include

begin_include
include|#
directive|include
file|"vm_kern.h"
end_include

begin_comment
comment|/*  *	vm_init initializes the virtual memory system.  *	This is done only by the first cpu up.  *  *	The start and end address of physical memory is passed in.  */
end_comment

begin_function
name|void
name|vm_mem_init
parameter_list|()
block|{
specifier|extern
name|vm_offset_t
name|avail_start
decl_stmt|,
name|avail_end
decl_stmt|;
specifier|extern
name|vm_offset_t
name|virtual_avail
decl_stmt|,
name|virtual_end
decl_stmt|;
comment|/* 	 *	Initializes resident memory structures. 	 *	From here on, all physical memory is accounted for, 	 *	and we use only virtual addresses. 	 */
name|virtual_avail
operator|=
name|vm_page_startup
argument_list|(
name|avail_start
argument_list|,
name|avail_end
argument_list|,
name|virtual_avail
argument_list|)
expr_stmt|;
comment|/* 	 * Initialize other VM packages 	 */
name|vm_object_init
argument_list|()
expr_stmt|;
name|vm_map_startup
argument_list|()
expr_stmt|;
name|kmem_init
argument_list|(
name|virtual_avail
argument_list|,
name|virtual_end
argument_list|)
expr_stmt|;
name|pmap_init
argument_list|(
name|avail_start
argument_list|,
name|avail_end
argument_list|)
expr_stmt|;
name|vm_pager_init
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

