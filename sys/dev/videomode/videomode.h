begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: videomode.h,v 1.2 2010/05/04 21:17:10 macallan Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001, 2002 Bang Jun-Young  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_VIDEOMODE_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_VIDEOMODE_H
end_define

begin_struct
struct|struct
name|videomode
block|{
name|int
name|dot_clock
decl_stmt|;
comment|/* Dot clock frequency in kHz. */
name|int
name|hdisplay
decl_stmt|;
name|int
name|hsync_start
decl_stmt|;
name|int
name|hsync_end
decl_stmt|;
name|int
name|htotal
decl_stmt|;
name|int
name|vdisplay
decl_stmt|;
name|int
name|vsync_start
decl_stmt|;
name|int
name|vsync_end
decl_stmt|;
name|int
name|vtotal
decl_stmt|;
name|int
name|flags
decl_stmt|;
comment|/* Video mode flags; see below. */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Video mode flags.  */
end_comment

begin_define
define|#
directive|define
name|VID_PHSYNC
value|0x0001
end_define

begin_define
define|#
directive|define
name|VID_NHSYNC
value|0x0002
end_define

begin_define
define|#
directive|define
name|VID_PVSYNC
value|0x0004
end_define

begin_define
define|#
directive|define
name|VID_NVSYNC
value|0x0008
end_define

begin_define
define|#
directive|define
name|VID_INTERLACE
value|0x0010
end_define

begin_define
define|#
directive|define
name|VID_DBLSCAN
value|0x0020
end_define

begin_define
define|#
directive|define
name|VID_CSYNC
value|0x0040
end_define

begin_define
define|#
directive|define
name|VID_PCSYNC
value|0x0080
end_define

begin_define
define|#
directive|define
name|VID_NCSYNC
value|0x0100
end_define

begin_define
define|#
directive|define
name|VID_HSKEW
value|0x0200
end_define

begin_define
define|#
directive|define
name|VID_BCAST
value|0x0400
end_define

begin_define
define|#
directive|define
name|VID_PIXMUX
value|0x1000
end_define

begin_define
define|#
directive|define
name|VID_DBLCLK
value|0x2000
end_define

begin_define
define|#
directive|define
name|VID_CLKDIV2
value|0x4000
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|videomode
name|videomode_list
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|videomode_count
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|struct
name|videomode
modifier|*
name|pick_mode_by_dotclock
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|videomode
modifier|*
name|pick_mode_by_ref
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sort_modes
parameter_list|(
name|struct
name|videomode
modifier|*
parameter_list|,
name|struct
name|videomode
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_VIDEOMODE_H */
end_comment

end_unit

