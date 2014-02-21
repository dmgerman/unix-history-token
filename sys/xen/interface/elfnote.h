begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * elfnote.h  *  * Definitions used for the Xen ELF notes.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2006, Ian Campbell, XenSource Ltd.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ELFNOTE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_ELFNOTE_H__
end_define

begin_comment
comment|/*  * The notes should live in a PT_NOTE segment and have "Xen" in the  * name field.  *  * Numeric types are either 4 or 8 bytes depending on the content of  * the desc field.  *  * LEGACY indicated the fields in the legacy __xen_guest string which  * this a note type replaces.  */
end_comment

begin_comment
comment|/*  * NAME=VALUE pair (string).  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_INFO
value|0
end_define

begin_comment
comment|/*  * The virtual address of the entry point (numeric).  *  * LEGACY: VIRT_ENTRY  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_ENTRY
value|1
end_define

begin_comment
comment|/* The virtual address of the hypercall transfer page (numeric).  *  * LEGACY: HYPERCALL_PAGE. (n.b. legacy value is a physical page  * number not a virtual address)  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_HYPERCALL_PAGE
value|2
end_define

begin_comment
comment|/* The virtual address where the kernel image should be mapped (numeric).  *  * Defaults to 0.  *  * LEGACY: VIRT_BASE  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_VIRT_BASE
value|3
end_define

begin_comment
comment|/*  * The offset of the ELF paddr field from the acutal required  * psuedo-physical address (numeric).  *  * This is used to maintain backwards compatibility with older kernels  * which wrote __PAGE_OFFSET into that field. This field defaults to 0  * if not present.  *  * LEGACY: ELF_PADDR_OFFSET. (n.b. legacy default is VIRT_BASE)  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_PADDR_OFFSET
value|4
end_define

begin_comment
comment|/*  * The version of Xen that we work with (string).  *  * LEGACY: XEN_VER  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_XEN_VERSION
value|5
end_define

begin_comment
comment|/*  * The name of the guest operating system (string).  *  * LEGACY: GUEST_OS  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_GUEST_OS
value|6
end_define

begin_comment
comment|/*  * The version of the guest operating system (string).  *  * LEGACY: GUEST_VER  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_GUEST_VERSION
value|7
end_define

begin_comment
comment|/*  * The loader type (string).  *  * LEGACY: LOADER  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_LOADER
value|8
end_define

begin_comment
comment|/*  * The kernel supports PAE (x86/32 only, string = "yes", "no" or  * "bimodal").  *  * For compatibility with Xen 3.0.3 and earlier the "bimodal" setting  * may be given as "yes,bimodal" which will cause older Xen to treat  * this kernel as PAE.  *  * LEGACY: PAE (n.b. The legacy interface included a provision to  * indicate 'extended-cr3' support allowing L3 page tables to be  * placed above 4G. It is assumed that any kernel new enough to use  * these ELF notes will include this and therefore "yes" here is  * equivalent to "yes[entended-cr3]" in the __xen_guest interface.  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_PAE_MODE
value|9
end_define

begin_comment
comment|/*  * The features supported/required by this kernel (string).  *  * The string must consist of a list of feature names (as given in  * features.h, without the "XENFEAT_" prefix) separated by '|'  * characters. If a feature is required for the kernel to function  * then the feature name must be preceded by a '!' character.  *  * LEGACY: FEATURES  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_FEATURES
value|10
end_define

begin_comment
comment|/*  * The kernel requires the symbol table to be loaded (string = "yes" or "no")  * LEGACY: BSD_SYMTAB (n.b. The legacy treated the presence or absence  * of this string as a boolean flag rather than requiring "yes" or  * "no".  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_BSD_SYMTAB
value|11
end_define

begin_comment
comment|/*  * The lowest address the hypervisor hole can begin at (numeric).  *  * This must not be set higher than HYPERVISOR_VIRT_START. Its presence  * also indicates to the hypervisor that the kernel can deal with the  * hole starting at a higher address.  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_HV_START_LOW
value|12
end_define

begin_comment
comment|/*  * List of maddr_t-sized mask/value pairs describing how to recognize  * (non-present) L1 page table entries carrying valid MFNs (numeric).  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_L1_MFN_VALID
value|13
end_define

begin_comment
comment|/*  * Whether or not the guest supports cooperative suspend cancellation.  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_SUSPEND_CANCEL
value|14
end_define

begin_comment
comment|/*  * The (non-default) location the initial phys-to-machine map should be  * placed at by the hypervisor (Dom0) or the tools (DomU).  * The kernel must be prepared for this mapping to be established using  * large pages, despite such otherwise not being available to guests.  * The kernel must also be able to handle the page table pages used for  * this mapping not being accessible through the initial mapping.  * (Only x86-64 supports this at present.)  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_INIT_P2M
value|15
end_define

begin_comment
comment|/*  * Whether or not the guest can deal with being passed an initrd not  * mapped through its initial page tables.  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_MOD_START_PFN
value|16
end_define

begin_comment
comment|/*  * The features supported by this kernel (numeric).  *  * Other than XEN_ELFNOTE_FEATURES on pre-4.2 Xen, this note allows a  * kernel to specify support for features that older hypervisors don't  * know about. The set of features 4.2 and newer hypervisors will  * consider supported by the kernel is the combination of the sets  * specified through this and the string note.  *  * LEGACY: FEATURES  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_SUPPORTED_FEATURES
value|17
end_define

begin_comment
comment|/*  * The number of the highest elfnote defined.  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_MAX
value|XEN_ELFNOTE_SUPPORTED_FEATURES
end_define

begin_comment
comment|/*  * System information exported through crash notes.  *  * The kexec / kdump code will create one XEN_ELFNOTE_CRASH_INFO   * note in case of a system crash. This note will contain various  * information about the system, see xen/include/xen/elfcore.h.  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_CRASH_INFO
value|0x1000001
end_define

begin_comment
comment|/*  * System registers exported through crash notes.  *  * The kexec / kdump code will create one XEN_ELFNOTE_CRASH_REGS   * note per cpu in case of a system crash. This note is architecture  * specific and will contain registers not saved in the "CORE" note.  * See xen/include/xen/elfcore.h for more information.  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_CRASH_REGS
value|0x1000002
end_define

begin_comment
comment|/*  * xen dump-core none note.  * xm dump-core code will create one XEN_ELFNOTE_DUMPCORE_NONE  * in its dump file to indicate that the file is xen dump-core  * file. This note doesn't have any other information.  * See tools/libxc/xc_core.h for more information.  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_DUMPCORE_NONE
value|0x2000000
end_define

begin_comment
comment|/*  * xen dump-core header note.  * xm dump-core code will create one XEN_ELFNOTE_DUMPCORE_HEADER  * in its dump file.  * See tools/libxc/xc_core.h for more information.  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_DUMPCORE_HEADER
value|0x2000001
end_define

begin_comment
comment|/*  * xen dump-core xen version note.  * xm dump-core code will create one XEN_ELFNOTE_DUMPCORE_XEN_VERSION  * in its dump file. It contains the xen version obtained via the  * XENVER hypercall.  * See tools/libxc/xc_core.h for more information.  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_DUMPCORE_XEN_VERSION
value|0x2000002
end_define

begin_comment
comment|/*  * xen dump-core format version note.  * xm dump-core code will create one XEN_ELFNOTE_DUMPCORE_FORMAT_VERSION  * in its dump file. It contains a format version identifier.  * See tools/libxc/xc_core.h for more information.  */
end_comment

begin_define
define|#
directive|define
name|XEN_ELFNOTE_DUMPCORE_FORMAT_VERSION
value|0x2000003
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_ELFNOTE_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

