begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ftamsystem.h - include file for FTAM responder */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/ftam2/RCS/ftamsystem.h,v 7.2 91/02/22 09:24:10 mrose Interim $  *  *  * $Log:	ftamsystem.h,v $  * Revision 7.2  91/02/22  09:24:10  mrose  * Interim 6.8  *   * Revision 7.1  90/11/05  13:30:00  mrose  * nist  *   * Revision 7.0  89/11/23  21:54:41  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"ftamsbr.h"
end_include

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_define
define|#
directive|define
name|SCPYN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strncpy ((a), (b), sizeof (a))
end_define

begin_comment
comment|/*
comment|SERVER */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ftamfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|myname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ftam_adios
argument_list|()
decl_stmt|,
name|ftam_advise
argument_list|()
decl_stmt|,
name|ftam_diag
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|adios
argument_list|()
decl_stmt|,
name|advise
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|UNIX DATA */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|myuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|myhomelen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|myhome
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dev_t
name|null_dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ino_t
name|null_ino
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|VFS DATA */
end_comment

begin_define
define|#
directive|define
name|NMAX
value|8
end_define

begin_comment
comment|/* too painful to get right! */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NGROUPS
end_ifndef

begin_define
define|#
directive|define
name|NACCT
value|32
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NACCT
value|(NGROUPS + 20)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|vfsmap
name|vfs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ordering affects default action in st2vfs() 				   put preferential entries towards the end */
end_comment

begin_define
define|#
directive|define
name|VFS_UBF
value|0
end_define

begin_comment
comment|/* offset to FTAM-3 */
end_comment

begin_define
define|#
directive|define
name|VFS_UTF
value|1
end_define

begin_comment
comment|/*  ..       FTAM-1 */
end_comment

begin_define
define|#
directive|define
name|VFS_FDF
value|2
end_define

begin_comment
comment|/*  ..       NIST-9 */
end_comment

begin_comment
comment|/*
comment|REGIME DATA */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|class
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|units
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|attrs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fadusize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|ACTIVITY DATA */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|myfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|myfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stat
name|myst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|statok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vfsmap
modifier|*
name|myvf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active contents type */
end_comment

begin_decl_stmt
specifier|extern
name|caddr_t
name|myparam
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   .. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|myaccess
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current access request */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|initiator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current initiator identity */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|FADUidentity
name|mylocation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current location */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mymode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current processing mode */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|myoperation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   .. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_decl_stmt
specifier|extern
name|AEI
name|mycalling
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current calling AET */
end_comment

begin_decl_stmt
specifier|extern
name|AEI
name|myresponding
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current responding AET */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|account
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current account */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mygid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "inner" account */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mylock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current concurrency control */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|FTAMconcurrency
name|myconctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* .. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mylockstyle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current locking style */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mycontext
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current access context */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mylevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   .. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS5
end_ifndef

begin_define
define|#
directive|define
name|unlock
parameter_list|()
value|if (mylock) (void) flock (myfd, LOCK_UN); else
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|unlock
parameter_list|()
define|\
value|if (mylock) { \ 	struct flock fs; \  \ 	fs.l_type = F_UNLCK; \ 	fs.l_whence = L_SET; \ 	fs.l_start = fs.l_len = 0; \ 	(void) fcntl (myfd, F_SETLK,&fs); \     } \     else
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BRIDGE
end_ifdef

begin_comment
comment|/* FTP interface routines and variables */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ftp_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ftp_exits
argument_list|()
decl_stmt|,
name|ftp_delete
argument_list|()
decl_stmt|,
name|ftp_mkdir
argument_list|()
decl_stmt|,
name|ftp_rename
argument_list|()
decl_stmt|,
name|ftp_type
argument_list|()
decl_stmt|,
name|ftp_write
argument_list|()
decl_stmt|,
name|ftp_append
argument_list|()
decl_stmt|,
name|ftp_read
argument_list|()
decl_stmt|,
name|ftp_ls
argument_list|()
decl_stmt|,
name|ftp_login
argument_list|()
decl_stmt|,
name|ftp_quit
argument_list|()
decl_stmt|,
name|ftp_abort
argument_list|()
decl_stmt|,
name|ftp_reply
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

