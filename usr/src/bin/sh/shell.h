begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)shell.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The follow should be set to reflect the type of system you have:  *	JOBS -> 1 if you have Berkeley job control, 0 otherwise.  *	SYMLINKS -> 1 if your system includes symbolic links, 0 otherwise.  *	DIRENT -> 1 if your system has the SVR3 directory(3X) routines.  *	UDIR -> 1 if you want the shell to simulate the /u directory.  *	SHORTNAMES -> 1 if your linker cannot handle long names.  *	define BSD if you are running 4.2 BSD or later.  *	define SYSV if you are running under System V.  *	define DEBUG to turn on debugging.  *  * When debugging is on, debugging info will be written to $HOME/trace and  * a quit signal will generate a core dump.  */
end_comment

begin_define
define|#
directive|define
name|JOBS
value|1
end_define

begin_define
define|#
directive|define
name|SYMLINKS
value|1
end_define

begin_define
define|#
directive|define
name|DIRENT
value|1
end_define

begin_define
define|#
directive|define
name|UDIR
value|0
end_define

begin_define
define|#
directive|define
name|ATTY
value|0
end_define

begin_define
define|#
directive|define
name|SHORTNAMES
value|0
end_define

begin_define
define|#
directive|define
name|BSD
end_define

begin_comment
comment|/* #define SYSV */
end_comment

begin_comment
comment|/* #define DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|(void *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|pointer
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|STATIC
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|MKINIT
end_define

begin_comment
comment|/* empty */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|nullstr
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* null string */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|TRACE
parameter_list|(
name|param
parameter_list|)
value|trace param
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRACE
parameter_list|(
name|param
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

