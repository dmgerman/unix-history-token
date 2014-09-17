begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011-2014 Matteo Landi, Luigi Rizzo. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``S IS''AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  *  * Definitions of constants and the structures used by the netmap  * framework, for the part visible to both kernel and userspace.  * Detailed info on netmap is available with "man netmap" or at  *  *	http://info.iet.unipi.it/~luigi/netmap/  *  * This API is also used to communicate with the VALE software switch  */
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

begin_define
define|#
directive|define
name|NETMAP_API
value|11
end_define

begin_comment
comment|/* current API version */
end_comment

begin_define
define|#
directive|define
name|NETMAP_MIN_API
value|11
end_define

begin_comment
comment|/* min and max versions accepted */
end_comment

begin_define
define|#
directive|define
name|NETMAP_MAX_API
value|15
end_define

begin_comment
comment|/*  * Some fields should be cache-aligned to reduce contention.  * The alignment is architecture and OS dependent, but rather than  * digging into OS headers to find the exact value we use an estimate  * that should cover most architectures.  */
end_comment

begin_define
define|#
directive|define
name|NM_CACHE_ALIGN
value|128
end_define

begin_comment
comment|/*  * --- Netmap data structures ---  *  * The userspace data structures used by netmap are shown below.  * They are allocated by the kernel and mmap()ed by userspace threads.  * Pointers are implemented as memory offsets or indexes,  * so that they can be easily dereferenced in kernel and userspace.     KERNEL (opaque, obviously)    ====================================================================                                          |    USERSPACE                             |      struct netmap_ring                                          +---->+---------------+                                              / | head,cur,tail |    struct netmap_if (nifp, 1 per fd)        /  | buf_ofs       |     +---------------+                      /   | other fields  |     | ni_tx_rings   |                     /    +===============+     | ni_rx_rings   |                    /     | buf_idx, len  | slot[0]     |               |                   /      | flags, ptr    |     |               |                  /       +---------------+     +===============+                 /        | buf_idx, len  | slot[1]     | txring_ofs[0] | (rel.to nifp)--'         | flags, ptr    |     | txring_ofs[1] |                          +---------------+      (tx+1 entries)                           (num_slots entries)     | txring_ofs[t] |                          | buf_idx, len  | slot[n-1]     +---------------+                          | flags, ptr    |     | rxring_ofs[0] |                          +---------------+     | rxring_ofs[1] |      (rx+1 entries)     | rxring_ofs[r] |     +---------------+   * For each "interface" (NIC, host stack, PIPE, VALE switch port) bound to  * a file descriptor, the mmap()ed region contains a (logically readonly)  * struct netmap_if pointing to struct netmap_ring's.  *  * There is one netmap_ring per physical NIC ring, plus one tx/rx ring  * pair attached to the host stack (this pair is unused for non-NIC ports).  *  * All physical/host stack ports share the same memory region,  * so that zero-copy can be implemented between them.  * VALE switch ports instead have separate memory regions.  *  * The netmap_ring is the userspace-visible replica of the NIC ring.  * Each slot has the index of a buffer (MTU-sized and residing in the  * mmapped region), its length and some flags. An extra 64-bit pointer  * is provided for user-supplied buffers in the tx path.  *  * In user space, the buffer address is computed as  *	(char *)ring + buf_ofs + index * NETMAP_BUF_SIZE  *  * Added in NETMAP_API 11:  *  * + NIOCREGIF can request the allocation of extra spare buffers from  *   the same memory pool. The desired number of buffers must be in  *   nr_arg3. The ioctl may return fewer buffers, depending on memory  *   availability. nr_arg3 will return the actual value, and, once  *   mapped, nifp->ni_bufs_head will be the index of the first buffer.  *  *   The buffers are linked to each other using the first uint32_t  *   as the index. On close, ni_bufs_head must point to the list of  *   buffers to be released.  *  * + NIOCREGIF can request space for extra rings (and buffers)  *   allocated in the same memory space. The number of extra rings  *   is in nr_arg1, and is advisory. This is a no-op on NICs where  *   the size of the memory space is fixed.  *  * + NIOCREGIF can attach to PIPE rings sharing the same memory  *   space with a parent device. The ifname indicates the parent device,  *   which must already exist. Flags in nr_flags indicate if we want to  *   bind the master or slave side, the index (from nr_ringid)  *   is just a cookie and does not need to be sequential.  *  * + NIOCREGIF can also attach to 'monitor' rings that replicate  *   the content of specific rings, also from the same memory space.  *  *   Extra flags in nr_flags support the above functions.  *   Application libraries may use the following naming scheme:  *	netmap:foo			all NIC ring pairs  *	netmap:foo^			only host ring pair  *	netmap:foo+			all NIC ring + host ring pairs  *	netmap:foo-k			the k-th NIC ring pair  *	netmap:foo{k			PIPE ring pair k, master side  *	netmap:foo}k			PIPE ring pair k, slave side  */
end_comment

