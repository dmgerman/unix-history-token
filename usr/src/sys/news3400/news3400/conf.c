begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)conf.c	7.5 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_decl_stmt
name|int
name|rawread
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
expr|struct
name|uio
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rawwrite
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
expr|struct
name|uio
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|swstrategy
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttselect
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dev_type_open
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t, int, int, struct proc *))
end_define

begin_define
define|#
directive|define
name|dev_type_close
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t, int, int, struct proc *))
end_define

begin_define
define|#
directive|define
name|dev_type_strategy
parameter_list|(
name|n
parameter_list|)
value|int n __P((struct buf *))
end_define

begin_define
define|#
directive|define
name|dev_type_ioctl
parameter_list|(
name|n
parameter_list|)
define|\
value|int n __P((dev_t, int, caddr_t, int, struct proc *))
end_define

begin_comment
comment|/* bdevsw-specific types */
end_comment

begin_define
define|#
directive|define
name|dev_type_dump
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t))
end_define

begin_define
define|#
directive|define
name|dev_type_size
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t))
end_define

begin_define
define|#
directive|define
name|dev_decl
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
value|__CONCAT(dev_type_,t)(__CONCAT(n,t))
end_define

begin_define
define|#
directive|define
name|dev_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|(c> 0 ? __CONCAT(n,t) : (__CONCAT(dev_type_,t)((*))) enxio)
end_define

begin_comment
comment|/* bdevsw-specific initializations */
end_comment

begin_define
define|#
directive|define
name|dev_size_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|(c> 0 ? __CONCAT(n,size) : 0)
end_define

begin_define
define|#
directive|define
name|bdev_decl
parameter_list|(
name|n
parameter_list|)
define|\
value|dev_decl(n,open); dev_decl(n,close); dev_decl(n,strategy); \ 	dev_decl(n,ioctl); dev_decl(n,dump); dev_decl(n,size)
end_define

begin_define
define|#
directive|define
name|bdev_disk_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), (dev_type_close((*))) nullop, \ 	dev_init(c,n,strategy), dev_init(c,n,ioctl), \ 	dev_init(c,n,dump), dev_size_init(c,n), 0 }
end_define

begin_define
define|#
directive|define
name|bdev_tape_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), \ 	dev_init(c,n,strategy), dev_init(c,n,ioctl), \ 	dev_init(c,n,dump), 0, B_TAPE }
end_define

begin_define
define|#
directive|define
name|bdev_swap_init
parameter_list|()
value|{ \ 	(dev_type_open((*))) enodev, (dev_type_close((*))) enodev, \ 	swstrategy, (dev_type_ioctl((*))) enodev, \ 	(dev_type_dump((*))) enodev, 0, 0 }
end_define

begin_define
define|#
directive|define
name|bdev_notdef
parameter_list|()
value|bdev_tape_init(0,no)
end_define

