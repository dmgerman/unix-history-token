begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|TUNED
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
end_define

begin_comment
comment|/* only on UNIX systems (NOT INCORPORATED YET) */
end_comment

begin_define
define|#
directive|define
name|IPROCS
end_define

begin_comment
comment|/* interactive processes */
end_comment

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
end_define

begin_comment
comment|/* enable the backup files code */
end_comment

begin_define
define|#
directive|define
name|F_COMPLETION
end_define

begin_comment
comment|/* filename completion */
end_comment

begin_define
define|#
directive|define
name|ABBREV
end_define

begin_comment
comment|/* word abbreviation mode */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|IBMPC
argument_list|)
operator|||
name|defined
argument_list|(
name|MAC
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|ID_CHAR
end_define

begin_comment
comment|/* include code to IDchar */
end_comment

begin_define
define|#
directive|define
name|WIRED_TERMS
end_define

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
end_define

begin_comment
comment|/* include the code for Lisp Mode */
end_comment

begin_define
define|#
directive|define
name|CMT_FMT
end_define

begin_comment
comment|/* include the comment formatting routines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_define
define|#
directive|define
name|LOAD_AV
end_define

begin_comment
comment|/* Use the load average for various commands. #			   Do not define this if you lack a load average #			   system call and kmem is read protected. */
end_comment

begin_empty
empty|#
end_empty

begin_define
define|#
directive|define
name|BIFF
end_define

begin_comment
comment|/* if you have biff (or the equivalent) */
end_comment

begin_define
define|#
directive|define
name|SPELL
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

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_undef
undef|#
directive|undef
name|F_COMPLETION
end_undef

begin_define
define|#
directive|define
name|F_COMPLETION
value|1
end_define

begin_define
define|#
directive|define
name|byte_zero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|setmem((s),(n),0)
end_define

begin_define
define|#
directive|define
name|swritef
value|sprintf
end_define

begin_define
define|#
directive|define
name|USE_PROTOTYPES
value|1
end_define

begin_define
define|#
directive|define
name|NBUF
value|64
end_define

begin_define
define|#
directive|define
name|JBUFSIZ
value|1024
end_define

begin_undef
undef|#
directive|undef
name|LISP
end_undef

begin_define
define|#
directive|define
name|LISP
value|1
end_define

begin_undef
undef|#
directive|undef
name|ABBREV
end_undef

begin_define
define|#
directive|define
name|ABBREV
value|1
end_define

begin_undef
undef|#
directive|undef
name|CMT_FMT
end_undef

begin_define
define|#
directive|define
name|CMT_FMT
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
if|#
directive|if
name|defined
argument_list|(
name|IPROCS
argument_list|)
operator|&&
name|defined
argument_list|(
name|PIPEPROCS
argument_list|)
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

