begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_IOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|_PCI_IOCTL_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|pcisel
block|{
name|u_char
name|pc_bus
decl_stmt|;
comment|/* bus number */
name|u_char
name|pc_dev
decl_stmt|;
comment|/* device on this bus */
name|u_char
name|pc_func
decl_stmt|;
comment|/* function on this device */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pci_conf
block|{
name|struct
name|pcisel
name|pc_sel
decl_stmt|;
comment|/* bus+slot+function */
name|u_char
name|pc_hdr
decl_stmt|;
comment|/* PCI header type */
name|pcidi_t
name|pc_devid
decl_stmt|;
comment|/* device ID */
name|pcidi_t
name|pc_subid
decl_stmt|;
comment|/* subvendor ID */
name|u_int32_t
name|pc_class
decl_stmt|;
comment|/* device class */
name|struct
name|pci_device
modifier|*
name|pc_dvp
decl_stmt|;
comment|/* device driver pointer or NULL */
name|struct
name|pcicb
modifier|*
name|pc_cb
decl_stmt|;
comment|/* pointer to bus parameters */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pci_conf_io
block|{
name|size_t
name|pci_len
decl_stmt|;
comment|/* length of buffer */
name|struct
name|pci_conf
modifier|*
name|pci_buf
decl_stmt|;
comment|/* buffer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pci_io
block|{
name|struct
name|pcisel
name|pi_sel
decl_stmt|;
comment|/* device to operate on */
name|int
name|pi_reg
decl_stmt|;
comment|/* configuration register to examine */
name|int
name|pi_width
decl_stmt|;
comment|/* width (in bytes) of read or write */
name|u_int32_t
name|pi_data
decl_stmt|;
comment|/* data to write or result of read */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PCIOCGETCONF
value|_IOWR('p', 1, struct pci_conf_io)
end_define

begin_define
define|#
directive|define
name|PCIOCREAD
value|_IOWR('p', 2, struct pci_io)
end_define

begin_define
define|#
directive|define
name|PCIOCWRITE
value|_IOWR('p', 3, struct pci_io)
end_define

begin_define
define|#
directive|define
name|PCIOCATTACHED
value|_IOWR('p', 4, struct pci_io)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCI_IOCTL_H */
end_comment

end_unit

