begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 	unixhdr.h	4.1	82/05/12  */
end_comment

begin_define
define|#
directive|define
name|MAGIC1
value|0407
end_define

begin_define
define|#
directive|define
name|MAGIC2
value|0410
end_define

begin_define
define|#
directive|define
name|MAGIC3
value|0411
end_define

begin_define
define|#
directive|define
name|MAGIC4
value|0405
end_define

begin_struct
struct|struct
block|{
name|unsigned
name|short
name|magic
decl_stmt|;
name|unsigned
name|short
name|textsize
decl_stmt|;
name|unsigned
name|short
name|datasize
decl_stmt|;
name|unsigned
name|short
name|bsssize
decl_stmt|;
name|unsigned
name|short
name|symsize
decl_stmt|;
name|unsigned
name|short
name|entry
decl_stmt|;
name|unsigned
name|short
name|dummy
decl_stmt|;
name|unsigned
name|short
name|relflag
decl_stmt|;
block|}
name|header
struct|;
end_struct

end_unit

