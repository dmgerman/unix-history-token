begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)scsi.c	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * SCSI utility routines for making SCSI device drivers easier.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<pmax/dev/device.h>
end_include

begin_include
include|#
directive|include
file|<pmax/dev/scsi.h>
end_include

begin_comment
comment|/*  * The error codes for class 0-6 sense data are class specific.  * The follow arrays of strings are used to print error messages.  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|Class0Errors
index|[]
init|=
block|{
literal|"No sense data"
block|,
literal|"No index signal"
block|,
literal|"No seek complete"
block|,
literal|"Write fault"
block|,
literal|"Drive not ready"
block|,
literal|"Drive not selected"
block|,
literal|"No Track 00"
block|,
literal|"Multiple drives selected"
block|,
literal|"No address acknowledged"
block|,
literal|"Media not loaded"
block|,
literal|"Insufficient capacity"
block|,
literal|"Drive timeout"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|Class1Errors
index|[]
init|=
block|{
literal|"ID CRC error"
block|,
literal|"Unrecoverable data error"
block|,
literal|"ID address mark not found"
block|,
literal|"Data address mark not found"
block|,
literal|"Record not found"
block|,
literal|"Seek error"
block|,
literal|"DMA timeout error"
block|,
literal|"Write protected"
block|,
literal|"Correctable data check"
block|,
literal|"Bad block found"
block|,
literal|"Interleave error"
block|,
literal|"Data transfer incomplete"
block|,
literal|"Unformatted or bad format on drive"
block|,
literal|"Self test failed"
block|,
literal|"Defective track (media errors)"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|Class2Errors
index|[]
init|=
block|{
literal|"Invalid command"
block|,
literal|"Illegal block address"
block|,
literal|"Aborted"
block|,
literal|"Volume overflow"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|Class7Errors
index|[]
init|=
block|{
literal|"No sense data"
block|,
literal|"Recoverable error"
block|,
literal|"Drive not ready"
block|,
literal|"Media error"
block|,
literal|"Hardware error"
block|,
literal|"Illegal request"
block|,
literal|"Unit attention"
block|,
literal|"Write protected"
block|,
literal|"Blank check error"
block|,
literal|"Vendor error"
block|,
literal|"Powerup failure"
block|,
literal|"Abort"
block|,
literal|"Equal"
block|,
literal|"Overflow"
block|,
literal|"Reserved14/miscompare"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|scsiNumErrors
index|[]
init|=
block|{
sizeof|sizeof
argument_list|(
name|Class0Errors
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|Class1Errors
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|Class2Errors
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
modifier|*
name|scsiErrors
index|[]
init|=
block|{
name|Class0Errors
block|,
name|Class1Errors
block|,
name|Class2Errors
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Decode the sense data and print a suitable message.  */
end_comment

