begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dsparc -Dsun -Dunix -Asystem=unix -Asystem=bsd"
end_define

begin_comment
comment|/* Override the name of the mcount profiling function.  */
end_comment

begin_undef
undef|#
directive|undef
name|MCOUNT_FUNCTION
end_undef

begin_define
define|#
directive|define
name|MCOUNT_FUNCTION
value|"*.mcount"
end_define

begin_comment
comment|/* LINK_SPEC is needed only for SunOS 4.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

end_unit

