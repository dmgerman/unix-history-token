begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  * From: $NetBSD: gatea20.c,v 1.2 1997/10/29 00:32:49 fvdl Exp $  */
end_comment

begin_comment
comment|/* extracted from freebsd:sys/i386/boot/biosboot/io.c */
end_comment

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
ifdef|#
directive|ifdef
name|IBM_L40
name|outb
argument_list|(
literal|0x92
argument_list|,
literal|0x2
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !IBM_L40 */
while|while
condition|(
name|inb
argument_list|(
name|K_STATUS
argument_list|)
operator|&
name|K_IBUF_FUL
condition|)
empty_stmt|;
while|while
condition|(
name|inb
argument_list|(
name|K_STATUS
argument_list|)
operator|&
name|K_OBUF_FUL
condition|)
operator|(
name|void
operator|)
name|inb
argument_list|(
name|K_RDWR
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|K_CMD
argument_list|,
name|KC_CMD_WOUT
argument_list|)
expr_stmt|;
name|delay
argument_list|(
literal|100
argument_list|)
expr_stmt|;
while|while
condition|(
name|inb
argument_list|(
name|K_STATUS
argument_list|)
operator|&
name|K_IBUF_FUL
condition|)
empty_stmt|;
name|outb
argument_list|(
name|K_RDWR
argument_list|,
name|x_20
argument_list|)
expr_stmt|;
name|delay
argument_list|(
literal|100
argument_list|)
expr_stmt|;
while|while
condition|(
name|inb
argument_list|(
name|K_STATUS
argument_list|)
operator|&
name|K_IBUF_FUL
condition|)
empty_stmt|;
endif|#
directive|endif
comment|/* IBM_L40 */
asm|__asm("popfl");
block|}
end_function

end_unit

