begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)wd.c	7.2 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/* TODO:  *	o Bump error count after timeout.  *	o Satisfy ATA timing in all cases.  *	o Finish merging berry/sos timeout code (bump error count...).  *	o Merge/fix TIH/NetBSD bad144 code.  *	o Don't use polling except for initialization.  Need to  *	  reorganize the state machine.  Then "extra" interrupts  *	  shouldn't happen (except maybe one for initialization).  *	o Fix disklabel, boot and driver inconsistencies with  *	  bad144 in standard versions.  *	o Support extended DOS partitions.  *	o Support swapping to DOS partitions.  *	o Handle bad sectors, clustering, disklabelling, DOS  *	  partitions and swapping driver-independently.  Use  *	  i386/dkbad.c for bad sectors.  Swapping will need new  *	  driver entries for polled reinit and polled write).  */
end_comment

begin_include
include|#
directive|include
file|"wd.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NWDC
end_ifdef

begin_undef
undef|#
directive|undef
name|NWDC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"wdc.h"
end_include

begin_if
if|#
directive|if
name|NWDC
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|"opt_hw_wdog.h"
end_include

begin_include
include|#
directive|include
file|"opt_ide_delay.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dkbad.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_include
include|#
directive|include
file|<sys/diskslice.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/devicestat.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootinfo.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/wdreg.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_prot.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/atapi.h>
end_include

