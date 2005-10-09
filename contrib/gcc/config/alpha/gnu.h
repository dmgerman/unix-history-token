begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an Alpha running GNU with ELF as the target machine.  */
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
value|fprintf (stderr, " (Alpha GNU)");
end_define

begin_undef
undef|#
directive|undef
name|TARGET_OS_CPP_BUILTINS
end_undef

begin_comment
comment|/* config.gcc includes alpha/linux.h.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {					\ 	HURD_TARGET_OS_CPP_BUILTINS();		\ 	builtin_define ("_LONGLONG");		\     } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ELF_DYNAMIC_LINKER
end_undef

begin_define
define|#
directive|define
name|ELF_DYNAMIC_LINKER
value|"/lib/ld.so"
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
value|"%{!shared: \      %{!static: \        %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}} \      %{static:crt0.o%s}} \    crti.o%s \    %{!static:%{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}}"
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

