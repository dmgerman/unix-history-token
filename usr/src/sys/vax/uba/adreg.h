begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	adreg.h	4.1	82/06/26	*/
end_comment

begin_struct
struct|struct
name|addevice
block|{
name|short
name|int
name|ad_csr
decl_stmt|;
comment|/* Control status register */
name|short
name|int
name|ad_data
decl_stmt|;
comment|/* Data buffer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AD_CHAN
value|(('a'<<8)|0)
end_define

begin_define
define|#
directive|define
name|AD_READ
value|(('a'<<8)|1)
end_define

begin_comment
comment|/*  * Unibus CSR register bits  */
end_comment

begin_define
define|#
directive|define
name|AD_START
value|01
end_define

begin_define
define|#
directive|define
name|AD_SCHMITT
value|020
end_define

begin_define
define|#
directive|define
name|AD_CLOCK
value|040
end_define

begin_define
define|#
directive|define
name|AD_IENABLE
value|0100
end_define

begin_define
define|#
directive|define
name|AD_DONE
value|0200
end_define

begin_define
define|#
directive|define
name|AD_INCENABLE
value|040000
end_define

begin_define
define|#
directive|define
name|AD_ERROR
value|0100000
end_define

end_unit

