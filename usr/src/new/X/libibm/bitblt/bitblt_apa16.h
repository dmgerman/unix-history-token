begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: bitblt_apa16.h,v 10.1 86/11/19 10:51:47 jg Exp $ */
end_comment

begin_comment
comment|/*  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software without  * specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  *  * Written by Daniel Stone, Brown University/IRIS April 23, 1986.  *  * This file contains the defines to do hardware bit block transfers (bitblt's)  * on the APA-16.  */
end_comment

begin_comment
comment|/* $Header: bitblt_apa16.h,v 10.1 86/11/19 10:51:47 jg Exp $ */
end_comment

begin_comment
comment|/* $Source: /u1/X/libibm/bitblt/RCS/bitblt_apa16.h,v $ */
end_comment

begin_comment
comment|/*  * Log 2 of the screen width.  */
end_comment

begin_define
define|#
directive|define
name|LOG2_BPSW
value|7
end_define

begin_comment
comment|/*  * Divide and multiply by Bytes Per Screen Width.  */
end_comment

begin_define
define|#
directive|define
name|DIV_BPSW
parameter_list|(
name|value
parameter_list|)
value|((value)>> LOG2_BPSW)
end_define

begin_define
define|#
directive|define
name|MUL_BPSW
parameter_list|(
name|value
parameter_list|)
value|((value)<< LOG2_BPSW)
end_define

begin_comment
comment|/*  * Screen dimensions in pixels.  */
end_comment

begin_define
define|#
directive|define
name|SCREEN_WD
value|1024
end_define

begin_define
define|#
directive|define
name|HIDDEN_WD
value|SCREEN_WD
end_define

begin_define
define|#
directive|define
name|SCREEN_HT
value|768
end_define

begin_define
define|#
directive|define
name|HIDDEN_HT
value|256
end_define

begin_comment
comment|/*  * Screen dimensions in words.  */
end_comment

begin_define
define|#
directive|define
name|SCREEN_WORD_WD
value|(SCREEN_WD/BPW)
end_define

begin_define
define|#
directive|define
name|HIDDEN_WORD_WD
value|(HIDDEN_WD/BPW)
end_define

begin_define
define|#
directive|define
name|SCREEN_WORD_HT
value|(SCREEN_HT/BPW)
end_define

begin_define
define|#
directive|define
name|HIDDEN_WORD_HT
value|(HIDDEN_HT/BPW)
end_define

begin_define
define|#
directive|define
name|IO_ADDR
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|MODEL_IO_ADDR
value|(IO_ADDR | 0x04000000)
end_define

begin_comment
comment|/*  * Hidden frame buffer address.  */
end_comment

begin_define
define|#
directive|define
name|HID_OFFSET
value|0x00018000
end_define

begin_define
define|#
directive|define
name|HID_APA16BASE
value|(APA16BASE + HID_OFFSET)
end_define

begin_comment
comment|/*  * Within the hidden screen area there is an area for 2 hardware locators.  */
end_comment

begin_define
define|#
directive|define
name|LOCATOR_OFFSET
value|(HID_OFFSET + 0x800)
end_define

begin_define
define|#
directive|define
name|LOCATOR_APA16BASE
value|(APA16BASE + LOCATOR_OFFSET)
end_define

begin_comment
comment|/*  * The bottom right corners of both locators.  */
end_comment

begin_define
define|#
directive|define
name|AND_LOCATOR_RT
value|48
end_define

begin_define
define|#
directive|define
name|AND_LOCATOR_BM
value|848
end_define

begin_define
define|#
directive|define
name|XOR_LOCATOR_RT
value|(48*2)
end_define

begin_define
define|#
directive|define
name|XOR_LOCATOR_BM
value|AND_LOCATOR_BM
end_define

begin_define
define|#
directive|define
name|SAVE_AND_LOCATOR_RT
value|(48*3)
end_define

begin_define
define|#
directive|define
name|SAVE_AND_LOCATOR_BM
value|848
end_define

begin_define
define|#
directive|define
name|SAVE_XOR_LOCATOR_RT
value|(48*4)
end_define

