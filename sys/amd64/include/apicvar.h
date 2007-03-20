begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 John Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_APICVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_APICVAR_H_
end_define

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_comment
comment|/*  * Local&& I/O APIC variable definitions.  */
end_comment

begin_comment
comment|/*  * Layout of local APIC interrupt vectors:  *  *	0xff (255)  +-------------+  *                  |             | 15 (Spurious / IPIs / Local Interrupts)  *	0xf0 (240)  +-------------+  *                  |             | 14 (I/O Interrupts / Timer)  *	0xe0 (224)  +-------------+  *                  |             | 13 (I/O Interrupts)  *	0xd0 (208)  +-------------+  *                  |             | 12 (I/O Interrupts)  *	0xc0 (192)  +-------------+  *                  |             | 11 (I/O Interrupts)  *	0xb0 (176)  +-------------+  *                  |             | 10 (I/O Interrupts)  *	0xa0 (160)  +-------------+  *                  |             | 9 (I/O Interrupts)  *	0x90 (144)  +-------------+  *                  |             | 8 (I/O Interrupts / System Calls)  *	0x80 (128)  +-------------+  *                  |             | 7 (I/O Interrupts)  *	0x70 (112)  +-------------+  *                  |             | 6 (I/O Interrupts)  *	0x60 (96)   +-------------+  *                  |             | 5 (I/O Interrupts)  *	0x50 (80)   +-------------+  *                  |             | 4 (I/O Interrupts)  *	0x40 (64)   +-------------+  *                  |             | 3 (I/O Interrupts)  *	0x30 (48)   +-------------+  *                  |             | 2 (ATPIC Interrupts)  *	0x20 (32)   +-------------+  *                  |             | 1 (Exceptions, traps, faults, etc.)  *	0x10 (16)   +-------------+  *                  |             | 0 (Exceptions, traps, faults, etc.)  *	0x00 (0)    +-------------+  *  * Note: 0x80 needs to be handled specially and not allocated to an  * I/O device!  */
end_comment

begin_define
define|#
directive|define
name|APIC_ID_ALL
value|0xff
end_define

begin_comment
comment|/* I/O Interrupts are used for external devices such as ISA, PCI, etc. */
end_comment

begin_define
define|#
directive|define
name|APIC_IO_INTS
value|(IDT_IO_INTS + 16)
end_define

begin_define
define|#
directive|define
name|APIC_NUM_IOINTS
value|191
end_define

begin_comment
comment|/* The timer interrupt is used for clock handling and drives hardclock, etc. */
end_comment

begin_define
define|#
directive|define
name|APIC_TIMER_INT
value|(APIC_IO_INTS + APIC_NUM_IOINTS)
end_define

begin_comment
comment|/*    ********************* !!! WARNING !!! ******************************  * Each local apic has an interrupt receive fifo that is two entries deep  * for each interrupt priority class (higher 4 bits of interrupt vector).  * Once the fifo is full the APIC can no longer receive interrupts for this  * class and sending IPIs from other CPUs will be blocked.  * To avoid deadlocks there should be no more than two IPI interrupts  * pending at the same time.  * Currently this is guaranteed by dividing the IPIs in two groups that have   * each at most one IPI interrupt pending. The first group is protected by the  * smp_ipi_mtx and waits for the completion of the IPI (Only one IPI user   * at a time) The second group uses a single interrupt and a bitmap to avoid  * redundant IPI interrupts.  *  * Right now IPI_STOP used by kdb shares the interrupt priority class with  * the two IPI groups mentioned above. As such IPI_STOP may cause a deadlock.  * Eventually IPI_STOP should use NMI IPIs - this would eliminate this and  * other deadlocks caused by IPI_STOP.  */
end_comment

begin_comment
comment|/* Interrupts for local APIC LVT entries other than the timer. */
end_comment

begin_define
define|#
directive|define
name|APIC_LOCAL_INTS
value|240
end_define

begin_define
define|#
directive|define
name|APIC_ERROR_INT
value|APIC_LOCAL_INTS
end_define

