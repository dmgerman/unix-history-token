begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an i386 running BSDI's BSD/OS (formerly known as BSD/386)    as the target machine.  */
end_comment

begin_include
include|#
directive|include
file|"i386/386bsd.h"
end_include

begin_comment
comment|/* We exist mostly to add -Dbsdi and such to the predefines. */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -Dbsdi -D__i386__ -D__bsdi__ -D____386BSD____ -D__386BSD__ -DBSD_NET2 -Asystem(unix) -Asystem(bsd) -Acpu(i386) -Amachine(i386)"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_UNSIGNED
end_undef

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|0
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* This is suitable for BSD/OS 3.0; we don't know about earlier releases.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|" #"
end_define

begin_comment
comment|/* Until they use ELF or something that handles dwarf2 unwinds    and initialization stuff better.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_comment
comment|/* BSD/OS still uses old binutils that don't insert nops by default    when the .align directive demands to insert extra space in the text    segment.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|if ((LOG)!=0) fprintf ((FILE), "\t.align %d,0x90\n", (LOG))
end_define

end_unit

