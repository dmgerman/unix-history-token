begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * platform.h  *   * Hardware platform operations. Intended for use by domain-0 kernel.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2002-2006, K Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_PLATFORM_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_PLATFORM_H__
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_define
define|#
directive|define
name|XENPF_INTERFACE_VERSION
value|0x03000001
end_define

begin_comment
comment|/*  * Set clock such that it would read<secs,nsecs> after 00:00:00 UTC,  * 1 January, 1970 if the current system time was<system_time>.  */
end_comment

begin_define
define|#
directive|define
name|XENPF_settime
value|17
end_define

begin_struct
struct|struct
name|xenpf_settime
block|{
comment|/* IN variables. */
name|uint32_t
name|secs
decl_stmt|;
name|uint32_t
name|nsecs
decl_stmt|;
name|uint64_t
name|system_time
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xenpf_settime
name|xenpf_settime_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenpf_settime_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Request memory range (@mfn, @mfn+@nr_mfns-1) to have type @type.  * On x86, @type is an architecture-defined MTRR memory type.  * On success, returns the MTRR that was used (@reg) and a handle that can  * be passed to XENPF_DEL_MEMTYPE to accurately tear down the new setting.  * (x86-specific).  */
end_comment

begin_define
define|#
directive|define
name|XENPF_add_memtype
value|31
end_define

begin_struct
struct|struct
name|xenpf_add_memtype
block|{
comment|/* IN variables. */
name|xen_pfn_t
name|mfn
decl_stmt|;
name|uint64_t
name|nr_mfns
decl_stmt|;
name|uint32_t
name|type
decl_stmt|;
comment|/* OUT variables. */
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|reg
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xenpf_add_memtype
name|xenpf_add_memtype_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenpf_add_memtype_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Tear down an existing memory-range type. If @handle is remembered then it  * should be passed in to accurately tear down the correct setting (in case  * of overlapping memory regions with differing types). If it is not known  * then @handle should be set to zero. In all cases @reg must be set.  * (x86-specific).  */
end_comment

begin_define
define|#
directive|define
name|XENPF_del_memtype
value|32
end_define

begin_struct
struct|struct
name|xenpf_del_memtype
block|{
comment|/* IN variables. */
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|reg
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xenpf_del_memtype
name|xenpf_del_memtype_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenpf_del_memtype_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Read current type of an MTRR (x86-specific). */
end_comment

begin_define
define|#
directive|define
name|XENPF_read_memtype
value|33
end_define

begin_struct
struct|struct
name|xenpf_read_memtype
block|{
comment|/* IN variables. */
name|uint32_t
name|reg
decl_stmt|;
comment|/* OUT variables. */
name|xen_pfn_t
name|mfn
decl_stmt|;
name|uint64_t
name|nr_mfns
decl_stmt|;
name|uint32_t
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xenpf_read_memtype
name|xenpf_read_memtype_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenpf_read_memtype_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XENPF_microcode_update
value|35
end_define

begin_struct
struct|struct
name|xenpf_microcode_update
block|{
comment|/* IN variables. */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* Pointer to microcode data */
name|uint32_t
name|length
decl_stmt|;
comment|/* Length of microcode data. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xenpf_microcode_update
name|xenpf_microcode_update_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenpf_microcode_update_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XENPF_platform_quirk
value|39
end_define

begin_define
define|#
directive|define
name|QUIRK_NOIRQBALANCING
value|1
end_define

begin_comment
comment|/* Do not restrict IO-APIC RTE targets */
end_comment

begin_define
define|#
directive|define
name|QUIRK_IOAPIC_BAD_REGSEL
value|2
end_define

begin_comment
comment|/* IO-APIC REGSEL forgets its value    */
end_comment

begin_define
define|#
directive|define
name|QUIRK_IOAPIC_GOOD_REGSEL
value|3
end_define

begin_comment
comment|/* IO-APIC REGSEL behaves properly     */
end_comment

begin_struct
struct|struct
name|xenpf_platform_quirk
block|{
comment|/* IN variables. */
name|uint32_t
name|quirk_id
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xenpf_platform_quirk
name|xenpf_platform_quirk_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenpf_platform_quirk_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XENPF_firmware_info
value|50
end_define

begin_define
define|#
directive|define
name|XEN_FW_DISK_INFO
value|1
end_define

begin_comment
comment|/* from int 13 AH=08/41/48 */
end_comment

begin_define
define|#
directive|define
name|XEN_FW_DISK_MBR_SIGNATURE
value|2
end_define

begin_comment
comment|/* from MBR offset 0x1b8 */
end_comment

begin_define
define|#
directive|define
name|XEN_FW_VBEDDC_INFO
value|3
end_define

begin_comment
comment|/* from int 10 AX=4f15 */
end_comment

begin_struct
struct|struct
name|xenpf_firmware_info
block|{
comment|/* IN variables. */
name|uint32_t
name|type
decl_stmt|;
name|uint32_t
name|index
decl_stmt|;
comment|/* OUT variables. */
union|union
block|{
struct|struct
block|{
comment|/* Int13, Fn48: Check Extensions Present. */
name|uint8_t
name|device
decl_stmt|;
comment|/* %dl: bios device number */
name|uint8_t
name|version
decl_stmt|;
comment|/* %ah: major version      */
name|uint16_t
name|interface_support
decl_stmt|;
comment|/* %cx: support bitmap     */
comment|/* Int13, Fn08: Legacy Get Device Parameters. */
name|uint16_t
name|legacy_max_cylinder
decl_stmt|;
comment|/* %cl[7:6]:%ch: max cyl # */
name|uint8_t
name|legacy_max_head
decl_stmt|;
comment|/* %dh: max head #         */
name|uint8_t
name|legacy_sectors_per_track
decl_stmt|;
comment|/* %cl[5:0]: max sector #  */
comment|/* Int13, Fn41: Get Device Parameters (as filled into %ds:%esi). */
comment|/* NB. First uint16_t of buffer must be set to buffer size.      */
name|void
modifier|*
name|edd_params
decl_stmt|;
block|}
name|disk_info
struct|;
comment|/* XEN_FW_DISK_INFO */
struct|struct
block|{
name|uint8_t
name|device
decl_stmt|;
comment|/* bios device number  */
name|uint32_t
name|mbr_signature
decl_stmt|;
comment|/* offset 0x1b8 in mbr */
block|}
name|disk_mbr_signature
struct|;
comment|/* XEN_FW_DISK_MBR_SIGNATURE */
struct|struct
block|{
comment|/* Int10, AX=4F15: Get EDID info. */
name|uint8_t
name|capabilities
decl_stmt|;
name|uint8_t
name|edid_transfer_time
decl_stmt|;
comment|/* must refer to 128-byte buffer */
name|XEN_GUEST_HANDLE
argument_list|(
argument|uint8_t
argument_list|)
name|edid
expr_stmt|;
block|}
name|vbeddc_info
struct|;
comment|/* XEN_FW_VBEDDC_INFO */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xenpf_firmware_info
name|xenpf_firmware_info_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenpf_firmware_info_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_platform_op
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|interface_version
decl_stmt|;
comment|/* XENPF_INTERFACE_VERSION */
union|union
block|{
name|struct
name|xenpf_settime
name|settime
decl_stmt|;
name|struct
name|xenpf_add_memtype
name|add_memtype
decl_stmt|;
name|struct
name|xenpf_del_memtype
name|del_memtype
decl_stmt|;
name|struct
name|xenpf_read_memtype
name|read_memtype
decl_stmt|;
name|struct
name|xenpf_microcode_update
name|microcode
decl_stmt|;
name|struct
name|xenpf_platform_quirk
name|platform_quirk
decl_stmt|;
name|struct
name|xenpf_firmware_info
name|firmware_info
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|128
index|]
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_platform_op
name|xen_platform_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_platform_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_PLATFORM_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

