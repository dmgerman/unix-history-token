begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	conf.c	4.3	%G%	*/
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
file|"../h/proc.h"
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
file|"../h/pte.h"
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

begin_include
include|#
directive|include
file|"../conf/hp.h"
end_include

begin_if
if|#
directive|if
name|NHP
operator|>
literal|0
end_if

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

begin_define
define|#
directive|define
name|HPTAB
value|&hptab
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|hpstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|hpread
value|nodev
end_define

begin_define
define|#
directive|define
name|hpwrite
value|nodev
end_define

begin_define
define|#
directive|define
name|hpintr
value|nodev
end_define

begin_define
define|#
directive|define
name|HTTAB
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"../conf/ht.h"
end_include

begin_if
if|#
directive|if
name|NHT
operator|>
literal|0
end_if

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

begin_define
define|#
directive|define
name|HTTAB
value|&httab
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|htopen
value|nodev
end_define

begin_define
define|#
directive|define
name|htclose
value|nodev
end_define

begin_define
define|#
directive|define
name|htstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|htread
value|nodev
end_define

begin_define
define|#
directive|define
name|htwrite
value|nodev
end_define

begin_define
define|#
directive|define
name|HTTAB
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"../conf/up.h"
end_include

begin_if
if|#
directive|if
name|NUP
operator|>
literal|0
end_if

begin_decl_stmt
name|int
name|upstrategy
argument_list|()
decl_stmt|,
name|upread
argument_list|()
decl_stmt|,
name|upwrite
argument_list|()
decl_stmt|,
name|upreset
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
name|uptab
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UPTAB
value|&uptab
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|upstrategy
value|nodev
end_define

begin_define
define|#
directive|define
name|upread
value|nodev
end_define

begin_define
define|#
directive|define
name|upwrite
value|nodev
end_define

begin_define
define|#
directive|define
name|upreset
value|nulldev
end_define

