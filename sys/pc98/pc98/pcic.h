begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * TODO:  * [1] integrate into current if_ed.c  * [2] parse tuples to find out where to map the shared memory buffer,  *     and what to write into the configuration register  * [3] move pcic-specific code into a separate module.  *  * Device driver for IBM PCMCIA Credit Card Adapter for Ethernet,  * if_ze.c  *  * Based on the Device driver for National Semiconductor DS8390 ethernet  * adapters by David Greenman.  Modifications for PCMCIA by Keith Moore.  * Adapted for FreeBSD 1.1.5 by Jordan Hubbard.  *  * Currently supports only the IBM Credit Card Adapter for Ethernet, but  * could probably work with other PCMCIA cards also, if it were modified  * to get the locations of the PCMCIA configuration option register (COR)  * by parsing the configuration tuples, rather than by hard-coding in  * the value expected by IBM's card.  *  * Sources for data on the PCMCIA/IBM CCAE specific portions of the driver:  *  * [1] _Local Area Network Credit Card Adapters Technical Reference_,  *     IBM Corp., SC30-3585-00, part # 33G9243.  * [2] "pre-alpha" PCMCIA support code for Linux by Barry Jaspan.  * [3] Intel 82536SL PC Card Interface Controller Data Sheet, Intel  *     Order Number 290423-002  * [4] National Semiconductor DP83902A ST-NIC (tm) Serial Network  *     Interface Controller for Twisted Pair data sheet.  *  *  * Copyright (C) 1993, David Greenman. This software may be used, modified,  *   copied, distributed, and sold, in both source and binary form provided  *   that the above copyright and these terms are retained. Under no  *   circumstances is the author responsible for the proper functioning  *   of this software, nor does the author assume any responsibility  *   for damages incurred with its use.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCIC_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCIC_H__
end_define

begin_comment
comment|/*****************************************************************************  *                 pcmcia controller chip (PCIC) support                     *  *               (eventually, move this to a separate file)                  *  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"ic/i82365.h"
end_include

begin_comment
comment|/*  * Each PCIC chip (82365SL or clone) can handle two card slots, and there  * can be up to four PCICs in a system.  (On some machines, not all of the  * address lines are decoded, so a card may appear to be in more than one  * slot.)  */
end_comment

begin_define
define|#
directive|define
name|MAXSLOT
value|8
end_define

begin_comment
comment|/*  * To access a register on the PCIC for a particular slot, you  * first write the correct OFFSET value for that slot in the  * INDEX register for the PCIC controller.  You then read or write  * the value from or to the DATA register for that controller.  *  * The first pair of chips shares I/O addresses for DATA and INDEX,  * as does the second pair.   (To the programmer, it looks like each  * pair is a single chip.)  The i/o port addresses are hard-wired  * into the PCIC; so the following addresses should be valid for  * any machine that uses this chip.  */
end_comment

begin_define
define|#
directive|define
name|PCIC_INDEX_0
value|0x3E0
end_define

begin_comment
comment|/* index reg, chips 0 and 1 */
end_comment

begin_define
define|#
directive|define
name|PCIC_DATA_0
value|0x3E1
end_define

begin_comment
comment|/* data register, chips 0 and 1 */
end_comment

begin_define
define|#
directive|define
name|PCIC_INDEX_1
value|0x3E2
end_define

begin_comment
comment|/* index reg, chips 1 and 2 */
end_comment

begin_define
define|#
directive|define
name|PCIC_DATA_1
value|0x3E3
end_define

begin_comment
comment|/* data register, chips 1 and 2 */
end_comment

begin_comment
comment|/*  * Given a slot number, calculate the INDEX and DATA registers  * to talk to that slot.  OFFSET is added to the register number  * to address the registers for a particular slot.  */
end_comment

begin_define
define|#
directive|define
name|INDEX
parameter_list|(
name|slot
parameter_list|)
value|((slot)< 4 ? PCIC_INDEX_0 : PCIC_INDEX_1)
end_define

begin_define
define|#
directive|define
name|DATA
parameter_list|(
name|slot
parameter_list|)
value|((slot)< 4 ? PCIC_DATA_0 : PCIC_DATA_1)
end_define

begin_define
define|#
directive|define
name|OFFSET
parameter_list|(
name|slot
parameter_list|)
value|((slot) % 4 * 0x40)
end_define

begin_comment
comment|/*  * There are 5 sets (windows) of memory mapping registers on the PCIC chip  * for each slot, numbered 0..4.  *  * They start at 10/50 hex within the chip's register space (not system  * I/O space), and are eight addresses apart.  These are actually pairs of  * 8-bit-wide registers (low byte first, then high byte) since the  * address fields are actually 12 bits long.  The upper bits are used  * for other things like 8/16-bit select and wait states.  *  * Memory mapping registers include start/stop addresses to define the  * region to be mapped (in terms of system memory addresses), and  * an offset register to allow for translation from system space  * to card space.  The lower 12 bits aren't included in these, so memory is  * mapped in 4K chunks.  */
end_comment

begin_define
define|#
directive|define
name|MEM_START_ADDR
parameter_list|(
name|window
parameter_list|)
value|(((window) * 0x08) + 0x10)
end_define