begin_comment
comment|/*  * struct netmap_slot is a buffer descriptor  */
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
comment|/* length for this slot */
name|uint16_t
name|flags
decl_stmt|;
comment|/* buf changed, etc. */
name|uint64_t
name|ptr
decl_stmt|;
comment|/* pointer for indirect buffers */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following flags control how the slot is used  */
end_comment

begin_define
define|#
directive|define
name|NS_BUF_CHANGED
value|0x0001
end_define

begin_comment
comment|/* buf_idx changed */
end_comment

begin_comment
comment|/* 	 * must be set whenever buf_idx is changed (as it might be 	 * necessary to recompute the physical address and mapping) 	 */
end_comment

begin_define
define|#
directive|define
name|NS_REPORT
value|0x0002
end_define

begin_comment
comment|/* ask the hardware to report results */
end_comment

begin_comment
comment|/* 	 * Request notification when slot is used by the hardware. 	 * Normally transmit completions are handled lazily and 	 * may be unreported. This flag lets us know when a slot 	 * has been sent (e.g. to terminate the sender). 	 */
end_comment

begin_define
define|#
directive|define
name|NS_FORWARD
value|0x0004
end_define

begin_comment
comment|/* pass packet 'forward' */
end_comment

begin_comment
comment|/* 	 * (Only for physical ports, rx rings with NR_FORWARD set). 	 * Slot released to the kernel (i.e. before ring->head) with 	 * this flag set are passed to the peer ring (host/NIC), 	 * thus restoring the host-NIC connection for these slots. 	 * This supports efficient traffic monitoring or firewalling. 	 */
end_comment

begin_define
define|#
directive|define
name|NS_NO_LEARN
value|0x0008
end_define

begin_comment
comment|/* disable bridge learning */
end_comment

begin_comment
comment|/* 	 * On a VALE switch, do not 'learn' the source port for  	 * this buffer. 	 */
end_comment

begin_define
define|#
directive|define
name|NS_INDIRECT
value|0x0010
end_define

begin_comment
comment|/* userspace buffer */
end_comment

begin_comment
comment|/* 	 * (VALE tx rings only) data is in a userspace buffer, 	 * whose address is in the 'ptr' field in the slot. 	 */
end_comment

begin_define
define|#
directive|define
name|NS_MOREFRAG
value|0x0020
end_define

begin_comment
comment|/* packet has more fragments */
end_comment

begin_comment
comment|/* 	 * (VALE ports only) 	 * Set on all but the last slot of a multi-segment packet. 	 * The 'len' field refers to the individual fragment. 	 */
end_comment

begin_define
define|#
directive|define
name|NS_PORT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|NS_PORT_MASK
value|(0xff<< NS_PORT_SHIFT)
end_define

begin_comment
comment|/*  	 * The high 8 bits of the flag, if not zero, indicate the 	 * destination port for the VALE switch, overriding  	 * the lookup table.  	 */
end_comment

begin_define
define|#
directive|define
name|NS_RFRAGS
parameter_list|(
name|_slot
parameter_list|)
value|( ((_slot)->flags>> 8)& 0xff)
end_define

begin_comment
comment|/* 	 * (VALE rx rings only) the high 8 bits 	 *  are the number of fragments. 	 */
end_comment

begin_comment
comment|/*  * struct netmap_ring  *  * Netmap representation of a TX or RX ring (also known as "queue").  * This is a queue implemented as a fixed-size circular array.  * At the software level the important fields are: head, cur, tail.  *  * In TX rings:  *  *	head	first slot available for transmission.  *	cur	wakeup point. select() and poll() will unblock  *		when 'tail' moves past 'cur'  *	tail	(readonly) first slot reserved to the kernel  *  *	[head .. tail-1] can be used for new packets to send;  *	'head' and 'cur' must be incremented as slots are filled  *	    with new packets to be sent;  *	'cur' can be moved further ahead if we need more space  *	for new transmissions. XXX todo (2014-03-12)  *  * In RX rings:  *  *	head	first valid received packet  *	cur	wakeup point. select() and poll() will unblock  *		when 'tail' moves past 'cur'  *	tail	(readonly) first slot reserved to the kernel  *  *	[head .. tail-1] contain received packets;  *	'head' and 'cur' must be incremented as slots are consumed  *		and can be returned to the kernel;  *	'cur' can be moved further ahead if we want to wait for  *		new packets without returning the previous ones.  *  * DATA OWNERSHIP/LOCKING:  *	The netmap_ring, and all slots and buffers in the range  *	[head .. tail-1] are owned by the user program;  *	the kernel only accesses them during a netmap system call  *	and in the user thread context.  *  *	Other slots and buffers are reserved for use by the kernel  */
end_comment

