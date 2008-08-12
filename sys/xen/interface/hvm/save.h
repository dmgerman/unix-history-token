begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * hvm/save.h  *  * Structure definitions for HVM state that is held by Xen and must  * be saved along with the domain's memory and device-model state.  *  *   * Copyright (c) 2007 XenSource Ltd.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_HVM_SAVE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_HVM_SAVE_H__
end_define

begin_comment
comment|/*  * Structures in this header *must* have the same layout in 32bit   * and 64bit environments: this means that all fields must be explicitly   * sized types and aligned to their sizes, and the structs must be   * a multiple of eight bytes long.  *  * Only the state necessary for saving and restoring (i.e. fields   * that are analogous to actual hardware state) should go in this file.   * Internal mechanisms should be kept in Xen-private headers.  */
end_comment

begin_comment
comment|/*   * Each entry is preceded by a descriptor giving its type and length  */
end_comment

begin_struct
struct|struct
name|hvm_save_descriptor
block|{
name|uint16_t
name|typecode
decl_stmt|;
comment|/* Used to demux the various types below */
name|uint16_t
name|instance
decl_stmt|;
comment|/* Further demux within a type */
name|uint32_t
name|length
decl_stmt|;
comment|/* In bytes, *not* including this descriptor */
block|}
struct|;
end_struct

begin_comment
comment|/*   * Each entry has a datatype associated with it: for example, the CPU state   * is saved as a HVM_SAVE_TYPE(CPU), which has HVM_SAVE_LENGTH(CPU),   * and is identified by a descriptor with typecode HVM_SAVE_CODE(CPU).  * DECLARE_HVM_SAVE_TYPE binds these things together with some type-system  * ugliness.  */
end_comment

begin_define
define|#
directive|define
name|DECLARE_HVM_SAVE_TYPE
parameter_list|(
name|_x
parameter_list|,
name|_code
parameter_list|,
name|_type
parameter_list|)
define|\
value|struct __HVM_SAVE_TYPE_##_x { _type t; char c[_code]; }
end_define

