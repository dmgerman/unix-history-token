begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define to 1 if NLS is requested.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENABLE_NLS
end_undef

begin_comment
comment|/* Define as 1 if you have catgets and don't want to use GNU gettext.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CATGETS
end_undef

begin_comment
comment|/* Define as 1 if you have gettext and don't want to use GNU gettext.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETTEXT
end_undef

begin_comment
comment|/* Define if your locale.h file contains LC_MESSAGES.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LC_MESSAGES
end_undef

begin_comment
comment|/* Define as 1 if you have the stpcpy function.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STPCPY
end_undef

begin_comment
comment|/* Define if your assembler supports specifying the maximum number    of bytes to skip when using the GAS .p2align command.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_undef

begin_comment
comment|/* Define if your assembler supports .balign and .p2align.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GAS_BALIGN_AND_P2ALIGN
end_undef

begin_comment
comment|/* Define if your assembler uses the old HImode fild and fist notation.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GAS_FILDS_FISTS
end_undef

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_undef
undef|#
directive|undef
name|ssize_t
end_undef

begin_comment
comment|/* Define if cpp should also search $prefix/include.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFIX_INCLUDE_DIR
end_undef

begin_expr_stmt
unit|@
name|BOTTOM
expr|@
end_expr_stmt

begin_comment
comment|/* Bison unconditionally undefines `const' if neither `__STDC__' nor    __cplusplus are defined.  That's a problem since we use `const' in    the GCC headers, and the resulting bison code is therefore type    unsafe.  Thus, we must match the bison behavior here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

