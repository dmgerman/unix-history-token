begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC, for bi-arch SPARC    running Solaris 2, defaulting to 64-bit code generation.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
define|\
value|(MASK_V9 + MASK_PTR64 + MASK_64BIT
comment|/* + MASK_HARD_QUAD */
value|+ \    MASK_STACK_BIAS + MASK_FPU + MASK_LONG_DOUBLE_128)
end_define

begin_comment
comment|/* Target OS builtins.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_SUB_OS_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|TARGET_SUB_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\ 	builtin_define_std ("sparc");		\     }						\   while (0)
end_define

end_unit

