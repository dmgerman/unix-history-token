begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== fd.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * Description : Basic fd header.  *  *  1.00 93/08/14 proven  *      -Started coding this file.  *  *	1.01 93/11/13 proven  *		-The functions readv() and writev() added  */
end_comment

begin_comment
comment|/*  * New pthread types.  */
end_comment

begin_enum
enum|enum
name|fd_type
block|{
name|FD_NT
block|,
comment|/* Not tested */
name|FD_NIU
block|,
comment|/* Known to be not in use */
name|FD_HALF_DUPLEX
block|,
comment|/* Files, and seeking devices */
name|FD_FULL_DUPLEX
comment|/* pipes, sockets, drivers, ... */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|FD_READ
value|0x1
end_define

begin_define
define|#
directive|define
name|FD_WRITE
value|0x2
end_define

begin_define
define|#
directive|define
name|FD_RDWR
value|(FD_READ | FD_WRITE)
end_define

begin_struct
struct|struct
name|fd_ops
block|{
name|int
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|read
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fcntl
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|writev
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|readv
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|seek
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_union
union|union
name|fd_data
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|fd_table_entry
block|{
name|struct
name|pthread_queue
name|r_queue
decl_stmt|;
name|struct
name|pthread_queue
name|w_queue
decl_stmt|;
name|struct
name|pthread
modifier|*
name|r_owner
decl_stmt|;
name|struct
name|pthread
modifier|*
name|w_owner
decl_stmt|;
name|semaphore
name|lock
decl_stmt|;
name|struct
name|fd_table_entry
modifier|*
name|next
decl_stmt|;
name|struct
name|fd_ops
modifier|*
name|ops
decl_stmt|;
name|enum
name|fd_type
name|type
decl_stmt|;
name|int
name|lockcount
decl_stmt|;
comment|/* Count for FILE locks */
name|int
name|count
decl_stmt|;
comment|/* data that needs to be passed to the type dependent fd */
name|int
name|flags
decl_stmt|;
name|union
name|fd_data
name|fd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Important data structure  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fd_table_entry
modifier|*
name|fd_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dtablesize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * New functions  */
end_comment

begin_expr_stmt
name|__BEGIN_DECLS
if|#
directive|if
name|defined
argument_list|(
name|PTHREAD_KERNEL
argument_list|)
endif|#
directive|endif
name|__END_DECLS
end_expr_stmt

end_unit

