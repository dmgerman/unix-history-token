begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for bi-arch SPARC    running Solaris 2 using the GNU linker.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_ARCH_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
value|"\ %{m32:-m elf32_sparc %(link_arch32)} \ %{m64:-m elf64_sparc %(link_arch64)} \ %{!m32:%{!m64:%(link_arch_default)}} \ "
end_define

end_unit

