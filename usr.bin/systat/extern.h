begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)extern.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<kvm.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|cmdtab
modifier|*
name|curcmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cmdtab
name|cmdtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|text
modifier|*
name|xtext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|wnd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|dr_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|c
decl_stmt|,
modifier|*
name|namp
decl_stmt|,
name|hostname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
modifier|*
name|dk_mspw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|kvm_t
modifier|*
name|kd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|ntext
decl_stmt|,
name|textp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|dk_select
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|CMDLINE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dk_ndrive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hz
decl_stmt|,
name|stathz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|hertz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sampling frequency for cp_time and dk_time */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|naptime
decl_stmt|,
name|col
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nhosts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nports
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|protos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|device_selection
modifier|*
name|dev_select
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|generation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_devices
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_selected
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_selections
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|select_generation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nlist
name|namelist
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|checkhost
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|checkport
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closeiostat
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closeicmp
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closeip
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closekre
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closembufs
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closenetstat
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closepigs
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closeswap
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closetcp
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmdiostat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmdkre
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmdnetstat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cmdtab
modifier|*
name|lookup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|command
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|die
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dkinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dkcmd
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
name|error
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|fetchicmp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fetchip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fetchiostat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fetchkre
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fetchmbufs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fetchnetstat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fetchpigs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fetchswap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fetchtcp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getsysctl
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initicmp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initiostat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initkre
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initmbufs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initnetstat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initpigs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initswap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inittcp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|keyboard
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kvm_ckread
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|labelicmp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|labelip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|labeliostat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|labelkre
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|labelmbufs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|labelnetstat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|labelpigs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|labels
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|labelswap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|labeltcp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netcmd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlisterr
parameter_list|(
name|struct
name|nlist
type|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|WINDOW
modifier|*
name|openicmp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|WINDOW
modifier|*
name|openip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|WINDOW
modifier|*
name|openiostat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|WINDOW
modifier|*
name|openkre
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|WINDOW
modifier|*
name|openmbufs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|WINDOW
modifier|*
name|opennetstat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|WINDOW
modifier|*
name|openpigs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|WINDOW
modifier|*
name|openswap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|WINDOW
modifier|*
name|opentcp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prefix
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reseticmp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resetip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resettcp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|showicmp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|showip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|showiostat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|showkre
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|showmbufs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|shownetstat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|showpigs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|showswap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|showtcp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|status
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|suspend
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sysctl_dynread
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

