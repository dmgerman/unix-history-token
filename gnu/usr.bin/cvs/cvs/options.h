begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* src/options.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *   * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with the CVS 1.4 kit.  *   * This file holds (most of) the configuration tweaks that can be made to  * customize CVS for your site.  CVS comes configured for a typical SunOS 4.x  * environment.  The comments for each configurable item are intended to be  * self-explanatory.  All #defines are tested first to see if an over-riding  * option was specified on the "make" command line.  *   * If special libraries are needed, you will have to edit the Makefile.in file  * or the configure script directly.  Sorry.  */
end_comment

begin_comment
comment|/*  * CVS provides the most features when used in conjunction with the Version-5  * release of RCS.  Thus, it is the default.  This also assumes that GNU diff  * Version-1.15 is being used as well -- you will have to configure your RCS  * V5 release separately to make this the case. If you do not have RCS V5 and  * GNU diff V1.15, comment out this define. You should not try mixing and  * matching other combinations of these tools.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_RCS5
end_ifndef

begin_define
define|#
directive|define
name|HAVE_RCS5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If, before installing this version of CVS, you were running RCS V4 AND you  * are installing this CVS and RCS V5 and GNU diff 1.15 all at the same time,  * you should turn on the following define.  It only exists to try to do  * reasonable things with your existing checked out files when you upgrade to  * RCS V5, since the keyword expansion formats have changed with RCS V5.  *   * If you already have been running with RCS5, or haven't been running with CVS  * yet at all, or are sticking with RCS V4 for now, leave the commented out.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAD_RCS4
end_ifndef

begin_comment
comment|/* #define	HAD_RCS4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For portability and heterogeneity reasons, CVS is shipped by default using  * my own text-file version of the ndbm database library in the src/myndbm.c  * file.  If you want better performance and are not concerned about  * heterogeneous hosts accessing your modules file, turn this option off.  */
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
comment|/*  * The "diff" program to execute when creating patch output.  This "diff"  * must support the "-c" option for context diffing.  Specify a full  * pathname if your site wants to use a particular diff.  Note that unlike  * the diff used with RCS, you *must not* supply -a here (doing so will cause  * the server to generate patches which patch cannot handle in some cases).  *   * NOTE: this program is only used for the ``patch'' sub-command (and  * for ``update'' if you are using the server).  The other commands  * use rcsdiff which will use whatever version of diff was specified  * when rcsdiff was built on your system.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIFF
end_ifndef

begin_define
define|#
directive|define
name|DIFF
value|"diff"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The "grep" program to execute when checking to see if a merged file had  * any conflicts.  This "grep" must support a standard basic  * regular expression as an argument.  Specify a full pathname if your site  * wants to use a particular grep.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GREP
end_ifndef

begin_define
define|#
directive|define
name|GREP
value|"grep"
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
comment|/*  * By default, RCS programs are executed with the shell or through execlp(),  * so the user's PATH environment variable is searched.  If you'd like to  * bind all RCS programs to a certain directory (perhaps one not in most  * people's PATH) then set the default in RCSBIN_DFLT.  Note that setting  * this here will cause all RCS programs to be executed from this directory,  * unless the user overrides the default with the RCSBIN environment variable  * or the "-b" option to CVS.  *   * If you use the password-authenticating server, then you need to  * make sure that the server can find the RCS programs to invoke them.  * The authenticating server starts out running as root, and then  * switches to run as the appropriate user once authentication is  * complete.  But no actual shell is ever started by that user, so the  * PATH environment variable may not contain the directory with the  * RCS binaries, even though if that user logged in normally, PATH  * would include the directory.    *  * One way to solve this problem is to set RCSBIN_DFLT here.  An  * alternative is to make sure that root has the right directory in  * its path already.  Another, probably better alternative is to  * specify -b in /etc/inetd.conf.   *  * This define should be either the empty string ("") or a full  * pathname to the directory containing all the installed programs  * from the RCS distribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RCSBIN_DFLT
end_ifndef

begin_define
define|#
directive|define
name|RCSBIN_DFLT
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The default editor to use, if one does not specify the "-e" option to cvs,  * or does not have an EDITOR environment variable.  I set this to just "vi",  * and use the shell to find where "vi" actually is.  This allows sites with  * /usr/bin/vi or /usr/ucb/vi to work equally well (assuming that your PATH  * is reasonable).  */
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
comment|/*  * The cvs admin command is restricted to the members of the group  * CVS_ADMIN_GROUP.  If this group does not exist, all users are  * allowed to run cvs admin.  To disable the cvs admin for all users,  * create an empty group CVS_ADMIN_GROUP.  To disable access control for  * cvs admin, comment out the define below.  */
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
comment|/*  * The Repository file holds the path to the directory within the source  * repository that contains the RCS ,v files for each CVS working directory.  * This path is either a full-path or a path relative to CVSROOT.  *   * The only advantage that I can see to having a relative path is that One can  * change the physical location of the master source repository, change one's  * CVSROOT environment variable, and CVS will work without problems.  I  * recommend using full-paths.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RELATIVE_REPOS
end_ifndef

begin_comment
comment|/* #define	RELATIVE_REPOS	 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * When committing or importing files, you must enter a log message.  * Normally, you can do this either via the -m flag on the command line or an  * editor will be started for you.  If you like to use logging templates (the  * rcsinfo file within the $CVSROOT/CVSROOT directory), you might want to  * force people to use the editor even if they specify a message with -m.  * Enabling FORCE_USE_EDITOR will cause the -m message to be appended to the  * temp file when the editor is started.  */
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
comment|/*  * When locking the repository, some sites like to remove locks and assume  * the program that created them went away if the lock has existed for a long  * time.  This used to be the default for previous versions of CVS.  CVS now  * attempts to be much more robust, so lock files should not be left around  * by mistake. The new behaviour will never remove old locks (they must now  * be removed by hand).  Enabling CVS_FUDGELOCKS will cause CVS to remove  * locks that are older than CVSLCKAGE seconds.  * Use of this option is NOT recommended.  */
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
comment|/*  * When committing a permanent change, CVS and RCS make a log entry of  * who committed the change.  If you are committing the change logged in  * as "root" (not under "su" or other root-priv giving program), CVS/RCS  * cannot determine who is actually making the change.  *  * As such, by default, CVS disallows changes to be committed by users  * logged in as "root".  You can disable this option by commenting  * out the lines below.  */
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
comment|/*  * The "cvs diff" command accepts all the single-character options that GNU  * diff (1.15) accepts.  Except -D.  GNU diff uses -D as a way to put  * cpp-style #define's around the output differences.  CVS, by default, uses  * -D to specify a free-form date (like "cvs diff -D '1 week ago'").  If  * you would prefer that the -D option of "cvs diff" work like the GNU diff  * option, then comment out this define.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_DIFFDATE
end_ifndef

begin_define
define|#
directive|define
name|CVS_DIFFDATE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define this to enable the SETXID support.  The way to use this is    to create a group with no users in it (except perhaps cvs    administrators), set the cvs executable to setgid that group, chown    all the repository files to that group, and change all directory    permissions in the repository to 770.  The last person to modify a    file will own it, but as long as directory permissions are set    right that won't matter.  You'll need a system which inherits file    groups from the parent directory.  I don't know how carefully this    has been inspected for security holes.  */
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
comment|/* Should we build the password-authenticating client?  Whether to    include the password-authenticating _server_, on the other hand, is    set in config.h.  */
end_comment

begin_define
define|#
directive|define
name|AUTH_CLIENT_SUPPORT
value|1
end_define

begin_comment
comment|/*  * If you are working with a large remote repository and a 'cvs checkout' is  * swamping your network and memory, define these to enable flow control.  * You will end up with even less guarantees of a consistant checkout,  * but that may be better than no checkout at all.  The master server process  * will monitor how far it is getting behind, if it reaches the high water  * mark, it will signal the child process to stop generating data when  * convenient (ie: no locks are held, currently at the beginning of a   * new directory).  Once the buffer has drained sufficiently to reach the  * low water mark, it will be signalled to start again.  * -- EXPERIMENTAL! --  A better solution may be in the works.  * You may override the default hi/low watermarks here too.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERVER_FLOWCONTROL
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End of CVS configuration section */
end_comment

begin_comment
comment|/*  * Externs that are included in libc, but are used frequently enough to  * warrant defining here.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|getwd
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

