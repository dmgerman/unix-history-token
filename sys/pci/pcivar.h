begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** ** ** $FreeBSD$ ** **  Declarations for pci device drivers. ** **  FreeBSD ** **------------------------------------------------------------------------- ** ** Copyright (c) 1994 Wolfgang Stanglmeier.  All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions ** are met: ** 1. Redistributions of source code must retain the above copyright **    notice, this list of conditions and the following disclaimer. ** 2. Redistributions in binary form must reproduce the above copyright **    notice, this list of conditions and the following disclaimer in the **    documentation and/or other materials provided with the distribution. ** 3. The name of the author may not be used to endorse or promote products **    derived from this software without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR ** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES ** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. ** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, ** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT ** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF ** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** *************************************************************************** */
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
value|"pl2 95/03/21"
end_define

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
name|unsigned
name|tag
decl_stmt|;
block|}
name|pcici_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sametag
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x).tag == (y).tag)
end_define

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
name|int
function_decl|(
modifier|*
name|pd_shutdown
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
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

begin_decl_stmt
specifier|extern
name|unsigned
name|pci_max_burst_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log2 of safe burst transfer length */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|pci_mechanism
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|pci_maxdevice
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*----------------------------------------------------------------- ** **	Map a pci device to physical and virtual memory. ** **      Entry selects the register in the pci configuration **	space, which supplies the size of the region, and **	receives the physical address. ** **	In case of success the function sets the addresses **	in *va and *pa, and returns 1. **	In case of errors a message is written, **	and the function returns 0. ** **----------------------------------------------------------------- */
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
name|vm_offset_t
modifier|*
name|va
parameter_list|,
name|vm_offset_t
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*----------------------------------------------------------------- ** **	Map a pci device to an io port area. ** **	Entry selects the register in the pci configuration **	space, which supplies the size of the region, and **	receives the port number. ** **	In case of success the function sets the port number in pa, **	and returns 1. **	In case of errors a message is written, **	and the function returns 0. ** **----------------------------------------------------------------- */
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

begin_comment
comment|/*----------------------------------------------------------------- ** **	Map a pci interrupt to an isa irq line, and enable the interrupt. ** **      ----------------- ** **      func is the interrupt handler, arg is the argument **      to the handler (usually a pointer to a softc). ** **      The maskptr argument should be&bio_imask, **&net_imask etc. or NULL. ** **      If there is any error, a message is written, and **      the function returns with zero. **      Else it returns with a value different to zero. ** **      ----------------- ** **	The irq number is read from the configuration space. **	(Should have been set by the bios). ** **	Supports multiple handlers per irq (shared interrupts). ** **----------------------------------------------------------------- */
end_comment

begin_typedef
typedef|typedef
name|void
name|pci_inthand_t
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|pci_int_desc
block|{
name|struct
name|pci_int_desc
modifier|*
name|pcid_next
decl_stmt|;
name|pcici_t
name|pcid_tag
decl_stmt|;
name|pci_inthand_t
modifier|*
name|pcid_handler
decl_stmt|;
name|void
modifier|*
name|pcid_argument
decl_stmt|;
name|unsigned
modifier|*
name|pcid_maskptr
decl_stmt|;
name|unsigned
name|pcid_tally
decl_stmt|;
name|unsigned
name|pcid_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|pci_map_int
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|pci_inthand_t
modifier|*
name|func
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

begin_function_decl
name|int
name|pci_unmap_int
parameter_list|(
name|pcici_t
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_get_bus
parameter_list|(
name|pcici_t
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_get_device
parameter_list|(
name|pcici_t
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_get_function
parameter_list|(
name|pcici_t
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