begin_define
define|#
directive|define
name|SAVE_XOR_LOCATOR_BM
value|AND_LOCATOR_BM
end_define

begin_comment
comment|/*  * Dimensions of the locators found in the hidden screen area.  */
end_comment

begin_define
define|#
directive|define
name|HARD_LOCATOR_WD
value|48
end_define

begin_define
define|#
directive|define
name|HARD_LOCATOR_HT
value|64
end_define

begin_comment
comment|/*  * Spot on the APA-16's memory where the hardware cursor is located.  */
end_comment

begin_define
define|#
directive|define
name|AND_LOCATOR
value|LOCATOR_APA16BASE
end_define

begin_define
define|#
directive|define
name|XOR_LOCATOR
value|(LOCATOR_APA16BASE + BTOB(HARD_LOCATOR_WD))
end_define

begin_comment
comment|/*  * Spot on the APA-16's memory where we will save the current locator.  */
end_comment

begin_define
define|#
directive|define
name|SAVE_AND_LOCATOR
value|(LOCATOR_APA16BASE + BTOB(HARD_LOCATOR_WD*2))
end_define

begin_define
define|#
directive|define
name|SAVE_XOR_LOCATOR
value|(LOCATOR_APA16BASE + BTOB(HARD_LOCATOR_WD*3))
end_define

begin_comment
comment|/*  * Within the hidden screen area there is an area for hidden fonts.  */
end_comment

begin_define
define|#
directive|define
name|FONT_Y_COORD
value|848
end_define

begin_define
define|#
directive|define
name|FONT_OFFSET
value|(HID_OFFSET + 0x2800)
end_define

begin_define
define|#
directive|define
name|FONT_APA16BASE
value|(APA16BASE + FONT_OFFSET)
end_define

begin_define
define|#
directive|define
name|FONT_XBASE
value|1
end_define

begin_define
define|#
directive|define
name|FONT_YBASE
value|848
end_define

begin_define
define|#
directive|define
name|FONT_YBASE_BOTTOM
value|896
end_define

begin_comment
comment|/*  * Within the hidden screen area there is an area for a rasterop queue.  */
end_comment

begin_define
define|#
directive|define
name|QUE_Y_COORD
value|896
end_define

begin_define
define|#
directive|define
name|QUE_OFFSET
value|(HID_OFFSET + 0x4000)
end_define

begin_define
define|#
directive|define
name|QUE_APA16BASE
value|(APA16BASE + QUE_OFFSET)
end_define

begin_define
define|#
directive|define
name|RESERVE_Y_COORD
value|1006
end_define

begin_define
define|#
directive|define
name|RESERVE_OFFSET
value|(HID_OFFSET + 0x7700)
end_define

begin_define
define|#
directive|define
name|LAST_QUE_OFFSET
value|(RESERVE_OFFSET - 2)
end_define

begin_define
define|#
directive|define
name|LAST_QUE_APA16BASE
value|(APA16BASE + LAST_QUE_OFFSET)
end_define

begin_define
define|#
directive|define
name|QUE_WD
value|SCREEN_WD
end_define

begin_define
define|#
directive|define
name|QUE_HT
value|110
end_define

begin_comment
comment|/*  * Macro that builds the queue pointer using the screen address which is a  * short pointer.  */
end_comment

begin_define
define|#
directive|define
name|SPTR_TO_QPTR
parameter_list|(
name|sptr
parameter_list|)
value|((short)(DIV_2((long)sptr& 0x0000ffff) | \ 				 0xE000))
end_define

begin_comment
comment|/*  * Macro that takes a queue pointer (an unsigned short) and builds a unsigned  * short pointer from it.  */
end_comment

begin_define
define|#
directive|define
name|QPTR_TO_SPTR
parameter_list|(
name|qptr
parameter_list|)
value|((unsigned short *)(MUL_2(qptr)|QUE_APA16BASE))
end_define

begin_comment
comment|/*  * Macros that take a short pointer to the bitmap and return the x value in bits  * and the y value in scanlines.  */
end_comment

begin_define
define|#
directive|define
name|SPTR_TO_X
parameter_list|(
name|sptr
parameter_list|)
value|(MUL_BPB((long)sptr& 0x007f))
end_define

