begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_STDDEF_H
end_ifndef

begin_define
define|#
directive|define
name|_STDDEF_H
end_define

begin_comment
comment|/* Signed type of difference of two pointers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRDIFF_T
end_ifndef

begin_comment
comment|/* in case<sys/types.h> has defined it. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_T_PTRDIFF
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__PTRDIFF_T
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRDIFF_T_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|___int_ptrdiff_t_h
end_ifndef

begin_define
define|#
directive|define
name|_PTRDIFF_T
end_define

begin_define
define|#
directive|define
name|_T_PTRDIFF
end_define

begin_define
define|#
directive|define
name|__PTRDIFF_T
end_define

begin_define
define|#
directive|define
name|_PTRDIFF_T_
end_define

begin_define
define|#
directive|define
name|___int_ptrdiff_t_h
end_define

begin_typedef
typedef|typedef
name|long
name|ptrdiff_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ___int_ptrdiff_t_h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PTRDIFF_T_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PTRDIFF_T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _T_PTRDIFF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PTRDIFF_T */
end_comment

begin_comment
comment|/* Unsigned type of `sizeof' something.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T
end_ifndef

begin_comment
comment|/* in case<sys/types.h> has defined it. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_T_SIZE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__SIZE_T
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|___int_size_t_h
end_ifndef

begin_define
define|#
directive|define
name|_SIZE_T
end_define

begin_define
define|#
directive|define
name|_T_SIZE
end_define

begin_define
define|#
directive|define
name|__SIZE_T
end_define

begin_define
define|#
directive|define
name|_SIZE_T_
end_define

begin_define
define|#
directive|define
name|___int_size_t_h
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ___int_size_t_h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIZE_T_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SIZE_T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _T_SIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIZE_T */
end_comment

begin_comment
comment|/* A null pointer constant.  */
end_comment

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_comment
comment|/* in case<stdio.h> has defined it. */
end_comment

begin_define
define|#
directive|define
name|NULL
value|((void *)0)
end_define

begin_comment
comment|/* Offset of member MEMBER in a struct of type TYPE.  */
end_comment

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|TYPE
parameter_list|,
name|MEMBER
parameter_list|)
value|((size_t)&((TYPE *)0)->MEMBER)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDDEF_H */
end_comment

end_unit

