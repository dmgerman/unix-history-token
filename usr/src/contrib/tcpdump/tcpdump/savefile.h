begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Header: savefile.h,v 1.10 90/12/17 13:48:58 mccanne Exp $  *  * Header for offline storage info.  * Extraction/creation by Jeffrey Mogul, DECWRL.  *  * Used to save the received packet headers, after filtering, to  * a file, and then read them later.  */
end_comment

begin_comment
comment|/*  * Each packet in the dump file is prepended with this generic header.  * This gets around the problem of different headers for different  * packet interfaces.  */
end_comment

begin_struct
struct|struct
name|packet_header
block|{
name|struct
name|timeval
name|ts
decl_stmt|;
comment|/* time stamp */
name|u_long
name|len
decl_stmt|;
comment|/* length this packet (off wire) */
name|u_long
name|caplen
decl_stmt|;
comment|/* length of portion present */
block|}
struct|;
end_struct

begin_comment
comment|/* true if the contents of the savefile being read are byte-swapped */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sf_swapped
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* macros for when sf_swapped is true: */
end_comment

begin_comment
comment|/*  * We use the "receiver-makes-right" approach to byte order,  * because time is at a premium when we are writing the file.  * In other words, the file_header and packet_header records  * are written in host byte order.  * Note that the packets are always written in network byte order.  *  * ntoh[ls] aren't sufficient because we might need to swap on a big-endian  * machine (if the file was written in little-end order).  */
end_comment

begin_define
define|#
directive|define
name|SWAPLONG
parameter_list|(
name|y
parameter_list|)
define|\
value|((((y)&0xff)<<24) | (((y)&0xff00)<<8) | (((y)&0xff0000)>>8) | (((y)>>24)&0xff))
end_define

begin_define
define|#
directive|define
name|SWAPSHORT
parameter_list|(
name|y
parameter_list|)
define|\
value|( (((y)&0xff)<<8) | (((y)&0xff00)>>8) )
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|sf_readfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dump file being read from */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|sf_writefile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dump file being written to */
end_comment

begin_function_decl
name|int
name|sf_read_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sf_read
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sf_next_packet
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sf_write_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sf_write
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sf_err
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SFERR_TRUNC
value|1
end_define

begin_define
define|#
directive|define
name|SFERR_BADVERSION
value|2
end_define

begin_define
define|#
directive|define
name|SFERR_BADF
value|3
end_define

begin_define
define|#
directive|define
name|SFERR_EOF
value|4
end_define

begin_comment
comment|/* not really an error, just a status */
end_comment

end_unit

