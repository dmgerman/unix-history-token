begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_struct
struct|struct
name|spi_command
block|{
name|void
modifier|*
name|tx_cmd
decl_stmt|;
name|uint32_t
name|tx_cmd_sz
decl_stmt|;
name|void
modifier|*
name|rx_cmd
decl_stmt|;
name|uint32_t
name|rx_cmd_sz
decl_stmt|;
name|void
modifier|*
name|tx_data
decl_stmt|;
name|uint32_t
name|tx_data_sz
decl_stmt|;
name|void
modifier|*
name|rx_data
decl_stmt|;
name|uint32_t
name|rx_data_sz
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SPI_CHIP_SELECT_HIGH
value|0x1
end_define

begin_comment
comment|/* Chip select high (else low) */
end_comment

end_unit

