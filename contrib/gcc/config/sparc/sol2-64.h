begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for 64-bit SPARC    running Solaris 2 using the GNU linker.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LINKER_DOES_NOT_WORK_WITH_DWARF2
end_ifdef

begin_undef
undef|#
directive|undef
name|LINKER_DOES_NOT_WORK_WITH_DWARF2
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AS_SPARC64_FLAG
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|LINK_ARCH_SPEC
end_ifdef

begin_undef
undef|#
directive|undef
name|LINK_ARCH_SPEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
value|"\ %{m32:-m elf32_sparc %(link_arch32)} \ %{m64:-m elf64_sparc %(link_arch64)} \ %{!m32:%{!m64:%(link_arch_default)}} \ "
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

