begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* system.h    Header file for system dependent stuff in the Taylor UUCP package.    This file is not itself system dependent.     Copyright (C) 1991, 1992, 1993, 1994, 1995 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|SYSTEM_H
end_define

begin_if
if|#
directive|if
name|ANSI_C
end_if

begin_comment
comment|/* These structures are used in prototypes but are not defined in this    header file.  */
end_comment

begin_struct_decl
struct_decl|struct
name|tm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uuconf_system
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uuconf_port
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sconnection
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sstatus
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|scmd
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Any function which returns an error should also report an error    message, unless otherwise indicated.     Any function that returns a char *, rather than a const char *, is    returning a pointer to a buffer allocated by zbufalc which must be    freed using ubuffree, unless otherwise indicated.  */
end_comment

begin_comment
comment|/* The maximum length of a remote system name.  */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|cSysdep_max_name_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize.  If something goes wrong, this routine should just    exit.  The flag argument is 0, or a combination of any of the    following flags.  */
end_comment

begin_comment
comment|/* This program needs to know the current working directory.  This is    used because on Unix it can be expensive to determine the current    working directory (some versions of getcwd fork a process), but in    most cases we don't need to know it.  However, we are going to    chdir to the spool directory (unless INIT_CHDIR is set), so we have    to get the cwd now if we are ever going to get it.  Both uucp and    uux use the function fsysdep_needs_cwd to determine whether they    will need the current working directory, and pass the argument to    usysdep_initialize appropriately.  There's probably a cleaner way    to handle this, but this will suffice for now.  */
end_comment

begin_define
define|#
directive|define
name|INIT_GETCWD
value|(01)
end_define

begin_comment
comment|/* This program should not chdir to the spool directory.  This may    only make sense on Unix.  It is set by cu.  */
end_comment

begin_define
define|#
directive|define
name|INIT_NOCHDIR
value|(02)
end_define

begin_comment
comment|/* This program needs special access to the spool directories.  That    means, on Unix, this program is normally installed setuid.  */
end_comment

begin_define
define|#
directive|define
name|INIT_SUID
value|(04)
end_define

begin_comment
comment|/* Do not close all open descriptors.  This is not used by the UUCP    code, but it is used by other programs which share some of the    system dependent libraries.  */
end_comment

begin_define
define|#
directive|define
name|INIT_NOCLOSE
value|(010)
end_define

