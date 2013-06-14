begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * PCI Backend/Frontend Common Data Structures& Macros  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  *   Author: Ryan Wilson<hap9@epoch.ncsc.mil>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PCI_COMMON_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PCI_COMMON_H__
end_define

begin_comment
comment|/* Be sure to bump this number if you change this file */
end_comment

begin_define
define|#
directive|define
name|XEN_PCI_MAGIC
value|"7"
end_define

begin_comment
comment|/* xen_pci_sharedinfo flags */
end_comment

begin_define
define|#
directive|define
name|_XEN_PCIF_active
value|(0)
end_define

begin_define
define|#
directive|define
name|XEN_PCIF_active
value|(1<<_XEN_PCIF_active)
end_define

begin_define
define|#
directive|define
name|_XEN_PCIB_AERHANDLER
value|(1)
end_define

begin_define
define|#
directive|define
name|XEN_PCIB_AERHANDLER
value|(1<<_XEN_PCIB_AERHANDLER)
end_define

begin_define
define|#
directive|define
name|_XEN_PCIB_active
value|(2)
end_define

begin_define
define|#
directive|define
name|XEN_PCIB_active
value|(1<<_XEN_PCIB_active)
end_define

begin_comment
comment|/* xen_pci_op commands */
end_comment

begin_define
define|#
directive|define
name|XEN_PCI_OP_conf_read
value|(0)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_OP_conf_write
value|(1)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_OP_enable_msi
value|(2)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_OP_disable_msi
value|(3)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_OP_enable_msix
value|(4)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_OP_disable_msix
value|(5)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_OP_aer_detected
value|(6)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_OP_aer_resume
value|(7)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_OP_aer_mmio
value|(8)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_OP_aer_slotreset
value|(9)
end_define

begin_comment
comment|/* xen_pci_op error numbers */
end_comment

begin_define
define|#
directive|define
name|XEN_PCI_ERR_success
value|(0)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_ERR_dev_not_found
value|(-1)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_ERR_invalid_offset
value|(-2)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_ERR_access_denied
value|(-3)
end_define

begin_define
define|#
directive|define
name|XEN_PCI_ERR_not_implemented
value|(-4)
end_define

begin_comment
comment|/* XEN_PCI_ERR_op_failed - backend failed to complete the operation */
end_comment

begin_define
define|#
directive|define
name|XEN_PCI_ERR_op_failed
value|(-5)
end_define

begin_comment
comment|/*  * it should be PAGE_SIZE-sizeof(struct xen_pci_op))/sizeof(struct msix_entry))  * Should not exceed 128  */
end_comment

begin_define
define|#
directive|define
name|SH_INFO_MAX_VEC
value|128
end_define

begin_struct
struct|struct
name|xen_msix_entry
block|{
name|uint16_t
name|vector
decl_stmt|;
name|uint16_t
name|entry
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_pci_op
block|{
comment|/* IN: what action to perform: XEN_PCI_OP_* */
name|uint32_t
name|cmd
decl_stmt|;
comment|/* OUT: will contain an error number (if any) from errno.h */
name|int32_t
name|err
decl_stmt|;
comment|/* IN: which device to touch */
name|uint32_t
name|domain
decl_stmt|;
comment|/* PCI Domain/Segment */
name|uint32_t
name|bus
decl_stmt|;
name|uint32_t
name|devfn
decl_stmt|;
comment|/* IN: which configuration registers to touch */
name|int32_t
name|offset
decl_stmt|;
name|int32_t
name|size
decl_stmt|;
comment|/* IN/OUT: Contains the result after a READ or the value to WRITE */
name|uint32_t
name|value
decl_stmt|;
comment|/* IN: Contains extra infor for this operation */
name|uint32_t
name|info
decl_stmt|;
comment|/*IN:  param for msi-x */
name|struct
name|xen_msix_entry
name|msix_entries
index|[
name|SH_INFO_MAX_VEC
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*used for pcie aer handling*/
end_comment

begin_struct
struct|struct
name|xen_pcie_aer_op
block|{
comment|/* IN: what action to perform: XEN_PCI_OP_* */
name|uint32_t
name|cmd
decl_stmt|;
comment|/*IN/OUT: return aer_op result or carry error_detected state as input*/
name|int32_t
name|err
decl_stmt|;
comment|/* IN: which device to touch */
name|uint32_t
name|domain
decl_stmt|;
comment|/* PCI Domain/Segment*/
name|uint32_t
name|bus
decl_stmt|;
name|uint32_t
name|devfn
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_pci_sharedinfo
block|{
comment|/* flags - XEN_PCIF_* */
name|uint32_t
name|flags
decl_stmt|;
name|struct
name|xen_pci_op
name|op
decl_stmt|;
name|struct
name|xen_pcie_aer_op
name|aer_op
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PCI_COMMON_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

