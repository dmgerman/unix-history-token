begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC, for bi-arch SPARC    running Solaris 2 using the GNU assembler.  */
end_comment

begin_undef
undef|#
directive|undef
name|AS_SPARC64_FLAG
end_undef

begin_define
define|#
directive|define
name|AS_SPARC64_FLAG
value|"-TSO -64 -Av9"
end_define

begin_comment
comment|/* Emit a DTP-relative reference to a TLS variable.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AS_TLS
end_ifdef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DWARF_DTPREL
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|,
name|X
parameter_list|)
define|\
value|sparc_output_dwarf_dtprel (FILE, SIZE, X)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

