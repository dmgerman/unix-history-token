begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Lukas Ertl  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/*  * A single RAID5 request usually needs more than one I/O transaction,  * depending on the state of the associated subdisks and the direction of the  * transaction (read or write).  */
end_comment

begin_define
define|#
directive|define
name|GV_ENQUEUE
parameter_list|(
name|bp
parameter_list|,
name|cbp
parameter_list|,
name|pbp
parameter_list|)
define|\
value|do { 							\ 		if (bp->bio_driver1 == NULL) {			\ 			bp->bio_driver1 = cbp;			\ 		} else {					\ 			pbp = bp->bio_driver1;			\ 			while (pbp->bio_caller1 != NULL)	\ 				pbp = pbp->bio_caller1;		\ 			pbp->bio_caller1 = cbp;			\ 		}						\ 	} while (0);
end_define

begin_struct
struct|struct
name|gv_raid5_packet
block|{
name|caddr_t
name|data
decl_stmt|;
comment|/* Data buffer of this sub-request- */
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
name|struct
name|bio
modifier|*
name|parity
decl_stmt|;
comment|/* The bio containing the parity data. */
name|struct
name|bio
modifier|*
name|waiting
decl_stmt|;
comment|/* A bio that need to wait for other bios. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|gv_bioq
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
name|gv_stripe_active
parameter_list|(
name|struct
name|gv_plex
modifier|*
parameter_list|,
name|struct
name|bio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gv_build_raid5_req
parameter_list|(
name|struct
name|gv_plex
modifier|*
parameter_list|,
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
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gv_check_raid5
parameter_list|(
name|struct
name|gv_plex
modifier|*
parameter_list|,
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
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gv_rebuild_raid5
parameter_list|(
name|struct
name|gv_plex
modifier|*
parameter_list|,
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
name|off_t
parameter_list|,
name|off_t
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
name|void
name|gv_plex_done
parameter_list|(
name|struct
name|bio
modifier|*
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

