begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 MICOM-Interlan, Inc., Boxborough Mass  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)npreg.h	7.2 (Berkeley) 4/8/87  *  * Merged header file for MICOM-Interlan NP100.  */
end_comment

begin_comment
comment|/*  *	np100.h version 1.3  *  *	This version retrieved: 8/18/86 @ 18:58:44  *	    This delta created: 8/18/86 @ 18:27:32  */
end_comment

begin_comment
comment|/*  * Typedefs for the VAX   */
end_comment

begin_typedef
typedef|typedef
name|short
name|sign16
typedef|;
end_typedef

begin_comment
comment|/* 16 bit signed value */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|unsign16
typedef|;
end_typedef

begin_comment
comment|/* 16 bit unsigned value */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|unsign32
typedef|;
end_typedef

begin_comment
comment|/* 32 bit unsigned value */
end_comment

begin_typedef
typedef|typedef
name|long
name|paddr_t
typedef|;
end_typedef

begin_comment
comment|/* Physical addresses */
end_comment

begin_comment
comment|/*  * Tunables  */
end_comment

begin_define
define|#
directive|define
name|NUMCQE
value|40
end_define

begin_comment
comment|/* Number of CQE's per board */
end_comment

begin_comment
comment|/* Host configuration word in Status Block */
end_comment

begin_comment
comment|/*  * To disable the lock/unlock internal function calls clear the 0x8000  * bit in the host configuration word (HOSTCONF)  */
end_comment

begin_define
define|#
directive|define
name|HOSTCONF
value|0x0109
end_define

begin_comment
comment|/* See above */
end_comment

begin_define
define|#
directive|define
name|LOWBYTE
value|1
end_define

begin_define
define|#
directive|define
name|HIGHBYTE
value|0
end_define

begin_define
define|#
directive|define
name|BUFFMAPPED
value|0
end_define

begin_comment
comment|/*  * Memory mapping definintions for PM68DUAL hardware.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PM68DUAL
end_ifdef

begin_define
define|#
directive|define
name|PISHMEM
value|0x200000
end_define

begin_define
define|#
directive|define
name|PISHMEMSIZE
value|2
end_define

begin_define
define|#
directive|define
name|PIOFF
value|0x8000
end_define

begin_comment
comment|/* change this to unique mem add. */
end_comment

begin_define
define|#
directive|define
name|PIWINDOW
value|MBUSBUFR + PIOFF
end_define

begin_define
define|#
directive|define
name|WINDOWSIZE
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NPMAXXFR
value|32768
end_define

begin_comment
comment|/* Maximum number of bytes / read */
end_comment

begin_comment
comment|/*  * Define the protocols supported by the NP Driver.  */
end_comment

begin_define
define|#
directive|define
name|NONE
value|0x00
end_define

begin_comment
comment|/* No protocols active for a process */
end_comment

begin_define
define|#
directive|define
name|NPMAINT
value|0x01
end_define

begin_comment
comment|/* Maintenance protocol, superusers only */
end_comment

begin_define
define|#
directive|define
name|NPNTS
value|0x02
end_define

begin_comment
comment|/* NTS Terminal Server */
end_comment

begin_define
define|#
directive|define
name|NPIDP
value|0x04
end_define

begin_comment
comment|/* Direct Datalink Access */
end_comment

begin_define
define|#
directive|define
name|NPDLA
value|0x04
end_define

begin_comment
comment|/* Direct Datalink Access */
end_comment

begin_define
define|#
directive|define
name|NPXNS
value|0x06
end_define

begin_comment
comment|/* Xerox NS ITP */
end_comment

begin_define
define|#
directive|define
name|NPTCP
value|0x08
end_define

begin_comment
comment|/* TCP/IP */
end_comment

begin_define
define|#
directive|define
name|NPISO
value|0x0A
end_define

begin_comment
comment|/* ISO */
end_comment

begin_define
define|#
directive|define
name|NPCLCONN
value|0xFF
end_define

begin_comment
comment|/* Closed connection, i.e. no protocol */
end_comment

begin_comment
comment|/*  * Convert the protocol to a value used in the Device Protocol Mask field  * of the Shared Memory Status Block.  */
end_comment

begin_define
define|#
directive|define
name|PROTOMASK
parameter_list|(
name|x
parameter_list|)
value|( 1<< (x) )
end_define

begin_comment
comment|/*  * Special requests handled by the NP Driver  */
end_comment

begin_define
define|#
directive|define
name|OS_STP
value|03400
end_define

begin_comment
comment|/* Shut down connection on I Board */
end_comment

begin_define
define|#
directive|define
name|NPSTOP
value|3
end_define

begin_comment
comment|/* Conversion from above (OS_STP) */
end_comment

begin_define
define|#
directive|define
name|NPCHNGP
value|50
end_define

begin_comment
comment|/* Change the protocol on a connection */
end_comment

begin_define
define|#
directive|define
name|NPCHNGB
value|51
end_define

begin_comment
comment|/* Change the Board number */
end_comment

begin_comment
comment|/*  * Miscellaneous  */
end_comment

begin_define
define|#
directive|define
name|ON
value|0x8000
end_define

begin_comment
comment|/* Used for Command Q's scan and change flag */
end_comment

