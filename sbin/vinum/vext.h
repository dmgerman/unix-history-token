begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Nan Yang Computer Services Limited  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed for the NetBSD Project  *      by Jason R. Thorpe.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: vext.h,v 1.9 1998/08/11 03:06:02 grog Exp grog $ */
end_comment

begin_define
define|#
directive|define
name|MAXARGS
value|64
end_define

begin_comment
comment|/* maximum number of args on a line */
end_comment

begin_define
define|#
directive|define
name|PLEXINITSIZE
value|MAXPHYS
end_define

begin_comment
comment|/* block size to write when initializing */
end_comment

begin_enum
enum|enum
block|{
name|KILOBYTE
init|=
literal|1024
block|,
name|MEGABYTE
init|=
literal|1048576
block|,
name|GIGABYTE
init|=
literal|1073741824
block|}
enum|;
end_enum

begin_comment
comment|/* Prototype declarations */
end_comment

begin_function_decl
name|void
name|parseline
parameter_list|(
name|int
name|c
parameter_list|,
name|char
modifier|*
name|args
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* parse a line with c parameters at args */
end_comment

begin_function_decl
name|void
name|checkentry
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|haveargs
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check arg, error message if not valid */
end_comment

begin_function_decl
name|void
name|vinum_create
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_read
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_modify
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_volume
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_plex
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_sd
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_drive
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_list
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_info
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_set
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_rm
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_init
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_resetconfig
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_start
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|continue_revive
parameter_list|(
name|int
name|plexno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_stop
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_volume_stats
parameter_list|(
name|int
name|volno
parameter_list|,
name|int
name|recurse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_plex_stats
parameter_list|(
name|int
name|plexno
parameter_list|,
name|int
name|recurse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_sd_stats
parameter_list|(
name|int
name|sdno
parameter_list|,
name|int
name|recurse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_drive_stats
parameter_list|(
name|int
name|driveno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_resetstats
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_attach
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_detach
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_rename
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_rename_2
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_replace
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_printconfig
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_label
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_ld
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_ls
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_lp
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_lv
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
name|void
name|vinum_debug
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|make_devices
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_drive_info
parameter_list|(
name|struct
name|drive
modifier|*
name|drive
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_sd_info
parameter_list|(
name|struct
name|sd
modifier|*
name|sd
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_plex_sd_info
parameter_list|(
name|struct
name|sd
modifier|*
name|sd
parameter_list|,
name|int
name|plexno
parameter_list|,
name|int
name|sdno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_plex_info
parameter_list|(
name|struct
name|plex
modifier|*
name|plex
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_volume_info
parameter_list|(
name|struct
name|volume
modifier|*
name|volume
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_object
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|enum
name|objecttype
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|lltoa
parameter_list|(
name|long
name|long
name|l
parameter_list|,
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_ldi
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_lvi
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_lpi
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_lsi
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vinum_li
parameter_list|(
name|int
name|object
parameter_list|,
name|enum
name|objecttype
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|roughlength
parameter_list|(
name|long
name|long
name|bytes
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|sizespec
parameter_list|(
name|char
modifier|*
name|spec
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|force
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 to force some dangerous ops */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set verbose operation */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* very verbose operation */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|recurse
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set recursion */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stats
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show statistics */
end_comment

begin_comment
comment|/* Structures to read kernel data into */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|_vinum_conf
name|vinum_conf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration information */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|volume
name|vol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|plex
name|plex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sd
name|sd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|drive
name|drive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|command_fail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return on a failed command */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|superdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vinum super device */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stdin line number for error messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|file_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and line in input file (yes, this is tacky) */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|buffer
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer to read in to */
end_comment

end_unit

