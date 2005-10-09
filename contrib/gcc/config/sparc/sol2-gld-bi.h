begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC, for bi-arch SPARC    running Solaris 2 using the GNU linker.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_ARCH32_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_ARCH32_SPEC
define|\
value|LINK_ARCH32_SPEC_BASE "%{!static: -rpath-link %R/usr/lib}"
end_define

begin_undef
undef|#
directive|undef
name|LINK_ARCH64_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_ARCH64_SPEC
define|\
value|LINK_ARCH64_SPEC_BASE "%{!static: -rpath-link %R/usr/lib/sparcv9}"
end_define

begin_undef
undef|#
directive|undef
name|LINK_ARCH_SPEC
end_undef

begin_if
if|#
directive|if
name|DISABLE_MULTILIB
end_if

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
value|"\ %{m32:-m elf32_sparc %(link_arch32)} \ %{m64:%edoes not support multilib} \ %{!m32:%{!m64:%(link_arch_default)}} \ "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
value|"\ %{m32:%edoes not support multilib} \ %{m64:-m elf64_sparc %(link_arch64)} \ %{!m32:%{!m64:%(link_arch_default)}} \ "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

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

