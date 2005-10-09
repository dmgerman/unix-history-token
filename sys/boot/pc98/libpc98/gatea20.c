begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $NetBSD: gatea20.c,v 1.2 1997/10/29 00:32:49 fvdl Exp $  */
end_comment

begin_comment
comment|/* extracted from freebsd:sys/i386/boot/biosboot/io.c */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<bootstrap.h>
end_include

begin_include
include|#
directive|include
file|"libi386.h"
end_include

begin_define
define|#
directive|define
name|K_RDWR
value|0x60
end_define

begin_comment
comment|/* keyboard data& cmds (read/write) */
end_comment

begin_define
define|#
directive|define
name|K_STATUS
value|0x64
end_define

begin_comment
comment|/* keyboard status */
end_comment

begin_define
define|#
directive|define
name|K_CMD
value|0x64
end_define

begin_comment
comment|/* keybd ctlr command (write-only) */
end_comment

begin_define
define|#
directive|define
name|K_OBUF_FUL
value|0x01
end_define

begin_comment
comment|/* output buffer full */
end_comment

begin_define
define|#
directive|define
name|K_IBUF_FUL
value|0x02
end_define

begin_comment
comment|/* input buffer full */
end_comment

begin_define
define|#
directive|define
name|KC_CMD_WIN
value|0xd0
end_define

begin_comment
comment|/* read  output port */
end_comment

begin_define
define|#
directive|define
name|KC_CMD_WOUT
value|0xd1
end_define

begin_comment
comment|/* write output port */
end_comment

begin_define
define|#
directive|define
name|KB_A20
value|0x9f
end_define

begin_comment
comment|/* enable A20, 					   reset (!), 					   enable output buffer full interrupt 					   enable data line 					   disable clock line */
end_comment

begin_comment
comment|/*  * Gate A20 for high memory  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|x_20
init|=
name|KB_A20
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|gateA20
parameter_list|()
block|{
asm|__asm("pushfl ; cli");
name|outb
argument_list|(
literal|0xf2
argument_list|,
literal|0x00
argument_list|)
expr_stmt|;
name|outb
argument_list|(
literal|0xf6
argument_list|,
literal|0x02
argument_list|)
expr_stmt|;
asm|__asm("popfl");
block|}
end_function

end_unit

