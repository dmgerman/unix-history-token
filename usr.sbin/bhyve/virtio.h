begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013  Chris Torek<torek @ torek net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_H_
end_define

begin_comment
comment|/*  * These are derived from several virtio specifications.  *  * Some useful links:  *    https://github.com/rustyrussell/virtio-spec  *    http://people.redhat.com/pbonzini/virtio-spec.pdf  */
end_comment

begin_comment
comment|/*  * A virtual device has zero or more "virtual queues" (virtqueue).  * Each virtqueue uses at least two 4096-byte pages, laid out thus:  *  *      +-----------------------------------------------+  *      |    "desc":<N> descriptors, 16 bytes each    |  *      |   -----------------------------------------   |  *      |   "avail":   2 uint16;<N> uint16; 1 uint16   |  *      |   -----------------------------------------   |  *      |              pad to 4k boundary               |  *      +-----------------------------------------------+  *      |   "used": 2 x uint16;<N> elems; 1 uint16     |  *      |   -----------------------------------------   |  *      |              pad to 4k boundary               |  *      +-----------------------------------------------+  *  * The number<N> that appears here is always a power of two and is  * limited to no more than 32768 (as it must fit in a 16-bit field).  * If<N> is sufficiently large, the above will occupy more than  * two pages.  In any case, all pages must be physically contiguous  * within the guest's physical address space.  *  * The<N> 16-byte "desc" descriptors consist of a 64-bit guest  * physical address<addr>, a 32-bit length<len>, a 16-bit  *<flags>, and a 16-bit<next> field (all in guest byte order).  *  * There are three flags that may be set :  *	NEXT    descriptor is chained, so use its "next" field  *	WRITE   descriptor is for host to write into guest RAM  *		(else host is to read from guest RAM)  *	INDIRECT   descriptor address field is (guest physical)  *		address of a linear array of descriptors  *  * Unless INDIRECT is set,<len> is the number of bytes that may  * be read/written from guest physical address<addr>.  If  * INDIRECT is set, WRITE is ignored and<len> provides the length  * of the indirect descriptors (and<len> must be a multiple of  * 16).  Note that NEXT may still be set in the main descriptor  * pointing to the indirect, and should be set in each indirect  * descriptor that uses the next descriptor (these should generally  * be numbered sequentially).  However, INDIRECT must not be set  * in the indirect descriptors.  Upon reaching an indirect descriptor  * without a NEXT bit, control returns to the direct descriptors.  *  * Except inside an indirect, each<next> value must be in the  * range [0 .. N) (i.e., the half-open interval).  (Inside an  * indirect, each<next> must be in the range [0 ..<len>/16).)  *  * The "avail" data structures reside in the same pages as the  * "desc" structures since both together are used by the device to  * pass information to the hypervisor's virtual driver.  These  * begin with a 16-bit<flags> field and 16-bit index<idx>, then  * have<N> 16-bit<ring> values, followed by one final 16-bit  * field<used_event>.  The<N><ring> entries are simply indices  * indices into the descriptor ring (and thus must meet the same  * constraints as each<next> value).  However,<idx> is counted  * up from 0 (initially) and simply wraps around after 65535; it  * is taken mod<N> to find the next available entry.  *  * The "used" ring occupies a separate page or pages, and contains  * values written from the virtual driver back to the guest OS.  * This begins with a 16-bit<flags> and 16-bit<idx>, then there  * are<N> "vring_used" elements, followed by a 16-bit<avail_event>.  * The<N> "vring_used" elements consist of a 32-bit<id> and a  * 32-bit<len> (vu_tlen below).  The<id> is simply the index of  * the head of a descriptor chain the guest made available  * earlier, and the<len> is the number of bytes actually written,  * e.g., in the case of a network driver that provided a large  * receive buffer but received only a small amount of data.  *  * The two event fields,<used_event> and<avail_event>, in the  * avail and used rings (respectively -- note the reversal!), are  * always provided, but are used only if the virtual device  * negotiates the VIRTIO_RING_F_EVENT_IDX feature during feature  * negotiation.  Similarly, both rings provide a flag --  * VRING_AVAIL_F_NO_INTERRUPT and VRING_USED_F_NO_NOTIFY -- in  * their<flags> field, indicating that the guest does not need an  * interrupt, or that the hypervisor driver does not need a  * notify, when descriptors are added to the corresponding ring.  * (These are provided only for interrupt optimization and need  * not be implemented.)  */
end_comment

