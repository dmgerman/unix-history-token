begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software_Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	supcdefs.h -- Declarations shared by the collection of files  *			that build the sup client.  *  **********************************************************************  * HISTORY  * 7-July-93  Nate Williams at Montana State University  *	Modified SUP to use gzip based compression when sending files  *	across the network to save BandWidth  *  * $Log: supcdefs.h,v $  * Revision 1.1.1.1  1995/12/26 04:54:46  peter  * Import the unmodified version of the sup that we are using.  * The heritage of this version is not clear.  It appears to be NetBSD  * derived from some time ago.  *  * Revision 1.3  1994/08/11  02:46:21  rich  * Added extensions written by David Dawes.  From the man page:  *  * The -u flag, or the noupdate supfile option prevent updates from  * occurring for regular files where the modification time and mode  * hasn't changed.  *  * Now, how do we feed these patches back to CMU for consideration?  *  * Revision 1.2  1994/06/20  06:04:06  rgrimes  * Humm.. they did a lot of #if __STDC__ but failed to properly prototype  * the code.  Also fixed one bad argument to a wait3 call.  *  * It won't compile -Wall, but atleast it compiles standard without warnings  * now.  *  * Revision 1.1.1.1  1993/08/21  00:46:34  jkh  * Current sup with compression support.  *  * Revision 1.1.1.1  1993/05/21  14:52:18  cgd  * initial import of CMU's SUP to NetBSD  *  * Revision 1.6  92/08/11  12:06:52  mrt  * 	Added CFURELSUF  - use-release-suffix flag  * 	Made rpause code conditional on MACH rather than CMUCS  * 	[92/07/26            mrt]  *   * Revision 1.5  92/02/08  18:23:57  mja  * 	Added CFKEEP flag.  * 	[92/01/17            vdelvecc]  *   * 10-Feb-88  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added timeout for backoff.  *  * 28-Jun-87  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added Crelease for "release" support.  *  * 25-May-87  Doug Philips (dwp) at Carnegie-Mellon University  *	Created.  *  **********************************************************************  */
end_comment

begin_include
include|#
directive|include
file|<libc.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_if
if|#
directive|if
name|MACH
end_if

begin_comment
comment|/* used by resource pausing code only */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MACH */
end_comment

begin_include
include|#
directive|include
file|<c.h>
end_include

begin_include
include|#
directive|include
file|"sup.h"
end_include

begin_include
include|#
directive|include
file|"supmsg.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|uid_t
name|getuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|gid_t
name|getgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|PGMVERSION
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************  ***    D A T A   S T R U C T U R E S    ***  *******************************************/
end_comment

begin_struct
struct|struct
name|collstruct
block|{
comment|/* one per collection to be upgraded */
name|char
modifier|*
name|Cname
decl_stmt|;
comment|/* collection name */
name|TREE
modifier|*
name|Chost
decl_stmt|;
comment|/* attempted host for collection */
name|TREE
modifier|*
name|Chtree
decl_stmt|;
comment|/* possible hosts for collection */
name|char
modifier|*
name|Cbase
decl_stmt|;
comment|/* local base directory */
name|char
modifier|*
name|Chbase
decl_stmt|;
comment|/* remote base directory */
name|char
modifier|*
name|Cprefix
decl_stmt|;
comment|/* local collection pathname prefix */
name|char
modifier|*
name|Crelease
decl_stmt|;
comment|/* release name */
name|char
modifier|*
name|Cnotify
decl_stmt|;
comment|/* user to notify of status */
name|char
modifier|*
name|Clogin
decl_stmt|;
comment|/* remote login name */
name|char
modifier|*
name|Cpswd
decl_stmt|;
comment|/* remote password */
name|char
modifier|*
name|Ccrypt
decl_stmt|;
comment|/* data encryption key */
name|char
modifier|*
name|Crenamelog
decl_stmt|;
comment|/* Where to log files moved when busy */
name|int
name|Ctimeout
decl_stmt|;
comment|/* timeout for backoff */
name|int
name|Cflags
decl_stmt|;
comment|/* collection flags */
name|int
name|Cnogood
decl_stmt|;
comment|/* upgrade no good, "when" unchanged */
name|int
name|Clockfd
decl_stmt|;
comment|/*>= 0 if collection is locked */
name|struct
name|collstruct
modifier|*
name|Cnext
decl_stmt|;
comment|/* next collection */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|collstruct
name|COLLECTION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CFALL
value|0x0001
end_define

begin_define
define|#
directive|define
name|CFBACKUP
value|0x0002
end_define

begin_define
define|#
directive|define
name|CFDELETE
value|0x0004
end_define

begin_define
define|#
directive|define
name|CFEXECUTE
value|0x0008
end_define

begin_define
define|#
directive|define
name|CFLIST
value|0x0010
end_define

begin_define
define|#
directive|define
name|CFLOCAL
value|0x0020
end_define

begin_define
define|#
directive|define
name|CFMAIL
value|0x0040
end_define

begin_define
define|#
directive|define
name|CFOLD
value|0x0080
end_define

begin_define
define|#
directive|define
name|CFVERBOSE
value|0x0100
end_define

begin_define
define|#
directive|define
name|CFKEEP
value|0x0200
end_define

begin_define
define|#
directive|define
name|CFURELSUF
value|0x0400
end_define

begin_define
define|#
directive|define
name|CFCOMPRESS
value|0x0800
end_define

begin_define
define|#
directive|define
name|CFNOUPDATE
value|0x1000
end_define

begin_define
define|#
directive|define
name|CFUNLINKBUSY
value|0x2000
end_define

begin_comment
comment|/*************************  ***	M A C R O S    ***  *************************/
end_comment

begin_define
define|#
directive|define
name|vnotify
value|if (thisC->Cflags&CFVERBOSE)  notify
end_define

begin_comment
comment|/*  * C prototypes  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
name|void
name|done
name|__P
argument_list|(
operator|(
name|int
name|value
operator|,
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|goaway
name|__P
argument_list|(
operator|(
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|notify
name|__P
argument_list|(
operator|(
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

