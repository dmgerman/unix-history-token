begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************  * file: userconfig/uc_main.h  *  * Copyright (c) 1996 Eric L. Hernes (erich@rrnet.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|ISA_BIOTAB
value|0
end_define

begin_define
define|#
directive|define
name|ISA_TTYTAB
value|1
end_define

begin_define
define|#
directive|define
name|ISA_NETTAB
value|2
end_define

begin_define
define|#
directive|define
name|ISA_NULLTAB
value|3
end_define

begin_define
define|#
directive|define
name|ISA_WDCTAB
value|4
end_define

begin_define
define|#
directive|define
name|ISA_FDCTAB
value|5
end_define

begin_define
define|#
directive|define
name|EISA_SET
value|6
end_define

begin_define
define|#
directive|define
name|EISA_LIST
value|7
end_define

begin_define
define|#
directive|define
name|PCI_SET
value|8
end_define

begin_define
define|#
directive|define
name|SCSI_LIST
value|9
end_define

begin_define
define|#
directive|define
name|SCSI_BUSSES
value|10
end_define

begin_define
define|#
directive|define
name|SCSI_CINIT
value|11
end_define

begin_define
define|#
directive|define
name|SCSI_DINIT
value|12
end_define

begin_define
define|#
directive|define
name|SCSI_TINIT
value|13
end_define

begin_comment
comment|/* symbols + the null terminator */
end_comment

begin_define
define|#
directive|define
name|NSYMBOLS
value|15
end_define

begin_struct
struct|struct
name|kernel
block|{
name|int
name|fd
decl_stmt|;
comment|/* file descriptor for the kernel image, either a binary or /dev/kmem */
name|caddr_t
name|core
decl_stmt|;
comment|/* either the mmap()ed kernel image, or a scratch area */
name|u_int
name|size
decl_stmt|;
comment|/* size of the object at ->core */
name|int
name|incore
decl_stmt|;
comment|/* true if the kernel is running */
ifdef|#
directive|ifdef
name|UC_PRIVATE
name|struct
name|nlist
modifier|*
name|nl
decl_stmt|;
comment|/* the symbol table */
else|#
directive|else
name|void
modifier|*
name|nl
decl_stmt|;
endif|#
directive|endif
name|struct
name|uc_isa
modifier|*
name|isa_devp
decl_stmt|;
comment|/* pointer to the isa devices (if any) */
name|struct
name|uc_eisa
modifier|*
name|eisa_devp
decl_stmt|;
comment|/* pointer to the eisa devices (if any) */
name|struct
name|uc_pci
modifier|*
name|pci_devp
decl_stmt|;
comment|/* pointer to the pci devices (if any) */
name|struct
name|uc_scsi
modifier|*
name|scsi_devp
decl_stmt|;
comment|/* pointer to the scsi devices (if any) */
name|struct
name|uc_scsibus
modifier|*
name|scsibus_devp
decl_stmt|;
comment|/* internal pointer to scsibus wirings */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uc_isa
block|{
name|char
modifier|*
name|device
decl_stmt|;
name|u_short
name|port
decl_stmt|;
name|u_short
name|irq
decl_stmt|;
name|short
name|drq
decl_stmt|;
name|u_int
name|iomem
decl_stmt|;
name|int
name|iosize
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|alive
decl_stmt|;
name|int
name|enabled
decl_stmt|;
ifdef|#
directive|ifdef
name|UC_PRIVATE
name|struct
name|isa_device
modifier|*
name|idp
decl_stmt|;
else|#
directive|else
name|void
modifier|*
name|idp
decl_stmt|;
endif|#
directive|endif
name|int
name|modified
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uc_pci
block|{
name|char
modifier|*
name|device
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uc_eisa
block|{
name|char
modifier|*
name|device
decl_stmt|;
name|char
modifier|*
name|full_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uc_scsibus
block|{
name|int
name|bus_no
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|char
modifier|*
name|driver
decl_stmt|;
ifdef|#
directive|ifdef
name|UC_PRIVATE
name|struct
name|scsi_ctlr_config
modifier|*
name|config
decl_stmt|;
else|#
directive|else
name|void
modifier|*
name|config
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uc_scsi
block|{
name|char
modifier|*
name|device
decl_stmt|;
name|char
modifier|*
name|adapter
decl_stmt|;
name|u_short
name|target
decl_stmt|;
name|u_short
name|lun
decl_stmt|;
name|char
modifier|*
name|desc
decl_stmt|;
ifdef|#
directive|ifdef
name|UC_PRIVATE
name|struct
name|scsi_device_config
modifier|*
name|config
decl_stmt|;
else|#
directive|else
name|void
modifier|*
name|config
decl_stmt|;
endif|#
directive|endif
name|int
name|modified
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* nearly everything useful returns a list */
end_comment

begin_struct
struct|struct
name|list
block|{
name|int
name|ac
decl_stmt|;
name|char
modifier|*
modifier|*
name|av
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_comment
comment|/* uc_main.c */
end_comment

begin_comment
comment|/* these are really the only public ones */
end_comment

begin_function_decl
name|struct
name|kernel
modifier|*
name|uc_open
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uc_close
parameter_list|(
name|struct
name|kernel
modifier|*
name|kern
parameter_list|,
name|int
name|writeback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|list
modifier|*
name|uc_getdev
parameter_list|(
name|struct
name|kernel
modifier|*
name|kern
parameter_list|,
name|char
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uc_isa.c */
end_comment

begin_function_decl
name|void
name|get_isa_info
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|list
modifier|*
name|get_isa_devlist
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|list
modifier|*
name|get_isa_device
parameter_list|(
name|struct
name|uc_isa
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isa_setdev
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|,
name|struct
name|list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isa_free
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|,
name|int
name|writeback
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uc_eisa.c */
end_comment

begin_function_decl
name|void
name|get_eisa_info
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|list
modifier|*
name|get_eisa_devlist
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|list
modifier|*
name|get_eisa_device
parameter_list|(
name|struct
name|uc_eisa
modifier|*
name|ep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eisa_free
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|,
name|int
name|writeback
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uc_pci.c */
end_comment

begin_function_decl
name|void
name|get_pci_info
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|list
modifier|*
name|get_pci_devlist
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|list
modifier|*
name|get_pci_device
parameter_list|(
name|struct
name|uc_pci
modifier|*
name|pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pci_free
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|,
name|int
name|writeback
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uc_scsi.c */
end_comment

begin_function_decl
name|void
name|get_scsi_info
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|list
modifier|*
name|get_scsi_devlist
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|list
modifier|*
name|get_scsi_device
parameter_list|(
name|struct
name|uc_scsi
modifier|*
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scsi_setdev
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|,
name|struct
name|list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scsi_free
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|,
name|int
name|writeback
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uc_kmem.c */
end_comment

begin_function_decl
name|u_int
name|kv_to_u
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|,
name|u_int
name|adr
parameter_list|,
name|u_int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|kv_dref_p
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|,
name|u_int
name|adr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|kv_dref_t
parameter_list|(
name|struct
name|kernel
modifier|*
name|kp
parameter_list|,
name|u_int
name|adr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uc_list.c */
end_comment

begin_function_decl
name|struct
name|list
modifier|*
name|list_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|list_append
parameter_list|(
name|struct
name|list
modifier|*
name|list
parameter_list|,
name|char
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|list_print
parameter_list|(
name|struct
name|list
modifier|*
name|list
parameter_list|,
name|char
modifier|*
name|separator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|list_destroy
parameter_list|(
name|struct
name|list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* end of userconfig/uc_main.h */
end_comment

end_unit

