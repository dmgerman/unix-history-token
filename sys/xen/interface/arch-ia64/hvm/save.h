begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * save_types.h  *  * Copyright (c) 2007 Isaku Yamahata<yamahata at valinux co jp>  *                    VA Linux Systems Japan K.K.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_HVM_SAVE_IA64_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_HVM_SAVE_IA64_H__
end_define

begin_include
include|#
directive|include
file|"../../hvm/save.h"
end_include

begin_include
include|#
directive|include
file|"../../arch-ia64.h"
end_include

begin_comment
comment|/*   * Save/restore header: general info about the save file.   */
end_comment

begin_comment
comment|/* x86 uses 0x54381286 */
end_comment

begin_define
define|#
directive|define
name|HVM_FILE_MAGIC
value|0x343641492f6e6558UL
end_define

begin_comment
comment|/* "Xen/IA64" */
end_comment

begin_define
define|#
directive|define
name|HVM_FILE_VERSION
value|0x0000000000000001UL
end_define

begin_struct
struct|struct
name|hvm_save_header
block|{
name|uint64_t
name|magic
decl_stmt|;
comment|/* Must be HVM_FILE_MAGIC */
name|uint64_t
name|version
decl_stmt|;
comment|/* File format version */
name|uint64_t
name|changeset
decl_stmt|;
comment|/* Version of Xen that saved this file */
name|uint64_t
name|cpuid
index|[
literal|5
index|]
decl_stmt|;
comment|/* CPUID[0x01][%eax] on the saving machine */
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
comment|/*  * CPU  */
end_comment

begin_struct
struct|struct
name|hvm_hw_ia64_cpu
block|{
name|uint64_t
name|ipsr
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
name|hvm_hw_ia64_cpu
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * CPU  */
end_comment

begin_struct
struct|struct
name|hvm_hw_ia64_vpd
block|{
name|struct
name|vpd
name|vpd
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|VPD
argument_list|,
literal|3
argument_list|,
expr|struct
name|hvm_hw_ia64_vpd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * device dependency  * vacpi => viosapic => vlsapic  */
end_comment

begin_comment
comment|/*  * vlsapic  */
end_comment

begin_struct
struct|struct
name|hvm_hw_ia64_vlsapic
block|{
name|uint64_t
name|insvc
index|[
literal|4
index|]
decl_stmt|;
name|uint64_t
name|vhpi
decl_stmt|;
comment|// ??? should this be saved in vpd
name|uint8_t
name|xtp
decl_stmt|;
name|uint8_t
name|pal_init_pending
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|VLSAPIC
argument_list|,
literal|4
argument_list|,
expr|struct
name|hvm_hw_ia64_vlsapic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* set  * unconditionaly set v->arch.irq_new_peding = 1   * unconditionaly set v->arch.irq_new_condition = 0  */
end_comment

begin_comment
comment|/*  * vtime  */
end_comment

begin_comment
comment|/* itc, itm, itv are saved by arch vcpu context */
end_comment

begin_struct
struct|struct
name|hvm_hw_ia64_vtime
block|{
name|uint64_t
name|itc
decl_stmt|;
name|uint64_t
name|itm
decl_stmt|;
name|uint64_t
name|last_itc
decl_stmt|;
name|uint64_t
name|pending
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|VTIME
argument_list|,
literal|5
argument_list|,
expr|struct
name|hvm_hw_ia64_vtime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * calculate v->vtm.vtm_offset  * ??? Or should vtm_offset be set by leave_hypervisor_tail()?  * start vtm_timer if necessary by vtm_set_itm().  * ??? Or should vtm_timer be set by leave_hypervisor_tail()?  *  * ??? or should be done by schedule_tail()  *        => schedule_tail() should do.  */
end_comment

begin_comment
comment|/*  * viosapic  */
end_comment

begin_define
define|#
directive|define
name|VIOSAPIC_NUM_PINS
value|48
end_define

begin_comment
comment|/* To share VT-d code which uses vioapic_redir_entry.  * Although on ia64 this is for vsapic, but we have to vioapic_redir_entry  * instead of viosapic_redir_entry.  */
end_comment

begin_union
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
name|reserve1
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
name|reserve2
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
name|reserve3
range|:
literal|7
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|dest_id
decl_stmt|;
block|}
name|fields
struct|;
block|}
union|;
end_union

begin_struct
struct|struct
name|hvm_hw_ia64_viosapic
block|{
name|uint64_t
name|irr
decl_stmt|;
name|uint64_t
name|isr
decl_stmt|;
name|uint32_t
name|ioregsel
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
name|uint64_t
name|lowest_vcpu_id
decl_stmt|;
name|uint64_t
name|base_address
decl_stmt|;
name|union
name|vioapic_redir_entry
name|redirtbl
index|[
name|VIOSAPIC_NUM_PINS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|VIOSAPIC
argument_list|,
literal|6
argument_list|,
expr|struct
name|hvm_hw_ia64_viosapic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * vacpi  * PM timer  */
end_comment

begin_struct
struct|struct
name|vacpi_regs
block|{
union|union
block|{
struct|struct
block|{
name|uint32_t
name|pm1a_sts
range|:
literal|16
decl_stmt|;
comment|/* PM1a_EVT_BLK.PM1a_STS: status register */
name|uint32_t
name|pm1a_en
range|:
literal|16
decl_stmt|;
comment|/* PM1a_EVT_BLK.PM1a_EN: enable register */
block|}
struct|;
name|uint32_t
name|evt_blk
decl_stmt|;
block|}
union|;
name|uint32_t
name|tmr_val
decl_stmt|;
comment|/* PM_TMR_BLK.TMR_VAL: 32bit free-running counter */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hvm_hw_ia64_vacpi
block|{
name|struct
name|vacpi_regs
name|regs
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|VACPI
argument_list|,
literal|7
argument_list|,
expr|struct
name|hvm_hw_ia64_vacpi
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* update last_gtime and setup timer of struct vacpi */
end_comment

begin_comment
comment|/*  * opt_feature: identity mapping of region 4, 5 and 7.  * With the c/s 16396:d2935f9c217f of xen-ia64-devel.hg,  * opt_feature hypercall supports only region 4,5,7 identity mappings.  * structure hvm_hw_ia64_identity_mappings only supports them.  * The new structure, struct hvm_hw_ia64_identity_mappings, is created to  * avoid to keep up with change of the xen/ia64 internal structure, struct  * opt_feature.  *  * If it is enhanced in the future, new structure will be created.  */
end_comment

begin_struct
struct|struct
name|hvm_hw_ia64_identity_mapping
block|{
name|uint64_t
name|on
decl_stmt|;
comment|/* on/off */
name|uint64_t
name|pgprot
decl_stmt|;
comment|/* The page protection bit mask of the pte. */
name|uint64_t
name|key
decl_stmt|;
comment|/* A protection key. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hvm_hw_ia64_identity_mappings
block|{
name|struct
name|hvm_hw_ia64_identity_mapping
name|im_reg4
decl_stmt|;
comment|/* Region 4 identity mapping */
name|struct
name|hvm_hw_ia64_identity_mapping
name|im_reg5
decl_stmt|;
comment|/* Region 5 identity mapping */
name|struct
name|hvm_hw_ia64_identity_mapping
name|im_reg7
decl_stmt|;
comment|/* Region 7 identity mapping */
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|OPT_FEATURE_IDENTITY_MAPPINGS
argument_list|,
literal|8
argument_list|,
expr|struct
name|hvm_hw_ia64_identity_mappings
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
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_HVM_SAVE_IA64_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

