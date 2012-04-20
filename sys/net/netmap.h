begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011 Matteo Landi, Luigi Rizzo. All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *   *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the  *      distribution.  *   *   3. Neither the name of the authors nor the names of their contributors  *      may be used to endorse or promote products derived from this  *      software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY MATTEO LANDI AND CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MATTEO LANDI OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  * $Id: netmap.h 10601 2012-02-21 16:40:14Z luigi $  *  * Definitions of constants and the structures used by the netmap  * framework, for the part visible to both kernel and userspace.  * Detailed info on netmap is available with "man netmap" or at  *   *	http://info.iet.unipi.it/~luigi/netmap/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_NETMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_NETMAP_H_
end_define

begin_comment
comment|/*  * --- Netmap data structures ---  *  * The data structures used by netmap are shown below. Those in  * capital letters are in an mmapp()ed area shared with userspace,  * while others are private to the kernel.  * Shared structures do not contain pointers but only memory  * offsets, so that addressing is portable between kernel and userspace.    softc +----------------+ | standard fields| | if_pspare[0] ----------+ +----------------+       |                          | +----------------+<------+ |(netmap_adapter)| |                |                             netmap_kring | tx_rings *--------------------------------->+---------------+ |                |       netmap_kring         | ring    *---------. | rx_rings *--------->+---------------+       | nr_hwcur      |   | +----------------+    | ring    *--------.    | nr_hwavail    |   V                       | nr_hwcur      |  |    | selinfo       |   |                       | nr_hwavail    |  |    +---------------+   .                       | selinfo       |  |    |     ...       |   .                       +---------------+  |    |(ntx+1 entries)|                       |    ....       |  |    |               |                       |(nrx+1 entries)|  |    +---------------+                       |               |  |    KERNEL             +---------------+  |                                          |   ====================================================================                                          |    USERSPACE                             |      NETMAP_RING                                          +---->+-------------+                                              / | cur         |    NETMAP_IF  (nifp, one per file desc.)    /  | avail       |     +---------------+                      /   | buf_ofs     |     | ni_tx_rings   |                     /    +=============+     | ni_rx_rings   |                    /     | buf_idx     | slot[0]     |               |                   /      | len, flags  |     |               |                  /       +-------------+     +===============+                 /        | buf_idx     | slot[1]     | txring_ofs[0] | (rel.to nifp)--'         | len, flags  |     | txring_ofs[1] |                          +-------------+   (num_rings+1 entries)                     (nr_num_slots entries)     | txring_ofs[n] |                          | buf_idx     | slot[n-1]     +---------------+                          | len, flags  |     | rxring_ofs[0] |                          +-------------+     | rxring_ofs[1] |   (num_rings+1 entries)     | txring_ofs[n] |     +---------------+   * The private descriptor ('softc' or 'adapter') of each interface  * is extended with a "struct netmap_adapter" containing netmap-related  * info (see description in dev/netmap/netmap_kernel.h.  * Among other things, tx_rings and rx_rings point to the arrays of  * "struct netmap_kring" which in turn reache the various  * "struct netmap_ring", shared with userspace.   * The NETMAP_RING is the userspace-visible replica of the NIC ring.  * Each slot has the index of a buffer, its length and some flags.  * In user space, the buffer address is computed as  *	(char *)ring + buf_ofs + index*NETMAP_BUF_SIZE  * In the kernel, buffers do not necessarily need to be contiguous,  * and the virtual and physical addresses are derived through  * a lookup table.  * To associate a different buffer to a slot, applications must  * write the new index in buf_idx, and set NS_BUF_CHANGED flag to  * make sure that the kernel updates the hardware ring as needed.  *  * Normally the driver is not requested to report the result of  * transmissions (this can dramatically speed up operation).  * However the user may request to report completion by setting  * NS_REPORT.  */
end_comment