begin_expr_stmt
name|bdev_decl
argument_list|(
name|no
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* dummy declarations */
end_comment

begin_include
include|#
directive|include
file|"sd.h"
end_include

begin_define
define|#
directive|define
name|sd_b_ioctl
value|sdioctl
end_define

begin_define
define|#
directive|define
name|sd_b_strategy
value|sdstrategy
end_define

begin_define
define|#
directive|define
name|sd_b_dump
value|sddump
end_define

begin_define
define|#
directive|define
name|sd_b_size
value|sdsize
end_define

begin_expr_stmt
name|bdev_decl
argument_list|(
name|sd_b_
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"fd.h"
end_include

begin_define
define|#
directive|define
name|fd_b_ioctl
value|fdioctl
end_define

begin_define
define|#
directive|define
name|fd_b_strategy
value|fdstrategy
end_define

begin_define
define|#
directive|define
name|fd_b_dump
value|fddump
end_define

begin_define
define|#
directive|define
name|fd_b_size
value|fdsize
end_define

begin_expr_stmt
name|bdev_decl
argument_list|(
name|fd_b_
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"vn.h"
end_include

begin_expr_stmt
name|bdev_decl
argument_list|(
name|vn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|bdevsw
name|bdevsw
index|[]
init|=
block|{
name|bdev_disk_init
argument_list|(
name|NSD
argument_list|,
name|sd_b_
argument_list|)
block|,
comment|/* 0: SCSI disk */
name|bdev_disk_init
argument_list|(
name|NFD
argument_list|,
name|fd_b_
argument_list|)
block|,
comment|/* 1: floppy disk */
name|bdev_notdef
argument_list|()
block|,
comment|/* 2 */
name|bdev_disk_init
argument_list|(
name|NVN
argument_list|,
name|vn
argument_list|)
block|,
comment|/* 3: vnode disk driver (swap to files) */
name|bdev_swap_init
argument_list|()
block|,
comment|/* 4: swap pseudo-device */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nblkdev
init|=
sizeof|sizeof
argument_list|(
name|bdevsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|bdevsw
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cdevsw-specific types */
end_comment

begin_define
define|#
directive|define
name|dev_type_read
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t, struct uio *, int))
end_define

begin_define
define|#
directive|define
name|dev_type_write
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t, struct uio *, int))
end_define

begin_define
define|#
directive|define
name|dev_type_stop
parameter_list|(
name|n
parameter_list|)
value|int n __P((struct tty *, int))
end_define

begin_define
define|#
directive|define
name|dev_type_reset
parameter_list|(
name|n
parameter_list|)
value|int n __P((int))
end_define

begin_define
define|#
directive|define
name|dev_type_select
parameter_list|(
name|n
parameter_list|)
value|int n __P((dev_t, int, struct proc *))
end_define

begin_define
define|#
directive|define
name|dev_type_map
parameter_list|(
name|n
parameter_list|)
value|int n __P(())
end_define

begin_define
define|#
directive|define
name|cdev_decl
parameter_list|(
name|n
parameter_list|)
define|\
value|dev_decl(n,open); dev_decl(n,close); dev_decl(n,read); \ 	dev_decl(n,write); dev_decl(n,ioctl); dev_decl(n,stop); \ 	dev_decl(n,reset); dev_decl(n,select); dev_decl(n,map); \ 	dev_decl(n,strategy); extern struct tty __CONCAT(n,_tty)[]
end_define

begin_define
define|#
directive|define
name|dev_tty_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|(c> 0 ? __CONCAT(n,_tty) : 0)
end_define

begin_comment
comment|/* open, read, write, ioctl, strategy */
end_comment

begin_define
define|#
directive|define
name|cdev_disk_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), (dev_type_close((*))) nullop, dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, seltrue, (dev_type_map((*))) enodev, \ 	dev_init(c,n,strategy) }
end_define

begin_comment
comment|/* open, close, read, write, ioctl, strategy */
end_comment

begin_define
define|#
directive|define
name|cdev_tape_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), rawread, \ 	rawwrite, dev_init(c,n,ioctl), (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, seltrue, (dev_type_map((*))) enodev, \ 	dev_init(c,n,strategy) }
end_define

begin_comment
comment|/* open, close, read, write, ioctl, stop, tty */
end_comment

begin_define
define|#
directive|define
name|cdev_tty_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), dev_init(c,n,stop), \ 	(dev_type_reset((*))) nullop, dev_tty_init(c,n), ttselect, \ 	(dev_type_map((*))) enodev, 0 }
end_define

begin_define
define|#
directive|define
name|cdev_notdef
parameter_list|()
value|{ \ 	(dev_type_open((*))) enodev, (dev_type_close((*))) enodev, \ 	(dev_type_read((*))) enodev, (dev_type_write((*))) enodev, \ 	(dev_type_ioctl((*))) enodev, (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, seltrue, \ 	(dev_type_map((*))) enodev, 0 }
end_define

begin_comment
comment|/* open, close, read, write, ioctl -- XXX should be tty */
end_comment

begin_define
define|#
directive|define
name|cdev_vc_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), dev_init(c,n,stop), \ 	(dev_type_reset((*))) nullop, 0, dev_init(c,n,select), \ 	(dev_type_map((*))) enodev, 0 }
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|no
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* dummy declarations */
end_comment

begin_include
include|#
directive|include
file|"rs.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|rs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cdev_decl
argument_list|(
name|vc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"bm.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|cn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cdev_decl
argument_list|(
name|ctty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, read, write, ioctl, select -- XXX should be a tty */
end_comment

begin_define
define|#
directive|define
name|cdev_ctty_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), (dev_type_close((*))) nullop, dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) nullop, \ 	(dev_type_reset((*))) nullop, 0, dev_init(c,n,select), \ 	(dev_type_map((*))) enodev, 0 }
end_define

