begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: dma.h,v 1.7 1992/12/14 00:29:34 root Exp root $  * linux/include/asm/dma.h: Defines for using and allocating dma channels.  * Written by Hennus Bergman, 1992.  * High DMA channel support& info by Hannu Savolainen  * and John Boyd, Nov. 1992.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ASM_DMA_H
end_ifndef

begin_define
define|#
directive|define
name|_ASM_DMA_H
end_define

begin_include
include|#
directive|include
file|<asm/io.h>
end_include

begin_comment
comment|/* need byte IO */
end_comment

begin_define
define|#
directive|define
name|deb_outb
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{printk("out %02x, %02x\n", x, y);outb(x,y);}
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_REALLY_SLOW_DMA_CONTROLLER
end_ifdef

begin_define
define|#
directive|define
name|outb
value|outb_p
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NOTES about DMA transfers:  *  *  controller 1: channels 0-3, byte operations, ports 00-1F  *  controller 2: channels 4-7, word operations, ports C0-DF  *  *  - ALL registers are 8 bits only, regardless of transfer size  *  - channel 4 is not used - cascades 1 into 2.  *  - channels 0-3 are byte - addresses/counts are for physical bytes  *  - channels 5-7 are word - addresses/counts are for physical words  *  - transfers must not cross physical 64K (0-3) or 128K (5-7) boundaries  *  - transfer count loaded to registers is 1 less than actual count  *  - controller 2 offsets are all even (2x offsets for controller 1)  *  - page registers for 5-7 don't use data bit 0, represent 128K pages  *  - page registers for 0-3 use bit 0, represent 64K pages  *  * DMA transfers are limited to the lower 16MB of _physical_ memory.    * Note that addresses loaded into registers must be _physical_ addresses,  * not logical addresses (which may differ if paging is active).  *  *  Address mapping for channels 0-3:  *  *   A23 ... A16 A15 ... A8  A7 ... A0    (Physical addresses)  *    |  ...  |   |  ... |   |  ... |  *    |  ...  |   |  ... |   |  ... |  *    |  ...  |   |  ... |   |  ... |  *   P7  ...  P0  A7 ... A0  A7 ... A0     * |    Page    | Addr MSB | Addr LSB |   (DMA registers)  *  *  Address mapping for channels 5-7:  *  *   A23 ... A17 A16 A15 ... A9 A8 A7 ... A1 A0    (Physical addresses)  *    |  ...  |   \   \   ... \  \  \  ... \  \  *    |  ...  |    \   \   ... \  \  \  ... \  (not used)  *    |  ...  |     \   \   ... \  \  \  ... \  *   P7  ...  P1 (0) A7 A6  ... A0 A7 A6 ... A0     * |      Page      |  Addr MSB   |  Addr LSB  |   (DMA registers)  *  * Again, channels 5-7 transfer _physical_ words (16 bits), so addresses  * and counts _must_ be word-aligned (the lowest address bit is _ignored_ at  * the hardware level, so odd-byte transfers aren't possible).  *  * Transfer count (_not # bytes_) is limited to 64K, represented as actual  * count - 1 : 64K => 0xFFFF, 1 => 0x0000.  Thus, count is always 1 or more,  * and up to 128K bytes may be transferred on channels 5-7 in one operation.   *  */
end_comment

begin_define
define|#
directive|define
name|MAX_DMA_CHANNELS
value|8
end_define

begin_comment
comment|/* 8237 DMA controllers */
end_comment

begin_define
define|#
directive|define
name|IO_DMA1_BASE
value|0x00
end_define

begin_comment
comment|/* 8 bit slave DMA, channels 0..3 */
end_comment

begin_define
define|#
directive|define
name|IO_DMA2_BASE
value|0xC0
end_define

begin_comment
comment|/* 16 bit master DMA, ch 4(=slave input)..7 */
end_comment

begin_comment
comment|/* DMA controller registers */
end_comment

begin_define
define|#
directive|define
name|DMA1_CMD_REG
value|0x08
end_define

begin_comment
comment|/* command register (w) */
end_comment

begin_define
define|#
directive|define
name|DMA1_STAT_REG
value|0x08
end_define

begin_comment
comment|/* status register (r) */
end_comment

begin_define
define|#
directive|define
name|DMA1_REQ_REG
value|0x09
end_define

begin_comment
comment|/* request register (w) */
end_comment

begin_define
define|#
directive|define
name|DMA1_MASK_REG
value|0x0A
end_define

begin_comment
comment|/* single-channel mask (w) */
end_comment

begin_define
define|#
directive|define
name|DMA1_MODE_REG
value|0x0B
end_define

begin_comment
comment|/* mode register (w) */
end_comment

begin_define
define|#
directive|define
name|DMA1_CLEAR_FF_REG
value|0x0C
end_define

begin_comment
comment|/* clear pointer flip-flop (w) */
end_comment

begin_define
define|#
directive|define
name|DMA1_TEMP_REG
value|0x0D
end_define

begin_comment
comment|/* Temporary Register (r) */
end_comment

begin_define
define|#
directive|define
name|DMA1_RESET_REG
value|0x0D
end_define

begin_comment
comment|/* Master Clear (w) */
end_comment

begin_define
define|#
directive|define
name|DMA1_CLR_MASK_REG
value|0x0E
end_define

begin_comment
comment|/* Clear Mask */
end_comment

begin_define
define|#
directive|define
name|DMA1_MASK_ALL_REG
value|0x0F
end_define

begin_comment
comment|/* all-channels mask (w) */
end_comment

begin_define
define|#
directive|define
name|DMA2_CMD_REG
value|0xD0
end_define

begin_comment
comment|/* command register (w) */
end_comment

begin_define
define|#
directive|define
name|DMA2_STAT_REG
value|0xD0
end_define

begin_comment
comment|/* status register (r) */
end_comment

begin_define
define|#
directive|define
name|DMA2_REQ_REG
value|0xD2
end_define

begin_comment
comment|/* request register (w) */
end_comment

begin_define
define|#
directive|define
name|DMA2_MASK_REG
value|0xD4
end_define

begin_comment
comment|/* single-channel mask (w) */
end_comment

begin_define
define|#
directive|define
name|DMA2_MODE_REG
value|0xD6
end_define

begin_comment
comment|/* mode register (w) */
end_comment

begin_define
define|#
directive|define
name|DMA2_CLEAR_FF_REG
value|0xD8
end_define

begin_comment
comment|/* clear pointer flip-flop (w) */
end_comment

begin_define
define|#
directive|define
name|DMA2_TEMP_REG
value|0xDA
end_define

begin_comment
comment|/* Temporary Register (r) */
end_comment

begin_define
define|#
directive|define
name|DMA2_RESET_REG
value|0xDA
end_define

begin_comment
comment|/* Master Clear (w) */
end_comment

begin_define
define|#
directive|define
name|DMA2_CLR_MASK_REG
value|0xDC
end_define

begin_comment
comment|/* Clear Mask */
end_comment

begin_define
define|#
directive|define
name|DMA2_MASK_ALL_REG
value|0xDE
end_define

begin_comment
comment|/* all-channels mask (w) */
end_comment

begin_define
define|#
directive|define
name|DMA_ADDR_0
value|0x00
end_define

begin_comment
comment|/* DMA address registers */
end_comment

begin_define
define|#
directive|define
name|DMA_ADDR_1
value|0x02
end_define

begin_define
define|#
directive|define
name|DMA_ADDR_2
value|0x04
end_define

begin_define
define|#
directive|define
name|DMA_ADDR_3
value|0x06
end_define

begin_define
define|#
directive|define
name|DMA_ADDR_4
value|0xC0
end_define

begin_define
define|#
directive|define
name|DMA_ADDR_5
value|0xC4
end_define

begin_define
define|#
directive|define
name|DMA_ADDR_6
value|0xC8
end_define

begin_define
define|#
directive|define
name|DMA_ADDR_7
value|0xCC
end_define

begin_define
define|#
directive|define
name|DMA_CNT_0
value|0x01
end_define

begin_comment
comment|/* DMA count registers */
end_comment

begin_define
define|#
directive|define
name|DMA_CNT_1
value|0x03
end_define

begin_define
define|#
directive|define
name|DMA_CNT_2
value|0x05
end_define

begin_define
define|#
directive|define
name|DMA_CNT_3
value|0x07
end_define

begin_define
define|#
directive|define
name|DMA_CNT_4
value|0xC2
end_define

begin_define
define|#
directive|define
name|DMA_CNT_5
value|0xC6
end_define

begin_define
define|#
directive|define
name|DMA_CNT_6
value|0xCA
end_define

begin_define
define|#
directive|define
name|DMA_CNT_7
value|0xCE
end_define

begin_define
define|#
directive|define
name|DMA_PAGE_0
value|0x87
end_define

begin_comment
comment|/* DMA page registers */
end_comment

begin_define
define|#
directive|define
name|DMA_PAGE_1
value|0x83
end_define

begin_define
define|#
directive|define
name|DMA_PAGE_2
value|0x81
end_define

begin_define
define|#
directive|define
name|DMA_PAGE_3
value|0x82
end_define

begin_define
define|#
directive|define
name|DMA_PAGE_5
value|0x8B
end_define

begin_define
define|#
directive|define
name|DMA_PAGE_6
value|0x89
end_define

begin_define
define|#
directive|define
name|DMA_PAGE_7
value|0x8A
end_define

begin_define
define|#
directive|define
name|DMA_MODE_READ
value|0x44
end_define

begin_comment
comment|/* I/O to memory, no autoinit, increment, single mode */
end_comment

begin_define
define|#
directive|define
name|DMA_MODE_WRITE
value|0x48
end_define

begin_comment
comment|/* memory to I/O, no autoinit, increment, single mode */
end_comment

begin_define
define|#
directive|define
name|DMA_MODE_CASCADE
value|0xC0
end_define

begin_comment
comment|/* pass thru DREQ->HRQ, DACK<-HLDA only */
end_comment

begin_comment
comment|/* enable/disable a specific DMA channel */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|enable_dma
parameter_list|(
name|unsigned
name|int
name|dmanr
parameter_list|)
block|{
if|if
condition|(
name|dmanr
operator|<=
literal|3
condition|)
name|deb_outb
argument_list|(
argument|dmanr
argument_list|,
argument|DMA1_MASK_REG
argument_list|)
else|else
name|deb_outb
argument_list|(
name|dmanr
operator|&
literal|3
argument_list|,
name|DMA2_MASK_REG
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|disable_dma
parameter_list|(
name|unsigned
name|int
name|dmanr
parameter_list|)
block|{
if|if
condition|(
name|dmanr
operator|<=
literal|3
condition|)
name|deb_outb
argument_list|(
argument|dmanr |
literal|4
argument_list|,
argument|DMA1_MASK_REG
argument_list|)
else|else
name|deb_outb
argument_list|(
operator|(
name|dmanr
operator|&
literal|3
operator|)
operator||
literal|4
argument_list|,
name|DMA2_MASK_REG
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Clear the 'DMA Pointer Flip Flop'.  * Write 0 for LSB/MSB, 1 for MSB/LSB access.  * Use this once to initialize the FF to a known state.  * After that, keep track of it. :-)  * --- In order to do that, the DMA routines below should ---  * --- only be used while interrupts are disabled! ---  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|clear_dma_ff
parameter_list|(
name|unsigned
name|int
name|dmanr
parameter_list|)
block|{
if|if
condition|(
name|dmanr
operator|<=
literal|3
condition|)
name|deb_outb
argument_list|(
literal|0
argument_list|,
argument|DMA1_CLEAR_FF_REG
argument_list|)
else|else
name|deb_outb
argument_list|(
literal|0
argument_list|,
name|DMA2_CLEAR_FF_REG
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* set mode (above) for a specific DMA channel */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|set_dma_mode
parameter_list|(
name|unsigned
name|int
name|dmanr
parameter_list|,
name|char
name|mode
parameter_list|)
block|{
if|if
condition|(
name|dmanr
operator|<=
literal|3
condition|)
name|deb_outb
argument_list|(
argument|mode | dmanr
argument_list|,
argument|DMA1_MODE_REG
argument_list|)
else|else
name|deb_outb
argument_list|(
name|mode
operator||
operator|(
name|dmanr
operator|&
literal|3
operator|)
argument_list|,
name|DMA2_MODE_REG
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Set only the page register bits of the transfer address.  * This is used for successive transfers when we know the contents of  * the lower 16 bits of the DMA current address register, but a 64k boundary  * may have been crossed.  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|set_dma_page
parameter_list|(
name|unsigned
name|int
name|dmanr
parameter_list|,
name|char
name|pagenr
parameter_list|)
block|{
switch|switch
condition|(
name|dmanr
condition|)
block|{
case|case
literal|0
case|:
name|deb_outb
argument_list|(
name|pagenr
argument_list|,
name|DMA_PAGE_0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|deb_outb
argument_list|(
name|pagenr
argument_list|,
name|DMA_PAGE_1
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|deb_outb
argument_list|(
name|pagenr
argument_list|,
name|DMA_PAGE_2
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|deb_outb
argument_list|(
name|pagenr
argument_list|,
name|DMA_PAGE_3
argument_list|)
expr_stmt|;
break|break;
case|case
literal|5
case|:
name|deb_outb
argument_list|(
name|pagenr
operator|&
literal|0xfe
argument_list|,
name|DMA_PAGE_5
argument_list|)
expr_stmt|;
break|break;
case|case
literal|6
case|:
name|deb_outb
argument_list|(
name|pagenr
operator|&
literal|0xfe
argument_list|,
name|DMA_PAGE_6
argument_list|)
expr_stmt|;
break|break;
case|case
literal|7
case|:
name|deb_outb
argument_list|(
name|pagenr
operator|&
literal|0xfe
argument_list|,
name|DMA_PAGE_7
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|/* Set transfer address& page bits for specific DMA channel.  * Assumes dma flipflop is clear.  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|set_dma_addr
parameter_list|(
name|unsigned
name|int
name|dmanr
parameter_list|,
name|unsigned
name|int
name|a
parameter_list|)
block|{
name|set_dma_page
argument_list|(
name|dmanr
argument_list|,
name|a
operator|>>
literal|16
argument_list|)
expr_stmt|;
if|if
condition|(
name|dmanr
operator|<=
literal|3
condition|)
block|{
name|deb_outb
argument_list|(
name|a
operator|&
literal|0xff
argument_list|,
operator|(
operator|(
name|dmanr
operator|&
literal|3
operator|)
operator|<<
literal|1
operator|)
operator|+
name|IO_DMA1_BASE
argument_list|)
expr_stmt|;
name|deb_outb
argument_list|(
argument|(a>>
literal|8
argument|)&
literal|0xff
argument_list|,
argument|((dmanr&
literal|3
argument|)<<
literal|1
argument|) + IO_DMA1_BASE
argument_list|)
block|}
else|else
block|{
name|deb_outb
argument_list|(
operator|(
name|a
operator|>>
literal|1
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
operator|(
name|dmanr
operator|&
literal|3
operator|)
operator|<<
literal|2
operator|)
operator|+
name|IO_DMA2_BASE
argument_list|)
expr_stmt|;
name|deb_outb
argument_list|(
operator|(
name|a
operator|>>
literal|9
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
operator|(
name|dmanr
operator|&
literal|3
operator|)
operator|<<
literal|2
operator|)
operator|+
name|IO_DMA2_BASE
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Set transfer size (max 64k for DMA1..3, 128k for DMA5..7) for  * a specific DMA channel.  * You must ensure the parameters are valid.  * NOTE: from a manual: "the number of transfers is one more  * than the initial word count"! This is taken into account.  * Assumes dma flip-flop is clear.  * NOTE 2: "count" represents _bytes_ and must be even for channels 5-7.  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|set_dma_count
parameter_list|(
name|unsigned
name|int
name|dmanr
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
block|{
name|count
operator|--
expr_stmt|;
if|if
condition|(
name|dmanr
operator|<=
literal|3
condition|)
block|{
name|deb_outb
argument_list|(
name|count
operator|&
literal|0xff
argument_list|,
operator|(
operator|(
name|dmanr
operator|&
literal|3
operator|)
operator|<<
literal|1
operator|)
operator|+
literal|1
operator|+
name|IO_DMA1_BASE
argument_list|)
expr_stmt|;
name|deb_outb
argument_list|(
operator|(
name|count
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
operator|(
name|dmanr
operator|&
literal|3
operator|)
operator|<<
literal|1
operator|)
operator|+
literal|1
operator|+
name|IO_DMA1_BASE
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|deb_outb
argument_list|(
operator|(
name|count
operator|>>
literal|1
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
operator|(
name|dmanr
operator|&
literal|3
operator|)
operator|<<
literal|2
operator|)
operator|+
literal|2
operator|+
name|IO_DMA2_BASE
argument_list|)
expr_stmt|;
name|deb_outb
argument_list|(
operator|(
name|count
operator|>>
literal|9
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
operator|(
name|dmanr
operator|&
literal|3
operator|)
operator|<<
literal|2
operator|)
operator|+
literal|2
operator|+
name|IO_DMA2_BASE
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Get DMA residue count. After a DMA transfer, this  * should return zero. Reading this while a DMA transfer is  * still in progress will return unpredictable results.  * If called before the channel has been used, it may return 1.  * Otherwise, it returns the number of _bytes_ left to transfer.  *  * Assumes DMA flip-flop is clear.  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|get_dma_residue
parameter_list|(
name|unsigned
name|int
name|dmanr
parameter_list|)
block|{
name|unsigned
name|int
name|io_port
init|=
operator|(
name|dmanr
operator|<=
literal|3
operator|)
condition|?
operator|(
operator|(
name|dmanr
operator|&
literal|3
operator|)
operator|<<
literal|1
operator|)
operator|+
literal|1
operator|+
name|IO_DMA1_BASE
else|:
operator|(
operator|(
name|dmanr
operator|&
literal|3
operator|)
operator|<<
literal|2
operator|)
operator|+
literal|2
operator|+
name|IO_DMA2_BASE
decl_stmt|;
comment|/* using short to get 16-bit wrap around */
name|unsigned
name|short
name|count
decl_stmt|;
name|count
operator|=
literal|1
operator|+
name|inb
argument_list|(
name|io_port
argument_list|)
expr_stmt|;
name|count
operator|+=
name|inb
argument_list|(
name|io_port
argument_list|)
operator|<<
literal|8
expr_stmt|;
return|return
operator|(
name|dmanr
operator|<=
literal|3
operator|)
condition|?
name|count
else|:
operator|(
name|count
operator|<<
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* These are in kernel/dma.c: */
end_comment

begin_function_decl
specifier|extern
name|int
name|request_dma
parameter_list|(
name|unsigned
name|int
name|dmanr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reserve a DMA channel */
end_comment

begin_function_decl
specifier|extern
name|void
name|free_dma
parameter_list|(
name|unsigned
name|int
name|dmanr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* release it again */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ASM_DMA_H */
end_comment

end_unit

