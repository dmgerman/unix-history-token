begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: clockreg.h 1.14 91/01/18$  *  *	@(#)clockreg.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * HP300 "real time clock" (MC6840) registers  */
end_comment

begin_struct
struct|struct
name|clkreg
block|{
name|u_char
name|clk_dummy1
decl_stmt|;
name|u_char
name|clk_cr3
decl_stmt|;
define|#
directive|define
name|clk_cr1
value|clk_cr3
name|u_char
name|clk_dummy2
decl_stmt|;
name|u_char
name|clk_cr2
decl_stmt|;
define|#
directive|define
name|clk_sr
value|clk_cr2
name|u_char
name|clk_dummy3
decl_stmt|;
name|u_char
name|clk_msb1
decl_stmt|;
name|u_char
name|clk_dummy4
decl_stmt|;
name|u_char
name|clk_lsb1
decl_stmt|;
name|u_char
name|clk_dummy5
decl_stmt|;
name|u_char
name|clk_msb2
decl_stmt|;
name|u_char
name|clk_dummy6
decl_stmt|;
name|u_char
name|clk_lsb2
decl_stmt|;
name|u_char
name|clk_dummy7
decl_stmt|;
name|u_char
name|clk_msb3
decl_stmt|;
name|u_char
name|clk_dummy8
decl_stmt|;
name|u_char
name|clk_lsb3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* base/offsets for register access (for locore.s) */
end_comment

begin_define
define|#
directive|define
name|CLKBASE
value|IIOPOFF(0x5F8000)
end_define

begin_define
define|#
directive|define
name|CLKCR1
value|0x1
end_define

begin_define
define|#
directive|define
name|CLKCR2
value|0x3
end_define

begin_define
define|#
directive|define
name|CLKCR3
value|CLKCR1
end_define

begin_define
define|#
directive|define
name|CLKSR
value|CLKCR2
end_define

begin_define
define|#
directive|define
name|CLKMSB1
value|0x5
end_define

begin_define
define|#
directive|define
name|CLKMSB2
value|0x9
end_define

begin_define
define|#
directive|define
name|CLKMSB3
value|0xD
end_define

begin_comment
comment|/* output of counter 3 clocks counter 2 */
end_comment

begin_define
define|#
directive|define
name|CLK_OENAB
value|0x80
end_define

begin_comment
comment|/* output enable */
end_comment

begin_define
define|#
directive|define
name|CLK_IENAB
value|0x40
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|CLK_8BIT
value|0x04
end_define

begin_comment
comment|/* 8 bit mode */
end_comment

begin_define
define|#
directive|define
name|CLK_RESET
value|0x01
end_define

begin_comment
comment|/* chip reset (CR1 only) */
end_comment

begin_define
define|#
directive|define
name|CLK_CR1
value|0x01
end_define

begin_comment
comment|/* select CR1 (CR2 only) */
end_comment

begin_define
define|#
directive|define
name|CLK_CR3
value|0x00
end_define

begin_comment
comment|/* select CR3 (CR2 only) */
end_comment

begin_define
define|#
directive|define
name|CLK_INT1
value|0x01
end_define

begin_comment
comment|/* interrupt flag for timer 1 (SR only) */
end_comment

begin_define
define|#
directive|define
name|CLK_INT2
value|0x02
end_define

begin_comment
comment|/* interrupt flag for timer 2 (SR only) */
end_comment

begin_define
define|#
directive|define
name|CLK_INT3
value|0x04
end_define

begin_comment
comment|/* interrupt flag for timer 3 (SR only) */
end_comment

begin_define
define|#
directive|define
name|CLK_INTR
value|0x80
end_define

begin_comment
comment|/* composite interrupt flag (SR only) */
end_comment

begin_define
define|#
directive|define
name|CLK_RESOLUTION
value|4
end_define

begin_comment
comment|/* 4 usec resolution (250Khz) */
end_comment

begin_define
define|#
directive|define
name|CLK_INTERVAL
value|2500
end_define

begin_comment
comment|/* 10msec interval at 250KHz */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOTDEF
end_ifdef

begin_define
define|#
directive|define
name|CLK_INTERVAL
value|5000
end_define

begin_comment
comment|/* 20msec interval at 250Khz */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * HP300 battery-backed clock  */
end_comment

begin_struct
struct|struct
name|bbc_tm
block|{
name|int
name|tm_sec
decl_stmt|;
name|int
name|tm_min
decl_stmt|;
name|int
name|tm_hour
decl_stmt|;
name|int
name|tm_mday
decl_stmt|;
name|int
name|tm_mon
decl_stmt|;
name|int
name|tm_year
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FEBRUARY
value|2
end_define

begin_define
define|#
directive|define
name|STARTOFTIME
value|1970
end_define

begin_define
define|#
directive|define
name|SECDAY
value|86400L
end_define

begin_define
define|#
directive|define
name|SECYR
value|(SECDAY * 365)
end_define

begin_define
define|#
directive|define
name|BBC_SET_REG
value|0xe0
end_define

begin_define
define|#
directive|define
name|BBC_WRITE_REG
value|0xc2
end_define

begin_define
define|#
directive|define
name|BBC_READ_REG
value|0xc3
end_define

begin_define
define|#
directive|define
name|NUM_BBC_REGS
value|12
end_define

begin_define
define|#
directive|define
name|leapyear
parameter_list|(
name|year
parameter_list|)
value|((year) % 4 == 0)
end_define

begin_define
define|#
directive|define
name|range_test
parameter_list|(
name|n
parameter_list|,
name|l
parameter_list|,
name|h
parameter_list|)
value|if ((n)< (l) || (n)> (h)) return(0)
end_define

begin_define
define|#
directive|define
name|days_in_year
parameter_list|(
name|a
parameter_list|)
value|(leapyear(a) ? 366 : 365)
end_define

begin_define
define|#
directive|define
name|days_in_month
parameter_list|(
name|a
parameter_list|)
value|(month_days[(a) - 1])
end_define

begin_define
define|#
directive|define
name|bbc_to_decimal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(bbc_registers[a] * 10 + bbc_registers[b])
end_define

begin_define
define|#
directive|define
name|decimal_to_bbc
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|{ \ 	bbc_registers[a] = (n) % 10; \ 	bbc_registers[b] = (n) / 10; \ }
end_define

end_unit

