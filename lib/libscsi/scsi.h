begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1994 HD Associates (hd@world.std.com)  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * This product includes software developed by HD Associates  * 4. Neither the name of the HD Associaates nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY HD ASSOCIATES``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL HD ASSOCIATES OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* libscsi: Library header file for the SCSI user library.  */
end_comment

begin_include
include|#
directive|include
file|<sys/scsiio.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|SCSIREQ_ERROR
parameter_list|(
name|SR
parameter_list|)
value|(\ 0 \ || SR->senselen_used
comment|/* Sent sense */
value|\ || SR->status
comment|/* Host adapter status */
value|\ || SR->retsts
comment|/* SCSI transfer status */
value|\ || SR->error
comment|/* copy of errno */
value|\ )
end_define

begin_decl_stmt
name|scsireq_t
modifier|*
name|scsireq_reset
name|__P
argument_list|(
operator|(
name|scsireq_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|scsireq_t
modifier|*
name|scsireq_new
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsireq_buff_decode
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|size_t
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsireq_decode
name|__P
argument_list|(
operator|(
name|scsireq_t
operator|*
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsireq_decode_visit
name|__P
argument_list|(
operator|(
name|scsireq_t
operator|*
operator|,
name|char
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|int
argument_list|,
name|void
operator|*
argument_list|,
name|int
argument_list|,
name|char
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsireq_encode
name|__P
argument_list|(
operator|(
name|scsireq_t
operator|*
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsireq_encode_visit
name|__P
argument_list|(
operator|(
name|scsireq_t
operator|*
operator|,
name|char
operator|*
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|char
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|scsireq_t
modifier|*
name|scsireq_build
name|__P
argument_list|(
operator|(
name|scsireq_t
operator|*
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
name|u_long
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|scsireq_t
modifier|*
name|scsireq_build_visit
name|__P
argument_list|(
operator|(
name|scsireq_t
operator|*
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
name|u_long
operator|,
name|char
operator|*
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|char
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsireq_enter
name|__P
argument_list|(
operator|(
name|int
operator|,
name|scsireq_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scsi_dump
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsi_debug
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|,
name|scsireq_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|scsi_debug_output
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsi_open
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSI_H_ */
end_comment

end_unit