begin_expr_stmt
name|dev_type_read
argument_list|(
name|mmrw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* read/write */
end_comment

begin_define
define|#
directive|define
name|cdev_mm_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	(dev_type_open((*))) nullop, (dev_type_close((*))) nullop, mmrw, \ 	mmrw, (dev_type_ioctl((*))) enodev, (dev_type_stop((*))) nullop, \ 	(dev_type_reset((*))) nullop, 0, seltrue, (dev_type_map((*))) enodev, 0 }
end_define

begin_include
include|#
directive|include
file|"sd.h"
end_include

begin_define
define|#
directive|define
name|sd_c_read
value|sdread
end_define

begin_define
define|#
directive|define
name|sd_c_write
value|sdwrite
end_define

begin_define
define|#
directive|define
name|sd_c_ioctl
value|sdioctl
end_define

begin_define
define|#
directive|define
name|sd_c_reset
value|sdreset
end_define

begin_define
define|#
directive|define
name|sd_c_strategy
value|sdstrategy
end_define

begin_define
define|#
directive|define
name|sd_c_dump
value|sddump
end_define

begin_define
define|#
directive|define
name|sd_c_size
value|sdsize
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|sd_c_
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"fd.h"
end_include

begin_define
define|#
directive|define
name|fd_c_read
value|fdread
end_define

begin_define
define|#
directive|define
name|fd_c_write
value|fdwrite
end_define

begin_define
define|#
directive|define
name|fd_c_ioctl
value|fdioctl
end_define

begin_define
define|#
directive|define
name|fd_c_reset
value|fdreset
end_define

begin_define
define|#
directive|define
name|fd_c_strategy
value|fdstrategy
end_define

begin_define
define|#
directive|define
name|fd_c_dump
value|fddump
end_define

begin_define
define|#
directive|define
name|fd_c_size
value|fdsize
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|fd_c_
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"lp.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|lp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* read, write, strategy */
end_comment

begin_define
define|#
directive|define
name|cdev_swap_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	(dev_type_open((*))) nullop, (dev_type_close((*))) nullop, rawread, \ 	rawwrite, (dev_type_ioctl((*))) enodev, (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, (dev_type_select((*))) enodev, \ 	(dev_type_map((*))) enodev, dev_init(c,n,strategy) }
end_define

begin_include
include|#
directive|include
file|"pty.h"
end_include

begin_define
define|#
directive|define
name|pts_tty
value|pt_tty
end_define

begin_define
define|#
directive|define
name|ptsioctl
value|ptyioctl
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|pts
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|ptc_tty
value|pt_tty
end_define

begin_define
define|#
directive|define
name|ptcioctl
value|ptyioctl
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|ptc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, read, write, ioctl, tty, select */
end_comment

begin_define
define|#
directive|define
name|cdev_ptc_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) nullop, \ 	(dev_type_reset((*))) nullop, dev_tty_init(c,n), dev_init(c,n,select), \ 	(dev_type_map((*))) enodev, 0 }
end_define

begin_include
include|#
directive|include
file|"kb.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|kb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, write, ioctl */
end_comment

begin_define
define|#
directive|define
name|cdev_kb_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), (dev_type_read((*))) enodev, \ 	dev_init(c,n,write), dev_init(c,n,ioctl), \ 	(dev_type_stop((*))) enodev, (dev_type_reset((*))) nullop, 0, \ 	seltrue, (dev_type_map((*))) enodev, \ 	0 }
end_define

begin_include
include|#
directive|include
file|"ms.h"
end_include

begin_define
define|#
directive|define
name|msmap
value|msmmap
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|ms
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, read, write, ioctl, select */
end_comment

begin_define
define|#
directive|define
name|cdev_ms_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, seltrue, (dev_type_map((*))) enodev, \ 	0 }
end_define

begin_include
include|#
directive|include
file|"fb.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|fb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, ioctl, mmap */
end_comment

begin_define
define|#
directive|define
name|cdev_fb_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), (dev_type_read((*))) enodev, \ 	(dev_type_write((*))) enodev, dev_init(c,n,ioctl), \ 	(dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, seltrue, (dev_type_map((*))) enodev, 0 }
end_define

