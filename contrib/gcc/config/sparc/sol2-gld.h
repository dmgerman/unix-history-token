begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC, for SPARC running Solaris 2    using the GNU linker.  */
end_comment

begin_comment
comment|/* Undefine this so that attribute((init_priority)) works.  */
end_comment

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|SUPPORTS_INIT_PRIORITY
end_undef

begin_define
define|#
directive|define
name|SUPPORTS_INIT_PRIORITY
value|1
end_define

end_unit

