begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, Sujal M. Patel  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Sujal M. Patel  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $Id: pnp.h,v 1.2 1997/09/18 08:04:13 jmg Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_PNP_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_PNP_H_
end_define

begin_comment
comment|/* Maximum Number of PnP Devices.  8 should be plenty */
end_comment

begin_define
define|#
directive|define
name|MAX_PNP_CARDS
value|8
end_define

begin_comment
comment|/*  * the following is the maximum number of PnP Logical devices that  * userconfig can handle.  */
end_comment

begin_define
define|#
directive|define
name|MAX_PNP_LDN
value|20
end_define

begin_comment
comment|/* Static ports to access PnP state machine */
end_comment

begin_define
define|#
directive|define
name|_PNP_ADDRESS
value|0x279
end_define

begin_define
define|#
directive|define
name|_PNP_WRITE_DATA
value|0xa79
end_define

begin_comment
comment|/* PnP Registers.  Write to ADDRESS and then use WRITE/READ_DATA */
end_comment

begin_define
define|#
directive|define
name|SET_RD_DATA
value|0x00
end_define

begin_comment
comment|/*** 	Writing to this location modifies the address of the port used for 	reading from the Plug and Play ISA cards.   Bits[7:0] become I/O 	read port address bits[9:2].  Reads from this register are ignored. 	***/
end_comment

begin_define
define|#
directive|define
name|SERIAL_ISOLATION
value|0x01
end_define

begin_comment
comment|/*** 	A read to this register causes a Plug and Play cards in the Isolation 	state to compare one bit of the boards ID. 	This register is read only. 	***/
end_comment

begin_define
define|#
directive|define
name|CONFIG_CONTROL
value|0x02
end_define

begin_comment
comment|/*** 	Bit[2]  Reset CSN to 0 	Bit[1]  Return to the Wait for Key state 	Bit[0]  Reset all logical devices and restore configuration 		registers to their power-up values.  	A write to bit[0] of this register performs a reset function on 	all logical devices.  This resets the contents of configuration 	registers to  their default state.  All card's logical devices 	enter their default state and the CSN is preserved. 		       	A write to bit[1] of this register causes all cards to enter the 	Wait for Key state but all CSNs are preserved and logical devices 	are not affected. 			     	A write to bit[2] of this register causes all cards to reset their 	CSN to zero . 			   	This register is write-only.  The values are not sticky, that is, 	hardware will automatically clear them and there is no need for 	software to clear the bits. 	***/
end_comment

begin_define
define|#
directive|define
name|WAKE
value|0x03
end_define

begin_comment
comment|/*** 	A write to this port will cause all cards that have a CSN that 	matches the write data[7:0] to go from the Sleep state to the either 	the Isolation state if the write data for this command is zero or 	the Config state if the write data is not zero.  Additionally, the 	pointer to the byte-serial device is reset.  This register is   	writeonly. 	***/
end_comment

begin_define
define|#
directive|define
name|RESOURCE_DATA
value|0x04
end_define

begin_comment
comment|/*** 	A read from this address reads the next byte of resource information. 	The Status register must be polled until bit[0] is set before this 	register may be read.  This register is read only. 	***/
end_comment

begin_define
define|#
directive|define
name|STATUS
value|0x05
end_define

begin_comment
comment|/*** 	Bit[0] when set indicates it is okay to read the next data byte   	from the Resource Data register.  This register is readonly. 	***/
end_comment

begin_define
define|#
directive|define
name|SET_CSN
value|0x06
end_define

begin_comment
comment|/*** 	A write to this port sets a card's CSN.  The CSN is a value uniquely 	assigned to each ISA card after the serial identification process 	so that each card may be individually selected during a Wake[CSN] 	command. This register is read/write.  	***/
end_comment

begin_define
define|#
directive|define
name|SET_LDN
value|0x07
end_define

begin_comment
comment|/*** 	Selects the current logical device.  All reads and writes of memory, 	I/O, interrupt and DMA configuration information access the registers 	of the logical device written here.  In addition, the I/O Range 	Check and Activate  commands operate only on the selected logical 	device.  This register is read/write. If a card has only 1 logical 	device, this location should be a read-only value of 0x00. 	***/
end_comment

begin_comment
comment|/*** addresses 0x08 - 0x1F Card Level Reserved for future use ***/
end_comment

begin_comment
comment|/*** addresses 0x20 - 0x2F Card Level, Vendor Defined ***/
end_comment

