begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* syshdr.unx -*- C -*-    Unix system header for the uuconf library.     Copyright (C) 1992, 1993 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_comment
comment|/* The root directory (used when setting local-send and local-receive    values).  */
end_comment

begin_define
define|#
directive|define
name|ZROOTDIR
value|"/"
end_define

begin_comment
comment|/* The current directory (used by uuconv as a prefix for the newly    created file names).  */
end_comment

begin_define
define|#
directive|define
name|ZCURDIR
value|"."
end_define

begin_comment
comment|/* The names of the Taylor UUCP configuration files.  These are    appended to NEWCONFIGLIB which is defined in Makefile.  */
end_comment

begin_define
define|#
directive|define
name|CONFIGFILE
value|"/config"
end_define

begin_define
define|#
directive|define
name|SYSFILE
value|"/sys"
end_define

begin_define
define|#
directive|define
name|PORTFILE
value|"/port"
end_define

begin_define
define|#
directive|define
name|DIALFILE
value|"/dial"
end_define

begin_define
define|#
directive|define
name|CALLFILE
value|"/call"
end_define

begin_define
define|#
directive|define
name|PASSWDFILE
value|"/passwd"
end_define

begin_define
define|#
directive|define
name|DIALCODEFILE
value|"/dialcode"
end_define

begin_comment
comment|/* The names of the various V2 configuration files.  These are    appended to OLDCONFIGLIB which is defined in Makefile.  */
end_comment

begin_define
define|#
directive|define
name|V2_SYSTEMS
value|"/L.sys"
end_define

begin_define
define|#
directive|define
name|V2_DEVICES
value|"/L-devices"
end_define

begin_define
define|#
directive|define
name|V2_USERFILE
value|"/USERFILE"
end_define

begin_define
define|#
directive|define
name|V2_CMDS
value|"/L.cmds"
end_define

begin_define
define|#
directive|define
name|V2_DIALCODES
value|"/L-dialcodes"
end_define

begin_comment
comment|/* The names of the HDB configuration files.  These are appended to    OLDCONFIGLIB which is defined in Makefile.  */
end_comment

begin_define
define|#
directive|define
name|HDB_SYSFILES
value|"/Sysfiles"
end_define

begin_define
define|#
directive|define
name|HDB_SYSTEMS
value|"/Systems"
end_define

begin_define
define|#
directive|define
name|HDB_PERMISSIONS
value|"/Permissions"
end_define

begin_define
define|#
directive|define
name|HDB_DEVICES
value|"/Devices"
end_define

begin_define
define|#
directive|define
name|HDB_DIALERS
value|"/Dialers"
end_define

begin_define
define|#
directive|define
name|HDB_DIALCODES
value|"/Dialcodes"
end_define

begin_define
define|#
directive|define
name|HDB_MAXUUXQTS
value|"/Maxuuxqts"
end_define

begin_define
define|#
directive|define
name|HDB_REMOTE_UNKNOWN
value|"/remote.unknown"
end_define

begin_comment
comment|/* A string which is inserted between the value of OLDCONFIGLIB    (defined in the Makefile) and any names specified in the HDB    Sysfiles file.  */
end_comment

begin_define
define|#
directive|define
name|HDB_SEPARATOR
value|"/"
end_define

begin_comment
comment|/* A macro to check whether fopen failed because the file did not    exist.  */
end_comment

begin_define
define|#
directive|define
name|FNO_SUCH_FILE
parameter_list|()
value|(errno == ENOENT)
end_define

begin_if
if|#
directive|if
operator|!
name|HAVE_STRERROR
end_if

begin_comment
comment|/* We need a definition for strerror; normally the function in the    unix directory is used, but we want to be independent of that    library.  This macro evaluates its argument multiple times.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|strerror
parameter_list|(
name|ierr
parameter_list|)
define|\
value|((ierr)>= 0&& (ierr)< sys_nerr ? sys_errlist[ierr] : "unknown error")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_STRERROR */
end_comment

begin_comment
comment|/* This macro is used to make a filename found in a configuration file    into an absolute path.  The zdir argument is the directory to put it    in.  The zset argument is set to the new string.  The fallocated    argument is set to TRUE if the new string was allocated.  */
end_comment

begin_define
define|#
directive|define
name|MAKE_ABSOLUTE
parameter_list|(
name|zset
parameter_list|,
name|fallocated
parameter_list|,
name|zfile
parameter_list|,
name|zdir
parameter_list|,
name|pblock
parameter_list|)
define|\
value|do \     { \       if (*(zfile) == '/') \ 	{ \ 	  (zset) = (zfile); \ 	  (fallocated) = FALSE; \ 	} \       else \ 	{ \ 	  size_t abs_cdir, abs_cfile; \ 	  char *abs_zret; \ \ 	  abs_cdir = strlen (zdir); \ 	  abs_cfile = strlen (zfile); \ 	  abs_zret = (char *) uuconf_malloc ((pblock), \ 					     abs_cdir + abs_cfile + 2); \ 	  (zset) = abs_zret; \ 	  (fallocated) = TRUE; \ 	  if (abs_zret != NULL) \ 	    { \ 	      memcpy ((pointer) abs_zret, (pointer) (zdir), abs_cdir); \ 	      abs_zret[abs_cdir] = '/'; \ 	      memcpy ((pointer) (abs_zret + abs_cdir + 1), \ 		      (pointer) (zfile), abs_cfile + 1); \ 	    } \ 	} \     } \   while (0)
end_define

begin_comment
comment|/* We want to be able to mark the Taylor UUCP system files as close on    exec.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_FILE_H
end_if

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FD_CLOEXEC
end_ifndef

begin_define
define|#
directive|define
name|FD_CLOEXEC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CLOSE_ON_EXEC
parameter_list|(
name|e
parameter_list|)
define|\
value|do \     { \       int cle_i = fileno (e); \  \       fcntl (cle_i, F_SETFD, fcntl (cle_i, F_GETFD, 0) | FD_CLOEXEC); \     } \   while (0)
end_define

end_unit

