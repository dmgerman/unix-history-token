begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1989 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)systat.h	5.6 (Berkeley) %G%  */
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
name|double
name|avenrun
index|[
literal|3
index|]
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

begin_define
define|#
directive|define
name|KREAD
parameter_list|(
name|addr
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
value|kvm_ckread((addr), (buf), (len))
end_define

begin_define
define|#
directive|define
name|NVAL
parameter_list|(
name|indx
parameter_list|)
value|nlst[(indx)].n_value
end_define

begin_define
define|#
directive|define
name|NPTR
parameter_list|(
name|indx
parameter_list|)
value|(void *)NVAL((indx))
end_define

begin_define
define|#
directive|define
name|NREAD
parameter_list|(
name|indx
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
value|kvm_ckread(NPTR((indx)), (buf), (len))
end_define

begin_define
define|#
directive|define
name|LONG
value|(sizeof (long))
end_define

end_unit

