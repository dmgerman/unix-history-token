begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|FINI_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INIT_ARRAY_SECTION_ASM_OP
value|"\t.section\t.init_array,\"aw\",%init_array"
end_define

begin_define
define|#
directive|define
name|FINI_ARRAY_SECTION_ASM_OP
value|"\t.section\t.fini_array,\"aw\",%fini_array"
end_define

end_unit

