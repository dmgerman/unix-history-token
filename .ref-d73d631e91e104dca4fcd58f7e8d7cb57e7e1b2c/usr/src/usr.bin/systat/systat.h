begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1989 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)systat.h	5.4 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/dkstat.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_struct
struct|struct
name|p_times
block|{
name|short
name|pt_pid
decl_stmt|;
name|float
name|pt_pctcpu
decl_stmt|;
name|int
name|pt_uid
decl_stmt|;
name|int
name|pt_paddr
decl_stmt|;
name|struct
name|proc
modifier|*
name|pt_pp
decl_stmt|;
block|}
modifier|*
name|pt
struct|;
end_struct

begin_decl_stmt
name|long
name|nproc
decl_stmt|,
name|procp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|kprocp
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|procs
block|{
name|int
name|pid
decl_stmt|;
name|char
name|cmd
index|[
literal|16
index|]
decl_stmt|;
block|}
name|procs
index|[
literal|200
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|numprocs
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|users
block|{
name|int
name|k_uid
decl_stmt|;
name|char
name|k_name
index|[
literal|16
index|]
decl_stmt|;
block|}
name|known
index|[
literal|30
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|numknown
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|cmdtab
block|{
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/* command name */
name|int
function_decl|(
modifier|*
name|c_refresh
function_decl|)
parameter_list|()
function_decl|;
comment|/* display refresh */
name|int
function_decl|(
modifier|*
name|c_fetch
function_decl|)
parameter_list|()
function_decl|;
comment|/* sets up data structures */
name|int
function_decl|(
modifier|*
name|c_label
function_decl|)
parameter_list|()
function_decl|;
comment|/* label display */
name|int
function_decl|(
modifier|*
name|c_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* initialize namelist, etc. */
name|WINDOW
modifier|*
function_decl|(
modifier|*
name|c_open
function_decl|)
parameter_list|()
function_decl|;
comment|/* open display */
name|int
function_decl|(
modifier|*
name|c_close
function_decl|)
parameter_list|()
function_decl|;
comment|/* close display */
name|int
function_decl|(
modifier|*
name|c_cmd
function_decl|)
parameter_list|()
function_decl|;
comment|/* display command interpreter */
name|char
name|c_flags
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CF_INIT
value|0x1
end_define

begin_comment
comment|/* been initialized */
end_comment

begin_define
define|#
directive|define
name|CF_LOADAV
value|0x2
end_define

begin_comment
comment|/* display w/ load average */
end_comment

begin_decl_stmt
name|struct
name|cmdtab
modifier|*
name|curcmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cmdtab
name|cmdtab
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|cmdtab
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|kmem
decl_stmt|,
name|mem
decl_stmt|,
name|swap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|naptime
decl_stmt|,
name|col
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|ntext
decl_stmt|,
name|textp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|text
modifier|*
name|xtext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fscale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|lccpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kmemf
decl_stmt|,
modifier|*
name|memf
decl_stmt|,
modifier|*
name|swapf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hz
decl_stmt|,
name|phz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|dr_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dk_ndrive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|dk_select
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
modifier|*
name|dk_mspw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|c
decl_stmt|,
modifier|*
name|namp
decl_stmt|,
name|hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nports
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nhosts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|protos
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TCP
value|0x1
end_define

begin_define
define|#
directive|define
name|UDP
value|0x2
end_define

begin_decl_stmt
name|struct
name|pte
modifier|*
name|usrpt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
modifier|*
name|Usrptma
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|wnd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CMDLINE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|calloc
argument_list|()
decl_stmt|,
modifier|*
name|strncpy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|getw
parameter_list|()
function_decl|;
end_function_decl

end_unit

