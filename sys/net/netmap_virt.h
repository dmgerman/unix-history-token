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

begin_define
define|#
directive|define
name|NETMAP_VIRT_CSB_SIZE
value|4096
end_define

begin_comment
comment|/* ptnetmap features */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_F_BASE
value|1
end_define

begin_define
define|#
directive|define
name|PTNETMAP_F_FULL
value|2
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_F_VNET_HDR
value|4
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
value|0x3333
end_define

begin_comment
comment|/* TODO change vendor_id */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_PCI_DEVICE_ID
value|0x0001
end_define

begin_comment
comment|/* memory device */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_PCI_NETIF_ID
value|0x0002
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

begin_comment
comment|/* 32 bit r/o */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_IO_PCI_FEATURES
value|0
end_define

begin_comment
comment|/* XXX should be removed */
end_comment

begin_comment
comment|/* 32 bit r/o */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_IO_PCI_MEMSIZE
value|4
end_define

begin_comment
comment|/* size of the netmap memory shared 						 * between guest and host */
end_comment

begin_comment
comment|/* 16 bit r/o */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_IO_PCI_HOSTID
value|8
end_define

begin_comment
comment|/* memory allocator ID in netmap host */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_IO_SIZE
value|10
end_define

begin_comment
comment|/*  * ptnetmap configuration  *  * The hypervisor (QEMU or bhyve) sends this struct to the host netmap  * module through an ioctl() command when it wants to start the ptnetmap  * kthreads.  */
end_comment