begin_define
define|#
directive|define
name|SPTR_TO_Y
parameter_list|(
name|sptr
parameter_list|)
value|(DIV_BPSW((long)sptr& 0x1ff80))
end_define

begin_define
define|#
directive|define
name|X_LOCATOR_R
value|((unsigned short *)(MODEL_IO_ADDR | 0xD9F800))
end_define

begin_define
define|#
directive|define
name|Y_LOCATOR_R
value|((unsigned short *)(MODEL_IO_ADDR | 0xD9F802))
end_define

begin_define
define|#
directive|define
name|QUE_COUNT_R
value|((unsigned short *)(MODEL_IO_ADDR | 0xD9F804))
end_define

begin_define
define|#
directive|define
name|QUE_PTR_R
value|((unsigned short *)(MODEL_IO_ADDR | 0xD9f806))
end_define

begin_define
define|#
directive|define
name|QUE_LINK_PTR_R
value|((unsigned short *)(MODEL_IO_ADDR | 0xD9f814))
end_define

begin_define
define|#
directive|define
name|QUE_MODE_R
value|((unsigned short *)(MODEL_IO_ADDR | 0xD9f816))
end_define

begin_comment
comment|/*  * Macros and defines for the mode register.  */
end_comment

begin_define
define|#
directive|define
name|MODE_R
value|(IO_ADDR | 0x0D10)
end_define

begin_define
define|#
directive|define
name|ACCESS_BIT
value|0x8000
end_define

begin_define
define|#
directive|define
name|SET_ACCESS_BIT
parameter_list|(
name|mode
parameter_list|)
value|(mode |= ACCESS_BIT)
end_define

begin_define
define|#
directive|define
name|CLR_ACCESS_BIT
parameter_list|(
name|mode
parameter_list|)
value|(mode&= ~ACCESS_BIT)
end_define

begin_define
define|#
directive|define
name|PAGE_SELECT
value|0x4000
end_define

begin_define
define|#
directive|define
name|WR_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|SET_WR_MASK
parameter_list|(
name|mode
parameter_list|,
name|msk
parameter_list|)
value|mode = ((mode& ~WR_MASK)|((msk<<8)& WR_MASK))
end_define

begin_define
define|#
directive|define
name|CLR_WR_MASK
parameter_list|(
name|mode
parameter_list|)
value|mode&= ~WR_MASK
end_define

begin_define
define|#
directive|define
name|LOGIC_FUNC
value|0x00f0
end_define

begin_define
define|#
directive|define
name|SET_LOGIC_FUNC
parameter_list|(
name|mode
parameter_list|,
name|fc
parameter_list|)
value|mode = ((mode& ~LOGIC_FUNC)| \ 						((fc<<4)& LOGIC_FUNC))
end_define

begin_define
define|#
directive|define
name|CLR_LOGIC_FUNC
parameter_list|(
name|mode
parameter_list|)
value|mode&= ~LOGIC_FUNC
end_define

begin_define
define|#
directive|define
name|START_BIT
value|0x000f
end_define

begin_define
define|#
directive|define
name|SET_START_BIT
parameter_list|(
name|mode
parameter_list|,
name|sb
parameter_list|)
value|mode = ((mode& ~START_BIT)|(sb& START_BIT))
end_define

begin_define
define|#
directive|define
name|CLR_START_BIT
parameter_list|(
name|mode
parameter_list|)
value|mode&= ~START_BIT
end_define

begin_comment
comment|/*  * More understandable names for access bit.  */
end_comment

begin_define
define|#
directive|define
name|HORZ_ACCESS
parameter_list|(
name|mode
parameter_list|)
value|SET_ACCESS_BIT(mode)
end_define

begin_define
define|#
directive|define
name|VERT_ACCESS
parameter_list|(
name|mode
parameter_list|)
value|CLR_ACCESS_BIT(mode)
end_define

begin_comment
comment|/*  * Control/Status register.  */
end_comment

begin_define
define|#
directive|define
name|CS_R
value|(IO_ADDR | 0x0D12)
end_define

begin_define
define|#
directive|define
name|BACKGRND_BIT
value|0x0400
end_define

