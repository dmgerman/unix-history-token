begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Use semicolons to separate elements of a path.  */
end_comment

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|';'
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\ 	builtin_define_std ("unix");		\     }						\   while (0)
end_define

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{posix:-D_POSIX_SOURCE}"
end_define

end_unit

