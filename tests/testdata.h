begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|__ASSEMBLY__
end_ifdef

begin_define
define|#
directive|define
name|ASM_CONST_LL
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_CONST_LL
parameter_list|(
name|x
parameter_list|)
value|(x##ULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TEST_ADDR_1
value|ASM_CONST_LL(0xdeadbeef00000000)
end_define

begin_define
define|#
directive|define
name|TEST_SIZE_1
value|ASM_CONST_LL(0x100000)
end_define

begin_define
define|#
directive|define
name|TEST_ADDR_2
value|ASM_CONST_LL(123456789)
end_define

begin_define
define|#
directive|define
name|TEST_SIZE_2
value|ASM_CONST_LL(010000)
end_define

begin_define
define|#
directive|define
name|TEST_VALUE_1
value|0xdeadbeef
end_define

begin_define
define|#
directive|define
name|TEST_VALUE_2
value|123456789
end_define

begin_define
define|#
directive|define
name|PHANDLE_1
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHANDLE_2
value|0x2001
end_define

begin_define
define|#
directive|define
name|TEST_STRING_1
value|"hello world"
end_define

begin_define
define|#
directive|define
name|TEST_STRING_2
value|"nastystring: \a\b\t\n\v\f\r\\\""
end_define

begin_define
define|#
directive|define
name|TEST_STRING_3
value|"\xde\xad\xbe\xef"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|fdt_header
name|_test_tree1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fdt_header
name|_truncated_property
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fdt_header
name|_bad_node_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fdt_header
name|_bad_node_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fdt_header
name|_bad_prop_char
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __ASSEMBLY */
end_comment

end_unit

