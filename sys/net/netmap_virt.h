begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2013-2016 Luigi Rizzo  * Copyright (C) 2013-2016 Giuseppe Lettieri  * Copyright (C) 2013-2016 Vincenzo Maffione  * Copyright (C) 2015 Stefano Garzarella  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETMAP_VIRT_H
end_ifndef

begin_define
define|#
directive|define
name|NETMAP_VIRT_H
end_define

begin_comment
comment|/*  * ptnetmap_memdev: device used to expose memory into the guest VM  *  * These macros are used in the hypervisor frontend (QEMU, bhyve) and in the  * guest device driver.  */
end_comment

begin_comment
comment|/* PCI identifiers and PCI BARs for the ptnetmap memdev  * and ptnetmap network interface. */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_MEMDEV_NAME
value|"ptnetmap-memdev"
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PCI_VENDOR_ID
value|0x1b36
end_define

begin_comment
comment|/* QEMU virtual devices */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_PCI_DEVICE_ID
value|0x000c
end_define

begin_comment
comment|/* memory device */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_PCI_NETIF_ID
value|0x000d
end_define

begin_comment
comment|/* ptnet network interface */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_IO_PCI_BAR
value|0
end_define

begin_define
define|#
directive|define
name|PTNETMAP_MEM_PCI_BAR
value|1
end_define

begin_define
define|#
directive|define
name|PTNETMAP_MSIX_PCI_BAR
value|2
end_define

begin_comment
comment|/* Registers for the ptnetmap memdev */
end_comment

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_MEMSIZE_LO
value|0
end_define

begin_comment
comment|/* netmap memory size (low) */
end_comment

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_MEMSIZE_HI
value|4
end_define

begin_comment
comment|/* netmap_memory_size (high) */
end_comment

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_MEMID
value|8
end_define

begin_comment
comment|/* memory allocator ID in the host */
end_comment

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_IF_POOL_OFS
value|64
end_define

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_IF_POOL_OBJNUM
value|68
end_define

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_IF_POOL_OBJSZ
value|72
end_define

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_RING_POOL_OFS
value|76
end_define

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_RING_POOL_OBJNUM
value|80
end_define

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_RING_POOL_OBJSZ
value|84
end_define

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_BUF_POOL_OFS
value|88
end_define

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_BUF_POOL_OBJNUM
value|92
end_define

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_BUF_POOL_OBJSZ
value|96
end_define

begin_define
define|#
directive|define
name|PTNET_MDEV_IO_END
value|100
end_define

begin_comment
comment|/*  * ptnetmap configuration  *  * The ptnet kthreads (running in host kernel-space) need to be configured  * in order to know how to intercept guest kicks (I/O register writes) and  * how to inject MSI-X interrupts to the guest. The configuration may vary  * depending on the hypervisor. Currently, we support QEMU/KVM on Linux and  * and bhyve on FreeBSD.  * The configuration is passed by the hypervisor to the host netmap module  * by means of an ioctl() with nr_cmd=NETMAP_PT_HOST_CREATE, and it is  * specified by the ptnetmap_cfg struct. This struct contains an header  * with general informations and an array of entries whose size depends  * on the hypervisor. The NETMAP_PT_HOST_CREATE command is issued every  * time the kthreads are started.  */
end_comment

begin_struct
struct|struct
name|ptnetmap_cfg
block|{
define|#
directive|define
name|PTNETMAP_CFGTYPE_QEMU
value|0x1
define|#
directive|define
name|PTNETMAP_CFGTYPE_BHYVE
value|0x2
name|uint16_t
name|cfgtype
decl_stmt|;
comment|/* how to interpret the cfg entries */
name|uint16_t
name|entry_size
decl_stmt|;
comment|/* size of a config entry */
name|uint32_t
name|num_rings
decl_stmt|;
comment|/* number of config entries */
name|void
modifier|*
name|ptrings
decl_stmt|;
comment|/* ptrings inside CSB */
comment|/* Configuration entries are allocated right after the struct. */
block|}
struct|;
end_struct

begin_comment
comment|/* Configuration of a ptnetmap ring for QEMU. */
end_comment

