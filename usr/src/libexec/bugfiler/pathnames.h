begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)pathnames.h	5.3 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|MAIL_CMD
value|"/usr/sbin/sendmail -i -t -F \"Bugs Bunny\" -f owner-bugs"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_TMP
end_undef

begin_define
define|#
directive|define
name|_PATH_TMP
value|"/tmp/BUG_XXXXXX";
end_define

end_unit

