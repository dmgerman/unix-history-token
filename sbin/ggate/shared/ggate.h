begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GGATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_GGATE_H_
end_define

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|G_GATE_BUFSIZE_START
value|65536
end_define

begin_define
define|#
directive|define
name|G_GATE_PORT
value|3080
end_define

begin_define
define|#
directive|define
name|G_GATE_RCVBUF
value|131072
end_define

begin_define
define|#
directive|define
name|G_GATE_SNDBUF
value|131072
end_define

begin_define
define|#
directive|define
name|G_GATE_QUEUE_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|G_GATE_TIMEOUT
value|30
end_define

begin_decl_stmt
specifier|extern
name|int
name|g_gate_devfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g_gate_verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Client's initial packet. */
end_comment

begin_struct
struct|struct
name|g_gate_cinit
block|{
name|char
name|gc_path
index|[
name|PATH_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|uint8_t
name|gc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Server's initial packet. */
end_comment

begin_struct
struct|struct
name|g_gate_sinit
block|{
name|uint8_t
name|gs_flags
decl_stmt|;
name|uint64_t
name|gs_mediasize
decl_stmt|;
name|uint32_t
name|gs_sectorsize
decl_stmt|;
name|uint16_t
name|gs_error
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Control struct. */
end_comment

begin_struct
struct|struct
name|g_gate_hdr
block|{
name|uint8_t
name|gh_cmd
decl_stmt|;
comment|/* command */
name|uint64_t
name|gh_offset
decl_stmt|;
comment|/* device offset */
name|uint32_t
name|gh_length
decl_stmt|;
comment|/* size of block */
name|int16_t
name|gh_error
decl_stmt|;
comment|/* error value (0 if ok) */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|g_gate_vlog
parameter_list|(
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_gate_log
parameter_list|(
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_gate_xvlog
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_gate_xlog
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|g_gate_mediasize
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|g_gate_sectorsize
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_gate_open_device
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_gate_close_device
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_gate_ioctl
parameter_list|(
name|unsigned
name|long
name|req
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_gate_destroy
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_gate_openflags
parameter_list|(
name|unsigned
name|ggflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_gate_load_module
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|LIBGEOM
end_ifdef

begin_function_decl
name|void
name|g_gate_list
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|in_addr_t
name|g_gate_str2ip
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * g_gate_swap2h_* - functions swap bytes to host byte order (from big endian).  * g_gate_swap2n_* - functions swap bytes to network byte order (actually  *                   to big endian byte order).  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|g_gate_swap2h_cinit
parameter_list|(
name|struct
name|g_gate_cinit
modifier|*
name|cinit
name|__unused
parameter_list|)
block|{
comment|/* Nothing here for now. */
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|g_gate_swap2n_cinit
parameter_list|(
name|struct
name|g_gate_cinit
modifier|*
name|cinit
name|__unused
parameter_list|)
block|{
comment|/* Nothing here for now. */
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|g_gate_swap2h_sinit
parameter_list|(
name|struct
name|g_gate_sinit
modifier|*
name|sinit
parameter_list|)
block|{
comment|/* Swap only used fields. */
name|sinit
operator|->
name|gs_mediasize
operator|=
name|be64toh
argument_list|(
name|sinit
operator|->
name|gs_mediasize
argument_list|)
expr_stmt|;
name|sinit
operator|->
name|gs_sectorsize
operator|=
name|be32toh
argument_list|(
name|sinit
operator|->
name|gs_sectorsize
argument_list|)
expr_stmt|;
name|sinit
operator|->
name|gs_error
operator|=
name|be16toh
argument_list|(
name|sinit
operator|->
name|gs_error
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|g_gate_swap2n_sinit
parameter_list|(
name|struct
name|g_gate_sinit
modifier|*
name|sinit
parameter_list|)
block|{
comment|/* Swap only used fields. */
name|sinit
operator|->
name|gs_mediasize
operator|=
name|htobe64
argument_list|(
name|sinit
operator|->
name|gs_mediasize
argument_list|)
expr_stmt|;
name|sinit
operator|->
name|gs_sectorsize
operator|=
name|htobe32
argument_list|(
name|sinit
operator|->
name|gs_sectorsize
argument_list|)
expr_stmt|;
name|sinit
operator|->
name|gs_error
operator|=
name|htobe16
argument_list|(
name|sinit
operator|->
name|gs_error
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|g_gate_swap2h_hdr
parameter_list|(
name|struct
name|g_gate_hdr
modifier|*
name|hdr
parameter_list|)
block|{
comment|/* Swap only used fields. */
name|hdr
operator|->
name|gh_offset
operator|=
name|be64toh
argument_list|(
name|hdr
operator|->
name|gh_offset
argument_list|)
expr_stmt|;
name|hdr
operator|->
name|gh_length
operator|=
name|be32toh
argument_list|(
name|hdr
operator|->
name|gh_length
argument_list|)
expr_stmt|;
name|hdr
operator|->
name|gh_error
operator|=
name|be16toh
argument_list|(
name|hdr
operator|->
name|gh_error
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|g_gate_swap2n_hdr
parameter_list|(
name|struct
name|g_gate_hdr
modifier|*
name|hdr
parameter_list|)
block|{
comment|/* Swap only used fields. */
name|hdr
operator|->
name|gh_offset
operator|=
name|htobe64
argument_list|(
name|hdr
operator|->
name|gh_offset
argument_list|)
expr_stmt|;
name|hdr
operator|->
name|gh_length
operator|=
name|htobe32
argument_list|(
name|hdr
operator|->
name|gh_length
argument_list|)
expr_stmt|;
name|hdr
operator|->
name|gh_error
operator|=
name|htobe16
argument_list|(
name|hdr
operator|->
name|gh_error
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GGATE_H_ */
end_comment

end_unit