begin_struct
struct|struct
name|ptnetmap_cfgentry_qemu
block|{
name|uint32_t
name|ioeventfd
decl_stmt|;
comment|/* to intercept guest register access */
name|uint32_t
name|irqfd
decl_stmt|;
comment|/* to inject guest interrupts */
block|}
struct|;
end_struct

begin_comment
comment|/* Configuration of a ptnetmap ring for bhyve. */
end_comment

begin_struct
struct|struct
name|ptnetmap_cfgentry_bhyve
block|{
name|uint64_t
name|wchan
decl_stmt|;
comment|/* tsleep() parameter, to wake up kthread */
name|uint32_t
name|ioctl_fd
decl_stmt|;
comment|/* ioctl fd */
comment|/* ioctl parameters to send irq */
name|uint32_t
name|ioctl_cmd
decl_stmt|;
comment|/* vmm.ko MSIX parameters for IOCTL */
struct|struct
block|{
name|uint64_t
name|msg_data
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
block|}
name|ioctl_data
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure filled-in by the kernel when asked for allocator info  * through NETMAP_POOLS_INFO_GET. Used by hypervisors supporting  * ptnetmap.  */
end_comment

begin_struct
struct|struct
name|netmap_pools_info
block|{
name|uint64_t
name|memsize
decl_stmt|;
comment|/* same as nmr->nr_memsize */
name|uint32_t
name|memid
decl_stmt|;
comment|/* same as nmr->nr_arg2 */
name|uint32_t
name|if_pool_offset
decl_stmt|;
name|uint32_t
name|if_pool_objtotal
decl_stmt|;
name|uint32_t
name|if_pool_objsize
decl_stmt|;
name|uint32_t
name|ring_pool_offset
decl_stmt|;
name|uint32_t
name|ring_pool_objtotal
decl_stmt|;
name|uint32_t
name|ring_pool_objsize
decl_stmt|;
name|uint32_t
name|buf_pool_offset
decl_stmt|;
name|uint32_t
name|buf_pool_objtotal
decl_stmt|;
name|uint32_t
name|buf_pool_objsize
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Pass a pointer to a userspace buffer to be passed to kernelspace for write  * or read. Used by NETMAP_PT_HOST_CREATE and NETMAP_POOLS_INFO_GET.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|nmreq_pointer_put
parameter_list|(
name|struct
name|nmreq
modifier|*
name|nmr
parameter_list|,
name|void
modifier|*
name|userptr
parameter_list|)
block|{
name|uintptr_t
modifier|*
name|pp
init|=
operator|(
name|uintptr_t
operator|*
operator|)
operator|&
name|nmr
operator|->
name|nr_arg1
decl_stmt|;
operator|*
name|pp
operator|=
operator|(
name|uintptr_t
operator|)
name|userptr
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ptnetmap features */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_F_VNET_HDR
value|1
end_define

begin_comment
comment|/* I/O registers for the ptnet device. */
end_comment

begin_define
define|#
directive|define
name|PTNET_IO_PTFEAT
value|0
end_define

begin_define
define|#
directive|define
name|PTNET_IO_PTCTL
value|4
end_define

begin_define
define|#
directive|define
name|PTNET_IO_MAC_LO
value|8
end_define

begin_define
define|#
directive|define
name|PTNET_IO_MAC_HI
value|12
end_define

begin_define
define|#
directive|define
name|PTNET_IO_CSBBAH
value|16
end_define

begin_define
define|#
directive|define
name|PTNET_IO_CSBBAL
value|20
end_define

begin_define
define|#
directive|define
name|PTNET_IO_NIFP_OFS
value|24
end_define

begin_define
define|#
directive|define
name|PTNET_IO_NUM_TX_RINGS
value|28
end_define

begin_define
define|#
directive|define
name|PTNET_IO_NUM_RX_RINGS
value|32
end_define

begin_define
define|#
directive|define
name|PTNET_IO_NUM_TX_SLOTS
value|36
end_define

begin_define
define|#
directive|define
name|PTNET_IO_NUM_RX_SLOTS
value|40
end_define

begin_define
define|#
directive|define
name|PTNET_IO_VNET_HDR_LEN
value|44
end_define

begin_define
define|#
directive|define
name|PTNET_IO_HOSTMEMID
value|48
end_define

begin_define
define|#
directive|define
name|PTNET_IO_END
value|52
end_define

begin_define
define|#
directive|define
name|PTNET_IO_KICK_BASE
value|128
end_define

begin_define
define|#
directive|define
name|PTNET_IO_MASK
value|0xff
end_define

begin_comment
comment|/* ptnetmap control commands (values for PTCTL register) */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_CREATE
value|1
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_DELETE
value|2
end_define

begin_comment
comment|/* If defined, CSB is allocated by the guest, not by the host. */
end_comment

begin_define
define|#
directive|define
name|PTNET_CSB_ALLOC
end_define

begin_comment
comment|/* ptnetmap ring fields shared between guest and host */
end_comment

begin_struct
struct|struct
name|ptnet_ring
block|{
comment|/* XXX revise the layout to minimize cache bounces. */
name|uint32_t
name|head
decl_stmt|;
comment|/* GW+ HR+ the head of the guest netmap_ring */
name|uint32_t
name|cur
decl_stmt|;
comment|/* GW+ HR+ the cur of the guest netmap_ring */
name|uint32_t
name|guest_need_kick
decl_stmt|;
comment|/* GW+ HR+ host-->guest notification enable */
name|uint32_t
name|sync_flags
decl_stmt|;
comment|/* GW+ HR+ the flags of the guest [tx|rx]sync() */
name|uint32_t
name|hwcur
decl_stmt|;
comment|/* GR+ HW+ the hwcur of the host netmap_kring */
name|uint32_t
name|hwtail
decl_stmt|;
comment|/* GR+ HW+ the hwtail of the host netmap_kring */
name|uint32_t
name|host_need_kick
decl_stmt|;
comment|/* GR+ HW+ guest-->host notification enable */
name|char
name|pad
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* CSB for the ptnet device. */
end_comment

begin_struct
struct|struct
name|ptnet_csb
block|{
define|#
directive|define
name|NETMAP_VIRT_CSB_SIZE
value|4096
name|struct
name|ptnet_ring
name|rings
index|[
name|NETMAP_VIRT_CSB_SIZE
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|ptnet_ring
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_PTNETMAP_GUEST
end_ifdef

begin_comment
comment|/* ptnetmap_memdev routines used to talk with ptnetmap_memdev device driver */
end_comment

begin_struct_decl
struct_decl|struct
name|ptnetmap_memdev
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|nm_os_pt_memdev_iomap
parameter_list|(
name|struct
name|ptnetmap_memdev
modifier|*
parameter_list|,
name|vm_paddr_t
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nm_os_pt_memdev_iounmap
parameter_list|(
name|struct
name|ptnetmap_memdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|nm_os_pt_memdev_ioread
parameter_list|(
name|struct
name|ptnetmap_memdev
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Guest driver: Write kring pointers (cur, head) to the CSB.  * This routine is coupled with ptnetmap_host_read_kring_csb(). */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ptnetmap_guest_write_kring_csb
parameter_list|(
name|struct
name|ptnet_ring
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|cur
parameter_list|,
name|uint32_t
name|head
parameter_list|)
block|{
comment|/*      * We need to write cur and head to the CSB but we cannot do it atomically.      * There is no way we can prevent the host from reading the updated value      * of one of the two and the old value of the other. However, if we make      * sure that the host never reads a value of head more recent than the      * value of cur we are safe. We can allow the host to read a value of cur      * more recent than the value of head, since in the netmap ring cur can be      * ahead of head and cur cannot wrap around head because it must be behind      * tail. Inverting the order of writes below could instead result into the      * host to think head went ahead of cur, which would cause the sync      * prologue to fail.      *      * The following memory barrier scheme is used to make this happen:      *      *          Guest              Host      *      *          STORE(cur)         LOAD(head)      *          mb()<-----------> mb()      *          STORE(head)        LOAD(cur)      */
name|ptr
operator|->
name|cur
operator|=
name|cur
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
name|ptr
operator|->
name|head
operator|=
name|head
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Guest driver: Read kring pointers (hwcur, hwtail) from the CSB.  * This routine is coupled with ptnetmap_host_write_kring_csb(). */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ptnetmap_guest_read_kring_csb
parameter_list|(
name|struct
name|ptnet_ring
modifier|*
name|ptr
parameter_list|,
name|struct
name|netmap_kring
modifier|*
name|kring
parameter_list|)
block|{
comment|/*      * We place a memory barrier to make sure that the update of hwtail never      * overtakes the update of hwcur.      * (see explanation in ptnetmap_host_write_kring_csb).      */
name|kring
operator|->
name|nr_hwtail
operator|=
name|ptr
operator|->
name|hwtail
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
name|kring
operator|->
name|nr_hwcur
operator|=
name|ptr
operator|->
name|hwcur
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_PTNETMAP_GUEST */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_PTNETMAP_HOST
end_ifdef

begin_comment
comment|/*  * ptnetmap kernel thread routines  * */
end_comment

begin_comment
comment|/* Functions to read and write CSB fields in the host */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_define
define|#
directive|define
name|CSB_READ
parameter_list|(
name|csb
parameter_list|,
name|field
parameter_list|,
name|r
parameter_list|)
value|(get_user(r,&csb->field))
end_define

begin_define
define|#
directive|define
name|CSB_WRITE
parameter_list|(
name|csb
parameter_list|,
name|field
parameter_list|,
name|v
parameter_list|)
value|(put_user(v,&csb->field))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! linux */
end_comment

begin_define
define|#
directive|define
name|CSB_READ
parameter_list|(
name|csb
parameter_list|,
name|field
parameter_list|,
name|r
parameter_list|)
value|(r = fuword32(&csb->field))
end_define

begin_define
define|#
directive|define
name|CSB_WRITE
parameter_list|(
name|csb
parameter_list|,
name|field
parameter_list|,
name|v
parameter_list|)
value|(suword32(&csb->field, v))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! linux */
end_comment

begin_comment
comment|/* Host netmap: Write kring pointers (hwcur, hwtail) to the CSB.  * This routine is coupled with ptnetmap_guest_read_kring_csb(). */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ptnetmap_host_write_kring_csb
parameter_list|(
name|struct
name|ptnet_ring
name|__user
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|hwcur
parameter_list|,
name|uint32_t
name|hwtail
parameter_list|)
block|{
comment|/*      * The same scheme used in ptnetmap_guest_write_kring_csb() applies here.      * We allow the guest to read a value of hwcur more recent than the value      * of hwtail, since this would anyway result in a consistent view of the      * ring state (and hwcur can never wraparound hwtail, since hwcur must be      * behind head).      *      * The following memory barrier scheme is used to make this happen:      *      *          Guest                Host      *      *          STORE(hwcur)         LOAD(hwtail)      *          mb()<-------------> mb()      *          STORE(hwtail)        LOAD(hwcur)      */
name|CSB_WRITE
argument_list|(
name|ptr
argument_list|,
name|hwcur
argument_list|,
name|hwcur
argument_list|)
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
name|CSB_WRITE
argument_list|(
name|ptr
argument_list|,
name|hwtail
argument_list|,
name|hwtail
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Host netmap: Read kring pointers (head, cur, sync_flags) from the CSB.  * This routine is coupled with ptnetmap_guest_write_kring_csb(). */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ptnetmap_host_read_kring_csb
parameter_list|(
name|struct
name|ptnet_ring
name|__user
modifier|*
name|ptr
parameter_list|,
name|struct
name|netmap_ring
modifier|*
name|shadow_ring
parameter_list|,
name|uint32_t
name|num_slots
parameter_list|)
block|{
comment|/*      * We place a memory barrier to make sure that the update of head never      * overtakes the update of cur.      * (see explanation in ptnetmap_guest_write_kring_csb).      */
name|CSB_READ
argument_list|(
name|ptr
argument_list|,
name|head
argument_list|,
name|shadow_ring
operator|->
name|head
argument_list|)
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
name|CSB_READ
argument_list|(
name|ptr
argument_list|,
name|cur
argument_list|,
name|shadow_ring
operator|->
name|cur
argument_list|)
expr_stmt|;
name|CSB_READ
argument_list|(
name|ptr
argument_list|,
name|sync_flags
argument_list|,
name|shadow_ring
operator|->
name|flags
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_PTNETMAP_HOST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETMAP_VIRT_H */
end_comment

end_unit