begin_define
define|#
directive|define
name|APIC_THERMAL_INT
value|(APIC_LOCAL_INTS + 1)
end_define

begin_define
define|#
directive|define
name|APIC_IPI_INTS
value|(APIC_LOCAL_INTS + 2)
end_define

begin_define
define|#
directive|define
name|IPI_RENDEZVOUS
value|(APIC_IPI_INTS)
end_define

begin_comment
comment|/* Inter-CPU rendezvous. */
end_comment

begin_define
define|#
directive|define
name|IPI_INVLTLB
value|(APIC_IPI_INTS + 1)
end_define

begin_comment
comment|/* TLB Shootdown IPIs */
end_comment

begin_define
define|#
directive|define
name|IPI_INVLPG
value|(APIC_IPI_INTS + 2)
end_define

begin_define
define|#
directive|define
name|IPI_INVLRNG
value|(APIC_IPI_INTS + 3)
end_define

begin_define
define|#
directive|define
name|IPI_INVLCACHE
value|(APIC_IPI_INTS + 4)
end_define

begin_comment
comment|/* Vector to handle bitmap based IPIs */
end_comment

begin_define
define|#
directive|define
name|IPI_BITMAP_VECTOR
value|(APIC_IPI_INTS + 6)
end_define

begin_comment
comment|/* IPIs handled by IPI_BITMAPED_VECTOR  (XXX ups is there a better place?) */
end_comment

begin_define
define|#
directive|define
name|IPI_AST
value|0
end_define

begin_comment
comment|/* Generate software trap. */
end_comment

begin_define
define|#
directive|define
name|IPI_PREEMPT
value|1
end_define

begin_define
define|#
directive|define
name|IPI_BITMAP_LAST
value|IPI_PREEMPT
end_define

begin_define
define|#
directive|define
name|IPI_IS_BITMAPED
parameter_list|(
name|x
parameter_list|)
value|((x)<= IPI_BITMAP_LAST)
end_define

begin_define
define|#
directive|define
name|IPI_STOP
value|(APIC_IPI_INTS + 7)
end_define

begin_comment
comment|/* Stop CPU until restarted. */
end_comment

begin_comment
comment|/*  * The spurious interrupt can share the priority class with the IPIs since  * it is not a normal interrupt. (Does not use the APIC's interrupt fifo)  */
end_comment

begin_define
define|#
directive|define
name|APIC_SPURIOUS_INT
value|255
end_define

begin_define
define|#
directive|define
name|LVT_LINT0
value|0
end_define

begin_define
define|#
directive|define
name|LVT_LINT1
value|1
end_define

begin_define
define|#
directive|define
name|LVT_TIMER
value|2
end_define

begin_define
define|#
directive|define
name|LVT_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|LVT_PMC
value|4
end_define

begin_define
define|#
directive|define
name|LVT_THERMAL
value|5
end_define

begin_define
define|#
directive|define
name|LVT_MAX
value|LVT_THERMAL
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_define
define|#
directive|define
name|APIC_IPI_DEST_SELF
value|-1
end_define

begin_define
define|#
directive|define
name|APIC_IPI_DEST_ALL
value|-2
end_define

begin_define
define|#
directive|define
name|APIC_IPI_DEST_OTHERS
value|-3
end_define

begin_define
define|#
directive|define
name|APIC_BUS_UNKNOWN
value|-1
end_define

begin_define
define|#
directive|define
name|APIC_BUS_ISA
value|0
end_define

begin_define
define|#
directive|define
name|APIC_BUS_EISA
value|1
end_define

begin_define
define|#
directive|define
name|APIC_BUS_PCI
value|2
end_define

begin_define
define|#
directive|define
name|APIC_BUS_MAX
value|APIC_BUS_PCI
end_define

begin_comment
comment|/*  * An APIC enumerator is a psuedo bus driver that enumerates APIC's including  * CPU's and I/O APIC's.  */
end_comment