begin_struct
struct|struct
name|netmap_slot
block|{
name|uint32_t
name|buf_idx
decl_stmt|;
comment|/* buffer index */
name|uint16_t
name|len
decl_stmt|;
comment|/* packet length, to be copied to/from the hw ring */
name|uint16_t
name|flags
decl_stmt|;
comment|/* buf changed, etc. */
define|#
directive|define
name|NS_BUF_CHANGED
value|0x0001
comment|/* must resync the map, buffer changed */
define|#
directive|define
name|NS_REPORT
value|0x0002
comment|/* ask the hardware to report results 				 * e.g. by generating an interrupt 				 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Netmap representation of a TX or RX ring (also known as "queue").  * This is a queue implemented as a fixed-size circular array.  * At the software level, two fields are important: avail and cur.  *  * In TX rings:  *	avail	indicates the number of slots available for transmission.  *		It is updated by the kernel after every netmap system call.  *		It MUST BE decremented by the application when it appends a  *		packet.  *	cur	indicates the slot to use for the next packet  *		to send (i.e. the "tail" of the queue).  *		It MUST BE incremented by the application before  *		netmap system calls to reflect the number of newly  *		sent packets.  *		It is checked by the kernel on netmap system calls  *		(normally unmodified by the kernel unless invalid).  *  *   The kernel side of netmap uses two additional fields in its own  *   private ring structure, netmap_kring:  *	nr_hwcur is a copy of nr_cur on an NIOCTXSYNC.  *	nr_hwavail is the number of slots known as available by the  *		hardware. It is updated on an INTR (inc by the  *		number of packets sent) and on a NIOCTXSYNC  *		(decrease by nr_cur - nr_hwcur)  *		A special case, nr_hwavail is -1 if the transmit  *		side is idle (no pending transmits).  *  * In RX rings:  *	avail	is the number of packets available (possibly 0).  *		It MUST BE decremented by the application when it consumes  *		a packet, and it is updated to nr_hwavail on a NIOCRXSYNC  *	cur	indicates the first slot that contains a packet not  *		processed yet (the "head" of the queue).  *		It MUST BE incremented by the software when it consumes  *		a packet.  *	reserved	indicates the number of buffers before 'cur'  *		that the application has still in use. Normally 0,  *		it MUST BE incremented by the application when it  *		does not return the buffer immediately, and decremented  *		when the buffer is finally freed.  *  *   The kernel side of netmap uses two additional fields in the kring:  *	nr_hwcur is a copy of nr_cur on an NIOCRXSYNC  *	nr_hwavail is the number of packets available. It is updated  *		on INTR (inc by the number of new packets arrived)  *		and on NIOCRXSYNC (decreased by nr_cur - nr_hwcur).  *  * DATA OWNERSHIP/LOCKING:  *	The netmap_ring is owned by the user program and it is only  *	accessed or modified in the upper half of the kernel during  *	a system call.  *  *	The netmap_kring is only modified by the upper half of the kernel.  */
end_comment

begin_struct
struct|struct
name|netmap_ring
block|{
comment|/* 	 * nr_buf_base_ofs is meant to be used through macros. 	 * It contains the offset of the buffer region from this 	 * descriptor. 	 */
specifier|const
name|ssize_t
name|buf_ofs
decl_stmt|;
specifier|const
name|uint32_t
name|num_slots
decl_stmt|;
comment|/* number of slots in the ring. */
name|uint32_t
name|avail
decl_stmt|;
comment|/* number of usable slots */
name|uint32_t
name|cur
decl_stmt|;
comment|/* 'current' r/w position */
name|uint32_t
name|reserved
decl_stmt|;
comment|/* not refilled before current */
specifier|const
name|uint16_t
name|nr_buf_size
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|NR_TIMESTAMP
value|0x0002
comment|/* set timestamp on *sync() */
name|struct
name|timeval
name|ts
decl_stmt|;
comment|/* time of last *sync() */
comment|/* the slots follow. This struct has variable size */
name|struct
name|netmap_slot
name|slot
index|[
literal|0
index|]
decl_stmt|;
comment|/* array of slots. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Netmap representation of an interface and its queue(s).  * There is one netmap_if for each file descriptor on which we want  * to select/poll.  We assume that on each interface has the same number  * of receive and transmit queues.  * select/poll operates on one or all pairs depending on the value of  * nmr_queueid passed on the ioctl.  */
end_comment

begin_struct
struct|struct
name|netmap_if
block|{
name|char
name|ni_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* name of the interface. */
specifier|const
name|u_int
name|ni_version
decl_stmt|;
comment|/* API version, currently unused */
specifier|const
name|u_int
name|ni_rx_rings
decl_stmt|;
comment|/* number of rx rings */
specifier|const
name|u_int
name|ni_tx_rings
decl_stmt|;
comment|/* if zero, same as ni_rx_rings */
comment|/* 	 * The following array contains the offset of each netmap ring 	 * from this structure. The first ni_tx_queues+1 entries refer 	 * to the tx rings, the next ni_rx_queues+1 refer to the rx rings 	 * (the last entry in each block refers to the host stack rings). 	 * The area is filled up by the kernel on NIOCREG, 	 * and then only read by userspace code. 	 */
specifier|const
name|ssize_t
name|ring_ofs
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|NIOCREGIF
end_ifndef

begin_comment
comment|/*  * ioctl names and related fields  *  * NIOCGINFO takes a struct ifreq, the interface name is the input,  *	the outputs are number of queues and number of descriptor  *	for each queue (useful to set number of threads etc.).  *  * NIOCREGIF takes an interface name within a struct ifreq,  *	and activates netmap mode on the interface (if possible).  *  * NIOCUNREGIF unregisters the interface associated to the fd.  *  * NIOCTXSYNC, NIOCRXSYNC synchronize tx or rx queues,  *	whose identity is set in NIOCREGIF through nr_ringid  */
end_comment

begin_comment
comment|/*  * struct nmreq overlays a struct ifreq  */
end_comment

begin_struct
struct|struct
name|nmreq
block|{
name|char
name|nr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|uint32_t
name|nr_version
decl_stmt|;
comment|/* API version */
define|#
directive|define
name|NETMAP_API
value|3
comment|/* current version */
name|uint32_t
name|nr_offset
decl_stmt|;
comment|/* nifp offset in the shared region */
name|uint32_t
name|nr_memsize
decl_stmt|;
comment|/* size of the shared region */
name|uint32_t
name|nr_tx_slots
decl_stmt|;
comment|/* slots in tx rings */
name|uint32_t
name|nr_rx_slots
decl_stmt|;
comment|/* slots in rx rings */
name|uint16_t
name|nr_tx_rings
decl_stmt|;
comment|/* number of tx rings */
name|uint16_t
name|nr_rx_rings
decl_stmt|;
comment|/* number of rx rings */
name|uint16_t
name|nr_ringid
decl_stmt|;
comment|/* ring(s) we care about */
define|#
directive|define
name|NETMAP_HW_RING
value|0x4000
comment|/* low bits indicate one hw ring */
define|#
directive|define
name|NETMAP_SW_RING
value|0x2000
comment|/* process the sw ring */
define|#
directive|define
name|NETMAP_NO_TX_POLL
value|0x1000
comment|/* no automatic txsync on poll */
define|#
directive|define
name|NETMAP_RING_MASK
value|0xfff
comment|/* the ring number */
name|uint16_t
name|spare1
decl_stmt|;
name|uint32_t
name|spare2
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FreeBSD uses the size value embedded in the _IOWR to determine  * how much to copy in/out. So we need it to match the actual  * data structure we pass. We put some spares in the structure  * to ease compatibility with other versions  */
end_comment

begin_define
define|#
directive|define
name|NIOCGINFO
value|_IOWR('i', 145, struct nmreq)
end_define

begin_comment
comment|/* return IF info */
end_comment

begin_define
define|#
directive|define
name|NIOCREGIF
value|_IOWR('i', 146, struct nmreq)
end_define

begin_comment
comment|/* interface register */
end_comment

begin_define
define|#
directive|define
name|NIOCUNREGIF
value|_IO('i', 147)
end_define

begin_comment
comment|/* interface unregister */
end_comment

begin_define
define|#
directive|define
name|NIOCTXSYNC
value|_IO('i', 148)
end_define

begin_comment
comment|/* sync tx queues */
end_comment

begin_define
define|#
directive|define
name|NIOCRXSYNC
value|_IO('i', 149)
end_define

begin_comment
comment|/* sync rx queues */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NIOCREGIF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_NETMAP_H_ */
end_comment

end_unit

