begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Video spigot capture driver.  *  * Copyright (c) 1995, Jim Lowe.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met: 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer. 2.  * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Version 1.2, Aug 30, 1995.  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SPIGOT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SPIGOT_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|spigot_info
block|{
name|unsigned
name|long
name|maddr
decl_stmt|;
name|unsigned
name|short
name|irq
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Get memory address.  */
end_comment

begin_define
define|#
directive|define
name|SPIGOT_GET_INFO
value|_IOR('s', 4, struct spigot_info)
end_define

begin_comment
comment|/*  * Set up a user interrupt.  */
end_comment

begin_define
define|#
directive|define
name|SPIGOT_SETINT
value|_IOW('s', 5, int)
end_define

begin_comment
comment|/*  * Allow/disallow access to the I/O Page.  */
end_comment

begin_define
define|#
directive|define
name|SPIGOT_IOPL_ON
value|_IO ('s', 6)
end_define

begin_define
define|#
directive|define
name|SPIGOT_IOPL_OFF
value|_IO ('s', 7)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/*  * Defines for spigot library.  */
end_comment

begin_function_decl
name|unsigned
name|short
modifier|*
name|spigot_open
parameter_list|(
name|char
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spigot_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spigot_set_capture_size
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|vtof
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|spigot_start_xfer
parameter_list|(
name|int
name|num_frames
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spigot_stop_xfer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|spigot_status
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Define the status bits.  */
end_comment

begin_define
define|#
directive|define
name|SPIGOT_COLOR
value|0x01
end_define

begin_comment
comment|/* Color present (No color) */
end_comment

begin_define
define|#
directive|define
name|SPIGOT_60HZ
value|0x02
end_define

begin_comment
comment|/* 60 hz input signal (50hz) */
end_comment

begin_define
define|#
directive|define
name|SPIGOT_NO_HORIZONTAL_LOCK
value|0x04
end_define

begin_comment
comment|/* Horizontal lock present */
end_comment

begin_define
define|#
directive|define
name|SPIGOT_HPLL_LOCKED
value|0x08
end_define

begin_comment
comment|/* HPLL locked (HPLL unlocked)*/
end_comment

begin_define
define|#
directive|define
name|SPIGOT_VCR_MODE
value|0x10
end_define

begin_comment
comment|/* VCR mode (TV mode) */
end_comment

begin_define
define|#
directive|define
name|SPIGOT_VSYNC_PRESENT
value|0x20
end_define

begin_comment
comment|/* Vsync present */
end_comment

begin_comment
comment|/*  * spigot_open() returns a data address pointing to the spigot data.  * Each read from this address returns the next word.  The ``dev'' passed  * is usually "/dev/spigot".  Data is described in the phillips desktop  * video data handbook under the 7191 chip.  Formats may be either  * YUV 4:2:2 or YUV 4:1:1.  A sample device driver for ``nv'' is included  * with this code.  *  * spigot_close() cleans up and closes the device.  *  * spigot_set_capture_size() will set the capture window size.  Width should be  * one of:	80, 160, 240, 320, or 640 for NTSC or  *		96, 192, 288, 384 for PAL.  * vtof is the Vertical top of frame offset and must be between 0 and 15 lines.  *  * spigot_start_xfer() will start a transfer from the 7191 to the data fifo.  * spigot_stop_xfer() will clear the data fifo and abort any transfers.  *  * spigot_status() will return the above status bits.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SPIGOT_H_ */
end_comment

end_unit

