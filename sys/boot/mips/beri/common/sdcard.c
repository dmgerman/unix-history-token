begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2014 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * Altera University Program SD Card micro-driver for boot2 and loader.  *  * XXXRW: It might be nice to add 'unit' arguments to all APIs to allow  * multiple instances to be addressed.  */
end_comment

begin_comment
comment|/* Constants lifted from altera_sdcard.h -- possibly we should share headers? */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_RXTX_BUFFER
value|0
end_define

begin_comment
comment|/* 512-byte I/O buffer */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_CID
value|512
end_define

begin_comment
comment|/* 16-byte Card ID number */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_CSD
value|528
end_define

begin_comment
comment|/* 16-byte Card Specific Data */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_OCR
value|544
end_define

begin_comment
comment|/* Operating Conditions Reg */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_SR
value|548
end_define

begin_comment
comment|/* SD Card Status Register */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_RCA
value|552
end_define

begin_comment
comment|/* Relative Card Address Reg */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_CMD_ARG
value|556
end_define

begin_comment
comment|/* Command Argument Register */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_CMD
value|560
end_define

begin_comment
comment|/* Command Register */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_ASR
value|564
end_define

begin_comment
comment|/* Auxiliary Status Register */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_OFF_RR1
value|568
end_define

begin_comment
comment|/* Response R1 */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_SECTORSIZE
value|512
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CMD_SEND_RCA
value|0x03
end_define

begin_comment
comment|/* Retrieve card RCA. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CMD_SEND_CSD
value|0x09
end_define

begin_comment
comment|/* Retrieve CSD register. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CMD_SEND_CID
value|0x0A
end_define

begin_comment
comment|/* Retrieve CID register. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CMD_READ_BLOCK
value|0x11
end_define

begin_comment
comment|/* Read block from disk. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CMD_WRITE_BLOCK
value|0x18
end_define

begin_comment
comment|/* Write block to disk. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_CMDVALID
value|0x0001
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_CARDPRESENT
value|0x0002
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_CMDINPROGRESS
value|0x0004
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_SRVALID
value|0x0008
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_CMDTIMEOUT
value|0x0010
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_ASR_CMDDATAERROR
value|0x0020
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_INITPROCRUNNING
value|0x0100
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_ERASEINTERRUPTED
value|0x0200
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_ILLEGALCOMMAND
value|0x0400
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_COMMANDCRCFAILED
value|0x0800
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_ADDRESSMISALIGNED
value|0x1000
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_ADDRBLOCKRANGE
value|0x2000
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_STRUCTURE_BYTE
value|15
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_STRUCTURE_MASK
value|0xc0
end_define

begin_comment
comment|/* 2 bits */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_STRUCTURE_RSHIFT
value|6
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_READ_BL_LEN_BYTE
value|10
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_READ_BL_LEN_MASK
value|0x0f
end_define

begin_comment
comment|/* 4 bits */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_BYTE0
value|7
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MASK0
value|0xc0
end_define

begin_comment
comment|/* top 2 bits */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_RSHIFT0
value|6
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_BYTE1
value|8
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MASK1
value|0xff
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_LSHIFT1
value|2
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_BYTE2
value|9
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MASK2
value|0x03
end_define

begin_comment
comment|/* bottom 2 bits */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_LSHIFT2
value|10
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_BYTE0
value|5
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_MASK0
value|0x80
end_define

begin_comment
comment|/* top 1 bit */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_RSHIFT0
value|7
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_BYTE1
value|6
end_define

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_MASK1
value|0x03
end_define

begin_comment
comment|/* bottom 2 bits */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_LSHIFT1
value|1
end_define