begin_define
define|#
directive|define
name|BLACK_ON_WHITE
value|*(unsigned short *)(CS_R) |= BACKGRND_BIT
end_define

begin_define
define|#
directive|define
name|WHITE_ON_BLACK
value|*(unsigned short *)(CS_R)&= ~BACKGRND_BIT
end_define

begin_define
define|#
directive|define
name|TOGGLE_BACKGRND
value|*(unsigned short *)(CS_R) ^= BACKGRND_BIT
end_define

begin_comment
comment|/*  * Increment Queue register.  NOTE: Reg is any register the data is ignored.  */
end_comment

begin_define
define|#
directive|define
name|INCR_QUE_R
value|(IO_ADDR | 0x0D14)
end_define

begin_define
define|#
directive|define
name|INCR_QUE_COUNT
parameter_list|(
name|reg
parameter_list|)
value|*(unsigned short *)INCR_QUE_R = (unsigned short)reg
end_define

begin_comment
comment|/*  * Wait for the rasterop engine to stop.  If it does not stop then kill it  * after a specified time.  The way this works is this, we poll the queue  * counter register waiting for it to zero (which means the rasterop has  * stopped), if it doesn't zero by QUE_TIME_OUT then assume something drastic  * went wrong and initialize the APA-16.  *   * Later we will re-write this to receive an interrupt.  */
end_comment

begin_define
define|#
directive|define
name|QUE_TIME_OUT
value|500000
end_define

begin_define
define|#
directive|define
name|WAIT_QUE
parameter_list|(
name|c
parameter_list|,
name|num
parameter_list|)
value|{					\ 	if (*QUE_COUNT_R != 0)	{				\ 		c = 0;						\ 		while (*QUE_COUNT_R != 0) {			\ 			if (c++ == QUE_TIME_OUT) {		\ 				c = *QUE_COUNT_R;		\ 				RESET_APA16(c);		\ 				printf("RESET APA-16! n:%d count:%d\r\n", \ 					num,c);			\ 				break;				\ 			}					\ 		}						\ 	}							\ }
end_define

begin_comment
comment|/*  * Video data output.  */
end_comment

begin_define
define|#
directive|define
name|VD_OUT
value|(IO_ADDR | 0xD1A)
end_define

begin_comment
comment|/*  * Disable video data output (pass it a temporary register).  */
end_comment

begin_define
define|#
directive|define
name|DISABLE_VD_OUT
parameter_list|(
name|reg
parameter_list|)
value|reg = *(unsigned short *)VD_OUT
end_define

begin_comment
comment|/*  * Enable video data output.  NOTE: Reg is any register. The data in "reg"  * is ignored.  */
end_comment

begin_define
define|#
directive|define
name|ENABLE_VD_OUT
parameter_list|(
name|reg
parameter_list|)
value|*(unsigned short *)VD_OUT = (unsigned short)reg
end_define

begin_comment
comment|/*  * Reset adaptor register.  */
end_comment

begin_define
define|#
directive|define
name|RA_R
value|(IO_ADDR | 0x0D20)
end_define

begin_define
define|#
directive|define
name|RESET_APA16
parameter_list|(
name|reg
parameter_list|)
value|*(unsigned short *)RA_R = (unsigned short)reg;
end_define

begin_comment
comment|/*  * Disable DMA processing.  NOTE: Reg is any register the data is ignored.  */
end_comment

begin_define
define|#
directive|define
name|DISABLE_DMA
value|(IO_ADDR | 0x0D26)
end_define

begin_define
define|#
directive|define
name|DISABLE_DMA_PROC
parameter_list|(
name|reg
parameter_list|)
value|*(unsigned short *)DISABLE_DMA=(unsigned short)reg
end_define

begin_define
define|#
directive|define
name|ENABLE_DMA
value|(IO_ADDR | 0x0D28)
end_define

begin_define
define|#
directive|define
name|ENABLE_DMA_PROC
parameter_list|(
name|reg
parameter_list|)
value|*(unsigned short *)ENABLE_DMA = (unsigned short)reg
end_define

begin_comment
comment|/*  * Default initial values for the APA-16 registers.   */
end_comment