begin_define
define|#
directive|define
name|ACTIVATE
value|0x30
end_define

begin_comment
comment|/*** 	For each logical device there is one activate register that controls 	whether or not the logical device is active on the ISA bus.  Bit[0], 	if set, activates the logical device.  Bits[7:1] are reserved and 	must return 0 on reads.  This is a read/write register. Before a 	logical device is activated, I/O range check must be disabled. 	***/
end_comment

begin_define
define|#
directive|define
name|IO_RANGE_CHECK
value|0x31
end_define

begin_comment
comment|/*** 	This register is used to perform a conflict check on the I/O port 	range programmed for use by a logical device.  	Bit[7:2]  Reserved and must return 0 on reads 	Bit[1]    Enable I/O Range check, if set then I/O Range Check 	is enabled. I/O range check is only valid when the logical 	device is inactive.  	Bit[0], if set, forces the logical device to respond to I/O reads 	of the logical device's assigned I/O range with a 0x55 when I/O 	range check is in operation.  If clear, the logical device drives 	0xAA.  This register is read/write. 	***/
end_comment

begin_comment
comment|/*** addr 0x32 - 0x37 Logical Device Control Reserved for future use ***/
end_comment

begin_comment
comment|/*** addr 0x38 - 0x3F Logical Device Control Vendor Define ***/
end_comment

begin_define
define|#
directive|define
name|MEM_CONFIG
value|0x40
end_define

begin_comment
comment|/*** 	Four memory resource registers per range, four ranges. 	Fill with 0 if no ranges are enabled.  	Offset 0:	RW Memory base address bits[23:16] 	Offset 1:	RW Memory base address bits[15:8] 	Offset 2:	Memory control 	    Bit[1] specifies 8/16-bit control.  This bit is set to indicate 	    16-bit memory, and cleared to indicate 8-bit memory. 	    Bit[0], if cleared, indicates the next field can be used as a range 	    length for decode (implies range length and base alignment of memory 	    descriptor are equal). 	    Bit[0], if set, indicates the next field is the upper limit for 	    the address. -  - Bit[0] is read-only. 	Offset 3:	RW upper limit or range len, bits[23:16] 	Offset 4:	RW upper limit or range len, bits[15:8] 	Offset 5-Offset 7: filler, unused. 	***/
end_comment

begin_define
define|#
directive|define
name|IO_CONFIG_BASE
value|0x60
end_define

begin_comment
comment|/*** 	Eight ranges, two bytes per range. 	Offset 0:		I/O port base address bits[15:8] 	Offset 1:		I/O port base address bits[7:0] 	***/
end_comment

begin_define
define|#
directive|define
name|IRQ_CONFIG
value|0x70
end_define

begin_comment
comment|/*** 	Two entries, two bytes per entry. 	Offset 0:	RW interrupt level (1..15, 0=unused). 	Offset 1:	Bit[1]: level(1:hi, 0:low), 			Bit[0]: type (1:level, 0:edge) 		byte 1 can be readonly if 1 type of int is used. 	***/
end_comment

begin_define
define|#
directive|define
name|DRQ_CONFIG
value|0x74
end_define

begin_comment
comment|/*** 	Two entries, one byte per entry. Bits[2:0] select 	which DMA channel is in use for DMA 0.  Zero selects DMA channel 	0, seven selects DMA channel 7. DMA channel 4, the cascade channel 	is used to indicate no DMA channel is active. 	***/
end_comment

begin_comment
comment|/*** 32-bit memory accesses are at 0x76 ***/
end_comment

begin_comment
comment|/* Small Resource Item names */
end_comment

begin_define
define|#
directive|define
name|PNP_VERSION
value|0x1
end_define

begin_define
define|#
directive|define
name|LOG_DEVICE_ID
value|0x2
end_define

begin_define
define|#
directive|define
name|COMP_DEVICE_ID
value|0x3
end_define

begin_define
define|#
directive|define
name|IRQ_FORMAT
value|0x4
end_define

begin_define
define|#
directive|define
name|DMA_FORMAT
value|0x5
end_define

begin_define
define|#
directive|define
name|START_DEPEND_FUNC
value|0x6
end_define

begin_define
define|#
directive|define
name|END_DEPEND_FUNC
value|0x7
end_define

begin_define
define|#
directive|define
name|IO_PORT_DESC
value|0x8
end_define

begin_define
define|#
directive|define
name|FIXED_IO_PORT_DESC
value|0x9
end_define

