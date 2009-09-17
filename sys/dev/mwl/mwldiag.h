begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2007-2009 Marvell Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MWL_DIAG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MWL_DIAG_H_
end_define

begin_comment
comment|/*  * Diagnostic interface.  This is an open-ended interface that  * is opaque to applications.  Diagnostic programs use this to  * retrieve internal data structures, etc.  There is no guarantee  * that calling conventions for calls other than MWL_DIAG_REVS  * are stable between HAL releases; a diagnostic application must  * use the HAL revision information to deal with ABI/API differences.  *  * NB: do not renumber these, certain codes are publicly used.  */
end_comment

begin_enum
enum|enum
block|{
name|MWL_DIAG_CMD_REVS
init|=
literal|0
block|,
comment|/* MAC/PHY/Radio revs */
name|MWL_DIAG_CMD_REGS
init|=
literal|1
block|,
comment|/* Registers */
name|MWL_DIAG_CMD_HOSTCMD
init|=
literal|2
block|,
comment|/* issue arbitrary cmd */
name|MWL_DIAG_CMD_FWLOAD
init|=
literal|3
block|,
comment|/* load firmware */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Device revision information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|mh_devid
decl_stmt|;
comment|/* PCI device ID */
name|uint16_t
name|mh_subvendorid
decl_stmt|;
comment|/* PCI subvendor ID */
name|uint16_t
name|mh_macRev
decl_stmt|;
comment|/* MAC revision */
name|uint16_t
name|mh_phyRev
decl_stmt|;
comment|/* PHY revision */
block|}
name|MWL_DIAG_REVS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|start
decl_stmt|;
comment|/* first register */
name|uint16_t
name|end
decl_stmt|;
comment|/* ending register or zero */
block|}
name|MWL_DIAG_REGRANGE
typedef|;
end_typedef

begin_comment
comment|/*  * Registers are mapped into virtual banks; the hal converts  * r/w operations through the diag api to host cmds as required.  *  * NB: register offsets are 16-bits and we need to avoid real  *     register mappings in BAR1.  */
end_comment

begin_define
define|#
directive|define
name|MWL_DIAG_BASE_MAC
value|0xa000
end_define

begin_define
define|#
directive|define
name|MWL_DIAG_ISMAC
parameter_list|(
name|r
parameter_list|)
define|\
value|(MWL_DIAG_BASE_MAC<= (r)&& (r)< (MWL_DIAG_BASE_MAC+0x1000))
end_define

begin_define
define|#
directive|define
name|MWL_DIAG_BASE_BB
value|0xe000
end_define

begin_define
define|#
directive|define
name|MWL_DIAG_ISBB
parameter_list|(
name|r
parameter_list|)
define|\
value|(MWL_DIAG_BASE_BB<= (r)&& (r)< (MWL_DIAG_BASE_BB+0x1000))
end_define

begin_define
define|#
directive|define
name|MWL_DIAG_BASE_RF
value|0xf000
end_define

begin_define
define|#
directive|define
name|MWL_DIAG_ISRF
parameter_list|(
name|r
parameter_list|)
define|\
value|(MWL_DIAG_BASE_RF<= (r)&& (r)< (MWL_DIAG_BASE_RF+0x1000))
end_define

begin_comment
comment|/*  * Firmware download  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|opmode
decl_stmt|;
comment|/* operating mode */
name|uint32_t
name|signature
decl_stmt|;
comment|/* f/w ready signature */
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable length pathname */
block|}
name|MWL_DIAG_FWLOAD
typedef|;
end_typedef

begin_struct
struct|struct
name|mwl_diag
block|{
name|char
name|md_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "mv0" */
name|uint16_t
name|md_id
decl_stmt|;
define|#
directive|define
name|MWL_DIAG_DYN
value|0x8000
comment|/* allocate buffer in caller */
define|#
directive|define
name|MWL_DIAG_IN
value|0x4000
comment|/* copy in parameters */
define|#
directive|define
name|MWL_DIAG_OUT
value|0x0000
comment|/* copy out results (always) */
define|#
directive|define
name|MWL_DIAG_ID
value|0x0fff
name|uint16_t
name|md_in_size
decl_stmt|;
comment|/* pack to fit, yech */
name|void
modifier|*
name|md_in_data
decl_stmt|;
name|void
modifier|*
name|md_out_data
decl_stmt|;
name|u_int
name|md_out_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCGMVDIAG
value|_IOWR('i', 138, struct mwl_diag)
end_define

begin_define
define|#
directive|define
name|SIOCGMVRESET
value|_IOW('i', 139, struct mwl_diag)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MWL_DIAG_H_ */
end_comment

end_unit