begin_expr_stmt
name|scsiPrintSense
argument_list|(
name|sp
argument_list|,
name|len
argument_list|)
specifier|register
name|ScsiClass7Sense
operator|*
name|sp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|ScsiClass0Sense
modifier|*
name|sp0
decl_stmt|;
name|int
name|class
decl_stmt|,
name|code
decl_stmt|;
if|if
condition|(
name|sp
operator|->
name|error7
operator|!=
literal|0x70
condition|)
block|{
name|sp0
operator|=
operator|(
name|ScsiClass0Sense
operator|*
operator|)
name|sp
expr_stmt|;
name|class
operator|=
name|sp0
operator|->
name|error
operator|>>
literal|4
expr_stmt|;
name|code
operator|=
name|sp0
operator|->
name|error
operator|&
literal|0xF
expr_stmt|;
if|if
condition|(
name|code
operator|>=
name|scsiNumErrors
index|[
name|class
index|]
condition|)
name|printf
argument_list|(
literal|"sense error 0x%x"
argument_list|,
name|sp0
operator|->
name|error
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|scsiErrors
index|[
name|class
index|]
index|[
name|code
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|valid
condition|)
name|printf
argument_list|(
literal|", blk %d"
argument_list|,
operator|(
name|sp0
operator|->
name|highAddr
operator|<<
literal|16
operator|)
operator||
operator|(
name|sp0
operator|->
name|midAddr
operator|<<
literal|8
operator|)
operator||
name|sp0
operator|->
name|lowAddr
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|sp
operator|->
name|key
operator|>=
sizeof|sizeof
argument_list|(
name|Class7Errors
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
condition|)
name|printf
argument_list|(
literal|"sense class 7 error 0x%x"
argument_list|,
name|sp
operator|->
name|key
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|Class7Errors
index|[
name|sp
operator|->
name|key
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|fileMark
condition|)
name|printf
argument_list|(
literal|", file mark seen"
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|endOfMedia
condition|)
name|printf
argument_list|(
literal|", end of media seen"
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|badBlockLen
condition|)
name|printf
argument_list|(
literal|", block length mis-match"
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|valid
condition|)
name|printf
argument_list|(
literal|", blk %d"
argument_list|,
operator|(
name|sp
operator|->
name|info1
operator|<<
literal|24
operator|)
operator||
operator|(
name|sp
operator|->
name|info2
operator|<<
literal|16
operator|)
operator||
operator|(
name|sp
operator|->
name|info3
operator|<<
literal|8
operator|)
operator||
name|sp
operator|->
name|info4
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Setup a command block for a SCSI Group0 command.  */
end_comment

begin_function
name|void
name|scsiGroup0Cmd
parameter_list|(
name|cmd
parameter_list|,
name|lun
parameter_list|,
name|block
parameter_list|,
name|count
parameter_list|,
name|c
parameter_list|)
name|unsigned
name|cmd
decl_stmt|;
comment|/* group0 SCSI command */
name|unsigned
name|lun
decl_stmt|;
comment|/* Logical Unit Number */
specifier|register
name|unsigned
name|block
decl_stmt|;
comment|/* starting block number for transfer */
name|unsigned
name|count
decl_stmt|;
comment|/* # of sectors/bytes to transfer */
specifier|register
name|ScsiGroup0Cmd
modifier|*
name|c
decl_stmt|;
comment|/* command to be filled in */
block|{
name|c
operator|->
name|command
operator|=
name|cmd
expr_stmt|;
name|c
operator|->
name|unitNumber
operator|=
name|lun
expr_stmt|;
name|c
operator|->
name|highAddr
operator|=
name|block
operator|>>
literal|16
expr_stmt|;
name|c
operator|->
name|midAddr
operator|=
name|block
operator|>>
literal|8
expr_stmt|;
name|c
operator|->
name|lowAddr
operator|=
name|block
expr_stmt|;
name|c
operator|->
name|blockCount
operator|=
name|count
expr_stmt|;
name|c
operator|->
name|control
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Setup a command block for a SCSI Group1 command.  */
end_comment

begin_function
name|void
name|scsiGroup1Cmd
parameter_list|(
name|cmd
parameter_list|,
name|lun
parameter_list|,
name|block
parameter_list|,
name|count
parameter_list|,
name|c
parameter_list|)
name|unsigned
name|cmd
decl_stmt|;
comment|/* group0 SCSI command */
name|unsigned
name|lun
decl_stmt|;
comment|/* Logical Unit Number */
specifier|register
name|unsigned
name|block
decl_stmt|;
comment|/* starting block number for transfer */
name|unsigned
name|count
decl_stmt|;
comment|/* # of sectors/bytes to transfer */
specifier|register
name|ScsiGroup1Cmd
modifier|*
name|c
decl_stmt|;
comment|/* command to be filled in */
block|{
name|c
operator|->
name|command
operator|=
name|cmd
expr_stmt|;
name|c
operator|->
name|unitNumber
operator|=
name|lun
expr_stmt|;
name|c
operator|->
name|pad1
operator|=
literal|0
expr_stmt|;
name|c
operator|->
name|highAddr
operator|=
name|block
operator|>>
literal|24
expr_stmt|;
name|c
operator|->
name|midHighAddr
operator|=
name|block
operator|>>
literal|16
expr_stmt|;
name|c
operator|->
name|midLowAddr
operator|=
name|block
operator|>>
literal|8
expr_stmt|;
name|c
operator|->
name|lowAddr
operator|=
name|block
expr_stmt|;
name|c
operator|->
name|pad2
operator|=
literal|0
expr_stmt|;
name|c
operator|->
name|highBlockCount
operator|=
name|count
operator|>>
literal|8
expr_stmt|;
name|c
operator|->
name|lowBlockCount
operator|=
name|count
expr_stmt|;
name|c
operator|->
name|control
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

