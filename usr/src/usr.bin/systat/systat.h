begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1989, 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)systat.h	5.10 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
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
name|void
function_decl|(
modifier|*
name|c_refresh
function_decl|)
parameter_list|()
function_decl|;
comment|/* display refresh */
name|void
function_decl|(
modifier|*
name|c_fetch
function_decl|)
parameter_list|()
function_decl|;
comment|/* sets up data structures */
name|void
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
name|void
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
value|namelist[(indx)].n_value
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

