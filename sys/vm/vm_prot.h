begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_prot.h	8.1 (Berkeley) 6/11/93  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	Virtual memory protection definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_PROT_
end_ifndef

begin_define
define|#
directive|define
name|_VM_PROT_
end_define

begin_comment
comment|/*  *	Types defined:  *  *	vm_prot_t		VM protection values.  */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|vm_prot_t
typedef|;
end_typedef

begin_comment
comment|/*  *	Protection values, defined as bits within the vm_prot_t type  */
end_comment

begin_define
define|#
directive|define
name|VM_PROT_NONE
value|((vm_prot_t) 0x00)
end_define

begin_define
define|#
directive|define
name|VM_PROT_READ
value|((vm_prot_t) 0x01)
end_define

begin_comment
comment|/* read permission */
end_comment

begin_define
define|#
directive|define
name|VM_PROT_WRITE
value|((vm_prot_t) 0x02)
end_define

begin_comment
comment|/* write permission */
end_comment

begin_define
define|#
directive|define
name|VM_PROT_EXECUTE
value|((vm_prot_t) 0x04)
end_define

begin_comment
comment|/* execute permission */
end_comment

begin_comment
comment|/*  *	The default protection for newly-created virtual memory  */
end_comment

begin_define
define|#
directive|define
name|VM_PROT_DEFAULT
value|(VM_PROT_READ|VM_PROT_WRITE|VM_PROT_EXECUTE)
end_define

begin_comment
comment|/*  *	The maximum privileges possible, for parameter checking.  */
end_comment

begin_define
define|#
directive|define
name|VM_PROT_ALL
value|(VM_PROT_READ|VM_PROT_WRITE|VM_PROT_EXECUTE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VM_PROT_ */
end_comment

end_unit

