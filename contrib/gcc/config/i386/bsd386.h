begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an i386 running BSDI's BSD/386 1.1 as the target    machine.  */
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

end_unit

