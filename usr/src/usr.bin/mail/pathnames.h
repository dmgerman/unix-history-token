begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)pathnames.h	5.6 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Declarations and constants specific to an installation.  *  * Vax/Unix version 7.  */
end_comment

begin_define
define|#
directive|define
name|SENDMAIL
value|"/usr/lib/sendmail"
end_define

begin_comment
comment|/* Name of classy mail deliverer */
end_comment

begin_define
define|#
directive|define
name|EDITOR
value|"/usr/ucb/ex"
end_define

begin_comment
comment|/* Name of text editor */
end_comment

begin_define
define|#
directive|define
name|VISUAL
value|"/usr/ucb/vi"
end_define

begin_comment
comment|/* Name of display editor */
end_comment

begin_define
define|#
directive|define
name|SHELL
value|"/bin/csh"
end_define

begin_comment
comment|/* Standard shell */
end_comment

begin_define
define|#
directive|define
name|MORE
value|"/usr/ucb/more"
end_define

begin_comment
comment|/* Standard output pager */
end_comment

begin_define
define|#
directive|define
name|HELPFILE
value|"/usr/lib/Mail.help"
end_define

begin_comment
comment|/* Name of casual help file */
end_comment

begin_define
define|#
directive|define
name|THELPFILE
value|"/usr/lib/Mail.tildehelp"
end_define

begin_comment
comment|/* Name of casual tilde help */
end_comment

begin_define
define|#
directive|define
name|POSTAGE
value|"/usr/adm/maillog"
end_define

begin_comment
comment|/* Where to audit mail sending */
end_comment

begin_define
define|#
directive|define
name|MASTER
value|"/usr/lib/Mail.rc"
end_define

begin_define
define|#
directive|define
name|APPEND
end_define

begin_comment
comment|/* New mail goes to end of mailbox */
end_comment

end_unit

