begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GCC for Intel i386 running SCO.  */
end_comment

begin_comment
comment|/* Big buffers improve performance.  */
end_comment

begin_define
define|#
directive|define
name|IO_BUFFER_SIZE
value|(0x8000 - 1024)
end_define

end_unit

