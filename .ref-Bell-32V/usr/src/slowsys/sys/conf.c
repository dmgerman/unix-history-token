begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
file|"../h/buf.h"
end_include

begin_include
include|#
directive|include
file|"../h/tty.h"
end_include

begin_include
include|#
directive|include
file|"../h/conf.h"
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
file|"../h/file.h"
end_include

begin_include
include|#
directive|include
file|"../h/inode.h"
end_include

begin_include
include|#
directive|include
file|"../h/acct.h"
end_include

begin_include
include|#
directive|include
file|"../h/mba.h"
end_include

begin_function_decl
name|int
name|nulldev
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nodev
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|random
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|hpstrategy
argument_list|()
decl_stmt|,
name|hpread
argument_list|()
decl_stmt|,
name|hpwrite
argument_list|()
decl_stmt|,
name|hpintr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
name|hptab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|htopen
argument_list|()
decl_stmt|,
name|htclose
argument_list|()
decl_stmt|,
name|htstrategy
argument_list|()
decl_stmt|,
name|htread
argument_list|()
decl_stmt|,
name|htwrite
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
name|httab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bdevsw
name|bdevsw
index|[]
init|=
block|{
comment|/* 0 */
name|nulldev
block|,
name|nulldev
block|,
name|hpstrategy
block|,
operator|&
name|hptab
block|,
comment|/* 1 */
name|htopen
block|,
name|htclose
block|,
name|htstrategy
block|,
operator|&
name|httab
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|consopen
argument_list|()
decl_stmt|,
name|consclose
argument_list|()
decl_stmt|,
name|consread
argument_list|()
decl_stmt|,
name|conswrite
argument_list|()
decl_stmt|,
name|consioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dzopen
argument_list|()
decl_stmt|,
name|dzclose
argument_list|()
decl_stmt|,
name|dzread
argument_list|()
decl_stmt|,
name|dzwrite
argument_list|()
decl_stmt|,
name|dzioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tty
name|dz_tty
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|syopen
argument_list|()
decl_stmt|,
name|syread
argument_list|()
decl_stmt|,
name|sywrite
argument_list|()
decl_stmt|,
name|sysioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mmread
argument_list|()
decl_stmt|,
name|mmwrite
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cdevsw
name|cdevsw
index|[]
init|=
block|{
comment|/* 0 */
name|consopen
block|,
name|consclose
block|,
name|consread
block|,
name|conswrite
block|,
name|consioctl
block|,
literal|0
block|,
comment|/* 1 */
name|dzopen
block|,
name|dzclose
block|,
name|dzread
block|,
name|dzwrite
block|,
name|dzioctl
block|,
name|dz_tty
block|,
comment|/* 2 */
name|syopen
block|,
name|nulldev
block|,
name|syread
block|,
name|sywrite
block|,
name|sysioctl
block|,
literal|0
block|,
comment|/* 3 */
name|nulldev
block|,
name|nulldev
block|,
name|mmread
block|,
name|mmwrite
block|,
name|nodev
block|,
literal|0
block|,
comment|/* 4 */
name|nulldev
block|,
name|nulldev
block|,
name|hpread
block|,
name|hpwrite
block|,
name|nodev
block|,
literal|0
block|,
comment|/* 5 */
name|htopen
block|,
name|htclose
block|,
name|htread
block|,
name|htwrite
block|,
name|nodev
block|,
literal|0
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttyopen
argument_list|()
decl_stmt|,
name|ttyclose
argument_list|()
decl_stmt|,
name|ttread
argument_list|()
decl_stmt|,
name|ttwrite
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttyinput
argument_list|()
decl_stmt|,
name|ttstart
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|linesw
name|linesw
index|[]
init|=
block|{
comment|/* 0 */
name|ttyopen
block|,
name|nulldev
block|,
name|ttread
block|,
name|ttwrite
block|,
name|nodev
block|,
name|ttyinput
block|,
name|ttstart
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nldisp
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|rootdev
init|=
name|makedev
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|swapdev
init|=
name|makedev
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|pipedev
init|=
name|makedev
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
name|swplo
init|=
literal|4600
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nswap
init|=
literal|5000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
name|buf
index|[
name|NBUF
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|file
name|file
index|[
name|NFILE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|inode
name|inode
index|[
name|NINODE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|text
name|text
index|[
name|NTEXT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
name|proc
index|[
name|NPROC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
name|bfreelist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|acct
name|acctbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|inode
modifier|*
name|acctp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|usrstack
init|=
operator|(
name|int
operator|*
operator|)
name|USRSTACK
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*tbl*/
end_comment

begin_decl_stmt
name|int
name|mem_no
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* major device number of memory special file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Sysmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|mmap
init|=
block|{
name|Sysmap
operator|+
literal|256
operator|+
literal|16
operator|+
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|u
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|vmmap
init|=
operator|(
name|int
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
operator|&
name|u
operator|+
literal|16
operator|*
literal|512
operator|+
literal|2
operator|*
literal|512
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mbanum
index|[]
init|=
block|{
comment|/* mba number of major device */
literal|0
block|,
comment|/* disk */
literal|1
block|,
comment|/* tape */
literal|9999999
block|,
comment|/* unused */
literal|9999999
block|,
comment|/* unused */
literal|0
block|,
comment|/* disk, raw */
literal|1
block|,
comment|/* tape, raw */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|mbaloc
index|[]
init|=
block|{
comment|/* virtual location of mba */
operator|(
name|int
operator|*
operator|)
name|MBA0
block|,
operator|(
name|int
operator|*
operator|)
name|MBA1
block|, 	}
decl_stmt|;
end_decl_stmt

end_unit

