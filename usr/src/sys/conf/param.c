begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	param.c	6.3	84/01/09	*/
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/systm.h"
end_include

begin_include
include|#
directive|include
file|"../h/socket.h"
end_include

begin_include
include|#
directive|include
file|"../h/dir.h"
end_include

begin_include
include|#
directive|include
file|"../h/user.h"
end_include

begin_include
include|#
directive|include
file|"../h/proc.h"
end_include

begin_include
include|#
directive|include
file|"../h/text.h"
end_include

begin_include
include|#
directive|include
file|"../h/inode.h"
end_include

begin_include
include|#
directive|include
file|"../h/file.h"
end_include

begin_include
include|#
directive|include
file|"../h/callout.h"
end_include

begin_include
include|#
directive|include
file|"../h/clist.h"
end_include

begin_include
include|#
directive|include
file|"../h/cmap.h"
end_include

begin_include
include|#
directive|include
file|"../h/mbuf.h"
end_include

begin_include
include|#
directive|include
file|"../h/nami.h"
end_include

begin_include
include|#
directive|include
file|"../h/quota.h"
end_include

begin_include
include|#
directive|include
file|"../h/kernel.h"
end_include

begin_comment
comment|/*  * System parameter formulae.  *  * This file is copied into each directory where we compile  * the kernel; it should be modified there to suit local taste  * if necessary.  *  * Compiled with -DHZ=xx -DTIMEZONE=x -DDST=x -DMAXUSERS=xx  */
end_comment

begin_define
define|#
directive|define
name|HZ
value|100
end_define

begin_decl_stmt
name|int
name|hz
init|=
name|HZ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tick
init|=
literal|1000000
operator|/
name|HZ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timezone
name|tz
init|=
block|{
name|TIMEZONE
block|,
name|DST
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NPROC
value|(20 + 8 * MAXUSERS)
end_define

begin_decl_stmt
name|int
name|nproc
init|=
name|NPROC
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_define
define|#
directive|define
name|NETSLOP
value|20
end_define

begin_comment
comment|/* for all the lousy servers*/
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NETSLOP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NCHSIZE
value|(60 + 2 * MAXUSERS)
end_define

begin_decl_stmt
name|int
name|nchsize
init|=
name|NCHSIZE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ntext
init|=
literal|24
operator|+
name|MAXUSERS
operator|+
name|NETSLOP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ninode
init|=
operator|(
name|NPROC
operator|+
literal|16
operator|+
name|MAXUSERS
operator|+
operator|(
literal|2
operator|*
name|NCHSIZE
operator|/
literal|3
operator|)
operator|)
operator|+
literal|32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfile
init|=
literal|16
operator|*
operator|(
name|NPROC
operator|+
literal|16
operator|+
name|MAXUSERS
operator|)
operator|/
literal|10
operator|+
literal|32
operator|+
literal|2
operator|*
name|NETSLOP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncallout
init|=
literal|16
operator|+
name|NPROC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nclist
init|=
literal|100
operator|+
literal|16
operator|*
name|MAXUSERS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nport
init|=
name|NPROC
operator|/
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nmbclusters
init|=
name|NMBCLUSTERS
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|QUOTA
end_ifdef

begin_decl_stmt
name|int
name|nquota
init|=
operator|(
name|MAXUSERS
operator|*
literal|9
operator|)
operator|/
literal|7
operator|+
literal|3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ndquot
init|=
operator|(
name|MAXUSERS
operator|*
name|NMOUNT
operator|)
operator|/
literal|4
operator|+
name|NPROC
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These are initialized at bootstrap time  * to values dependent on memory size  */
end_comment

begin_decl_stmt
name|int
name|nbuf
decl_stmt|,
name|nswbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * These have to be allocated somewhere; allocating  * them here forces loader errors if this file is omitted.  */
end_comment

begin_decl_stmt
name|struct
name|proc
modifier|*
name|proc
decl_stmt|,
modifier|*
name|procNPROC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|text
modifier|*
name|text
decl_stmt|,
modifier|*
name|textNTEXT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|inode
modifier|*
name|inode
decl_stmt|,
modifier|*
name|inodeNINODE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|file
modifier|*
name|file
decl_stmt|,
modifier|*
name|fileNFILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|callout
modifier|*
name|callout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cblock
modifier|*
name|cfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
modifier|*
name|buf
decl_stmt|,
modifier|*
name|swbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|swsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|swpf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|buffers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cmap
modifier|*
name|cmap
decl_stmt|,
modifier|*
name|ecmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nch
modifier|*
name|nch
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|QUOTA
end_ifdef

begin_decl_stmt
name|struct
name|quota
modifier|*
name|quota
decl_stmt|,
modifier|*
name|quotaNQUOTA
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dquot
modifier|*
name|dquot
decl_stmt|,
modifier|*
name|dquotNDQUOT
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

