begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)lock.h	8.1 (Berkeley) 6/11/93  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $Id: lock.h,v 1.3 1995/01/09 16:05:31 davidg Exp $  */
end_comment

begin_comment
comment|/*  *	Locking primitives definitions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_LOCK_H_
end_define

begin_comment
comment|/*  *	The general lock structure.  Provides for multiple readers,  *	upgrading from read to write, and sleeping until the lock  *	can be gained.  */
end_comment

begin_struct
struct|struct
name|lock
block|{
comment|/* 	 * Only the "interlock" field is used for hardware exclusion; other 	 * fields are modified with normal instructions after acquiring the 	 * interlock bit. 	 */
name|boolean_t
name|want_write
decl_stmt|;
comment|/* Writer is waiting, or locked for write */
name|boolean_t
name|want_upgrade
decl_stmt|;
comment|/* Read-to-write upgrade waiting */
name|boolean_t
name|waiting
decl_stmt|;
comment|/* Someone is sleeping on lock */
name|boolean_t
name|can_sleep
decl_stmt|;
comment|/* Can attempts to lock go to sleep */
name|int
name|read_count
decl_stmt|;
comment|/* Number of accepted readers */
name|struct
name|proc
modifier|*
name|proc
decl_stmt|;
comment|/* If recursive locking, process that has lock */
name|int
name|recursion_depth
decl_stmt|;
comment|/* Depth of recursion */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|lock
name|lock_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|lock
modifier|*
name|lock_t
typedef|;
end_typedef

begin_comment
comment|/* Sleep locks must work even if no multiprocessing. */
end_comment

begin_define
define|#
directive|define
name|lock_read_done
parameter_list|(
name|l
parameter_list|)
value|lock_done(l)
end_define

begin_define
define|#
directive|define
name|lock_write_done
parameter_list|(
name|l
parameter_list|)
value|lock_done(l)
end_define

begin_decl_stmt
name|void
name|lock_clear_recursive
name|__P
argument_list|(
operator|(
name|lock_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lock_done
name|__P
argument_list|(
operator|(
name|lock_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lock_init
name|__P
argument_list|(
operator|(
name|lock_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lock_read
name|__P
argument_list|(
operator|(
name|lock_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|lock_read_to_write
name|__P
argument_list|(
operator|(
name|lock_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lock_set_recursive
name|__P
argument_list|(
operator|(
name|lock_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lock_sleepable
name|__P
argument_list|(
operator|(
name|lock_t
operator|,
name|boolean_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|lock_try_read
name|__P
argument_list|(
operator|(
name|lock_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|lock_try_read_to_write
name|__P
argument_list|(
operator|(
name|lock_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|lock_try_write
name|__P
argument_list|(
operator|(
name|lock_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lock_write
name|__P
argument_list|(
operator|(
name|lock_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lock_write_to_read
name|__P
argument_list|(
operator|(
name|lock_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LOCK_H_ */
end_comment

end_unit

