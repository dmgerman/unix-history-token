begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, Stefan Esser<se@FreeBSD.ORG>  * Copyright (c) 1997, 1998, 1999, Kenneth D. Merry<ken@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PCIIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PCIIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|PCI_MAXNAMELEN
value|16
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|PCI_GETCONF_LAST_DEVICE
block|,
name|PCI_GETCONF_LIST_CHANGED
block|,
name|PCI_GETCONF_MORE_DEVS
block|,
name|PCI_GETCONF_ERROR
block|}
name|pci_getconf_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PCI_GETCONF_NO_MATCH
init|=
literal|0x00
block|,
name|PCI_GETCONF_MATCH_BUS
init|=
literal|0x01
block|,
name|PCI_GETCONF_MATCH_DEV
init|=
literal|0x02
block|,
name|PCI_GETCONF_MATCH_FUNC
init|=
literal|0x04
block|,
name|PCI_GETCONF_MATCH_NAME
init|=
literal|0x08
block|,
name|PCI_GETCONF_MATCH_UNIT
init|=
literal|0x10
block|,
name|PCI_GETCONF_MATCH_VENDOR
init|=
literal|0x20
block|,
name|PCI_GETCONF_MATCH_DEVICE
init|=
literal|0x40
block|,
name|PCI_GETCONF_MATCH_CLASS
init|=
literal|0x80
block|}
name|pci_getconf_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|pcisel
block|{
name|u_int8_t
name|pc_bus
decl_stmt|;
comment|/* bus number */
name|u_int8_t
name|pc_dev
decl_stmt|;
comment|/* device on this bus */
name|u_int8_t
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
name|u_int8_t
name|pc_hdr
decl_stmt|;
comment|/* PCI header type */
name|u_int16_t
name|pc_subvendor
decl_stmt|;
comment|/* card vendor ID */
name|u_int16_t
name|pc_subdevice
decl_stmt|;
comment|/* card device ID, assigned by  					   card vendor */
name|u_int16_t
name|pc_vendor
decl_stmt|;
comment|/* chip vendor ID */
name|u_int16_t
name|pc_device
decl_stmt|;
comment|/* chip device ID, assigned by  					   chip vendor */
name|u_int8_t
name|pc_class
decl_stmt|;
comment|/* chip PCI class */
name|u_int8_t
name|pc_subclass
decl_stmt|;
comment|/* chip PCI subclass */
name|u_int8_t
name|pc_progif
decl_stmt|;
comment|/* chip PCI programming interface */
name|u_int8_t
name|pc_revid
decl_stmt|;
comment|/* chip revision ID */
name|char
name|pd_name
index|[
name|PCI_MAXNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* device name */
name|u_long
name|pd_unit
decl_stmt|;
comment|/* device unit number */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pci_match_conf
block|{
name|struct
name|pcisel
name|pc_sel
decl_stmt|;
comment|/* bus+slot+function */
name|char
name|pd_name
index|[
name|PCI_MAXNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* device name */
name|u_long
name|pd_unit
decl_stmt|;
comment|/* Unit number */
name|u_int16_t
name|pc_vendor
decl_stmt|;
comment|/* PCI Vendor ID */
name|u_int16_t
name|pc_device
decl_stmt|;
comment|/* PCI Device ID */
name|u_int8_t
name|pc_class
decl_stmt|;
comment|/* PCI class */
name|pci_getconf_flags
name|flags
decl_stmt|;
comment|/* Matching expression */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pci_conf_io
block|{
name|u_int32_t
name|pat_buf_len
decl_stmt|;
comment|/* pattern buffer length */
name|u_int32_t
name|num_patterns
decl_stmt|;
comment|/* number of patterns */
name|struct
name|pci_match_conf
modifier|*
name|patterns
decl_stmt|;
comment|/* pattern buffer */
name|u_int32_t
name|match_buf_len
decl_stmt|;
comment|/* match buffer length */
name|u_int32_t
name|num_matches
decl_stmt|;
comment|/* number of matches returned */
name|struct
name|pci_conf
modifier|*
name|matches
decl_stmt|;
comment|/* match buffer */
name|u_int32_t
name|offset
decl_stmt|;
comment|/* offset into device list */
name|u_int32_t
name|generation
decl_stmt|;
comment|/* device list generation */
name|pci_getconf_status
name|status
decl_stmt|;
comment|/* request status */
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
comment|/* !_SYS_PCIIO_H_ */
end_comment

end_unit

