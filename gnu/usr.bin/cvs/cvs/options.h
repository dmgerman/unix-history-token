begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *   * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with the CVS source distribution.  *   * This file holds (most of) the configuration tweaks that can be made to  * customize CVS for your site.  CVS comes configured for a typical SunOS 4.x  * environment.  The comments for each configurable item are intended to be  * self-explanatory.  All #defines are tested first to see if an over-riding  * option was specified on the "make" command line.  *   * If special libraries are needed, you will have to edit the Makefile.in file  * or the configure script directly.  Sorry.  */
end_comment

begin_comment
comment|/* By default, CVS stores its modules and other such items in flat    text files (MY_NDBM enables this).  Turning off MY_NDBM causes CVS    to look for a system-supplied ndbm database library and use it    instead.  That may speed things up, but the default setting    generally works fine too.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MY_NDBM
end_ifndef

begin_define
define|#
directive|define
name|MY_NDBM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The "patch" program to run when using the CVS server and accepting  * patches across the network.  Specify a full pathname if your site  * wants to use a particular patch.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PATCH_PROGRAM
end_ifndef

begin_define
define|#
directive|define
name|PATCH_PROGRAM
value|"patch"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Directory used for storing temporary files, if not overridden by    environment variables or the -T global option.  There should be little    need to change this (-T is a better mechanism if you need to use a    different directory for temporary files).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TMPDIR_DFLT
end_ifndef

begin_define
define|#
directive|define
name|TMPDIR_DFLT
value|"/tmp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The default editor to use, if one does not specify the "-e" option  * to cvs, or does not have an EDITOR environment variable.  I set  * this to just "vi", and use the shell to find where "vi" actually  * is.  This allows sites with /usr/bin/vi or /usr/ucb/vi to work  * equally well (assuming that your PATH is reasonable).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EDITOR_DFLT
end_ifndef

begin_define
define|#
directive|define
name|EDITOR_DFLT
value|"vi"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The default umask to use when creating or otherwise setting file or  * directory permissions in the repository.  Must be a value in the  * range of 0 through 0777.  For example, a value of 002 allows group  * rwx access and world rx access; a value of 007 allows group rwx  * access but no world access.  This value is overridden by the value  * of the CVSUMASK environment variable, which is interpreted as an  * octal number.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UMASK_DFLT
end_ifndef

begin_define
define|#
directive|define
name|UMASK_DFLT
value|002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The cvs admin command is restricted to the members of the group  * CVS_ADMIN_GROUP.  If this group does not exist, all users are  * allowed to run cvs admin.  To disable the cvs admin for all users,  * create an empty group CVS_ADMIN_GROUP.  To disable access control  * for cvs admin, comment out the define below.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_ADMIN_GROUP
end_ifndef

begin_define
define|#
directive|define
name|CVS_ADMIN_GROUP
value|"cvsadmin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The Repository file holds the path to the directory within the  * source repository that contains the RCS ,v files for each CVS  * working directory.  This path is either a full-path or a path  * relative to CVSROOT.  *   * The big advantage that I can see to having a relative path is that  * one can change the physical location of the master source  * repository, change the contents of CVS/Root files in your  * checked-out code, and CVS will work without problems.  *  * Therefore, RELATIVE_REPOS is now the default.  In the future, this  * is likely to disappear entirely as a compile-time (or other) option,  * so if you have other software which relies on absolute pathnames,  * update them.  */
end_comment

begin_define
define|#
directive|define
name|RELATIVE_REPOS
value|1
end_define

begin_comment
comment|/*  * When committing or importing files, you must enter a log message.  * Normally, you can do this either via the -m flag on the command  * line or an editor will be started for you.  If you like to use  * logging templates (the rcsinfo file within the $CVSROOT/CVSROOT  * directory), you might want to force people to use the editor even  * if they specify a message with -m.  Enabling FORCE_USE_EDITOR will  * cause the -m message to be appended to the temp file when the  * editor is started.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FORCE_USE_EDITOR
end_ifndef

begin_comment
comment|/* #define 	FORCE_USE_EDITOR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * When locking the repository, some sites like to remove locks and  * assume the program that created them went away if the lock has  * existed for a long time.  This used to be the default for previous  * versions of CVS.  CVS now attempts to be much more robust, so lock  * files should not be left around by mistake. The new behaviour will  * never remove old locks (they must now be removed by hand).  * Enabling CVS_FUDGELOCKS will cause CVS to remove locks that are  * older than CVSLCKAGE seconds.  *   * Use of this option is NOT recommended.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_FUDGELOCKS
end_ifndef

begin_comment
comment|/* #define CVS_FUDGELOCKS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * When committing a permanent change, CVS and RCS make a log entry of  * who committed the change.  If you are committing the change logged  * in as "root" (not under "su" or other root-priv giving program),  * CVS/RCS cannot determine who is actually making the change.  *  * As such, by default, CVS disallows changes to be committed by users  * logged in as "root".  You can disable this option by commenting out  * the lines below.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_BADROOT
end_ifndef

begin_define
define|#
directive|define
name|CVS_BADROOT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define this to enable the SETXID support.  The way to use this is    to create a group with no users in it (except perhaps cvs    administrators), set the cvs executable to setgid that group, chown    all the repository files to that group, and change all directory    permissions in the repository to 770.  The last person to modify a    file will own it, but as long as directory permissions are set    right that won't matter.  You'll need a system which inherits file    groups from the parent directory (WARNING: using the wrong kind of    system (I think Solaris 2.4 is the wrong kind, for example) will    create a security hole!  You will receive no warning other than the    fact that files in the working directory are owned by the group    which cvs is setgid to).     One security hole which has been reported is that setgid is not    turned off when the editor is invoked--most editors provide a way    to execute a shell, or the user can specify an editor (this one is    large enough to drive a truck through).  Don't assume that the    holes described here are the only ones; I don't know how carefully    SETXID has been inspected for security holes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SETXID_SUPPORT
end_ifndef

begin_comment
comment|/* #define SETXID_SUPPORT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Should we build the password-authenticating client?  Whether to  * include the password-authenticating _server_, on the other hand, is  * set in config.h.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|AUTH_CLIENT_SUPPORT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If you are working with a large remote repository and a 'cvs  * checkout' is swamping your network and memory, define these to  * enable flow control.  You will end up with even less probability of  * a consistent checkout (see Concurrency in cvs.texinfo), but CVS  * doesn't try to guarantee that anyway.  The master server process  * will monitor how far it is getting behind, if it reaches the high  * water mark, it will signal the child process to stop generating  * data when convenient (ie: no locks are held, currently at the  * beginning of a new directory).  Once the buffer has drained  * sufficiently to reach the low water mark, it will be signalled to  * start again.  You may override the default hi/low watermarks here  * too.  */
end_comment

begin_define
define|#
directive|define
name|SERVER_FLOWCONTROL
end_define

begin_define
define|#
directive|define
name|SERVER_HI_WATER
value|(2 * 1024 * 1024)
end_define

begin_define
define|#
directive|define
name|SERVER_LO_WATER
value|(1 * 1024 * 1024)
end_define

begin_comment
comment|/* End of CVS configuration section */
end_comment

begin_comment
comment|/*  * Externs that are included in libc, but are used frequently enough  * to warrant defining here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDC_HEADERS
end_ifndef

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

