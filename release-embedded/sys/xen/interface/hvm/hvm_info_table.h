begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * hvm/hvm_info_table.h  *   * HVM parameter and information table, written into guest memory map.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_HVM_HVM_INFO_TABLE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_HVM_HVM_INFO_TABLE_H__
end_define

begin_define
define|#
directive|define
name|HVM_INFO_PFN
value|0x09F
end_define

begin_define
define|#
directive|define
name|HVM_INFO_OFFSET
value|0x800
end_define

begin_define
define|#
directive|define
name|HVM_INFO_PADDR
value|((HVM_INFO_PFN<< 12) + HVM_INFO_OFFSET)
end_define

begin_comment
comment|/* Maximum we can support with current vLAPIC ID mapping. */
end_comment

begin_define
define|#
directive|define
name|HVM_MAX_VCPUS
value|128
end_define

begin_struct
struct|struct
name|hvm_info_table
block|{
name|char
name|signature
index|[
literal|8
index|]
decl_stmt|;
comment|/* "HVM INFO" */
name|uint32_t
name|length
decl_stmt|;
name|uint8_t
name|checksum
decl_stmt|;
comment|/* Should firmware build APIC descriptors (APIC MADT / MP BIOS)? */
name|uint8_t
name|apic_mode
decl_stmt|;
comment|/* How many CPUs does this domain have? */
name|uint32_t
name|nr_vcpus
decl_stmt|;
comment|/*      * MEMORY MAP provided by HVM domain builder.      * Notes:      *  1. page_to_phys(x) = x<< 12      *  2. If a field is zero, the corresponding range does not exist.      */
comment|/*      *  0x0 to page_to_phys(low_mem_pgend)-1:      *    RAM below 4GB (except for VGA hole 0xA0000-0xBFFFF)      */
name|uint32_t
name|low_mem_pgend
decl_stmt|;
comment|/*      *  page_to_phys(reserved_mem_pgstart) to 0xFFFFFFFF:      *    Reserved for special memory mappings      */
name|uint32_t
name|reserved_mem_pgstart
decl_stmt|;
comment|/*      *  0x100000000 to page_to_phys(high_mem_pgend)-1:      *    RAM above 4GB      */
name|uint32_t
name|high_mem_pgend
decl_stmt|;
comment|/* Bitmap of which CPUs are online at boot time. */
name|uint8_t
name|vcpu_online
index|[
operator|(
name|HVM_MAX_VCPUS
operator|+
literal|7
operator|)
operator|/
literal|8
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
comment|/* __XEN_PUBLIC_HVM_HVM_INFO_TABLE_H__ */
end_comment

end_unit

