begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Mikael Hybsch  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCD_H
end_ifndef

begin_define
define|#
directive|define
name|SCD_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|char
name|bcd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|M_msf
parameter_list|(
name|msf
parameter_list|)
value|msf[0]
end_define

begin_define
define|#
directive|define
name|S_msf
parameter_list|(
name|msf
parameter_list|)
value|msf[1]
end_define

begin_define
define|#
directive|define
name|F_msf
parameter_list|(
name|msf
parameter_list|)
value|msf[2]
end_define

begin_define
define|#
directive|define
name|IS_ATTENTION
parameter_list|(
name|port
parameter_list|)
value|((inb(port+IREG_STATUS)& SBIT_ATTENTION) != 0)
end_define

begin_define
define|#
directive|define
name|IS_BUSY
parameter_list|(
name|port
parameter_list|)
value|((inb(port+IREG_STATUS)& SBIT_BUSY) != 0)
end_define

begin_define
define|#
directive|define
name|IS_DATA_RDY
parameter_list|(
name|port
parameter_list|)
value|((inb(port+IREG_STATUS)& SBIT_DATA_READY) != 0)
end_define

begin_define
define|#
directive|define
name|STATUS_BIT
parameter_list|(
name|port
parameter_list|,
name|bit
parameter_list|)
value|((inb(port+IREG_STATUS)& (bit)) != 0)
end_define

begin_define
define|#
directive|define
name|FSTATUS_BIT
parameter_list|(
name|port
parameter_list|,
name|bit
parameter_list|)
value|((inb(port+IREG_FSTATUS)& (bit)) != 0)
end_define

begin_define
define|#
directive|define
name|OREG_COMMAND
value|0
end_define

begin_define
define|#
directive|define
name|OREG_WPARAMS
value|1
end_define

begin_define
define|#
directive|define
name|OREG_CONTROL
value|3
end_define

begin_define
define|#
directive|define
name|CBIT_ATTENTION_CLEAR
value|0x01
end_define

begin_define
define|#
directive|define
name|CBIT_RESULT_READY_CLEAR
value|0x02
end_define

begin_define
define|#
directive|define
name|CBIT_DATA_READY_CLEAR
value|0x04
end_define

begin_define
define|#
directive|define
name|CBIT_RPARAM_CLEAR
value|0x40
end_define

begin_define
define|#
directive|define
name|CBIT_RESET_DRIVE
value|0x80
end_define

begin_define
define|#
directive|define
name|IREG_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|SBIT_ATTENTION
value|0x01
end_define

begin_define
define|#
directive|define
name|SBIT_RESULT_READY
value|0x02
end_define

begin_define
define|#
directive|define
name|SBIT_DATA_READY
value|0x04
end_define

begin_define
define|#
directive|define
name|SBIT_BUSY
value|0x80
end_define

begin_define
define|#
directive|define
name|IREG_RESULT
value|1
end_define

begin_define
define|#
directive|define
name|IREG_DATA
value|2
end_define

begin_define
define|#
directive|define
name|IREG_FSTATUS
value|3
end_define

begin_define
define|#
directive|define
name|FBIT_WPARAM_READY
value|0x01
end_define

begin_define
define|#
directive|define
name|CMD_GET_DRIVE_CONFIG
value|0x00
end_define

begin_define
define|#
directive|define
name|CMD_SET_DRIVE_PARAM
value|0x10
end_define

begin_define
define|#
directive|define
name|CMD_GET_SUBCHANNEL_DATA
value|0x21
end_define

begin_define
define|#
directive|define
name|CMD_GET_TOC
value|0x24
end_define

begin_define
define|#
directive|define
name|CMD_READ_TOC
value|0x30
end_define

begin_define
define|#
directive|define
name|CMD_READ
value|0x34
end_define

begin_define
define|#
directive|define
name|CMD_PLAY_AUDIO
value|0x40
end_define

begin_define
define|#
directive|define
name|CMD_STOP_AUDIO
value|0x41
end_define

begin_define
define|#
directive|define
name|CMD_EJECT
value|0x50
end_define

begin_define
define|#
directive|define
name|CMD_SPIN_UP
value|0x51
end_define

begin_define
define|#
directive|define
name|CMD_SPIN_DOWN
value|0x52
end_define

begin_define
define|#
directive|define
name|ERR_CD_NOT_LOADED
value|0x20
end_define

begin_define
define|#
directive|define
name|ERR_NO_CD_INSIDE
value|0x21
end_define

begin_define
define|#
directive|define
name|ERR_NOT_SPINNING
value|0x22
end_define

begin_define
define|#
directive|define
name|ERR_FATAL_READ_ERROR1
value|0x53
end_define

begin_define
define|#
directive|define
name|ERR_FATAL_READ_ERROR2
value|0x57
end_define

begin_define
define|#
directive|define
name|ATTEN_DRIVE_LOADED
value|0x80
end_define

begin_define
define|#
directive|define
name|ATTEN_EJECT_PUSHED
value|0x81
end_define

begin_define
define|#
directive|define
name|ATTEN_AUDIO_DONE
value|0x90
end_define

begin_define
define|#
directive|define
name|ATTEN_SPIN_UP_DONE
value|0x24
end_define

begin_define
define|#
directive|define
name|ATTEN_SPIN_DOWN
value|0x27
end_define

begin_define
define|#
directive|define
name|ATTEN_EJECT_DONE
value|0x28
end_define

begin_struct
struct|struct
name|sony_drive_configuration
block|{
name|char
name|vendor
index|[
literal|8
index|]
decl_stmt|;
name|char
name|product
index|[
literal|16
index|]
decl_stmt|;
name|char
name|revision
index|[
literal|8
index|]
decl_stmt|;
name|u_short
name|config
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Almost same as cd_sub_channel_position_data */
end_comment

begin_struct
struct|struct
name|sony_subchannel_position_data
block|{
name|u_char
name|control
range|:
literal|4
decl_stmt|;
name|u_char
name|addr_type
range|:
literal|4
decl_stmt|;
name|u_char
name|track_number
decl_stmt|;
name|u_char
name|index_number
decl_stmt|;
name|u_char
name|rel_msf
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|dummy
decl_stmt|;
name|u_char
name|abs_msf
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sony_tracklist
block|{
name|u_char
name|adr
range|:
literal|4
decl_stmt|;
comment|/* xcdplayer needs these two values */
name|u_char
name|ctl
range|:
literal|4
decl_stmt|;
name|u_char
name|track
decl_stmt|;
name|u_char
name|start_msf
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_TRACKS
value|100
end_define

begin_struct
struct|struct
name|sony_toc
block|{
name|u_char
name|session_number
decl_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
name|first_track
decl_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
name|last_track
decl_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
name|lead_out_start_msf
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|sony_tracklist
name|tracks
index|[
name|MAX_TRACKS
index|]
decl_stmt|;
comment|/* The rest is just to take space in case all data is returned */
name|u_char
name|dummy
index|[
literal|6
operator|*
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCD_H */
end_comment

end_unit

