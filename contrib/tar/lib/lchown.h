begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Some systems don't have ENOSYS.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ENOSYS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ENOTSUP
end_ifdef

begin_define
define|#
directive|define
name|ENOSYS
value|ENOTSUP
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Some systems don't have ENOTSUP either.  */
end_comment

begin_define
define|#
directive|define
name|ENOSYS
value|EINVAL
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

