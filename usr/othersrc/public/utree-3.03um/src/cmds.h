begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      CMDS.H  *      UTREE system command and filename definitions.  *      3.03-um klin, Tue Feb 11 19:23:58 1992, Splitted from conf.h  *  *      Copyright (c) 1991/92 by Peter Klingebiel& UNIX Magazin Muenchen.  *      For copying and distribution information see the file COPYRIGHT.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MAIN_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid_cmds
index|[]
init|=
literal|"@(#) utree 3.03-um (klin) Feb 11 1992 cmds.h"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAIN_&& !lint */
end_comment

begin_comment
comment|/*  *      SOME DEFAULT SYSTEM COMMANDS.  */
end_comment

begin_comment
comment|/* May be overriden by environment or utree variables.                  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|SHELL
value|"csh"
end_define

begin_comment
comment|/* Default shell. See csh(1)            */
end_comment

begin_define
define|#
directive|define
name|EDITPRG
value|"vi"
end_define

begin_comment
comment|/* Default editor. See vi(1)            */
end_comment

begin_define
define|#
directive|define
name|PAGEPRG
value|"more"
end_define

begin_comment
comment|/* Default pager. See more(1)           */
end_comment

begin_define
define|#
directive|define
name|DUMPPRG
value|"od"
end_define

begin_comment
comment|/* Default dumper. See od(1)            */
end_comment

begin_define
define|#
directive|define
name|PRINTPRG
value|"lpr"
end_define

begin_comment
comment|/* Default printer. See lpr(1)          */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYSV */
end_comment

begin_define
define|#
directive|define
name|SHELL
value|"sh"
end_define

begin_comment
comment|/* Default shell. See sh(1)             */
end_comment

begin_define
define|#
directive|define
name|EDITPRG
value|"ed"
end_define

begin_comment
comment|/* Default editor. See ed(1)            */
end_comment

begin_define
define|#
directive|define
name|PAGEPRG
value|"pg"
end_define

begin_comment
comment|/* Default pager. See pg(1)             */
end_comment

begin_define
define|#
directive|define
name|DUMPPRG
value|"od"
end_define

begin_comment
comment|/* Default dumper. See od(1)            */
end_comment

begin_define
define|#
directive|define
name|PRINTPRG
value|"lp"
end_define

begin_comment
comment|/* Default printer. See lp(1)           */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_define
define|#
directive|define
name|CPFILE
value|"cp"
end_define

begin_comment
comment|/* Copy files. See cp(1)                */
end_comment

begin_define
define|#
directive|define
name|MVFILE
value|"mv"
end_define

begin_comment
comment|/* Move files. See mv(1)                */
end_comment

begin_define
define|#
directive|define
name|LSFILE
value|"ls"
end_define

begin_comment
comment|/* List files. See ls(1)                */
end_comment

begin_define
define|#
directive|define
name|RMFILE
value|"rm"
end_define

begin_comment
comment|/* Remove files. See rm(1)              */
end_comment

begin_define
define|#
directive|define
name|RMOPTS
value|"-rf"
end_define

begin_comment
comment|/* Remove all option                    */
end_comment

begin_define
define|#
directive|define
name|MKDIR
value|"mkdir"
end_define

begin_comment
comment|/* Create directory. See mkdir(1)       */
end_comment

begin_define
define|#
directive|define
name|RMDIR
value|"rmdir"
end_define

begin_comment
comment|/* Remove directory. See rmdir(1)       */
end_comment

begin_define
define|#
directive|define
name|DUDIR
value|"du -s"
end_define

begin_comment
comment|/* Directory disk usage. See du(1)      */
end_comment

begin_define
define|#
directive|define
name|GRFILE
value|"grep"
end_define

begin_comment
comment|/* Search in files. See grep(1)         */
end_comment

begin_define
define|#
directive|define
name|GROPTS
value|"-c"
end_define

begin_comment
comment|/* Print count only option              */
end_comment

begin_comment
comment|/*  *      FILENAMES USED BY UTREE.  */
end_comment

begin_define
define|#
directive|define
name|UTBCKUP
value|"utree.backup"
end_define

begin_comment
comment|/* Utree backup shell script            */
end_comment

begin_define
define|#
directive|define
name|UTBACK
value|"utree.bak"
end_define

begin_comment
comment|/* Utree backup file list               */
end_comment

begin_define
define|#
directive|define
name|UTHELP
value|"utree.help"
end_define

begin_comment
comment|/* Utree help pages                     */
end_comment

begin_define
define|#
directive|define
name|UTSTART
value|"utree"
end_define

begin_comment
comment|/* Utree startup file in home or libdir */
end_comment

begin_define
define|#
directive|define
name|UTLIST
value|".utreelist"
end_define

begin_comment
comment|/* Utree tree list file in $HOME        */
end_comment

begin_define
define|#
directive|define
name|UTHIST
value|".utreehist"
end_define

begin_comment
comment|/* Utree command history file in $HOME  */
end_comment

end_unit

