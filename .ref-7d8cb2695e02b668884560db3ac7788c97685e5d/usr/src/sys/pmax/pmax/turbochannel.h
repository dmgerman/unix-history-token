begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University  * and Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)turbochannel.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * 	Created, from the DEC specs:  * 	"TURBOchannel Hardware Specification"  * 	EK-369AA-OD-005, Version 005, July 1990  *  *	File: tc.h  * 	Author: Alessandro Forin, Carnegie Mellon University  *	Date:	9/90  *  *	Definitions for the TURBOchannel BUS.  */
end_comment

begin_comment
comment|/*  * Max conceivable number of slots on the TC  */
end_comment

begin_define
define|#
directive|define
name|TC_MAX_SLOTS
value|8
end_define

begin_define
define|#
directive|define
name|TC_MAX_LOGICAL_SLOTS
value|12
end_define

begin_comment
comment|/*  * Address map specifications for any TC option  * These are offset from the option's base address  */
end_comment

begin_define
define|#
directive|define
name|TC_OFF_ROM
value|0x000003e0
end_define

begin_comment
comment|/* required ROM info */
end_comment

begin_define
define|#
directive|define
name|TC_OFF_PROTO_ROM
value|0x003c03e0
end_define

begin_comment
comment|/* 'obsolete' alternate */
end_comment

begin_define
define|#
directive|define
name|TC_ROM_TEST_DATA_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|TC_ROM_SLEN
value|4
end_define

begin_define
define|#
directive|define
name|TC_ROM_LLEN
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|value
decl_stmt|;
name|char
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|tc_padded_char_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|tc_padded_char_t
name|rom_width
decl_stmt|;
comment|/* legal: 1 2 4 */
name|tc_padded_char_t
name|rom_stride
decl_stmt|;
comment|/* legal: 4 */
name|tc_padded_char_t
name|rom_size
decl_stmt|;
comment|/* legal: 0-255, unit: 8kb */
name|tc_padded_char_t
name|slot_size
decl_stmt|;
comment|/* legal: 1-128, unit: 4Mb */
name|unsigned
name|char
name|test_data
index|[
name|TC_ROM_TEST_DATA_SIZE
index|]
decl_stmt|;
comment|/* must always contain: 						/* x55 x00 xaa xff 						/* (each byte is repeated 						/*  rom_stride times) */
name|tc_padded_char_t
name|firmware_rev
index|[
name|TC_ROM_LLEN
index|]
decl_stmt|;
name|tc_padded_char_t
name|vendor_name
index|[
name|TC_ROM_LLEN
index|]
decl_stmt|;
name|tc_padded_char_t
name|module_name
index|[
name|TC_ROM_LLEN
index|]
decl_stmt|;
name|tc_padded_char_t
name|host_firmware_type
index|[
name|TC_ROM_SLEN
index|]
decl_stmt|;
block|}
name|tc_rommap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|present
decl_stmt|;
comment|/* and do we handle it */
name|u_char
name|slot_size
decl_stmt|;
comment|/* how many TC slots */
name|u_char
name|rom_width
decl_stmt|;
comment|/* bytewide or.. */
name|u_char
name|unit
decl_stmt|;
comment|/* Device unit number */
name|char
name|module_name
index|[
name|TC_ROM_LLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* ROM name */
name|char
name|module_id
index|[
name|TC_ROM_LLEN
operator|*
literal|2
operator|+
literal|1
index|]
decl_stmt|;
comment|/* vendor and rev */
name|u_long
name|k1seg_address
decl_stmt|;
comment|/* TC starting address */
name|char
modifier|*
name|driver_name
decl_stmt|;
comment|/* software name */
name|void
function_decl|(
modifier|*
name|intr
function_decl|)
parameter_list|()
function_decl|;
comment|/* interrupt routine */
block|}
name|tc_option_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|tc_option_t
name|tc_slot_info
index|[]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern	void (*tc_slot_hand_fill
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|tc_option_t
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

