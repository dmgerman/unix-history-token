begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* trace.h     Definitions for omapi tracing facility... */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Internet Software Consortium.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names  *    of its contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE INTERNET SOFTWARE CONSORTIUM OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This software has been written for the Internet Software Consortium  * by Ted Lemon, as part of a project for Nominum, Inc.   To learn more  * about the Internet Software Consortium, see http://www.isc.org/.  To  * learn more about Nominum, Inc., see ``http://www.nominum.com''.  */
end_comment

begin_define
define|#
directive|define
name|TRACEFILE_MAGIC
value|0x64484370UL
end_define

begin_comment
comment|/* dHCp */
end_comment

begin_define
define|#
directive|define
name|TRACEFILE_VERSION
value|1
end_define

begin_comment
comment|/* The first thing in a trace file is the header, which basically just     defines the version of the file. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|magic
decl_stmt|;
comment|/* Magic number for trace file. */
name|u_int32_t
name|version
decl_stmt|;
comment|/* Version of file. */
name|int32_t
name|hlen
decl_stmt|;
comment|/* Length of this header. */
name|int32_t
name|phlen
decl_stmt|;
comment|/* Length of packet headers. */
block|}
name|tracefile_header_t
typedef|;
end_typedef

begin_comment
comment|/* The trace file is composed of a bunch of trace packets.   Each such packet    has a type, followed by a length, followed by a timestamp, followed by    the actual contents of the packet.   The type indexes are not fixed -    they are allocated either on readback or when writing a trace file.    One index type is reserved - type zero means that this record is a type    name to index mapping. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|type_index
decl_stmt|;
comment|/* Index to the type of handler that this 				   packet needs. */
name|u_int32_t
name|length
decl_stmt|;
comment|/* Length of the packet.  This includes 				   everything except the fixed header. */
name|u_int32_t
name|when
decl_stmt|;
comment|/* When the packet was written. */
name|u_int32_t
name|pad
decl_stmt|;
comment|/* Round this out to a quad boundary. */
block|}
name|tracepacket_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TRACE_INDEX_MAPPING_SIZE
value|4
end_define

begin_comment
comment|/* trace_index_mapping_t less name. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|index
decl_stmt|;
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
block|}
name|trace_index_mapping_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|trace_type
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward */
end_comment

begin_typedef
typedef|typedef
name|struct
name|trace_type
name|trace_type_t
typedef|;
end_typedef

begin_struct
struct|struct
name|trace_type
block|{
name|trace_type_t
modifier|*
name|next
decl_stmt|;
name|int
name|index
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
name|baggage
decl_stmt|;
name|void
function_decl|(
modifier|*
name|have_packet
function_decl|)
parameter_list|(
name|trace_type_t
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|stop_tracing
function_decl|)
parameter_list|(
name|trace_type_t
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|trace_iov
block|{
specifier|const
name|char
modifier|*
name|buf
decl_stmt|;
name|unsigned
name|len
decl_stmt|;
block|}
name|trace_iov_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|addrtype
decl_stmt|;
name|u_int16_t
name|addrlen
decl_stmt|;
name|u_int8_t
name|address
index|[
literal|16
index|]
decl_stmt|;
name|u_int16_t
name|port
decl_stmt|;
block|}
name|trace_addr_t
typedef|;
end_typedef

begin_function_decl
name|void
name|trace_free_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|trace_playback
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|trace_record
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|trace_init
parameter_list|(
name|void
function_decl|(
modifier|*
name|set_time
function_decl|)
parameter_list|(
name|u_int32_t
parameter_list|)
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
name|trace_begin
parameter_list|(
specifier|const
name|char
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
name|trace_write_packet
parameter_list|(
name|trace_type_t
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
specifier|const
name|char
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
name|trace_write_packet_iov
parameter_list|(
name|trace_type_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|trace_iov_t
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
name|void
name|trace_type_stash
parameter_list|(
name|trace_type_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|trace_type_t
modifier|*
name|trace_type_register
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|trace_type_t
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|char
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|trace_type_t
modifier|*
parameter_list|)
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
name|void
name|trace_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trace_index_map_input
parameter_list|(
name|trace_type_t
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trace_index_stop_tracing
parameter_list|(
name|trace_type_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trace_replay_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trace_file_replay
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|trace_get_next_packet
parameter_list|(
name|trace_type_t
modifier|*
modifier|*
parameter_list|,
name|tracepacket_t
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|unsigned
modifier|*
parameter_list|,
name|unsigned
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|trace_get_file
parameter_list|(
name|trace_type_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|trace_get_packet
parameter_list|(
name|trace_type_t
modifier|*
modifier|*
parameter_list|,
name|unsigned
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|trace_snoop_time
parameter_list|(
name|trace_type_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