begin_comment
comment|/*  * Not all RR1 values are "errors" per se -- check only for the ones that are  * when performing error handling.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_SDCARD_RR1_ERRORMASK
define|\
value|(ALTERA_SDCARD_RR1_ERASEINTERRUPTED | ALTERA_SDCARD_RR1_ILLEGALCOMMAND |  \     ALTERA_SDCARD_RR1_COMMANDCRCFAILED | ALTERA_SDCARD_RR1_ADDRESSMISALIGNED |\     ALTERA_SDCARD_RR1_ADDRBLOCKRANGE)
end_define

begin_decl_stmt
specifier|extern
name|void
name|__cheri_sdcard_vaddr__
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ALTERA_SDCARD_PTR
parameter_list|(
name|type
parameter_list|,
name|offset
parameter_list|)
define|\
value|(volatile type *)((uint8_t *)&__cheri_sdcard_vaddr__ + (offset))
end_define

begin_function
specifier|static
name|__inline
name|uint16_t
name|altera_sdcard_read_uint16
parameter_list|(
name|u_int
name|offset
parameter_list|)
block|{
specifier|volatile
name|uint16_t
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|ALTERA_SDCARD_PTR
argument_list|(
name|uint16_t
argument_list|,
name|offset
argument_list|)
expr_stmt|;
return|return
operator|(
name|le16toh
argument_list|(
operator|*
name|p
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|altera_sdcard_write_uint16
parameter_list|(
name|u_int
name|offset
parameter_list|,
name|uint16_t
name|v
parameter_list|)
block|{
specifier|volatile
name|uint16_t
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|ALTERA_SDCARD_PTR
argument_list|(
name|uint16_t
argument_list|,
name|offset
argument_list|)
expr_stmt|;
operator|*
name|p
operator|=
name|htole16
argument_list|(
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|altera_sdcard_write_uint32
parameter_list|(
name|u_int
name|offset
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|ALTERA_SDCARD_PTR
argument_list|(
name|uint32_t
argument_list|,
name|offset
argument_list|)
expr_stmt|;
operator|*
name|p
operator|=
name|htole32
argument_list|(
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint16_t
name|altera_sdcard_read_asr
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|altera_sdcard_read_uint16
argument_list|(
name|ALTERA_SDCARD_OFF_ASR
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint16_t
name|altera_sdcard_read_rr1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|altera_sdcard_read_uint16
argument_list|(
name|ALTERA_SDCARD_OFF_RR1
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|altera_sdcard_write_cmd
parameter_list|(
name|uint16_t
name|cmd
parameter_list|)
block|{
name|altera_sdcard_write_uint16
argument_list|(
name|ALTERA_SDCARD_OFF_CMD
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|altera_sdcard_write_cmd_arg
parameter_list|(
name|uint32_t
name|cmd_arg
parameter_list|)
block|{
name|altera_sdcard_write_uint32
argument_list|(
name|ALTERA_SDCARD_OFF_CMD_ARG
argument_list|,
name|cmd_arg
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* NB: Use 16-bit aligned buffer due to hardware features, so 16-bit type. */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|altera_sdcard_read_csd
parameter_list|(
name|uint16_t
modifier|*
name|csdp
parameter_list|)
block|{
specifier|volatile
name|uint16_t
modifier|*
name|hw_csdp
decl_stmt|;
name|u_int
name|i
decl_stmt|;
name|hw_csdp
operator|=
name|ALTERA_SDCARD_PTR
argument_list|(
name|uint16_t
argument_list|,
name|ALTERA_SDCARD_OFF_CSD
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ALTERA_SDCARD_CSD_SIZE
operator|/
sizeof|sizeof
argument_list|(
name|uint16_t
argument_list|)
condition|;
name|i
operator|++
control|)
name|csdp
index|[
name|i
index|]
operator|=
name|hw_csdp
index|[
name|i
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Private interface: load exactly one block of size ALTERA_SDCARD_SECTORSIZE  * from block #lba.  */
end_comment

begin_function
specifier|static
name|int
name|altera_sdcard_read_block
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|lba
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|rxtxp
decl_stmt|;
name|uint32_t
modifier|*
name|bufp
decl_stmt|;
name|uint16_t
name|asr
decl_stmt|,
name|rr1
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|altera_sdcard_read_asr
argument_list|()
operator|&
name|ALTERA_SDCARD_ASR_CARDPRESENT
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"SD Card: card not present\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|bufp
operator|=
operator|(
name|uint32_t
operator|*
operator|)
name|buf
expr_stmt|;
name|rxtxp
operator|=
name|ALTERA_SDCARD_PTR
argument_list|(
name|uint32_t
argument_list|,
name|ALTERA_SDCARD_OFF_RXTX_BUFFER
argument_list|)
expr_stmt|;
comment|/* 	 * Issue read block command. 	 */
name|altera_sdcard_write_cmd_arg
argument_list|(
name|lba
operator|*
name|ALTERA_SDCARD_SECTORSIZE
argument_list|)
expr_stmt|;
name|altera_sdcard_write_cmd
argument_list|(
name|ALTERA_SDCARD_CMD_READ_BLOCK
argument_list|)
expr_stmt|;
comment|/* 	 * Wait for device to signal completion of command. 	 */
while|while
condition|(
operator|(
name|asr
operator|=
name|altera_sdcard_read_asr
argument_list|()
operator|)
operator|&
name|ALTERA_SDCARD_ASR_CMDINPROGRESS
condition|)
empty_stmt|;
comment|/* 	 * Due to hardware bugs/features, interpretting this field is messy. 	 */
name|rr1
operator|=
name|altera_sdcard_read_rr1
argument_list|()
expr_stmt|;
name|rr1
operator|&=
operator|~
name|ALTERA_SDCARD_RR1_COMMANDCRCFAILED
expr_stmt|;
comment|/* HW bug. */
if|if
condition|(
name|asr
operator|&
name|ALTERA_SDCARD_ASR_CMDTIMEOUT
condition|)
block|{
name|printf
argument_list|(
literal|"SD Card: timeout\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|asr
operator|&
name|ALTERA_SDCARD_ASR_CMDDATAERROR
operator|)
operator|&&
operator|(
name|rr1
operator|&
name|ALTERA_SDCARD_RR1_ERRORMASK
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"SD Card: asr %u rr1 %u\n"
argument_list|,
name|asr
argument_list|,
name|rr1
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* 	 * We can't use a regular memcpy() due to byte-enable bugs in the 	 * Altera IP core: instead copy in 32-bit units. 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ALTERA_SDCARD_SECTORSIZE
operator|/
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
condition|;
name|i
operator|++
control|)
name|bufp
index|[
name|i
index|]
operator|=
name|rxtxp
index|[
name|i
index|]
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Public interface: load 'nblk' blocks from block #lba into *buf.  */
end_comment

begin_function
name|int
name|altera_sdcard_read
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|lba
parameter_list|,
name|unsigned
name|nblk
parameter_list|)
block|{
name|uint8_t
modifier|*
name|bufp
init|=
name|buf
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nblk
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|altera_sdcard_read_block
argument_list|(
name|bufp
operator|+
name|i
operator|*
name|ALTERA_SDCARD_SECTORSIZE
argument_list|,
name|lba
operator|+
name|i
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"SD Card: block read %u failed\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Public interface: query (current) media size.  */
end_comment

begin_function
name|uint64_t
name|altera_sdcard_get_mediasize
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|mediasize
decl_stmt|;
name|uint64_t
name|c_size
decl_stmt|,
name|c_size_mult
decl_stmt|,
name|read_bl_len
decl_stmt|;
name|uint16_t
name|csd16
index|[
name|ALTERA_SDCARD_CSD_SIZE
operator|/
sizeof|sizeof
argument_list|(
name|uint16_t
argument_list|)
index|]
decl_stmt|;
name|uint8_t
modifier|*
name|csd8p
init|=
operator|(
name|uint8_t
operator|*
operator|)
operator|&
name|csd16
decl_stmt|;
name|uint8_t
name|byte0
decl_stmt|,
name|byte1
decl_stmt|,
name|byte2
decl_stmt|;
name|altera_sdcard_read_csd
argument_list|(
name|csd16
argument_list|)
expr_stmt|;
comment|/* Provide 16-bit alignment. */
name|read_bl_len
operator|=
name|csd8p
index|[
name|ALTERA_SDCARD_CSD_READ_BL_LEN_BYTE
index|]
expr_stmt|;
name|read_bl_len
operator|&=
name|ALTERA_SDCARD_CSD_READ_BL_LEN_MASK
expr_stmt|;
name|byte0
operator|=
name|csd8p
index|[
name|ALTERA_SDCARD_CSD_C_SIZE_BYTE0
index|]
expr_stmt|;
name|byte0
operator|&=
name|ALTERA_SDCARD_CSD_C_SIZE_MASK0
expr_stmt|;
name|byte1
operator|=
name|csd8p
index|[
name|ALTERA_SDCARD_CSD_C_SIZE_BYTE1
index|]
expr_stmt|;
name|byte2
operator|=
name|csd8p
index|[
name|ALTERA_SDCARD_CSD_C_SIZE_BYTE2
index|]
expr_stmt|;
name|byte2
operator|&=
name|ALTERA_SDCARD_CSD_C_SIZE_MASK2
expr_stmt|;
name|c_size
operator|=
operator|(
name|byte0
operator|>>
name|ALTERA_SDCARD_CSD_C_SIZE_RSHIFT0
operator|)
operator||
operator|(
name|byte1
operator|<<
name|ALTERA_SDCARD_CSD_C_SIZE_LSHIFT1
operator|)
operator||
operator|(
name|byte2
operator|<<
name|ALTERA_SDCARD_CSD_C_SIZE_LSHIFT2
operator|)
expr_stmt|;
name|byte0
operator|=
name|csd8p
index|[
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_BYTE0
index|]
expr_stmt|;
name|byte0
operator|&=
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_MASK0
expr_stmt|;
name|byte1
operator|=
name|csd8p
index|[
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_BYTE1
index|]
expr_stmt|;
name|byte1
operator|&=
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_MASK1
expr_stmt|;
name|c_size_mult
operator|=
operator|(
name|byte0
operator|>>
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_RSHIFT0
operator|)
operator||
operator|(
name|byte1
operator|<<
name|ALTERA_SDCARD_CSD_C_SIZE_MULT_LSHIFT1
operator|)
expr_stmt|;
name|mediasize
operator|=
operator|(
name|c_size
operator|+
literal|1
operator|)
operator|*
operator|(
literal|1
operator|<<
operator|(
name|c_size_mult
operator|+
literal|2
operator|)
operator|)
operator|*
operator|(
literal|1
operator|<<
name|read_bl_len
operator|)
expr_stmt|;
return|return
operator|(
name|mediasize
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Public interface: is media present / supported?  */
end_comment

begin_function
name|int
name|altera_sdcard_get_present
parameter_list|(
name|void
parameter_list|)
block|{
name|uint16_t
name|csd16
index|[
name|ALTERA_SDCARD_CSD_SIZE
operator|/
sizeof|sizeof
argument_list|(
name|uint16_t
argument_list|)
index|]
decl_stmt|;
name|uint8_t
modifier|*
name|csd8p
init|=
operator|(
name|uint8_t
operator|*
operator|)
operator|&
name|csd16
decl_stmt|;
name|uint8_t
name|csd_structure
decl_stmt|;
comment|/* First: does status bit think it is there? */
if|if
condition|(
operator|!
operator|(
name|altera_sdcard_read_asr
argument_list|()
operator|&
name|ALTERA_SDCARD_ASR_CARDPRESENT
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"SD Card: not present\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* Second: do we understand the CSD structure version? */
name|altera_sdcard_read_csd
argument_list|(
name|csd16
argument_list|)
expr_stmt|;
comment|/* Provide 16-bit alignment. */
name|csd_structure
operator|=
name|csd8p
index|[
name|ALTERA_SDCARD_CSD_STRUCTURE_BYTE
index|]
expr_stmt|;
name|csd_structure
operator|&=
name|ALTERA_SDCARD_CSD_STRUCTURE_MASK
expr_stmt|;
name|csd_structure
operator|>>=
name|ALTERA_SDCARD_CSD_STRUCTURE_RSHIFT
expr_stmt|;
if|if
condition|(
name|csd_structure
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"SD Card: unrecognised csd %u\n"
argument_list|,
name|csd_structure
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Public interface: query sector size.  */
end_comment

begin_function
name|uint64_t
name|altera_sdcard_get_sectorsize
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|ALTERA_SDCARD_SECTORSIZE
operator|)
return|;
block|}
end_function

end_unit

