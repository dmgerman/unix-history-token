begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: bitblt_aed.h,v 10.1 86/11/19 10:51:37 jg Exp $ */
end_comment

begin_comment
comment|/* aed.h - Defines and macros needed to support AED  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_define
define|#
directive|define
name|AED_BM_ADDR
value|0xEF100000
end_define

begin_define
define|#
directive|define
name|AED_WIDTH
value|1024
end_define

begin_define
define|#
directive|define
name|AED_HEIGHT
value|800
end_define

begin_define
define|#
directive|define
name|AED_BM_SIZE
value|(((((AED_WIDTH/8) * AED_HEIGHT) + 2047) / 2048) * 2048)
end_define

begin_define
define|#
directive|define
name|AED_COLOR
value|((int *)(AED_BM_ADDR + AED_BM_SIZE + 0))
end_define

begin_define
define|#
directive|define
name|AED_CMDQ_SEMA
value|(*((int *)(AED_BM_ADDR + AED_BM_SIZE + 4)))
end_define

begin_define
define|#
directive|define
name|AED_CMDQ_INDEX
value|(*((int *)(AED_BM_ADDR + AED_BM_SIZE + 8)))
end_define

begin_define
define|#
directive|define
name|AED_CMDQ
value|((struct aed_cmd *)(AED_BM_ADDR + AED_BM_SIZE + 128))
end_define

begin_define
define|#
directive|define
name|AED_CMD_SIZE
value|64
end_define

begin_comment
comment|/* size of a command on queue */
end_comment

begin_define
define|#
directive|define
name|AED_MAX_CMDS
value|((2048 - 128) / AED_CMD_SIZE)
end_define

begin_comment
comment|/*  * Types of aed commands  */
end_comment

begin_define
define|#
directive|define
name|AED_ECHO_RECT
value|1
end_define

begin_define
define|#
directive|define
name|AED_DRAW_LINE
value|2
end_define

begin_define
define|#
directive|define
name|AED_SCREEN_COPY
value|3
end_define

begin_comment
comment|/*  * echo a rectangle from the simulated bitmap to the display.  */
end_comment

begin_struct
struct|struct
name|aed_echo_rect
block|{
name|short
name|origin_y
decl_stmt|;
name|short
name|origin_x
decl_stmt|;
name|short
name|corner_y
decl_stmt|;
name|short
name|corner_x
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * draw a line  */
end_comment

begin_struct
struct|struct
name|aed_draw_line
block|{
name|short
name|from_x
decl_stmt|;
name|short
name|from_y
decl_stmt|;
name|short
name|to_x
decl_stmt|;
name|short
name|to_y
decl_stmt|;
name|short
name|rule
decl_stmt|;
name|short
name|width
decl_stmt|;
name|short
name|color
decl_stmt|;
name|u_short
name|pat
decl_stmt|;
name|short
name|patlen
decl_stmt|;
name|short
name|top
decl_stmt|;
name|short
name|left
decl_stmt|;
name|short
name|bottom
decl_stmt|;
name|short
name|right
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * screen to screen copy  */
end_comment

begin_struct
struct|struct
name|aed_screen_copy
block|{
name|short
name|from_x
decl_stmt|;
name|short
name|from_y
decl_stmt|;
name|short
name|to_x
decl_stmt|;
name|short
name|to_y
decl_stmt|;
name|short
name|width
decl_stmt|;
name|short
name|height
decl_stmt|;
name|short
name|rule
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * AED command struct  */
end_comment

begin_struct
struct|struct
name|aed_cmd
block|{
name|long
name|cmd
decl_stmt|;
union|union
name|cmd_block
block|{
name|struct
name|aed_echo_rect
name|echo_rect
decl_stmt|;
name|struct
name|aed_draw_line
name|draw_line
decl_stmt|;
name|struct
name|aed_screen_copy
name|screen_copy
decl_stmt|;
block|}
name|aed_cmd_block
union|;
name|char
name|padding
index|[
name|AED_CMD_SIZE
operator|-
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
expr|union
name|cmd_block
argument_list|)
index|]
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ECHO_RECT
value|aed_cmd_block.echo_rect
end_define

begin_define
define|#
directive|define
name|SCREEN_COPY
value|aed_cmd_block.screen_copy
end_define

begin_define
define|#
directive|define
name|DRAW_LINE
value|aed_cmd_block.draw_line
end_define

begin_comment
comment|/*  * map bltter combination rule to AED combination rule  */
end_comment

begin_decl_stmt
specifier|static
name|u_char
name|aed_rules
index|[
literal|16
index|]
init|=
block|{
literal|0
block|,
literal|8
block|,
literal|4
block|,
literal|12
block|,
literal|2
block|,
literal|10
block|,
literal|6
block|,
literal|14
block|,
literal|1
block|,
literal|9
block|,
literal|5
block|,
literal|13
block|,
literal|3
block|,
literal|11
block|,
literal|7
block|,
literal|15
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AED_RULE
parameter_list|(
name|x_rule
parameter_list|)
value|(((u_short)aed_rules[x_rule])& 0x0F)
end_define

end_unit