begin_struct
struct|struct
name|apic_enumerator
block|{
specifier|const
name|char
modifier|*
name|apic_name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|apic_probe
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|apic_probe_cpus
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|apic_setup_local
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|apic_setup_io
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|SLIST_ENTRY
argument_list|(
argument|apic_enumerator
argument_list|)
name|apic_next
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|inthand_t
name|IDTVEC
argument_list|(
name|apic_isr1
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|apic_isr2
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|apic_isr3
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|apic_isr4
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|apic_isr5
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|apic_isr6
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|apic_isr7
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|spuriousint
argument_list|)
decl_stmt|,
name|IDTVEC
argument_list|(
name|timerint
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|lapic_paddr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|u_int
name|apic_alloc_vector
parameter_list|(
name|u_int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|apic_alloc_vectors
parameter_list|(
name|u_int
modifier|*
name|irqs
parameter_list|,
name|u_int
name|count
parameter_list|,
name|u_int
name|align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|apic_enable_vector
parameter_list|(
name|u_int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|apic_free_vector
parameter_list|(
name|u_int
name|vector
parameter_list|,
name|u_int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|apic_idt_to_irq
parameter_list|(
name|u_int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|apic_register_enumerator
parameter_list|(
name|struct
name|apic_enumerator
modifier|*
name|enumerator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ioapic_create
parameter_list|(
name|vm_paddr_t
name|addr
parameter_list|,
name|int32_t
name|apic_id
parameter_list|,
name|int
name|intbase
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ioapic_disable_pin
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|u_int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ioapic_get_vector
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|u_int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ioapic_register
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ioapic_remap_vector
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|u_int
name|pin
parameter_list|,
name|int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ioapic_set_bus
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|u_int
name|pin
parameter_list|,
name|int
name|bus_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ioapic_set_extint
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|u_int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ioapic_set_nmi
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|u_int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ioapic_set_polarity
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|u_int
name|pin
parameter_list|,
name|enum
name|intr_polarity
name|pol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ioapic_set_triggermode
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|u_int
name|pin
parameter_list|,
name|enum
name|intr_trigger
name|trigger
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ioapic_set_smi
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|u_int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_create
parameter_list|(
name|u_int
name|apic_id
parameter_list|,
name|int
name|boot_cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_dump
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_eoi
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lapic_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_init
parameter_list|(
name|vm_paddr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lapic_intr_pending
parameter_list|(
name|u_int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_ipi_raw
parameter_list|(
name|register_t
name|icrlo
parameter_list|,
name|u_int
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_ipi_vectored
parameter_list|(
name|u_int
name|vector
parameter_list|,
name|int
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lapic_ipi_wait
parameter_list|(
name|int
name|delay
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_handle_intr
parameter_list|(
name|int
name|vector
parameter_list|,
name|struct
name|trapframe
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_handle_timer
parameter_list|(
name|struct
name|trapframe
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_set_logical_id
parameter_list|(
name|u_int
name|apic_id
parameter_list|,
name|u_int
name|cluster
parameter_list|,
name|u_int
name|cluster_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lapic_set_lvt_mask
parameter_list|(
name|u_int
name|apic_id
parameter_list|,
name|u_int
name|lvt
parameter_list|,
name|u_char
name|masked
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lapic_set_lvt_mode
parameter_list|(
name|u_int
name|apic_id
parameter_list|,
name|u_int
name|lvt
parameter_list|,
name|u_int32_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lapic_set_lvt_polarity
parameter_list|(
name|u_int
name|apic_id
parameter_list|,
name|u_int
name|lvt
parameter_list|,
name|enum
name|intr_polarity
name|pol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lapic_set_lvt_triggermode
parameter_list|(
name|u_int
name|apic_id
parameter_list|,
name|u_int
name|lvt
parameter_list|,
name|enum
name|intr_trigger
name|trigger
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_set_tpr
parameter_list|(
name|u_int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lapic_setup
parameter_list|(
name|int
name|boot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lapic_setup_clock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_APICVAR_H_ */
end_comment

end_unit