begin_define
define|#
directive|define
name|SM_RES_RESERVED
value|0xa-0xd
end_define

begin_define
define|#
directive|define
name|SM_VENDOR_DEFINED
value|0xe
end_define

begin_define
define|#
directive|define
name|END_TAG
value|0xf
end_define

begin_comment
comment|/* Large Resource Item names */
end_comment

begin_define
define|#
directive|define
name|MEMORY_RANGE_DESC
value|0x1
end_define

begin_define
define|#
directive|define
name|ID_STRING_ANSI
value|0x2
end_define

begin_define
define|#
directive|define
name|ID_STRING_UNICODE
value|0x3
end_define

begin_define
define|#
directive|define
name|LG_VENDOR_DEFINED
value|0x4
end_define

begin_define
define|#
directive|define
name|_32BIT_MEM_RANGE_DESC
value|0x5
end_define

begin_define
define|#
directive|define
name|_32BIT_FIXED_LOC_DESC
value|0x6
end_define

begin_define
define|#
directive|define
name|LG_RES_RESERVED
value|0x7-0x7f
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_comment
comment|/*  * pnp_cinfo contains Configuration Information. They are used  * to communicate to the device driver the actual configuration  * of the device, and also by the userconfig menu to let the  * operating system override any configuration set by the bios.  *  */
end_comment

begin_struct
struct|struct
name|pnp_cinfo
block|{
name|u_int
name|vendor_id
decl_stmt|;
comment|/* board id */
name|u_int
name|serial
decl_stmt|;
comment|/* Board's Serial Number */
name|u_long
name|flags
decl_stmt|;
comment|/* OS-reserved flags */
name|u_char
name|csn
decl_stmt|;
comment|/* assigned Card Select Number */
name|u_char
name|ldn
decl_stmt|;
comment|/* Logical Device Number */
name|u_char
name|enable
decl_stmt|;
comment|/* pnp enable */
name|u_char
name|override
decl_stmt|;
comment|/* override bios parms (in userconfig) */
name|u_char
name|irq
index|[
literal|2
index|]
decl_stmt|;
comment|/* IRQ Number */
name|u_char
name|irq_type
index|[
literal|2
index|]
decl_stmt|;
comment|/* IRQ Type */
name|u_char
name|drq
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|port
index|[
literal|8
index|]
decl_stmt|;
comment|/* The Base Address of the Port */
struct|struct
block|{
name|u_long
name|base
decl_stmt|;
comment|/* Memory Base Address */
name|int
name|control
decl_stmt|;
comment|/* Memory Control Register */
name|u_long
name|range
decl_stmt|;
comment|/* Memory Range *OR* Upper Limit */
block|}
name|mem
index|[
literal|4
index|]
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pnp_device
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
name|u_long
name|csn
parameter_list|,
name|u_long
name|vendor_id
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pd_attach
function_decl|)
parameter_list|(
name|u_long
name|csn
parameter_list|,
name|u_long
name|vend_id
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|u_long
modifier|*
name|pd_count
decl_stmt|;
name|u_int
modifier|*
name|imask
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_pnp_id
block|{
name|u_long
name|vendor_id
decl_stmt|;
name|u_long
name|serial
decl_stmt|;
name|u_char
name|checksum
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pnp_dlist_node
block|{
name|struct
name|pnp_device
modifier|*
name|pnp
decl_stmt|;
name|struct
name|isa_device
name|dev
decl_stmt|;
name|struct
name|pnp_dlist_node
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_pnp_id
name|pnp_id
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|pnp_dlist_node
modifier|*
name|pnp_device_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pnp_id
name|pnp_devices
index|[
name|MAX_PNP_CARDS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pnp_cinfo
name|pnp_ldn_overrides
index|[
name|MAX_PNP_LDN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pnp_overrides_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|linker_set
name|pnpdevice_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * these two functions are for use in drivers  */
end_comment

begin_function_decl
name|int
name|read_pnp_parms
parameter_list|(
name|struct
name|pnp_cinfo
modifier|*
name|d
parameter_list|,
name|int
name|ldn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_pnp_parms
parameter_list|(
name|struct
name|pnp_cinfo
modifier|*
name|d
parameter_list|,
name|int
name|ldn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|enable_pnp_card
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * used by autoconfigure to actually probe and attach drivers  */
end_comment

begin_decl_stmt
name|void
name|pnp_configure
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_ISA_PNP_H_ */
end_comment

end_unit

