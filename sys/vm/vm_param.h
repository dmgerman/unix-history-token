begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_param.h	8.1 (Berkeley) 6/11/93  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	Machine independent virtual memory parameters.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_PARAM_
end_ifndef

begin_define
define|#
directive|define
name|_VM_PARAM_
end_define

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_comment
comment|/*  * CTL_VM identifiers  */
end_comment

begin_define
define|#
directive|define
name|VM_TOTAL
value|1
end_define

begin_comment
comment|/* struct vmtotal */
end_comment

begin_define
define|#
directive|define
name|VM_METER
value|VM_TOTAL
end_define

begin_comment
comment|/* deprecated, use VM_TOTAL */
end_comment

begin_define
define|#
directive|define
name|VM_LOADAVG
value|2
end_define

begin_comment
comment|/* struct loadavg */
end_comment

begin_define
define|#
directive|define
name|VM_V_FREE_MIN
value|3
end_define

begin_comment
comment|/* cnt.v_free_min */
end_comment

begin_define
define|#
directive|define
name|VM_V_FREE_TARGET
value|4
end_define

begin_comment
comment|/* cnt.v_free_target */
end_comment

begin_define
define|#
directive|define
name|VM_V_FREE_RESERVED
value|5
end_define

begin_comment
comment|/* cnt.v_free_reserved */
end_comment

begin_define
define|#
directive|define
name|VM_V_INACTIVE_TARGET
value|6
end_define

begin_comment
comment|/* cnt.v_inactive_target */
end_comment

begin_define
define|#
directive|define
name|VM_V_CACHE_MIN
value|7
end_define

begin_comment
comment|/* cnt.v_cache_min */
end_comment

begin_define
define|#
directive|define
name|VM_V_CACHE_MAX
value|8
end_define

begin_comment
comment|/* cnt.v_cache_max */
end_comment

begin_define
define|#
directive|define
name|VM_V_PAGEOUT_FREE_MIN
value|9
end_define

begin_comment
comment|/* cnt.v_pageout_free_min */
end_comment

begin_define
define|#
directive|define
name|VM_PAGEOUT_ALGORITHM
value|10
end_define

begin_comment
comment|/* pageout algorithm */
end_comment

begin_define
define|#
directive|define
name|VM_SWAPPING_ENABLED
value|11
end_define

begin_comment
comment|/* swapping enabled */
end_comment

begin_define
define|#
directive|define
name|VM_MAXID
value|12
end_define

begin_comment
comment|/* number of valid vm ids */
end_comment

begin_define
define|#
directive|define
name|CTL_VM_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "vmtotal", CTLTYPE_STRUCT }, \ 	{ "loadavg", CTLTYPE_STRUCT }, \ 	{ "v_free_min", CTLTYPE_INT }, \ 	{ "v_free_target", CTLTYPE_INT }, \ 	{ "v_free_reserved", CTLTYPE_INT }, \ 	{ "v_inactive_target", CTLTYPE_INT }, \ 	{ "v_cache_min", CTLTYPE_INT }, \ 	{ "v_cache_max", CTLTYPE_INT }, \ 	{ "v_pageout_free_min", CTLTYPE_INT}, \ 	{ "pageout_algorithm", CTLTYPE_INT}, \ 	{ "swapping_enabled", CTLTYPE_INT},\ }
end_define

begin_comment
comment|/*  * Structure for swap device statistics  */
end_comment

begin_define
define|#
directive|define
name|XSWDEV_VERSION
value|1
end_define

begin_struct
struct|struct
name|xswdev
block|{
name|u_int
name|xsw_version
decl_stmt|;
name|dev_t
name|xsw_dev
decl_stmt|;
name|int
name|xsw_flags
decl_stmt|;
name|int
name|xsw_nblks
decl_stmt|;
name|int
name|xsw_used
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Return values from the VM routines.  */
end_comment

begin_define
define|#
directive|define
name|KERN_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|KERN_INVALID_ADDRESS
value|1
end_define

begin_define
define|#
directive|define
name|KERN_PROTECTION_FAILURE
value|2
end_define

begin_define
define|#
directive|define
name|KERN_NO_SPACE
value|3
end_define

begin_define
define|#
directive|define
name|KERN_INVALID_ARGUMENT
value|4
end_define

begin_define
define|#
directive|define
name|KERN_FAILURE
value|5
end_define

begin_define
define|#
directive|define
name|KERN_RESOURCE_SHORTAGE
value|6
end_define

begin_define
define|#
directive|define
name|KERN_NOT_RECEIVER
value|7
end_define

begin_define
define|#
directive|define
name|KERN_NO_ACCESS
value|8
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ASSEMBLER
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|num_pages
parameter_list|(
name|x
parameter_list|)
define|\
value|((vm_offset_t)((((vm_offset_t)(x)) + PAGE_MASK)>> PAGE_SHIFT))
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|maxtsiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|dfldsiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|maxdsiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|dflssiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|maxssiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|sgrowsiz
decl_stmt|;
end_decl_stmt

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
comment|/* ASSEMBLER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VM_PARAM_ */
end_comment

end_unit