begin_define
define|#
directive|define
name|MEM_STOP_ADDR
parameter_list|(
name|window
parameter_list|)
value|(((window) * 0x08) + 0x12)
end_define

begin_define
define|#
directive|define
name|MEM_OFFSET
parameter_list|(
name|window
parameter_list|)
value|(((window) * 0x08) + 0x14)
end_define

begin_comment
comment|/*  * this bit gets set in the address window enable register (PCIC_ADDRWINE)  * to enable a particular address window.  */
end_comment

begin_define
define|#
directive|define
name|MEM_ENABLE_BIT
parameter_list|(
name|window
parameter_list|)
value|((1)<< (window))
end_define

begin_comment
comment|/*  * There are two i/o port addressing windows.  I/O ports cannot be  * relocated within system i/o space (unless the card doesn't decode  * all of the address bits); unlike card memory, there is no address  * translation offset.  */
end_comment

begin_define
define|#
directive|define
name|IO_START_ADDR
parameter_list|(
name|window
parameter_list|)
value|((window) ? PCIC_IO1_STL : PCIC_IO0_STL)
end_define

begin_define
define|#
directive|define
name|IO_STOP_ADDR
parameter_list|(
name|window
parameter_list|)
value|((window) ? PCIC_IO1_SPL : PCIC_IO0_SPL)
end_define

begin_define
define|#
directive|define
name|IO_ENABLE_BIT
parameter_list|(
name|window
parameter_list|)
value|((window) ? PCIC_IO1_EN : PCIC_IO0_EN)
end_define

begin_define
define|#
directive|define
name|IO_CS16_BIT
parameter_list|(
name|window
parameter_list|)
value|((window) ? PCIC_IO1_CS16 : PCIC_IO0_CS16)
end_define

begin_comment
comment|/*  * types of mapped memory  */
end_comment

begin_enum
enum|enum
name|memtype
block|{
name|COMMON
block|,
name|ATTRIBUTE
block|}
enum|;
end_enum

begin_comment
comment|/*  * read a byte from a pcic register for a particular slot  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|char
name|pcic_getb
parameter_list|(
name|int
name|slot
parameter_list|,
name|int
name|reg
parameter_list|)
block|{
name|outb
argument_list|(
name|INDEX
argument_list|(
name|slot
argument_list|)
argument_list|,
name|OFFSET
argument_list|(
name|slot
argument_list|)
operator|+
name|reg
argument_list|)
expr_stmt|;
return|return
name|inb
argument_list|(
name|DATA
argument_list|(
name|slot
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * write a byte to a pcic register for a particular slot  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|pcic_putb
parameter_list|(
name|int
name|slot
parameter_list|,
name|int
name|reg
parameter_list|,
name|unsigned
name|char
name|val
parameter_list|)
block|{
name|outb
argument_list|(
name|INDEX
argument_list|(
name|slot
argument_list|)
argument_list|,
name|OFFSET
argument_list|(
name|slot
argument_list|)
operator|+
name|reg
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|DATA
argument_list|(
name|slot
argument_list|)
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * read a word from a pcic register for a particular slot  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|short
name|pcic_getw
parameter_list|(
name|int
name|slot
parameter_list|,
name|int
name|reg
parameter_list|)
block|{
return|return
name|pcic_getb
argument_list|(
name|slot
argument_list|,
name|reg
argument_list|)
operator||
operator|(
name|pcic_getb
argument_list|(
name|slot
argument_list|,
name|reg
operator|+
literal|1
argument_list|)
operator|<<
literal|8
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * write a word to a pcic register at a particular slot  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|pcic_putw
parameter_list|(
name|int
name|slot
parameter_list|,
name|int
name|reg
parameter_list|,
name|unsigned
name|short
name|val
parameter_list|)
block|{
name|pcic_putb
argument_list|(
name|slot
argument_list|,
name|reg
argument_list|,
name|val
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|pcic_putb
argument_list|(
name|slot
argument_list|,
name|reg
operator|+
literal|1
argument_list|,
operator|(
name|val
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|pcic_print_regs
parameter_list|(
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcic_map_memory
parameter_list|(
name|int
name|slot
parameter_list|,
name|int
name|window
parameter_list|,
name|unsigned
name|long
name|sys_addr
parameter_list|,
name|unsigned
name|long
name|card_addr
parameter_list|,
name|unsigned
name|long
name|length
parameter_list|,
name|enum
name|memtype
name|type
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcic_unmap_memory
parameter_list|(
name|int
name|slot
parameter_list|,
name|int
name|window
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcic_map_io
parameter_list|(
name|int
name|slot
parameter_list|,
name|int
name|window
parameter_list|,
name|unsigned
name|short
name|base
parameter_list|,
name|unsigned
name|short
name|length
parameter_list|,
name|unsigned
name|short
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TEST
end_ifdef

begin_function_decl
name|void
name|pcic_unmap_io
parameter_list|(
name|int
name|slot
parameter_list|,
name|int
name|window
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TEST */
end_comment

begin_function_decl
name|void
name|pcic_map_irq
parameter_list|(
name|int
name|slot
parameter_list|,
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcic_power_on
parameter_list|(
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcic_power_off
parameter_list|(
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcic_reset
parameter_list|(
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PCIC_H__ */
end_comment

end_unit

