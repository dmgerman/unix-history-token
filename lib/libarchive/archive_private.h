begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_PRIVATE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_PRIVATE_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|"archive.h"
end_include

begin_include
include|#
directive|include
file|"archive_string.h"
end_include

begin_define
define|#
directive|define
name|ARCHIVE_WRITE_MAGIC
value|(0xb0c5c0deU)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_READ_MAGIC
value|(0xdeb0c5U)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_WRITE_DISK_MAGIC
value|(0xc001b0c5U)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STATE_ANY
value|0xFFFFU
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STATE_NEW
value|1U
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STATE_HEADER
value|2U
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STATE_DATA
value|4U
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STATE_DATA_END
value|8U
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STATE_EOF
value|0x10U
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STATE_CLOSED
value|0x20U
end_define

begin_define
define|#
directive|define
name|ARCHIVE_STATE_FATAL
value|0x8000U
end_define

begin_struct
struct|struct
name|archive_vtable
block|{
name|int
function_decl|(
modifier|*
name|archive_write_close
function_decl|)
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|archive_write_finish
function_decl|)
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|archive_write_header
function_decl|)
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|archive_write_finish_entry
function_decl|)
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
name|ssize_t
function_decl|(
modifier|*
name|archive_write_data
function_decl|)
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|ssize_t
function_decl|(
modifier|*
name|archive_write_data_block
function_decl|)
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|archive
block|{
comment|/* 	 * The magic/state values are used to sanity-check the 	 * client's usage.  If an API function is called at a 	 * ridiculous time, or the client passes us an invalid 	 * pointer, these values allow me to catch that. 	 */
name|unsigned
name|int
name|magic
decl_stmt|;
name|unsigned
name|int
name|state
decl_stmt|;
comment|/* 	 * Some public API functions depend on the "real" type of the 	 * archive object. 	 */
name|struct
name|archive_vtable
modifier|*
name|vtable
decl_stmt|;
name|int
name|archive_format
decl_stmt|;
specifier|const
name|char
modifier|*
name|archive_format_name
decl_stmt|;
name|int
name|compression_code
decl_stmt|;
comment|/* Currently active compression. */
specifier|const
name|char
modifier|*
name|compression_name
decl_stmt|;
comment|/* Position in UNCOMPRESSED data stream. */
name|off_t
name|file_position
decl_stmt|;
comment|/* Position in COMPRESSED data stream. */
name|off_t
name|raw_position
decl_stmt|;
name|int
name|archive_error_number
decl_stmt|;
specifier|const
name|char
modifier|*
name|error
decl_stmt|;
name|struct
name|archive_string
name|error_string
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Check magic value and state; exit if it isn't valid. */
end_comment

begin_function_decl
name|void
name|__archive_check_magic
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|unsigned
name|int
name|magic
parameter_list|,
name|unsigned
name|int
name|state
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__archive_errx
parameter_list|(
name|int
name|retvalue
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|err_combine
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

