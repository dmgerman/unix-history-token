begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XSCALE_MACH_H__
end_ifndef

begin_define
define|#
directive|define
name|__XSCALE_MACH_H__
end_define

begin_comment
comment|/* These are predefined by new versions of GNU cpp.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__USER_LABEL_PREFIX__
end_ifndef

begin_define
define|#
directive|define
name|__USER_LABEL_PREFIX__
value|_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__REGISTER_PREFIX__
end_ifndef

begin_define
define|#
directive|define
name|__REGISTER_PREFIX__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANSI concatenation macros.  */
end_comment

begin_define
define|#
directive|define
name|CONCAT1
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CONCAT2(a, b)
end_define

begin_define
define|#
directive|define
name|CONCAT2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_comment
comment|/* Use the right prefix for global labels.  */
end_comment

begin_define
define|#
directive|define
name|SYM
parameter_list|(
name|x
parameter_list|)
value|CONCAT1(__USER_LABEL_PREFIX__, x)
end_define

begin_define
define|#
directive|define
name|PRELOAD
parameter_list|(
name|X
parameter_list|)
value|pld	[X]
end_define

begin_define
define|#
directive|define
name|PRELOADSTR
parameter_list|(
name|X
parameter_list|)
value|"	pld	[" X "]"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__XSCALE_MACH_H__ */
end_comment

end_unit

