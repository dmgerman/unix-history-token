begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Lukas Ertl  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GEOM_VINUM_RAID5_H_
end_ifndef

begin_define
define|#
directive|define
name|_GEOM_VINUM_RAID5_H_
end_define

begin_comment
comment|/*  * A single RAID5 request usually needs more than one I/O transaction,  * depending on the state of the associated subdisks and the direction of the  * transaction (read or write).  Every subrequest of a RAID5 request,  * represented by a gv_raid_packet, is defined by a gv_raid5_bit.  */
end_comment

begin_comment
comment|/* A subrequest of a RAID5 read/write operation. */
end_comment

begin_struct
struct|struct
name|gv_raid5_bit
block|{
name|struct
name|bio
modifier|*
name|bio
decl_stmt|;
comment|/* BIO of this subrequest. */
name|caddr_t
name|buf
decl_stmt|;
comment|/* Data buffer of this subrequest. */
name|int
name|malloc
decl_stmt|;
comment|/* Flag if data buffer was malloced. */
name|struct
name|g_consumer
modifier|*
name|consumer
decl_stmt|;
comment|/* Consumer to send the BIO to. */
name|TAILQ_ENTRY
argument_list|(
argument|gv_raid5_bit
argument_list|)
name|list
expr_stmt|;
comment|/* Entry in the list of this request. */
block|}
struct|;
end_struct

begin_comment
comment|/* Container for one or more gv_raid5_bits; represents a RAID5 I/O request. */
end_comment

begin_struct
struct|struct
name|gv_raid5_packet
block|{
name|caddr_t
name|buf
decl_stmt|;
comment|/* Data buffer of this RAID5 request. */
name|off_t
name|length
decl_stmt|;
comment|/* Size of data buffer. */
name|off_t
name|lockbase
decl_stmt|;
comment|/* Deny access to our plex offset. */
name|off_t
name|offset
decl_stmt|;
comment|/* The drive offset of the subdisk. */
name|int
name|bufmalloc
decl_stmt|;
comment|/* Flag if data buffer was malloced. */
name|int
name|active
decl_stmt|;
comment|/* Count of active subrequests. */
name|int
name|rqcount
decl_stmt|;
comment|/* Count of subrequests. */
name|struct
name|bio
modifier|*
name|bio
decl_stmt|;
comment|/* Pointer to the original bio. */
name|caddr_t
name|data
decl_stmt|;
comment|/* Pointer to the original data. */
name|struct
name|g_consumer
modifier|*
name|original
decl_stmt|;
comment|/* Consumer to the data stripe. */
name|struct
name|g_consumer
modifier|*
name|parity
decl_stmt|;
comment|/* Consumer to the parity stripe. */
comment|/* State of this RAID5 packet. */
enum|enum
block|{
name|SETUP
block|,
comment|/* Newly created. */
name|VALID
block|,
comment|/* Ready for processing. */
name|IO
block|,
comment|/* Currently doing I/O. */
name|FINISH
comment|/* Packet has finished. */
block|}
name|state
enum|;
comment|/* Type of this RAID5 transaction. */
enum|enum
block|{
name|JUNK
block|,
comment|/* Newly created, not valid. */
name|NORMAL
block|,
comment|/* Normal read or write. */
name|ISPARITY
block|,
comment|/* Containing only parity data. */
name|NOPARITY
block|,
comment|/* Parity stripe not available. */
name|DEGRADED
block|,
comment|/* Data stripe not available. */
name|COMBINED
comment|/* Data and parity stripes ok, others not. */
block|}
name|type
enum|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|gv_raid5_bit
argument_list|)
name|bits
expr_stmt|;
comment|/* List of subrequests. */
name|TAILQ_ENTRY
argument_list|(
argument|gv_raid5_packet
argument_list|)
name|list
expr_stmt|;
comment|/* Entry in plex's packet list. */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|gv_build_raid5_req
parameter_list|(
name|struct
name|gv_raid5_packet
modifier|*
parameter_list|,
name|struct
name|bio
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|long
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_free_raid5_packet
parameter_list|(
name|struct
name|gv_raid5_packet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_raid5_done
parameter_list|(
name|struct
name|bio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_raid5_worker
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|gv_raid5_packet
modifier|*
name|gv_new_raid5_packet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|gv_raid5_bit
modifier|*
name|gv_new_raid5_bit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GEOM_VINUM_RAID5_H_ */
end_comment

end_unit