begin_function_decl
specifier|extern
name|void
name|wdstart
parameter_list|(
name|int
name|ctrlr
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|IDE_DELAY
end_ifdef

begin_define
define|#
directive|define
name|TIMEOUT
value|IDE_DELAY
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TIMEOUT
value|10000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RETRIES
value|5
end_define

begin_comment
comment|/* number of retries before giving up */
end_comment

begin_define
define|#
directive|define
name|RECOVERYTIME
value|500000
end_define

begin_comment
comment|/* usec for controller to recover after err */
end_comment

begin_define
define|#
directive|define
name|MAXTRANSFER
value|255
end_define

begin_comment
comment|/* max size of transfer in sectors */
end_comment

begin_comment
comment|/* correct max is 256 but some controllers */
end_comment

begin_comment
comment|/* can't handle that in all cases */
end_comment

begin_define
define|#
directive|define
name|WDOPT_32BIT
value|0x8000
end_define

begin_define
define|#
directive|define
name|WDOPT_SLEEPHACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|WDOPT_DMA
value|0x2000
end_define

begin_define
define|#
directive|define
name|WDOPT_LBA
value|0x1000
end_define

begin_define
define|#
directive|define
name|WDOPT_FORCEHD
parameter_list|(
name|x
parameter_list|)
value|(((x)&0x0f00)>>8)
end_define

begin_define
define|#
directive|define
name|WDOPT_MULTIMASK
value|0x00ff
end_define

begin_comment
comment|/*  * Drive states.  Used to initialize drive.  */
end_comment

begin_define
define|#
directive|define
name|CLOSED
value|0
end_define

begin_comment
comment|/* disk is closed. */
end_comment

begin_define
define|#
directive|define
name|WANTOPEN
value|1
end_define

begin_comment
comment|/* open requested, not started */
end_comment

begin_define
define|#
directive|define
name|RECAL
value|2
end_define

begin_comment
comment|/* doing restore */
end_comment

begin_define
define|#
directive|define
name|OPEN
value|3
end_define

begin_comment
comment|/* done with open */
end_comment

begin_define
define|#
directive|define
name|PRIMARY
value|0
end_define

begin_comment
comment|/*  * Disk geometry.  A small part of struct disklabel.  * XXX disklabel.5 contains an old clone of disklabel.h.  */
end_comment

begin_struct
struct|struct
name|diskgeom
block|{
name|u_long
name|d_secsize
decl_stmt|;
comment|/* # of bytes per sector */
name|u_long
name|d_nsectors
decl_stmt|;
comment|/* # of data sectors per track */
name|u_long
name|d_ntracks
decl_stmt|;
comment|/* # of tracks per cylinder */
name|u_long
name|d_ncylinders
decl_stmt|;
comment|/* # of data cylinders per unit */
name|u_long
name|d_secpercyl
decl_stmt|;
comment|/* # of data sectors per cylinder */
name|u_long
name|d_secperunit
decl_stmt|;
comment|/* # of data sectors per unit */
name|u_long
name|d_precompcyl
decl_stmt|;
comment|/* XXX always 0 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The structure of a disk drive.  */
end_comment

begin_struct
struct|struct
name|disk
block|{
name|u_int
name|dk_bc
decl_stmt|;
comment|/* byte count left */
name|short
name|dk_skip
decl_stmt|;
comment|/* blocks already transferred */
name|int
name|dk_ctrlr
decl_stmt|;
comment|/* physical controller number */
name|int
name|dk_ctrlr_cmd640
decl_stmt|;
comment|/* controller number for CMD640 quirk */
name|u_int32_t
name|dk_unit
decl_stmt|;
comment|/* physical unit number */
name|u_int32_t
name|dk_lunit
decl_stmt|;
comment|/* logical unit number */
name|u_int32_t
name|dk_interface
decl_stmt|;
comment|/* interface (two ctrlrs per interface) */
name|char
name|dk_state
decl_stmt|;
comment|/* control state */
name|u_char
name|dk_status
decl_stmt|;
comment|/* copy of status reg. */
name|u_char
name|dk_error
decl_stmt|;
comment|/* copy of error reg. */
name|u_char
name|dk_timeout
decl_stmt|;
comment|/* countdown to next timeout */
name|u_int32_t
name|dk_port
decl_stmt|;
comment|/* i/o port base */
name|u_int32_t
name|dk_altport
decl_stmt|;
comment|/* altstatus port base */
name|u_long
name|cfg_flags
decl_stmt|;
comment|/* configured characteristics */
name|short
name|dk_flags
decl_stmt|;
comment|/* drive characteristics found */
define|#
directive|define
name|DKFL_SINGLE
value|0x00004
comment|/* sector at a time mode */
define|#
directive|define
name|DKFL_ERROR
value|0x00008
comment|/* processing a disk error */
define|#
directive|define
name|DKFL_LABELLING
value|0x00080
comment|/* readdisklabel() in progress */
define|#
directive|define
name|DKFL_32BIT
value|0x00100
comment|/* use 32-bit i/o mode */
define|#
directive|define
name|DKFL_MULTI
value|0x00200
comment|/* use multi-i/o mode */
define|#
directive|define
name|DKFL_BADSCAN
value|0x00400
comment|/* report all errors */
define|#
directive|define
name|DKFL_USEDMA
value|0x00800
comment|/* use DMA for data transfers */
define|#
directive|define
name|DKFL_DMA
value|0x01000
comment|/* using DMA on this transfer-- DKFL_SINGLE 				 * overrides this 				 */
define|#
directive|define
name|DKFL_LBA
value|0x02000
comment|/* use LBA for data transfers */
name|struct
name|wdparams
name|dk_params
decl_stmt|;
comment|/* ESDI/IDE drive/controller parameters */
name|unsigned
name|int
name|dk_multi
decl_stmt|;
comment|/* multi transfers */
name|int
name|dk_currentiosize
decl_stmt|;
comment|/* current io size */
name|struct
name|diskgeom
name|dk_dd
decl_stmt|;
comment|/* device configuration data */
name|struct
name|diskslices
modifier|*
name|dk_slices
decl_stmt|;
comment|/* virtual drives */
name|void
modifier|*
name|dk_dmacookie
decl_stmt|;
comment|/* handle for DMA services */
name|struct
name|devstat
name|dk_stats
decl_stmt|;
comment|/* devstat entry */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WD_COUNT_RETRIES
end_define

begin_decl_stmt
specifier|static
name|int
name|wdtest
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|disk
modifier|*
name|wddrives
index|[
name|NWD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of units */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|buf_queue_head
name|drive_queue
index|[
name|NWD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of queue per drive */
end_comment

begin_struct
specifier|static
struct|struct
block|{
name|int
name|b_active
decl_stmt|;
block|}
name|wdutab
index|[
name|NWD
index|]
struct|;
end_struct

begin_comment
comment|/* static struct buf wdtab[NWDC]; */
end_comment

begin_struct
specifier|static
struct|struct
block|{
name|struct
name|buf_queue_head
name|controller_queue
decl_stmt|;
name|int
name|b_errcnt
decl_stmt|;
name|int
name|b_active
decl_stmt|;
block|}
name|wdtab
index|[
name|NWDC
index|]
struct|;
end_struct

begin_decl_stmt
name|struct
name|wddma
name|wddma
index|[
name|NWDC
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|buf
name|rwdbuf
index|[
name|NWD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffers for raw IO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|int
name|wdprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|wdattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|wdustart
parameter_list|(
name|struct
name|disk
modifier|*
name|du
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|wdcontrol
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|wdcommand
parameter_list|(
name|struct
name|disk
modifier|*
name|du
parameter_list|,
name|u_int
name|cylinder
parameter_list|,
name|u_int
name|head
parameter_list|,
name|u_int
name|sector
parameter_list|,
name|u_int
name|count
parameter_list|,
name|u_int
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|wdsetctlr
parameter_list|(
name|struct
name|disk
modifier|*
name|du
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static int wdwsetctlr(struct disk *du);
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|int
name|wdsetmode
parameter_list|(
name|int
name|mode
parameter_list|,
name|void
modifier|*
name|wdinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|wdgetctlr
parameter_list|(
name|struct
name|disk
modifier|*
name|du
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|wderror
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|struct
name|disk
modifier|*
name|du
parameter_list|,
name|char
modifier|*
name|mesg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|wdflushirq
parameter_list|(
name|struct
name|disk
modifier|*
name|du
parameter_list|,
name|int
name|old_ipl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|wdreset
parameter_list|(
name|struct
name|disk
modifier|*
name|du
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|wdsleep
parameter_list|(
name|int
name|ctrlr
parameter_list|,
name|char
modifier|*
name|wmesg
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|timeout_t
name|wdtimeout
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|wdunwedge
parameter_list|(
name|struct
name|disk
modifier|*
name|du
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|wdwait
parameter_list|(
name|struct
name|disk
modifier|*
name|du
parameter_list|,
name|u_char
name|bits_wanted
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|isa_driver
name|wdcdriver
init|=
block|{
name|wdprobe
block|,
name|wdattach
block|,
literal|"wdc"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_open_t
name|wdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_close_t
name|wdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_strategy_t
name|wdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|wdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_dump_t
name|wddump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_psize_t
name|wdsize
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CDEV_MAJOR
value|3
end_define

begin_define
define|#
directive|define
name|BDEV_MAJOR
value|0
end_define

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|wd_cdevsw
init|=
block|{
comment|/* open */
name|wdopen
block|,
comment|/* close */
name|wdclose
block|,
comment|/* read */
name|physread
block|,
comment|/* write */
name|physwrite
block|,
comment|/* ioctl */
name|wdioctl
block|,
comment|/* poll */
name|nopoll
block|,
comment|/* mmap */
name|nommap
block|,
comment|/* strategy */
name|wdstrategy
block|,
comment|/* name */
literal|"wd"
block|,
comment|/* maj */
name|CDEV_MAJOR
block|,
comment|/* dump */
name|wddump
block|,
comment|/* psize */
name|wdsize
block|,
comment|/* flags */
name|D_DISK
block|,
comment|/* bmaj */
name|BDEV_MAJOR
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|atapictrlr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|eide_quirks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|wd_ident
index|[
name|NWD
index|]
index|[
literal|62
index|]
init|=
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_STRING
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|wd0_ident
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|wd_ident
index|[
literal|0
index|]
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_STRING
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|wd1_ident
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|wd_ident
index|[
literal|1
index|]
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_STRING
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|wd2_ident
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|wd_ident
index|[
literal|2
index|]
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_STRING
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|wd3_ident
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|wd_ident
index|[
literal|3
index|]
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  *  Here we use the pci-subsystem to find out, whether there is  *  a cmd640b-chip attached on this pci-bus. This public routine  *  will be called by ide_pci.c  */
end_comment

begin_function
name|void
name|wdc_pci
parameter_list|(
name|int
name|quirks
parameter_list|)
block|{
name|eide_quirks
operator|=
name|quirks
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Probe for controller.  */
end_comment

begin_function
specifier|static
name|int
name|wdprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dvp
parameter_list|)
block|{
name|int
name|unit
init|=
name|dvp
operator|->
name|id_unit
decl_stmt|;
name|int
name|interface
decl_stmt|;
name|struct
name|disk
modifier|*
name|du
decl_stmt|;
if|if
condition|(
name|unit
operator|>=
name|NWDC
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|du
operator|=
name|malloc
argument_list|(
sizeof|sizeof
expr|*
name|du
argument_list|,
name|M_TEMP
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|du
operator|==
name|NULL
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|bzero
argument_list|(
name|du
argument_list|,
sizeof|sizeof
expr|*
name|du
argument_list|)
expr_stmt|;
name|du
operator|->
name|dk_ctrlr
operator|=
name|dvp
operator|->
name|id_unit
expr_stmt|;
name|interface
operator|=
name|du
operator|->
name|dk_ctrlr
operator|/
literal|2
expr_stmt|;
name|du
operator|->
name|dk_interface
operator|=
name|interface
expr_stmt|;
name|du
operator|->
name|dk_port
operator|=
name|dvp
operator|->
name|id_iobase
expr_stmt|;
if|if
condition|(
name|wddma
index|[
name|interface
index|]
operator|.
name|wdd_candma
operator|!=
name|NULL
condition|)
block|{
name|du
operator|->
name|dk_dmacookie
operator|=
name|wddma
index|[
name|interface
index|]
operator|.
name|wdd_candma
argument_list|(
name|dvp
operator|->
name|id_iobase
argument_list|,
name|du
operator|->
name|dk_ctrlr
argument_list|,
name|du
operator|->
name|dk_unit
argument_list|)
expr_stmt|;
name|du
operator|->
name|dk_altport
operator|=
name|wddma
index|[
name|interface
index|]
operator|.
name|wdd_altiobase
argument_list|(
name|du
operator|->
name|dk_dmacookie
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|du
operator|->
name|dk_altport
operator|==
literal|0
condition|)
name|du
operator|->
name|dk_altport
operator|=
name|du
operator|->
name|dk_port
operator|+
name|wd_ctlr
expr_stmt|;
comment|/* check if we have registers that work */
name|outb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_sdh
argument_list|,
name|WDSD_IBM
argument_list|)
expr_stmt|;
comment|/* set unit 0 */
name|outb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_cyl_lo
argument_list|,
literal|0xa5
argument_list|)
expr_stmt|;
comment|/* wd_cyl_lo is read/write */
if|if
condition|(
name|inb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_cyl_lo
argument_list|)
operator|==
literal|0xff
condition|)
block|{
comment|/* XXX too weak */
comment|/* There is no master, try the ATAPI slave. */
name|du
operator|->
name|dk_unit
operator|=
literal|1
expr_stmt|;
name|outb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_sdh
argument_list|,
name|WDSD_IBM
operator||
literal|0x10
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_cyl_lo
argument_list|,
literal|0xa5
argument_list|)
expr_stmt|;
if|if
condition|(
name|inb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_cyl_lo
argument_list|)
operator|==
literal|0xff
condition|)
goto|goto
name|nodevice
goto|;
block|}
if|if
condition|(
name|wdreset
argument_list|(
name|du
argument_list|)
operator|==
literal|0
condition|)
goto|goto
name|reset_ok
goto|;
comment|/* test for ATAPI signature */
name|outb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_sdh
argument_list|,
name|WDSD_IBM
argument_list|)
expr_stmt|;
comment|/* master */
if|if
condition|(
name|inb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_cyl_lo
argument_list|)
operator|==
literal|0x14
operator|&&
name|inb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_cyl_hi
argument_list|)
operator|==
literal|0xeb
condition|)
goto|goto
name|reset_ok
goto|;
name|du
operator|->
name|dk_unit
operator|=
literal|1
expr_stmt|;
name|outb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_sdh
argument_list|,
name|WDSD_IBM
operator||
literal|0x10
argument_list|)
expr_stmt|;
comment|/* slave */
if|if
condition|(
name|inb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_cyl_lo
argument_list|)
operator|==
literal|0x14
operator|&&
name|inb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_cyl_hi
argument_list|)
operator|==
literal|0xeb
condition|)
goto|goto
name|reset_ok
goto|;
name|DELAY
argument_list|(
name|RECOVERYTIME
argument_list|)
expr_stmt|;
if|if
condition|(
name|wdreset
argument_list|(
name|du
argument_list|)
operator|!=
literal|0
condition|)
block|{
goto|goto
name|nodevice
goto|;
block|}
name|reset_ok
label|:
comment|/* execute a controller only command */
if|if
condition|(
name|wdcommand
argument_list|(
name|du
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|WDCC_DIAGNOSE
argument_list|)
operator|!=
literal|0
operator|||
name|wdwait
argument_list|(
name|du
argument_list|,
literal|0
argument_list|,
name|TIMEOUT
argument_list|)
operator|<
literal|0
condition|)
block|{
goto|goto
name|nodevice
goto|;
block|}
comment|/* 	 * drive(s) did not time out during diagnostic : 	 * Get error status and check that both drives are OK. 	 * Table 9-2 of ATA specs suggests that we must check for 	 * a value of 0x01 	 * 	 * Strangely, some controllers will return a status of 	 * 0x81 (drive 0 OK, drive 1 failure), and then when 	 * the DRV bit is set, return status of 0x01 (OK) for 	 * drive 2.  (This seems to contradict the ATA spec.) 	 */
name|du
operator|->
name|dk_error
operator|=
name|inb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_error
argument_list|)
expr_stmt|;
if|if
condition|(
name|du
operator|->
name|dk_error
operator|!=
literal|0x01
operator|&&
name|du
operator|->
name|dk_error
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|du
operator|->
name|dk_error
operator|&
literal|0x80
condition|)
block|{
comment|/* drive 1 failure */
comment|/* first set the DRV bit */
name|u_int
name|sdh
decl_stmt|;
name|sdh
operator|=
name|inb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_sdh
argument_list|)
expr_stmt|;
name|sdh
operator|=
name|sdh
operator||
literal|0x10
expr_stmt|;
name|outb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_sdh
argument_list|,
name|sdh
argument_list|)
expr_stmt|;
comment|/* Wait, to make sure drv 1 has completed diags */
if|if
condition|(
name|wdwait
argument_list|(
name|du
argument_list|,
literal|0
argument_list|,
name|TIMEOUT
argument_list|)
operator|<
literal|0
condition|)
goto|goto
name|nodevice
goto|;
comment|/* Get status for drive 1 */
name|du
operator|->
name|dk_error
operator|=
name|inb
argument_list|(
name|du
operator|->
name|dk_port
operator|+
name|wd_error
argument_list|)
expr_stmt|;
comment|/* printf("Error (drv 1) : %x\n", du->dk_error); */
comment|/* 			 * Sometimes (apparently mostly with ATAPI 			 * drives involved) 0x81 really means 0x81 			 * (drive 0 OK, drive 1 failed). 			 */
if|if
condition|(
name|du
operator|->
name|dk_error
operator|!=
literal|0x01
operator|&&
name|du
operator|->
name|dk_error
operator|!=
literal|0x81
condition|)
goto|goto
name|nodevice
goto|;
block|}
else|else
comment|/* drive 0 fail */
goto|goto
name|nodevice
goto|;
block|}
name|free
argument_list|(
name|du
argument_list|,
name|M_TEMP
argument_list|)
expr_stmt|;
return|return
operator|(
name|IO_WDCSIZE
operator|)
return|;
name|nodevice
label|:
name|free
argument_list|(
name|du
argument_list|,
name|M_TEMP
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Attach each drive if possible.  */
end_comment

begin_function
specifier|static
name|int
name|wdattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dvp
parameter_list|)
block|{
name|int
name|unit
decl_stmt|,
name|lunit
decl_stmt|,
name|flags
decl_stmt|,
name|i
decl_stmt|;
name|struct
name|disk
modifier|*
name|du
decl_stmt|;
name|struct
name|wdparams
modifier|*
name|wp
decl_stmt|;
specifier|static
name|char
name|buf
index|[]
init|=
literal|"wdcXXX"
decl_stmt|;
specifier|static
name|int
name|once
decl_stmt|;
name|dvp
operator|->
name|id_intr
operator|=
name|wdintr
expr_stmt|;
if|if
condition|(
name|dvp
operator|->
name|id_unit
operator|>=
name|NWDC
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|!
name|once
condition|)
block|{
name|cdevsw_add
argument_list|(
operator|&
name|wd_cdevsw
argument_list|)
expr_stmt|;
name|once
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|eide_quirks
operator|&
name|Q_CMD640B
condition|)
block|{
if|if
condition|(
name|dvp
operator|->
name|id_unit
operator|==
name|PRIMARY
condition|)
block|{
name|printf
argument_list|(
literal|"wdc0: CMD640B workaround enabled\n"
argument_list|)
expr_stmt|;
name|bufq_init
argument_list|(
operator|&
name|wdtab
index|[
name|PRIMARY
index|]
operator|.
name|controller_queue
argument_list|)
expr_stmt|;
block|}
block|}
else|else
name|bufq_init
argument_list|(
operator|&
name|wdtab
index|[
name|dvp
operator|->
name|id_unit
index|]
operator|.
name|controller_queue
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"wdc%d"
argument_list|,
name|dvp
operator|->
name|id_unit
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|resource_query_string
argument_list|(
operator|-
literal|1
argument_list|,
literal|"at"
argument_list|,
name|buf
argument_list|)
init|;
name|i
operator|!=
operator|-
literal|1
condition|;
name|i
operator|=
name|resource_query_string
argument_list|(
name|i
argument_list|,
literal|"at"
argument_list|,
name|buf
argument_list|)
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|resource_query_name
argument_list|(
name|i
argument_list|)
argument_list|,
literal|"wd"
argument_list|)
condition|)
comment|/* Avoid a bit of foot shooting. */
continue|continue;
name|lunit
operator|=
name|resource_query_unit
argument_list|(
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|lunit
operator|>=
name|NWD
condition|)
continue|continue;
if|if
condition|(
name|resource_int_value
argument_list|(
literal|"wd"
argument_list|,
name|lunit
argument_list|,
literal|"drive"
argument_list|,
operator|&
name|unit
argument_list|)
operator|!=
literal|0
condition|)
continue|continue;
if|if
condition|(
name|resource_int_value
argument_list|(
literal|"wd"
argument_list|,
name|lunit
argument_list|,
literal|"flags"
argument_list|,
operator|&
name|flags
argument_list|)
operator|!=
literal|0
condition|)
name|flags
operator|=
literal|0
expr_stmt|;
name|du
operator|=
name|malloc
argument_list|(
sizeof|sizeof
expr|*
name|du
argument_list|,
name|M_TEMP
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|du
operator|==
name|NULL
condition|)
continue|continue;
if|if
condition|(
name|wddrives
index|[
name|lunit
index|]
operator|!=
name|NULL
condition|)
name|panic
argument_list|(
literal|"drive attached twice"
argument_list|)
expr_stmt|;
name|wddrives
index|[
name|lunit
index|]
operator|=
name|du
expr_stmt|;
name|bufq_init
argument_list|(
operator|&
name|drive_queue
index|[
name|lunit
index|]
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|du
argument_list|,
sizeof|sizeof
expr|*
name|du
argument_list|)
expr_stmt|;
name|du
operator|->
name|dk_ctrlr
operator|=
name|dvp
operator|->
name|id_unit
expr_stmt|;
if|if
condition|(
name|eide_quirks
operator|&
name|Q_CMD640B
condition|)
block|{
name|du
operator|->
name|dk_ctrlr_cmd640
operator|=
name|PRIMARY
expr_stmt|;
block|}
else|else
block|{
name|du
operator|->
name|dk_ctrlr_cmd640
operator|=
name|du
operator|->
name|dk_ctrlr
expr_stmt|;
block|}
name|du
operator|->
name|dk_unit
operator|=
name|unit
expr_stmt|;
name|du
operator|->
name|dk_lunit
operator|=
name|lunit
expr_stmt|;
name|du
operator|->
name|dk_port
operator|=
name|dvp
operator|->
name|id_iobase
expr_stmt|;
name|du
operator|->
name|dk_altport
operator|=
name|du
operator|->
name|dk_port
operator|+
name|wd_ctlr
expr_stmt|;
comment|/* 		 * Use the individual device flags or the controller 		 * flags. 		 */
name|du
operator|->
name|cfg_flags
operator|=
name|flags
operator||
operator|(
operator|(
name|dvp
operator|->
name|id_flags
operator|)
operator|>>
operator|(
literal|16
operator|*
name|unit
operator|)
operator|)
expr_stmt|;
if|if
condition|(
name|wdgetctlr
argument_list|(
name|du
argument_list|)
operator|==
literal|0
condition|)
block|{
name|bzero
argument_list|(
argument|wd_ident[lunit]
argument_list|,
argument|sizeof(wd_ident[lunit]); 			snprintf(wd_ident[lunit], sizeof(wd_ident[lunit]),
literal|"%s %s"
argument|, 				 du->dk_params.wdp_model, 				 du->dk_params.wdp_serial);
comment|/* 			 * Print out description of drive. 			 * wdp_model may not be null terminated. 			 */
argument|printf(
literal|"wdc%d: unit %d (wd%d):<%.*s>"
argument|, 				dvp->id_unit, unit, lunit, 				(int)sizeof(du->dk_params.wdp_model), 				du->dk_params.wdp_model); 			if (du->dk_flags& DKFL_LBA) 				printf(
literal|", LBA"
argument|); 			if (du->dk_flags& DKFL_USEDMA) 				printf(
literal|", DMA"
argument|); 			if (du->dk_flags& DKFL_32BIT) 				printf(
literal|", 32-bit"
argument|); 			if (du->dk_multi>
literal|1
argument|) 				printf(
literal|", multi-block-%d"
argument|, du->dk_multi); 			if (du->cfg_flags& WDOPT_SLEEPHACK) 				printf(
literal|", sleep-hack"
argument|); 			printf(
literal|"\n"
argument|); 			if (bootverbose) { 				printf(
literal|"wd%d: Serial Number %s\n"
argument|, lunit, 				       du->dk_params.wdp_serial); 			} 			if (du->dk_params.wdp_heads ==
literal|0
argument|) 				printf(
literal|"wd%d: size unknown, using %s values\n"
argument|, 				       lunit, du->dk_dd.d_secperunit>
literal|17
argument|?
literal|"BIOS"
argument|:
literal|"fake"
argument|); 			printf(
literal|"wd%d: %luMB (%lu sectors), "
literal|"%lu cyls, %lu heads, %lu S/T, %lu B/S\n"
argument|, 			       lunit, 			       du->dk_dd.d_secperunit 			       / ((
literal|1024L
argument|*
literal|1024L
argument|) / du->dk_dd.d_secsize), 			       du->dk_dd.d_secperunit, 			       du->dk_dd.d_ncylinders, 			       du->dk_dd.d_ntracks, 			       du->dk_dd.d_nsectors, 			       du->dk_dd.d_secsize);  			if (bootverbose) { 			    wp =&du->dk_params; 			    printf(
literal|"wd%d: ATA INQUIRE valid = %04x, "
literal|"dmamword = %04x, apio = %04x, "
literal|"udma = %04x\n"
argument|, 				du->dk_lunit, 				wp->wdp_atavalid, 				wp->wdp_dmamword, 				wp->wdp_eidepiomodes, 				wp->wdp_udmamode); 			  }
comment|/* 			 * Start timeout routine for this drive. 			 * XXX timeout should be per controller. 			 */
argument|wdtimeout(du);  			make_dev(&wd_cdevsw,  			    dkmakeminor(lunit, WHOLE_DISK_SLICE, RAW_PART), 			    UID_ROOT, GID_OPERATOR,
literal|0640
argument|,
literal|"rwd%d"
argument|, lunit);
comment|/* 			 * Export the drive to the devstat interface. 			 */
argument|devstat_add_entry(&du->dk_stats,
literal|"wd"
argument|,  					  lunit, du->dk_dd.d_secsize, 					  DEVSTAT_NO_ORDERED_TAGS, 					  DEVSTAT_TYPE_DIRECT | 					  DEVSTAT_TYPE_IF_IDE, 					  DEVSTAT_PRIORITY_WD);  		} else { 			free(du, M_TEMP); 			wddrives[lunit] = NULL; 		} 	}
comment|/* 	 * Probe all free IDE units, searching for ATAPI drives. 	 */
argument|for (unit=
literal|0
argument|; unit<
literal|2
argument|; ++unit) { 		for (lunit=
literal|0
argument|; lunit<NWD; ++lunit) 			if (wddrives[lunit]&& 			    wddrives[lunit]->dk_ctrlr == dvp->id_unit&& 			    wddrives[lunit]->dk_unit == unit) 				goto next; 		if (atapi_attach (dvp->id_unit, unit, dvp->id_iobase)) 			atapictrlr = dvp->id_unit; next: ; 	}
comment|/* 	 * Discard any interrupts generated by wdgetctlr().  wdflushirq() 	 * doesn't work now because the ambient ipl is too high. 	 */
argument|if (eide_quirks& Q_CMD640B) { 		wdtab[PRIMARY].b_active =
literal|2
argument|; 	} else { 		wdtab[dvp->id_unit].b_active =
literal|2
argument|; 	}  	return (
literal|1
argument|); }
comment|/* Read/write routine for a buffer.  Finds the proper unit, range checks  * arguments, and schedules the transfer.  Does not wait for the transfer  * to complete.  Multi-page transfers are supported.  All I/O requests must  * be a multiple of a sector in length.  */
argument|void wdstrategy(register struct buf *bp) { 	struct disk *du; 	int	lunit = dkunit(bp->b_dev); 	int	s;
comment|/* valid unit, controller, and request?  */
argument|if (lunit>= NWD || bp->b_blkno<
literal|0
argument||| (du = wddrives[lunit]) == NULL 	    || bp->b_bcount % DEV_BSIZE !=
literal|0
argument|) {  		bp->b_error = EINVAL; 		bp->b_flags |= B_ERROR; 		goto done; 	}
comment|/* 	 * Do bounds checking, adjust transfer, and set b_pblkno. 	 */
argument|if (dscheck(bp, du->dk_slices)<=
literal|0
argument|) 		goto done;
comment|/* 	 * Check for *any* block on this transfer being on the bad block list 	 * if it is, then flag the block as a transfer that requires 	 * bad block handling.  Also, used as a hint for low level disksort 	 * clustering code to keep from coalescing a bad transfer into 	 * a normal transfer.  Single block transfers for a large number of 	 * blocks associated with a cluster I/O are undesirable. 	 * 	 * XXX the old disksort() doesn't look at B_BAD.  Coalescing _is_ 	 * desirable.  We should split the results at bad blocks just 	 * like we should split them at MAXTRANSFER boundaries. 	 */
argument|if (dsgetbad(bp->b_dev, du->dk_slices) != NULL) { 		long *badsect = dsgetbad(bp->b_dev, du->dk_slices)->bi_bad; 		int i; 		int nsecs = howmany(bp->b_bcount, DEV_BSIZE);
comment|/* XXX pblkno is too physical. */
argument|daddr_t nspblkno = bp->b_pblkno 		    - du->dk_slices->dss_slices[dkslice(bp->b_dev)].ds_offset; 		int blkend = nspblkno + nsecs;  		for (i =
literal|0
argument|; badsect[i] != -
literal|1
argument|&& badsect[i]< blkend; i++) { 			if (badsect[i]>= nspblkno) { 				bp->b_flags |= B_BAD; 				break; 			} 		} 	}
comment|/* queue transfer on drive, activate drive and controller if idle */
argument|s = splbio();
comment|/* Pick up changes made by readdisklabel(). */
argument|if (du->dk_flags& DKFL_LABELLING&& du->dk_state> RECAL) { 		wdsleep(du->dk_ctrlr,
literal|"wdlab"
argument|); 		du->dk_state = WANTOPEN; 	}  	bufqdisksort(&drive_queue[lunit], bp);  	if (wdutab[lunit].b_active ==
literal|0
argument|) 		wdustart(du);
comment|/* start drive */
argument|if (wdtab[du->dk_ctrlr_cmd640].b_active ==
literal|0
argument|) 		wdstart(du->dk_ctrlr);
comment|/* start controller */
comment|/* Tell devstat that we have started a transaction on this drive */
argument|devstat_start_transaction(&du->dk_stats);  	splx(s); 	return;  done:
comment|/* toss transfer, we're done early */
argument|biodone(bp); }
comment|/*  * Routine to queue a command to the controller.  The unit's  * request is linked into the active list for the controller.  * If the controller is idle, the transfer is started.  */
argument|static void wdustart(register struct disk *du) { 	register struct buf *bp; 	int	ctrlr = du->dk_ctrlr_cmd640;
comment|/* unit already active? */
argument|if (wdutab[du->dk_lunit].b_active) 		return;   	bp = bufq_first(&drive_queue[du->dk_lunit]); 	if (bp == NULL) {
comment|/* yes, an assign */
argument|return; 	}
comment|/* 	 * store away which device we came from. 	 */
argument|bp->b_driver1 = du;  	bufq_remove(&drive_queue[du->dk_lunit], bp);
comment|/* link onto controller queue */
argument|bufq_insert_tail(&wdtab[ctrlr].controller_queue, bp);
comment|/* mark the drive unit as busy */
argument|wdutab[du->dk_lunit].b_active =
literal|1
argument|;  }
comment|/*  * Controller startup routine.  This does the calculation, and starts  * a single-sector read or write operation.  Called to start a transfer,  * or from the interrupt routine to continue a multi-sector transfer.  * RESTRICTIONS:  * 1. The transfer length must be an exact multiple of the sector size.  */
argument|void wdstart(int ctrlr) { 	register struct disk *du; 	register struct buf *bp; 	struct diskgeom *lp;
comment|/* XXX sic */
argument|long	blknum; 	long	secpertrk
argument_list|,
argument|secpercyl; 	u_int	lunit; 	u_int	count; 	int	ctrlr_atapi;  	if (eide_quirks& Q_CMD640B) { 		ctrlr = PRIMARY; 		ctrlr_atapi = atapictrlr; 	} else { 		ctrlr_atapi = ctrlr; 	}  	if (wdtab[ctrlr].b_active ==
literal|2
argument|) 		wdtab[ctrlr].b_active =
literal|0
argument|; 	if (wdtab[ctrlr].b_active) 		return;
comment|/* is there a drive for the controller to do a transfer with? */
argument|bp = bufq_first(&wdtab[ctrlr].controller_queue); 	if (bp == NULL) { 		if (atapi_start&& atapi_start (ctrlr_atapi))
comment|/* mark controller active in ATAPI mode */
argument|wdtab[ctrlr].b_active =
literal|3
argument|; 		return; 	}
comment|/* obtain controller and drive information */
argument|lunit = dkunit(bp->b_dev); 	du = wddrives[lunit];
comment|/* if not really a transfer, do control operations specially */
argument|if (du->dk_state< OPEN) { 		if (du->dk_state != WANTOPEN) 			printf(
literal|"wd%d: wdstart: weird dk_state %d\n"
argument|, 			       du->dk_lunit, du->dk_state); 		if (wdcontrol(bp) !=
literal|0
argument|) 			printf(
literal|"wd%d: wdstart: wdcontrol returned nonzero, state = %d\n"
argument|, 			       du->dk_lunit, du->dk_state); 		return; 	}
comment|/* calculate transfer details */
argument|blknum = bp->b_pblkno + du->dk_skip;
ifdef|#
directive|ifdef
name|WDDEBUG
argument|if (du->dk_skip ==
literal|0
argument|) 		printf(
literal|"wd%d: wdstart: %s %d@%d; map "
argument|, lunit, 		       (bp->b_flags& B_READ) ?
literal|"read"
argument|:
literal|"write"
argument|, 		       bp->b_bcount, blknum); 	else 		printf(
literal|" %d)%x"
argument|, du->dk_skip, inb(du->dk_altport));
endif|#
directive|endif
argument|lp =&du->dk_dd; 	secpertrk = lp->d_nsectors; 	secpercyl = lp->d_secpercyl;  	if (du->dk_skip ==
literal|0
argument|) { 		du->dk_bc = bp->b_bcount;  		if (bp->b_flags& B_BAD
comment|/* 		     * XXX handle large transfers inefficiently instead 		     * of crashing on them. 		     */
argument||| howmany(du->dk_bc, DEV_BSIZE)> MAXTRANSFER) 			du->dk_flags |= DKFL_SINGLE; 	}  	if (du->dk_flags& DKFL_SINGLE&& dsgetbad(bp->b_dev, du->dk_slices) != NULL) {
comment|/* XXX */
argument|u_long ds_offset = 		    du->dk_slices->dss_slices[dkslice(bp->b_dev)].ds_offset;  		blknum = transbad144(dsgetbad(bp->b_dev, du->dk_slices), 				     blknum - ds_offset) + ds_offset; 	}  	wdtab[ctrlr].b_active =
literal|1
argument|;
comment|/* mark controller active */
comment|/* if starting a multisector transfer, or doing single transfers */
argument|if (du->dk_skip ==
literal|0
argument||| (du->dk_flags& DKFL_SINGLE)) { 		u_int	command; 		u_int	count1; 		long	cylin
argument_list|,
argument|head
argument_list|,
argument|sector;  		if (du->dk_flags& DKFL_LBA) { 			sector = (blknum>>
literal|0
argument|)&
literal|0xff
argument|;  			cylin = (blknum>>
literal|8
argument|)&
literal|0xffff
argument|; 			head = ((blknum>>
literal|24
argument|)&
literal|0xf
argument|) | WDSD_LBA;  		} 		else { 			cylin = blknum / secpercyl; 			head = (blknum % secpercyl) / secpertrk; 			sector = blknum % secpertrk; 		}
comment|/*  		 * XXX this looks like an attempt to skip bad sectors 		 * on write. 		 */
argument|if (wdtab[ctrlr].b_errcnt&& (bp->b_flags& B_READ) ==
literal|0
argument|) 			du->dk_bc += DEV_BSIZE;  		count1 = howmany( du->dk_bc, DEV_BSIZE);  		du->dk_flags&= ~DKFL_MULTI;  		if (du->dk_flags& DKFL_SINGLE) { 			command = (bp->b_flags& B_READ) 				  ? WDCC_READ : WDCC_WRITE; 			count1 =
literal|1
argument|; 			du->dk_currentiosize =
literal|1
argument|; 		} else { 			if((du->dk_flags& DKFL_USEDMA)&& 			   wddma[du->dk_interface].wdd_dmaverify(du->dk_dmacookie, 				(void *)((int)bp->b_data +  				     du->dk_skip * DEV_BSIZE), 				du->dk_bc, 				bp->b_flags& B_READ)) { 				du->dk_flags |= DKFL_DMA; 				if( bp->b_flags& B_READ) 					command = WDCC_READ_DMA; 				else 					command = WDCC_WRITE_DMA; 				du->dk_currentiosize = count1; 			} else if( (count1>
literal|1
argument|)&& (du->dk_multi>
literal|1
argument|)) { 				du->dk_flags |= DKFL_MULTI; 				if( bp->b_flags& B_READ) { 					command = WDCC_READ_MULTI; 				} else { 					command = WDCC_WRITE_MULTI; 				} 				du->dk_currentiosize = du->dk_multi; 				if( du->dk_currentiosize> count1) 					du->dk_currentiosize = count1; 			} else { 				if( bp->b_flags& B_READ) { 					command = WDCC_READ; 				} else { 					command = WDCC_WRITE; 				} 				du->dk_currentiosize =
literal|1
argument|; 			} 		}
comment|/* 		 * XXX this loop may never terminate.  The code to handle 		 * counting down of retries and eventually failing the i/o 		 * is in wdintr() and we can't get there from here. 		 */
argument|if (wdtest !=
literal|0
argument|) { 			if (--wdtest ==
literal|0
argument|) { 				wdtest =
literal|100
argument|; 				printf(
literal|"dummy wdunwedge\n"
argument|); 				wdunwedge(du); 			} 		}  		if ((du->dk_flags& (DKFL_DMA|DKFL_SINGLE)) == DKFL_DMA) { 			wddma[du->dk_interface].wdd_dmaprep(du->dk_dmacookie, 					   (void *)((int)bp->b_data +  						    du->dk_skip * DEV_BSIZE), 					   du->dk_bc, 					   bp->b_flags& B_READ); 		} 		while (wdcommand(du, cylin, head, sector, count1, command) 		       !=
literal|0
argument|) { 			wderror(bp, du,
literal|"wdstart: timeout waiting to give command"
argument|); 			wdunwedge(du); 		}
ifdef|#
directive|ifdef
name|WDDEBUG
argument|printf(
literal|"cylin %ld head %ld sector %ld addr %x sts %x\n"
argument|, 		       cylin, head, sector, 		       (int)bp->b_data + du->dk_skip * DEV_BSIZE, 		       inb(du->dk_altport));
endif|#
directive|endif
argument|}
comment|/* 	 * Schedule wdtimeout() to wake up after a few seconds.  Retrying 	 * unmarked bad blocks can take 3 seconds!  Then it is not good that 	 * we retry 5 times. 	 * 	 * On the first try, we give it 10 seconds, for drives that may need 	 * to spin up. 	 * 	 * XXX wdtimeout() doesn't increment the error count so we may loop 	 * forever.  More seriously, the loop isn't forever but causes a 	 * crash. 	 * 	 * TODO fix b_resid bug elsewhere (fd.c....).  Fix short but positive 	 * counts being discarded after there is an error (in physio I 	 * think).  Discarding them would be OK if the (special) file offset 	 * was not advanced. 	 */
argument|if (wdtab[ctrlr].b_errcnt ==
literal|0
argument|) 		du->dk_timeout =
literal|1
argument|+
literal|10
argument|; 	else 		du->dk_timeout =
literal|1
argument|+
literal|3
argument|;
comment|/* if this is a DMA op, start DMA and go away until it's done. */
argument|if ((du->dk_flags& (DKFL_DMA|DKFL_SINGLE)) == DKFL_DMA) { 		wddma[du->dk_interface].wdd_dmastart(du->dk_dmacookie); 		return; 	}
comment|/* If this is a read operation, just go away until it's done. */
argument|if (bp->b_flags& B_READ) 		return;
comment|/* Ready to send data? */
argument|if (wdwait(du, WDCS_READY | WDCS_SEEKCMPLT | WDCS_DRQ, TIMEOUT)<
literal|0
argument|) { 		wderror(bp, du,
literal|"wdstart: timeout waiting for DRQ"
argument|);
comment|/* 		 * XXX what do we do now?  If we've just issued the command, 		 * then we can treat this failure the same as a command 		 * failure.  But if we are continuing a multi-sector write, 		 * the command was issued ages ago, so we can't simply 		 * restart it. 		 * 		 * XXX we waste a lot of time unnecessarily translating block 		 * numbers to cylin/head/sector for continued i/o's. 		 */
argument|}  	count =
literal|1
argument|; 	if( du->dk_flags& DKFL_MULTI) { 		count = howmany(du->dk_bc, DEV_BSIZE); 		if( count> du->dk_multi) 			count = du->dk_multi; 		if( du->dk_currentiosize> count) 			du->dk_currentiosize = count; 	}  	if (du->dk_flags& DKFL_32BIT) 		outsl(du->dk_port + wd_data, 		      (void *)((int)bp->b_data + du->dk_skip * DEV_BSIZE), 		      (count * DEV_BSIZE) / sizeof(long)); 	else 		outsw(du->dk_port + wd_data, 		      (void *)((int)bp->b_data + du->dk_skip * DEV_BSIZE), 		      (count * DEV_BSIZE) / sizeof(short)); 	du->dk_bc -= DEV_BSIZE * count; }
comment|/* Interrupt routine for the controller.  Acknowledge the interrupt, check for  * errors on the current operation, mark it done if necessary, and start  * the next request.  Also check for a partially done transfer, and  * continue with the next chunk if so.  */
argument|void wdintr(void *unitnum) { 	register struct	disk *du; 	register struct buf *bp; 	int dmastat =
literal|0
argument|;
comment|/* Shut up GCC */
argument|int unit = (int)unitnum;  	int ctrlr_atapi;  	if (eide_quirks& Q_CMD640B) { 		unit = PRIMARY; 		ctrlr_atapi = atapictrlr; 	} else { 		ctrlr_atapi = unit; 	}  	if (wdtab[unit].b_active ==
literal|2
argument|) 		return;
comment|/* intr in wdflushirq() */
argument|if (!wdtab[unit].b_active) {
ifdef|#
directive|ifdef
name|WDDEBUG
comment|/* 		 * These happen mostly because the power-mgt part of the 		 * bios shuts us down, and we just manage to see the 		 * interrupt from the "SLEEP" command.  		 */
argument|printf(
literal|"wdc%d: extra interrupt\n"
argument|, unit);
endif|#
directive|endif
argument|return; 	} 	if (wdtab[unit].b_active ==
literal|3
argument|) {
comment|/* process an ATAPI interrupt */
argument|if (atapi_intr&& atapi_intr (ctrlr_atapi))
comment|/* ATAPI op continues */
argument|return;
comment|/* controller is free, start new op */
argument|wdtab[unit].b_active =
literal|0
argument|; 		wdstart (unit); 		return; 	} 	bp = bufq_first(&wdtab[unit].controller_queue); 	du = wddrives[dkunit(bp->b_dev)];
comment|/* finish off DMA */
argument|if ((du->dk_flags& (DKFL_DMA|DKFL_SINGLE)) == DKFL_DMA) {
comment|/* XXX SMP boxes sometimes generate an early intr.  Why? */
argument|if ((wddma[du->dk_interface].wdd_dmastatus(du->dk_dmacookie)&  		    WDDS_INTERRUPT) ==
literal|0
argument|) 			return; 		dmastat = wddma[du->dk_interface].wdd_dmadone(du->dk_dmacookie); 	}  	du->dk_timeout =
literal|0
argument|;
comment|/* check drive status/failure */
argument|if (wdwait(du,
literal|0
argument|, TIMEOUT)<
literal|0
argument|) { 		wderror(bp, du,
literal|"wdintr: timeout waiting for status"
argument|); 		du->dk_status |= WDCS_ERR;
comment|/* XXX */
argument|}
comment|/* is it not a transfer, but a control operation? */
argument|if (du->dk_state< OPEN) { 		wdtab[unit].b_active =
literal|0
argument|; 		switch (wdcontrol(bp)) { 		case
literal|0
argument|: 			return; 		case
literal|1
argument|: 			wdstart(unit); 			return; 		case
literal|2
argument|: 			goto done; 		} 	}
comment|/* have we an error? */
argument|if ((du->dk_status& (WDCS_ERR | WDCS_ECCCOR)) 	    || (((du->dk_flags& (DKFL_DMA|DKFL_SINGLE)) == DKFL_DMA)&& dmastat != WDDS_INTERRUPT)) {  		unsigned int errstat; oops:
comment|/* 		 * XXX bogus inb() here 		 */
argument|errstat = inb(du->dk_port + wd_error);  		if(((du->dk_flags& (DKFL_DMA|DKFL_SINGLE)) == DKFL_DMA)&& 		   (errstat& WDERR_ABORT)) { 			wderror(bp, du,
literal|"reverting to PIO mode"
argument|); 			du->dk_flags&= ~DKFL_USEDMA; 		} else if((du->dk_flags& DKFL_MULTI)&&                     (errstat& WDERR_ABORT)) { 			wderror(bp, du,
literal|"reverting to non-multi sector mode"
argument|); 			du->dk_multi =
literal|1
argument|; 		}  		if (!(du->dk_status& (WDCS_ERR | WDCS_ECCCOR))&& 		    (((du->dk_flags& (DKFL_DMA|DKFL_SINGLE)) == DKFL_DMA)&&  		     (dmastat != WDDS_INTERRUPT))) 			printf(
literal|"wd%d: DMA failure, DMA status %b\n"
argument|,  			       du->dk_lunit, dmastat, WDDS_BITS);
ifdef|#
directive|ifdef
name|WDDEBUG
argument|wderror(bp, du,
literal|"wdintr"
argument|);
endif|#
directive|endif
argument|if ((du->dk_flags& DKFL_SINGLE) ==
literal|0
argument|) { 			du->dk_flags |= DKFL_ERROR; 			goto outt; 		}  		if (du->dk_flags& DKFL_BADSCAN) { 			bp->b_error = EIO; 			bp->b_flags |= B_ERROR; 		} else if (du->dk_status& WDCS_ERR) { 			if (++wdtab[unit].b_errcnt< RETRIES) { 				wdtab[unit].b_active =
literal|0
argument|; 			} else { 				wderror(bp, du,
literal|"hard error"
argument|); 				bp->b_error = EIO; 				bp->b_flags |= B_ERROR;
comment|/* flag the error */
argument|} 		} else if (du->dk_status& WDCS_ECCCOR) 			wderror(bp, du,
literal|"soft ecc"
argument|); 	}
comment|/* 	 * If this was a successful read operation, fetch the data. 	 */
argument|if (((bp->b_flags& (B_READ | B_ERROR)) == B_READ)&& !((du->dk_flags& (DKFL_DMA|DKFL_SINGLE)) == DKFL_DMA)&& wdtab[unit].b_active) { 		u_int	chk
argument_list|,
argument|dummy
argument_list|,
argument|multisize; 		multisize = chk = du->dk_currentiosize * DEV_BSIZE; 		if( du->dk_bc< chk) { 			chk = du->dk_bc; 			if( ((chk + DEV_BSIZE -
literal|1
argument|) / DEV_BSIZE)< du->dk_currentiosize) { 				du->dk_currentiosize = (chk + DEV_BSIZE -
literal|1
argument|) / DEV_BSIZE; 				multisize = du->dk_currentiosize * DEV_BSIZE; 			} 		}
comment|/* ready to receive data? */
argument|if ((du->dk_status& (WDCS_READY | WDCS_SEEKCMPLT | WDCS_DRQ)) 		    != (WDCS_READY | WDCS_SEEKCMPLT | WDCS_DRQ)) 			wderror(bp, du,
literal|"wdintr: read intr arrived early"
argument|); 		if (wdwait(du, WDCS_READY | WDCS_SEEKCMPLT | WDCS_DRQ, TIMEOUT) !=
literal|0
argument|) { 			wderror(bp, du,
literal|"wdintr: read error detected late"
argument|); 			goto oops; 		}
comment|/* suck in data */
argument|if( du->dk_flags& DKFL_32BIT) 			insl(du->dk_port + wd_data, 			     (void *)((int)bp->b_data + du->dk_skip * DEV_BSIZE), 					chk / sizeof(long)); 		else 			insw(du->dk_port + wd_data, 			     (void *)((int)bp->b_data + du->dk_skip * DEV_BSIZE), 					chk / sizeof(short)); 		du->dk_bc -= chk;
comment|/* XXX for obsolete fractional sector reads. */
argument|while (chk< multisize) { 			insw(du->dk_port + wd_data,&dummy,
literal|1
argument|); 			chk += sizeof(short); 		}  	}
comment|/* final cleanup on DMA */
argument|if (((bp->b_flags& B_ERROR) ==
literal|0
argument|)&& ((du->dk_flags& (DKFL_DMA|DKFL_SINGLE)) == DKFL_DMA)&& wdtab[unit].b_active) { 		int iosize;  		iosize = du->dk_currentiosize * DEV_BSIZE;  		du->dk_bc -= iosize;  	}  outt: 	if (wdtab[unit].b_active) { 		if ((bp->b_flags& B_ERROR) ==
literal|0
argument|) { 			du->dk_skip += du->dk_currentiosize;
comment|/* add to successful sectors */
argument|if (wdtab[unit].b_errcnt) 				wderror(bp, du,
literal|"soft error"
argument|); 			wdtab[unit].b_errcnt =
literal|0
argument|;
comment|/* see if more to transfer */
argument|if (du->dk_bc>
literal|0
argument|&& (du->dk_flags& DKFL_ERROR) ==
literal|0
argument|) { 				if( (du->dk_flags& DKFL_SINGLE) || 					((bp->b_flags& B_READ) ==
literal|0
argument|)) { 					wdtab[unit].b_active =
literal|0
argument|; 					wdstart(unit); 				} else { 					du->dk_timeout =
literal|1
argument|+
literal|3
argument|; 				} 				return;
comment|/* next chunk is started */
argument|} else if ((du->dk_flags& (DKFL_SINGLE | DKFL_ERROR)) 				   == DKFL_ERROR) { 				du->dk_skip =
literal|0
argument|; 				du->dk_flags&= ~DKFL_ERROR; 				du->dk_flags |= DKFL_SINGLE; 				wdtab[unit].b_active =
literal|0
argument|; 				wdstart(unit); 				return;
comment|/* redo xfer sector by sector */
argument|} 		}  done: ;
comment|/* done with this transfer, with or without error */
argument|du->dk_flags&= ~(DKFL_SINGLE|DKFL_DMA); 		bufq_remove(&wdtab[unit].controller_queue, bp); 		wdtab[unit].b_errcnt =
literal|0
argument|; 		bp->b_resid = bp->b_bcount - du->dk_skip * DEV_BSIZE; 		wdutab[du->dk_lunit].b_active =
literal|0
argument|; 		du->dk_skip =
literal|0
argument|; 		devstat_end_transaction_buf(&du->dk_stats, bp); 		biodone(bp); 	}
comment|/* controller idle */
argument|wdtab[unit].b_active =
literal|0
argument|;
comment|/* anything more on drive queue? */
argument|wdustart(du);
comment|/* anything more for controller to do? */
argument|wdstart(unit); }
comment|/*  * Initialize a drive.  */
argument|int wdopen(dev_t dev, int flags, int fmt, struct proc *p) { 	register unsigned int lunit; 	register struct disk *du; 	int	error;  	lunit = dkunit(dev); 	if (lunit>= NWD || dktype(dev) !=
literal|0
argument|) 		return (ENXIO); 	du = wddrives[lunit]; 	if (du == NULL) 		return (ENXIO);  	dev->si_iosize_max =
literal|248
argument|*
literal|512
argument|;
comment|/* Finish flushing IRQs left over from wdattach(). */
argument|if (wdtab[du->dk_ctrlr_cmd640].b_active ==
literal|2
argument|) 		wdtab[du->dk_ctrlr_cmd640].b_active =
literal|0
argument|;  	du->dk_flags&= ~DKFL_BADSCAN;
comment|/* spin waiting for anybody else reading the disk label */
argument|while (du->dk_flags& DKFL_LABELLING) 		tsleep((caddr_t)&du->dk_flags, PZERO -
literal|1
argument|,
literal|"wdopen"
argument|,
literal|1
argument|);
if|#
directive|if
literal|1
argument|wdsleep(du->dk_ctrlr,
literal|"wdopn1"
argument|); 	du->dk_flags |= DKFL_LABELLING; 	du->dk_state = WANTOPEN; 	{ 	struct disklabel label;  	bzero(&label, sizeof label); 	label.d_secsize = du->dk_dd.d_secsize; 	label.d_nsectors = du->dk_dd.d_nsectors; 	label.d_ntracks = du->dk_dd.d_ntracks; 	label.d_ncylinders = du->dk_dd.d_ncylinders; 	label.d_secpercyl = du->dk_dd.d_secpercyl; 	label.d_secperunit = du->dk_dd.d_secperunit; 	error = dsopen(dev, fmt, DSO_BAD144,&du->dk_slices,&label); 	} 	du->dk_flags&= ~DKFL_LABELLING; 	wdsleep(du->dk_ctrlr,
literal|"wdopn2"
argument|); 	return (error);
else|#
directive|else
argument|if ((du->dk_flags& DKFL_BSDLABEL) ==
literal|0
argument|) {
comment|/* 		 * wdtab[ctrlr].b_active != 0 implies  XXX applicable now ?? 		 * drive_queue[lunit].b_act == NULL (?)  XXX applicable now ?? 		 * so the following guards most things (until the next i/o). 		 * It doesn't guard against a new i/o starting and being 		 * affected by the label being changed.  Sigh. 		 */
argument|wdsleep(du->dk_ctrlr,
literal|"wdopn1"
argument|);  		du->dk_flags |= DKFL_LABELLING; 		du->dk_state = WANTOPEN;  		error = dsinit(dkmodpart(dev, RAW_PART),&du->dk_dd,&du->dk_slices); 		if (error !=
literal|0
argument|) { 			du->dk_flags&= ~DKFL_LABELLING; 			return (error); 		}
comment|/* XXX check value returned by wdwsetctlr(). */
argument|wdwsetctlr(du); 		if (dkslice(dev) == WHOLE_DISK_SLICE) { 			dsopen(dev, fmt, du->dk_slices); 			return (
literal|0
argument|); 		}
comment|/* 		 * Read label using RAW_PART partition. 		 * 		 * If the drive has an MBR, then the current geometry (from 		 * wdgetctlr()) is used to read it; then the BIOS/DOS 		 * geometry is inferred and used to read the label off the 		 * 'c' partition.  Otherwise the label is read using the 		 * current geometry.  The label gives the final geometry. 		 * If bad sector handling is enabled, then this geometry 		 * is used to read the bad sector table.  The geometry 		 * changes occur inside readdisklabel() and are propagated 		 * to the driver by resetting the state machine. 		 * 		 * XXX can now handle changes directly since dsinit() doesn't 		 * do too much. 		 */
argument|msg = correct_readdisklabel(dkmodpart(dev, RAW_PART),&du->dk_dd);
comment|/* XXX check value returned by wdwsetctlr(). */
argument|wdwsetctlr(du); 		if (msg == NULL&& du->dk_dd.d_flags& D_BADSECT) 			msg = readbad144(dkmodpart(dev, RAW_PART),&du->dk_dd,&du->dk_bad); 		du->dk_flags&= ~DKFL_LABELLING; 		if (msg != NULL) { 			log(LOG_WARNING,
literal|"wd%d: cannot find label (%s)\n"
argument|, 			    lunit, msg); 			if (part != RAW_PART) 				return (EINVAL);
comment|/* XXX needs translation */
comment|/* 			 * Soon return.  This is how slices without labels 			 * are allowed.  They only work on the raw partition. 			 */
argument|} else { 			unsigned long newsize
argument_list|,
argument|offset
argument_list|,
argument|size;
if|#
directive|if
literal|0
comment|/* 			 * Force RAW_PART partition to be the whole disk. 			 */
argument|offset = du->dk_dd.d_partitions[RAW_PART].p_offset; 			if (offset != 0) { 				printf( 		"wd%d: changing offset of '%c' partition from %lu to 0\n", 				       du->dk_lunit, 'a' + RAW_PART, offset); 				du->dk_dd.d_partitions[RAW_PART].p_offset = 0; 			} 			size = du->dk_dd.d_partitions[RAW_PART].p_size; 			newsize = du->dk_dd.d_secperunit;
comment|/* XXX */
argument|if (size != newsize) { 				printf( 		"wd%d: changing size of '%c' partition from %lu to %lu\n", 				       du->dk_lunit, 'a' + RAW_PART, size, 				       newsize); 				du->dk_dd.d_partitions[RAW_PART].p_size 					= newsize; 			}
endif|#
directive|endif
argument|}
comment|/* Pick up changes made by readdisklabel(). */
argument|wdsleep(du->dk_ctrlr,
literal|"wdopn2"
argument|); 		du->dk_state = WANTOPEN; 	}
comment|/* 	 * Warn if a partion is opened that overlaps another partition which 	 * is open unless one is the "raw" partition (whole disk). 	 */
argument|if ((du->dk_openpart& mask) ==
literal|0
argument|&& part != RAW_PART) { 		int	start
argument_list|,
argument|end;  		pp =&du->dk_dd.d_partitions[part]; 		start = pp->p_offset; 		end = pp->p_offset + pp->p_size; 		for (pp = du->dk_dd.d_partitions; 		     pp<&du->dk_dd.d_partitions[du->dk_dd.d_npartitions]; 		     pp++) { 			if (pp->p_offset + pp->p_size<= start || 			    pp->p_offset>= end) 				continue; 			if (pp - du->dk_dd.d_partitions == RAW_PART) 				continue; 			if (du->dk_openpart& (
literal|1
argument|<< (pp - du->dk_dd.d_partitions))) 				log(LOG_WARNING,
literal|"wd%d%c: overlaps open partition (%c)\n"
argument|, 				    lunit, part +
literal|'a'
argument|, 				    pp - du->dk_dd.d_partitions +
literal|'a'
argument|); 		} 	} 	if (part>= du->dk_dd.d_npartitions&& part != RAW_PART) 		return (ENXIO);  	dsopen(dev, fmt, du->dk_slices);  	return (
literal|0
argument|);
endif|#
directive|endif
argument|}
comment|/*  * Implement operations other than read/write.  * Called from wdstart or wdintr during opens.  * Uses finite-state-machine to track progress of operation in progress.  * Returns 0 if operation still in progress, 1 if completed, 2 if error.  */
argument|static int wdcontrol(register struct buf *bp) { 	register struct disk *du; 	int	ctrlr;  	du = wddrives[dkunit(bp->b_dev)]; 	ctrlr = du->dk_ctrlr_cmd640;  	switch (du->dk_state) { 	case WANTOPEN: tryagainrecal: 		wdtab[ctrlr].b_active =
literal|1
argument|; 		if (wdcommand(du,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|, WDCC_RESTORE | WD_STEP) !=
literal|0
argument|) { 			wderror(bp, du,
literal|"wdcontrol: wdcommand failed"
argument|); 			goto maybe_retry; 		} 		du->dk_state = RECAL; 		return (
literal|0
argument|); 	case RECAL: 		if (du->dk_status& WDCS_ERR || wdsetctlr(du) !=
literal|0
argument|) { 			wderror(bp, du,
literal|"wdcontrol: recal failed"
argument|); maybe_retry: 			if (du->dk_status& WDCS_ERR) 				wdunwedge(du); 			du->dk_state = WANTOPEN; 			if (++wdtab[ctrlr].b_errcnt< RETRIES) 				goto tryagainrecal; 			bp->b_error = ENXIO;
comment|/* XXX needs translation */
argument|bp->b_flags |= B_ERROR; 			return (
literal|2
argument|); 		} 		wdtab[ctrlr].b_errcnt =
literal|0
argument|; 		du->dk_state = OPEN;
comment|/* 		 * The rest of the initialization can be done by normal 		 * means. 		 */
argument|return (
literal|1
argument|); 	} 	panic(
literal|"wdcontrol"
argument|); 	return (
literal|2
argument|); }
comment|/*  * Wait uninterruptibly until controller is not busy, then send it a command.  * The wait usually terminates immediately because we waited for the previous  * command to terminate.  */
argument|static int wdcommand(struct disk *du, u_int cylinder, u_int head, u_int sector, 	  u_int count, u_int command) { 	u_int	wdc;  	wdc = du->dk_port; 	if (du->cfg_flags& WDOPT_SLEEPHACK) {
comment|/* OK, so the APM bios has put the disk into SLEEP mode, 		 * how can we tell ?  Uhm, we can't.  There is no  		 * standardized way of finding out, and the only way to 		 * wake it up is to reset it.  Bummer. 		 * 		 * All the many and varied versions of the IDE/ATA standard 		 * explicitly tells us not to look at these registers if 		 * the disk is in SLEEP mode.  Well, too bad really, we 		 * have to find out if it's in sleep mode before we can  		 * avoid reading the registers. 		 * 		 * I have reason to belive that most disks will return 		 * either 0xff or 0x00 in all but the status register  		 * when in SLEEP mode, but I have yet to see one return  		 * 0x00, so we don't check for that yet. 		 * 		 * The check for WDCS_BUSY is for the case where the 		 * bios spins up the disk for us, but doesn't initialize 		 * it correctly					/phk 		 */
argument|if(inb(wdc + wd_precomp) + inb(wdc + wd_cyl_lo) + 		    inb(wdc + wd_cyl_hi) + inb(wdc + wd_sdh) + 		    inb(wdc + wd_sector) + inb(wdc + wd_seccnt) ==
literal|6
argument|*
literal|0xff
argument|) { 			if (bootverbose) 				printf(
literal|"wd(%d,%d): disk aSLEEP\n"
argument|, 					du->dk_ctrlr, du->dk_unit); 			wdunwedge(du); 		} else if(inb(wdc + wd_status) == WDCS_BUSY) { 			if (bootverbose) 				printf(
literal|"wd(%d,%d): disk is BUSY\n"
argument|, 					du->dk_ctrlr, du->dk_unit); 			wdunwedge(du); 		} 	}  	if (wdwait(du,
literal|0
argument|, TIMEOUT)<
literal|0
argument|) 		return (
literal|1
argument|); 	if( command == WDCC_FEATURES) { 		outb(wdc + wd_sdh, WDSD_IBM | (du->dk_unit<<
literal|4
argument|) | head); 		outb(wdc + wd_features, count); 		if ( count == WDFEA_SETXFER ) 			outb(wdc + wd_seccnt, sector); 	} else { 		outb(wdc + wd_precomp, du->dk_dd.d_precompcyl /
literal|4
argument|); 		outb(wdc + wd_cyl_lo, cylinder); 		outb(wdc + wd_cyl_hi, cylinder>>
literal|8
argument|); 		outb(wdc + wd_sdh, WDSD_IBM | (du->dk_unit<<
literal|4
argument|) | head); 		if (head& WDSD_LBA) 			outb(wdc + wd_sector, sector); 		else 			outb(wdc + wd_sector, sector +
literal|1
argument|); 		outb(wdc + wd_seccnt, count); 	} 	if (wdwait(du, (command == WDCC_DIAGNOSE || command == WDCC_IDC) 		       ?
literal|0
argument|: WDCS_READY, TIMEOUT)<
literal|0
argument|) 		return (
literal|1
argument|); 	outb(wdc + wd_command, command); 	return (
literal|0
argument|); }  static void wdsetmulti(struct disk *du) {
comment|/* 	 * The config option flags low 8 bits define the maximum multi-block 	 * transfer size.  If the user wants the maximum that the drive 	 * is capable of, just set the low bits of the config option to 	 * 0x00ff. 	 */
argument|if ((du->cfg_flags& WDOPT_MULTIMASK) !=
literal|0
argument|&& (du->dk_multi>
literal|1
argument|)) { 		int configval = du->cfg_flags& WDOPT_MULTIMASK; 		du->dk_multi = min(du->dk_multi, configval); 		if (wdcommand(du,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|, du->dk_multi, WDCC_SET_MULTI)) { 			du->dk_multi =
literal|1
argument|; 		} else { 		    	if (wdwait(du, WDCS_READY, TIMEOUT)<
literal|0
argument|) { 				du->dk_multi =
literal|1
argument|; 			} 		} 	} else { 		du->dk_multi =
literal|1
argument|; 	} }
comment|/*  * issue IDC to drive to tell it just what geometry it is to be.  */
argument|static int wdsetctlr(struct disk *du) { 	int error =
literal|0
argument|;
ifdef|#
directive|ifdef
name|WDDEBUG
argument|printf(
literal|"wd(%d,%d): wdsetctlr: C %lu H %lu S %lu\n"
argument|, 	       du->dk_ctrlr, du->dk_unit, 	       du->dk_dd.d_ncylinders, du->dk_dd.d_ntracks, 	       du->dk_dd.d_nsectors);
endif|#
directive|endif
argument|if (!(du->dk_flags& DKFL_LBA)) { 		if (du->dk_dd.d_ntracks ==
literal|0
argument||| du->dk_dd.d_ntracks>
literal|16
argument|) { 			struct wdparams *wp; 	 			printf(
literal|"wd%d: can't handle %lu heads from partition table "
argument|, 		       	du->dk_lunit, du->dk_dd.d_ntracks);
comment|/* obtain parameters */
argument|wp =&du->dk_params; 			if (wp->wdp_heads>
literal|0
argument|&& wp->wdp_heads<=
literal|16
argument|) { 				printf(
literal|"(controller value %u restored)\n"
argument|, 					wp->wdp_heads); 				du->dk_dd.d_ntracks = wp->wdp_heads; 			} 			else { 				printf(
literal|"(truncating to 16)\n"
argument|); 				du->dk_dd.d_ntracks =
literal|16
argument|; 			} 		} 	 		if (du->dk_dd.d_nsectors ==
literal|0
argument||| du->dk_dd.d_nsectors>
literal|255
argument|) { 			printf(
literal|"wd%d: cannot handle %lu sectors (max 255)\n"
argument|, 		       	du->dk_lunit, du->dk_dd.d_nsectors); 			error =
literal|1
argument|; 		} 		if (error) { 			wdtab[du->dk_ctrlr_cmd640].b_errcnt += RETRIES; 			return (
literal|1
argument|); 		} 		if (wdcommand(du, du->dk_dd.d_ncylinders, 						      du->dk_dd.d_ntracks -
literal|1
argument|,
literal|0
argument|, 		      	      du->dk_dd.d_nsectors, WDCC_IDC) !=
literal|0
argument||| wdwait(du, WDCS_READY, TIMEOUT)<
literal|0
argument|) { 			wderror((struct buf *)NULL, du,
literal|"wdsetctlr failed"
argument|); 			return (
literal|1
argument|); 		} 	}  	wdsetmulti(du);
ifdef|#
directive|ifdef
name|NOTYET
comment|/* set read caching and write caching */
argument|wdcommand(du,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|, WDFEA_RCACHE, WDCC_FEATURES); 	wdwait(du, WDCS_READY, TIMEOUT);  	wdcommand(du,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|, WDFEA_WCACHE, WDCC_FEATURES); 	wdwait(du, WDCS_READY, TIMEOUT);
endif|#
directive|endif
argument|return (
literal|0
argument|); }
if|#
directive|if
literal|0
comment|/*  * Wait until driver is inactive, then set up controller.  */
argument|static int wdwsetctlr(struct disk *du) { 	int	stat; 	int	x;  	wdsleep(du->dk_ctrlr, "wdwset"); 	x = splbio(); 	stat = wdsetctlr(du); 	wdflushirq(du, x); 	splx(x); 	return (stat); }
endif|#
directive|endif
comment|/*  * gross little callback function for wdddma interface. returns 1 for  * success, 0 for failure.  */
argument|static int wdsetmode(int mode, void *wdinfo) {     int i;     struct disk *du;      du = wdinfo;     if (bootverbose) 	printf(
literal|"wd%d: wdsetmode() setting transfer mode to %02x\n"
argument|,  	       du->dk_lunit, mode);     i = wdcommand(du,
literal|0
argument|,
literal|0
argument|, mode, WDFEA_SETXFER,  		  WDCC_FEATURES) ==
literal|0
argument|&& 	wdwait(du, WDCS_READY, TIMEOUT) ==
literal|0
argument|;     return i; }
comment|/*  * issue READP to drive to ask it what it is.  */
argument|static int wdgetctlr(struct disk *du) { 	int	i; 	char    tb[DEV_BSIZE]
argument_list|,
argument|tb2[DEV_BSIZE]; 	struct wdparams *wp = NULL; 	u_long flags = du->cfg_flags; again: 	if (wdcommand(du,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|, WDCC_READP) !=
literal|0
argument||| wdwait(du, WDCS_READY | WDCS_SEEKCMPLT | WDCS_DRQ, TIMEOUT) !=
literal|0
argument|) {
comment|/* 		 * if we failed on the second try, assume non-32bit 		 */
argument|if( du->dk_flags& DKFL_32BIT) 			goto failed;
comment|/* XXX need to check error status after final transfer. */
comment|/* 		 * Old drives don't support WDCC_READP.  Try a seek to 0. 		 * Some IDE controllers return trash if there is no drive 		 * attached, so first test that the drive can be selected. 		 * This also avoids long waits for nonexistent drives. 		 */
argument|if (wdwait(du,
literal|0
argument|, TIMEOUT)<
literal|0
argument|) 			return (
literal|1
argument|); 		outb(du->dk_port + wd_sdh, WDSD_IBM | (du->dk_unit<<
literal|4
argument|)); 		DELAY(
literal|5000
argument|);
comment|/* usually unnecessary; drive select is fast */
comment|/* 		 * Do this twice: may get a false WDCS_READY the first time. 		 */
argument|inb(du->dk_port + wd_status); 		if ((inb(du->dk_port + wd_status)& (WDCS_BUSY | WDCS_READY)) 		    != WDCS_READY 		    || wdcommand(du,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|, WDCC_RESTORE | WD_STEP) !=
literal|0
argument||| wdwait(du, WDCS_READY | WDCS_SEEKCMPLT, TIMEOUT) !=
literal|0
argument|) 			return (
literal|1
argument|);  		if (du->dk_unit == bootinfo.bi_n_bios_used) { 			du->dk_dd.d_secsize = DEV_BSIZE; 			du->dk_dd.d_nsectors = 			    bootinfo.bi_bios_geom[du->dk_unit]&
literal|0xff
argument|; 			du->dk_dd.d_ntracks = 			    ((bootinfo.bi_bios_geom[du->dk_unit]>>
literal|8
argument|)&
literal|0xff
argument|) 			    +
literal|1
argument|;
comment|/* XXX Why 2 ? */
argument|du->dk_dd.d_ncylinders = 			    (bootinfo.bi_bios_geom[du->dk_unit]>>
literal|16
argument|) +
literal|2
argument|; 			du->dk_dd.d_secpercyl = 			    du->dk_dd.d_ntracks * du->dk_dd.d_nsectors; 			du->dk_dd.d_secperunit = 			    du->dk_dd.d_secpercyl * du->dk_dd.d_ncylinders;
if|#
directive|if
literal|0
argument|du->dk_dd.d_partitions[WDRAW].p_size = 				du->dk_dd.d_secperunit; 			du->dk_dd.d_type = DTYPE_ST506; 			du->dk_dd.d_subtype |= DSTYPE_GEOMETRY; 			strncpy(du->dk_dd.d_typename, "Bios geometry", 				sizeof du->dk_dd.d_typename); 			strncpy(du->dk_params.wdp_model, "ST506", 				sizeof du->dk_params.wdp_model);
endif|#
directive|endif
argument|bootinfo.bi_n_bios_used ++; 			return
literal|0
argument|; 		}
comment|/* 		 * Fake minimal drive geometry for reading the MBR. 		 * readdisklabel() may enlarge it to read the label and the 		 * bad sector table. 		 */
argument|du->dk_dd.d_secsize = DEV_BSIZE; 		du->dk_dd.d_nsectors =
literal|17
argument|; 		du->dk_dd.d_ntracks =
literal|1
argument|; 		du->dk_dd.d_ncylinders =
literal|1
argument|; 		du->dk_dd.d_secpercyl =
literal|17
argument|; 		du->dk_dd.d_secperunit =
literal|17
argument|;
if|#
directive|if
literal|0
comment|/* 		 * Fake maximal drive size for writing the label. 		 */
argument|du->dk_dd.d_partitions[RAW_PART].p_size = 64 * 16 * 1024;
comment|/* 		 * Fake some more of the label for printing by disklabel(1) 		 * in case there is no real label. 		 */
argument|du->dk_dd.d_type = DTYPE_ST506; 		du->dk_dd.d_subtype |= DSTYPE_GEOMETRY; 		strncpy(du->dk_dd.d_typename, "Fake geometry", 			sizeof du->dk_dd.d_typename);
endif|#
directive|endif
comment|/* Fake the model name for printing by wdattach(). */
argument|strncpy(du->dk_params.wdp_model,
literal|"unknown"
argument|, 			sizeof du->dk_params.wdp_model);  		return (
literal|0
argument|); 	}
comment|/* obtain parameters */
argument|wp =&du->dk_params; 	if (du->dk_flags& DKFL_32BIT) 		insl(du->dk_port + wd_data, tb, sizeof(tb) / sizeof(long)); 	else 		insw(du->dk_port + wd_data, tb, sizeof(tb) / sizeof(short));
comment|/* try 32-bit data path (VLB IDE controller) */
argument|if (flags& WDOPT_32BIT) { 		if (! (du->dk_flags& DKFL_32BIT)) { 			bcopy(tb, tb2, sizeof(struct wdparams)); 			du->dk_flags |= DKFL_32BIT; 			goto again; 		}
comment|/* check that we really have 32-bit controller */
argument|if (bcmp (tb, tb2, sizeof(struct wdparams)) !=
literal|0
argument|) { failed:
comment|/* test failed, use 16-bit i/o mode */
argument|bcopy(tb2, tb, sizeof(struct wdparams)); 			du->dk_flags&= ~DKFL_32BIT; 		} 	}  	bcopy(tb, wp, sizeof(struct wdparams));
comment|/* shuffle string byte order */
argument|for (i =
literal|0
argument|; (unsigned)i< sizeof(wp->wdp_model); i +=
literal|2
argument|) { 		u_short *p;  		p = (u_short *) (wp->wdp_model + i); 		*p = ntohs(*p); 	}
comment|/* 	 * Clean up the wdp_model by converting nulls to spaces, and 	 * then removing the trailing spaces. 	 */
argument|for (i =
literal|0
argument|; (unsigned)i< sizeof(wp->wdp_model); i++) { 		if (wp->wdp_model[i] ==
literal|'\0'
argument|) { 			wp->wdp_model[i] =
literal|' '
argument|; 		} 	} 	for (i = sizeof(wp->wdp_model) -
literal|1
argument|; 	    (i>=
literal|0
argument|&& wp->wdp_model[i] ==
literal|' '
argument|); i--) { 		wp->wdp_model[i] =
literal|'\0'
argument|; 	}
comment|/* 	 * find out the drives maximum multi-block transfer capability 	 */
argument|du->dk_multi = wp->wdp_nsecperint&
literal|0xff
argument|; 	wdsetmulti(du);
comment|/* 	 * check drive's DMA capability 	 */
argument|if (wddma[du->dk_interface].wdd_candma) { 		du->dk_dmacookie = wddma[du->dk_interface].wdd_candma( 		    du->dk_port, du->dk_ctrlr, du->dk_unit);
comment|/* does user want this? */
argument|if ((du->cfg_flags& WDOPT_DMA)&&
comment|/* have we got a DMA controller? */
argument|du->dk_dmacookie&&
comment|/* can said drive do DMA? */
argument|wddma[du->dk_interface].wdd_dmainit(du->dk_dmacookie, wp, wdsetmode, du)) { 		    du->dk_flags |= DKFL_USEDMA; 		} 	} else { 		du->dk_dmacookie = NULL; 	}
ifdef|#
directive|ifdef
name|WDDEBUG
argument|printf(
literal|"\nwd(%d,%d): wdgetctlr: gc %x cyl %d trk %d sec %d type %d sz %d model %s\n"
argument|, 	       du->dk_ctrlr, du->dk_unit, wp->wdp_config, wp->wdp_cylinders, 	       wp->wdp_heads, wp->wdp_sectors, wp->wdp_buffertype, 	       wp->wdp_buffersize, wp->wdp_model);
endif|#
directive|endif
comment|/* update disklabel given drive information */
argument|du->dk_dd.d_secsize = DEV_BSIZE; 	if ((du->cfg_flags& WDOPT_LBA)&& wp->wdp_lbasize) { 		du->dk_dd.d_nsectors =
literal|63
argument|; 		if (wp->wdp_lbasize<
literal|16
argument|*
literal|63
argument|*
literal|1024
argument|) {
comment|/*<=528.4 MB */
argument|du->dk_dd.d_ntracks =
literal|16
argument|; 		} 		else if (wp->wdp_lbasize<
literal|32
argument|*
literal|63
argument|*
literal|1024
argument|) {
comment|/*<=1.057 GB */
argument|du->dk_dd.d_ntracks =
literal|32
argument|; 		} 		else if (wp->wdp_lbasize<
literal|64
argument|*
literal|63
argument|*
literal|1024
argument|) {
comment|/*<=2.114 GB */
argument|du->dk_dd.d_ntracks =
literal|64
argument|; 		} 		else if (wp->wdp_lbasize<
literal|128
argument|*
literal|63
argument|*
literal|1024
argument|) {
comment|/*<=4.228 GB */
argument|du->dk_dd.d_ntracks =
literal|128
argument|; 		} 		else if (wp->wdp_lbasize<
literal|255
argument|*
literal|63
argument|*
literal|1024
argument|) {
comment|/*<=8.422 GB */
argument|du->dk_dd.d_ntracks =
literal|255
argument|; 		} 		else {
comment|/*>8.422 GB */
argument|du->dk_dd.d_ntracks =
literal|255
argument|;
comment|/* XXX */
argument|} 		du->dk_dd.d_secpercyl= du->dk_dd.d_ntracks*du->dk_dd.d_nsectors; 		du->dk_dd.d_ncylinders = wp->wdp_lbasize/du->dk_dd.d_secpercyl; 		du->dk_dd.d_secperunit = wp->wdp_lbasize; 		du->dk_flags |= DKFL_LBA; 	} 	else { 		du->dk_dd.d_ncylinders = wp->wdp_cylinders;
comment|/* +- 1 */
argument|du->dk_dd.d_ntracks = wp->wdp_heads; 		du->dk_dd.d_nsectors = wp->wdp_sectors; 		du->dk_dd.d_secpercyl =  			du->dk_dd.d_ntracks * du->dk_dd.d_nsectors; 		du->dk_dd.d_secperunit =  			du->dk_dd.d_secpercyl * du->dk_dd.d_ncylinders; 		if (wp->wdp_cylinders ==
literal|16383
argument|&& 		    du->dk_dd.d_secperunit< wp->wdp_lbasize) { 			du->dk_dd.d_secperunit = wp->wdp_lbasize; 			du->dk_dd.d_ncylinders =  				du->dk_dd.d_secperunit / du->dk_dd.d_secpercyl; 		} 	} 	if (WDOPT_FORCEHD(du->cfg_flags)) { 		du->dk_dd.d_ntracks = WDOPT_FORCEHD(du->cfg_flags); 		du->dk_dd.d_secpercyl =  		    du->dk_dd.d_ntracks * du->dk_dd.d_nsectors; 		du->dk_dd.d_ncylinders = 		    du->dk_dd.d_secperunit / du->dk_dd.d_secpercyl; 	}
if|#
directive|if
literal|0
argument|du->dk_dd.d_partitions[RAW_PART].p_size = du->dk_dd.d_secperunit;
comment|/* dubious ... */
argument|bcopy("ESDI/IDE", du->dk_dd.d_typename, 9); 	bcopy(wp->wdp_model + 20, du->dk_dd.d_packname, 14 - 1);
comment|/* better ... */
argument|du->dk_dd.d_type = DTYPE_ESDI; 	du->dk_dd.d_subtype |= DSTYPE_GEOMETRY;
endif|#
directive|endif
argument|return (
literal|0
argument|); }  int wdclose(dev_t dev, int flags, int fmt, struct proc *p) { 	dsclose(dev, fmt, wddrives[dkunit(dev)]->dk_slices); 	return (
literal|0
argument|); }  int wdioctl(dev_t dev, u_long cmd, caddr_t addr, int flags, struct proc *p) { 	int	lunit = dkunit(dev); 	register struct disk *du; 	int	error;  	du = wddrives[lunit]; 	wdsleep(du->dk_ctrlr,
literal|"wdioct"
argument|); 	error = dsioctl(dev, cmd, addr, flags,&du->dk_slices); 	if (error != ENOIOCTL) 		return (error); 	switch (cmd) { 	case DIOCSBADSCAN: 		if (*(int *)addr) 			du->dk_flags |= DKFL_BADSCAN; 		else 			du->dk_flags&= ~DKFL_BADSCAN; 		return (
literal|0
argument|); 	default: 		return (ENOTTY); 	} }  int wdsize(dev_t dev) { 	struct disk *du; 	int	lunit;  	lunit = dkunit(dev); 	if (lunit>= NWD || dktype(dev) !=
literal|0
argument|) 		return (-
literal|1
argument|); 	du = wddrives[lunit]; 	if (du == NULL) 		return (-
literal|1
argument|); 	return (dssize(dev,&du->dk_slices)); }   int wddump(dev_t dev) { 	register struct disk *du; 	struct disklabel *lp; 	long	num;
comment|/* number of sectors to write */
argument|int	lunit
argument_list|,
argument|part; 	long	blkoff
argument_list|,
argument|blknum; 	long	blkchk
argument_list|,
argument|blkcnt
argument_list|,
argument|blknext; 	u_long	ds_offset; 	u_long	nblocks; 	static int wddoingadump =
literal|0
argument|; 	long	cylin
argument_list|,
argument|head
argument_list|,
argument|sector; 	long	secpertrk
argument_list|,
argument|secpercyl; 	char   *addr;
comment|/* Toss any characters present prior to dump. */
argument|while (cncheckc() != -
literal|1
argument|) 		;
comment|/* Check for acceptable device. */
comment|/* XXX should reset to maybe allow du->dk_state< OPEN. */
argument|lunit = dkunit(dev);
comment|/* eventually support floppies? */
argument|part = dkpart(dev); 	if (lunit>= NWD || (du = wddrives[lunit]) == NULL 	    || du->dk_state< OPEN 	    || (lp = dsgetlabel(dev, du->dk_slices)) == NULL) 		return (ENXIO);
comment|/* Size of memory to dump, in disk sectors. */
argument|num = (u_long)Maxmem * PAGE_SIZE / du->dk_dd.d_secsize;   	secpertrk = du->dk_dd.d_nsectors; 	secpercyl = du->dk_dd.d_secpercyl; 	nblocks = lp->d_partitions[part].p_size; 	blkoff = lp->d_partitions[part].p_offset;
comment|/* XXX */
argument|ds_offset = du->dk_slices->dss_slices[dkslice(dev)].ds_offset; 	blkoff += ds_offset;
if|#
directive|if
literal|0
argument|pg("part %x, nblocks %d, dumplo %d num %d\n", 	   part, nblocks, dumplo, num);
endif|#
directive|endif
comment|/* Check transfer bounds against partition size. */
argument|if (dumplo<
literal|0
argument||| dumplo + num> nblocks) 		return (EINVAL);
comment|/* Check if we are being called recursively. */
argument|if (wddoingadump) 		return (EFAULT);
if|#
directive|if
literal|0
comment|/* Mark controller active for if we panic during the dump. */
argument|wdtab[du->dk_ctrlr].b_active = 1;
endif|#
directive|endif
argument|wddoingadump =
literal|1
argument|;
comment|/* Recalibrate the drive. */
argument|DELAY(
literal|5
argument|);
comment|/* ATA spec XXX NOT */
argument|if (wdcommand(du,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|, WDCC_RESTORE | WD_STEP) !=
literal|0
argument||| wdwait(du, WDCS_READY | WDCS_SEEKCMPLT, TIMEOUT) !=
literal|0
argument||| wdsetctlr(du) !=
literal|0
argument|) { 		wderror((struct buf *)NULL, du,
literal|"wddump: recalibrate failed"
argument|); 		return (EIO); 	}  	du->dk_flags |= DKFL_SINGLE; 	addr = (char *)
literal|0
argument|; 	blknum = dumplo + blkoff; 	while (num>
literal|0
argument|) { 		blkcnt = num; 		if (blkcnt> MAXTRANSFER) 			blkcnt = MAXTRANSFER;
comment|/* Keep transfer within current cylinder. */
argument|if ((blknum + blkcnt -
literal|1
argument|) / secpercyl != blknum / secpercyl) 			blkcnt = secpercyl - (blknum % secpercyl); 		blknext = blknum + blkcnt;
comment|/* 		 * See if one of the sectors is in the bad sector list 		 * (if we have one).  If the first sector is bad, then 		 * reduce the transfer to this one bad sector; if another 		 * sector is bad, then reduce reduce the transfer to 		 * avoid any bad sectors. 		 */
argument|if (du->dk_flags& DKFL_SINGLE&& dsgetbad(dev, du->dk_slices) != NULL) { 		  for (blkchk = blknum; blkchk< blknum + blkcnt; blkchk++) { 			daddr_t blknew; 			blknew = transbad144(dsgetbad(dev, du->dk_slices), 					     blkchk - ds_offset) + ds_offset; 			if (blknew != blkchk) {
comment|/* Found bad block. */
argument|blkcnt = blkchk - blknum; 				if (blkcnt>
literal|0
argument|) { 					blknext = blknum + blkcnt; 					goto out; 				} 				blkcnt =
literal|1
argument|; 				blknext = blknum + blkcnt;
if|#
directive|if
literal|1
operator|||
name|defined
argument_list|(
name|WDDEBUG
argument_list|)
argument|printf(
literal|"bad block %ld -> %ld\n"
argument|, 				   (long)blknum, (long)blknew);
endif|#
directive|endif
argument|break; 			} 		    } 		} out:
comment|/* Compute disk address. */
argument|cylin = blknum / secpercyl; 		head = (blknum % secpercyl) / secpertrk; 		sector = blknum % secpertrk;
if|#
directive|if
literal|0
comment|/* Let's just talk about this first... */
argument|pg("cylin l%d head %ld sector %ld addr 0x%x count %ld", 		   cylin, head, sector, addr, blkcnt);
endif|#
directive|endif
comment|/* Do the write. */
argument|if (wdcommand(du, cylin, head, sector, blkcnt, WDCC_WRITE) 		    !=
literal|0
argument|) { 			wderror((struct buf *)NULL, du,
literal|"wddump: timeout waiting to to give command"
argument|); 			return (EIO); 		} 		while (blkcnt !=
literal|0
argument|) { 			if (is_physical_memory((vm_offset_t)addr)) 				pmap_enter(kernel_pmap, (vm_offset_t)CADDR1, 					   trunc_page((vm_offset_t)addr), VM_PROT_READ, TRUE); 			else 				pmap_enter(kernel_pmap, (vm_offset_t)CADDR1, 					   trunc_page(
literal|0
argument|), VM_PROT_READ, TRUE);
comment|/* Ready to send data? */
argument|DELAY(
literal|5
argument|);
comment|/* ATA spec */
argument|if (wdwait(du, WDCS_READY | WDCS_SEEKCMPLT | WDCS_DRQ, TIMEOUT)<
literal|0
argument|) { 				wderror((struct buf *)NULL, du,
literal|"wddump: timeout waiting for DRQ"
argument|); 				return (EIO); 			} 			if (du->dk_flags& DKFL_32BIT) 				outsl(du->dk_port + wd_data, 				      CADDR1 + ((int)addr& PAGE_MASK), 				      DEV_BSIZE / sizeof(long)); 			else 				outsw(du->dk_port + wd_data, 				      CADDR1 + ((int)addr& PAGE_MASK), 				      DEV_BSIZE / sizeof(short)); 			addr += DEV_BSIZE;
comment|/* 			 * If we are dumping core, it may take a while. 			 * So reassure the user and hold off any watchdogs. 			 */
argument|if ((unsigned)addr % (
literal|1024
argument|*
literal|1024
argument|) ==
literal|0
argument|) {
ifdef|#
directive|ifdef
name|HW_WDOG
argument|if (wdog_tickler) 					(*wdog_tickler)();
endif|#
directive|endif
comment|/* HW_WDOG */
argument|printf(
literal|"%ld "
argument|, num / (
literal|1024
argument|*
literal|1024
argument|/ DEV_BSIZE)); 			} 			num--; 			blkcnt--; 		}
comment|/* Wait for completion. */
argument|DELAY(
literal|5
argument|);
comment|/* ATA spec XXX NOT */
argument|if (wdwait(du, WDCS_READY | WDCS_SEEKCMPLT, TIMEOUT)<
literal|0
argument|) { 			wderror((struct buf *)NULL, du,
literal|"wddump: timeout waiting for status"
argument|); 			return (EIO); 		}
comment|/* Check final status. */
argument|if ((du->dk_status& (WDCS_READY | WDCS_SEEKCMPLT | WDCS_DRQ | WDCS_ERR)) 		    != (WDCS_READY | WDCS_SEEKCMPLT)) { 			wderror((struct buf *)NULL, du,
literal|"wddump: extra DRQ, or error"
argument|); 			return (EIO); 		}
comment|/* Update block count. */
argument|blknum = blknext;
comment|/* Operator aborting dump? */
argument|if (cncheckc() != -
literal|1
argument|) 			return (EINTR); 	} 	return (
literal|0
argument|); }  static void wderror(struct buf *bp, struct disk *du, char *mesg) { 	if (bp == NULL) 		printf(
literal|"wd%d: %s"
argument|, du->dk_lunit, mesg); 	else 		diskerr(bp, mesg, LOG_PRINTF, du->dk_skip, 			dsgetlabel(bp->b_dev, du->dk_slices)); 	printf(
literal|" (status %b error %b)\n"
argument|, 	       du->dk_status, WDCS_BITS, du->dk_error, WDERR_BITS); }
comment|/*  * Discard any interrupts that were latched by the interrupt system while  * we were doing polled i/o.  */
argument|static void wdflushirq(struct disk *du, int old_ipl) { 	wdtab[du->dk_ctrlr_cmd640].b_active =
literal|2
argument|; 	splx(old_ipl); 	(void)splbio(); 	wdtab[du->dk_ctrlr_cmd640].b_active =
literal|0
argument|; }
comment|/*  * Reset the controller.  */
argument|static int wdreset(struct disk *du) { 	int     err =
literal|0
argument|;  	if ((du->dk_flags& (DKFL_DMA|DKFL_SINGLE)) == DKFL_DMA) 		wddma[du->dk_interface].wdd_dmadone(du->dk_dmacookie); 	(void)wdwait(du,
literal|0
argument|, TIMEOUT); 	outb(du->dk_altport, WDCTL_IDS | WDCTL_RST); 	DELAY(
literal|10
argument|*
literal|1000
argument|); 	outb(du->dk_altport, WDCTL_IDS); 	outb(du->dk_port + wd_sdh, WDSD_IBM | (du->dk_unit<<
literal|4
argument|)); 	if (wdwait(du,
literal|0
argument|, TIMEOUT) !=
literal|0
argument|) 		err =
literal|1
argument|;
comment|/* no IDE drive found */
argument|du->dk_error = inb(du->dk_port + wd_error); 	if (du->dk_error !=
literal|0x01
argument|) 		err =
literal|1
argument|;
comment|/* the drive is incompatible */
argument|outb(du->dk_altport, WDCTL_4BIT); 	return (err); }
comment|/*  * Sleep until driver is inactive.  * This is used only for avoiding rare race conditions, so it is unimportant  * that the sleep may be far too short or too long.  */
argument|static void wdsleep(int ctrlr, char *wmesg) { 	int s = splbio(); 	if (eide_quirks& Q_CMD640B) 		ctrlr = PRIMARY; 	while (wdtab[ctrlr].b_active) 		tsleep((caddr_t)&wdtab[ctrlr].b_active, PZERO -
literal|1
argument|, wmesg,
literal|1
argument|); 	splx(s); }  static void wdtimeout(void *cdu) { 	struct disk *du; 	int	x; 	static	int	timeouts;  	du = (struct disk *)cdu; 	x = splbio(); 	if (du->dk_timeout !=
literal|0
argument|&& --du->dk_timeout ==
literal|0
argument|) { 		if(timeouts++<=
literal|5
argument|) { 			char *msg;  			msg = (timeouts>
literal|5
argument|) ?
literal|"Last time I say: interrupt timeout.  Probably a portable PC."
argument|:
literal|"interrupt timeout"
argument|; 			wderror((struct buf *)NULL, du, msg); 			if (du->dk_dmacookie) 				printf(
literal|"wd%d: wdtimeout() DMA status %b\n"
argument|,  				       du->dk_lunit, 				       wddma[du->dk_interface].wdd_dmastatus(du->dk_dmacookie),  				       WDDS_BITS); 		} 		wdunwedge(du); 		wdflushirq(du, x); 		du->dk_skip =
literal|0
argument|; 		du->dk_flags |= DKFL_SINGLE; 		wdstart(du->dk_ctrlr); 	} 	timeout(wdtimeout, cdu, hz); 	splx(x); }
comment|/*  * Reset the controller after it has become wedged.  This is different from  * wdreset() so that wdreset() can be used in the probe and so that this  * can restore the geometry .  */
argument|static int wdunwedge(struct disk *du) { 	struct disk *du1; 	int	lunit;
comment|/* Schedule other drives for recalibration. */
argument|for (lunit =
literal|0
argument|; lunit< NWD; lunit++) 		if ((du1 = wddrives[lunit]) != NULL&& du1 != du&& du1->dk_ctrlr == du->dk_ctrlr&& du1->dk_state> WANTOPEN) 			du1->dk_state = WANTOPEN;  	DELAY(RECOVERYTIME); 	if (wdreset(du) ==
literal|0
argument|) {
comment|/* 		 * XXX - recalibrate current drive now because some callers 		 * aren't prepared to have its state change. 		 */
argument|if (wdcommand(du,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|, WDCC_RESTORE | WD_STEP) ==
literal|0
argument|&& wdwait(du, WDCS_READY | WDCS_SEEKCMPLT, TIMEOUT) ==
literal|0
argument|&& wdsetctlr(du) ==
literal|0
argument|) 			return (
literal|0
argument|); 	} 	wderror((struct buf *)NULL, du,
literal|"wdunwedge failed"
argument|); 	return (
literal|1
argument|); }
comment|/*  * Wait uninterruptibly until controller is not busy and either certain  * status bits are set or an error has occurred.  * The wait is usually short unless it is for the controller to process  * an entire critical command.  * Return 1 for (possibly stale) controller errors, -1 for timeout errors,  * or 0 for no errors.  * Return controller status in du->dk_status and, if there was a controller  * error, return the error code in du->dk_error.  */
ifdef|#
directive|ifdef
name|WD_COUNT_RETRIES
argument|static int min_retries[NWDC];
endif|#
directive|endif
argument|static int wdwait(struct disk *du, u_char bits_wanted, int timeout) { 	int	wdc; 	u_char	status;
define|#
directive|define
name|POLLING
value|1000
argument|wdc = du->dk_port; 	timeout += POLLING;
comment|/*  * This delay is really too long, but does not impact the performance  * as much when using the multi-sector option.  Shorter delays have  * caused I/O errors on some drives and system configs.  This should  * probably be fixed if we develop a better short term delay mechanism.  */
argument|DELAY(
literal|1
argument|);  	do {
ifdef|#
directive|ifdef
name|WD_COUNT_RETRIES
argument|if (min_retries[du->dk_ctrlr]> timeout 		    || min_retries[du->dk_ctrlr] ==
literal|0
argument|) 			min_retries[du->dk_ctrlr] = timeout;
endif|#
directive|endif
argument|du->dk_status = status = inb(wdc + wd_status);
comment|/* 		 * Atapi drives have a very interesting feature, when attached 		 * as a slave on the IDE bus, and there is no master. 		 * They release the bus after getting the command. 		 * We should reselect the drive here to get the status. 		 */
argument|if (status ==
literal|0xff
argument|) { 			outb(wdc + wd_sdh, WDSD_IBM | du->dk_unit<<
literal|4
argument|); 			du->dk_status = status = inb(wdc + wd_status); 		} 		if (!(status& WDCS_BUSY)) { 			if (status& WDCS_ERR) { 				du->dk_error = inb(wdc + wd_error);
comment|/* 				 * We once returned here.  This is wrong 				 * because the error bit is apparently only 				 * valid after the controller has interrupted 				 * (e.g., the error bit is stale when we wait 				 * for DRQ for writes).  So we can't depend 				 * on the error bit at all when polling for 				 * command completion. 				 */
argument|} 			if ((status& bits_wanted) == bits_wanted) { 				return (status& WDCS_ERR); 			} 		} 		if (timeout< TIMEOUT)
comment|/* 			 * Switch to a polling rate of about 1 KHz so that 			 * the timeout is almost machine-independent.  The 			 * controller is taking a long time to respond, so 			 * an extra msec won't matter. 			 */
argument|DELAY(
literal|1000
argument|); 		else 			DELAY(
literal|1
argument|); 	} while (--timeout !=
literal|0
argument|); 	return (-
literal|1
argument|); }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NWDC> 0 */
end_comment

end_unit

