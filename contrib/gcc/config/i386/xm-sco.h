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

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_comment
comment|/* The SCO compiler gets it wrong, and treats enumerated bitfields    as signed quantities, making it impossible to use an 8-bit enum    for compiling GNU C++.  */
end_comment

begin_define
define|#
directive|define
name|ONLY_INT_FIELDS
value|1
end_define

begin_define
define|#
directive|define
name|CODE_FIELD_BUG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

