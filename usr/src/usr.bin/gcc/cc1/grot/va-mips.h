begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ---------------------------------------- */
end_comment

begin_comment
comment|/*           VARARGS  for MIPS/GNU CC       */
end_comment

begin_comment
comment|/*                                          */
end_comment

begin_comment
comment|/*                                          */
end_comment

begin_comment
comment|/*                                          */
end_comment

begin_comment
comment|/*                                          */
end_comment

begin_comment
comment|/* ---------------------------------------- */
end_comment

begin_comment
comment|/* These macros implement traditional (non-ANSI) varargs    for GNU C.  */
end_comment

begin_define
define|#
directive|define
name|va_alist
value|__builtin_va_alist
end_define

begin_define
define|#
directive|define
name|va_dcl
value|int __builtin_va_alist;
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST_
end_define

begin_define
define|#
directive|define
name|va_list
value|char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
value|AP = (char *)&__builtin_va_alist
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|AP
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_comment
comment|/* complains about constant in conditional context */
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|list
parameter_list|,
name|mode
parameter_list|)
value|((mode *)(list += sizeof(mode)))[-1]
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !lint */
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|AP
parameter_list|,
name|mode
parameter_list|)
value|((mode *)(AP = \ 	(char *) (sizeof(mode)> 4 ? ((int)AP + 2*8 - 1)& -8 \ 				   : ((int)AP + 2*4 - 1)& -4)))[-1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

end_unit

