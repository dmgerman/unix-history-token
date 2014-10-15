begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Mateusz Guzik<mjg@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SEQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SEQ_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * seq_t may be included in structs visible to userspace  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|seq_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Typical usage:  *  * writers:  * 	lock_exclusive(&obj->lock);  * 	seq_write_begin(&obj->seq);  * 	.....  * 	seq_write_end(&obj->seq);  * 	unlock_exclusive(&obj->unlock);  *  * readers:  * 	obj_t lobj;  * 	seq_t seq;  *  * 	for (;;) {  * 		seq = seq_read(&gobj->seq);  * 		lobj = gobj;  * 		if (seq_consistent(&gobj->seq, seq))  * 			break;  * 		cpu_spinwait();  * 	}  * 	foo(lobj);  */
end_comment

begin_comment
comment|/* A hack to get MPASS macro */
end_comment

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_comment
comment|/*  * This is a temporary hack until memory barriers are cleaned up.  *  * atomic_load_acq_int at least on amd64 provides a full memory barrier,  * in a way which affects perforance.  *  * Hack below covers all architectures and avoids most of the penalty at least  * on amd64.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|atomic_load_acq_rmb_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|p
parameter_list|)
block|{
specifier|volatile
name|u_int
name|v
decl_stmt|;
name|v
operator|=
operator|*
name|p
expr_stmt|;
name|atomic_load_acq_int
argument_list|(
operator|&
name|v
argument_list|)
expr_stmt|;
return|return
operator|(
name|v
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|bool
name|seq_in_modify
parameter_list|(
name|seq_t
name|seqp
parameter_list|)
block|{
return|return
operator|(
name|seqp
operator|&
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|seq_write_begin
parameter_list|(
name|seq_t
modifier|*
name|seqp
parameter_list|)
block|{
name|MPASS
argument_list|(
operator|!
name|seq_in_modify
argument_list|(
operator|*
name|seqp
argument_list|)
argument_list|)
expr_stmt|;
name|atomic_add_acq_int
argument_list|(
name|seqp
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|seq_write_end
parameter_list|(
name|seq_t
modifier|*
name|seqp
parameter_list|)
block|{
name|atomic_add_rel_int
argument_list|(
name|seqp
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|MPASS
argument_list|(
operator|!
name|seq_in_modify
argument_list|(
operator|*
name|seqp
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|seq_t
name|seq_read
parameter_list|(
name|seq_t
modifier|*
name|seqp
parameter_list|)
block|{
name|seq_t
name|ret
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|ret
operator|=
name|atomic_load_acq_rmb_int
argument_list|(
name|seqp
argument_list|)
expr_stmt|;
if|if
condition|(
name|seq_in_modify
argument_list|(
name|ret
argument_list|)
condition|)
block|{
name|cpu_spinwait
argument_list|()
expr_stmt|;
continue|continue;
block|}
break|break;
block|}
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|seq_t
name|seq_consistent
parameter_list|(
name|seq_t
modifier|*
name|seqp
parameter_list|,
name|seq_t
name|oldseq
parameter_list|)
block|{
return|return
operator|(
name|atomic_load_acq_rmb_int
argument_list|(
name|seqp
argument_list|)
operator|==
name|oldseq
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|seq_t
name|seq_consistent_nomb
parameter_list|(
name|seq_t
modifier|*
name|seqp
parameter_list|,
name|seq_t
name|oldseq
parameter_list|)
block|{
return|return
operator|(
operator|*
name|seqp
operator|==
name|oldseq
operator|)
return|;
block|}
end_function

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
comment|/* _SYS_SEQ_H_ */
end_comment

end_unit

