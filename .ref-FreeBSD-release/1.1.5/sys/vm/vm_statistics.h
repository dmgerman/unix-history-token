begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_statistics.h	7.2 (Berkeley) 4/21/91  *	$Id: vm_statistics.h,v 1.2 1993/10/16 16:20:55 rgrimes Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young, David Golub  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Virtual memory statistics structure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_STATISTICS_
end_ifndef

begin_define
define|#
directive|define
name|_VM_STATISTICS_
end_define

begin_struct
struct|struct
name|vm_statistics
block|{
name|long
name|pagesize
decl_stmt|;
comment|/* page size in bytes */
name|long
name|free_count
decl_stmt|;
comment|/* # of pages free */
name|long
name|active_count
decl_stmt|;
comment|/* # of pages active */
name|long
name|inactive_count
decl_stmt|;
comment|/* # of pages inactive */
name|long
name|wire_count
decl_stmt|;
comment|/* # of pages wired down */
name|long
name|zero_fill_count
decl_stmt|;
comment|/* # of zero fill pages */
name|long
name|reactivations
decl_stmt|;
comment|/* # of pages reactivated */
name|long
name|pageins
decl_stmt|;
comment|/* # of pageins */
name|long
name|pageouts
decl_stmt|;
comment|/* # of pageouts */
name|long
name|faults
decl_stmt|;
comment|/* # of faults */
name|long
name|cow_faults
decl_stmt|;
comment|/* # of copy-on-writes */
name|long
name|lookups
decl_stmt|;
comment|/* object cache lookups */
name|long
name|hits
decl_stmt|;
comment|/* object cache hits */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vm_statistics
modifier|*
name|vm_statistics_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|vm_statistics
name|vm_statistics_data_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|vm_statistics_data_t
name|vm_stat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/*  *	Each machine dependent implementation is expected to  *	keep certain statistics.  They may do this anyway they  *	so choose, but are expected to return the statistics  *	in the following structure.  */
end_comment

begin_struct
struct|struct
name|pmap_statistics
block|{
name|long
name|resident_count
decl_stmt|;
comment|/* # of pages mapped (total)*/
name|long
name|wired_count
decl_stmt|;
comment|/* # of pages wired */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pmap_statistics
modifier|*
name|pmap_statistics_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
endif|_VM_STATISTICS_
end_endif

end_unit