begin_define
define|#
directive|define
name|UBADDRMASK
value|0x3FFFF
end_define

begin_comment
comment|/* 18 bit UNIBUS address */
end_comment

begin_define
define|#
directive|define
name|INTMASK
value|0xFFFFFFFC
end_define

begin_comment
comment|/* Used for address validation */
end_comment

begin_define
define|#
directive|define
name|CMDMASK
value|0xFFFF
end_define

begin_comment
comment|/* Mask ioctl cmd field (see ioctl.h) */
end_comment

begin_define
define|#
directive|define
name|NPPSADDR
value|0x324
end_define

begin_comment
comment|/* Pointer to addr of on-board panic string */
end_comment

begin_define
define|#
directive|define
name|PANLEN
value|133
end_define

begin_comment
comment|/* length of the panic buffer */
end_comment

begin_comment
comment|/*  * Map function code from user to I-Board format  */
end_comment

begin_define
define|#
directive|define
name|FUNCTMAP
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 6) | 077)
end_define

begin_comment
comment|/* Maps user function to NP funcs */
end_comment

begin_comment
comment|/*  * Round up to a 16 byte boundary  */
end_comment

begin_define
define|#
directive|define
name|ROUND16
parameter_list|(
name|x
parameter_list|)
value|(((x) + 15)& (~0x0F))
end_define

begin_comment
comment|/* Round to 16 byte boundary */
end_comment

begin_define
define|#
directive|define
name|ADDR24
value|1
end_define

begin_comment
comment|/* Used by iomalloc() to specify 24 bit address */
end_comment

begin_define
define|#
directive|define
name|NPERRSHIFT
value|8
end_define

begin_comment
comment|/* Used in function ReqDone() */
end_comment

begin_define
define|#
directive|define
name|NPOK
value|0
end_define

begin_define
define|#
directive|define
name|LOWORD
parameter_list|(
name|X
parameter_list|)
value|(((ushort *)&(X))[0])
end_define

begin_define
define|#
directive|define
name|HIWORD
parameter_list|(
name|X
parameter_list|)
value|(((ushort *)&(X))[1])
end_define

begin_comment
comment|/* Everyday flag settings */
end_comment

begin_define
define|#
directive|define
name|NPSET
value|1
end_define

begin_define
define|#
directive|define
name|NPCLEAR
value|0
end_define

begin_comment
comment|/*  * Command Queue Elements are the primary data structure for passing data  * between the driver and the device.  */
end_comment

begin_struct
struct|struct
name|CQE
block|{
name|struct
name|npreq
modifier|*
name|cqe_reqid
decl_stmt|;
comment|/* Address of asssociated npreq */
union|union
block|{
name|unsign32
name|cqe_Famid
decl_stmt|;
comment|/* Family ID (Process ID) - wn */
name|unsign16
name|cqe_PrtSig
index|[
literal|2
index|]
decl_stmt|;
comment|/* port and signal - tn */
block|}
name|u1
union|;
define|#
directive|define
name|cqe_famid
value|u1.cqe_Famid
define|#
directive|define
name|cqe_port
value|u1.cqe_PrtSig[0]
define|#
directive|define
name|cqe_signal
value|u1.cqe_PrtSig[1]
name|unsign16
name|cqe_func
decl_stmt|;
comment|/* I/O function to be performed */
ifdef|#
directive|ifdef
name|mc68000
name|char
name|cqe_prot
decl_stmt|;
comment|/* Protocol type for I/O request */
name|char
name|cqe_lenrpb
decl_stmt|;
comment|/* Length of the RPB in bytes */
else|#
directive|else
name|char
name|cqe_lenrpb
decl_stmt|;
comment|/* Length of the RPB in bytes */
name|char
name|cqe_prot
decl_stmt|;
comment|/* Protocol type for I/O request */
endif|#
directive|endif
union|union
block|{
name|unsign16
name|cqe_ustS
index|[
literal|2
index|]
decl_stmt|;
comment|/* Protocol status return */
name|unsign32
name|cqe_ustL
decl_stmt|;
comment|/* Protocol status return */
block|}
name|u2
union|;
define|#
directive|define
name|cqe_ust0
value|u2.cqe_ustS[0]
define|#
directive|define
name|cqe_ust1
value|u2.cqe_ustS[1]
define|#
directive|define
name|cqe_usts
value|u2.cqe_ustL
name|unsign16
name|cqe_devrsv
decl_stmt|;
comment|/* Reserved for use by device only! */
ifdef|#
directive|ifdef
name|mc68000
name|char
name|cqe_char
decl_stmt|;
comment|/* CQE characteristics */
name|char
name|cqe_sts
decl_stmt|;
comment|/* Status return from device to user */
name|char
name|cqe_wind
decl_stmt|;
comment|/* Buffer mapping window size (page units) */
name|char
name|cqe_nbuf
decl_stmt|;
comment|/* Number of data buffers for I/O */
else|#
directive|else
name|char
name|cqe_sts
decl_stmt|;
comment|/* Status return from device to user */
name|char
name|cqe_char
decl_stmt|;
comment|/* CQE characteristics */
name|char
name|cqe_nbuf
decl_stmt|;
comment|/* Number of data buffers for I/O */
name|char
name|cqe_wind
decl_stmt|;
comment|/* Buffer mapping window size (page units) */
endif|#
directive|endif
name|unsign16
name|cqe_bcnt
decl_stmt|;
comment|/* Total number of bytes in the data buffer */
union|union
block|{
name|unsign16
name|cqe_Unused
decl_stmt|;
comment|/* Unused */
struct|struct
block|{
name|char
name|cqe_Maxbcnt
decl_stmt|;
comment|/* Maximum size of buffer */
name|char
name|cqe_Bflags
decl_stmt|;
comment|/* Used by the SPI */
block|}
name|s
struct|;
block|}
name|u3
union|;
define|#
directive|define
name|cqe_unused
value|u3.cqe_Unused
define|#
directive|define
name|cqe_maxbcnt
value|u3.s.cqe_Maxbcnt
define|#
directive|define
name|cqe_bflags
value|u3.s.cqe_Bflags
name|unsign16
name|cqe_dma
index|[
literal|2
index|]
decl_stmt|;
comment|/* Address of the MULTIBUS data buffer */
name|unsign16
name|rpb1
decl_stmt|;
comment|/* Word 1 of protocol parameters */
name|unsign16
name|rpb2
decl_stmt|;
comment|/* Word 2 of protocol parameters */
name|unsign16
name|rpb3
decl_stmt|;
comment|/* Word 3 of protocol parameters */
name|unsign16
name|rpb4
decl_stmt|;
comment|/* Word 4 of protocol parameters */
name|unsign16
name|rpb5
decl_stmt|;
comment|/* Word 5 of protocol parameters */
name|unsign16
name|rpb6
decl_stmt|;
comment|/* Word 6 of protocol parameters */
name|unsign16
name|rpb7
decl_stmt|;
comment|/* Word 7 of protocol parameters */
name|unsign16
name|rpb8
decl_stmt|;
comment|/* Word 8 of protocol parameters */
name|unsign16
name|rpb9
decl_stmt|;
comment|/* Word 9 of protocol parameters */
name|unsign16
name|rpb10
decl_stmt|;
comment|/* Word 10 of protocol parameters */
name|unsign16
name|rpb11
decl_stmt|;
comment|/* Word 11 of protocol parameters */
name|unsign16
name|rpb12
decl_stmt|;
comment|/* Word 12 of protocol parameters */
block|}
struct|;
end_struct

