begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1998, 2000 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * 'Register' definitions for the MCBUS main  * system bus found on AlphaServer 4100 systems.  */
end_comment

begin_comment
comment|/*  * Information gathered from:"  *  * "Rawhide System Programmer's Manual, revision 1.4".  */
end_comment

begin_comment
comment|/*  * There are 7 possible MC bus modules (architecture says 10, but  * the address map details say otherwise), 1 though 7.  * Their uses are defined as follows:  *  *	MID	Module  *	----    ------  *	1	Memory  *	2	CPU  *	3	CPU  *	4	CPU, PCI  *	5	CPU, PCI  *	6	CPU, PCI  *	7	CPU, PCI  *  */
end_comment

begin_define
define|#
directive|define
name|MCBUS_MID_MAX
value|7
end_define

begin_comment
comment|/*  * For this architecture, bit 39 of a 40 bit address controls whether  * you access I/O or Memory space. Further, there *could* be multiple  * MC busses (but only one specified for now).  */
end_comment

begin_define
define|#
directive|define
name|MCBUS_IOSPACE
value|0x0000008000000000L
end_define

begin_define
define|#
directive|define
name|MCBUS_GID_MASK
value|0x0000007000000000L
end_define

begin_define
define|#
directive|define
name|MCBUS_GID_SHIFT
value|36
end_define

begin_define
define|#
directive|define
name|MCBUS_MID_MASK
value|0x0000000E00000000L
end_define

begin_define
define|#
directive|define
name|MCBUS_MID_SHIFT
value|33
end_define

begin_define
define|#
directive|define
name|MAX_MC_BUS
value|8
end_define

begin_comment
comment|/*  * This is something of a layering violation, but it makes probing cleaner.  */
end_comment

begin_define
define|#
directive|define
name|MCPCIA_PER_MCBUS
value|4
end_define

begin_comment
comment|/* the MCPCIA bridge CSR addresses, offset zero, is a good thing to probe for */
end_comment

begin_define
define|#
directive|define
name|MCPCIA_BRIDGE_ADDR
parameter_list|(
name|gid
parameter_list|,
name|mid
parameter_list|)
define|\
value|(MCBUS_IOSPACE | 0x1E0000000LL	|		\ 	(((unsigned long) gid)<< MCBUS_GID_SHIFT) |	\ 	(((unsigned long) mid)<< MCBUS_MID_SHIFT))
end_define

end_unit

