begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995-1997 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  $Id: saver.h,v 1.4.2.1 1997/09/02 10:36:40 yokota Exp $  */
end_comment

begin_include
include|#
directive|include
file|<machine/apm_bios.h>
end_include

begin_include
include|#
directive|include
file|<machine/console.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/syscons.h>
end_include

begin_decl_stmt
specifier|extern
name|scr_stat
modifier|*
name|cur_console
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
modifier|*
name|Crtat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|crtc_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|crtc_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|scr_map
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scrn_blanked
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fonts_loaded
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|font_8
index|[]
decl_stmt|,
name|font_14
index|[]
decl_stmt|,
name|font_16
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|palette
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|video_mode_ptr
decl_stmt|;
end_decl_stmt

end_unit

