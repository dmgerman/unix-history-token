begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* The linker can generate branch islands.  */
end_comment

begin_define
define|#
directive|define
name|DARWIN_LINKER_GENERATES_ISLANDS
value|1
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_COMMON
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {									\     unsigned HOST_WIDE_INT _new_size = (SIZE);				\     fprintf ((FILE), ".comm ");						\     assemble_name ((FILE), (NAME));					\     if (_new_size == 0) _new_size = 1;					\     fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",		\ 	     _new_size, floor_log2 ((ALIGN) / BITS_PER_UNIT));		\   } while (0)
end_define

end_unit

