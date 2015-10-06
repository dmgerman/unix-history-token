begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * kexec.h - Public portion  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *   * Xen port written by:  * - Simon 'Horms' Horman<horms@verge.net.au>  * - Magnus Damm<magnus@valinux.co.jp>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_PUBLIC_KEXEC_H
end_ifndef

begin_define
define|#
directive|define
name|_XEN_PUBLIC_KEXEC_H
end_define

begin_comment
comment|/* This file describes the Kexec / Kdump hypercall interface for Xen.  *  * Kexec under vanilla Linux allows a user to reboot the physical machine   * into a new user-specified kernel. The Xen port extends this idea  * to allow rebooting of the machine from dom0. When kexec for dom0  * is used to reboot,  both the hypervisor and the domains get replaced  * with some other kernel. It is possible to kexec between vanilla  * Linux and Xen and back again. Xen to Xen works well too.  *  * The hypercall interface for kexec can be divided into three main  * types of hypercall operations:  *  * 1) Range information:  *    This is used by the dom0 kernel to ask the hypervisor about various   *    address information. This information is needed to allow kexec-tools   *    to fill in the ELF headers for /proc/vmcore properly.  *  * 2) Load and unload of images:  *    There are no big surprises here, the kexec binary from kexec-tools  *    runs in userspace in dom0. The tool loads/unloads data into the  *    dom0 kernel such as new kernel, initramfs and hypervisor. When  *    loaded the dom0 kernel performs a load hypercall operation, and  *    before releasing all page references the dom0 kernel calls unload.  *  * 3) Kexec operation:  *    This is used to start a previously loaded kernel.  */
end_comment

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|KEXEC_XEN_NO_PAGES
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Prototype for this hypercall is:  *  int kexec_op(int cmd, void *args)  * @cmd  == KEXEC_CMD_...   *          KEXEC operation to perform  * @args == Operation-specific extra arguments (NULL if none).  */
end_comment

begin_comment
comment|/*  * Kexec supports two types of operation:  * - kexec into a regular kernel, very similar to a standard reboot  *   - KEXEC_TYPE_DEFAULT is used to specify this type  * - kexec into a special "crash kernel", aka kexec-on-panic  *   - KEXEC_TYPE_CRASH is used to specify this type  *   - parts of our system may be broken at kexec-on-panic time  *     - the code should be kept as simple and self-contained as possible  */
end_comment

begin_define
define|#
directive|define
name|KEXEC_TYPE_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|KEXEC_TYPE_CRASH
value|1
end_define

begin_comment
comment|/* The kexec implementation for Xen allows the user to load two  * types of kernels, KEXEC_TYPE_DEFAULT and KEXEC_TYPE_CRASH.  * All data needed for a kexec reboot is kept in one xen_kexec_image_t  * per "instance". The data mainly consists of machine address lists to pages  * together with destination addresses. The data in xen_kexec_image_t  * is passed to the "code page" which is one page of code that performs  * the final relocations before jumping to the new kernel.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xen_kexec_image
block|{
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
name|unsigned
name|long
name|page_list
index|[
name|KEXEC_XEN_NO_PAGES
index|]
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|long
name|indirection_page
decl_stmt|;
name|unsigned
name|long
name|start_address
decl_stmt|;
block|}
name|xen_kexec_image_t
typedef|;
end_typedef

begin_comment
comment|/*  * Perform kexec having previously loaded a kexec or kdump kernel  * as appropriate.  * type == KEXEC_TYPE_DEFAULT or KEXEC_TYPE_CRASH [in]  *  * Control is transferred to the image entry point with the host in  * the following state.  *  * - The image may be executed on any PCPU and all other PCPUs are  *   stopped.  *  * - Local interrupts are disabled.  *  * - Register values are undefined.  *  * - The image segments have writeable 1:1 virtual to machine  *   mappings.  The location of any page tables is undefined and these  *   page table frames are not be mapped.  */
end_comment

begin_define
define|#
directive|define
name|KEXEC_CMD_kexec
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
name|xen_kexec_exec
block|{
name|int
name|type
decl_stmt|;
block|}
name|xen_kexec_exec_t
typedef|;
end_typedef

begin_comment
comment|/*  * Load/Unload kernel image for kexec or kdump.  * type  == KEXEC_TYPE_DEFAULT or KEXEC_TYPE_CRASH [in]  * image == relocation information for kexec (ignored for unload) [in]  */
end_comment

begin_define
define|#
directive|define
name|KEXEC_CMD_kexec_load_v1
value|1
end_define

begin_comment
comment|/* obsolete since 0x00040400 */
end_comment

begin_define
define|#
directive|define
name|KEXEC_CMD_kexec_unload_v1
value|2
end_define

begin_comment
comment|/* obsolete since 0x00040400 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xen_kexec_load_v1
block|{
name|int
name|type
decl_stmt|;
name|xen_kexec_image_t
name|image
decl_stmt|;
block|}
name|xen_kexec_load_v1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KEXEC_RANGE_MA_CRASH
value|0
end_define

begin_comment
comment|/* machine address and size of crash area */
end_comment

begin_define
define|#
directive|define
name|KEXEC_RANGE_MA_XEN
value|1
end_define