begin_define
define|#
directive|define
name|MODER_DEFAULT
value|0x8090
end_define

begin_define
define|#
directive|define
name|CSR_DEFAULT
value|0x0400
end_define

begin_comment
comment|/*  * Defines and macros for the rasterop commands.  * ROT stands for Raster Operation Type.  * LF stands for logic function.  */
end_comment

begin_define
define|#
directive|define
name|DECR_QUE_COUNT
value|0x0800
end_define

begin_define
define|#
directive|define
name|ROT_WRDST
value|0x02F0
end_define

begin_define
define|#
directive|define
name|ROT_RECTCP
value|0x0300
end_define

begin_define
define|#
directive|define
name|ROT_TDDMA
value|0x0370
end_define

begin_define
define|#
directive|define
name|LF_CLEAR
value|0x0000
end_define

begin_define
define|#
directive|define
name|LF_DSTandSRC
value|0x0001
end_define

begin_define
define|#
directive|define
name|LF_NotDSTandSRC
value|0x0002
end_define

begin_define
define|#
directive|define
name|LF_COPYDST
value|0x0003
end_define

begin_define
define|#
directive|define
name|LF_DSTandNotSRC
value|0x0008
end_define

begin_define
define|#
directive|define
name|LF_COPYSRC
value|0x0009
end_define

begin_define
define|#
directive|define
name|LF_NotDST
value|0x0009
end_define

begin_define
define|#
directive|define
name|LF_DSTxorSRC
value|0x000a
end_define

begin_define
define|#
directive|define
name|LF_DSTorSRC
value|0x000b
end_define

begin_define
define|#
directive|define
name|LF_NotDSTorNotSRC
value|0x000e
end_define

begin_define
define|#
directive|define
name|LF_SET
value|0x000f
end_define

begin_define
define|#
directive|define
name|IS_ROT_WRDST
parameter_list|(
name|excmd
parameter_list|)
value|((excmd& 0x03f0) == ROT_WRDST)
end_define

begin_comment
comment|/*  * Rasterop execute command instruction.  */
end_comment

begin_define
define|#
directive|define
name|BUILD_EXCMD
parameter_list|(
name|decrflag
parameter_list|,
name|ROT_type
parameter_list|,
name|LF_type
parameter_list|)
define|\
value|(0xD000 | decrflag | ROT_type | LF_type)
end_define

begin_define
define|#
directive|define
name|Y_BRCH_BASE
value|896
end_define

begin_define
define|#
directive|define
name|X_BRCH_BASE
value|0
end_define

begin_comment
comment|/*  * Rasterop branch instruction.  Both X and Y should be given in bits.  * Y must be between 896 and 1023. X must fall on a word boundrary.    */
end_comment

begin_define
define|#
directive|define
name|BUILD_BRCH
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((Y_BRCH_BASE<< 6) | ((y)<< 6) | DIV_BPW(x))
end_define

begin_define
define|#
directive|define
name|HIGH_BYTE
parameter_list|(
name|addr
parameter_list|)
value|(((unsigned long)addr& 0x1fe0000)>> 17)
end_define

begin_define
define|#
directive|define
name|MID_BYTE
parameter_list|(
name|addr
parameter_list|)
value|(((unsigned long)addr& 0x1fe00)>> 9)
end_define

begin_define
define|#
directive|define
name|LOW_BYTE
parameter_list|(
name|addr
parameter_list|)
value|(((unsigned long)addr& 0x1fe)>> 1)
end_define

begin_comment
comment|/*  * Queue command codes for the registers on the APA-16.  */
end_comment

begin_define
define|#
directive|define
name|REG_Y_LOOP
value|0x0000
end_define

begin_define
define|#
directive|define
name|REG_X_LOOP
value|0x1000
end_define

begin_define
define|#
directive|define
name|REG_GEN_A
value|0x2000
end_define

begin_define
define|#
directive|define
name|REG_GEN_B
value|0x3000
end_define

begin_define
define|#
directive|define
name|REG_Y_SRC
value|0x4000
end_define

begin_define
define|#
directive|define
name|REG_X_SRC
value|0x5000
end_define

begin_define
define|#
directive|define
name|REG_Y_DST
value|0x6000
end_define

