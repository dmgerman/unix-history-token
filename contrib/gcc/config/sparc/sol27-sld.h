begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Up through Solaris 2.7, the system linker does not work with DWARF    or DWARF2, since it does not have working support for relocations    to unaligned data.  */
end_comment

begin_undef
undef|#
directive|undef
name|DWARF_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|DWARF2_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|ASM_DEBUG_SPEC
end_undef

end_unit

