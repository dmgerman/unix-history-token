begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Intel 8237 DMA Controller  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|DMA37MD_SINGLE
value|0x40
end_define

begin_comment
comment|/* single pass mode */
end_comment

begin_define
define|#
directive|define
name|DMA37MD_CASCADE
value|0xc0
end_define

begin_comment
comment|/* cascade mode */
end_comment

begin_define
define|#
directive|define
name|DMA37MD_AUTO
value|0x50
end_define

begin_comment
comment|/* autoinitialise single pass mode */
end_comment

begin_define
define|#
directive|define
name|DMA37MD_WRITE
value|0x04
end_define

begin_comment
comment|/* read the device, write memory operation */
end_comment

begin_define
define|#
directive|define
name|DMA37MD_READ
value|0x08
end_define

begin_comment
comment|/* write the device, read memory operation */
end_comment

end_unit