begin_struct
struct|struct
name|netmap_ring
block|{
comment|/* 	 * buf_ofs is meant to be used through macros. 	 * It contains the offset of the buffer region from this 	 * descriptor. 	 */
specifier|const
name|int64_t
name|buf_ofs
decl_stmt|;
specifier|const
name|uint32_t
name|num_slots
decl_stmt|;
comment|/* number of slots in the ring. */
specifier|const
name|uint32_t
name|nr_buf_size
decl_stmt|;
specifier|const
name|uint16_t
name|ringid
decl_stmt|;
specifier|const
name|uint16_t
name|dir
decl_stmt|;
comment|/* 0: tx, 1: rx */
name|uint32_t
name|head
decl_stmt|;
comment|/* (u) first user slot */
name|uint32_t
name|cur
decl_stmt|;
comment|/* (u) wakeup point */
name|uint32_t
name|tail
decl_stmt|;
comment|/* (k) first kernel slot */
name|uint32_t
name|flags
decl_stmt|;
name|struct
name|timeval
name|ts
decl_stmt|;
comment|/* (k) time of last *sync() */
comment|/* opaque room for a mutex or similar object */
name|uint8_t
name|sem
index|[
literal|128
index|]
name|__attribute__
argument_list|(
operator|(
name|__aligned__
argument_list|(
name|NM_CACHE_ALIGN
argument_list|)
operator|)
argument_list|)
decl_stmt|;
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
comment|/*  * RING FLAGS  */
end_comment

begin_define
define|#
directive|define
name|NR_TIMESTAMP
value|0x0002
end_define

begin_comment
comment|/* set timestamp on *sync() */
end_comment

begin_comment
comment|/* 	 * updates the 'ts' field on each netmap syscall. This saves 	 * saves a separate gettimeofday(), and is not much worse than 	 * software timestamps generated in the interrupt handler. 	 */
end_comment

begin_define
define|#
directive|define
name|NR_FORWARD
value|0x0004
end_define

begin_comment
comment|/* enable NS_FORWARD for ring */
end_comment

begin_comment
comment|/* 	 * Enables the NS_FORWARD slot flag for the ring. 	 */
end_comment

begin_comment
comment|/*  * Netmap representation of an interface and its queue(s).  * This is initialized by the kernel when binding a file  * descriptor to a port, and should be considered as readonly  * by user programs. The kernel never uses it.  *  * There is one netmap_if for each file descriptor on which we want  * to select/poll.  * select/poll operates on one or all pairs depending on the value of  * nmr_queueid passed on the ioctl.  */
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
name|uint32_t
name|ni_version
decl_stmt|;
comment|/* API version, currently unused */
specifier|const
name|uint32_t
name|ni_flags
decl_stmt|;
comment|/* properties */
define|#
directive|define
name|NI_PRIV_MEM
value|0x1
comment|/* private memory region */
comment|/* 	 * The number of packet rings available in netmap mode. 	 * Physical NICs can have different numbers of tx and rx rings. 	 * Physical NICs also have a 'host' ring pair. 	 * Additionally, clients can request additional ring pairs to 	 * be used for internal communication. 	 */
specifier|const
name|uint32_t
name|ni_tx_rings
decl_stmt|;
comment|/* number of HW tx rings */
specifier|const
name|uint32_t
name|ni_rx_rings
decl_stmt|;
comment|/* number of HW rx rings */
name|uint32_t
name|ni_bufs_head
decl_stmt|;
comment|/* head index for extra bufs */
name|uint32_t
name|ni_spare1
index|[
literal|5
index|]
decl_stmt|;
comment|/* 	 * The following array contains the offset of each netmap ring 	 * from this structure, in the following order: 	 * NIC tx rings (ni_tx_rings); host tx ring (1); extra tx rings; 	 * NIC rx rings (ni_rx_rings); host tx ring (1); extra rx rings. 	 * 	 * The area is filled up by the kernel on NIOCREGIF, 	 * and then only read by userspace code. 	 */
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
comment|/*  * ioctl names and related fields  *  * NIOCTXSYNC, NIOCRXSYNC synchronize tx or rx queues,  *	whose identity is set in NIOCREGIF through nr_ringid.  *	These are non blocking and take no argument.  *  * NIOCGINFO takes a struct ifreq, the interface name is the input,  *	the outputs are number of queues and number of descriptor  *	for each queue (useful to set number of threads etc.).  *	The info returned is only advisory and may change before  *	the interface is bound to a file descriptor.  *  * NIOCREGIF takes an interface name within a struct nmre,  *	and activates netmap mode on the interface (if possible).  *  * The argument to NIOCGINFO/NIOCREGIF overlays struct ifreq so we  * can pass it down to other NIC-related ioctls.  *  * The actual argument (struct nmreq) has a number of options to request  * different functions.  * The following are used in NIOCREGIF when nr_cmd == 0:  *  * nr_name	(in)  *	The name of the port (em0, valeXXX:YYY, etc.)  *	limited to IFNAMSIZ for backward compatibility.  *  * nr_version	(in/out)  *	Must match NETMAP_API as used in the kernel, error otherwise.  *	Always returns the desired value on output.  *  * nr_tx_slots, nr_tx_slots, nr_tx_rings, nr_rx_rings (in/out)  *	On input, non-zero values may be used to reconfigure the port  *	according to the requested values, but this is not guaranteed.  *	On output the actual values in use are reported.  *  * nr_ringid (in)  *	Indicates how rings should be bound to the file descriptors.  *	If nr_flags != 0, then the low bits (in NETMAP_RING_MASK)  *	are used to indicate the ring number, and nr_flags specifies  *	the actual rings to bind. NETMAP_NO_TX_POLL is unaffected.  *  *	NOTE: THE FOLLOWING (nr_flags == 0) IS DEPRECATED:  *	If nr_flags == 0, NETMAP_HW_RING and NETMAP_SW_RING control  *	the binding as follows:  *	0 (default)			binds all physical rings  *	NETMAP_HW_RING | ring number	binds a single ring pair  *	NETMAP_SW_RING			binds only the host tx/rx rings  *  *	NETMAP_NO_TX_POLL can be OR-ed to make select()/poll() push  *		packets on tx rings only if POLLOUT is set.  *		The default is to push any pending packet.  *  *	NETMAP_DO_RX_POLL can be OR-ed to make select()/poll() release  *		packets on rx rings also when POLLIN is NOT set.  *		The default is to touch the rx ring only with POLLIN.  *		Note that this is the opposite of TX because it  *		reflects the common usage.  *  *	NOTE: NETMAP_PRIV_MEM IS DEPRECATED, use nr_arg2 instead.  *	NETMAP_PRIV_MEM is set on return for ports that do not use  *		the global memory allocator.  *		This information is not significant and applications  *		should look at the region id in nr_arg2  *  * nr_flags	is the recommended mode to indicate which rings should  *		be bound to a file descriptor. Values are NR_REG_*  *  * nr_arg1 (in)	The number of extra rings to be reserved.  *		Especially when allocating a VALE port the system only  *		allocates the amount of memory needed for the port.  *		If more shared memory rings are desired (e.g. for pipes),  *		the first invocation for the same basename/allocator  *		should specify a suitable number. Memory cannot be  *		extended after the first allocation without closing  *		all ports on the same region.  *  * nr_arg2 (in/out) The identity of the memory region used.  *		On input, 0 means the system decides autonomously,  *		other values may try to select a specific region.  *		On return the actual value is reported.  *		Region '1' is the global allocator, normally shared  *		by all interfaces. Other values are private regions.  *		If two ports the same region zero-copy is possible.  *  * nr_arg3 (in/out)	number of extra buffers to be allocated.  *  *  *  * nr_cmd (in)	if non-zero indicates a special command:  *	NETMAP_BDG_ATTACH	 and nr_name = vale*:ifname  *		attaches the NIC to the switch; nr_ringid specifies  *		which rings to use. Used by vale-ctl -a ...  *	    nr_arg1 = NETMAP_BDG_HOST also attaches the host port  *		as in vale-ctl -h ...  *  *	NETMAP_BDG_DETACH	and nr_name = vale*:ifname  *		disconnects a previously attached NIC.  *		Used by vale-ctl -d ...  *  *	NETMAP_BDG_LIST  *		list the configuration of VALE switches.  *  *	NETMAP_BDG_VNET_HDR  *		Set the virtio-net header length used by the client  *		of a VALE switch port.  *  *	NETMAP_BDG_NEWIF  *		create a persistent VALE port with name nr_name.  *		Used by vale-ctl -n ...  *  *	NETMAP_BDG_DELIF  *		delete a persistent VALE port. Used by vale-ctl -d ...  *  * nr_arg1, nr_arg2, nr_arg3  (in/out)		command specific  *  *  *  */
end_comment

begin_comment
comment|/*  * struct nmreq overlays a struct ifreq (just the name)  */
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
comment|/* single NIC ring pair */
define|#
directive|define
name|NETMAP_SW_RING
value|0x2000
comment|/* only host ring pair */
define|#
directive|define
name|NETMAP_RING_MASK
value|0x0fff
comment|/* the ring number */
define|#
directive|define
name|NETMAP_NO_TX_POLL
value|0x1000
comment|/* no automatic txsync on poll */
define|#
directive|define
name|NETMAP_DO_RX_POLL
value|0x8000
comment|/* DO automatic rxsync on poll */
name|uint16_t
name|nr_cmd
decl_stmt|;
define|#
directive|define
name|NETMAP_BDG_ATTACH
value|1
comment|/* attach the NIC */
define|#
directive|define
name|NETMAP_BDG_DETACH
value|2
comment|/* detach the NIC */
define|#
directive|define
name|NETMAP_BDG_REGOPS
value|3
comment|/* register bridge callbacks */
define|#
directive|define
name|NETMAP_BDG_LIST
value|4
comment|/* get bridge's info */
define|#
directive|define
name|NETMAP_BDG_VNET_HDR
value|5
comment|/* set the port virtio-net-hdr length */
define|#
directive|define
name|NETMAP_BDG_OFFSET
value|NETMAP_BDG_VNET_HDR
comment|/* deprecated alias */
define|#
directive|define
name|NETMAP_BDG_NEWIF
value|6
comment|/* create a virtual port */
define|#
directive|define
name|NETMAP_BDG_DELIF
value|7
comment|/* destroy a virtual port */
name|uint16_t
name|nr_arg1
decl_stmt|;
comment|/* reserve extra rings in NIOCREGIF */
define|#
directive|define
name|NETMAP_BDG_HOST
value|1
comment|/* attach the host stack on ATTACH */
name|uint16_t
name|nr_arg2
decl_stmt|;
name|uint32_t
name|nr_arg3
decl_stmt|;
comment|/* req. extra buffers in NIOCREGIF */
name|uint32_t
name|nr_flags
decl_stmt|;
comment|/* various modes, extends nr_ringid */
name|uint32_t
name|spare2
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NR_REG_MASK
value|0xf
end_define

begin_comment
comment|/* values for nr_flags */
end_comment

begin_enum
enum|enum
block|{
name|NR_REG_DEFAULT
init|=
literal|0
block|,
comment|/* backward compat, should not be used. */
name|NR_REG_ALL_NIC
init|=
literal|1
block|,
name|NR_REG_SW
init|=
literal|2
block|,
name|NR_REG_NIC_SW
init|=
literal|3
block|,
name|NR_REG_ONE_NIC
init|=
literal|4
block|,
name|NR_REG_PIPE_MASTER
init|=
literal|5
block|,
name|NR_REG_PIPE_SLAVE
init|=
literal|6
block|, }
enum|;
end_enum

begin_comment
comment|/* monitor uses the NR_REG to select the rings to monitor */
end_comment

begin_define
define|#
directive|define
name|NR_MONITOR_TX
value|0x100
end_define

begin_define
define|#
directive|define
name|NR_MONITOR_RX
value|0x200
end_define

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

begin_define
define|#
directive|define
name|NIOCCONFIG
value|_IOWR('i',150, struct nm_ifreq)
end_define

begin_comment
comment|/* for ext. modules */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NIOCREGIF */
end_comment

begin_comment
comment|/*  * Helper functions for kernel and userspace  */
end_comment

begin_comment
comment|/*  * check if space is available in the ring.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|nm_ring_empty
parameter_list|(
name|struct
name|netmap_ring
modifier|*
name|ring
parameter_list|)
block|{
return|return
operator|(
name|ring
operator|->
name|cur
operator|==
name|ring
operator|->
name|tail
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Opaque structure that is passed to an external kernel  * module via ioctl(fd, NIOCCONFIG, req) for a user-owned  * bridge port (at this point ephemeral VALE interface).  */
end_comment

begin_define
define|#
directive|define
name|NM_IFRDATA_LEN
value|256
end_define

begin_struct
struct|struct
name|nm_ifreq
block|{
name|char
name|nifr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|char
name|data
index|[
name|NM_IFRDATA_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_NETMAP_H_ */
end_comment

end_unit