begin_comment
comment|/* 	(dev_type_reset((*))) nullop, 0, seltrue, dev_init(c,n,map), 0 } */
end_comment

begin_include
include|#
directive|include
file|"st.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|st
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"lb.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|lbp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"ir.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|ir
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, read, ioctl */
end_comment

begin_define
define|#
directive|define
name|cdev_ir_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	(dev_type_write((*))) enodev, dev_init(c,n,ioctl), \ 	(dev_type_stop((*))) enodev, (dev_type_reset((*))) nullop, 0, \ 	seltrue, (dev_type_map((*))) enodev, 0 }
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|log
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, read, ioctl, select -- XXX should be a generic device */
end_comment

begin_define
define|#
directive|define
name|cdev_log_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	(dev_type_write((*))) enodev, dev_init(c,n,ioctl), \ 	(dev_type_stop((*))) enodev, (dev_type_reset((*))) nullop, 0, \ 	dev_init(c,n,select), (dev_type_map((*))) enodev, 0 }
end_define

begin_expr_stmt
name|dev_type_open
argument_list|(
name|fdopen
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open */
end_comment

begin_define
define|#
directive|define
name|cdev_fd_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), (dev_type_close((*))) enodev, \ 	(dev_type_read((*))) enodev, (dev_type_write((*))) enodev, \ 	(dev_type_ioctl((*))) enodev, (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) enodev, 0, (dev_type_select((*))) enodev, \ 	(dev_type_map((*))) enodev, 0 }
end_define

begin_expr_stmt
name|cdev_decl
argument_list|(
name|vn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, read, write, ioctl -- XXX should be a disk */
end_comment

begin_define
define|#
directive|define
name|cdev_vn_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), (dev_type_close((*))) nullop, dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) nullop, 0, seltrue, (dev_type_map((*))) enodev, \ 	0 }
end_define

begin_include
include|#
directive|include
file|"bpfilter.h"
end_include

begin_expr_stmt
name|cdev_decl
argument_list|(
name|bpf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* open, close, read, write, ioctl, select -- XXX should be generic device */
end_comment

begin_define
define|#
directive|define
name|cdev_bpf_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), dev_init(c,n,read), \ 	dev_init(c,n,write), dev_init(c,n,ioctl), (dev_type_stop((*))) enodev, \ 	(dev_type_reset((*))) enodev, 0, dev_init(c,n,select), \ 	(dev_type_map((*))) enodev, 0 }
end_define