begin_struct
struct|struct
name|ptnetmap_cfg
block|{
define|#
directive|define
name|PTNETMAP_CFG_FEAT_CSB
value|0x0001
define|#
directive|define
name|PTNETMAP_CFG_FEAT_EVENTFD
value|0x0002
define|#
directive|define
name|PTNETMAP_CFG_FEAT_IOCTL
value|0x0004
name|uint32_t
name|features
decl_stmt|;
name|void
modifier|*
name|ptrings
decl_stmt|;
comment|/* ptrings inside CSB */
name|uint32_t
name|num_rings
decl_stmt|;
comment|/* number of entries */
name|struct
name|ptnet_ring_cfg
name|entries
index|[
literal|0
index|]
decl_stmt|;
comment|/* per-ptring configuration */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Functions used to write ptnetmap_cfg from/to the nmreq.  * The user-space application writes the pointer of ptnetmap_cfg  * (user-space buffer) starting from nr_arg1 field, so that the kernel  * can read it with copyin (copy_from_user).  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ptnetmap_write_cfg
parameter_list|(
name|struct
name|nmreq
modifier|*
name|nmr
parameter_list|,
name|struct
name|ptnetmap_cfg
modifier|*
name|cfg
parameter_list|)
block|{
name|uintptr_t
modifier|*
name|nmr_ptncfg
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
name|nmr_ptncfg
operator|=
operator|(
name|uintptr_t
operator|)
name|cfg
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ptnetmap control commands */
end_comment

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_CONFIG
value|1
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_FINALIZE
value|2
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_IFNEW
value|3
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_IFDELETE
value|4
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_RINGSCREATE
value|5
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_RINGSDELETE
value|6
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_DEREF
value|7
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_TXSYNC
value|8
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_RXSYNC
value|9
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_REGIF
value|10
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_UNREGIF
value|11
end_define

begin_define
define|#
directive|define
name|PTNETMAP_PTCTL_HOSTMEMID
value|12
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
name|PTNET_IO_PTSTS
value|8
end_define

begin_comment
comment|/* hole */
end_comment

begin_define
define|#
directive|define
name|PTNET_IO_MAC_LO
value|16
end_define

begin_define
define|#
directive|define
name|PTNET_IO_MAC_HI
value|20
end_define

begin_define
define|#
directive|define
name|PTNET_IO_CSBBAH
value|24
end_define

begin_define
define|#
directive|define
name|PTNET_IO_CSBBAL
value|28
end_define

begin_define
define|#
directive|define
name|PTNET_IO_NIFP_OFS
value|32
end_define

begin_define
define|#
directive|define
name|PTNET_IO_NUM_TX_RINGS
value|36
end_define

begin_define
define|#
directive|define
name|PTNET_IO_NUM_RX_RINGS
value|40
end_define

begin_define
define|#
directive|define
name|PTNET_IO_NUM_TX_SLOTS
value|44
end_define

begin_define
define|#
directive|define
name|PTNET_IO_NUM_RX_SLOTS
value|48
end_define

begin_define
define|#
directive|define
name|PTNET_IO_VNET_HDR_LEN
value|52
end_define

begin_define
define|#
directive|define
name|PTNET_IO_END
value|56
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
name|char
name|pad
index|[
literal|4
index|]
decl_stmt|;
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
name|uint32_t
name|sync_flags
decl_stmt|;
comment|/* GW+ HR+ the flags of the guest [tx|rx]sync() */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WITH_PTNETMAP_HOST
argument_list|)
operator|||
name|defined
argument_list|(
name|WITH_PTNETMAP_GUEST
argument_list|)
end_if

begin_comment
comment|/* return l_elem - r_elem with wraparound */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|ptn_sub
parameter_list|(
name|uint32_t
name|l_elem
parameter_list|,
name|uint32_t
name|r_elem
parameter_list|,
name|uint32_t
name|num_slots
parameter_list|)
block|{
name|int64_t
name|res
decl_stmt|;
name|res
operator|=
call|(
name|int64_t
call|)
argument_list|(
name|l_elem
argument_list|)
operator|-
name|r_elem
expr_stmt|;
return|return
operator|(
name|res
operator|<
literal|0
operator|)
condition|?
name|res
operator|+
name|num_slots
else|:
name|res
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_PTNETMAP_HOST || WITH_PTNETMAP_GUEST */
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
comment|/*  * HOST read/write kring pointers from/in CSB  */
end_comment

begin_comment
comment|/* Host: Read kring pointers (head, cur, sync_flags) from CSB */
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
name|g_ring
parameter_list|,
name|uint32_t
name|num_slots
parameter_list|)
block|{
name|uint32_t
name|old_head
init|=
name|g_ring
operator|->
name|head
decl_stmt|,
name|old_cur
init|=
name|g_ring
operator|->
name|cur
decl_stmt|;
name|uint32_t
name|d
decl_stmt|,
name|inc_h
decl_stmt|,
name|inc_c
decl_stmt|;
comment|//mb(); /* Force memory complete before read CSB */
comment|/*      * We must first read head and then cur with a barrier in the      * middle, because cur can exceed head, but not vice versa.      * The guest must first write cur and then head with a barrier.      *      * head<= cur      *      *          guest           host      *      *          STORE(cur)      LOAD(head)      *            mb() ----------- mb()      *          STORE(head)     LOAD(cur)      *      * This approach ensures that every head that we read is      * associated with the correct cur. In this way head can not exceed cur.      */
name|CSB_READ
argument_list|(
name|ptr
argument_list|,
name|head
argument_list|,
name|g_ring
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
name|g_ring
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
name|g_ring
operator|->
name|flags
argument_list|)
expr_stmt|;
comment|/*      * Even with the previous barrier, it is still possible that we read an      * updated cur and an old head.      * To detect this situation, we can check if the new cur overtakes      * the (apparently) new head.      */
name|d
operator|=
name|ptn_sub
argument_list|(
name|old_cur
argument_list|,
name|old_head
argument_list|,
name|num_slots
argument_list|)
expr_stmt|;
comment|/* previous distance */
name|inc_c
operator|=
name|ptn_sub
argument_list|(
name|g_ring
operator|->
name|cur
argument_list|,
name|old_cur
argument_list|,
name|num_slots
argument_list|)
expr_stmt|;
comment|/* increase of cur */
name|inc_h
operator|=
name|ptn_sub
argument_list|(
name|g_ring
operator|->
name|head
argument_list|,
name|old_head
argument_list|,
name|num_slots
argument_list|)
expr_stmt|;
comment|/* increase of head */
if|if
condition|(
name|unlikely
argument_list|(
name|inc_c
operator|>
name|num_slots
operator|-
name|d
operator|+
name|inc_h
argument_list|)
condition|)
block|{
comment|/* cur overtakes head */
name|ND
argument_list|(
literal|1
argument_list|,
literal|"ERROR cur overtakes head - old_cur: %u cur: %u old_head: %u head: %u"
argument_list|,
name|old_cur
argument_list|,
name|g_ring
operator|->
name|cur
argument_list|,
name|old_head
argument_list|,
name|g_ring
operator|->
name|head
argument_list|)
expr_stmt|;
name|g_ring
operator|->
name|cur
operator|=
name|nm_prev
argument_list|(
name|g_ring
operator|->
name|head
argument_list|,
name|num_slots
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|//*g_cur = *g_head;
block|}
block|}
end_function

begin_comment
comment|/* Host: Write kring pointers (hwcur, hwtail) into the CSB */
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
comment|/* We must write hwtail before hwcur (see below). */
name|CSB_WRITE
argument_list|(
name|ptr
argument_list|,
name|hwtail
argument_list|,
name|hwtail
argument_list|)
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
name|CSB_WRITE
argument_list|(
name|ptr
argument_list|,
name|hwcur
argument_list|,
name|hwcur
argument_list|)
expr_stmt|;
comment|//mb(); /* Force memory complete before send notification */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_PTNETMAP_HOST */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_PTNETMAP_GUEST
end_ifdef

begin_comment
comment|/*  * GUEST read/write kring pointers from/in CSB.  * To use into device driver.  */
end_comment

begin_comment
comment|/* Guest: Write kring pointers (cur, head) into the CSB */
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
comment|/* We must write cur before head for sync reason (see above) */
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
comment|//mb(); /* Force memory complete before send notification */
block|}
end_function

begin_comment
comment|/* Guest: Read kring pointers (hwcur, hwtail) from CSB */
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
name|uint32_t
name|old_hwcur
init|=
name|kring
operator|->
name|nr_hwcur
decl_stmt|,
name|old_hwtail
init|=
name|kring
operator|->
name|nr_hwtail
decl_stmt|;
name|uint32_t
name|num_slots
init|=
name|kring
operator|->
name|nkr_num_slots
decl_stmt|;
name|uint32_t
name|d
decl_stmt|,
name|inc_hc
decl_stmt|,
name|inc_ht
decl_stmt|;
comment|//mb(); /* Force memory complete before read CSB */
comment|/*      * We must first read hwcur and then hwtail with a barrier in the      * middle, because hwtail can exceed hwcur, but not vice versa.      * The host must first write hwtail and then hwcur with a barrier.      *      * hwcur<= hwtail      *      *          host            guest      *      *          STORE(hwtail)   LOAD(hwcur)      *            mb()  ---------  mb()      *          STORE(hwcur)    LOAD(hwtail)      *      * This approach ensures that every hwcur that the guest reads is      * associated with the correct hwtail. In this way hwcur can not exceed      * hwtail.      */
name|kring
operator|->
name|nr_hwcur
operator|=
name|ptr
operator|->
name|hwcur
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
name|kring
operator|->
name|nr_hwtail
operator|=
name|ptr
operator|->
name|hwtail
expr_stmt|;
comment|/*      * Even with the previous barrier, it is still possible that we read an      * updated hwtail and an old hwcur.      * To detect this situation, we can check if the new hwtail overtakes      * the (apparently) new hwcur.      */
name|d
operator|=
name|ptn_sub
argument_list|(
name|old_hwtail
argument_list|,
name|old_hwcur
argument_list|,
name|num_slots
argument_list|)
expr_stmt|;
comment|/* previous distance */
name|inc_ht
operator|=
name|ptn_sub
argument_list|(
name|kring
operator|->
name|nr_hwtail
argument_list|,
name|old_hwtail
argument_list|,
name|num_slots
argument_list|)
expr_stmt|;
comment|/* increase of hwtail */
name|inc_hc
operator|=
name|ptn_sub
argument_list|(
name|kring
operator|->
name|nr_hwcur
argument_list|,
name|old_hwcur
argument_list|,
name|num_slots
argument_list|)
expr_stmt|;
comment|/* increase of hwcur */
if|if
condition|(
name|unlikely
argument_list|(
name|inc_ht
operator|>
name|num_slots
operator|-
name|d
operator|+
name|inc_hc
argument_list|)
condition|)
block|{
name|ND
argument_list|(
literal|1
argument_list|,
literal|"ERROR hwtail overtakes hwcur - old_hwtail: %u hwtail: %u old_hwcur: %u hwcur: %u"
argument_list|,
name|old_hwtail
argument_list|,
name|kring
operator|->
name|nr_hwtail
argument_list|,
name|old_hwcur
argument_list|,
name|kring
operator|->
name|nr_hwcur
argument_list|)
expr_stmt|;
name|kring
operator|->
name|nr_hwtail
operator|=
name|nm_prev
argument_list|(
name|kring
operator|->
name|nr_hwcur
argument_list|,
name|num_slots
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|//kring->nr_hwtail = kring->nr_hwcur;
block|}
block|}
end_function

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_PTNETMAP_GUEST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETMAP_VIRT_H */
end_comment

end_unit

