begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/tcpdump/fddi.h,v 1.9 2000/10/09 02:59:39 guy Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Based on Ultrix if_fddi.h  */
end_comment

begin_comment
comment|/*  * This stuff should come from a system header file, but there's no  * obviously portable way to do that and it's not really going  * to change from system to system (except for the padding business).  */
end_comment

begin_struct
struct|struct
name|fddi_header
block|{
name|u_char
name|fddi_fc
decl_stmt|;
comment|/* frame control */
name|u_char
name|fddi_dhost
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|fddi_shost
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Length of an FDDI header; note that some compilers may pad  * "struct fddi_header" to a multiple of 4 bytes, for example, so  * "sizeof (struct fddi_header)" may not give the right  * answer.  */
end_comment

begin_define
define|#
directive|define
name|FDDI_HDRLEN
value|13
end_define

begin_comment
comment|/* Useful values for fddi_fc (frame control) field */
end_comment

begin_comment
comment|/*  * FDDI Frame Control bits  */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_C
value|0x80
end_define

begin_comment
comment|/* Class bit */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_L
value|0x40
end_define

begin_comment
comment|/* Address length bit */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_F
value|0x30
end_define

begin_comment
comment|/* Frame format bits */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_Z
value|0x0f
end_define

begin_comment
comment|/* Control bits */
end_comment

begin_comment
comment|/*  * FDDI Frame Control values. (48-bit addressing only).  */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_VOID
value|0x40
end_define

begin_comment
comment|/* Void frame */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_NRT
value|0x80
end_define

begin_comment
comment|/* Nonrestricted token */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_RT
value|0xc0
end_define

begin_comment
comment|/* Restricted token */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_SMT_INFO
value|0x41
end_define

begin_comment
comment|/* SMT Info */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_SMT_NSA
value|0x4F
end_define

begin_comment
comment|/* SMT Next station adrs */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_MAC_BEACON
value|0xc2
end_define

begin_comment
comment|/* MAC Beacon frame */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_MAC_CLAIM
value|0xc3
end_define

begin_comment
comment|/* MAC Claim frame */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_LLC_ASYNC
value|0x50
end_define

begin_comment
comment|/* Async. LLC frame */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_LLC_SYNC
value|0xd0
end_define

begin_comment
comment|/* Sync. LLC frame */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_IMP_ASYNC
value|0x60
end_define

begin_comment
comment|/* Implementor Async. */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_IMP_SYNC
value|0xe0
end_define

begin_comment
comment|/* Implementor Synch. */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_SMT
value|0x40
end_define

begin_comment
comment|/* SMT frame */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_MAC
value|0xc0
end_define

begin_comment
comment|/* MAC frame */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_CLFF
value|0xF0
end_define

begin_comment
comment|/* Class/Length/Format bits */
end_comment

begin_define
define|#
directive|define
name|FDDIFC_ZZZZ
value|0x0F
end_define

begin_comment
comment|/* Control bits */
end_comment

end_unit

