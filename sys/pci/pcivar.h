begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** ** **  $Id: pcireg.h,v 1.2 1994/11/02 23:47:14 se Exp $ ** **  Declarations for pci device drivers. ** **  386bsd / FreeBSD ** **------------------------------------------------------------------------- ** ** Copyright (c) 1994 Wolfgang Stanglmeier.  All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions ** are met: ** 1. Redistributions of source code must retain the above copyright **    notice, this list of conditions and the following disclaimer. ** 2. Redistributions in binary form must reproduce the above copyright **    notice, this list of conditions and the following disclaimer in the **    documentation and/or other materials provided with the distribution. ** 3. The name of the author may not be used to endorse or promote products **    derived from this software without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR ** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES ** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. ** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, ** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT ** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF ** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** *************************************************************************** */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCI_VAR_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCI_VAR_H__
end_define

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------- ** **	main pci initialization function. **	called at boot time from autoconf.c ** **----------------------------------------------------------------- */
end_comment

begin_function_decl
name|void
name|pci_configure
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*----------------------------------------------------------------- ** **	The pci configuration id describes a pci device on the bus. **	It is constructed from: bus, device& function numbers. ** **----------------------------------------------------------------- */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|u_long
name|cfg1
decl_stmt|;
struct|struct
block|{
name|u_char
name|enable
decl_stmt|;
name|u_char
name|forward
decl_stmt|;
name|u_short
name|port
decl_stmt|;
block|}
name|cfg2
struct|;
block|}
name|pcici_t
typedef|;
end_typedef

begin_comment
comment|/*----------------------------------------------------------------- ** **	Each pci device has an unique device id. **	It is used to find a matching driver. ** **----------------------------------------------------------------- */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|pcidi_t
typedef|;
end_typedef

begin_comment
comment|/*----------------------------------------------------------------- ** **	The following functions are provided for the device driver **	to read/write the configuration space. ** **	pci_conf_read(): **		Read a long word from the pci configuration space. **		Requires a tag (from pcitag) and the register **		number (should be a long word alligned one). ** **	pci_conf_write(): **		Writes a long word to the pci configuration space. **		Requires a tag (from pcitag), the register number **		(should be a long word alligned one), and a value. ** **----------------------------------------------------------------- */
end_comment

begin_function_decl
name|u_long
name|pci_conf_read
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|u_long
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pci_conf_write
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|u_long
name|reg
parameter_list|,
name|u_long
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------- ** **	The pci driver structure. ** **	name:	The short device name. ** **	probe:	Checks if the driver can support a device **		with this type. The tag may be used to get **		more info with pci_read_conf(). See below. **		It returns a string with the devices name, **		or a NULL pointer, if the driver cannot **		support this device. ** **	attach:	Allocate a control structure and prepare **		it. This function may use the pci mapping **		functions. See below. **		(configuration id) or type. ** **	count:	A pointer to a unit counter. **		It's used by the pci configurator to **		allocate unit numbers. ** **----------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|pci_device
block|{
name|char
modifier|*
name|pd_name
decl_stmt|;
name|char
modifier|*
function_decl|(
modifier|*
name|pd_probe
function_decl|)
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|pcidi_t
name|type
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pd_attach
function_decl|)
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
name|u_long
modifier|*
name|pd_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*----------------------------------------------------------------- ** **	This table includes pointers to all pci device drivers. **	It should be generated by the linker. ** **----------------------------------------------------------------- */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|linker_set
name|pcidevice_set
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------- ** **	The pci-devconf interface. ** **----------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|pci_info
block|{
name|u_short
name|pi_bus
decl_stmt|;
name|u_short
name|pi_device
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PCI_EXT_CONF_LEN
value|(16)
end_define

begin_define
define|#
directive|define
name|PCI_EXTERNAL_LEN
value|(sizeof(struct pci_externalize_buffer))
end_define

begin_struct
struct|struct
name|pci_externalize_buffer
block|{
name|struct
name|pci_info
name|peb_pci_info
decl_stmt|;
name|u_long
name|peb_config
index|[
name|PCI_EXT_CONF_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------- ** **	Map a pci device to physical and virtual memory. ** **	The va and pa addresses are "in/out" parameters. **	If they are 0 on entry, the function assigns an address. ** **	Entry selects the register in the pci configuration **	space, which supplies the size of the region, and **	receives the physical address. ** **	If there is any error, a message is written, and **	the function returns with zero. **	Else it returns with a value different to zero. ** **----------------------------------------------------------------- */
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

begin_comment
comment|/*----------------------------------------------------------------- ** **	Map a pci device to an io port area. ** **	*pa is an "in/out" parameter. **	If it's 0 on entry, the function assigns an port number.. ** **	Entry selects the register in the pci configuration **	space, which supplies the size of the region, and **	receives the port number. ** **	If there is any error, a message is written, and **	the function returns with zero. **	Else it returns with a value different to zero. ** **----------------------------------------------------------------- */
end_comment

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

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------- ** **	Map a pci interrupt to an isa irq line, **	and enable the interrupt. ** **	func is the interrupt handler, arg is the argument **	to this function. ** **	The maskptr argument should be&bio_imask, **&net_imask etc. or NULL. ** **	If there is any error, a message is written, and **	the function returns with zero. **	Else it returns with a value different to zero. ** **	A word of caution for FreeBSD 2.0: ** **	We use the register_intr() function. ** **	The interrupt line of the selected device is included **	into the supplied mask: after the corresponding splXXX **	this drivers interrupts are blocked. ** **	But in the interrupt handlers startup code ONLY **	the interrupt of the driver is blocked, and NOT **	all interrupts of the spl group. ** **	It may be required to additional block the group **	interrupts by splXXX() inside the interrupt handler. ** **	In pre 2.0 kernels we emulate the register_intr **	function. The emulating function blocks all interrupts **	of the group in the interrupt handler prefix code. ** **----------------------------------------------------------------- */
end_comment

begin_function_decl
name|int
name|pci_map_int
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|unsigned
modifier|*
name|maskptr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

