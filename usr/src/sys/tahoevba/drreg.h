begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)drreg.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_comment
comment|/*     ------------------------------------------     Must include<h/types.h> and<h/buf.h>     ------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|DRINTV
value|0x9c
end_define

begin_comment
comment|/* Has to match with ml/scb.s */
end_comment

begin_define
define|#
directive|define
name|DRADDMOD
value|0x01
end_define

begin_comment
comment|/* Addr modifier used to access TAHOE memory */
end_comment

begin_define
define|#
directive|define
name|DR_ZERO
value|0
end_define

begin_define
define|#
directive|define
name|DRPRI
value|(PZERO+1)
end_define

begin_define
define|#
directive|define
name|DR_TICK
value|600
end_define

begin_comment
comment|/* Default # of clock ticks between call 				   to local timer watchdog routine */
end_comment

begin_define
define|#
directive|define
name|DR_TOCK
value|2
end_define

begin_comment
comment|/* default # of calls to local watch dog 				   before an IO or wait is determined to 				   have timeout */
end_comment

begin_struct
struct|struct
name|rsdevice
block|{
name|ushort
name|dr_cstat
decl_stmt|;
comment|/* Control& status registers */
name|ushort
name|dr_data
decl_stmt|;
comment|/* Input/Ouptut data registers */
name|char
name|dr_addmod
decl_stmt|;
comment|/* Address modifier for DMA */
name|char
name|dr_intvect
decl_stmt|;
comment|/* Interrupt vector */
name|ushort
name|dr_pulse
decl_stmt|;
comment|/* Pulse command register */
name|ushort
name|dr_xx08
decl_stmt|;
comment|/* Not used */
name|ushort
name|dr_xx0A
decl_stmt|;
comment|/* Not used */
name|ushort
name|dr_xx0C
decl_stmt|;
comment|/* Not used */
name|ushort
name|dr_xx0E
decl_stmt|;
comment|/* Not used */
name|ushort
name|dr_xx10
decl_stmt|;
comment|/* Not used */
name|ushort
name|dr_walo
decl_stmt|;
comment|/* Low DMA address register --when written-- */
name|ushort
name|dr_range
decl_stmt|;
comment|/* DMA range counter */
name|ushort
name|dr_ralo
decl_stmt|;
comment|/* Low DMA address register --when read-- */
name|ushort
name|dr_xx18
decl_stmt|;
comment|/* Not used */
name|ushort
name|dr_wahi
decl_stmt|;
comment|/* High DMA address register --when written-- */
name|ushort
name|dr_xx1C
decl_stmt|;
comment|/* Not used */
name|ushort
name|dr_rahi
decl_stmt|;
comment|/* High DMA address register --when read-- */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dr_aux
block|{
name|struct
name|rsdevice
modifier|*
name|dr_addr
decl_stmt|;
comment|/* Physical addr of currently active DR11 */
name|struct
name|buf
modifier|*
name|dr_actf
decl_stmt|;
comment|/* Pointers to DR11's active buffers list */
name|unsigned
name|int
name|dr_flags
decl_stmt|;
comment|/* State: Hold open, active,... */
name|ushort
name|dr_cmd
decl_stmt|;
comment|/* Hold cmd placed here by ioctl 				   for later execution by rsstrategy() */
name|ushort
name|dr_op
decl_stmt|;
comment|/* Current operation: DR_READ/DR_WRITE */
name|long
name|dr_bycnt
decl_stmt|;
comment|/* Total byte cnt of current operation */
comment|/* decremented by completion interrupt */
name|caddr_t
name|dr_oba
decl_stmt|;
comment|/* original xfer addr, count */
name|long
name|dr_obc
decl_stmt|;
name|unsigned
name|long
name|rtimoticks
decl_stmt|,
comment|/* No of ticks before timing out on no stall 				   read */
name|wtimoticks
decl_stmt|,
comment|/* No of ticks before timing out on no stall 				   write */
name|currenttimo
decl_stmt|;
comment|/* the number of current timeout call to 				   omrwtimo() */
name|ushort
name|dr_istat
decl_stmt|;
comment|/* Latest interrupt status */
name|struct
name|buf
name|dr_buf
decl_stmt|;
comment|/*ushort dr_time;		/* # of ticks until timeout */
comment|/*ushort dr_tock;		/* # of ticks accumulated */
comment|/*ushort dr_cseq;		/* Current sequence number */
comment|/*ushort dr_lseq;		/* Last sequence number */
block|}
struct|;
end_struct

begin_comment
comment|/*	Command used by drioctl()  */
end_comment

begin_struct
struct|struct
name|dr11io
block|{
name|ushort
name|arg
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RSADDR
parameter_list|(
name|unit
parameter_list|)
value|((struct rsdevice *)drinfo[unit]->ui_addr)
end_define

begin_comment
comment|/*	Control register bits */
end_comment

begin_define
define|#
directive|define
name|RDMA
value|0x8000
end_define

begin_comment
comment|/* reset DMA end-of-range flag */
end_comment

begin_define
define|#
directive|define
name|RATN
value|0x4000
end_define

begin_comment
comment|/* reset attention flag */
end_comment

begin_define
define|#
directive|define
name|RPER
value|0x2000
end_define

begin_comment
comment|/* reset device parity error flag */
end_comment

begin_define
define|#
directive|define
name|MCLR
value|0x1000
end_define

begin_comment
comment|/* master clear board and INT device */
end_comment

begin_define
define|#
directive|define
name|CYCL
value|0x0100
end_define

begin_comment
comment|/* forces DMA cycle if DMA enabled */
end_comment

begin_define
define|#
directive|define
name|IENB
value|0x0040
end_define

begin_comment
comment|/* enables interrupt */
end_comment

begin_define
define|#
directive|define
name|FCN3
value|0x0008
end_define

begin_comment
comment|/* func. bit 3 to device (FNCT3 H) */
end_comment

begin_define
define|#
directive|define
name|FCN2
value|0x0004
end_define

begin_comment
comment|/* func. bit 2 to device (FNCT2 H) */
end_comment

begin_comment
comment|/* also asserts ACLO FCNT2 H to device */
end_comment

begin_define
define|#
directive|define
name|FCN1
value|0x0002
end_define

begin_comment
comment|/* func. bit 1 to device (FNCT1 H) */
end_comment

begin_define
define|#
directive|define
name|GO
value|0x0001
end_define

begin_comment
comment|/* enable DMA and pulse GO to device */
end_comment

begin_comment
comment|/*	Status register bits */
end_comment

begin_define
define|#
directive|define
name|DMAF
value|0x8000
end_define

begin_comment
comment|/* indicates DMA end-of-range */
end_comment

begin_define
define|#
directive|define
name|ATTF
value|0x4000
end_define

begin_comment
comment|/* indicates attention false-to-true */
end_comment

begin_define
define|#
directive|define
name|ATTN
value|0x2000
end_define

begin_comment
comment|/* current state of ATTENTION H input */
end_comment

begin_define
define|#
directive|define
name|PERR
value|0x1000
end_define

begin_comment
comment|/* Set by external parity error */
end_comment

begin_define
define|#
directive|define
name|STTA
value|0x0800
end_define

begin_comment
comment|/* STATUS A H input state */
end_comment

begin_define
define|#
directive|define
name|STTB
value|0x0400
end_define

begin_comment
comment|/* STATUS B H input state */
end_comment

begin_define
define|#
directive|define
name|STTC
value|0x0200
end_define

begin_comment
comment|/* STATUS C H input state */
end_comment

begin_define
define|#
directive|define
name|REDY
value|0x0080
end_define

begin_comment
comment|/* board ready for cmd (dma not on) */
end_comment

begin_define
define|#
directive|define
name|IENF
value|0x0040
end_define

begin_comment
comment|/* Interrupt enabled if on */
end_comment

begin_define
define|#
directive|define
name|BERR
value|0x0020
end_define

begin_comment
comment|/* Set if bus error during DMA */
end_comment

begin_define
define|#
directive|define
name|TERR
value|0x0010
end_define

begin_comment
comment|/* Set if bus timeout during DMA */
end_comment

begin_define
define|#
directive|define
name|FC3S
value|0x0008
end_define

begin_comment
comment|/* State of FCN3 latch */
end_comment

begin_define
define|#
directive|define
name|FC2S
value|0x0004
end_define

begin_comment
comment|/* State of FCN2 latch */
end_comment

begin_define
define|#
directive|define
name|FC1S
value|0x0002
end_define

begin_comment
comment|/* State of FCN1 latch */
end_comment

begin_define
define|#
directive|define
name|DLFG
value|0x0001
end_define

begin_comment
comment|/* 0 -> IKON-10083 *** 1 -> IKON-10077 */
end_comment

begin_comment
comment|/*	Pulse command register bits */
end_comment

begin_define
define|#
directive|define
name|SMSK
value|0x0040
end_define

begin_comment
comment|/* pulse interrupt mask on:  Set IENB */
end_comment

begin_define
define|#
directive|define
name|RMSK
value|0x0020
end_define

begin_comment
comment|/* pulse interrupt mask off: Reset IENB */
end_comment

begin_comment
comment|/*	  * 	DR11 driver's internal flags -- to be stored in dr_flags  */
end_comment

begin_define
define|#
directive|define
name|DR_FMSK
value|0x0000E
end_define

begin_comment
comment|/* function bits mask */
end_comment

begin_define
define|#
directive|define
name|DR_OPEN
value|0x00001
end_define

begin_comment
comment|/* This dr11 has been opened */
end_comment

begin_define
define|#
directive|define
name|DR_PRES
value|0x00002
end_define

begin_comment
comment|/* This dr11 is present */
end_comment

begin_define
define|#
directive|define
name|DR_ACTV
value|0x00004
end_define

begin_comment
comment|/* waiting for end-of-range */
end_comment

begin_define
define|#
directive|define
name|DR_ATWT
value|0x00008
end_define

begin_comment
comment|/* waiting for attention interrupt */
end_comment

begin_define
define|#
directive|define
name|DR_ATRX
value|0x00010
end_define

begin_comment
comment|/* attn received-resets when read */
end_comment

begin_define
define|#
directive|define
name|DR_TMDM
value|0x00020
end_define

begin_comment
comment|/* timeout waiting for end-of-range */
end_comment

begin_define
define|#
directive|define
name|DR_TMAT
value|0x00040
end_define

begin_comment
comment|/* timeout waiting for attention */
end_comment

begin_define
define|#
directive|define
name|DR_DMAX
value|0x00080
end_define

begin_comment
comment|/* end-of-range interrupt received */
end_comment

begin_define
define|#
directive|define
name|DR_PCYL
value|0x00100
end_define

begin_comment
comment|/* set cycle with next go */
end_comment

begin_define
define|#
directive|define
name|DR_DFCN
value|0x00200
end_define

begin_comment
comment|/* donot update function bits until next  go */
end_comment

begin_define
define|#
directive|define
name|DR_DACL
value|0x00400
end_define

begin_comment
comment|/* defer alco pulse until go */
end_comment

begin_define
define|#
directive|define
name|DR_LOOPTST
value|0x02000
end_define

begin_comment
comment|/* This dr11 is in loopback test mode */
end_comment

begin_define
define|#
directive|define
name|DR_LNKMODE
value|0x04000
end_define

begin_comment
comment|/* This dr11 is in link mode */
end_comment

begin_define
define|#
directive|define
name|DR_NORSTALL
value|0x10000
end_define

begin_comment
comment|/* Device is set to no stall mode for reads. */
end_comment

begin_define
define|#
directive|define
name|DR_NOWSTALL
value|0x20000
end_define

begin_comment
comment|/* Device is set to no stall mode for writes. */
end_comment

begin_define
define|#
directive|define
name|DR_TIMEDOUT
value|0x40000
end_define

begin_comment
comment|/* The device timed out on a stall mode R/W */
end_comment

begin_comment
comment|/*	  * 	DR11 driver's internal flags -- to be stored in dr_op  */
end_comment

begin_define
define|#
directive|define
name|DR_READ
value|FCN1
end_define

begin_define
define|#
directive|define
name|DR_WRITE
value|0
end_define

begin_comment
comment|/*  *	Ioctl commands */
end_comment

begin_define
define|#
directive|define
name|DRWAIT
value|_IOWR('d',1,long)
end_define

begin_define
define|#
directive|define
name|DRPIOW
value|_IOWR('d',2,long)
end_define

begin_define
define|#
directive|define
name|DRPACL
value|_IOWR('d',3,long)
end_define

begin_define
define|#
directive|define
name|DRDACL
value|_IOWR('d',4,long)
end_define

begin_define
define|#
directive|define
name|DRPCYL
value|_IOWR('d',5,long)
end_define

begin_define
define|#
directive|define
name|DRDFCN
value|_IOWR('d',6,long)
end_define

begin_define
define|#
directive|define
name|DRRPER
value|_IOWR('d',7,long)
end_define

begin_define
define|#
directive|define
name|DRRATN
value|_IOWR('d',8,long)
end_define

begin_define
define|#
directive|define
name|DRRDMA
value|_IOWR('d',9,long)
end_define

begin_define
define|#
directive|define
name|DRSFCN
value|_IOWR('d',10,long)
end_define

begin_define
define|#
directive|define
name|DRSETRSTALL
value|_IOWR('d',13,long)
end_define

begin_define
define|#
directive|define
name|DRSETNORSTALL
value|_IOWR('d',14,long)
end_define

begin_define
define|#
directive|define
name|DRGETRSTALL
value|_IOWR('d',15,long)
end_define

begin_define
define|#
directive|define
name|DRSETRTIMEOUT
value|_IOWR('d',16,long)
end_define

begin_define
define|#
directive|define
name|DRGETRTIMEOUT
value|_IOWR('d',17,long)
end_define

begin_define
define|#
directive|define
name|DRSETWSTALL
value|_IOWR('d',18,long)
end_define

begin_define
define|#
directive|define
name|DRSETNOWSTALL
value|_IOWR('d',19,long)
end_define

begin_define
define|#
directive|define
name|DRGETWSTALL
value|_IOWR('d',20,long)
end_define

begin_define
define|#
directive|define
name|DRSETWTIMEOUT
value|_IOWR('d',21,long)
end_define

begin_define
define|#
directive|define
name|DRGETWTIMEOUT
value|_IOWR('d',22,long)
end_define

begin_define
define|#
directive|define
name|DRWRITEREADY
value|_IOWR('d',23,long)
end_define

begin_define
define|#
directive|define
name|DRREADREADY
value|_IOWR('d',24,long)
end_define

begin_define
define|#
directive|define
name|DRBUSY
value|_IOWR('d',25,long)
end_define

begin_define
define|#
directive|define
name|DRRESET
value|_IOWR('d',26,long)
end_define

begin_comment
comment|/* The block size for buffering and DMA transfers. */
end_comment

begin_comment
comment|/* OM_BLOCKSIZE must be even and<= 32768. Multiples of 512 are prefered. */
end_comment

begin_define
define|#
directive|define
name|OM_BLOCKSIZE
value|32768
end_define

begin_comment
comment|/* --- Define ioctl call used by dr11 utility device --  */
end_comment

begin_define
define|#
directive|define
name|DR11STAT
value|_IOWR('d',30,struct dr11io)
end_define

begin_comment
comment|/* Get status dr11, unit  						   number is dr11io.arg[0] */
end_comment

begin_define
define|#
directive|define
name|DR11LOOP
value|_IOR('d',31,struct dr11io)
end_define

begin_comment
comment|/* Perform loopback test */
end_comment

begin_comment
comment|/* ---------------------------------------------------- */
end_comment

end_unit

