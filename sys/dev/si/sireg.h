begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Device driver for Specialix range (SI/XIO) of serial line multiplexors.  * 'C' definitions for Specialix serial multiplex driver.  *  * Copyright (C) 1990, 1992, 1998 Specialix International,  * Copyright (C) 1993, Andy Rutter<andy@acronym.co.uk>  * Copyright (C) 1995, Peter Wemm<peter@netplex.com.au>  *  * Derived from:	SunOS 4.x version  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notices, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notices, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Andy Rutter of  *	Advanced Methods and Tools Ltd. based on original information  *	from Specialix International.  * 4. Neither the name of Advanced Methods and Tools, nor Specialix  *    International may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN  * NO EVENT SHALL THE AUTHORS BE LIABLE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Hardware parameters which should be changed at your peril!  */
end_comment

begin_comment
comment|/* Base and mask for SI Host 2.x (SIHOST2) */
end_comment

begin_define
define|#
directive|define
name|SIPLSIG
value|0x7FF8
end_define

begin_comment
comment|/* Start of control space */
end_comment

begin_define
define|#
directive|define
name|SIPLCNTL
value|0x7FF8
end_define

begin_comment
comment|/* Ditto */
end_comment

begin_define
define|#
directive|define
name|SIPLRESET
value|SIPLCNTL
end_define

begin_comment
comment|/* 0 = reset */
end_comment

begin_define
define|#
directive|define
name|SIPLIRQ11
value|(SIPLCNTL+1)
end_define

begin_comment
comment|/* 0 = mask irq 11 */
end_comment

begin_define
define|#
directive|define
name|SIPLIRQ12
value|(SIPLCNTL+2)
end_define

begin_comment
comment|/* 0 = mask irq 12 */
end_comment

begin_define
define|#
directive|define
name|SIPLIRQ15
value|(SIPLCNTL+3)
end_define

begin_comment
comment|/* 0 = mask irq 15 */
end_comment

begin_define
define|#
directive|define
name|SIPLIRQSET
value|(SIPLCNTL+4)
end_define

begin_comment
comment|/* 0 = interrupt host */
end_comment

begin_define
define|#
directive|define
name|SIPLIRQCLR
value|(SIPLCNTL+5)
end_define

begin_comment
comment|/* 0 = clear irq */
end_comment

begin_comment
comment|/* SI Host 1.x */
end_comment

begin_define
define|#
directive|define
name|SIRAM
value|0x0000
end_define

begin_comment
comment|/* Ram Starts here */
end_comment

begin_define
define|#
directive|define
name|SIRESET
value|0x8000
end_define

begin_comment
comment|/* Set reset */
end_comment

begin_define
define|#
directive|define
name|SIRESET_CL
value|0xc000
end_define

begin_comment
comment|/* Clear reset */
end_comment

begin_define
define|#
directive|define
name|SIWAIT
value|0x9000
end_define

begin_comment
comment|/* Set wait */
end_comment

begin_define
define|#
directive|define
name|SIWAIT_CL
value|0xd000
end_define

begin_comment
comment|/* Set wait */
end_comment

begin_define
define|#
directive|define
name|SIINTCL
value|0xA000
end_define

begin_comment
comment|/* Clear host int */
end_comment

begin_define
define|#
directive|define
name|SIINTCL_CL
value|0xE000
end_define

begin_comment
comment|/* Clear host int */
end_comment

begin_comment
comment|/* SI EISA */
end_comment

begin_define
define|#
directive|define
name|SIEISADEVID
value|0x4d980411
end_define

begin_comment
comment|/* EISA Device ID */
end_comment

begin_define
define|#
directive|define
name|SIEISABASE
value|0xc00
end_define

begin_comment
comment|/* Our ports start here */
end_comment

begin_define
define|#
directive|define
name|SIEISAIOSIZE
value|0x100
end_define

begin_comment
comment|/* XXX How many ports */
end_comment

begin_comment
comment|/* SI old PCI */
end_comment

begin_define
define|#
directive|define
name|SIPCIBADR
value|0x10
end_define

begin_comment
comment|/* Which BADR to map in RAM */
end_comment

begin_define
define|#
directive|define
name|SIPCI_MEMSIZE
value|0x100000
end_define

begin_comment
comment|/* Mapping size */
end_comment

begin_define
define|#
directive|define
name|SIPCIRESET
value|0xc0001
end_define

begin_comment
comment|/* 0 = Reset */
end_comment

begin_define
define|#
directive|define
name|SIPCIINTCL
value|0x40001
end_define

begin_comment
comment|/* 0 = clear int */
end_comment

begin_comment
comment|/* SI Jet PCI */
end_comment

begin_define
define|#
directive|define
name|SIJETSSIDREG
value|0x2c
end_define

begin_comment
comment|/* Is it an SX or RIO? */
end_comment

begin_define
define|#
directive|define
name|SIJETBADR
value|0x18
end_define

begin_comment
comment|/* Which BADR to map in RAM */
end_comment

begin_comment
comment|/* SI Jet PCI& ISA */
end_comment

begin_define
define|#
directive|define
name|SIJETIDBASE
value|0x7c00
end_define

begin_comment
comment|/* ID ROM base */
end_comment

begin_define
define|#
directive|define
name|SISPLXID
value|0x984d
end_define

begin_comment
comment|/* Specialix ID */
end_comment

begin_define
define|#
directive|define
name|SIUNIQID
value|0x7c0e
end_define

begin_comment
comment|/*& 0xf0 = 0x20 for SX */
end_comment

begin_define
define|#
directive|define
name|SIJETIDSTR
value|0x7c20
end_define

begin_comment
comment|/* ID ROM string */
end_comment

begin_define
define|#
directive|define
name|SIJETRESET
value|0x7d00
end_define

begin_define
define|#
directive|define
name|SIJETINTCL
value|0x7d80
end_define

begin_define
define|#
directive|define
name|SIJETCONFIG
value|0x7c00
end_define

begin_comment
comment|/* for ISA, top nibble = IRQ */
end_comment

begin_define
define|#
directive|define
name|SIJETBUSEN
value|0x2
end_define

begin_define
define|#
directive|define
name|SIJETIRQEN
value|0x4
end_define

begin_comment
comment|/*  * MEMSIZE is the total shared mem region  * RAMSIZE is value to use when probing  * PROBEALLOC is the amount to bus_resource_alloc() during probe.  */
end_comment

begin_define
define|#
directive|define
name|SIJETPCI_MEMSIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|SIJETISA_MEMSIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|SIJET_RAMSIZE
value|0x7000
end_define

begin_define
define|#
directive|define
name|SIHOST_MEMSIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|SIHOST_RAMSIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|SIHOST2_MEMSIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|SIHOST2_RAMSIZE
value|0x7ff7
end_define

begin_define
define|#
directive|define
name|SIEISA_MEMSIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|SIEISA_RAMSIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|SIPROBEALLOC
value|0x8000
end_define

end_unit