begin_define
define|#
directive|define
name|HVM_SAVE_TYPE
parameter_list|(
name|_x
parameter_list|)
value|typeof (((struct __HVM_SAVE_TYPE_##_x *)(0))->t)
end_define

begin_define
define|#
directive|define
name|HVM_SAVE_LENGTH
parameter_list|(
name|_x
parameter_list|)
value|(sizeof (HVM_SAVE_TYPE(_x)))
end_define

begin_define
define|#
directive|define
name|HVM_SAVE_CODE
parameter_list|(
name|_x
parameter_list|)
value|(sizeof (((struct __HVM_SAVE_TYPE_##_x *)(0))->c))
end_define

begin_comment
comment|/*   * Save/restore header: general info about the save file.   */
end_comment

begin_define
define|#
directive|define
name|HVM_FILE_MAGIC
value|0x54381286
end_define

begin_define
define|#
directive|define
name|HVM_FILE_VERSION
value|0x00000001
end_define

begin_struct
struct|struct
name|hvm_save_header
block|{
name|uint32_t
name|magic
decl_stmt|;
comment|/* Must be HVM_FILE_MAGIC */
name|uint32_t
name|version
decl_stmt|;
comment|/* File format version */
name|uint64_t
name|changeset
decl_stmt|;
comment|/* Version of Xen that saved this file */
name|uint32_t
name|cpuid
decl_stmt|;
comment|/* CPUID[0x01][%eax] on the saving machine */
name|uint32_t
name|pad0
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|HEADER
argument_list|,
literal|1
argument_list|,
expr|struct
name|hvm_save_header
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Processor  */
end_comment

begin_struct
struct|struct
name|hvm_hw_cpu
block|{
name|uint8_t
name|fpu_regs
index|[
literal|512
index|]
decl_stmt|;
name|uint64_t
name|rax
decl_stmt|;
name|uint64_t
name|rbx
decl_stmt|;
name|uint64_t
name|rcx
decl_stmt|;
name|uint64_t
name|rdx
decl_stmt|;
name|uint64_t
name|rbp
decl_stmt|;
name|uint64_t
name|rsi
decl_stmt|;
name|uint64_t
name|rdi
decl_stmt|;
name|uint64_t
name|rsp
decl_stmt|;
name|uint64_t
name|r8
decl_stmt|;
name|uint64_t
name|r9
decl_stmt|;
name|uint64_t
name|r10
decl_stmt|;
name|uint64_t
name|r11
decl_stmt|;
name|uint64_t
name|r12
decl_stmt|;
name|uint64_t
name|r13
decl_stmt|;
name|uint64_t
name|r14
decl_stmt|;
name|uint64_t
name|r15
decl_stmt|;
name|uint64_t
name|rip
decl_stmt|;
name|uint64_t
name|rflags
decl_stmt|;
name|uint64_t
name|cr0
decl_stmt|;
name|uint64_t
name|cr2
decl_stmt|;
name|uint64_t
name|cr3
decl_stmt|;
name|uint64_t
name|cr4
decl_stmt|;
name|uint64_t
name|dr0
decl_stmt|;
name|uint64_t
name|dr1
decl_stmt|;
name|uint64_t
name|dr2
decl_stmt|;
name|uint64_t
name|dr3
decl_stmt|;
name|uint64_t
name|dr6
decl_stmt|;
name|uint64_t
name|dr7
decl_stmt|;
name|uint32_t
name|cs_sel
decl_stmt|;
name|uint32_t
name|ds_sel
decl_stmt|;
name|uint32_t
name|es_sel
decl_stmt|;
name|uint32_t
name|fs_sel
decl_stmt|;
name|uint32_t
name|gs_sel
decl_stmt|;
name|uint32_t
name|ss_sel
decl_stmt|;
name|uint32_t
name|tr_sel
decl_stmt|;
name|uint32_t
name|ldtr_sel
decl_stmt|;
name|uint32_t
name|cs_limit
decl_stmt|;
name|uint32_t
name|ds_limit
decl_stmt|;
name|uint32_t
name|es_limit
decl_stmt|;
name|uint32_t
name|fs_limit
decl_stmt|;
name|uint32_t
name|gs_limit
decl_stmt|;
name|uint32_t
name|ss_limit
decl_stmt|;
name|uint32_t
name|tr_limit
decl_stmt|;
name|uint32_t
name|ldtr_limit
decl_stmt|;
name|uint32_t
name|idtr_limit
decl_stmt|;
name|uint32_t
name|gdtr_limit
decl_stmt|;
name|uint64_t
name|cs_base
decl_stmt|;
name|uint64_t
name|ds_base
decl_stmt|;
name|uint64_t
name|es_base
decl_stmt|;
name|uint64_t
name|fs_base
decl_stmt|;
name|uint64_t
name|gs_base
decl_stmt|;
name|uint64_t
name|ss_base
decl_stmt|;
name|uint64_t
name|tr_base
decl_stmt|;
name|uint64_t
name|ldtr_base
decl_stmt|;
name|uint64_t
name|idtr_base
decl_stmt|;
name|uint64_t
name|gdtr_base
decl_stmt|;
name|uint32_t
name|cs_arbytes
decl_stmt|;
name|uint32_t
name|ds_arbytes
decl_stmt|;
name|uint32_t
name|es_arbytes
decl_stmt|;
name|uint32_t
name|fs_arbytes
decl_stmt|;
name|uint32_t
name|gs_arbytes
decl_stmt|;
name|uint32_t
name|ss_arbytes
decl_stmt|;
name|uint32_t
name|tr_arbytes
decl_stmt|;
name|uint32_t
name|ldtr_arbytes
decl_stmt|;
name|uint32_t
name|sysenter_cs
decl_stmt|;
name|uint32_t
name|padding0
decl_stmt|;
name|uint64_t
name|sysenter_esp
decl_stmt|;
name|uint64_t
name|sysenter_eip
decl_stmt|;
comment|/* msr for em64t */
name|uint64_t
name|shadow_gs
decl_stmt|;
comment|/* msr content saved/restored. */
name|uint64_t
name|msr_flags
decl_stmt|;
name|uint64_t
name|msr_lstar
decl_stmt|;
name|uint64_t
name|msr_star
decl_stmt|;
name|uint64_t
name|msr_cstar
decl_stmt|;
name|uint64_t
name|msr_syscall_mask
decl_stmt|;
name|uint64_t
name|msr_efer
decl_stmt|;
comment|/* guest's idea of what rdtsc() would return */
name|uint64_t
name|tsc
decl_stmt|;
comment|/* pending event, if any */
union|union
block|{
name|uint32_t
name|pending_event
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|pending_vector
range|:
literal|8
decl_stmt|;
name|uint8_t
name|pending_type
range|:
literal|3
decl_stmt|;
name|uint8_t
name|pending_error_valid
range|:
literal|1
decl_stmt|;
name|uint32_t
name|pending_reserved
range|:
literal|19
decl_stmt|;
name|uint8_t
name|pending_valid
range|:
literal|1
decl_stmt|;
block|}
struct|;
block|}
union|;
comment|/* error code for pending event */
name|uint32_t
name|error_code
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|CPU
argument_list|,
literal|2
argument_list|,
expr|struct
name|hvm_hw_cpu
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * PIC  */
end_comment

begin_struct
struct|struct
name|hvm_hw_vpic
block|{
comment|/* IR line bitmasks. */
name|uint8_t
name|irr
decl_stmt|;
name|uint8_t
name|imr
decl_stmt|;
name|uint8_t
name|isr
decl_stmt|;
comment|/* Line IRx maps to IRQ irq_base+x */
name|uint8_t
name|irq_base
decl_stmt|;
comment|/*      * Where are we in ICW2-4 initialisation (0 means no init in progress)?      * Bits 0-1 (=x): Next write at A=1 sets ICW(x+1).      * Bit 2: ICW1.IC4  (1 == ICW4 included in init sequence)      * Bit 3: ICW1.SNGL (0 == ICW3 included in init sequence)      */
name|uint8_t
name|init_state
range|:
literal|4
decl_stmt|;
comment|/* IR line with highest priority. */
name|uint8_t
name|priority_add
range|:
literal|4
decl_stmt|;
comment|/* Reads from A=0 obtain ISR or IRR? */
name|uint8_t
name|readsel_isr
range|:
literal|1
decl_stmt|;
comment|/* Reads perform a polling read? */
name|uint8_t
name|poll
range|:
literal|1
decl_stmt|;
comment|/* Automatically clear IRQs from the ISR during INTA? */
name|uint8_t
name|auto_eoi
range|:
literal|1
decl_stmt|;
comment|/* Automatically rotate IRQ priorities during AEOI? */
name|uint8_t
name|rotate_on_auto_eoi
range|:
literal|1
decl_stmt|;
comment|/* Exclude slave inputs when considering in-service IRQs? */
name|uint8_t
name|special_fully_nested_mode
range|:
literal|1
decl_stmt|;
comment|/* Special mask mode excludes masked IRs from AEOI and priority checks. */
name|uint8_t
name|special_mask_mode
range|:
literal|1
decl_stmt|;
comment|/* Is this a master PIC or slave PIC? (NB. This is not programmable.) */
name|uint8_t
name|is_master
range|:
literal|1
decl_stmt|;
comment|/* Edge/trigger selection. */
name|uint8_t
name|elcr
decl_stmt|;
comment|/* Virtual INT output. */
name|uint8_t
name|int_output
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|PIC
argument_list|,
literal|3
argument_list|,
expr|struct
name|hvm_hw_vpic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * IO-APIC  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_define
define|#
directive|define
name|VIOAPIC_IS_IOSAPIC
value|1
end_define

begin_define
define|#
directive|define
name|VIOAPIC_NUM_PINS
value|24
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VIOAPIC_NUM_PINS
value|48
end_define

begin_comment
comment|/* 16 ISA IRQs, 32 non-legacy PCI IRQS. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|hvm_hw_vioapic
block|{
name|uint64_t
name|base_address
decl_stmt|;
name|uint32_t
name|ioregsel
decl_stmt|;
name|uint32_t
name|id
decl_stmt|;
union|union
name|vioapic_redir_entry
block|{
name|uint64_t
name|bits
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|vector
decl_stmt|;
name|uint8_t
name|delivery_mode
range|:
literal|3
decl_stmt|;
name|uint8_t
name|dest_mode
range|:
literal|1
decl_stmt|;
name|uint8_t
name|delivery_status
range|:
literal|1
decl_stmt|;
name|uint8_t
name|polarity
range|:
literal|1
decl_stmt|;
name|uint8_t
name|remote_irr
range|:
literal|1
decl_stmt|;
name|uint8_t
name|trig_mode
range|:
literal|1
decl_stmt|;
name|uint8_t
name|mask
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserve
range|:
literal|7
decl_stmt|;
if|#
directive|if
operator|!
name|VIOAPIC_IS_IOSAPIC
name|uint8_t
name|reserved
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|dest_id
decl_stmt|;
else|#
directive|else
name|uint8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|dest_id
decl_stmt|;
endif|#
directive|endif
block|}
name|fields
struct|;
block|}
name|redirtbl
index|[
name|VIOAPIC_NUM_PINS
index|]
union|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|IOAPIC
argument_list|,
literal|4
argument_list|,
expr|struct
name|hvm_hw_vioapic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * LAPIC  */
end_comment

begin_struct
struct|struct
name|hvm_hw_lapic
block|{
name|uint64_t
name|apic_base_msr
decl_stmt|;
name|uint32_t
name|disabled
decl_stmt|;
comment|/* VLAPIC_xx_DISABLED */
name|uint32_t
name|timer_divisor
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|LAPIC
argument_list|,
literal|5
argument_list|,
expr|struct
name|hvm_hw_lapic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hvm_hw_lapic_regs
block|{
comment|/* A 4k page of register state */
name|uint8_t
name|data
index|[
literal|0x400
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|LAPIC_REGS
argument_list|,
literal|6
argument_list|,
expr|struct
name|hvm_hw_lapic_regs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * IRQs  */
end_comment

begin_struct
struct|struct
name|hvm_hw_pci_irqs
block|{
comment|/*      * Virtual interrupt wires for a single PCI bus.      * Indexed by: device*4 + INTx#.      */
union|union
block|{
name|DECLARE_BITMAP
argument_list|(
name|i
argument_list|,
literal|32
operator|*
literal|4
argument_list|)
expr_stmt|;
name|uint64_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|PCI_IRQ
argument_list|,
literal|7
argument_list|,
expr|struct
name|hvm_hw_pci_irqs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hvm_hw_isa_irqs
block|{
comment|/*      * Virtual interrupt wires for ISA devices.      * Indexed by ISA IRQ (assumes no ISA-device IRQ sharing).      */
union|union
block|{
name|DECLARE_BITMAP
argument_list|(
name|i
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|uint64_t
name|pad
index|[
literal|1
index|]
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|ISA_IRQ
argument_list|,
literal|8
argument_list|,
expr|struct
name|hvm_hw_isa_irqs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hvm_hw_pci_link
block|{
comment|/*      * PCI-ISA interrupt router.      * Each PCI<device:INTx#> is 'wire-ORed' into one of four links using      * the traditional 'barber's pole' mapping ((device + INTx#)& 3).      * The router provides a programmable mapping from each link to a GSI.      */
name|uint8_t
name|route
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|pad0
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|PCI_LINK
argument_list|,
literal|9
argument_list|,
expr|struct
name|hvm_hw_pci_link
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   *  PIT  */
end_comment

begin_struct
struct|struct
name|hvm_hw_pit
block|{
struct|struct
name|hvm_hw_pit_channel
block|{
name|uint32_t
name|count
decl_stmt|;
comment|/* can be 65536 */
name|uint16_t
name|latched_count
decl_stmt|;
name|uint8_t
name|count_latched
decl_stmt|;
name|uint8_t
name|status_latched
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|read_state
decl_stmt|;
name|uint8_t
name|write_state
decl_stmt|;
name|uint8_t
name|write_latch
decl_stmt|;
name|uint8_t
name|rw_mode
decl_stmt|;
name|uint8_t
name|mode
decl_stmt|;
name|uint8_t
name|bcd
decl_stmt|;
comment|/* not supported */
name|uint8_t
name|gate
decl_stmt|;
comment|/* timer start */
block|}
name|channels
index|[
literal|3
index|]
struct|;
comment|/* 3 x 16 bytes */
name|uint32_t
name|speaker_data_on
decl_stmt|;
name|uint32_t
name|pad0
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|PIT
argument_list|,
literal|10
argument_list|,
expr|struct
name|hvm_hw_pit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   * RTC  */
end_comment

begin_define
define|#
directive|define
name|RTC_CMOS_SIZE
value|14
end_define

begin_struct
struct|struct
name|hvm_hw_rtc
block|{
comment|/* CMOS bytes */
name|uint8_t
name|cmos_data
index|[
name|RTC_CMOS_SIZE
index|]
decl_stmt|;
comment|/* Index register for 2-part operations */
name|uint8_t
name|cmos_index
decl_stmt|;
name|uint8_t
name|pad0
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|RTC
argument_list|,
literal|11
argument_list|,
expr|struct
name|hvm_hw_rtc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * HPET  */
end_comment

begin_define
define|#
directive|define
name|HPET_TIMER_NUM
value|3
end_define

begin_comment
comment|/* 3 timers supported now */
end_comment

begin_struct
struct|struct
name|hvm_hw_hpet
block|{
comment|/* Memory-mapped, software visible registers */
name|uint64_t
name|capability
decl_stmt|;
comment|/* capabilities */
name|uint64_t
name|res0
decl_stmt|;
comment|/* reserved */
name|uint64_t
name|config
decl_stmt|;
comment|/* configuration */
name|uint64_t
name|res1
decl_stmt|;
comment|/* reserved */
name|uint64_t
name|isr
decl_stmt|;
comment|/* interrupt status reg */
name|uint64_t
name|res2
index|[
literal|25
index|]
decl_stmt|;
comment|/* reserved */
name|uint64_t
name|mc64
decl_stmt|;
comment|/* main counter */
name|uint64_t
name|res3
decl_stmt|;
comment|/* reserved */
struct|struct
block|{
comment|/* timers */
name|uint64_t
name|config
decl_stmt|;
comment|/* configuration/cap */
name|uint64_t
name|cmp
decl_stmt|;
comment|/* comparator */
name|uint64_t
name|fsb
decl_stmt|;
comment|/* FSB route, not supported now */
name|uint64_t
name|res4
decl_stmt|;
comment|/* reserved */
block|}
name|timers
index|[
name|HPET_TIMER_NUM
index|]
struct|;
name|uint64_t
name|res5
index|[
literal|4
operator|*
operator|(
literal|24
operator|-
name|HPET_TIMER_NUM
operator|)
index|]
decl_stmt|;
comment|/* reserved, up to 0x3ff */
comment|/* Hidden register state */
name|uint64_t
name|period
index|[
name|HPET_TIMER_NUM
index|]
decl_stmt|;
comment|/* Last value written to comparator */
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|HPET
argument_list|,
literal|12
argument_list|,
expr|struct
name|hvm_hw_hpet
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * PM timer  */
end_comment

begin_struct
struct|struct
name|hvm_hw_pmtimer
block|{
name|uint32_t
name|tmr_val
decl_stmt|;
comment|/* PM_TMR_BLK.TMR_VAL: 32bit free-running counter */
name|uint16_t
name|pm1a_sts
decl_stmt|;
comment|/* PM1a_EVT_BLK.PM1a_STS: status register */
name|uint16_t
name|pm1a_en
decl_stmt|;
comment|/* PM1a_EVT_BLK.PM1a_EN: enable register */
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|PMTIMER
argument_list|,
literal|13
argument_list|,
expr|struct
name|hvm_hw_pmtimer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   * Largest type-code in use  */
end_comment

begin_define
define|#
directive|define
name|HVM_SAVE_CODE_MAX
value|13
end_define

begin_comment
comment|/*   * The series of save records is teminated by a zero-type, zero-length   * descriptor.  */
end_comment

begin_struct
struct|struct
name|hvm_save_end
block|{}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|END
argument_list|,
literal|0
argument_list|,
expr|struct
name|hvm_save_end
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_HVM_SAVE_H__ */
end_comment

end_unit

