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

begin_ifndef
ifndef|#
directive|ifndef
name|PC98
end_ifndef

begin_comment
comment|/* **  Register definitions for DMA controller 1 (channels 0..3): */
end_comment

begin_define
define|#
directive|define
name|DMA1_CHN
parameter_list|(
name|c
parameter_list|)
value|(IO_DMA1 + 1*(2*(c)))
end_define

begin_comment
comment|/* addr reg for channel c */
end_comment

begin_define
define|#
directive|define
name|DMA1_STATUS
value|(IO_DMA1 + 1*8)
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|DMA1_SMSK
value|(IO_DMA1 + 1*10)
end_define

begin_comment
comment|/* single mask register */
end_comment

begin_define
define|#
directive|define
name|DMA1_MODE
value|(IO_DMA1 + 1*11)
end_define

begin_comment
comment|/* mode register */
end_comment

begin_define
define|#
directive|define
name|DMA1_FFC
value|(IO_DMA1 + 1*12)
end_define

begin_comment
comment|/* clear first/last FF */
end_comment

begin_define
define|#
directive|define
name|DMA1_RESET
value|(IO_DMA1 + 1*13)
end_define

begin_comment
comment|/* reset */
end_comment

begin_comment
comment|/* **  Register definitions for DMA controller 2 (channels 4..7): */
end_comment

begin_define
define|#
directive|define
name|DMA2_CHN
parameter_list|(
name|c
parameter_list|)
value|(IO_DMA2 + 2*(2*(c)))
end_define

begin_comment
comment|/* addr reg for channel c */
end_comment

begin_define
define|#
directive|define
name|DMA2_STATUS
value|(IO_DMA2 + 2*8)
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|DMA2_SMSK
value|(IO_DMA2 + 2*10)
end_define

begin_comment
comment|/* single mask register */
end_comment

begin_define
define|#
directive|define
name|DMA2_MODE
value|(IO_DMA2 + 2*11)
end_define

begin_comment
comment|/* mode register */
end_comment

begin_define
define|#
directive|define
name|DMA2_FFC
value|(IO_DMA2 + 2*12)
end_define

begin_comment
comment|/* clear first/last FF */
end_comment

begin_define
define|#
directive|define
name|DMA2_RESET
value|(IO_DMA2 + 2*13)
end_define

begin_comment
comment|/* reset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

