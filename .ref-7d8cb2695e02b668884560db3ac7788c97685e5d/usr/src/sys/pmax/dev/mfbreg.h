begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)mfbreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * This configuration uses two twin Bt431s and a single Bt455 colour map.  * (Yep, that's a colour map on a single bitplane mono display)  */
end_comment

begin_define
define|#
directive|define
name|SET_VALUE
parameter_list|(
name|x
parameter_list|)
value|(((x)<<8)|((x)&0xff))
end_define

begin_define
define|#
directive|define
name|GET_VALUE
parameter_list|(
name|x
parameter_list|)
value|((x)&0xff)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|u_short
name|addr_lo
decl_stmt|;
name|short
name|pad0
decl_stmt|;
specifier|volatile
name|u_short
name|addr_hi
decl_stmt|;
name|short
name|pad1
decl_stmt|;
specifier|volatile
name|u_short
name|addr_cmap
decl_stmt|;
name|short
name|pad2
decl_stmt|;
specifier|volatile
name|u_short
name|addr_reg
decl_stmt|;
name|short
name|pad3
decl_stmt|;
block|}
name|bt431_regmap_t
typedef|;
end_typedef

begin_comment
comment|/*  * Generic register access  */
end_comment

begin_comment
comment|/* when using autoincrement */
end_comment

begin_define
define|#
directive|define
name|BT431_WRITE_REG_AUTOI
parameter_list|(
name|regs
parameter_list|,
name|val
parameter_list|)
value|{ \ 		(regs)->addr_reg = SET_VALUE(val); \ 		MachEmptyWriteBuffer(); \ 	}
end_define

begin_define
define|#
directive|define
name|BT431_READ_REG_AUTOI
parameter_list|(
name|regs
parameter_list|)
define|\
value|GET_VALUE(((regs)->addr_reg))
end_define

begin_define
define|#
directive|define
name|BT431_WRITE_CMAP_AUTOI
parameter_list|(
name|regs
parameter_list|,
name|val
parameter_list|)
value|{ \ 		(regs)->addr_cmap = (val); \ 		MachEmptyWriteBuffer(); \ 	}
end_define

begin_define
define|#
directive|define
name|BT431_READ_CMAP_AUTOI
parameter_list|(
name|regs
parameter_list|)
define|\
value|((regs)->addr_cmap)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|u_char
name|addr_cmap
decl_stmt|;
name|char
name|pad0
index|[
literal|3
index|]
decl_stmt|;
specifier|volatile
name|u_char
name|addr_cmap_data
decl_stmt|;
name|char
name|pad1
index|[
literal|3
index|]
decl_stmt|;
specifier|volatile
name|u_char
name|addr_clr
decl_stmt|;
name|char
name|pad2
index|[
literal|3
index|]
decl_stmt|;
specifier|volatile
name|u_char
name|addr_ovly
decl_stmt|;
name|char
name|pad3
index|[
literal|3
index|]
decl_stmt|;
block|}
name|bt455_regmap_t
typedef|;
end_typedef

begin_comment
comment|/*  * Generic register access  */
end_comment

begin_define
define|#
directive|define
name|BT455_SELECT_ENTRY
parameter_list|(
name|regs
parameter_list|,
name|regno
parameter_list|)
value|{ \ 		(regs)->addr_cmap = (regno)&0x0f; \ 		MachEmptyWriteBuffer(); \ 	}
end_define

begin_comment
comment|/*  * Additional registers addressed indirectly  */
end_comment

begin_define
define|#
directive|define
name|BT431_REG_CMD
value|0x0000
end_define

begin_define
define|#
directive|define
name|BT431_REG_CXLO
value|0x0001
end_define

begin_define
define|#
directive|define
name|BT431_REG_CXHI
value|0x0002
end_define

begin_define
define|#
directive|define
name|BT431_REG_CYLO
value|0x0003
end_define

begin_define
define|#
directive|define
name|BT431_REG_CYHI
value|0x0004
end_define

begin_define
define|#
directive|define
name|BT431_REG_WXLO
value|0x0005
end_define

begin_define
define|#
directive|define
name|BT431_REG_WXHI
value|0x0006
end_define

begin_define
define|#
directive|define
name|BT431_REG_WYLO
value|0x0007
end_define

begin_define
define|#
directive|define
name|BT431_REG_WYHI
value|0x0008
end_define

begin_define
define|#
directive|define
name|BT431_REG_WWLO
value|0x0009
end_define

begin_define
define|#
directive|define
name|BT431_REG_WWHI
value|0x000a
end_define

begin_define
define|#
directive|define
name|BT431_REG_WHLO
value|0x000b
end_define

begin_define
define|#
directive|define
name|BT431_REG_WHHI
value|0x000c
end_define

begin_define
define|#
directive|define
name|BT431_REG_CRAM_BASE
value|0x0000
end_define

begin_define
define|#
directive|define
name|BT431_REG_CRAM_END
value|0x01ff
end_define

begin_comment
comment|/*  * Command register  */
end_comment

begin_define
define|#
directive|define
name|BT431_CMD_CURS_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|BT431_CMD_XHAIR_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|BT431_CMD_OR_CURSORS
value|0x10
end_define

begin_define
define|#
directive|define
name|BT431_CMD_AND_CURSORS
value|0x00
end_define

begin_define
define|#
directive|define
name|BT431_CMD_1_1_MUX
value|0x00
end_define

begin_define
define|#
directive|define
name|BT431_CMD_4_1_MUX
value|0x04
end_define

begin_define
define|#
directive|define
name|BT431_CMD_5_1_MUX
value|0x08
end_define

begin_define
define|#
directive|define
name|BT431_CMD_xxx_MUX
value|0x0c
end_define

begin_define
define|#
directive|define
name|BT431_CMD_THICK_1
value|0x00
end_define

begin_define
define|#
directive|define
name|BT431_CMD_THICK_3
value|0x01
end_define

begin_define
define|#
directive|define
name|BT431_CMD_THICK_5
value|0x02
end_define

begin_define
define|#
directive|define
name|BT431_CMD_THICK_7
value|0x03
end_define

end_unit

