begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== pthread_attr.h ========================================================  * Copyright (c) 1993 by Chris Provenzano, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * Description : Basic pthread attributes header.  *  *  1.00 93/11/03 proven  *      -Started coding this file.  */
end_comment

begin_define
define|#
directive|define
name|_POSIX_THREAD_ATTR_STACKSIZE
end_define

begin_define
define|#
directive|define
name|PTHREAD_STACK_DEFAULT
value|65536
end_define

begin_comment
comment|/*  * New pthread attribute types.  */
end_comment

begin_enum
enum|enum
name|pthread_sched_attr
block|{
name|SCHED_RR
block|,
name|SCHED_IO
block|,
name|SCHED_FIFO
block|,
name|SCHED_OTHER
block|, }
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|pthread_attr
block|{
name|enum
name|pthread_sched_attr
name|sched_attr
decl_stmt|;
name|void
modifier|*
name|stackaddr_attr
decl_stmt|;
name|size_t
name|stacksize_attr
decl_stmt|;
block|}
name|pthread_attr_t
typedef|;
end_typedef

begin_comment
comment|/*  * New functions  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|pthread_attr_init
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_destroy
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_setstacksize
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_getstacksize
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_setstackaddr
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_getstackaddr
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|void
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

