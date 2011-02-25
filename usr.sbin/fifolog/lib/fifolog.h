begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2008 Poul-Henning Kamp  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LOCAL_FIFOLOG_H_
end_ifndef

begin_define
define|#
directive|define
name|__LOCAL_FIFOLOG_H_
end_define

begin_comment
comment|/*  * Definitions for fifolog "protocol": the on-media layout.  *  * The fifolog on-media record has three layers:  *   The outer timestamping and synchronization layer.  *   The zlib implemented data compression.  *   The inner sequencing and identification layer.  *  * All three layers are synchronized at a subset of the outer layer  * record boundaries, from where reading can be initiated.  *  *  * The outer layer:  * -----------------  * The first record in a fifolog contains a magic string and version  * information along with a 32be encoded recordsize for all records  * in the fifolog, including the first.  * The recordsize is explicit to avoid ambiguities when a media is  * moved from one machine to another.  *  * Each record in the fifolog has the following contents:  *	offset	type	contents  *      --------------------------------------------------------------  *	0	32be	sequence_number  *			The sequence number is randomly chosen for the  *			fifolog and increments once for each record written.  *			It's presence allow quick identification of the next  *			record to be written using a binary search for the  *			first place where a discontinuity in the sequence  *			numbers occur.  *	4	 8	flags (FIFOLOG_FLG_*)  *  * If (flags& (FIFOLOG_FLG_SYNC)) the record is a synchronization point  * at which the inner layers are aligned so that reading can be started  * at this point.  * To enable seeks into the file based on timestamps, a third field is  * present in these records as well:  *	5	32be	time_t containing POSIX's understanding of UTC.  *  * These fields are immediately followed by the inner layer payload as  * described below, which has variable length.  *  * If the inner layer payload is shorter than the available space in  * the record, it is padded with zero bytes, and the number of unused  * bytes, including the encoded length thereof is recorded at the end  * of the record as follows:  *  * If (flags& FIFOLOG_FLG_1BYTE)  *	n-1	8	number of unused bytes  * else if (flags& FIFOLOG_FLG_4BYTE)  *	n-4	32be	number of unused bytes  *  *  * The gzip layer  * --------------  * Is just output from zlib, nothing special here.  FIFOLOG_FLG_SYNC  * corresponds to Z_FINISH flags to zlib.  * In most cases, the timer will expire before zlib has filled an entire  * record in which case Z_SYNC_FLUSH will be used to force as much as  * possible into the buffer before it is written.  This is not marked  * in outer layer (apart from a natural correlation with padding) since  * zlibs data stream handles this without help.  *  *  * The inner layer:  * ----------------  * The inner layer contains data identification and to the second  * timestamping (the timestamp in the outer layer only marks the  * first possible timestamp for content in the SYNC record).  *  *	offset	type	contents  *      --------------------------------------------------------------  *	0	32be	ident  *  * The bottom 30 bits of the identification word are application defined,  * presently unused in the stand-alone fifolog tools, but used in the  * original "measured" application that originated the fifolog format.  * Should for instance syslogd(8) grow native support for fifolog format,  * it could store the message priority here.  *  * If (ident& FIFOLOG_TIMESTAMP) the record is prefixed by:  *	4	32be	time_t containing POSIX's understanding of UTC.  *  * Then follows the content, either as a NUL terminated string or as  * a length encoded binary sequence:  *  * If (ident& FIFOLOG_LENGTH) the record is prefixed by:  *	{0|4}	8	length of binary data  *  */
end_comment

begin_comment
comment|/* Magic identification string */
end_comment

begin_define
define|#
directive|define
name|FIFOLOG_FMT_MAGIC
value|"Measured FIFOLOG Ver 1.01\n"
end_define

begin_comment
comment|/* Offset of the 32be encoded recordsize in the first sector */
end_comment

begin_define
define|#
directive|define
name|FIFOLOG_OFF_BS
value|0x20
end_define

begin_define
define|#
directive|define
name|FIFOLOG_FLG_1BYTE
value|0x01
end_define

begin_define
define|#
directive|define
name|FIFOLOG_FLG_4BYTE
value|0x02
end_define

begin_define
define|#
directive|define
name|FIFOLOG_FLG_RESTART
value|0x40
end_define

begin_define
define|#
directive|define
name|FIFOLOG_FLG_SYNC
value|0x80
end_define

begin_define
define|#
directive|define
name|FIFOLOG_TIMESTAMP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FIFOLOG_LENGTH
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FIFOLOG_IDENT
value|0x3fffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LOCAL_FIFOLOG_H_ */
end_comment

end_unit