begin_decl_stmt
name|struct
name|cdevsw
name|cdevsw
index|[]
init|=
block|{
name|cdev_vc_init
argument_list|(
literal|1
argument_list|,
name|vc
argument_list|)
block|,
comment|/* 0: virtual console */
name|cdev_tty_init
argument_list|(
name|NRS
argument_list|,
name|rs
argument_list|)
block|,
comment|/* 1: rs232c */
name|cdev_ctty_init
argument_list|(
literal|1
argument_list|,
name|ctty
argument_list|)
block|,
comment|/* 2: controlling terminal */
name|cdev_mm_init
argument_list|(
literal|1
argument_list|,
name|mm
argument_list|)
block|,
comment|/* 3: /dev/{null,mem,kmem,...} */
name|cdev_disk_init
argument_list|(
name|NSD
argument_list|,
name|sd_c_
argument_list|)
block|,
comment|/* 4: scsi disk */
name|cdev_disk_init
argument_list|(
name|NFD
argument_list|,
name|fd_c_
argument_list|)
block|,
comment|/* 5: floppy disk */
name|cdev_disk_init
argument_list|(
name|NLP
argument_list|,
name|lp
argument_list|)
block|,
comment|/* 6: printer */
name|cdev_swap_init
argument_list|(
literal|1
argument_list|,
name|sw
argument_list|)
block|,
comment|/* 7: /dev/drum (swap pseudo-device) */
name|cdev_tty_init
argument_list|(
name|NPTY
argument_list|,
name|pts
argument_list|)
block|,
comment|/* 8: pseudo-tty slave */
name|cdev_ptc_init
argument_list|(
name|NPTY
argument_list|,
name|ptc
argument_list|)
block|,
comment|/* 9: pseudo-tty master */
name|cdev_notdef
argument_list|()
block|,
comment|/* 10: md (sony memory disk) */
name|cdev_kb_init
argument_list|(
name|NKB
argument_list|,
name|kb
argument_list|)
block|,
comment|/* 11: keyboard */
name|cdev_ms_init
argument_list|(
name|NMS
argument_list|,
name|ms
argument_list|)
block|,
comment|/* 12: mouse */
name|cdev_fd_init
argument_list|(
literal|1
argument_list|,
name|fd
argument_list|)
block|,
comment|/* 13: file descriptor pseudo-dev */
name|cdev_fb_init
argument_list|(
name|NFB
argument_list|,
name|fb
argument_list|)
block|,
comment|/* 14: frame buffer */
name|cdev_vn_init
argument_list|(
name|NVN
argument_list|,
name|vn
argument_list|)
block|,
comment|/* 15: vnode disk */
name|cdev_tape_init
argument_list|(
name|NST
argument_list|,
name|st
argument_list|)
block|,
comment|/* 16: scsi tape */
name|cdev_kb_init
argument_list|(
name|NLB
argument_list|,
name|lbp
argument_list|)
block|,
comment|/* 17: lbp */
name|cdev_ir_init
argument_list|(
name|NIR
argument_list|,
name|ir
argument_list|)
block|,
comment|/* 18: image reader */
name|cdev_notdef
argument_list|()
block|,
comment|/* 19: vme */
name|cdev_notdef
argument_list|()
block|,
comment|/* 20: gpib */
name|cdev_notdef
argument_list|()
block|,
comment|/* 21: rd */
name|cdev_tty_init
argument_list|(
name|NBM
argument_list|,
name|cn
argument_list|)
block|,
comment|/* 22: console display device */
name|cdev_notdef
argument_list|()
block|,
comment|/* 23: ether */
name|cdev_bpf_init
argument_list|(
name|NBPFILTER
argument_list|,
name|bpf
argument_list|)
block|,
comment|/* 24: berkeley packet filter */
name|cdev_notdef
argument_list|()
block|,
comment|/* 25 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 26 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 27 */
name|cdev_notdef
argument_list|()
block|,
comment|/* 28: scsi */
name|cdev_notdef
argument_list|()
block|,
comment|/* 29: sony shm */
name|cdev_notdef
argument_list|()
block|,
comment|/* 30: sony semaphoe? */
name|cdev_notdef
argument_list|()
block|,
comment|/* 31: vvcrs */
name|cdev_notdef
argument_list|()
block|,
comment|/* 32: fddi */
name|cdev_log_init
argument_list|(
literal|1
argument_list|,
name|log
argument_list|)
block|,
comment|/* 33: /dev/klog */
name|cdev_notdef
argument_list|()
block|,
comment|/* 34: image board */
name|cdev_notdef
argument_list|()
block|,
comment|/* 35: sb? */
name|cdev_notdef
argument_list|()
block|,
comment|/* 36: sbe? */
name|cdev_notdef
argument_list|()
block|,
comment|/* 37: vd (safs) */
name|cdev_notdef
argument_list|()
block|,
comment|/* 38: xd (safs) */
name|cdev_notdef
argument_list|()
block|,
comment|/* 39: isdn */
name|cdev_notdef
argument_list|()
block|,
comment|/* 40: rb */
name|cdev_notdef
argument_list|()
block|,
comment|/* 41: gs */
name|cdev_notdef
argument_list|()
block|,
comment|/* 42: rx */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nchrdev
init|=
sizeof|sizeof
argument_list|(
name|cdevsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|cdevsw
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mem_no
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* major device number of memory special file */
end_comment

begin_comment
comment|/*  * Swapdev is a fake device implemented  * in sw.c used only internally to get to swstrategy.  * It cannot be provided to the users, because the  * swstrategy routine munches the b_dev and b_blkno entries  * before calling the appropriate driver.  This would horribly  * confuse, e.g. the hashing routines. Instead, /dev/drum is  * provided as a character (raw) device.  */
end_comment

begin_decl_stmt
name|dev_t
name|swapdev
init|=
name|makedev
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Routine that identifies /dev/mem and /dev/kmem.  *  * A minimal stub routine can always return 0.  */
end_comment

begin_macro
name|iskmemdev
argument_list|(
argument|dev
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|major
argument_list|(
name|dev
argument_list|)
operator|==
literal|3
operator|&&
operator|(
name|minor
argument_list|(
name|dev
argument_list|)
operator|==
literal|0
operator|||
name|minor
argument_list|(
name|dev
argument_list|)
operator|==
literal|1
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Routine to determine if a device is a disk.  *  * A minimal stub routine can always return 0.  */
end_comment

begin_macro
name|isdisk
argument_list|(
argument|dev
argument_list|,
argument|type
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|major
argument_list|(
name|dev
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
case|case
literal|3
case|:
if|if
condition|(
name|type
operator|==
name|VBLK
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|4
case|:
case|case
literal|15
case|:
if|if
condition|(
name|type
operator|==
name|VCHR
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* FALLTHROUGH */
default|default:
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* NOTREACHED */
block|}
end_block

begin_define
define|#
directive|define
name|MAXDEV
value|43
end_define

begin_decl_stmt
specifier|static
name|int
name|chrtoblktbl
index|[
name|MAXDEV
index|]
init|=
block|{
comment|/* VCHR */
comment|/* VBLK */
comment|/* 0 */
name|NODEV
block|,
comment|/* 1 */
name|NODEV
block|,
comment|/* 2 */
name|NODEV
block|,
comment|/* 3 */
name|NODEV
block|,
comment|/* 4 */
literal|0
block|,
comment|/* 5 */
name|NODEV
block|,
comment|/* 6 */
name|NODEV
block|,
comment|/* 7 */
name|NODEV
block|,
comment|/* 8 */
name|NODEV
block|,
comment|/* 9 */
name|NODEV
block|,
comment|/* 10 */
name|NODEV
block|,
comment|/* 11 */
name|NODEV
block|,
comment|/* 12 */
name|NODEV
block|,
comment|/* 13 */
name|NODEV
block|,
comment|/* 14 */
name|NODEV
block|,
comment|/* 15 */
literal|3
block|,
comment|/* 16 */
name|NODEV
block|,
comment|/* 17 */
name|NODEV
block|,
comment|/* 18 */
name|NODEV
block|,
comment|/* 19 */
name|NODEV
block|,
comment|/* 20 */
name|NODEV
block|,
comment|/* 21 */
name|NODEV
block|,
comment|/* 22 */
name|NODEV
block|,
comment|/* 23 */
name|NODEV
block|,
comment|/* 24 */
name|NODEV
block|,
comment|/* 25 */
name|NODEV
block|,
comment|/* 26 */
name|NODEV
block|,
comment|/* 27 */
name|NODEV
block|,
comment|/* 28 */
name|NODEV
block|,
comment|/* 29 */
name|NODEV
block|,
comment|/* 30 */
name|NODEV
block|,
comment|/* 31 */
name|NODEV
block|,
comment|/* 32 */
name|NODEV
block|,
comment|/* 33 */
name|NODEV
block|,
comment|/* 34 */
name|NODEV
block|,
comment|/* 35 */
name|NODEV
block|,
comment|/* 36 */
name|NODEV
block|,
comment|/* 37 */
name|NODEV
block|,
comment|/* 38 */
name|NODEV
block|,
comment|/* 39 */
name|NODEV
block|,
comment|/* 40 */
name|NODEV
block|,
comment|/* 41 */
name|NODEV
block|,
comment|/* 42 */
name|NODEV
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Routine to convert from character to block device number.  *  * A minimal stub routine can always return NODEV.  */
end_comment

begin_macro
name|chrtoblk
argument_list|(
argument|dev
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|blkmaj
decl_stmt|;
if|if
condition|(
name|major
argument_list|(
name|dev
argument_list|)
operator|>=
name|MAXDEV
operator|||
operator|(
name|blkmaj
operator|=
name|chrtoblktbl
index|[
name|major
argument_list|(
name|dev
argument_list|)
index|]
operator|)
operator|==
name|NODEV
condition|)
return|return
operator|(
name|NODEV
operator|)
return|;
return|return
operator|(
name|makedev
argument_list|(
name|blkmaj
argument_list|,
name|minor
argument_list|(
name|dev
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

