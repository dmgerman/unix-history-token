begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for SPARC running Solaris 2    using the system linker.  */
end_comment

begin_comment
comment|/* At least up through Solaris 2.6,    the system linker does not work with DWARF or DWARF2,    since it does not have working support for relocations    to unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|LINKER_DOES_NOT_WORK_WITH_DWARF2
end_define

end_unit

