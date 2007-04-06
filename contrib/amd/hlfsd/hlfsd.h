begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2004 Erez Zadok  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: hlfsd.h,v 1.4.2.7 2004/01/06 03:15:23 ezk Exp $  * $FreeBSD$  *  * HLFSD was written at Columbia University Computer Science Department, by  * Erez Zadok<ezk@cs.columbia.edu> and Alexander Dupuy<dupuy@cs.columbia.edu>  * It is being distributed under the same terms and conditions as amd does.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HLFSD_HLFS_H
end_ifndef

begin_define
define|#
directive|define
name|_HLFSD_HLFS_H
end_define

begin_comment
comment|/*  * MACROS AND CONSTANTS:  */
end_comment

begin_define
define|#
directive|define
name|HLFSD_VERSION
value|"hlfsd 1.2 (1993-2002)"
end_define

begin_define
define|#
directive|define
name|PERS_SPOOLMODE
value|0755
end_define

begin_define
define|#
directive|define
name|OPEN_SPOOLMODE
value|01777
end_define

begin_define
define|#
directive|define
name|DOTSTRING
value|"."
end_define

begin_comment
comment|/*  * ROOTID and SLINKID are the fixed "faked" node IDs (inodes) for  * the '.' (also '..') and the one symlink within the hlfs.  * They must always be unique, and should never match what a UID  * could be.  * They used to be -1 and -2, respectively.  *  * I used to cast these to (uid_t) but it failed to compile  * with /opt/SUNWspro/bin/cc because uid_t is long, while struct fattr's  * uid field is u_int.  Then it failed to compile on some linux systems  * which define uid_t to be unsigned short, so I used the lowest common  * size which is unsigned short.  */
end_comment

begin_comment
comment|/*  * XXX: this will cause problems to systems with UIDs greater than  * MAX_UNSIGNED_SHORT-3.  */
end_comment

begin_define
define|#
directive|define
name|ROOTID
value|(((unsigned short) ~0) - 1)
end_define

begin_define
define|#
directive|define
name|SLINKID
value|(((unsigned short) ~0) - 2)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|INVALIDID
end_ifndef

begin_comment
comment|/* this is also defined in include/am_utils.h */
end_comment

begin_define
define|#
directive|define
name|INVALIDID
value|(((unsigned short) ~0) - 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INVALIDID */
end_comment

begin_define
define|#
directive|define
name|DOTCOOKIE
value|1
end_define

begin_define
define|#
directive|define
name|DOTDOTCOOKIE
value|2
end_define

begin_define
define|#
directive|define
name|SLINKCOOKIE
value|3
end_define

begin_define
define|#
directive|define
name|ALT_SPOOLDIR
value|"/var/hlfs"
end_define

begin_comment
comment|/* symlink to use if others fail */
end_comment

begin_define
define|#
directive|define
name|HOME_SUBDIR
value|".hlfsdir"
end_define

begin_comment
comment|/* dirname in user's home dir */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_DIRNAME
value|"/hlfs/home"
end_define

begin_define
define|#
directive|define
name|DEFAULT_INTERVAL
value|900
end_define

begin_comment
comment|/* secs b/t re-reads of the password maps */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CACHE_INTERVAL
value|300
end_define

begin_comment
comment|/* secs during which assume a link is up */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_HLFS_GROUP
value|"hlfs"
end_define

begin_comment
comment|/* Group name for special hlfs_gid */
end_comment

begin_define
define|#
directive|define
name|PROGNAMESZ
value|(MAXHOSTNAMELEN - 5)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYSLOG
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_LOGFILE
value|"syslog"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE)_SYSLOG */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_LOGFILE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE)_SYSLOG */
end_comment

begin_define
define|#
directive|define
name|ERRM
value|": %m"
end_define

begin_define
define|#
directive|define
name|fatalerror
parameter_list|(
name|str
parameter_list|)
define|\
value|(fatal (strcat (strnsave ((str), strlen ((str)) + sizeof (ERRM) - 1), ERRM)))
end_define

begin_comment
comment|/*  * TYPEDEFS:  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|uid2home_t
name|uid2home_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|username2uid_t
name|username2uid_t
typedef|;
end_typedef

begin_comment
comment|/*  * STRUCTURES:  */
end_comment

begin_struct
struct|struct
name|uid2home_t
block|{
name|uid_t
name|uid
decl_stmt|;
comment|/* XXX: with or without UID_OFFSET? */
name|pid_t
name|child
decl_stmt|;
name|char
modifier|*
name|home
decl_stmt|;
comment|/* really allocated */
name|char
modifier|*
name|uname
decl_stmt|;
comment|/* an xref ptr to username2uid_t->username */
name|u_long
name|last_access_time
decl_stmt|;
name|int
name|last_status
decl_stmt|;
comment|/* 0=used $HOME/.hlfsspool; !0=used alt dir */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|username2uid_t
block|{
name|char
modifier|*
name|username
decl_stmt|;
comment|/* really allocated */
name|uid_t
name|uid
decl_stmt|;
comment|/* XXX: with or without UID_OFFSET? */
name|char
modifier|*
name|home
decl_stmt|;
comment|/* an xref ptr to uid2home_t->home */
block|}
struct|;
end_struct

begin_comment
comment|/*  * EXTERNALS:  */
end_comment

begin_function_decl
specifier|extern
name|RETSIGTYPE
name|cleanup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|RETSIGTYPE
name|interlock
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|SVCXPRT
modifier|*
name|nfs_program_2_transp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For quick_reply() */
end_comment

begin_decl_stmt
specifier|extern
name|SVCXPRT
modifier|*
name|nfsxprt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|alt_spooldir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|home_subdir
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|homedir
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mailbox
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|passwdfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|slinkname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gid_t
name|hlfs_gid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cache_interval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|noverify
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|serverpid
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|untab_index
parameter_list|(
name|char
modifier|*
name|username
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|am_nfs_fh
modifier|*
name|root_fhp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|am_nfs_fh
name|root
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nfstime
name|startup
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|uid2home_t
modifier|*
name|plt_search
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|username2uid_t
modifier|*
name|untab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user name table */
end_comment

begin_function_decl
specifier|extern
name|void
name|fatal
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|plt_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hlfsd_init_filehandles
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUG_PRINT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|plt_dump
parameter_list|(
name|uid2home_t
modifier|*
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|plt_print
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DEBUG) || defined(DEBUG_PRINT) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HLFSD_HLFS_H */
end_comment

end_unit

