begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* alloc.h     Definitions for the object management API protocol memory allocation... */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996-2001 Internet Software Consortium.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names  *    of its contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE INTERNET SOFTWARE CONSORTIUM OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This software has been written for the Internet Software Consortium  * by Ted Lemon in cooperation with Vixie Enterprises and Nominum, Inc.  * To learn more about the Internet Software Consortium, see  * ``http://www.isc.org/''.  To learn more about Vixie Enterprises,  * see ``http://www.vix.com''.   To learn more about Nominum, Inc., see  * ``http://www.nominum.com''.  */
end_comment

begin_function_decl
name|isc_result_t
name|omapi_buffer_new
parameter_list|(
name|omapi_buffer_t
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|omapi_buffer_reference
parameter_list|(
name|omapi_buffer_t
modifier|*
modifier|*
parameter_list|,
name|omapi_buffer_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|omapi_buffer_dereference
parameter_list|(
name|omapi_buffer_t
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_MEMORY_LEAKAGE
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUG_MALLOC_POOL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|DEBUG_MEMORY_LEAKAGE_ON_EXIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|DMDOFFSET
value|(sizeof (struct dmalloc_preamble))
end_define

begin_define
define|#
directive|define
name|DMLFSIZE
value|16
end_define

begin_define
define|#
directive|define
name|DMUFSIZE
value|16
end_define

begin_define
define|#
directive|define
name|DMDSIZE
value|(DMDOFFSET + DMLFSIZE + DMUFSIZE)
end_define

begin_struct
struct|struct
name|dmalloc_preamble
block|{
name|struct
name|dmalloc_preamble
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|unsigned
name|long
name|generation
decl_stmt|;
name|unsigned
name|char
name|low_fence
index|[
name|DMLFSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DMDOFFSET
value|0
end_define

begin_define
define|#
directive|define
name|DMDSIZE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* rc_history flags... */
end_comment

begin_define
define|#
directive|define
name|RC_LEASE
value|1
end_define

begin_define
define|#
directive|define
name|RC_MISC
value|2
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_RC_HISTORY
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|RC_HISTORY_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|RC_HISTORY_MAX
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|RC_HISTORY_FLAGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|RC_HISTORY_FLAGS
value|(RC_LEASE | RC_MISC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|rc_history_entry
block|{
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
name|void
modifier|*
name|reference
decl_stmt|;
name|void
modifier|*
name|addr
decl_stmt|;
name|int
name|refcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rc_register
parameter_list|(
name|x
parameter_list|,
name|l
parameter_list|,
name|r
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|d
parameter_list|,
name|f
parameter_list|)
value|do { \ 		if (RC_HISTORY_FLAGS& ~(f)) { \ 			rc_history [rc_history_index].file = (x); \ 			rc_history [rc_history_index].line = (l); \ 			rc_history [rc_history_index].reference = (r); \ 			rc_history [rc_history_index].addr = (y); \ 			rc_history [rc_history_index].refcnt = (z); \ 			rc_history_next (d); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|rc_register_mdl
parameter_list|(
name|r
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|d
parameter_list|,
name|f
parameter_list|)
define|\
value|rc_register (__FILE__, __LINE__, r, y, z, d, f)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|rc_register
parameter_list|(
name|file
parameter_list|,
name|line
parameter_list|,
name|reference
parameter_list|,
name|addr
parameter_list|,
name|refcnt
parameter_list|,
name|d
parameter_list|,
name|f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|rc_register_mdl
parameter_list|(
name|reference
parameter_list|,
name|addr
parameter_list|,
name|refcnt
parameter_list|,
name|d
parameter_list|,
name|f
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_MEMORY_LEAKAGE
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUG_MALLOC_POOL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|DEBUG_MEMORY_LEAKAGE_ON_EXIT
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|dmalloc_preamble
modifier|*
name|dmalloc_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|dmalloc_outstanding
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|dmalloc_longterm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|dmalloc_generation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|dmalloc_cutoff_generation
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_RC_HISTORY
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|rc_history_entry
name|rc_history
index|[
name|RC_HISTORY_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rc_history_index
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rc_history_count
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

