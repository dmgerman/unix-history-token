begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an i386 running GNU with ELF as the target machine.  */
end_comment

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
name|TARGET_OS_CPP_BUILTINS
end_undef

begin_comment
comment|/* config.gcc includes i386/linux.h.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\ 	HURD_TARGET_OS_CPP_BUILTINS();		\ 	if (flag_pic)				\ 	  {					\ 	    builtin_define ("__PIC__");		\ 	    builtin_define ("__pic__");		\ 	  }					\     }						\   while (0)
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
value|"%{posix:-D_POSIX_SOURCE} %{bsd:-D_BSD_SOURCE}"
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
value|"%{!shared: \      %{!static: \        %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}} \      %{static:crt0.o%s}} \    crti.o%s %{static:crtbeginT.o%s}\    %{!static:%{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}}"
end_define

begin_comment
comment|/* FIXME: Is a Hurd-specific fallback mechanism necessary?  */
end_comment

begin_undef
undef|#
directive|undef
name|MD_FALLBACK_FRAME_STATE_FOR
end_undef

end_unit

