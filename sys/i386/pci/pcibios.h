begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** ** **  $Id: pcibios.h,v 1.2 1994/09/01 02:01:45 se Exp $ ** **  #define   for pci-bus bios functions. ** **  386bsd / FreeBSD ** **------------------------------------------------------------------------- ** ** Copyright (c) 1994 Wolfgang Stanglmeier.  All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions ** are met: ** 1. Redistributions of source code must retain the above copyright **    notice, this list of conditions and the following disclaimer. ** 2. Redistributions in binary form must reproduce the above copyright **    notice, this list of conditions and the following disclaimer in the **    documentation and/or other materials provided with the distribution. ** 3. The name of the author may not be used to endorse or promote products **    derived from this software without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR ** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES ** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. ** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, ** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT ** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF ** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** **------------------------------------------------------------------------- ** **  $Log: pcibios.h,v $  * Revision 1.2  1994/09/01  02:01:45  se  * Submitted by:	Wolfgang Stanglmeier<wolf@dentaro.GUN.de>  * Merged in changes required for NetBSD support (by mycroft@gnu.ai.mit.edu)  * and support for multiple NCR chips.  * **  Revision 2.0.0.1  94/08/18  23:05:36  wolf **   **  Copyright message. **  New function: pci_last_bus(). **  Symbolic names for pci configuration space registers. **   **  Revision 2.0  94/07/10  15:53:32  wolf **  FreeBSD release. **   **  Revision 1.0  94/06/07  20:02:23  wolf **  Beta release. **   *************************************************************************** */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCIBIOS_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCIBIOS_H__
end_define

begin_comment
comment|/* **	the availability of a pci bus. **	configuration mode (1 or 2) **	0 if no pci bus found. */
end_comment

begin_function_decl
name|int
name|pci_conf_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* **	The number of the last available pci bus. */
end_comment

begin_function_decl
name|int
name|pci_last_bus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* **	get a "ticket" for accessing a pci device **	configuration space. */
end_comment

begin_function_decl
name|pcici_t
name|pcitag
parameter_list|(
name|unsigned
name|char
name|bus
parameter_list|,
name|unsigned
name|char
name|device
parameter_list|,
name|unsigned
name|char
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* **	read or write the configuration space. */
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
comment|/* **	Names for PCI configuration space registers. **	Copied from pcireg.h */
end_comment

begin_define
define|#
directive|define
name|PCI_ID_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_STATUS_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_MEM_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_REV_REG
value|0x08
end_define

begin_define
define|#
directive|define
name|PCI_MAJCLASS_OF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xff)
end_define

begin_define
define|#
directive|define
name|PCI_MINCLASS_OF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|PCI_PROGINT_OF
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  8)& 0xff)
end_define

begin_define
define|#
directive|define
name|PCI_REV_OF
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_enum
enum|enum
name|pci_majclass
block|{
name|PCI_MJC_OLD
init|=
literal|0
block|,
name|PCI_MJC_STOR
block|,
name|PCI_MJC_NET
block|,
name|PCI_MJC_DISPLAY
block|,
name|PCI_MJC_MEDIA
block|,
name|PCI_MJC_MEM
block|,
name|PCI_MJC_BRIDGE
block|}
enum|;
end_enum

begin_enum
enum|enum
name|pci_old_minclass
block|{
name|PCI_MIN_OLD
init|=
literal|0
block|,
name|PCI_MIN_OVGA
block|}
enum|;
end_enum

begin_enum
enum|enum
name|pci_stor_minclass
block|{
name|PCI_MIN_SCSI
init|=
literal|0
block|,
name|PCI_MIN_IDE
block|,
name|PCI_MIN_FLOP
block|,
name|PCI_MIN_IPI
block|,
name|PCI_MIN_OSTOR
block|}
enum|;
end_enum

begin_enum
enum|enum
name|pci_net_minclass
block|{
name|PCI_MIN_ETHER
init|=
literal|0
block|,
name|PCI_MIN_TOKEN
block|,
name|PCI_MIN_FDDI
block|,
name|PCI_MIN_ONET
block|}
enum|;
end_enum

begin_enum
enum|enum
name|pci_disp_minclass
block|{
name|PCI_MIN_VGA
init|=
literal|0
block|,
name|PCI_MIN_XGA
block|,
name|PCI_MIN_ODISP
block|}
enum|;
end_enum

begin_enum
enum|enum
name|pci_media_minclass
block|{
name|PCI_MIN_VIDEO
init|=
literal|0
block|,
name|PCI_MIN_AUDIO
block|,
name|PCI_MIN_OMEDIA
block|}
enum|;
end_enum

begin_enum
enum|enum
name|pci_mem_minclass
block|{
name|PCI_MIN_RAM
init|=
literal|0
block|,
name|PCI_MIN_FLASH
block|,
name|PCI_MIN_OMEM
block|}
enum|;
end_enum

begin_enum
enum|enum
name|pci_bridge_minclass
block|{
name|PCI_MIN_HOST
init|=
literal|0
block|,
name|PCI_MIN_ISA
block|,
name|PCI_MIN_EISA
block|,
name|PCI_MIN_MC
block|,
name|PCI_MIN_PCI
block|,
name|PCI_MIN_PCMCIA
block|,
name|PCI_MIN_OBRIDGE
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PCI_MAP_REG_START
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_MAP_REG_END
value|0x28
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_MAP_IO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_TYPE_32BIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_TYPE_32BIT_1M
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_TYPE_64BIT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_TYPE_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_CACHABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_ADDRESS_MASK
value|0xfffffff0
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_REG
value|0x3c
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_PIN_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_PIN_EXTRACT
parameter_list|(
name|x
parameter_list|)
value|((((x)& PCI_INTERRUPT_PIN_MASK)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_LINE_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_LINE_EXTRACT
parameter_list|(
name|x
parameter_list|)
value|((((x)& PCI_INTERRUPT_LINE_MASK)>> 0)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

