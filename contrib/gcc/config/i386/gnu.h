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

begin_comment
comment|/* Get machine-independent configuration parameters for the GNU system.  */
end_comment

begin_include
include|#
directive|include
file|<gnu.h>
end_include

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
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__ELF__ -D__i386__ -DMACH -Asystem(mach) \   -Dunix -Asystem(unix) -Asystem(posix) -D__GNU__ -Asystem(gnu)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) \   %{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__} \   %{posix:-D_POSIX_SOURCE} %{bsd:-D_BSD_SOURCE}"
end_define

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%(cc1_cpu)"
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

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared: \      %{!static: \        %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}} \      %{static:crt0.o%s}} \    crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

end_unit

