begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definition file for less */
end_comment

begin_comment
comment|/* Generated Sun Aug 16 09:47:26 PDT 1992 by linstall. */
end_comment

begin_comment
comment|/*  * Define XENIX if running under XENIX 3.0.  */
end_comment

begin_define
define|#
directive|define
name|XENIX
value|0
end_define

begin_comment
comment|/*  * VOID is 1 if your C compiler supports the "void" type,  * 0 if it does not.  */
end_comment

begin_define
define|#
directive|define
name|VOID
value|1
end_define

begin_comment
comment|/*  * VOID_POINTER is the definition of a pointer to any object.  */
end_comment

begin_define
define|#
directive|define
name|VOID_POINTER
value|void *
end_define

begin_comment
comment|/*  * offset_t is the type which lseek() returns.  * It is also the type of lseek()'s second argument.  */
end_comment

begin_define
define|#
directive|define
name|offset_t
value|long
end_define

begin_comment
comment|/*  * STAT is 1 if your system has the stat() call.  */
end_comment

begin_define
define|#
directive|define
name|STAT
value|1
end_define

begin_comment
comment|/*  * PERROR is 1 if your system has the perror() call.  * (Actually, if it has sys_errlist, sys_nerr and errno.)  */
end_comment

begin_define
define|#
directive|define
name|PERROR
value|1
end_define

begin_comment
comment|/*  * GET_TIME is 1 if your system has the time() call.  */
end_comment

begin_define
define|#
directive|define
name|GET_TIME
value|1
end_define

begin_comment
comment|/*  * TERMIO is 1 if your system has /usr/include/termio.h.  * This is normally the case for System 5.  * If TERMIO is 0 your system must have /usr/include/sgtty.h.  * This is normally the case for BSD.  */
end_comment

begin_define
define|#
directive|define
name|TERMIO
value|0
end_define

begin_comment
comment|/*  * HAS__SETJMP is 1 if your system has the _setjmp() call.  * This is normally the case only for BSD 4.2 and up,  * not for BSD 4.1 or System 5.  */
end_comment

begin_define
define|#
directive|define
name|HAS__SETJMP
value|1
end_define

begin_comment
comment|/*  * SIGSETMASK is 1 if your system has the sigsetmask() call.  * This is normally the case only for BSD 4.2,  * not for BSD 4.1 or System 5.  */
end_comment

begin_define
define|#
directive|define
name|SIGSETMASK
value|1
end_define

begin_comment
comment|/*  * NEED_PTEM_H is 1 if your system needs sys/ptem.h to declare struct winsize.  * This is normally the case only for SCOs System V.  */
end_comment

begin_define
define|#
directive|define
name|NEED_PTEM_H
value|0
end_define

begin_comment
comment|/*  * REGCMP is 1 if your system has the regcmp() function.  * This is normally the case for System 5.  * RECOMP is 1 if your system has the re_comp() function.  * This is normally the case for BSD.  * If neither is 1, pattern matching is supported, but without metacharacters.  */
end_comment

begin_define
define|#
directive|define
name|REGCMP
value|0
end_define

begin_define
define|#
directive|define
name|RECOMP
value|1
end_define

begin_comment
comment|/*  * SHELL_ESCAPE is 1 if you wish to allow shell escapes.  * (This is possible only if your system supplies the system() function.)  */
end_comment

begin_define
define|#
directive|define
name|SHELL_ESCAPE
value|1
end_define

begin_comment
comment|/*  * EDITOR is 1 if you wish to allow editor invocation (the "v" command).  * (This is possible only if your system supplies the system() function.)  * EDIT_PGM is the name of the (default) editor to be invoked.  */
end_comment

begin_define
define|#
directive|define
name|EDITOR
value|1
end_define

begin_define
define|#
directive|define
name|EDIT_PGM
value|"vi"
end_define

begin_comment
comment|/*  * TAGS is 1 if you wish to support tag files.  */
end_comment

begin_define
define|#
directive|define
name|TAGS
value|1
end_define

begin_comment
comment|/*  * USERFILE is 1 if you wish to allow a .less file to specify   * user-defined key bindings.  */
end_comment

begin_define
define|#
directive|define
name|USERFILE
value|1
end_define

begin_comment
comment|/*  * GLOB is 1 if you wish to have shell metacharacters expanded in filenames.  * This will generally work if your system provides the "popen" function  * and the "echo" shell command.  */
end_comment

begin_define
define|#
directive|define
name|GLOB
value|1
end_define

begin_comment
comment|/*  * PIPEC is 1 if you wish to have the "|" command  * which allows the user to pipe data into a shell command.  */
end_comment

begin_define
define|#
directive|define
name|PIPEC
value|1
end_define

begin_comment
comment|/*  * LOGFILE is 1 if you wish to allow the -l option (to create log files).  */
end_comment

begin_define
define|#
directive|define
name|LOGFILE
value|1
end_define

begin_comment
comment|/*  * ONLY_RETURN is 1 if you want RETURN to be the only input which  * will continue past an error message.  * Otherwise, any key will continue past an error message.  */
end_comment

begin_define
define|#
directive|define
name|ONLY_RETURN
value|0
end_define

begin_comment
comment|/*  * HELPFILE is the full pathname of the help file.  */
end_comment

begin_define
define|#
directive|define
name|HELPFILE
value|"/usr/local/bin/less.hlp"
end_define

end_unit

