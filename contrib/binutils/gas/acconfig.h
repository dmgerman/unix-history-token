begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Should gas use high-level BFD interfaces?  */
end_comment

begin_undef
undef|#
directive|undef
name|BFD_ASSEMBLER
end_undef

begin_comment
comment|/* Some assert/preprocessor combinations are incapable of handling    certain kinds of constructs in the argument of assert.  For example,    quoted strings (if requoting isn't done right) or newlines.  */
end_comment

begin_undef
undef|#
directive|undef
name|BROKEN_ASSERT
end_undef

begin_comment
comment|/* If we aren't doing cross-assembling, some operations can be optimized,    since byte orders and value sizes don't need to be adjusted.  */
end_comment

begin_undef
undef|#
directive|undef
name|CROSS_COMPILE
end_undef

begin_comment
comment|/* Some gas code wants to know these parameters.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ALIAS
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_CPU
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_CANONICAL
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_OS
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_VENDOR
end_undef

begin_comment
comment|/* Sometimes the system header files don't declare strstr.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_STRSTR
end_undef

begin_comment
comment|/* Sometimes the system header files don't declare malloc and realloc.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_MALLOC
end_undef

begin_comment
comment|/* Sometimes the system header files don't declare free.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_FREE
end_undef

begin_comment
comment|/* Sometimes the system header files don't declare sbrk.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_SBRK
end_undef

begin_comment
comment|/* Sometimes errno.h doesn't declare errno itself.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_ERRNO
end_undef

begin_undef
undef|#
directive|undef
name|MANY_SEGMENTS
end_undef

begin_comment
comment|/* Needed only for sparc configuration.  */
end_comment

begin_undef
undef|#
directive|undef
name|SPARC_V9
end_undef

begin_undef
undef|#
directive|undef
name|SPARC_ARCH64
end_undef

begin_comment
comment|/* Needed only for some configurations that can produce multiple output    formats.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_EMULATION
end_undef

begin_undef
undef|#
directive|undef
name|EMULATIONS
end_undef

begin_undef
undef|#
directive|undef
name|USE_EMULATIONS
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_AOUT
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_BOUT
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_COFF
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_ECOFF
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_ELF
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_GENERIC
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_HP300
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_IEEE
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_SOM
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_VMS
end_undef

begin_comment
comment|/* Used for some of the COFF configurations, when the COFF code needs    to select something based on the CPU type before it knows it... */
end_comment

begin_undef
undef|#
directive|undef
name|I386COFF
end_undef

begin_undef
undef|#
directive|undef
name|M68KCOFF
end_undef

begin_undef
undef|#
directive|undef
name|M88KCOFF
end_undef

end_unit

