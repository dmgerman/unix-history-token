begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_RWLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_RWLOCK_H_
end_define

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|rwlock
name|rw
decl_stmt|;
block|}
name|rwlock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|read_lock
parameter_list|(
name|_l
parameter_list|)
value|rw_rlock(&(_l)->rw)
end_define

begin_define
define|#
directive|define
name|write_lock
parameter_list|(
name|_l
parameter_list|)
value|rw_wlock(&(_l)->rw)
end_define

begin_define
define|#
directive|define
name|read_unlock
parameter_list|(
name|_l
parameter_list|)
value|rw_runlock(&(_l)->rw)
end_define

begin_define
define|#
directive|define
name|write_unlock
parameter_list|(
name|_l
parameter_list|)
value|rw_wunlock(&(_l)->rw)
end_define

begin_define
define|#
directive|define
name|read_lock_irq
parameter_list|(
name|lock
parameter_list|)
value|read_lock((lock))
end_define

begin_define
define|#
directive|define
name|read_unlock_irq
parameter_list|(
name|lock
parameter_list|)
value|read_unlock((lock))
end_define

begin_define
define|#
directive|define
name|write_lock_irq
parameter_list|(
name|lock
parameter_list|)
value|write_lock((lock))
end_define

begin_define
define|#
directive|define
name|write_unlock_irq
parameter_list|(
name|lock
parameter_list|)
value|write_unlock((lock))
end_define

begin_define
define|#
directive|define
name|read_lock_irqsave
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|)
define|\
value|do {(flags) = 0; read_lock(lock); } while (0)
end_define

begin_define
define|#
directive|define
name|write_lock_irqsave
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|)
define|\
value|do {(flags) = 0; write_lock(lock); } while (0)
end_define

begin_define
define|#
directive|define
name|read_unlock_irqrestore
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|)
define|\
value|do { read_unlock(lock); } while (0)
end_define

begin_define
define|#
directive|define
name|write_unlock_irqrestore
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|)
define|\
value|do { write_unlock(lock); } while (0)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|rwlock_init
parameter_list|(
name|rwlock_t
modifier|*
name|lock
parameter_list|)
block|{
name|memset
argument_list|(
operator|&
name|lock
operator|->
name|rw
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|lock
operator|->
name|rw
argument_list|)
argument_list|)
expr_stmt|;
name|rw_init_flags
argument_list|(
operator|&
name|lock
operator|->
name|rw
argument_list|,
literal|"lnxrw"
argument_list|,
name|RW_NOWITNESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_RWLOCK_H_ */
end_comment

end_unit

