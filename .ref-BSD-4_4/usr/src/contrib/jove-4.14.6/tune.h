begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|TUNED
value|1
end_define

begin_comment
comment|/* don't touch this */
end_comment

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_define
define|#
directive|define
name|SUBPROCS
value|1
end_define

begin_comment
comment|/* only on UNIX systems (NOT INCORPORATED YET) */
end_comment

begin_define
define|#
directive|define
name|IPROCS
value|1
end_define

begin_comment
comment|/* interactive processes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_2
end_ifdef

begin_define
define|#
directive|define
name|PTYPROCS
value|1
end_define

begin_comment
comment|/* use pseudo-ttys */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIPEPROCS
value|1
end_define

begin_comment
comment|/* use pipes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_define
define|#
directive|define
name|BACKUPFILES
value|1
end_define

begin_comment
comment|/* enable the backup files code */
end_comment

begin_define
define|#
directive|define
name|F_COMPLETION
value|1
end_define

begin_comment
comment|/* filename completion */
end_comment

begin_define
define|#
directive|define
name|ABBREV
value|1
end_define

begin_comment
comment|/* word abbreviation mode */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_define
define|#
directive|define
name|ID_CHAR
value|1
end_define

begin_comment
comment|/* include code to IDchar */
end_comment

begin_comment
comment|/* # define WIRED_TERMS 1 */
end_comment

begin_comment
comment|/* include code for wired terminals */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LISP
value|1
end_define

begin_comment
comment|/* include the code for Lisp Mode */
end_comment

begin_define
define|#
directive|define
name|CMT_FMT
value|1
end_define

begin_comment
comment|/* include the comment formatting routines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_comment
comment|/* Use the load average for various commands.  * Do not define LOAD_AV if you lack a load average  * system call and kmem is read protected.  */
end_comment

begin_comment
comment|/* # define LOAD_AV	1 */
end_comment

begin_define
define|#
directive|define
name|BIFF
value|1
end_define

begin_comment
comment|/* if you have biff (or the equivalent) */
end_comment

begin_define
define|#
directive|define
name|SPELL
value|1
end_define

begin_comment
comment|/* spell words and buffer commands */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DFLT_MODE
value|0666
end_define

begin_comment
comment|/* file will be created with this mode */
end_comment

begin_comment
comment|/* If the compiler does not support void, use -Dvoid=int or  * typedef int	void;  */
end_comment

begin_comment
comment|/* USE_PROTOTYPE must be defined for compilers that support prototypes  * but are NOT ANSI C, i.e. do not have __STDC__ == 1.  */
end_comment

begin_comment
comment|/* NO_PTRPROTO must be defined for compilers that support prototypes,  * but do NOT support prototypes for pointers to functions.  * It seems that some MSDOS and Mac compilers fall in this category.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_define
define|#
directive|define
name|NO_PTRPROTO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_define
define|#
directive|define
name|USE_PROTOTYPES
value|1
end_define

begin_define
define|#
directive|define
name|NO_PTRPROTO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These are here since they define things in tune.c.  If you add things to    tune.c, add them here too, if necessary. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|d_tempfile
decl_stmt|,
modifier|*
name|p_tempfile
decl_stmt|,
modifier|*
name|Recover
decl_stmt|,
modifier|*
name|Joverc
decl_stmt|,
ifdef|#
directive|ifdef
name|PIPEPROCS
modifier|*
name|Portsrv
decl_stmt|,
modifier|*
name|Kbd_Proc
decl_stmt|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MSDOS
name|CmdDb
index|[]
decl_stmt|,
else|#
directive|else
modifier|*
name|CmdDb
decl_stmt|,
endif|#
directive|endif
name|TmpFilePath
index|[]
decl_stmt|,
name|Shell
index|[]
decl_stmt|,
name|ShFlags
index|[]
decl_stmt|;
end_decl_stmt

end_unit

