begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2012, Broadcom Europe Ltd  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *    1. Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *    3. Neither the name of the copyright holder nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VC_AUDIO_DEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_VC_AUDIO_DEFS_H_
end_define

begin_define
define|#
directive|define
name|VC_AUDIOSERV_MIN_VER
value|1
end_define

begin_define
define|#
directive|define
name|VC_AUDIOSERV_VER
value|2
end_define

begin_comment
comment|/* FourCC code used for VCHI connection */
end_comment

begin_define
define|#
directive|define
name|VC_AUDIO_SERVER_NAME
value|MAKE_FOURCC("AUDS")
end_define

begin_comment
comment|/* Maximum message length */
end_comment

begin_define
define|#
directive|define
name|VC_AUDIO_MAX_MSG_LEN
value|(sizeof( VC_AUDIO_MSG_T ))
end_define

begin_comment
comment|/*   * List of screens that are currently supported  * All message types supported for HOST->VC direction  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|VC_AUDIO_MSG_TYPE_RESULT
block|,
comment|/* Generic result */
name|VC_AUDIO_MSG_TYPE_COMPLETE
block|,
comment|/* playback of samples complete */
name|VC_AUDIO_MSG_TYPE_CONFIG
block|,
comment|/* Configure */
name|VC_AUDIO_MSG_TYPE_CONTROL
block|,
comment|/* control  */
name|VC_AUDIO_MSG_TYPE_OPEN
block|,
comment|/*  open */
name|VC_AUDIO_MSG_TYPE_CLOSE
block|,
comment|/* close/shutdown */
name|VC_AUDIO_MSG_TYPE_START
block|,
comment|/* start output (i.e. resume) */
name|VC_AUDIO_MSG_TYPE_STOP
block|,
comment|/* stop output (i.e. pause) */
name|VC_AUDIO_MSG_TYPE_WRITE
block|,
comment|/* write samples */
name|VC_AUDIO_MSG_TYPE_MAX
block|}
name|VC_AUDIO_MSG_TYPE
typedef|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|vc_audio_msg_type_names
index|[]
init|=
block|{
literal|"VC_AUDIO_MSG_TYPE_RESULT"
block|,
literal|"VC_AUDIO_MSG_TYPE_COMPLETE"
block|,
literal|"VC_AUDIO_MSG_TYPE_CONFIG"
block|,
literal|"VC_AUDIO_MSG_TYPE_CONTROL"
block|,
literal|"VC_AUDIO_MSG_TYPE_OPEN"
block|,
literal|"VC_AUDIO_MSG_TYPE_CLOSE"
block|,
literal|"VC_AUDIO_MSG_TYPE_START"
block|,
literal|"VC_AUDIO_MSG_TYPE_STOP"
block|,
literal|"VC_AUDIO_MSG_TYPE_WRITE"
block|,
literal|"VC_AUDIO_MSG_TYPE_MAX"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configure the audio */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|channels
decl_stmt|;
name|uint32_t
name|samplerate
decl_stmt|;
name|uint32_t
name|bps
decl_stmt|;
block|}
name|VC_AUDIO_CONFIG_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|volume
decl_stmt|;
name|uint32_t
name|dest
decl_stmt|;
block|}
name|VC_AUDIO_CONTROL_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|dummy
decl_stmt|;
block|}
name|VC_AUDIO_OPEN_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|dummy
decl_stmt|;
block|}
name|VC_AUDIO_CLOSE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|dummy
decl_stmt|;
block|}
name|VC_AUDIO_START_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|draining
decl_stmt|;
block|}
name|VC_AUDIO_STOP_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|count
decl_stmt|;
comment|/* in bytes */
name|void
modifier|*
name|callback
decl_stmt|;
name|void
modifier|*
name|cookie
decl_stmt|;
name|uint16_t
name|silence
decl_stmt|;
name|uint16_t
name|max_packet
decl_stmt|;
block|}
name|VC_AUDIO_WRITE_T
typedef|;
end_typedef

begin_comment
comment|/* Generic result for a request (VC->HOST) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|success
decl_stmt|;
comment|/* Success value */
block|}
name|VC_AUDIO_RESULT_T
typedef|;
end_typedef

begin_comment
comment|/* Generic result for a request (VC->HOST) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|count
decl_stmt|;
comment|/* Success value */
name|void
modifier|*
name|callback
decl_stmt|;
name|void
modifier|*
name|cookie
decl_stmt|;
block|}
name|VC_AUDIO_COMPLETE_T
typedef|;
end_typedef

begin_comment
comment|/* Message header for all messages in HOST->VC direction */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|type
decl_stmt|;
comment|/* Message type (VC_AUDIO_MSG_TYPE) */
union|union
block|{
name|VC_AUDIO_CONFIG_T
name|config
decl_stmt|;
name|VC_AUDIO_CONTROL_T
name|control
decl_stmt|;
name|VC_AUDIO_OPEN_T
name|open
decl_stmt|;
name|VC_AUDIO_CLOSE_T
name|close
decl_stmt|;
name|VC_AUDIO_START_T
name|start
decl_stmt|;
name|VC_AUDIO_STOP_T
name|stop
decl_stmt|;
name|VC_AUDIO_WRITE_T
name|write
decl_stmt|;
name|VC_AUDIO_RESULT_T
name|result
decl_stmt|;
name|VC_AUDIO_COMPLETE_T
name|complete
decl_stmt|;
block|}
name|u
union|;
block|}
name|VC_AUDIO_MSG_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VC_AUDIO_DEFS_H_ */
end_comment

end_unit

