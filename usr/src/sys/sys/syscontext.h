begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)syscontext.h	7.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<user.h>
end_include

begin_comment
comment|/*  * This file defines the context necessary to do a system call.  * For the time being it just selects fields from the user structure.  */
end_comment

begin_define
define|#
directive|define
name|syscontext
value|user
end_define

begin_define
define|#
directive|define
name|sc_ap
value|u_ap
end_define

begin_define
define|#
directive|define
name|sc_nd
value|u_nd
end_define

begin_define
define|#
directive|define
name|sc_retval1
value|u_r.u_rv.R_val1
end_define

begin_define
define|#
directive|define
name|sc_retval2
value|u_r.u_rv.R_val2
end_define

begin_define
define|#
directive|define
name|sc_offset
value|u_r.r_off
end_define

begin_define
define|#
directive|define
name|sc_cdir
value|u_nd.ni_cdir
end_define

begin_define
define|#
directive|define
name|sc_rdir
value|u_nd.ni_rdir
end_define

begin_define
define|#
directive|define
name|sc_cred
value|u_nd.ni_cred
end_define

begin_define
define|#
directive|define
name|sc_uid
value|u_nd.ni_cred->cr_uid
end_define

begin_define
define|#
directive|define
name|sc_gid
value|u_nd.ni_cred->cr_groups[0]
end_define

begin_define
define|#
directive|define
name|sc_ruid
value|u_nd.ni_cred->cr_ruid
end_define

begin_define
define|#
directive|define
name|sc_rgid
value|u_rgid
end_define

begin_define
define|#
directive|define
name|sc_groups
value|u_nd.ni_cred->cr_groups
end_define

begin_define
define|#
directive|define
name|sc_ngroups
value|u_nd.ni_cred->cr_ngroups
end_define

begin_define
define|#
directive|define
name|sc_acflag
value|u_acflag
end_define

begin_define
define|#
directive|define
name|sc_cmask
value|u_cmask
end_define

begin_define
define|#
directive|define
name|sc_ofile
value|u_ofile
end_define

begin_define
define|#
directive|define
name|RETURN
parameter_list|(
name|value
parameter_list|)
value|{ u.u_error = (value); return; }
end_define

end_unit

