begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Hyperchannel Log Printer  *  * Copyright (c) 1983, Tektronix Inc.  * All Rights Reserved  *  */
end_comment

begin_decl_stmt
name|char
name|_rcsid
index|[]
init|=
literal|"$Header$$Locker$"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ok
parameter_list|(
name|x
parameter_list|)
value|(((int)(x))& 0x7fffffff)
end_define

begin_define
define|#
directive|define
name|HYELOG
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<vaxif/if_hyreg.h>
end_include

begin_include
include|#
directive|include
file|<vaxif/if_hy.h>
end_include

begin_decl_stmt
name|struct
name|nlist
name|nl
index|[
literal|2
index|]
init|=
block|{
block|{
literal|"_hy_elog"
block|}
block|,
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|hy_elog
index|[
name|HYE_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|hye_code
index|[]
init|=
block|{
literal|"message code 0 - INVALID"
block|,
comment|/* 00 */
literal|"adapter rcv data from trunk"
block|,
comment|/* 01 */
literal|"bad message length"
block|,
comment|/* 02 */
literal|"no space for message"
block|,
comment|/* 03 */
literal|"to port marked down"
block|,
comment|/* 04 */
literal|"no space for assoc data"
block|,
comment|/* 05 */
literal|"assoc data too big"
block|,
comment|/* 06 */
literal|"illegal function code"
block|,
comment|/* 07 */
literal|"message code 8 - INVALID"
block|,
comment|/* 08 */
literal|"message code 9 - INVALID"
block|,
comment|/* 09 */
literal|"not enough parameters"
block|,
comment|/* 0A */
literal|"too many parameters"
block|,
comment|/* 0B */
literal|"not enough data send to adapter"
block|,
comment|/* 0C */
literal|"too much data sent to adapter"
block|,
comment|/* 0D */
literal|"not all data read from buffer"
block|,
comment|/* 0E */
literal|"host tried to read too much data"
block|,
comment|/* 0F */
literal|"no messages queued for this port"
block|,
comment|/* 10 */
literal|"host master cleared during xfer"
block|,
comment|/* 11 */
literal|"host quit early"
block|,
comment|/* 12 */
literal|"parity error from arapter to host"
block|,
comment|/* 13 */
literal|"trunk transmission aborted"
block|,
comment|/* 14 */
literal|"device reserved to this adapter"
block|,
comment|/* 15 */
literal|"trunk xmit retry counter expired"
block|,
comment|/* 16 */
literal|"other adapter didn't send assoc data"
block|,
comment|/* 17 */
literal|"message code out of range"
comment|/* 18 */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
specifier|register
name|unsigned
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|ep
decl_stmt|;
specifier|register
name|unsigned
name|i
decl_stmt|;
name|int
name|mem
decl_stmt|;
name|nlist
argument_list|(
literal|"/vmunix"
argument_list|,
name|nl
argument_list|)
expr_stmt|;
if|if
condition|(
name|nl
index|[
literal|0
index|]
operator|.
name|n_type
operator|==
literal|0
condition|)
name|done
argument_list|(
literal|"No namelist\n"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|mem
operator|=
name|open
argument_list|(
literal|"/dev/kmem"
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|done
argument_list|(
literal|"Can't oper /dev/kmem\n"
argument_list|)
expr_stmt|;
name|lseek
argument_list|(
name|mem
argument_list|,
operator|(
name|long
operator|)
name|nl
index|[
literal|0
index|]
operator|.
name|n_value
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|read
argument_list|(
name|mem
argument_list|,
name|hy_elog
argument_list|,
sizeof|sizeof
argument_list|(
name|hy_elog
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Error	Other	XMITMSG	LSTDATA	LOCMSG	Error Description\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|HYE_MAX
condition|;
name|i
operator|++
control|)
block|{
name|printf
argument_list|(
literal|"%02x	%6d	%6d	%6d	%6d - %s\n"
argument_list|,
name|i
argument_list|,
name|hy_elog
index|[
name|i
index|]
argument_list|,
name|hy_elog
index|[
name|i
operator|+
operator|(
name|HYE_MAX
operator|+
literal|1
operator|)
index|]
argument_list|,
name|hy_elog
index|[
name|i
operator|+
literal|2
operator|*
operator|(
name|HYE_MAX
operator|+
literal|1
operator|)
index|]
argument_list|,
name|hy_elog
index|[
name|i
operator|+
literal|3
operator|*
operator|(
name|HYE_MAX
operator|+
literal|1
operator|)
index|]
argument_list|,
name|hye_code
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_macro
name|done
argument_list|(
argument|s
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|s
argument_list|,
operator|&
name|p
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

