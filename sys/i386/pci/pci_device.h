begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** ** **  $Id: pci_device.h,v 1.5 1994/09/28 16:34:10 se Exp $ ** **  #define   for pci based device drivers ** **  386bsd / FreeBSD ** **------------------------------------------------------------------------- ** ** Copyright (c) 1994 Wolfgang Stanglmeier.  All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions ** are met: ** 1. Redistributions of source code must retain the above copyright **    notice, this list of conditions and the following disclaimer. ** 2. Redistributions in binary form must reproduce the above copyright **    notice, this list of conditions and the following disclaimer in the **    documentation and/or other materials provided with the distribution. ** 3. The name of the author may not be used to endorse or promote products **    derived from this software without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR ** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES ** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. ** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, ** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT ** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF ** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** **------------------------------------------------------------------------- */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCI_DEVICE_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCI_DEVICE_H__
end_define

begin_comment
comment|/*------------------------------------------------------------ ** **  Per driver structure. ** **------------------------------------------------------------ */
end_comment

begin_struct
struct|struct
name|pci_driver
block|{
name|int
function_decl|(
modifier|*
name|probe
function_decl|)
parameter_list|(
name|pcici_t
name|pci_ident
parameter_list|)
function_decl|;
comment|/* test whether device is present */
name|int
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|pcici_t
name|pci_ident
parameter_list|)
function_decl|;
comment|/* setup driver for a device */
name|pcidi_t
name|device_id
decl_stmt|;
comment|/* device pci id */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* device (long) name */
name|int
function_decl|(
modifier|*
name|intr
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* interupt handler */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------- ** **  Per device structure. ** **  It is initialized by the config utility and should live in **  "ioconf.c". At the moment there is only one field. ** **  This is a first attempt to include the pci bus to 386bsd. **  So this structure may grow .. ** **  Extended by Garrett Wollman<wollman@halloran-eldar.lcs.mit.edu> **  for future loadable drivers . ** **----------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|pci_device
block|{
name|struct
name|pci_driver
modifier|*
name|pd_driver
decl_stmt|;
name|pcidi_t
name|pd_device_id
decl_stmt|;
comment|/* device pci id */
specifier|const
name|char
modifier|*
name|pd_name
decl_stmt|;
comment|/* for future loadable drivers */
name|int
name|pd_flags
decl_stmt|;
name|int
name|pd_npresent
decl_stmt|;
comment|/* for future loadable drivers */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PDF_LOADABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|PDF_COVERED
value|0x02
end_define

begin_comment
comment|/*----------------------------------------------------------- ** **  This table should be generated in file "ioconf.c" **  by the config program. **  It is used at boot time by the configuration function **  pci_configure() ** **----------------------------------------------------------- */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pci_device
name|pci_devtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*----------------------------------------------------------- ** **  This functions may be used by drivers to map devices **  to virtual and physical addresses. The va and pa **  addresses are "in/out" parameters. If they are 0 **  on entry, the mapping function assigns an address. ** **----------------------------------------------------------- */
end_comment

begin_function_decl
name|int
name|pci_map_mem
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|u_long
name|entry
parameter_list|,
name|u_long
modifier|*
name|va
parameter_list|,
name|u_long
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_map_port
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|u_long
name|entry
parameter_list|,
name|u_short
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__PCI_DEVICE_H__*/
end_comment

end_unit