begin_comment
comment|/* machine address and size of Xen itself */
end_comment

begin_define
define|#
directive|define
name|KEXEC_RANGE_MA_CPU
value|2
end_define

begin_comment
comment|/* machine address and size of a CPU note */
end_comment

begin_define
define|#
directive|define
name|KEXEC_RANGE_MA_XENHEAP
value|3
end_define

begin_comment
comment|/* machine address and size of xenheap                                      * Note that although this is adjacent                                      * to Xen it exists in a separate EFI                                      * region on ia64, and thus needs to be                                      * inserted into iomem_machine separately */
end_comment

begin_define
define|#
directive|define
name|KEXEC_RANGE_MA_BOOT_PARAM
value|4
end_define

begin_comment
comment|/* Obsolete: machine address and size of                                      * the ia64_boot_param */
end_comment

begin_define
define|#
directive|define
name|KEXEC_RANGE_MA_EFI_MEMMAP
value|5
end_define

begin_comment
comment|/* machine address and size of                                      * of the EFI Memory Map */
end_comment

begin_define
define|#
directive|define
name|KEXEC_RANGE_MA_VMCOREINFO
value|6
end_define

begin_comment
comment|/* machine address and size of vmcoreinfo */
end_comment

begin_comment
comment|/*  * Find the address and size of certain memory areas  * range == KEXEC_RANGE_... [in]  * nr    == physical CPU number (starting from 0) if KEXEC_RANGE_MA_CPU [in]  * size  == number of bytes reserved in window [out]  * start == address of the first byte in the window [out]  */
end_comment

begin_define
define|#
directive|define
name|KEXEC_CMD_kexec_get_range
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|xen_kexec_range
block|{
name|int
name|range
decl_stmt|;
name|int
name|nr
decl_stmt|;
name|unsigned
name|long
name|size
decl_stmt|;
name|unsigned
name|long
name|start
decl_stmt|;
block|}
name|xen_kexec_range_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|>=
literal|0x00040400
end_if

begin_comment
comment|/*  * A contiguous chunk of a kexec image and it's destination machine  * address.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xen_kexec_segment
block|{
union|union
block|{
name|XEN_GUEST_HANDLE
argument_list|(
argument|const_void
argument_list|)
name|h
expr_stmt|;
name|uint64_t
name|_pad
decl_stmt|;
block|}
name|buf
union|;
name|uint64_t
name|buf_size
decl_stmt|;
name|uint64_t
name|dest_maddr
decl_stmt|;
name|uint64_t
name|dest_size
decl_stmt|;
block|}
name|xen_kexec_segment_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_kexec_segment_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Load a kexec image into memory.  *  * For KEXEC_TYPE_DEFAULT images, the segments may be anywhere in RAM.  * The image is relocated prior to being executed.  *  * For KEXEC_TYPE_CRASH images, each segment of the image must reside  * in the memory region reserved for kexec (KEXEC_RANGE_MA_CRASH) and  * the entry point must be within the image. The caller is responsible  * for ensuring that multiple images do not overlap.  *  * All image segments will be loaded to their destination machine  * addresses prior to being executed.  The trailing portion of any  * segments with a source buffer (from dest_maddr + buf_size to  * dest_maddr + dest_size) will be zeroed.  *  * Segments with no source buffer will be accessible to the image when  * it is executed.  */
end_comment

begin_define
define|#
directive|define
name|KEXEC_CMD_kexec_load
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|xen_kexec_load
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* One of KEXEC_TYPE_* */
name|uint8_t
name|_pad
decl_stmt|;
name|uint16_t
name|arch
decl_stmt|;
comment|/* ELF machine type (EM_*). */
name|uint32_t
name|nr_segments
decl_stmt|;
union|union
block|{
name|XEN_GUEST_HANDLE
argument_list|(
argument|xen_kexec_segment_t
argument_list|)
name|h
expr_stmt|;
name|uint64_t
name|_pad
decl_stmt|;
block|}
name|segments
union|;
name|uint64_t
name|entry_maddr
decl_stmt|;
comment|/* image entry point machine address. */
block|}
name|xen_kexec_load_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_kexec_load_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Unload a kexec image.  *  * Type must be one of KEXEC_TYPE_DEFAULT or KEXEC_TYPE_CRASH.  */
end_comment

begin_define
define|#
directive|define
name|KEXEC_CMD_kexec_unload
value|5
end_define

begin_typedef
typedef|typedef
struct|struct
name|xen_kexec_unload
block|{
name|uint8_t
name|type
decl_stmt|;
block|}
name|xen_kexec_unload_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_kexec_unload_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __XEN_INTERFACE_VERSION__< 0x00040400 */
end_comment

begin_define
define|#
directive|define
name|KEXEC_CMD_kexec_load
value|KEXEC_CMD_kexec_load_v1
end_define

begin_define
define|#
directive|define
name|KEXEC_CMD_kexec_unload
value|KEXEC_CMD_kexec_unload_v1
end_define

begin_define
define|#
directive|define
name|xen_kexec_load
value|xen_kexec_load_v1
end_define

begin_define
define|#
directive|define
name|xen_kexec_load_t
value|xen_kexec_load_v1_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEN_PUBLIC_KEXEC_H */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-file-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

