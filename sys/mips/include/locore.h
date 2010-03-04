begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: locore.h,v 1.78 2007/10/17 19:55:36 garbled Exp $ */
end_comment

begin_comment
comment|/*  * Copyright 1996 The Board of Trustees of The Leland Stanford  * Junior University. All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appear in all copies.  Stanford University  * makes no representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Jump table for MIPS cpu locore functions that are implemented  * differently on different generations, or instruction-level  * archtecture (ISA) level, the Mips family.  *  * We currently provide support for MIPS I and MIPS III.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_LOCORE_H
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_LOCORE_H
end_define

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuregs.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_struct_decl
struct_decl|struct
name|tlb
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * CPU identification, from PRID register.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|mips_prid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MIPS_PRID_REV
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  0)& 0x00ff)
end_define

begin_define
define|#
directive|define
name|MIPS_PRID_IMPL
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  8)& 0x00ff)
end_define

begin_comment
comment|/* pre-MIPS32/64 */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_RSVD
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|MIPS_PRID_REV_MIN
parameter_list|(
name|x
parameter_list|)
value|((MIPS_PRID_REV(x)>> 0)& 0x0f)
end_define

begin_define
define|#
directive|define
name|MIPS_PRID_REV_MAJ
parameter_list|(
name|x
parameter_list|)
value|((MIPS_PRID_REV(x)>> 4)& 0x0f)
end_define

begin_comment
comment|/* MIPS32/64 */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x00ff)
end_define

begin_comment
comment|/* Company ID */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID_PREHISTORIC
value|0x00
end_define

begin_comment
comment|/* Not MIPS32/64 */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID_MTI
value|0x01
end_define

begin_comment
comment|/* MIPS Technologies, Inc. */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID_BROADCOM
value|0x02
end_define

begin_comment
comment|/* Broadcom */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID_ALCHEMY
value|0x03
end_define

begin_comment
comment|/* Alchemy Semiconductor */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID_SIBYTE
value|0x04
end_define

begin_comment
comment|/* SiByte */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID_SANDCRAFT
value|0x05
end_define

begin_comment
comment|/* SandCraft */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID_PHILIPS
value|0x06
end_define

begin_comment
comment|/* Philips */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID_TOSHIBA
value|0x07
end_define

begin_comment
comment|/* Toshiba */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID_LSI
value|0x08
end_define

begin_comment
comment|/* LSI */
end_comment

begin_comment
comment|/*	0x09	unannounced */
end_comment

begin_comment
comment|/*	0x0a	unannounced */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID_LEXRA
value|0x0b
end_define

begin_comment
comment|/* Lexra */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_CID_CAVIUM
value|0x0d
end_define

begin_comment
comment|/* Cavium */
end_comment

begin_define
define|#
directive|define
name|MIPS_PRID_COPTS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x00ff)
end_define

begin_comment
comment|/* Company Options */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__HAVE_MIPS_MACHDEP_CACHE_CONFIG
end_ifdef

begin_function_decl
name|void
name|mips_machdep_cache_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_LOCORE_H */
end_comment

end_unit

