begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if_il.h	7.3 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * Structure of an Ethernet header -- receive format  */
end_comment

begin_struct
struct|struct
name|il_rheader
block|{
name|u_char
name|ilr_status
decl_stmt|;
comment|/* Frame Status */
name|u_char
name|ilr_fill1
decl_stmt|;
name|u_short
name|ilr_length
decl_stmt|;
comment|/* Frame Length */
name|u_char
name|ilr_dhost
index|[
literal|6
index|]
decl_stmt|;
comment|/* Destination Host */
name|u_char
name|ilr_shost
index|[
literal|6
index|]
decl_stmt|;
comment|/* Source Host */
name|u_short
name|ilr_type
decl_stmt|;
comment|/* Type of packet */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of statistics record  */
end_comment

begin_struct
struct|struct
name|il_stats
block|{
name|u_short
name|ils_fill1
decl_stmt|;
name|u_short
name|ils_length
decl_stmt|;
comment|/* Length (should be 62) */
name|u_char
name|ils_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* Ethernet Address */
name|u_short
name|ils_frames
decl_stmt|;
comment|/* Number of Frames Received */
name|u_short
name|ils_rfifo
decl_stmt|;
comment|/* Number of Frames in Receive FIFO */
name|u_short
name|ils_xmit
decl_stmt|;
comment|/* Number of Frames Transmitted */
name|u_short
name|ils_xcollis
decl_stmt|;
comment|/* Number of Excess Collisions */
name|u_short
name|ils_frag
decl_stmt|;
comment|/* Number of Fragments Received */
name|u_short
name|ils_lost
decl_stmt|;
comment|/* Number of Times Frames Lost */
name|u_short
name|ils_multi
decl_stmt|;
comment|/* Number of Multicasts Accepted */
name|u_short
name|ils_rmulti
decl_stmt|;
comment|/* Number of Multicasts Rejected */
name|u_short
name|ils_crc
decl_stmt|;
comment|/* Number of CRC Errors */
name|u_short
name|ils_align
decl_stmt|;
comment|/* Number of Alignment Errors */
name|u_short
name|ils_collis
decl_stmt|;
comment|/* Number of Collisions */
name|u_short
name|ils_owcollis
decl_stmt|;
comment|/* Number of Out-of-window Collisions */
name|u_short
name|ils_fill2
index|[
literal|8
index|]
decl_stmt|;
name|char
name|ils_module
index|[
literal|8
index|]
decl_stmt|;
comment|/* Module ID */
name|char
name|ils_firmware
index|[
literal|8
index|]
decl_stmt|;
comment|/* Firmware ID */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of Collision Delay Time Record  */
end_comment

begin_struct
struct|struct
name|il_collis
block|{
name|u_short
name|ilc_fill1
decl_stmt|;
name|u_short
name|ilc_length
decl_stmt|;
comment|/* Length (should be 0-32) */
name|u_short
name|ilc_delay
index|[
literal|16
index|]
decl_stmt|;
comment|/* Delay Times */
block|}
struct|;
end_struct

end_unit