begin_comment
comment|/*  * NP Driver Request structure contains information about a request  * maintained solely by the driver. One per CQE, plus a header.  */
end_comment

begin_struct
struct|struct
name|npreq
block|{
name|struct
name|npreq
modifier|*
name|forw
decl_stmt|;
comment|/* Forward pointer for active list */
name|struct
name|npreq
modifier|*
name|back
decl_stmt|;
comment|/* Backward pointer for active list */
name|struct
name|npreq
modifier|*
name|free
decl_stmt|;
comment|/* Next member on free list */
name|struct
name|CQE
modifier|*
name|element
decl_stmt|;
comment|/* CQE associated with this request */
name|int
name|flags
decl_stmt|;
comment|/* Always useful */
name|int
name|reqcnt
decl_stmt|;
comment|/* Request count for reqtab */
name|int
name|bufoffset
decl_stmt|;
comment|/* Offset into buffer for turns */
name|int
name|bytecnt
decl_stmt|;
comment|/* Number of bytes to transfer */
name|caddr_t
name|virtmem
decl_stmt|;
comment|/* Virtual address of buffer */
name|int
name|mapbase
decl_stmt|;
comment|/* Address of the mapping register */
name|int
name|mapsize
decl_stmt|;
comment|/* Size of mapped area */
name|caddr_t
name|bufaddr
decl_stmt|;
comment|/* Address of the user buffer */
name|struct
name|buf
name|buf
decl_stmt|;
comment|/* Buf structure needed for mem. mgmt */
name|struct
name|proc
modifier|*
name|procp
decl_stmt|;
comment|/* Pointer to process of requestor */
name|caddr_t
name|user
decl_stmt|;
comment|/* Structure passed by user from itpuser.h */
name|int
function_decl|(
modifier|*
name|intr
function_decl|)
parameter_list|()
function_decl|;
comment|/* Ptr to routine to call at interrupt time */
name|int
name|int_param
decl_stmt|;
comment|/* Paramater to be used by above routine */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Npmaster structure, one per device, is used for boardwise centralization  * of relevant information including queues, I/O addresses and request pools.  */
end_comment

begin_struct
struct|struct
name|npmaster
block|{
name|struct
name|npmaster
modifier|*
name|next
decl_stmt|;
comment|/* Linked list of these, NULL terminator */
name|struct
name|npspace
modifier|*
name|shmemp
decl_stmt|;
comment|/* Shared memory address (driver<-> device) */
name|struct
name|uba_device
modifier|*
name|devp
decl_stmt|;
comment|/* UBA Device for this unit */
name|struct
name|NPREG
modifier|*
name|iobase
decl_stmt|;
comment|/* I/O base address for this board */
name|struct
name|npreq
modifier|*
name|reqtab
decl_stmt|;
comment|/* Header for pool of CQE requests */
name|int
name|iomapbase
decl_stmt|;
comment|/* Base index of I/O map reg's allocated */
name|int
name|flags
decl_stmt|;
comment|/* State of the Board */
name|int
name|unit
decl_stmt|;
comment|/* Unit number of this device */
name|int
name|vector
decl_stmt|;
comment|/* Interrupt vector for this unit */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|NPREG
block|{
name|unsign16
name|CSR0
decl_stmt|;
comment|/* Control Status Register 0 */
name|unsign16
name|CSR1
decl_stmt|;
comment|/* Control Status Register 1 */
name|unsign16
name|CSR2
decl_stmt|;
comment|/* Control Status Register 2 */
name|unsign16
name|CSR3
decl_stmt|;
comment|/* Control Status Register 3 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structures are used for communicating with the  * Intelligent Board and are located in Shared Memory.  */
end_comment

begin_comment
comment|/*  * Status Block  */
end_comment

begin_struct
struct|struct
name|NpStat
block|{
name|unsign16
name|sb_drw
decl_stmt|;
comment|/* Device Request Word */
name|unsign16
name|sb_hcw
decl_stmt|;
comment|/* Host Configuration Word */
name|unsign16
name|sb_dcw
decl_stmt|;
comment|/* Device Configuration Word */
name|unsign16
name|sb_dpm
decl_stmt|;
comment|/* Device Protocol Mask */
name|unsign16
name|sb_dcq
decl_stmt|;
comment|/* Offset to Device CQ */
name|unsign16
name|sb_hcq
decl_stmt|;
comment|/* Offset to Host CQ */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command Queue, two per device. One is owned by the driver and the other  * is owned by the device.  */
end_comment

begin_struct
struct|struct
name|CmdQue
block|{
name|unsign16
name|scanflag
decl_stmt|;
comment|/* Scan Flag, MSB set if being scanned */
name|unsign16
name|chngflag
decl_stmt|;
comment|/* Change Flag, MSB set by initiator */
name|unsign16
name|cq_wrap
decl_stmt|;
comment|/* Offset to last CQE entry +2 */
name|unsign16
name|cq_add
decl_stmt|;
comment|/* Offset to add a CQE to the queue */
name|unsign16
name|cq_rem
decl_stmt|;
comment|/* Offset to remove a CQE from the queue */
name|unsign16
name|cq_cqe
index|[
name|NUMCQE
index|]
decl_stmt|;
comment|/* Command Queue Element Offsets */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of the shared memory area per board. Declared this way to avoid  * compiler word alignment vagaries when computing offsets.  */
end_comment

begin_struct
struct|struct
name|npspace
block|{
name|struct
name|NpStat
name|statblock
decl_stmt|;
comment|/* Status Block */
name|struct
name|CmdQue
name|devcq
decl_stmt|;
comment|/* Device's Command Queue */
name|struct
name|CmdQue
name|hostcq
decl_stmt|;
comment|/* Host's Command Queue */
name|struct
name|CQE
name|elements
index|[
name|NUMCQE
index|]
decl_stmt|;
comment|/* Shared Command Queue Elements */
name|unsign16
name|filler
index|[
literal|8
index|]
decl_stmt|;
comment|/* Here for 16 byte alignment */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of array of base addresses of I-Board controllers  * (See global data definitions in np.c)  */
end_comment

begin_struct
struct|struct
name|npbase
block|{
name|caddr_t
name|baseaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* State of the NP Driver as kept in NpState */
end_comment

begin_define
define|#
directive|define
name|ICPAVAIL
value|0x01
end_define

begin_comment
comment|/* ICP is waiting for a request */
end_comment

begin_comment
comment|/* Tells ICP Process that there are no more requests for this board */
end_comment

begin_define
define|#
directive|define
name|BRDDONE
value|1
end_define

begin_comment
comment|/* Flags used by the driver (npreq structure) to monitor status of requests */
end_comment

begin_define
define|#
directive|define
name|REQDONE
value|0x01
end_define

begin_comment
comment|/* Request completed */
end_comment

begin_define
define|#
directive|define
name|IOIFC
value|0x02
end_define

begin_comment
comment|/* Internal Function Code Request */
end_comment

begin_define
define|#
directive|define
name|IOERR
value|0x04
end_define

begin_comment
comment|/* Error on Request */
end_comment

begin_define
define|#
directive|define
name|NPPEND
value|0x08
end_define

begin_comment
comment|/* Unused at this time */
end_comment

begin_define
define|#
directive|define
name|IOABORT
value|0x10
end_define

begin_comment
comment|/* Request aborted by ICP */
end_comment

begin_define
define|#
directive|define
name|KERNREQ
value|0x20
end_define

begin_comment
comment|/* Request was from the kernel */
end_comment

begin_define
define|#
directive|define
name|WANTREQ
value|0x40
end_define

begin_comment
comment|/* Process is waiting for a npreq structure */
end_comment

begin_define
define|#
directive|define
name|NPUIO
value|0x80
end_define

begin_comment
comment|/* Process doing physio */
end_comment

begin_define
define|#
directive|define
name|REQALOC
value|0x100
end_define

begin_comment
comment|/* Request has been allocated */
end_comment

begin_define
define|#
directive|define
name|REQUSE
value|0x200
end_define

begin_comment
comment|/* Request is in request queue */
end_comment

begin_comment
comment|/* Service Request Commands from the Intelligent Board */
end_comment

begin_define
define|#
directive|define
name|NOREQ
value|0x00
end_define

begin_comment
comment|/* No service requested */
end_comment

begin_define
define|#
directive|define
name|NPLOAD
value|0x01
end_define

begin_comment
comment|/* Dump request */
end_comment

begin_define
define|#
directive|define
name|NPDUMP
value|0x02
end_define

begin_comment
comment|/* Load request */
end_comment

begin_define
define|#
directive|define
name|NPPANIC
value|0x100
end_define

begin_comment
comment|/* Panic request */
end_comment

begin_comment
comment|/* Definitions of Status returned from the I-Board */
end_comment

begin_define
define|#
directive|define
name|NPDONE
value|0x01
end_define

begin_comment
comment|/* Normal completion */
end_comment

begin_define
define|#
directive|define
name|NPIFC
value|0x00
end_define

begin_comment
comment|/* Internal Function Code request */
end_comment

begin_define
define|#
directive|define
name|NPPERR
value|0x80
end_define

begin_comment
comment|/* Protocol error */
end_comment

begin_define
define|#
directive|define
name|NPMERR
value|0x82
end_define

begin_comment
comment|/* Memory allocation failure on I-Board */
end_comment

begin_comment
comment|/* Definitions of IFC type requests from I-Board */
end_comment

begin_define
define|#
directive|define
name|NPLOCK
value|0x64
end_define

begin_comment
comment|/* Lock the process's data area */
end_comment

begin_define
define|#
directive|define
name|NPUNLOCK
value|0xA4
end_define

begin_comment
comment|/* Unlock the process */
end_comment

begin_define
define|#
directive|define
name|NPREMAP
value|0x124
end_define

begin_comment
comment|/* Window turn */
end_comment

begin_comment
comment|/* Definition of flags for the Npmaster structure */
end_comment

begin_define
define|#
directive|define
name|CSRPEND
value|0x01
end_define

begin_comment
comment|/* CSR0 command pending */
end_comment

begin_define
define|#
directive|define
name|PANICREQ
value|0x02
end_define

begin_comment
comment|/* Panic request */
end_comment

begin_define
define|#
directive|define
name|DUMPREQ
value|0x04
end_define

begin_comment
comment|/* Dump request */
end_comment

begin_define
define|#
directive|define
name|LOADREQ
value|0x08
end_define

begin_comment
comment|/* Load request */
end_comment

begin_define
define|#
directive|define
name|BOARDREQ
value|0x10
end_define

begin_comment
comment|/* Any request by the board */
end_comment

begin_define
define|#
directive|define
name|BADBOARD
value|0x20
end_define

begin_comment
comment|/* Board disabled */
end_comment

begin_define
define|#
directive|define
name|AVAILABLE
value|0x40
end_define

begin_comment
comment|/* Board available */
end_comment

begin_define
define|#
directive|define
name|BRDRESET
value|0x80
end_define

begin_comment
comment|/* Board is being reset */
end_comment

begin_define
define|#
directive|define
name|PANIC1
value|0x100
end_define

begin_comment
comment|/* Driver wants panic address */
end_comment

begin_define
define|#
directive|define
name|PANIC2
value|0x200
end_define

begin_comment
comment|/* Driver wants panic string */
end_comment

begin_define
define|#
directive|define
name|PANIC3
value|0x400
end_define

begin_comment
comment|/* Clear first byte of panic string */
end_comment

begin_define
define|#
directive|define
name|LSTCMD
value|0x800
end_define

begin_comment
comment|/* Clear last command during NPIO */
end_comment

begin_define
define|#
directive|define
name|SCANNING
value|0x1000
end_define

begin_comment
comment|/* We are scanning for cqe's */
end_comment

begin_comment
comment|/*  * Debugging Constants  */
end_comment

begin_define
define|#
directive|define
name|DEBENTRY
value|0x0001
end_define

begin_comment
comment|/* debug entry points */
end_comment

begin_define
define|#
directive|define
name|DEBMEM
value|0x0002
end_define

begin_comment
comment|/* debug memory */
end_comment

begin_define
define|#
directive|define
name|DEBREQ
value|0x0004
end_define

begin_comment
comment|/* debug requests */
end_comment

begin_define
define|#
directive|define
name|DEBCQE
value|0x0008
end_define

begin_comment
comment|/* debug cqe's */
end_comment

begin_define
define|#
directive|define
name|DEBCQ
value|0x0010
end_define

begin_comment
comment|/* debug cq's */
end_comment

begin_define
define|#
directive|define
name|DEBMAINT
value|0x0020
end_define

begin_comment
comment|/* debug maintainance requests */
end_comment

begin_define
define|#
directive|define
name|DEBINTR
value|0x0040
end_define

begin_comment
comment|/* debug interrupt routines */
end_comment

begin_define
define|#
directive|define
name|DEBINIT
value|0x0080
end_define

begin_comment
comment|/* debug initialization routines */
end_comment

begin_define
define|#
directive|define
name|DEBIFC
value|0x0100
end_define

begin_comment
comment|/* debug Internal function codes */
end_comment

begin_define
define|#
directive|define
name|DEBIOCTL
value|0x0200
end_define

begin_comment
comment|/* debug ioctl calls */
end_comment

begin_define
define|#
directive|define
name|DEBOPEN
value|0x0400
end_define

begin_comment
comment|/* debug open calls */
end_comment

begin_define
define|#
directive|define
name|DEBIO
value|0x0800
end_define

begin_comment
comment|/* debug read& write calls */
end_comment

begin_define
define|#
directive|define
name|DEBCSR
value|0x1000
end_define

begin_comment
comment|/* debug CSR commands */
end_comment

begin_define
define|#
directive|define
name|DEBLOCK
value|0x2000
end_define

begin_comment
comment|/* debug lock / unlock calls */
end_comment

begin_define
define|#
directive|define
name|NOBOARD
value|0x4000
end_define

begin_comment
comment|/* debug user/host interface */
end_comment

begin_define
define|#
directive|define
name|DEBCANCEL
value|0x8000
end_define

begin_comment
comment|/* debug cancel command */
end_comment

begin_comment
comment|/*  *	npreg.h version 1.3  *  *	This version retrieved: 8/18/86 @ 18:58:46  *	    This delta created: 8/18/86 @ 18:27:42  */
end_comment

begin_comment
comment|/*  *			NPREG.H  *  * This file contain definitions of specific hardware interest  * to be used when communicating with the NI1510 Network Processor  * Board. More complete information can be found in the NI1510  * Multibus compatible Ethernet Communications Processor Hardware   * Specification.  */
end_comment

begin_comment
comment|/*  *	npcmd.h version 1.3  *  *	This version retrieved: 8/18/86 @ 18:58:45  *	    This delta created: 8/18/86 @ 18:27:38  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IOC_VOID
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../h/ioctl.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IoVOID
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IoVOID
value|IOC_VOID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NPRESET
value|(IoVOID|0x01)
end_define

begin_comment
comment|/* reset the board */
end_comment

begin_define
define|#
directive|define
name|NPSTART
value|(IoVOID|0x04)
end_define

begin_comment
comment|/* start board execution */
end_comment

begin_define
define|#
directive|define
name|NPGPANIC
value|(IoVOID|0x05)
end_define

begin_comment
comment|/* Get panic message */
end_comment

begin_define
define|#
directive|define
name|NPINIT
value|(IoVOID|0x06)
end_define

begin_comment
comment|/* initialize software on board */
end_comment

begin_define
define|#
directive|define
name|NPSTATS
value|(IoVOID|0x07)
end_define

begin_define
define|#
directive|define
name|NPRCSR0
value|(IoVOID|0x08)
end_define

begin_comment
comment|/* read CSR0 */
end_comment

begin_define
define|#
directive|define
name|NPRCSR1
value|(IoVOID|0x09)
end_define

begin_comment
comment|/* read CSR1 */
end_comment

begin_define
define|#
directive|define
name|NPRCSR2
value|(IoVOID|0x0a)
end_define

begin_comment
comment|/* read CSR2 */
end_comment

begin_define
define|#
directive|define
name|NPRCSR3
value|(IoVOID|0x0b)
end_define

begin_comment
comment|/* read CSR3 */
end_comment

begin_define
define|#
directive|define
name|NPWCSR0
value|(IoVOID|0x0c)
end_define

begin_comment
comment|/* write CSR0 */
end_comment

begin_define
define|#
directive|define
name|NPWCSR1
value|(IoVOID|0x0d)
end_define

begin_comment
comment|/* write CSR1 */
end_comment

begin_define
define|#
directive|define
name|NPWCSR2
value|(IoVOID|0x0e)
end_define

begin_comment
comment|/* write CSR2 */
end_comment

begin_define
define|#
directive|define
name|NPWCSR3
value|(IoVOID|0x0f)
end_define

begin_comment
comment|/* write CSR3 */
end_comment

begin_define
define|#
directive|define
name|NPPOLL
value|(IoVOID|0x10)
end_define

begin_define
define|#
directive|define
name|NPKILL
value|(IoVOID|0x11)
end_define

begin_define
define|#
directive|define
name|NPSETPROT
value|(IoVOID|0x12)
end_define

begin_comment
comment|/* set the protocol to use */
end_comment

begin_define
define|#
directive|define
name|NPSETBOARD
value|(IoVOID|0x13)
end_define

begin_comment
comment|/* set board to use */
end_comment

begin_define
define|#
directive|define
name|NPSETNPDEB
value|(IoVOID|0x14)
end_define

begin_comment
comment|/* set nc debuging level */
end_comment

begin_define
define|#
directive|define
name|NPSETADDR
value|(IoVOID|0x15)
end_define

begin_comment
comment|/* set host address */
end_comment

begin_define
define|#
directive|define
name|NPNETBOOT
value|(IoVOID|0x16)
end_define

begin_comment
comment|/* boot from the network */
end_comment

begin_define
define|#
directive|define
name|NPSETLAST
value|(IoVOID|0x17)
end_define

begin_comment
comment|/* set last command flag in NPIO */
end_comment

begin_define
define|#
directive|define
name|NPCLRICNT
value|(IoVOID|0x18)
end_define

begin_comment
comment|/* clear interupt count */
end_comment

begin_define
define|#
directive|define
name|NPGETICNT
value|(IoVOID|0x19)
end_define

begin_comment
comment|/* get interupt count */
end_comment

begin_define
define|#
directive|define
name|NPGETIVEC
value|(IoVOID|0x1a)
end_define

begin_comment
comment|/* get interupt vector */
end_comment

begin_define
define|#
directive|define
name|NPMAPMEM
value|(IoVOID|0x1b)
end_define

begin_comment
comment|/* map user memory to shmem */
end_comment

begin_define
define|#
directive|define
name|NP_SET
value|1031
end_define

begin_comment
comment|/* set memory mapping */
end_comment

begin_define
define|#
directive|define
name|NP_USET
value|1032
end_define

begin_comment
comment|/* unset memory mapping */
end_comment

begin_struct
struct|struct
name|np_mem
block|{
name|long
name|mem_type
decl_stmt|;
name|char
modifier|*
name|mem_addr
decl_stmt|;
name|long
name|mem_count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NNPCNN
value|4
end_define

begin_comment
comment|/* Number of connections per board */
end_comment

begin_define
define|#
directive|define
name|NPUNIT
parameter_list|(
name|a
parameter_list|)
value|((minor(a)>> 4)& 0x0F)
end_define

begin_define
define|#
directive|define
name|NPCONN
parameter_list|(
name|a
parameter_list|)
value|((minor(a))& 0x03)
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|IBOOTADDR
value|0xF8000l
end_define

begin_comment
comment|/* Addr of 80186 Boot ROM */
end_comment

begin_define
define|#
directive|define
name|INETBOOT
value|0xF8087l
end_define

begin_define
define|#
directive|define
name|IXEQADDR
value|0x400
end_define

begin_comment
comment|/* Where to begin Board image XEQ */
end_comment

begin_define
define|#
directive|define
name|DIAGTIME
value|1200
end_define

begin_comment
comment|/* Time for timeout /HZ seconds */
end_comment

begin_define
define|#
directive|define
name|DELAYTIME
value|1000000L
end_define

begin_comment
comment|/* delay count */
end_comment

begin_define
define|#
directive|define
name|NPDELAY
parameter_list|(
name|N
parameter_list|)
value|{register int n = (N)>> 1; while(--n> 0); }
end_define

begin_comment
comment|/* Handy macros for talking to the Board */
end_comment

begin_define
define|#
directive|define
name|RESET
parameter_list|(
name|x
parameter_list|)
value|(WCSR3(x->iobase,0xff))
end_define

begin_define
define|#
directive|define
name|CLEARINT
parameter_list|(
name|x
parameter_list|)
value|{unsign16 y; y = RCSR2(x->iobase); }
end_define

begin_define
define|#
directive|define
name|INTNI
parameter_list|(
name|x
parameter_list|)
value|(WCSR1(x->iobase,0xFF))
end_define

begin_comment
comment|/* Command and Status Register (CSR) Definitions */
end_comment

begin_comment
comment|/*  * CSR0 is the only direct means for data transfer between the host processor  * and the 3510. Access is controlled by the 80186 who sets the CSR1 Enable and  * Ready bits to allow writing here. Writing to this register will always  * result in an interrupt to the 80186.  */
end_comment

begin_comment
comment|/*   * Bit definitions for CSR1.  */
end_comment

begin_define
define|#
directive|define
name|NPRFU
value|0x01
end_define

begin_comment
comment|/* Reserved for Future Use */
end_comment

begin_define
define|#
directive|define
name|NPHOK
value|0x02
end_define

begin_comment
comment|/* Hardware OK */
end_comment

begin_define
define|#
directive|define
name|NPLAN
value|0x04
end_define

begin_comment
comment|/* Logic 0 indicates operational LAN exists */
end_comment

begin_define
define|#
directive|define
name|NP_IP
value|0x08
end_define

begin_comment
comment|/* Interrupt pending from this board */
end_comment

begin_define
define|#
directive|define
name|NP_IE
value|0x10
end_define

begin_comment
comment|/* Interrupts enabled for this board */
end_comment

begin_define
define|#
directive|define
name|NPRDR
value|0x20
end_define

begin_comment
comment|/* Set when 80186 writes data into CSR0 */
end_comment

begin_define
define|#
directive|define
name|NPRDY
value|0x40
end_define

begin_comment
comment|/* CSR0 ready to accept data */
end_comment

begin_define
define|#
directive|define
name|NPENB
value|0x80
end_define

begin_comment
comment|/* CSR0 available for use by the host */
end_comment

begin_comment
comment|/*  * Bit defintions for CSR0 Command Block  */
end_comment

begin_define
define|#
directive|define
name|NPLST
value|0x20
end_define

begin_comment
comment|/* Last Command */
end_comment

begin_define
define|#
directive|define
name|NPCMD
value|0x80
end_define

begin_comment
comment|/* Shared Memory Address */
end_comment

begin_define
define|#
directive|define
name|NPBGN
value|0x200
end_define

begin_comment
comment|/* Begin Execution in On-Board Memory */
end_comment

begin_define
define|#
directive|define
name|NPCBI
value|0x800
end_define

begin_comment
comment|/* Interrupt at completion of Command Block */
end_comment

begin_define
define|#
directive|define
name|NPDMP
value|0x2000
end_define

begin_comment
comment|/* Dump 80186 On-Board Memory to Multibus */
end_comment

begin_define
define|#
directive|define
name|NPLD
value|0x8000
end_define

begin_comment
comment|/* Load 80186 On-board Memory from Multibus */
end_comment

begin_comment
comment|/*  * CSR0 Count definitions. These are the lengths of the Command Blocks for the  * CSR0 commands above (not counting the Command Word itself).  */
end_comment

begin_define
define|#
directive|define
name|LSTCNT
value|0
end_define

begin_define
define|#
directive|define
name|CMDCNT
value|2
end_define

begin_define
define|#
directive|define
name|BGNCNT
value|2
end_define

begin_define
define|#
directive|define
name|CBICNT
value|1
end_define

begin_define
define|#
directive|define
name|DMPCNT
value|5
end_define

begin_define
define|#
directive|define
name|LDCNT
value|5
end_define

begin_define
define|#
directive|define
name|IOCNT
value|5
end_define

begin_comment
comment|/* Macros for reading and writing CSR's (Control and Status Registers) */
end_comment

begin_define
define|#
directive|define
name|WCSR0
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->CSR0 = y)
end_define

begin_define
define|#
directive|define
name|WCSR1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->CSR1 = y)
end_define

begin_define
define|#
directive|define
name|WCSR2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->CSR2 = y)
end_define

begin_define
define|#
directive|define
name|WCSR3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->CSR3 = y)
end_define

begin_define
define|#
directive|define
name|RCSR0
parameter_list|(
name|x
parameter_list|)
value|((x)->CSR0)
end_define

begin_define
define|#
directive|define
name|RCSR1
parameter_list|(
name|x
parameter_list|)
value|((x)->CSR1)
end_define

begin_define
define|#
directive|define
name|RCSR2
parameter_list|(
name|x
parameter_list|)
value|((x)->CSR2)
end_define

begin_define
define|#
directive|define
name|RCSR3
parameter_list|(
name|x
parameter_list|)
value|((x)->CSR3)
end_define

begin_struct
struct|struct
name|npconn
block|{
name|struct
name|npmaster
modifier|*
name|unit
decl_stmt|;
comment|/* Unit number (board) of this connection */
name|unsign16
name|protocol
decl_stmt|;
comment|/* Protocol used on this connection */
name|struct
name|buf
name|np_wbuf
decl_stmt|;
comment|/* write buf structure for raw access */
name|struct
name|buf
name|np_rbuf
decl_stmt|;
comment|/* read buf structure for raw access */
block|}
struct|;
end_struct

begin_comment
comment|/* ICP Board Requests */
end_comment

begin_define
define|#
directive|define
name|ICPLOAD
value|0x02
end_define

begin_define
define|#
directive|define
name|ICPDUMP
value|0x03
end_define

begin_define
define|#
directive|define
name|ICPPANIC
value|0x05
end_define

begin_define
define|#
directive|define
name|ICPPOLL
value|0x10
end_define

begin_comment
comment|/*  *	npdebug.h version 1.3  *  *	This version retrieved: 8/18/86 @ 18:58:46  *	    This delta created: 8/18/86 @ 18:27:39  */
end_comment

begin_comment
comment|/*  * Debugging Constants  */
end_comment

begin_define
define|#
directive|define
name|DEBENTRY
value|0x0001
end_define

begin_comment
comment|/* debug entry points */
end_comment

begin_define
define|#
directive|define
name|DEBMEM
value|0x0002
end_define

begin_comment
comment|/* debug memory */
end_comment

begin_define
define|#
directive|define
name|DEBREQ
value|0x0004
end_define

begin_comment
comment|/* debug requests */
end_comment

begin_define
define|#
directive|define
name|DEBCQE
value|0x0008
end_define

begin_comment
comment|/* debug cqe's */
end_comment

begin_define
define|#
directive|define
name|DEBCQ
value|0x0010
end_define

begin_comment
comment|/* debug cq's */
end_comment

begin_define
define|#
directive|define
name|DEBMAINT
value|0x0020
end_define

begin_comment
comment|/* debug maintainance requests */
end_comment

begin_define
define|#
directive|define
name|DEBINTR
value|0x0040
end_define

begin_comment
comment|/* debug interrupt routines */
end_comment

begin_define
define|#
directive|define
name|DEBINIT
value|0x0080
end_define

begin_comment
comment|/* debug initialization routines */
end_comment

begin_define
define|#
directive|define
name|DEBIFC
value|0x0100
end_define

begin_comment
comment|/* debug Internal function codes */
end_comment

begin_define
define|#
directive|define
name|DEBIOCTL
value|0x0200
end_define

begin_comment
comment|/* debug ioctl calls */
end_comment

begin_define
define|#
directive|define
name|DEBOPEN
value|0x0400
end_define

begin_comment
comment|/* debug open calls */
end_comment

begin_define
define|#
directive|define
name|DEBIO
value|0x0800
end_define

begin_comment
comment|/* debug read& write calls */
end_comment

begin_define
define|#
directive|define
name|DEBCSR
value|0x1000
end_define

begin_comment
comment|/* debug CSR commands */
end_comment

begin_define
define|#
directive|define
name|DEBLOCK
value|0x2000
end_define

begin_comment
comment|/* debug lock / unlock calls */
end_comment

end_unit

