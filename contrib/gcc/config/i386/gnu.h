begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an i386 running GNU with ELF as the target machine.  */
end_comment

begin_comment
comment|/* This does it mostly for us.  */
end_comment

begin_include
include|#
directive|include
file|<i386/linux.h>
end_include

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Di386 -Acpu(i386) -Amachine(i386) \ -Dunix -Asystem(unix)  -DMACH -Asystem(mach) -D__GNU__ -Asystem(gnu)"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i386 GNU)");
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-m elf_i386 %{shared:-shared} \   %{!shared: \     %{!static: \       %{rdynamic:-export-dynamic} \       %{!dynamic-linker:-dynamic-linker /lib/ld.so}} \     %{static:-static}}"
end_define

begin_comment
comment|/* Get machine-independent configuration parameters for the GNU system.  */
end_comment

begin_include
include|#
directive|include
file|<gnu.h>
end_include

end_unit

