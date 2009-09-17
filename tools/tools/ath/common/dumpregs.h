begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_DUMPREGS_
end_ifndef

begin_define
define|#
directive|define
name|_DUMPREGS_
end_define

begin_comment
comment|/*-  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|__constructor
value|__attribute__((constructor))
end_define

begin_struct
struct|struct
name|dumpreg
block|{
name|uint32_t
name|addr
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|bits
decl_stmt|;
name|int
name|type
decl_stmt|;
name|u_int
name|srevMin
decl_stmt|,
name|srevMax
decl_stmt|;
name|u_int
name|phyMin
decl_stmt|,
name|phyMax
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SREV
parameter_list|(
name|v
parameter_list|,
name|r
parameter_list|)
value|(((v)<< 16) | (r))
end_define

begin_define
define|#
directive|define
name|MAC_MATCH
parameter_list|(
name|dr
parameter_list|,
name|mv
parameter_list|,
name|mr
parameter_list|)
define|\
value|((dr)->srevMin<= SREV(mv,mr)&& SREV(mv,mr)< (dr)->srevMax)
end_define

begin_define
define|#
directive|define
name|PHY_MATCH
parameter_list|(
name|dr
parameter_list|,
name|pr
parameter_list|)
define|\
value|((dr)->phyMin<= (pr)&& (pr)< (dr)->phyMax)
end_define

begin_define
define|#
directive|define
name|PHYANY
value|0,0xffff
end_define

begin_enum
enum|enum
block|{
name|DUMP_BASIC
init|=
literal|0x0001
block|,
comment|/* basic/default registers */
name|DUMP_KEYCACHE
init|=
literal|0x0002
block|,
comment|/* key cache */
name|DUMP_BASEBAND
init|=
literal|0x0004
block|,
comment|/* baseband */
name|DUMP_INTERRUPT
init|=
literal|0x0008
block|,
comment|/* interrupt state */
name|DUMP_XR
init|=
literal|0x0010
block|,
comment|/* XR state */
name|DUMP_QCU
init|=
literal|0x0020
block|,
comment|/* QCU state */
name|DUMP_DCU
init|=
literal|0x0040
block|,
comment|/* DCU state */
name|DUMP_PUBLIC
init|=
literal|0x0061
block|,
comment|/* public = BASIC+QCU+DCU */
name|DUMP_ALL
init|=
literal|0xffff
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|_DEFREG
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|,
name|_type
parameter_list|)
define|\
value|{ .addr = _addr, .name = _name, .type = _type }
end_define

begin_define
define|#
directive|define
name|_DEFREGx
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|,
name|_type
parameter_list|,
name|_srevmin
parameter_list|,
name|_srevmax
parameter_list|)
define|\
value|{ .addr = _addr, .name = _name, .type = _type, \      .srevMin = _srevmin, .srevMax = _srevmax }
end_define

begin_define
define|#
directive|define
name|_DEFREGfmt
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|,
name|_type
parameter_list|,
name|_fmt
parameter_list|)
define|\
value|{ .addr = _addr, .name = _name, .type = _type, .bits = _fmt }
end_define

begin_define
define|#
directive|define
name|DEFVOID
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|)
value|_DEFREG(_addr, _name, 0)
end_define

begin_define
define|#
directive|define
name|DEFVOIDx
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|,
name|_smin
parameter_list|,
name|_smax
parameter_list|)
define|\
value|__DEFREGx(_addr, _name, _smin, _smax, 0)
end_define

begin_define
define|#
directive|define
name|DEFVOIDfmt
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|,
name|_fmt
parameter_list|)
define|\
value|_DEFREGfmt(_addr, _name, 0, _fmt)
end_define

begin_define
define|#
directive|define
name|DEFBASIC
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|)
value|_DEFREG(_addr, _name, DUMP_BASIC)
end_define

begin_define
define|#
directive|define
name|DEFBASICfmt
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|,
name|_fmt
parameter_list|)
define|\
value|_DEFREGfmt(_addr, _name, DUMP_BASIC, _fmt)
end_define

begin_define
define|#
directive|define
name|DEFBASICx
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|,
name|_smin
parameter_list|,
name|_smax
parameter_list|)
define|\
value|_DEFREGx(_addr, _name, DUMP_BASIC, _smin, _smax)
end_define

begin_define
define|#
directive|define
name|DEFBB
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|)
value|_DEFREG(_addr, _name, DUMP_BASEBAND)
end_define

begin_define
define|#
directive|define
name|DEFINT
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|)
value|_DEFREG(_addr, _name, DUMP_INTERRUPT)
end_define

begin_define
define|#
directive|define
name|DEFINTfmt
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|,
name|_fmt
parameter_list|)
define|\
value|_DEFREGfmt(_addr, _name, DUMP_INTERRUPT, _fmt)
end_define

begin_define
define|#
directive|define
name|DEFQCU
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|)
value|_DEFREG(_addr, _name, DUMP_QCU)
end_define

begin_define
define|#
directive|define
name|DEFDCU
parameter_list|(
name|_addr
parameter_list|,
name|_name
parameter_list|)
value|_DEFREG(_addr, _name, DUMP_DCU)
end_define

begin_function_decl
name|void
name|register_regs
parameter_list|(
name|struct
name|dumpreg
modifier|*
name|_regs
parameter_list|,
name|u_int
name|_nregs
parameter_list|,
name|int
name|def_srev_min
parameter_list|,
name|int
name|def_srev_max
parameter_list|,
name|int
name|def_phy_min
parameter_list|,
name|int
name|def_phy_max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|register_keycache
parameter_list|(
name|u_int
name|nslots
parameter_list|,
name|int
name|def_srev_min
parameter_list|,
name|int
name|def_srev_max
parameter_list|,
name|int
name|def_phy_min
parameter_list|,
name|int
name|def_phy_max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|register_range
parameter_list|(
name|u_int
name|brange
parameter_list|,
name|u_int
name|erange
parameter_list|,
name|int
name|what
parameter_list|,
name|int
name|def_srev_min
parameter_list|,
name|int
name|def_srev_max
parameter_list|,
name|int
name|def_phy_min
parameter_list|,
name|int
name|def_phy_max
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DUMPREGS_ */
end_comment

end_unit

