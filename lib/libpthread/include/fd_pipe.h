begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== fd_pipe.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * Description : The new fast ITC pipe header.  *  *  1.00 93/08/14 proven  *      -Started coding this file.  */
end_comment

begin_struct
struct|struct
name|__pipe
block|{
name|semaphore
name|lock
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|struct
name|pthread
modifier|*
name|wait
decl_stmt|;
name|char
modifier|*
name|wait_buf
decl_stmt|;
name|size_t
name|wait_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RD_CLOSED
value|0x01
end_define

begin_define
define|#
directive|define
name|WR_CLOSED
value|0x02
end_define

end_unit