begin_define
define|#
directive|define
name|UPTAB
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|swstrategy
argument_list|()
decl_stmt|,
name|swread
argument_list|()
decl_stmt|,
name|swwrite
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bdevsw
name|bdevsw
index|[]
init|=
block|{
name|nulldev
block|,
name|nulldev
block|,
name|hpstrategy
block|,
name|HPTAB
block|,
comment|/*0*/
name|htopen
block|,
name|htclose
block|,
name|htstrategy
block|,
name|HTTAB
block|,
comment|/*1*/
name|nulldev
block|,
name|nulldev
block|,
name|upstrategy
block|,
name|UPTAB
block|,
comment|/*2*/
comment|/* 3 reserved for rk07 */
name|nodev
block|,
name|nodev
block|,
name|nodev
block|,
literal|0
block|,
comment|/*3*/
name|nodev
block|,
name|nodev
block|,
name|swstrategy
block|,
literal|0
block|,
comment|/*4*/
comment|/* 5 reserved for tm03 */
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cnopen
argument_list|()
decl_stmt|,
name|cnclose
argument_list|()
decl_stmt|,
name|cnread
argument_list|()
decl_stmt|,
name|cnwrite
argument_list|()
decl_stmt|,
name|cnioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"../conf/dh.h"
end_include

begin_if
if|#
directive|if
name|NDH11
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|dhopen
value|nodev
end_define

begin_define
define|#
directive|define
name|dhclose
value|nodev
end_define

begin_define
define|#
directive|define
name|dhread
value|nodev
end_define

begin_define
define|#
directive|define
name|dhwrite
value|nodev
end_define

begin_define
define|#
directive|define
name|dhioctl
value|nodev
end_define

begin_define
define|#
directive|define
name|dhstop
value|nodev
end_define

begin_define
define|#
directive|define
name|dhreset
value|nulldev
end_define

begin_define
define|#
directive|define
name|dh11
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|dhopen
argument_list|()
decl_stmt|,
name|dhclose
argument_list|()
decl_stmt|,
name|dhread
argument_list|()
decl_stmt|,
name|dhwrite
argument_list|()
decl_stmt|,
name|dhioctl
argument_list|()
decl_stmt|,
name|dhstop
argument_list|()
decl_stmt|,
name|dhreset
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tty
name|dh11
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|flopen
argument_list|()
decl_stmt|,
name|flclose
argument_list|()
decl_stmt|,
name|flread
argument_list|()
decl_stmt|,
name|flwrite
argument_list|()
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"../conf/dz.h"
end_include

begin_if
if|#
directive|if
name|NDZ11
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|dzopen
value|nodev
end_define

begin_define
define|#
directive|define
name|dzclose
value|nodev
end_define

begin_define
define|#
directive|define
name|dzread
value|nodev
end_define

begin_define
define|#
directive|define
name|dzwrite
value|nodev
end_define

begin_define
define|#
directive|define
name|dzioctl
value|nodev
end_define

begin_define
define|#
directive|define
name|dzstop
value|nodev
end_define

begin_define
define|#
directive|define
name|dzreset
value|nulldev
end_define

begin_define
define|#
directive|define
name|dz_tty
value|0
end_define

begin_else
else|#
directive|else
end_else

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
decl_stmt|,
name|dzstop
argument_list|()
decl_stmt|,
name|dzreset
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

begin_endif
endif|#
directive|endif
end_endif

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
name|syioctl
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

begin_include
include|#
directive|include
file|"../conf/va.h"
end_include

begin_if
if|#
directive|if
name|NVA
operator|>
literal|0
end_if

begin_decl_stmt
name|int
name|vaopen
argument_list|()
decl_stmt|,
name|vaclose
argument_list|()
decl_stmt|,
name|vawrite
argument_list|()
decl_stmt|,
name|vaioctl
argument_list|()
decl_stmt|,
name|vareset
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vaopen
value|nodev
end_define

begin_define
define|#
directive|define
name|vaclose
value|nodev
end_define

begin_define
define|#
directive|define
name|vawrite
value|nodev
end_define

begin_define
define|#
directive|define
name|vaopen
value|nodev
end_define

begin_define
define|#
directive|define
name|vaioctl
value|nodev
end_define

begin_define
define|#
directive|define
name|vareset
value|nulldev
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"../conf/vp.h"
end_include

begin_if
if|#
directive|if
name|NVP
operator|>
literal|0
end_if

begin_decl_stmt
name|int
name|vpopen
argument_list|()
decl_stmt|,
name|vpclose
argument_list|()
decl_stmt|,
name|vpwrite
argument_list|()
decl_stmt|,
name|vpioctl
argument_list|()
decl_stmt|,
name|vpreset
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vpopen
value|nodev
end_define

begin_define
define|#
directive|define
name|vpclose
value|nodev
end_define

begin_define
define|#
directive|define
name|vpwrite
value|nodev
end_define

begin_define
define|#
directive|define
name|vpioctl
value|nodev
end_define

begin_define
define|#
directive|define
name|vpreset
value|nulldev
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|mxopen
argument_list|()
decl_stmt|,
name|mxclose
argument_list|()
decl_stmt|,
name|mxread
argument_list|()
decl_stmt|,
name|mxwrite
argument_list|()
decl_stmt|,
name|mxioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|mcread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mcwrite
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|cdevsw
name|cdevsw
index|[]
init|=
block|{
name|cnopen
block|,
name|cnclose
block|,
name|cnread
block|,
name|cnwrite
block|,
comment|/*0*/
name|cnioctl
block|,
name|nulldev
block|,
name|nulldev
block|,
literal|0
block|,
name|dzopen
block|,
name|dzclose
block|,
name|dzread
block|,
name|dzwrite
block|,
comment|/*1*/
name|dzioctl
block|,
name|dzstop
block|,
name|dzreset
block|,
name|dz_tty
block|,
name|syopen
block|,
name|nulldev
block|,
name|syread
block|,
name|sywrite
block|,
comment|/*2*/
name|syioctl
block|,
name|nulldev
block|,
name|nulldev
block|,
literal|0
block|,
name|nulldev
block|,
name|nulldev
block|,
name|mmread
block|,
name|mmwrite
block|,
comment|/*3*/
name|nodev
block|,
name|nulldev
block|,
name|nulldev
block|,
literal|0
block|,
name|nulldev
block|,
name|nulldev
block|,
name|hpread
block|,
name|hpwrite
block|,
comment|/*4*/
name|nodev
block|,
name|nodev
block|,
name|nulldev
block|,
literal|0
block|,
name|htopen
block|,
name|htclose
block|,
name|htread
block|,
name|htwrite
block|,
comment|/*5*/
name|nodev
block|,
name|nodev
block|,
name|nulldev
block|,
literal|0
block|,
name|vpopen
block|,
name|vpclose
block|,
name|nodev
block|,
name|vpwrite
block|,
comment|/*6*/
name|vpioctl
block|,
name|nulldev
block|,
name|vpreset
block|,
literal|0
block|,
name|nulldev
block|,
name|nulldev
block|,
name|swread
block|,
name|swwrite
block|,
comment|/*7*/
name|nodev
block|,
name|nodev
block|,
name|nulldev
block|,
literal|0
block|,
name|flopen
block|,
name|flclose
block|,
name|flread
block|,
name|flwrite
block|,
comment|/*8*/
name|nodev
block|,
name|nodev
block|,
name|nulldev
block|,
literal|0
block|,
name|mxopen
block|,
name|mxclose
block|,
name|mxread
block|,
name|mxwrite
block|,
comment|/*9*/
name|mxioctl
block|,
name|nulldev
block|,
name|nulldev
block|,
literal|0
block|,
name|vaopen
block|,
name|vaclose
block|,
name|nodev
block|,
name|vawrite
block|,
comment|/*10*/
name|vaioctl
block|,
name|nulldev
block|,
name|vareset
block|,
literal|0
block|,
comment|/* 11 reserved for rk07 */
name|nodev
block|,
name|nodev
block|,
name|nodev
block|,
name|nodev
block|,
comment|/*11*/
name|nodev
block|,
name|nodev
block|,
name|nulldev
block|,
literal|0
block|,
name|dhopen
block|,
name|dhclose
block|,
name|dhread
block|,
name|dhwrite
block|,
comment|/*12*/
name|dhioctl
block|,
name|dhstop
block|,
name|dhreset
block|,
name|dh11
block|,
name|nulldev
block|,
name|nulldev
block|,
name|upread
block|,
name|upwrite
block|,
comment|/*13*/
name|nodev
block|,
name|nodev
block|,
name|upreset
block|,
literal|0
block|,
comment|/* 14 reserved for tm03 */
comment|/* 15 reserved for lp11 */
literal|0
block|,	 }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttyopen
argument_list|()
decl_stmt|,
name|ttread
argument_list|()
decl_stmt|,
name|nullioctl
argument_list|()
decl_stmt|,
name|ttstart
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|ttwrite
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|ttyinput
argument_list|()
decl_stmt|,
name|ttyrend
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bkopen
argument_list|()
decl_stmt|,
name|bkclose
argument_list|()
decl_stmt|,
name|bkread
argument_list|()
decl_stmt|,
name|bkinput
argument_list|()
decl_stmt|,
name|bkioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ntyopen
argument_list|()
decl_stmt|,
name|ntyclose
argument_list|()
decl_stmt|,
name|ntread
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|ntwrite
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|ntyinput
argument_list|()
decl_stmt|,
name|ntyrend
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
name|ttyopen
block|,
name|nulldev
block|,
name|ttread
block|,
name|ttwrite
block|,
name|nullioctl
block|,
name|ttyinput
block|,
name|ttyrend
block|,
name|nulldev
block|,
name|nulldev
block|,
name|nulldev
block|,
comment|/* 0 */
name|bkopen
block|,
name|bkclose
block|,
name|bkread
block|,
name|ttwrite
block|,
name|bkioctl
block|,
name|bkinput
block|,
name|nodev
block|,
name|nulldev
block|,
name|ttstart
block|,
name|nulldev
block|,
comment|/* 1 */
name|ntyopen
block|,
name|ntyclose
block|,
name|ntread
block|,
name|ntwrite
block|,
name|nullioctl
block|,
name|ntyinput
block|,
name|ntyrend
block|,
name|nulldev
block|,
name|ttstart
block|,
name|nulldev
block|,
comment|/* 2 */
name|mxopen
block|,
name|mxclose
block|,
name|mcread
block|,
name|mcwrite
block|,
name|mxioctl
block|,
name|nulldev
block|,
name|nulldev
block|,
name|nulldev
block|,
name|nulldev
block|,
name|nulldev
block|,
comment|/* 3 */
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nldisp
init|=
literal|3
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
name|buf
name|bswlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free list of swap headers */
end_comment

begin_decl_stmt
name|struct
name|buf
modifier|*
name|bclnlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* header for list of cleaned pages */
end_comment

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
name|mem_no
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* major device number of memory special file */
end_comment

begin_comment
comment|/*  * Swapdev is a fake device implemented  * in sw.c used only internally to get to swstrategy.  * It cannot be provided to the users, because the  * swstrategy routine munches the b_dev and b_blkno entries  * before calling the appropriate driver.  This would horribly  * confuse, e.g. the hashing routines as well as the placement  * of the block on the d_tab chains.  Instead, /dev/drum is  * provided as a character (raw) device.  */
end_comment

begin_decl_stmt
name|dev_t
name|swapdev
init|=
name|makedev
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|u
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This is stupid, and will go away soon.  */
end_comment

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
specifier|extern
name|struct
name|pte
name|MBA0map
index|[]
decl_stmt|,
name|MBA1map
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mba_info
name|mbainfo
index|[]
init|=
block|{
name|MBA0
block|,
name|PHYSMBA0
block|,
name|MBA0map
block|,
name|MBA1
block|,
name|PHYSMBA1
block|,
name|MBA1map
block|}
decl_stmt|;
end_decl_stmt

end_unit

