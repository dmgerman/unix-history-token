begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  Sendmail **  Copyright (c) 1983  Eric P. Allman **  Berkeley, California ** **  Copyright (c) 1983 Regents of the University of California. **  All rights reserved.  The Berkeley software License Agreement **  specifies the terms and conditions for redistribution. ** **	@(#)conf.h	5.1 (Berkeley) 6/7/85 */
end_comment

begin_comment
comment|/* **  CONF.H -- definitions of compilation flags needed everywhere. ** **	This, together with conf.c, should be all the configuration **	information needed.  This stuff could be in a makefile, but **	we prefer to keep this file very small because it is different **	on a number of machines. ** */
end_comment

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_comment
comment|/* turn on debugging information */
end_comment

begin_comment
comment|/* # define	NEWFTP		/* use new ftp reply codes */
end_comment

begin_comment
comment|/* # define	NOTUNIX		/* don't use Unix-style mail headers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INGRES
end_ifdef

begin_define
define|#
directive|define
name|LOG
end_define

begin_comment
comment|/* turn on logging */
end_comment

begin_comment
comment|/* this flag requires -lsys in makefile */
end_comment

begin_endif
endif|#
directive|endif
endif|INGRES
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_define
define|#
directive|define
name|VFORK
end_define

begin_comment
comment|/* use the vfork syscall */
end_comment

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|V6
end_ifndef

begin_define
define|#
directive|define
name|DBM
end_define

begin_comment
comment|/* use the dbm library */
end_comment

begin_comment
comment|/* this flag requires -ldbm in makefile */
end_comment

begin_endif
endif|#
directive|endif
endif|V6
end_endif

end_unit