begin_define
define|#
directive|define
name|VRING_ALIGN
value|4096
end_define

begin_define
define|#
directive|define
name|VRING_DESC_F_NEXT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VRING_DESC_F_WRITE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|VRING_DESC_F_INDIRECT
value|(1<< 2)
end_define

begin_struct
struct|struct
name|virtio_desc
block|{
comment|/* AKA vring_desc */
name|uint64_t
name|vd_addr
decl_stmt|;
comment|/* guest physical address */
name|uint32_t
name|vd_len
decl_stmt|;
comment|/* length of scatter/gather seg */
name|uint16_t
name|vd_flags
decl_stmt|;
comment|/* VRING_F_DESC_* */
name|uint16_t
name|vd_next
decl_stmt|;
comment|/* next desc if F_NEXT */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|virtio_used
block|{
comment|/* AKA vring_used_elem */
name|uint32_t
name|vu_idx
decl_stmt|;
comment|/* head of used descriptor chain */
name|uint32_t
name|vu_tlen
decl_stmt|;
comment|/* length written-to */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VRING_AVAIL_F_NO_INTERRUPT
value|1
end_define

begin_struct
struct|struct
name|vring_avail
block|{
name|uint16_t
name|va_flags
decl_stmt|;
comment|/* VRING_AVAIL_F_* */
name|uint16_t
name|va_idx
decl_stmt|;
comment|/* counts to 65535, then cycles */
name|uint16_t
name|va_ring
index|[]
decl_stmt|;
comment|/* size N, reported in QNUM value */
comment|/*	uint16_t	va_used_event;	-- after N ring entries */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VRING_USED_F_NO_NOTIFY
value|1
end_define

begin_struct
struct|struct
name|vring_used
block|{
name|uint16_t
name|vu_flags
decl_stmt|;
comment|/* VRING_USED_F_* */
name|uint16_t
name|vu_idx
decl_stmt|;
comment|/* counts to 65535, then cycles */
name|struct
name|virtio_used
name|vu_ring
index|[]
decl_stmt|;
comment|/* size N */
comment|/*	uint16_t	vu_avail_event;	-- after N ring entries */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * The address of any given virtual queue is determined by a single  * Page Frame Number register.  The guest writes the PFN into the  * PCI config space.  However, a device that has two or more  * virtqueues can have a different PFN, and size, for each queue.  * The number of queues is determinable via the PCI config space  * VTCFG_R_QSEL register.  Writes to QSEL select the queue: 0 means  * queue #0, 1 means queue#1, etc.  Once a queue is selected, the  * remaining PFN and QNUM registers refer to that queue.  *  * QNUM is a read-only register containing a nonzero power of two  * that indicates the (hypervisor's) queue size.  Or, if reading it  * produces zero, the hypervisor does not have a corresponding  * queue.  (The number of possible queues depends on the virtual  * device.  The block device has just one; the network device  * provides either two -- 0 = receive, 1 = transmit -- or three,  * with 2 = control.)  *  * PFN is a read/write register giving the physical page address of  * the virtqueue in guest memory (the guest must allocate enough space  * based on the hypervisor's provided QNUM).  *  * QNOTIFY is effectively write-only: when the guest writes a queue  * number to the register, the hypervisor should scan the specified  * virtqueue. (Reading QNOTIFY currently always gets 0).  */
end_comment

begin_comment
comment|/*  * PFN register shift amount  */
end_comment

begin_define
define|#
directive|define
name|VRING_PFN
value|12
end_define

begin_comment
comment|/*  * Virtio device types  *  * XXX Should really be merged with<dev/virtio/virtio.h> defines  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_TYPE_NET
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_TYPE_BLOCK
value|2
end_define

begin_define
define|#
directive|define
name|VIRTIO_TYPE_CONSOLE
value|3
end_define

begin_define
define|#
directive|define
name|VIRTIO_TYPE_ENTROPY
value|4
end_define

begin_define
define|#
directive|define
name|VIRTIO_TYPE_BALLOON
value|5
end_define

begin_define
define|#
directive|define
name|VIRTIO_TYPE_IOMEMORY
value|6
end_define

begin_define
define|#
directive|define
name|VIRTIO_TYPE_RPMSG
value|7
end_define

begin_define
define|#
directive|define
name|VIRTIO_TYPE_SCSI
value|8
end_define

begin_define
define|#
directive|define
name|VIRTIO_TYPE_9P
value|9
end_define

begin_comment
comment|/* experimental IDs start at 65535 and work down */
end_comment

begin_comment
comment|/*  * PCI vendor/device IDs  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_VENDOR
value|0x1AF4
end_define

begin_define
define|#
directive|define
name|VIRTIO_DEV_NET
value|0x1000
end_define

begin_define
define|#
directive|define
name|VIRTIO_DEV_BLOCK
value|0x1001
end_define

begin_define
define|#
directive|define
name|VIRTIO_DEV_RANDOM
value|0x1005
end_define

begin_define
define|#
directive|define
name|VIRTIO_DEV_CONSOLE
value|0x1003
end_define

begin_comment
comment|/*  * PCI config space constants.  *  * If MSI-X is enabled, the ISR register is generally not used,  * and the configuration vector and queue vector appear at offsets  * 20 and 22 with the remaining configuration registers at 24.  * If MSI-X is not enabled, those two registers disappear and  * the remaining configuration registers start at offset 20.  */
end_comment

begin_define
define|#
directive|define
name|VTCFG_R_HOSTCAP
value|0
end_define

begin_define
define|#
directive|define
name|VTCFG_R_GUESTCAP
value|4
end_define

begin_define
define|#
directive|define
name|VTCFG_R_PFN
value|8
end_define

begin_define
define|#
directive|define
name|VTCFG_R_QNUM
value|12
end_define

begin_define
define|#
directive|define
name|VTCFG_R_QSEL
value|14
end_define

begin_define
define|#
directive|define
name|VTCFG_R_QNOTIFY
value|16
end_define

begin_define
define|#
directive|define
name|VTCFG_R_STATUS
value|18
end_define

begin_define
define|#
directive|define
name|VTCFG_R_ISR
value|19
end_define

begin_define
define|#
directive|define
name|VTCFG_R_CFGVEC
value|20
end_define

begin_define
define|#
directive|define
name|VTCFG_R_QVEC
value|22
end_define

begin_define
define|#
directive|define
name|VTCFG_R_CFG0
value|20
end_define

begin_comment
comment|/* No MSI-X */
end_comment

begin_define
define|#
directive|define
name|VTCFG_R_CFG1
value|24
end_define

begin_comment
comment|/* With MSI-X */
end_comment

begin_define
define|#
directive|define
name|VTCFG_R_MSIX
value|20
end_define

begin_comment
comment|/*  * Bits in VTCFG_R_STATUS.  Guests need not actually set any of these,  * but a guest writing 0 to this register means "please reset".  */
end_comment

begin_define
define|#
directive|define
name|VTCFG_STATUS_ACK
value|0x01
end_define

begin_comment
comment|/* guest OS has acknowledged dev */
end_comment

begin_define
define|#
directive|define
name|VTCFG_STATUS_DRIVER
value|0x02
end_define

begin_comment
comment|/* guest OS driver is loaded */
end_comment

begin_define
define|#
directive|define
name|VTCFG_STATUS_DRIVER_OK
value|0x04
end_define

begin_comment
comment|/* guest OS driver ready */
end_comment

begin_define
define|#
directive|define
name|VTCFG_STATUS_FAILED
value|0x80
end_define

begin_comment
comment|/* guest has given up on this dev */
end_comment

begin_comment
comment|/*  * Bits in VTCFG_R_ISR.  These apply only if not using MSI-X.  *  * (We don't [yet?] ever use CONF_CHANGED.)  */
end_comment

begin_define
define|#
directive|define
name|VTCFG_ISR_QUEUES
value|0x01
end_define

begin_comment
comment|/* re-scan queues */
end_comment

begin_define
define|#
directive|define
name|VTCFG_ISR_CONF_CHANGED
value|0x80
end_define

begin_comment
comment|/* configuration changed */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_MSI_NO_VECTOR
value|0xFFFF
end_define

begin_comment
comment|/*  * Feature flags.  * Note: bits 0 through 23 are reserved to each device type.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_F_NOTIFY_ON_EMPTY
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|VIRTIO_RING_F_INDIRECT_DESC
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|VIRTIO_RING_F_EVENT_IDX
value|(1<< 29)
end_define

begin_comment
comment|/* From section 2.3, "Virtqueue Configuration", of the virtio specification */
end_comment

begin_function
specifier|static
specifier|inline
name|size_t
name|vring_size
parameter_list|(
name|u_int
name|qsz
parameter_list|)
block|{
name|size_t
name|size
decl_stmt|;
comment|/* constant 3 below = va_flags, va_idx, va_used_event */
name|size
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|virtio_desc
argument_list|)
operator|*
name|qsz
operator|+
sizeof|sizeof
argument_list|(
name|uint16_t
argument_list|)
operator|*
operator|(
literal|3
operator|+
name|qsz
operator|)
expr_stmt|;
name|size
operator|=
name|roundup2
argument_list|(
name|size
argument_list|,
name|VRING_ALIGN
argument_list|)
expr_stmt|;
comment|/* constant 3 below = vu_flags, vu_idx, vu_avail_event */
name|size
operator|+=
sizeof|sizeof
argument_list|(
name|uint16_t
argument_list|)
operator|*
literal|3
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|virtio_used
argument_list|)
operator|*
name|qsz
expr_stmt|;
name|size
operator|=
name|roundup2
argument_list|(
name|size
argument_list|,
name|VRING_ALIGN
argument_list|)
expr_stmt|;
return|return
operator|(
name|size
operator|)
return|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|vmctx
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pci_devinst
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vqueue_info
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * A virtual device, with some number (possibly 0) of virtual  * queues and some size (possibly 0) of configuration-space  * registers private to the device.  The virtio_softc should come  * at the front of each "derived class", so that a pointer to the  * virtio_softc is also a pointer to the more specific, derived-  * from-virtio driver's softc.  *  * Note: inside each hypervisor virtio driver, changes to these  * data structures must be locked against other threads, if any.  * Except for PCI config space register read/write, we assume each  * driver does the required locking, but we need a pointer to the  * lock (if there is one) for PCI config space read/write ops.  *  * When the guest reads or writes the device's config space, the  * generic layer checks for operations on the special registers  * described above.  If the offset of the register(s) being read  * or written is past the CFG area (CFG0 or CFG1), the request is  * passed on to the virtual device, after subtracting off the  * generic-layer size.  (So, drivers can just use the offset as  * an offset into "struct config", for instance.)  *  * (The virtio layer also makes sure that the read or write is to/  * from a "good" config offset, hence vc_cfgsize, and on BAR #0.  * However, the driver must verify the read or write size and offset  * and that no one is writing a readonly register.)  *  * The BROKED flag ("this thing done gone and broked") is for future  * use.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_USE_MSIX
value|0x01
end_define

begin_define
define|#
directive|define
name|VIRTIO_EVENT_IDX
value|0x02
end_define

begin_comment
comment|/* use the event-index values */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BROKED
value|0x08
end_define

begin_comment
comment|/* ??? */
end_comment

begin_struct
struct|struct
name|virtio_softc
block|{
name|struct
name|virtio_consts
modifier|*
name|vs_vc
decl_stmt|;
comment|/* constants (see below) */
name|int
name|vs_flags
decl_stmt|;
comment|/* VIRTIO_* flags from above */
name|pthread_mutex_t
modifier|*
name|vs_mtx
decl_stmt|;
comment|/* POSIX mutex, if any */
name|struct
name|pci_devinst
modifier|*
name|vs_pi
decl_stmt|;
comment|/* PCI device instance */
name|uint32_t
name|vs_negotiated_caps
decl_stmt|;
comment|/* negotiated capabilities */
name|struct
name|vqueue_info
modifier|*
name|vs_queues
decl_stmt|;
comment|/* one per vc_nvq */
name|int
name|vs_curq
decl_stmt|;
comment|/* current queue */
name|uint8_t
name|vs_status
decl_stmt|;
comment|/* value from last status write */
name|uint8_t
name|vs_isr
decl_stmt|;
comment|/* ISR flags, if not MSI-X */
name|uint16_t
name|vs_msix_cfg_idx
decl_stmt|;
comment|/* MSI-X vector for config event */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VS_LOCK
parameter_list|(
name|vs
parameter_list|)
define|\
value|do {									\ 	if (vs->vs_mtx)							\ 		pthread_mutex_lock(vs->vs_mtx);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|VS_UNLOCK
parameter_list|(
name|vs
parameter_list|)
define|\
value|do {									\ 	if (vs->vs_mtx)							\ 		pthread_mutex_unlock(vs->vs_mtx);			\ } while (0)
end_define

begin_struct
struct|struct
name|virtio_consts
block|{
specifier|const
name|char
modifier|*
name|vc_name
decl_stmt|;
comment|/* name of driver (for diagnostics) */
name|int
name|vc_nvq
decl_stmt|;
comment|/* number of virtual queues */
name|size_t
name|vc_cfgsize
decl_stmt|;
comment|/* size of dev-specific config regs */
name|void
function_decl|(
modifier|*
name|vc_reset
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* called on virtual device reset */
name|void
function_decl|(
modifier|*
name|vc_qnotify
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|vqueue_info
modifier|*
parameter_list|)
function_decl|;
comment|/* called on QNOTIFY if no VQ notify */
name|int
function_decl|(
modifier|*
name|vc_cfgread
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
comment|/* called to read config regs */
name|int
function_decl|(
modifier|*
name|vc_cfgwrite
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
comment|/* called to write config regs */
name|void
function_decl|(
modifier|*
name|vc_apply_features
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
comment|/* called to apply negotiated features */
name|uint64_t
name|vc_hv_caps
decl_stmt|;
comment|/* hypervisor-provided capabilities */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Data structure allocated (statically) per virtual queue.  *  * Drivers may change vq_qsize after a reset.  When the guest OS  * requests a device reset, the hypervisor first calls  * vs->vs_vc->vc_reset(); then the data structure below is  * reinitialized (for each virtqueue: vs->vs_vc->vc_nvq).  *  * The remaining fields should only be fussed-with by the generic  * code.  *  * Note: the addresses of vq_desc, vq_avail, and vq_used are all  * computable from each other, but it's a lot simpler if we just  * keep a pointer to each one.  The event indices are similarly  * (but more easily) computable, and this time we'll compute them:  * they're just XX_ring[N].  */
end_comment

begin_define
define|#
directive|define
name|VQ_ALLOC
value|0x01
end_define

begin_comment
comment|/* set once we have a pfn */
end_comment

begin_define
define|#
directive|define
name|VQ_BROKED
value|0x02
end_define

begin_comment
comment|/* ??? */
end_comment

begin_struct
struct|struct
name|vqueue_info
block|{
name|uint16_t
name|vq_qsize
decl_stmt|;
comment|/* size of this queue (a power of 2) */
name|void
function_decl|(
modifier|*
name|vq_notify
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|vqueue_info
modifier|*
parameter_list|)
function_decl|;
comment|/* called instead of vc_notify, if not NULL */
name|struct
name|virtio_softc
modifier|*
name|vq_vs
decl_stmt|;
comment|/* backpointer to softc */
name|uint16_t
name|vq_num
decl_stmt|;
comment|/* we're the num'th queue in the softc */
name|uint16_t
name|vq_flags
decl_stmt|;
comment|/* flags (see above) */
name|uint16_t
name|vq_last_avail
decl_stmt|;
comment|/* a recent value of vq_avail->va_idx */
name|uint16_t
name|vq_save_used
decl_stmt|;
comment|/* saved vq_used->vu_idx; see vq_endchains */
name|uint16_t
name|vq_msix_idx
decl_stmt|;
comment|/* MSI-X index, or VIRTIO_MSI_NO_VECTOR */
name|uint32_t
name|vq_pfn
decl_stmt|;
comment|/* PFN of virt queue (not shifted!) */
specifier|volatile
name|struct
name|virtio_desc
modifier|*
name|vq_desc
decl_stmt|;
comment|/* descriptor array */
specifier|volatile
name|struct
name|vring_avail
modifier|*
name|vq_avail
decl_stmt|;
comment|/* the "avail" ring */
specifier|volatile
name|struct
name|vring_used
modifier|*
name|vq_used
decl_stmt|;
comment|/* the "used" ring */
block|}
struct|;
end_struct

begin_comment
comment|/* as noted above, these are sort of backwards, name-wise */
end_comment

begin_define
define|#
directive|define
name|VQ_AVAIL_EVENT_IDX
parameter_list|(
name|vq
parameter_list|)
define|\
value|(*(volatile uint16_t *)&(vq)->vq_used->vu_ring[(vq)->vq_qsize])
end_define

begin_define
define|#
directive|define
name|VQ_USED_EVENT_IDX
parameter_list|(
name|vq
parameter_list|)
define|\
value|((vq)->vq_avail->va_ring[(vq)->vq_qsize])
end_define

begin_comment
comment|/*  * Is this ring ready for I/O?  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|vq_ring_ready
parameter_list|(
name|struct
name|vqueue_info
modifier|*
name|vq
parameter_list|)
block|{
return|return
operator|(
name|vq
operator|->
name|vq_flags
operator|&
name|VQ_ALLOC
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Are there "available" descriptors?  (This does not count  * how many, just returns True if there are some.)  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|vq_has_descs
parameter_list|(
name|struct
name|vqueue_info
modifier|*
name|vq
parameter_list|)
block|{
return|return
operator|(
name|vq_ring_ready
argument_list|(
name|vq
argument_list|)
operator|&&
name|vq
operator|->
name|vq_last_avail
operator|!=
name|vq
operator|->
name|vq_avail
operator|->
name|va_idx
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Deliver an interrupt to guest on the given virtual queue  * (if possible, or a generic MSI interrupt if not using MSI-X).  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|vq_interrupt
parameter_list|(
name|struct
name|virtio_softc
modifier|*
name|vs
parameter_list|,
name|struct
name|vqueue_info
modifier|*
name|vq
parameter_list|)
block|{
if|if
condition|(
name|pci_msix_enabled
argument_list|(
name|vs
operator|->
name|vs_pi
argument_list|)
condition|)
name|pci_generate_msix
argument_list|(
name|vs
operator|->
name|vs_pi
argument_list|,
name|vq
operator|->
name|vq_msix_idx
argument_list|)
expr_stmt|;
else|else
block|{
name|VS_LOCK
argument_list|(
name|vs
argument_list|)
expr_stmt|;
name|vs
operator|->
name|vs_isr
operator||=
name|VTCFG_ISR_QUEUES
expr_stmt|;
name|pci_generate_msi
argument_list|(
name|vs
operator|->
name|vs_pi
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pci_lintr_assert
argument_list|(
name|vs
operator|->
name|vs_pi
argument_list|)
expr_stmt|;
name|VS_UNLOCK
argument_list|(
name|vs
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_struct_decl
struct_decl|struct
name|iovec
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|vi_softc_linkup
parameter_list|(
name|struct
name|virtio_softc
modifier|*
name|vs
parameter_list|,
name|struct
name|virtio_consts
modifier|*
name|vc
parameter_list|,
name|void
modifier|*
name|dev_softc
parameter_list|,
name|struct
name|pci_devinst
modifier|*
name|pi
parameter_list|,
name|struct
name|vqueue_info
modifier|*
name|queues
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vi_intr_init
parameter_list|(
name|struct
name|virtio_softc
modifier|*
name|vs
parameter_list|,
name|int
name|barnum
parameter_list|,
name|int
name|use_msix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vi_reset_dev
parameter_list|(
name|struct
name|virtio_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vi_set_io_bar
parameter_list|(
name|struct
name|virtio_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vq_getchain
parameter_list|(
name|struct
name|vqueue_info
modifier|*
name|vq
parameter_list|,
name|uint16_t
modifier|*
name|pidx
parameter_list|,
name|struct
name|iovec
modifier|*
name|iov
parameter_list|,
name|int
name|n_iov
parameter_list|,
name|uint16_t
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vq_retchain
parameter_list|(
name|struct
name|vqueue_info
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vq_relchain
parameter_list|(
name|struct
name|vqueue_info
modifier|*
name|vq
parameter_list|,
name|uint16_t
name|idx
parameter_list|,
name|uint32_t
name|iolen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vq_endchains
parameter_list|(
name|struct
name|vqueue_info
modifier|*
name|vq
parameter_list|,
name|int
name|used_all_avail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vi_pci_read
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|struct
name|pci_devinst
modifier|*
name|pi
parameter_list|,
name|int
name|baridx
parameter_list|,
name|uint64_t
name|offset
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vi_pci_write
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|struct
name|pci_devinst
modifier|*
name|pi
parameter_list|,
name|int
name|baridx
parameter_list|,
name|uint64_t
name|offset
parameter_list|,
name|int
name|size
parameter_list|,
name|uint64_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_H_ */
end_comment

end_unit