begin_define
define|#
directive|define
name|REG_X_DST
value|0x7000
end_define

begin_define
define|#
directive|define
name|REG_Y_BACKUP
value|0x8000
end_define

begin_define
define|#
directive|define
name|REG_X_BACKUP
value|0x9000
end_define

begin_define
define|#
directive|define
name|REG_HIGHBYTE
value|0xa000
end_define

begin_define
define|#
directive|define
name|REG_LOWBYTE
value|0xb000
end_define

begin_comment
comment|/*  * Now that we've defined those names for hardware guru's lets have some  * real names.  Notice how the HIGHBYTE register (whatever that is) is  * used as the Y destination register when dealing with rectangle copys  * also notice that the Y_LOOP register is used (as expected) as the height  * register during rectangle copies but that the Y_BACKUP register is used  * when only dealing with the destination.  */
end_comment

begin_define
define|#
directive|define
name|XDST_REG
value|REG_X_DST
end_define

begin_define
define|#
directive|define
name|YDST_REG
value|REG_Y_DST
end_define

begin_define
define|#
directive|define
name|XSRC_REG
value|REG_X_SRC
end_define

begin_define
define|#
directive|define
name|YSRC_REG
value|REG_Y_SRC
end_define

begin_define
define|#
directive|define
name|RECT_YDST_REG
value|REG_HIGHBYTE
end_define

begin_define
define|#
directive|define
name|WIDTH_REG
value|REG_X_BACKUP
end_define

begin_define
define|#
directive|define
name|HEIGHT_REG
value|REG_Y_BACKUP
end_define

begin_define
define|#
directive|define
name|RECT_HEIGHT_REG
value|REG_Y_LOOP
end_define

begin_define
define|#
directive|define
name|MAXPARAM
value|1024
end_define

begin_define
define|#
directive|define
name|VISPARAM
value|768
end_define

begin_define
define|#
directive|define
name|MINPARAM
value|1
end_define

begin_comment
comment|/*  * Register load command.  */
end_comment

begin_define
define|#
directive|define
name|BUILD_REGLOAD
parameter_list|(
name|REG_type
parameter_list|,
name|param
parameter_list|)
value|(REG_type | (param& (MAXPARAM-1)))
end_define

begin_comment
comment|/*  * Indicates a there is no bit image for this font.  */
end_comment

begin_define
define|#
directive|define
name|NULLIMAGE
value|MAXPARAM+1
end_define

begin_comment
comment|/*  * A nulls for pointers.  */
end_comment

begin_define
define|#
directive|define
name|US_NIL
value|((unsigned short *)0)
end_define

begin_define
define|#
directive|define
name|S_NIL
value|((short *)0)
end_define

begin_comment
comment|/*  * Execute the commands set up in the queue at Qaddr but first wait for  * the last command to finish, then set up the queue register pointer  * and increment the count nexec number of times.  */
end_comment

begin_define
define|#
directive|define
name|EXECUTE_QUE_CMDS
parameter_list|(
name|Qaddr
parameter_list|,
name|nexec
parameter_list|,
name|index
parameter_list|)
define|\
value|{							\ 		register i,tmp;					\ 		WAIT_QUE(index);				\ 		*QUE_PTR_R = Qaddr;				\ 		for (i = nexec + 1; --i;)			\ 			INCR_QUE_COUNT(tmp);			\ 	}
end_define

begin_comment
comment|/*  * Take an index into one of the queue instructions, wait for the last command  * to finish, set up the queue register pointer and increment the count the  * right number of times.  */
end_comment

begin_define
define|#
directive|define
name|DO_QUE_CMD
parameter_list|(
name|index
parameter_list|)
value|EXECUTE_QUE_CMDS(QUEinstr[index].Qaddr, \ 					   QUEinstr[index].nexec,index)
end_define

begin_comment
comment|/*  * Number of words needed to do a destination only command is 5 and  * the number of words needed to do a rectangle copy is 7.  */
end_comment

begin_define
define|#
directive|define
name|DSTCMDWORDS
value|5
end_define

begin_define
define|#
directive|define
name|RECTCMDWORDS
value|7
end_define

end_unit

