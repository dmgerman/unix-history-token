begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC, for SPARC running Solaris 2    using the GNU assembler.  */
end_comment

begin_comment
comment|/* Undefine this so that BNSYM/ENSYM pairs are emitted by STABS+.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DBX_BNSYM_ENSYM
end_undef

begin_comment
comment|/* Use GNU extensions to TLS support.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AS_TLS
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_SUN_TLS
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_GNU_TLS
end_undef

begin_define
define|#
directive|define
name|TARGET_SUN_TLS
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_GNU_TLS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

