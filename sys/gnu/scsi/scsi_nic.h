begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"@(#)$Id: scsi_nic.h,v 1.1 1995/01/25 14:06:18 jkr Exp jkr $"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  II - Version 0.1 $Revision: 1.1 $   $State: Exp $  *  * Copyright 1994 Dietmar Friede  *******************************************************************************  * Bug reports, patches, comments, suggestions should be sent to:  *  *	jkr@saarlink.de or jkrause@guug.de  *  *******************************************************************************  * $Log: scsi_nic.h,v $  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * This file defines the NICCY 5000 Interface.  * Copyright Dr. Neuhaus GmbH, Hamburg and Dietmar Friede  * */
end_comment

begin_define
define|#
directive|define
name|GET_MSG_COMMAND
value|0x08
end_define

begin_define
define|#
directive|define
name|PUT_MSG_COMMAND
value|0x0a
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_struct
struct|struct
name|scsi_msg
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|dummy
decl_stmt|;
name|u_char
name|len
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|Type
decl_stmt|;
name|unsigned
name|char
name|SubType
decl_stmt|;
name|unsigned
name|short
name|Number
decl_stmt|;
name|unsigned
name|char
name|MoreData
decl_stmt|;
name|unsigned
name|char
name|Reserved
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|short
name|DataLen
decl_stmt|;
name|unsigned
name|short
name|PLCI
decl_stmt|;
block|}
name|Header
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNIC_BUF_SIZE
value|2048+15
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Header
name|h
decl_stmt|;
name|unsigned
name|char
name|Data
index|[
name|SNIC_BUF_SIZE
index|]
decl_stmt|;
block|}
name|Buffer
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

end_unit

