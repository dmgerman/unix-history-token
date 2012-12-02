begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
struct|struct
name|ppi_header
block|{
name|uint8_t
name|ppi_ver
decl_stmt|;
name|uint8_t
name|ppi_flags
decl_stmt|;
name|uint16_t
name|ppi_len
decl_stmt|;
name|uint32_t
name|ppi_dlt
decl_stmt|;
block|}
name|ppi_header_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PPI_HDRLEN
value|8
end_define

end_unit