begin_decl_stmt
specifier|extern
name|void
name|usysdep_initialize
name|P
argument_list|(
operator|(
name|pointer
name|puuconf
operator|,
name|int
name|iflags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Exit the program.  The fsuccess argument indicates whether to    return an indication of success or failure to the outer    environment.  This routine should not return.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usysdep_exit
name|P
argument_list|(
operator|(
name|boolean
name|fsuccess
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called when a non-standard configuration file is being used, to    avoid handing out privileged access.  If it returns FALSE, default    configuration file will be used.  This is called before the    usysdep_initialize function is called.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_other_config
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Detach from the controlling terminal.  This probably only makes    sense on Unix.  It is called by uucico to try to get the modem port    as a controlling terminal.  It is also called by uucico before it    starts up uuxqt, so that uuxqt will be a complete daemon.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usysdep_detach
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the local node name if it is not specified in the configuration    files.  Returns NULL on error; otherwise the return value should    point to a static buffer.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zsysdep_localname
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the login name.  This is used when uucico is started up with no    arguments in slave mode, which causes it to assume that somebody    has logged in.  It also used by uucp and uux for recording the user    name.  This may not return NULL.  The return value should point to    a static buffer.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zsysdep_login_name
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set a signal handler for a signal.  If the signal occurs, the    appropriate element of afSignal should be set to the signal number    (see the declaration of afSignal in uucp.h).  This routine might be    able to just use signal, but Unix requires more complex handling.    This is called before usysdep_initialize.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usysdep_signal
name|P
argument_list|(
operator|(
name|int
name|isig
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Catch a signal.  This is actually defined as a macro in the system    dependent header file, and the prototype here just indicates how it    should be called.  It is called before a routine which must exit if    a signal occurs, and is expected to set do a setjmp (which is why    it must be a macro).  It is actually only called in one place in    the system independent code, before the call to read stdin in uux.    This is needed to handle 4.2 BSD restartable system calls, which    require a longjmp.  On systems which don't need to do    setjmp/longjmp around system calls, this can be redefined in    sysdep.h to TRUE.  It should return TRUE if the routine should    proceed, or FALSE if a signal occurred.  After having this return    TRUE, usysdep_start_catch should be used to start catching the    signal; this basically tells the signal handler that it's OK to do    the longjmp, if fsysdep_catch did not already do so.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|fsysdep_catch
end_ifndef

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_catch
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Start catching a signal.  This is called after fsysdep_catch to    tell the signal handler to go ahead and do the longjmp.  This may    be implemented as a macro in sysdep.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|usysdep_start_catch
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|usysdep_start_catch
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Stop catching a signal.  This is called when it is no longer    necessary for fsysdep_catch to handle signals.  This may be    implemented as a macro in sysdep.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|usysdep_end_catch
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|usysdep_end_catch
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Link two files.  On Unix this should attempt the link.  If it    succeeds it should return TRUE with *pfworked set to TRUE.  If the    link fails because it must go across a device, it should return    TRUE with *pfworked set to FALSE.  If the link fails for some other    reason, it should log an error message and return FALSE.  On a    system which does not support links to files, this should just    return TRUE with *pfworked set to FALSE.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_link
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfrom
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
name|boolean
operator|*
name|pfworked
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the port name.  This is used when uucico is started up in slave    mode to figure out which port was used to call in so that it can    determine any appropriate protocol parameters.  This may return    NULL if the port cannot be determined, which will just mean that no    protocol parameters are applied.  The name returned should be the    sort of name that would appear in the port file.  This should set    *pftcp_port to TRUE if it can determine that the port is a TCP    connection rather than a normal serial port.  The return value (if    not NULL) should point to a static buffer.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zsysdep_port_name
name|P
argument_list|(
operator|(
name|boolean
operator|*
name|pftcp_port
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expand a file name on the local system.  On Unix, if the zfile    argument begins with ~user/ it goes in that users home directory,    and if it begins with ~/ it goes in the public directory (the    public directory is passed to this routine, since each system may    have its own public directory).  Similar conventions may be    desirable on other systems.  This should always return an absolute    path name, probably in the public directory.  It should return NULL    on error; otherwise the return value should be allocated using    zbufcpy or zbufalc.  If pfbadname is not NULL, then if the function    returns NULL *pfbadname should be set to TRUE if the error is just    that the file name is badly specified; *pfbadname should be set to    FALSE for some sort of internal error.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_local_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zname
operator|,
specifier|const
name|char
operator|*
name|zpubdir
operator|,
name|boolean
operator|*
name|pfbadname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return whether a file name is in a directory, and check for read or    write access.  This should check whether zfile is within zdir (or    is zdir itself).  If it is not, it should return FALSE.  If zfile    is in zdir, then fcheck indicates whether further checking should    be done.  If fcheck is FALSE, no further checking is done.    Otherwise, if freadable is TRUE the user zuser should have search    access to all directories from zdir down to zfile and should have    read access on zfile itself (if zfile does not exist, or is not a    regular file, this function may return FALSE but does not have to).    If freadable is FALSE, the user zuser should have search access to    all directories from zdir down to zfile and should have write    access on zfile (which may be a directory, or may not actually    exist, which is acceptable).  The zuser argument may be NULL, in    which case the check should be made for any user, not just zuser.    There is no way for this function to return error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_in_directory
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|,
specifier|const
name|char
operator|*
name|zdir
operator|,
name|boolean
name|fcheck
operator|,
name|boolean
name|freadable
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return TRUE if a file exists, FALSE otherwise.  There is no way to    return error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_file_exists
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start up a program.  If the ffork argument is true, this should    spawn a new process and return.  If the ffork argument is false,    this may either return or not.  The three string arguments may be    catenated together to form the program to execute; I did it this    way to make it easy to call execl(2), and because I never needed    more than two arguments.  The program will always be "uucico" or    "uuxqt".  The return value should be TRUE on success, FALSE on    error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_run
name|P
argument_list|(
operator|(
name|boolean
name|ffork
operator|,
specifier|const
name|char
operator|*
name|zprogram
operator|,
specifier|const
name|char
operator|*
name|zarg1
operator|,
specifier|const
name|char
operator|*
name|zarg2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send a mail message.  This function will be passed an array of    strings.  All necessary newlines are already included; the strings    should simply be concatenated together to form the mail message.    It should return FALSE on error, although the return value is often    ignored.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_mail
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zto
operator|,
specifier|const
name|char
operator|*
name|zsubject
operator|,
name|int
name|cstrs
operator|,
specifier|const
name|char
operator|*
operator|*
name|paz
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the time in seconds since some epoch.  The actual epoch is    unimportant, so long as the time values are consistent across    program executions and the value is never negative.  If the    pimicros argument is not NULL, it should be set to the number of    microseconds (if this is not available, *pimicros should be set to    zero).  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|ixsysdep_time
name|P
argument_list|(
operator|(
name|long
operator|*
name|pimicros
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the time in seconds and microseconds (millionths of a second)    since some epoch.  The actual epoch is not important, and it may    change in between program invocations; this is provided because on    Unix the times function may be used.  If microseconds can not be    determined, *pimicros can just be set to zero.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|ixsysdep_process_time
name|P
argument_list|(
operator|(
name|long
operator|*
name|pimicros
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse the value returned by ixsysdep_time into a struct tm.  I    assume that this structure is defined in<time.h>.  This is    basically just localtime, except that the ANSI function takes a    time_t which may not be what is returned by ixsysdep_time.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usysdep_localtime
name|P
argument_list|(
operator|(
name|long
name|itime
operator|,
expr|struct
name|tm
operator|*
name|q
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sleep for a number of seconds.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usysdep_sleep
name|P
argument_list|(
operator|(
name|int
name|cseconds
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pause for half a second, or 1 second if subsecond sleeps are not    possible.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usysdep_pause
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Lock a remote system.  This should return FALSE if the system is    already locked (no error should be reported).  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_lock_system
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unlock a remote system.  This should return FALSE on error    (although the return value is generally ignored).  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_unlock_system
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the conversation sequence number for a remote system, and    increment it for next time.  This should return -1 on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|ixsysdep_get_sequence
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the status of a remote system.  This should return FALSE on    error.  Otherwise it should set *qret to the status.  If no status    information is available, this should set *qret to sensible values    and return TRUE.  If pfnone is not NULL, then it should be set to    TRUE if no status information was available or FALSE otherwise.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_get_status
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
expr|struct
name|sstatus
operator|*
name|qret
operator|,
name|boolean
operator|*
name|pfnone
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the status of a remote system.  This should return FALSE on    error.  The system will be locked before this call is made.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_set_status
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
expr|struct
name|sstatus
operator|*
name|qset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See whether a remote system is permitted to log in.  This is just    to support the remote.unknown shell script for HDB.  The zscript    argument is the script name, as return by uuconf_remote_unknown.    The zsystem argument is the name given by the remote system.  If    the system is not permitted to log in, this function should log an    error and return FALSE.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_unknown_caller
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zscript
operator|,
specifier|const
name|char
operator|*
name|zsystem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Check whether there is work for a remote system.  It should return    TRUE if there is work, FALSE otherwise; there is no way to indicate    an error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_has_work
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize the work scan.  This will be called before    fsysdep_get_work.  The bgrade argument is the minimum grade of    execution files that should be considered (e.g. a bgrade of 'd'    will allow all grades from 'A' to 'Z' and 'a' to 'd').  This    function should return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_get_work_init
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
name|int
name|bgrade
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the next command to be executed for a remote system.  The    bgrade argument will be the same as for fsysdep_get_work_init;    probably only one of these functions will use it, namely the    function for which it is more convenient.  This should return FALSE    on error.  The structure pointed to by qcmd should be filled in.    The strings may point into a static buffer; they will be copied out    if necessary.  If there is no more work, this should set qcmd->bcmd    to 'H' and return TRUE.  This should set qcmd->pseq to something    which can be passed to fsysdep_did_work to remove the job from the    queue when it has been completed.  This may set qcmd->bcmd to 'P'    to represent a poll file; the main code will just pass the pseq    element of such a structure to fsysdep_did_work if the system is    called.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_get_work
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
name|int
name|bgrade
operator|,
expr|struct
name|scmd
operator|*
name|qcmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remove a job from the work queue.  This must also remove the    temporary file used for a send command, if there is one.  It should    return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_did_work
name|P
argument_list|(
operator|(
name|pointer
name|pseq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save the temporary file for a send command.  This function should    return a string that will be put into a mail message.  On success    this string should say something like ``The file has been saved as    ...''.  On failure it could say something like ``The file could not    be saved because ...''.  If there is no temporary file, or for some    reason it's not appropriate to include a message, this function    should just return NULL.  This function is used when a file send    fails for some reason, to make sure that we don't completely lost    the file.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zsysdep_save_temp_file
name|P
argument_list|(
operator|(
name|pointer
name|pseq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save a file in a location used to hold corrupt files.  This is    called if a bad execution file is found by uuxqt.  This should    return the new name of the file (allocated by zbufalc), or NULL if    the move failed (in which the original file should remain).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_save_corrupt_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save a file in a location used to hold failed execution files.    This is called if a uuxqt execution fails.  This should return the    new name of the file (allocated by zbufalc), or NULL if the move    failed (in which case the original file should remain).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_save_failed_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cleanup anything left over by fsysdep_get_work_init and    fsysdep_get_work.  This may be called even though    fsysdep_get_work_init has not been.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usysdep_get_work_free
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Add a base name to a file if it is a directory.  If zfile names a    directory, then return a string naming a file within the directory    with the base file name of zname.  This should return NULL on    error.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_add_base
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|,
specifier|const
name|char
operator|*
name|zname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get a file name from the spool directory.  This should return NULL    on error.  The pseq argument is TRUE if the file was found from    searching the work directory; this is, unfortunately, needed to    support SVR4 spool directories.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_spool_file_name
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zfile
operator|,
name|pointer
name|pseq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make necessary directories.  This should create all non-existent    directories for a file.  If the fpublic argument is TRUE, anybody    should be permitted to create and remove files in the directory;    otherwise anybody can list the directory, but only the UUCP system    can create and remove files.  It should return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_make_dirs
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|,
name|boolean
name|fpublic
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create a stdio file, setting appropriate protection.  If the    fpublic argument is TRUE, the file is made publically accessible;    otherwise it is treated as a private data file.  If the fappend    argument is TRUE, the file is opened in append mode; otherwise any    previously existing file of the same name is removed.  If the    fmkdirs argument is TRUE, then any necessary directories should    also be created.  On a system in which file protections are    unimportant and the necessary directories exist, this may be    implemented as     fopen (zfile, fappend ? "a" : "w");     */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|esysdep_fopen
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|,
name|boolean
name|fpublic
operator|,
name|boolean
name|fappend
operator|,
name|boolean
name|fmkdirs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open a file, using the access permission of the user who invoked    the program.  The frd argument is TRUE if the file should be opened    for reading, and the fbinary argument is TRUE if the file should be    opened as a binary file (this is ignored on Unix, since there all    files are binary files).  This returns an openfile_t, not a FILE *.    This is supposed to be able to open a file even if it can not be    read by the uucp user.  This is not possible on some older Unix    systems.  */
end_comment

begin_decl_stmt
specifier|extern
name|openfile_t
name|esysdep_user_fopen
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|,
name|boolean
name|frd
operator|,
name|boolean
name|fbinary
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open a file to send to another system; the qsys argument is the    system the file is being sent to.  If fcheck is TRUE, it should    make sure that the file is readable by zuser (if zuser is NULL the    file must be readable by anybody).  This is to eliminate a window    between fsysdep_in_directory and esysdep_open_send.  If an error    occurs, it should return EFILECLOSED.  */
end_comment

begin_decl_stmt
specifier|extern
name|openfile_t
name|esysdep_open_send
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zname
operator|,
name|boolean
name|fcheck
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return a temporary file name to receive into.  This file will be    opened by esysdep_open_receive.  The qsys argument is the system    the file is coming from, the zto argument is the name the file will    have after it has been fully received, the ztemp argument, if it is    not NULL, is from the command sent by the remote system, and the    frestart argument is TRUE if the protocol and remote system permit    file transfers to be restarted.  The return value must be freed    using ubuffree.  The function should return NULL on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_receive_temp
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zfile
operator|,
specifier|const
name|char
operator|*
name|ztemp
operator|,
name|boolean
name|frestart
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open a file to receive from another system.  The zreceive argument    is the return value of zsysdep_receive_temp with the same qsys,    zfile and ztemp arguments.  If the function can determine that this    file has already been partially received, it should set *pcrestart    to the number of bytes that have been received.  If the file has    not been partially received, *pcrestart should be set to -1.    pcrestart will be passed in as NULL if file restart is not    supported by the protocol or the remote system.  The function    should return EFILECLOSED on error.  After the file is written,    fsysdep_move_file will be called to move the file to its final    destination, and to set the correct file mode.  */
end_comment

begin_decl_stmt
specifier|extern
name|openfile_t
name|esysdep_open_receive
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
specifier|const
name|char
operator|*
name|ztemp
operator|,
specifier|const
name|char
operator|*
name|zreceive
operator|,
name|long
operator|*
name|pcrestart
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Move a file.  This is used to move a received file to its final    location.  The zto argument is the file to create.  The zorig    argument is the name of the file to move.  If fmkdirs is TRUE, then    any necessary directories are created; fpublic indicates whether    they should be publically writeable or not.  If fcheck is TRUE,    this should make sure the directory is writeable by the user zuser    (if zuser is NULL, then it must be writeable by any user); this is    to avoid a window of vulnerability between fsysdep_in_directory and    fsysdep_move_file.  This function should return FALSE on error, in    which case the zorig file should still exist.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_move_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zorig
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
name|boolean
name|fmkdirs
operator|,
name|boolean
name|fpublic
operator|,
name|boolean
name|fcheck
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Change the mode of a file.  The imode argument is a Unix mode.    This should return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_change_mode
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|,
name|unsigned
name|int
name|imode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Truncate a file which we are receiving into.  This may be done by    closing the original file, removing it and reopening it.  This    should return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|openfile_t
name|esysdep_truncate
name|P
argument_list|(
operator|(
name|openfile_t
name|e
operator|,
specifier|const
name|char
operator|*
name|zname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sync a file to disk.  If this fails it should log an error using    the zmsg parameter, and return FALSE.  This is controlled by the    FSYNC_ON_CLOSE macro in policy.h.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_sync
name|P
argument_list|(
operator|(
name|openfile_t
name|e
operator|,
specifier|const
name|char
operator|*
name|zmsg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* It is possible for the acknowledgement of a received file to be    lost.  The sending system will then now know that the file was    correctly received, and will send it again.  This can be a problem    particularly with protocols which support channels, since they may    send several small files in a single window, all of which may be    received correctly although the sending system never sees the    acknowledgement.  If these files involve an execution, the    execution will happen twice, which will be bad.     This function is called when a file is completely received.  It is    supposed to try and remember the reception, in case the connection    is lost.  It is passed the system, the file name to receive to, and    the temporary file name from the sending system.  It should return    FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_remember_reception
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
specifier|const
name|char
operator|*
name|ztemp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function is called to see if a file has already been received    successfully.  It gets the same arguments as    fsysdep_remember_reception.  It should return TRUE if the file was    already received, FALSE otherwise.  There is no way to report    error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_already_received
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
specifier|const
name|char
operator|*
name|ztemp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function is called when it is no longer necessary to remember    that a file has been received.  This will be called when the    protocol knows that the receive message has been acknowledged.  It    gets the same arguments as fsysdep_remember_reception.  it should    return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_forget_reception
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
specifier|const
name|char
operator|*
name|ztemp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Start expanding a wildcarded file name.  This should return FALSE    on error; otherwise subsequent calls to zsysdep_wildcard should    return file names.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_wildcard_start
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the next wildcard name.  This should return NULL when there are    no more names to return.  The return value should be freed using    ubuffree.  The argument should be the same as that to    fsysdep_wildcard_start.  There is no way to return error.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_wildcard
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finish getting wildcard names.  This may be called before or after    zsysdep_wildcard has returned NULL.  It should return FALSE on    error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_wildcard_end
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Prepare to execute a bunch of file transfer requests.  This should    make an entry in the spool directory so that the next time uucico    is started up it will transfer these files.  The bgrade argument    specifies the grade of the commands.  The commands themselves are    in the pascmds array, which has ccmds entries.  The function should    return NULL on error, or the jobid on success.  The jobid is a    string that may be printed or passed to fsysdep_kill_job and    related functions, but is otherwise uninterpreted.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_spool_commands
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
name|int
name|bgrade
operator|,
name|int
name|ccmds
operator|,
specifier|const
expr|struct
name|scmd
operator|*
name|pascmds
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get a file name to use for a data file to be copied to another    system.  The ztname, zdname and zxname arguments will all either be    NULL or point to an array of CFILE_NAME_LEN characters in length.    The ztname array should be set to a temporary file name that could    be passed to zsysdep_spool_file_name to retrieve the return value    of this function; this will be appropriate for the temporary name    in a send request.  The zdname array should be set to a data file    name that is appropriate for the spool directory of the other    system; this will be appropriate for the name of the destination    file in a send request of a data file for an execution of some    sort.  The zxname array should be set to an execute file name that    is appropriate for the other system.  The zlocalname argument is    the name of the local system as seen by the remote system, the    bgrade argument is the grade, and fxqt is TRUE if this file is    going to become an execution file.  This should return NULL on    error.  */
end_comment

begin_define
define|#
directive|define
name|CFILE_NAME_LEN
value|(15)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_data_file_name
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zlocalname
operator|,
name|int
name|bgrade
operator|,
name|boolean
name|fxqt
operator|,
name|char
operator|*
name|ztname
operator|,
name|char
operator|*
name|zdname
operator|,
name|char
operator|*
name|zxname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get a name for a local execute file.  This is used by uux for a    local command with remote files.  Returns NULL on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_xqt_file_name
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Beginning getting execute files.  To get a list of execute files,    first fsysdep_get_xqt_init is called, then zsysdep_get_xqt is    called several times until it returns NULL, then finally    usysdep_get_xqt_free is called.  If the zsystem argument is not    NULL, it is the name of a system for which execution files are    desired.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_get_xqt_init
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsystem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the next execute file.  This should return NULL when finished    (with *pferr set to FALSE).  The zsystem argument should be the    same string as that passed to fsysdep_get_xqt_init.  On an error    this should return NULL with *pferr set to TRUE.  This should set    *pzsystem to the name of the system for which the execute file was    created; this is not guaranteed to match the zsystem argument--that    must be double checked by the caller.  Both the return value and    *pzsystem should be freed using ubuffree.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_get_xqt
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsystem
operator|,
name|char
operator|*
operator|*
name|pzsystem
operator|,
name|boolean
operator|*
name|pferr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clean up after getting execute files.  The zsystem argument should    be the same string as that passed to fsysdep_get_xqt_init.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usysdep_get_xqt_free
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsystem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Get the absolute pathname of a command to execute.  This is given    the legal list of commands (which may be the special case "ALL")    and the path.  It must return an absolute pathname to the command.    If it gets an error it should set *pferr to TRUE and return NULL;    if the command is not found it should set *pferr to FALSE and    return NULL.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_find_command
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zcmd
operator|,
name|char
operator|*
operator|*
name|pzcmds
operator|,
name|char
operator|*
operator|*
name|pzpath
operator|,
name|boolean
operator|*
name|pferr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expand file names for uuxqt.  This exists because uuxqt on Unix has    to expand file names which begin with a ~.  It does not want to    expand any other type of file name, and it turns a double ~ into a    single one without expanding.  If this returns NULL, the file does    not need to be changed; otherwise it returns a zbufalc'ed string.    There is no way to report error.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_xqt_local_file
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|ALLOW_FILENAME_ARGUMENTS
end_if

begin_comment
comment|/* Check an argument to an execution command to make sure that it    doesn't refer to a file name that may not be accessed.  This should    check the argument to see if it is a filename.  If it is, it should    either reject it out of hand or it should call fin_directory_list    on the file with both qsys->zremote_receive and qsys->zremote_send.    If the file is rejected, it should log an error and return FALSE.    Otherwise it should return TRUE.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_xqt_check_file
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! ALLOW_FILENAME_ARGUMENTS */
end_comment

begin_comment
comment|/* Run an execute file.  The arguments are:     qsys -- system for which execute file was created    zuser -- user who requested execution    pazargs -- list of arguments to command (element 0 is command)    zfullcmd -- command and arguments stuck together in one string    zinput -- file name for standard input (may be NULL)    zoutput -- file name for standard output (may be NULL)    fshell -- if TRUE, use /bin/sh to execute file    ilock -- return value of ixsysdep_lock_uuxqt    pzerror -- set to name of standard error file    pftemp -- set to TRUE if error is temporary, FALSE otherwise     If fshell is TRUE, the command should be executed with /bin/sh    (obviously, this can only really be done on Unix systems).  If an    error occurs this should return FALSE and set *pftemp    appropriately.  *pzerror should be freed using ubuffree.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_execute
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|,
specifier|const
name|char
operator|*
operator|*
name|pazargs
operator|,
specifier|const
name|char
operator|*
name|zfullcmd
operator|,
specifier|const
name|char
operator|*
name|zinput
operator|,
specifier|const
name|char
operator|*
name|zoutput
operator|,
name|boolean
name|fshell
operator|,
name|int
name|ilock
operator|,
name|char
operator|*
operator|*
name|pzerror
operator|,
name|boolean
operator|*
name|pftemp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lock for uuxqt execution.  If the cmaxuuxqts argument is not zero,    this should make sure that no more than cmaxuuxqts uuxqt processes    are running at once.  Also, only one uuxqt may execute a particular    command (specified by the -c option) at a time.  If zcmd is not    NULL, it is a command that must be locked.  This should return a    nonnegative number which will be passed to other routines,    including fsysdep_unlock_uuxqt, or -1 on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ixsysdep_lock_uuxqt
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zcmd
operator|,
name|int
name|cmaxuuxqts
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unlock a uuxqt process.  This is passed the return value of    ixsysdep_lock_uuxqt, as well as the arguments passed to    ixsysdep_lock_uuxqt.  It may return FALSE on error, but at present    the return value is ignored.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_unlock_uuxqt
name|P
argument_list|(
operator|(
name|int
name|iseq
operator|,
specifier|const
name|char
operator|*
name|zcmd
operator|,
name|int
name|cmaxuuxqts
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See whether a particular uuxqt command is locked.  This should    return TRUE if the command is locked (because ixsysdep_lock_uuxqt    was called with it as an argument), FALSE otherwise.  There is no    way to return error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_uuxqt_locked
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zcmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lock an execute file in order to execute it.  This should return    FALSE if the execute file is already locked.  There is no way to    return error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_lock_uuxqt_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unlock an execute file.  This should return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_unlock_uuxqt_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lock the execution directory.  The ilock argument is the return    value of ixsysdep_lock_uuxqt.  This should return FALSE if the    directory is already locked.  There is no way to return error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_lock_uuxqt_dir
name|P
argument_list|(
operator|(
name|int
name|ilock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remove all files in the execution directory, and unlock it.  This    should return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_unlock_uuxqt_dir
name|P
argument_list|(
operator|(
name|int
name|ilock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Move files into or out of the execution directory.  The code will    already have checked that all the files exist.  The elements in the    pzfrom array will be complete filenames, and the elements in the    pzto array will be either NULL (in which case the file should not    be moved) or simple base names.  If fto is TRUE, the files in    pzfrom should be moved to pzto; otherwise, the files in pzto should    be moved to pzfrom (this is used if a temporary failure occurs, in    which case the execution will be retried later).  If pzinput and    *pzinput are not NULL, then it is the name of the standard input    file; if it is the same as any element of pzfrom, then *pzinput    should be set to the zbufcpy of the corresponding pzto value, if    any.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_move_uuxqt_files
name|P
argument_list|(
operator|(
name|int
name|cfiles
operator|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|pzfrom
operator|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|pzto
operator|,
name|boolean
name|fto
operator|,
name|int
name|ilock
operator|,
name|char
operator|*
operator|*
name|pzinput
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Expand a file name on the local system, defaulting to the current    directory.  This is just like zsysdep_local_file, except that    relative files are placed in the working directory the program    started in rather than in the public directory.  This should return    NULL on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_local_file_cwd
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zname
operator|,
specifier|const
name|char
operator|*
name|zpubdir
operator|,
name|boolean
operator|*
name|pfbadname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add the working directory to a file name.  The named file is    actually on a remote system.  If the file already has a directory,    it should not be changed.  This should return NULL on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_add_cwd
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See whether a file name will need the current working directory    when zsysdep_local_file_cwd or zsysdep_add_cwd is called on it.    This will be called before usysdep_initialize.  It should just    check whether the argument is an absolute path.  See the comment    above usysdep_initialize in this file for an explanation of why    things are done this way.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_needs_cwd
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the base name of a file.  The file will be a local file name,    and this function should return the base file name, ideally in a    form which will make sense on most systems; it will be used if the    destination of a uucp is a directory.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_base_name
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return a filename within a directory.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_in_dir
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdir
operator|,
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the mode of a file.  This should return a Unix style file mode.    It should return 0 on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|ixsysdep_file_mode
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See whether the user has access to a file.  This is called by uucp    and uux to prevent copying of a file which uucp can read but the    user cannot.  If access is denied, this should log an error message    and return FALSE.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_access
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See whether the daemon has access to a file.  This is called by    uucp and uux when a file is queued up for transfer without being    copied into the spool directory.  It is merely an early error    check, as the daemon would of course discover the error itself when    it tried the transfer.  If access would be denied, this should log    an error message and return FALSE.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_daemon_access
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate a destination from system!user to a place in the public    directory where uupick will get the file.  On Unix this produces    system!~/receive/user/localname, and that's probably what it has to    produce on any other system as well.  Returns NULL on a usage    error, or otherwise returns string allocated by zbufcpy.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_uuto
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdest
operator|,
specifier|const
name|char
operator|*
name|zlocalname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return TRUE if a pathname exists and is a directory.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_directory
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zpath
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Walk a directory tree.  The zdir argument is the directory to walk.    The pufn argument is a function to call on each regular file in the    tree.  The first argument to pufn should be the full filename; the    second argument to pufn should be the filename relative to zdir;    the third argument to pufn should be the pinfo argument to    usysdep_walk_tree.  The usysdep_walk_tree function should return    FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|usysdep_walk_tree
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdir
operator|,
name|void
argument_list|(
argument|*pufn
argument_list|)
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfull
operator|,
specifier|const
name|char
operator|*
name|zrelative
operator|,
name|pointer
name|pinfo
operator|)
argument_list|)
operator|,
name|pointer
name|pinfo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Return the jobid of a work file, given the sequence value.  On    error this should log an error and return NULL.  The jobid is a    string which may be printed out and read in and passed to    fsysdep_kill_job, etc., but is not otherwise interpreted.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_jobid
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
name|pointer
name|pseq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See whether the current user is privileged.  Privileged users are    permitted to kill jobs submitted by another user, and they are    permitted to use the -u argument to uucico; other uses of this call    may be added later.  This should return TRUE if permission is    granted, FALSE otherwise.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_privileged
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Kill a job, given the jobid.  This should remove all associated    files and in general eliminate the job completely.  On error it    should log an error message and return FALSE.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_kill_job
name|P
argument_list|(
operator|(
name|pointer
name|puuconf
operator|,
specifier|const
name|char
operator|*
name|zjobid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Rejuvenate a job, given the jobid.  If possible, this should update    the time associated with the job such that it will not be    eliminated by uustat -K or similar programs that check the creation    time.  This should affect the return value of ixsysdep_work_time.    On error it should log an error message and return FALSE.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_rejuvenate_job
name|P
argument_list|(
operator|(
name|pointer
name|puuconf
operator|,
specifier|const
name|char
operator|*
name|zjobid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the time a job was queued, given the sequence number.  There is    no way to indicate error.  The return value must use the same epoch    as ixsysdep_time.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|ixsysdep_work_time
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
name|pointer
name|pseq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the time a file was created.  This is called by uustat on    execution files.  There is no way to indicate error.  The return    value must use the same epoch as ixsysdep_time.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|ixsysdep_file_time
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Touch a file to make it appear as though it was created at the    current time.  This is called by uustat on execution files.  On    error this should log an error message and return FALSE.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_touch_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the size in bytes of a file.  If this file does not exist, this    should not give an error message, but should return -1.  If some    other error occurs, this should return -2.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|csysdep_size
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the amount of free space on the containing the given file    name (the file may or may not exist).  If the amount of free space    cannot be determined, the function should return -1.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|csysdep_bytes_free
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start getting status information for all systems with available    status information.  There may be status information for unknown    systems, which is why this series of functions is used.  The phold    argument is used to pass information around, to possibly avoid the    use of static variables.  On error this should log an error and    return FALSE.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_all_status_init
name|P
argument_list|(
operator|(
name|pointer
operator|*
name|phold
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get status information for the next system.  This should return the    system name and fill in the qstat argument.  The phold argument    will be that set by fsysdep_all_status_init.  On error this should    log an error, set *pferr to TRUE, and return NULL.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_all_status
name|P
argument_list|(
operator|(
name|pointer
name|phold
operator|,
name|boolean
operator|*
name|pferr
operator|,
expr|struct
name|sstatus
operator|*
name|qstat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free up anything allocated by fsysdep_all_status_init and    zsysdep_all_status.  The phold argument is that set by    fsysdep_all_status_init.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usysdep_all_status_free
name|P
argument_list|(
operator|(
name|pointer
name|phold
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display the process status of all processes holding lock files.    This is uustat -p.  The return value is passed to usysdep_exit.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_lock_status
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Return TRUE if the user has legitimate access to the port.  This is    used by cu to control whether the user can open a port directly,    rather than merely being able to dial out on it.  Opening a port    directly allows the modem to be reprogrammed.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_port_access
name|P
argument_list|(
operator|(
expr|struct
name|uuconf_port
operator|*
name|qport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return whether the given port could be named by the given line.  On    Unix, the line argument would be something like "ttyd0", and this    function should return TRUE if the named port is "/dev/ttyd0".  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_port_is_line
name|P
argument_list|(
operator|(
expr|struct
name|uuconf_port
operator|*
name|qport
operator|,
specifier|const
name|char
operator|*
name|zline
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the terminal into raw mode.  In this mode no input characters    should be treated specially, and characters should be made    available as they are typed.  The original terminal mode should be    saved, so that it can be restored by fsysdep_terminal_restore.  If    flocalecho is TRUE, then local echoing should still be done;    otherwise echoing should be disabled.  This function returns FALSE    on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_terminal_raw
name|P
argument_list|(
operator|(
name|boolean
name|flocalecho
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Restore the terminal back to the original setting, before    fsysdep_terminal_raw was called.  Returns FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_terminal_restore
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read a line from the terminal.  The fsysdep_terminal_raw function    will have been called.  This should print the zprompt argument    (unless it is NULL) and return the line, allocated by zbufcpy, or    NULL on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_terminal_line
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zprompt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write a line to the terminal, ending with a newline.  This is    basically just puts (zline, stdout), except that the terminal will    be in raw mode, so on ASCII Unix systems the line needs to end with    \r\n.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_terminal_puts
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zline
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If faccept is TRUE, permit the user to generate signals from the    terminal.  If faccept is FALSE, turn signals off again.  After    fsysdep_terminal_raw is called, signals should be off.  Return    FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_terminal_signals
name|P
argument_list|(
operator|(
name|boolean
name|faccept
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The cu program expects the system dependent code to handle the    details of copying data from the communications port to the    terminal.  This should be set up by fsysdep_cu_init, and done while    fsysdep_cu is called.  It is permissible to do it on a continual    basis (on Unix a subprocess handles it) so long as the copying can    be stopped by the fsysdep_cu_copy function.     The fsysdep_cu_init function does any system dependent    initialization needed for this.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_cu_init
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy all data from the communications port to the terminal, and all    data from the terminal to the communications port.  Keep this up    until the escape character *zCuvar_escape is seen.  Set *pbcmd to    the character following the escape character; after the escape    character, zlocalname should be printed, possibly after a delay.    If two escape characters are entered in sequence, this function    should send a single escape character to the port, and not return.    Returns FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_cu
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|char
operator|*
name|pbcmd
operator|,
specifier|const
name|char
operator|*
name|zlocalname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If fcopy is TRUE, start copying data from the communications port    to the terminal.  If fcopy is FALSE, stop copying data.  This    function may be called several times during a cu session.  It    should return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_cu_copy
name|P
argument_list|(
operator|(
name|boolean
name|fcopy
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stop copying data from the communications port to the terminal, and    generally clean up after fsysdep_cu_init and fsysdep_cu.  Returns    FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_cu_finish
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Run a shell command.  If zcmd is NULL, or *zcmd == '\0', just    start up a shell.  The second argument is one of the following    values.  This should return FALSE on error.  */
end_comment

begin_enum
enum|enum
name|tshell_cmd
block|{
comment|/* Attach stdin and stdout to the terminal.  */
name|SHELL_NORMAL
block|,
comment|/* Attach stdout to the communications port, stdin to the terminal.  */
name|SHELL_STDOUT_TO_PORT
block|,
comment|/* Attach stdin to the communications port, stdout to the terminal.  */
name|SHELL_STDIN_FROM_PORT
block|,
comment|/* Attach both stdin and stdout to the communications port.  */
name|SHELL_STDIO_ON_PORT
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_shell
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
specifier|const
name|char
operator|*
name|zcmd
operator|,
expr|enum
name|tshell_cmd
name|tcmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Change directory.  If zdir is NULL, or *zdir == '\0', change to the    user's home directory.  Return FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_chdir
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Suspend the current process.  This is only expected to work on Unix    versions that support SIGTSTP.  In general, people can just shell    out.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_suspend
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Start getting files for uupick.  The zsystem argument may be NULL    to get files from all systems, or it may specify a particular    system.  The zpubdir argument is the public directory to use.  This    returns FALSE on error.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_uupick_init
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsystem
operator|,
specifier|const
name|char
operator|*
name|zpubdir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the next file for uupick.  This returns the basic file name.    It sets *pzfull to the full name, and *pzfrom to the name of the    system which sent this file over; both should be freed using    ubuffree.  *pzfull should be passed to ubuffree after it is no    longer needed.  The zsystem and zpubdir arguments should be the    same as the arguments to fsysdep_uupick_init.  This returns NULL    when all files been returned.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_uupick
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsystem
operator|,
specifier|const
name|char
operator|*
name|zpubdir
operator|,
name|char
operator|*
operator|*
name|pzfrom
operator|,
name|char
operator|*
operator|*
name|pzfull
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clean up after getting files for uupick.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_uupick_free
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsystem
operator|,
specifier|const
name|char
operator|*
name|zpubdir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate a local file name for uupick.  On Unix this is just like    zsysdep_local_file_cwd except that a file beginning with ~/ is    placed in the user's home directory rather than in the public    directory.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsysdep_uupick_local_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|,
name|boolean
operator|*
name|pfbadname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remove a directory and all the files in it.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_rmdir
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (SYSTEM_H) */
end_comment

end_unit

